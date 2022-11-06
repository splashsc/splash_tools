
undefined4 FUN_0041944c(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [3];
  
  local_18[0] = 4;
  iVar1 = dbSearchStr(DAT_004304f8,"access","name",param_1,0);
  if (-1 < iVar1) {
    dbReadInt(DAT_004304f8,"access","method",iVar1,local_18);
  }
  return local_18[0];
}

