
undefined4
umAddGroup(undefined4 param_1,short param_2,undefined4 param_3,short param_4,short param_5)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  trace(3,"UM: Adding group <%s>\n",param_1);
  iVar1 = umGroupExists(param_1);
  uVar3 = 0xfffffffc;
  if (iVar1 == 0) {
    iVar1 = FUN_00417b80(param_1);
    uVar3 = 0xfffffffa;
    if (iVar1 != 0) {
      iVar1 = dbAddRow(DAT_004304f8,"groups");
      uVar3 = 0xffffffff;
      if (-1 < iVar1) {
        iVar2 = dbWriteStr(DAT_004304f8,"groups","name",iVar1,param_1);
        if (iVar2 == 0) {
          dbWriteInt(DAT_004304f8,"groups",&DAT_0041fc54,iVar1,(int)param_2);
          dbWriteInt(DAT_004304f8,"groups","method",iVar1,param_3);
          dbWriteInt(DAT_004304f8,"groups",&DAT_0041fc14,iVar1,(int)param_4);
          uVar3 = 0;
          dbWriteInt(DAT_004304f8,"groups","disable",iVar1,(int)param_5);
        }
      }
    }
  }
  return uVar3;
}

