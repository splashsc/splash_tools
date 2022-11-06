
undefined4 FUN_00418c64(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [3];
  
  iVar1 = dbSearchStr(DAT_004304f8,"groups","name",param_1,0);
  if (iVar1 < 0) {
    local_18[0] = 4;
  }
  else {
    dbReadInt(DAT_004304f8,"groups","method",iVar1,local_18);
  }
  return local_18[0];
}

