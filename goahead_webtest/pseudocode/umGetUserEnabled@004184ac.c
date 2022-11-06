
bool umGetUserEnabled(undefined4 param_1)

{
  int iVar1;
  int local_18 [3];
  
  local_18[0] = 1;
  iVar1 = dbSearchStr(DAT_004304f8,"users","name",param_1,0);
  if (-1 < iVar1) {
    dbReadInt(DAT_004304f8,"users","disable",iVar1,local_18);
  }
  return local_18[0] == 0;
}

