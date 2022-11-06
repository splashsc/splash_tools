
/* WARNING: Could not reconcile some variable overlaps */

int umGetGroupProtected(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [3];
  
  local_18[0] = 0;
  iVar1 = dbSearchStr(DAT_004304f8,"groups","name",param_1,0);
  if (-1 < iVar1) {
    dbReadInt(DAT_004304f8,"groups",&DAT_0041fc14,iVar1,local_18);
  }
  return (int)(short)local_18[0];
}

