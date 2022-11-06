
int hAllocEntry(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hAlloc();
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    if (0 < param_3) {
      iVar2 = balloc(param_3);
      if (iVar2 == 0) {
        hFree(param_1,iVar1);
        return -1;
      }
      (*(code *)PTR_memset_004309cc)(iVar2,0,param_3);
      *(int *)(*param_1 + iVar1 * 4) = iVar2;
    }
    if (*param_2 <= iVar1) {
      *param_2 = iVar1 + 1;
    }
  }
  return iVar1;
}

