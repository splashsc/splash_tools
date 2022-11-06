
bool FUN_00418eb0(undefined4 param_1)

{
  int iVar1;
  int local_18 [3];
  
  iVar1 = dbSearchStr(DAT_004304f8,"groups","name",param_1,0);
  local_18[0] = 1;
  if (-1 < iVar1) {
    dbReadInt(DAT_004304f8,"groups","disable",iVar1,local_18);
  }
  return local_18[0] == 0;
}

