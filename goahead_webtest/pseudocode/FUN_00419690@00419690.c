
undefined4 FUN_00419690(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [3];
  
  local_18[0] = 0;
  iVar1 = dbSearchStr(DAT_004304f8,"access","name",param_1,0);
  if (-1 < iVar1) {
    dbReadStr(DAT_004304f8,"access","group",iVar1,local_18);
  }
  return local_18[0];
}

