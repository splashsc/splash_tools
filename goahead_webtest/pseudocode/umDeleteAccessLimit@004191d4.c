
undefined4 umDeleteAccessLimit(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  trace(3,"UM: Deleting Access Limit for <%s>\n",param_1);
  iVar1 = dbSearchStr(DAT_004304f8,"access","name",param_1,0);
  if (-1 < iVar1) {
    uVar2 = dbDeleteRow(DAT_004304f8,"access",iVar1);
    return uVar2;
  }
  return 0xfffffffe;
}

