
int * symFirst(int param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = *(int *)(DAT_00430bf8 + param_1 * 4);
  iVar1 = 0;
  do {
    iVar3 = iVar1;
    if (*(int *)(iVar4 + 4) <= iVar3) {
      return (int *)0x0;
    }
    iVar5 = *(int *)(iVar4 + 8);
    piVar2 = *(int **)(iVar5 + iVar3 * 4);
    iVar1 = iVar3 + 1;
  } while (piVar2 == (int *)0x0);
  if (*piVar2 == 0) {
    DAT_00430bfc = iVar3 + 1;
    DAT_00430c00 = *(undefined4 *)(iVar5 + (iVar3 + 1) * 4);
    return piVar2;
  }
  DAT_00430bfc = iVar3;
  DAT_00430c00 = *piVar2;
  return piVar2;
}

