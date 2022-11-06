
/* WARNING: Could not reconcile some variable overlaps */

int FUN_0041956c(undefined4 param_1)

{
  int iVar1;
  undefined4 local_18 [3];
  
  local_18[0] = 0xffffffff;
  iVar1 = dbSearchStr(DAT_004304f8,"access","name",param_1,0);
  if (-1 < iVar1) {
    dbReadInt(DAT_004304f8,"access","secure",iVar1,local_18);
  }
  return (int)(short)local_18[0];
}

