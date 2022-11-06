
int hFree(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *param_1;
  *(undefined4 *)(iVar4 + -8 + (param_2 + 2) * 4) = 0;
  iVar1 = *(int *)(iVar4 + -4) + -1;
  *(int *)(iVar4 + -4) = iVar1;
  if (iVar1 == 0) {
    bfree();
    *param_1 = 0;
  }
  iVar1 = -1;
  if ((*param_1 != 0) && (iVar1 = *(int *)(iVar4 + -8), *(int *)(iVar4 + -4) < iVar1)) {
    iVar2 = iVar1 * 4;
    iVar3 = 0;
    do {
      iVar1 = iVar1 + -1;
      iVar3 = iVar3 + -4;
      if (iVar1 < 0) break;
    } while (*(int *)(iVar4 + iVar2 + iVar3) == 0);
  }
  return iVar1 + 1;
}

