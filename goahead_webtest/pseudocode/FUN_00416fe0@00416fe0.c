
int FUN_00416fe0(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (param_3 < 1) {
      return iVar3;
    }
    iVar1 = ringqGetBlkMax(param_1);
    if (param_3 < iVar1) {
      iVar1 = param_3;
    }
    if (iVar1 < 1) break;
    (*(code *)PTR_memcpy_00430a90)(param_2,param_1[1],iVar1);
    iVar2 = param_1[1];
    param_2 = param_2 + iVar1;
    param_1[1] = iVar2 + iVar1;
    param_3 = param_3 - iVar1;
    iVar3 = iVar3 + iVar1;
    if ((uint)param_1[3] <= (uint)(iVar2 + iVar1)) {
      param_1[1] = *param_1;
    }
  }
  return iVar3;
}

