
int hAlloc(int **param_1)

{
  int *piVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  piVar4 = *param_1 + -2;
  if (*param_1 == (int *)0x0) {
    piVar4 = (int *)balloc(0x48);
    if (piVar4 == (int *)0x0) {
      return -1;
    }
    (*(code *)PTR_memset_004309cc)(piVar4,0,0x48);
    *piVar4 = 0x10;
    piVar4[1] = 0;
    *param_1 = piVar4 + 2;
  }
  iVar7 = *piVar4;
  iVar6 = iVar7;
  if (piVar4[1] < iVar7) {
    piVar5 = piVar4;
    iVar3 = 0;
    do {
      iVar6 = iVar3;
      if (iVar7 <= iVar6) goto LAB_0040ad44;
      piVar1 = piVar5 + 2;
      piVar5 = piVar5 + 1;
      iVar3 = iVar6 + 1;
    } while (*piVar1 != 0);
    piVar4[1] = piVar4[1] + 1;
  }
  else {
LAB_0040ad44:
    piVar4 = (int *)brealloc(piVar4,(iVar7 + 0x12) * 4);
    puVar2 = PTR_memset_004309cc;
    if (piVar4 == (int *)0x0) {
      iVar6 = -1;
    }
    else {
      *param_1 = piVar4 + 2;
      *piVar4 = iVar7 + 0x10;
      (*(code *)puVar2)(piVar4 + iVar7 + 2,0,0x40);
      piVar4[1] = piVar4[1] + 1;
    }
  }
  return iVar6;
}

