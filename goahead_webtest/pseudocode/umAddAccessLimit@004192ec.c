
undefined4 umAddAccessLimit(undefined4 param_1,undefined4 param_2,short param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  trace(3,"UM: Adding Access Limit for <%s>\n",param_1);
  iVar1 = umAccessLimitExists(param_1);
  uVar3 = 0xfffffffc;
  if (iVar1 == 0) {
    iVar1 = dbAddRow(DAT_004304f8,"access");
    uVar3 = 0xffffffff;
    if (-1 < iVar1) {
      iVar2 = dbWriteStr(DAT_004304f8,"access","name",iVar1,param_1);
      if (-1 < iVar2) {
        dbWriteInt(DAT_004304f8,"access","method",iVar1,param_2);
        dbWriteInt(DAT_004304f8,"access","secure",iVar1,(int)param_3);
        uVar3 = 0;
        dbWriteStr(DAT_004304f8,"access","group",iVar1,param_4);
      }
    }
  }
  return uVar3;
}

