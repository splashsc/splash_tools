
undefined4
umAddUser(undefined4 param_1,undefined4 param_2,undefined4 param_3,short param_4,short param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  trace(3,"UM: Adding User <%s>\n",param_1);
  iVar1 = umUserExists(param_1);
  uVar4 = 0xfffffffc;
  if (iVar1 == 0) {
    iVar1 = FUN_00417b80(param_1);
    uVar4 = 0xfffffffa;
    if (iVar1 != 0) {
      iVar1 = FUN_00417b80(param_2);
      uVar4 = 0xfffffff9;
      if (iVar1 != 0) {
        iVar1 = umGroupExists(param_3);
        uVar4 = 0xfffffffe;
        if (iVar1 != 0) {
          iVar1 = dbAddRow(DAT_004304f8,"users");
          uVar4 = 0xffffffff;
          if (-1 < iVar1) {
            iVar2 = dbWriteStr(DAT_004304f8,"users","name",iVar1,param_1);
            if (iVar2 == 0) {
              uVar3 = bstrdup(param_2);
              FUN_00417af0(uVar3);
              dbWriteStr(DAT_004304f8,"users","password",iVar1,uVar3);
              uVar4 = 0;
              bfree(uVar3);
              dbWriteStr(DAT_004304f8,"users","group",iVar1,param_3);
              dbWriteInt(DAT_004304f8,"users",&DAT_0041fc14,iVar1,(int)param_4);
              dbWriteInt(DAT_004304f8,"users","disable",iVar1,(int)param_5);
            }
          }
        }
      }
    }
  }
  return uVar4;
}

