
int * symNext(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(DAT_00430bf8 + param_1 * 4);
  iVar4 = DAT_00430bfc << 2;
  piVar1 = DAT_00430c00;
  iVar2 = DAT_00430bfc;
  while( true ) {
    if (*(int *)(iVar3 + 4) <= iVar2) {
      DAT_00430c00 = piVar1;
      return (int *)0x0;
    }
    iVar4 = iVar4 + 4;
    if (piVar1 != (int *)0x0) break;
    iVar2 = iVar2 + 1;
    piVar1 = *(int **)(*(int *)(iVar3 + 8) + iVar4);
  }
  if (*piVar1 == 0) {
    DAT_00430bfc = iVar2 + 1;
    DAT_00430c00 = (int *)*(undefined4 *)(*(int *)(iVar3 + 8) + (iVar2 + 1) * 4);
    return piVar1;
  }
  DAT_00430bfc = iVar2;
  DAT_00430c00 = (int *)*piVar1;
  return piVar1;
}

