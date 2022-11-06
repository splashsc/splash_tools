
undefined4 FUN_00418cfc(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = dbSearchStr(DAT_004304f8,"groups","name",param_1,0);
  uVar2 = 0xfffffffe;
  if (-1 < iVar1) {
    uVar2 = dbWriteInt(DAT_004304f8,"groups","method",iVar1,param_2);
  }
  return uVar2;
}

