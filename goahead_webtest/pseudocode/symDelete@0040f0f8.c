
undefined4 symDelete(int param_1,char *param_2)

{
  int **ppiVar1;
  int **ppiVar2;
  int **ppiVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar5 = *(int *)(DAT_00430bf8 + param_1 * 4);
  iVar4 = FUN_0040e920(iVar5);
  piVar6 = (int *)(*(int *)(iVar5 + 8) + iVar4 * 4);
  ppiVar3 = (int **)*piVar6;
  ppiVar2 = (int **)(undefined4 *)0x0;
  while( true ) {
    ppiVar1 = ppiVar3;
    if (ppiVar1 == (int **)0x0) {
      return 0xffffffff;
    }
    if ((*(char *)ppiVar1[1] == *param_2) &&
       (iVar4 = (*(code *)PTR_strcmp_004309b4)(ppiVar1[1],param_2), iVar4 == 0)) break;
    ppiVar3 = (int **)*ppiVar1;
    ppiVar2 = ppiVar1;
  }
  if (ppiVar2 == (int **)0x0) {
    *piVar6 = (int)*ppiVar1;
  }
  else {
    *ppiVar2 = *ppiVar1;
  }
  valueFree(ppiVar1 + 1);
  valueFree((int)ppiVar1 + 0x12);
  bfree(ppiVar1);
  return 0;
}

