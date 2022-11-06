
int * balloc(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  if ((DAT_00430b50 == 0) && (iVar2 = bopen(0,0x10000,0), iVar2 < 0)) {
    return (int *)0x0;
  }
  iVar2 = 0;
  if (param_1 < 0) {
    return (int *)0x0;
  }
  if (param_1 != 0) {
    iVar2 = param_1 + -1 >> 4;
  }
  iVar3 = 0;
  while (bVar1 = iVar2 != 0, iVar2 = iVar2 >> 1, bVar1) {
    iVar3 = iVar3 + 1;
  }
  iVar5 = 1 << (iVar3 + 4U & 0x1f);
  iVar2 = iVar5 + 8;
  if (iVar3 < 0xd) {
    piVar4 = (int *)(&DAT_00430b54)[iVar3];
    if (piVar4 == (int *)0x0) {
      if (DAT_00430b44 <= iVar2) goto LAB_00406248;
      DAT_00430b44 = DAT_00430b44 - iVar2;
      piVar4 = DAT_00430b4c;
      DAT_00430b4c = (int *)((int)DAT_00430b4c + iVar2);
    }
    else {
      (&DAT_00430b54)[iVar3] = *piVar4;
    }
    *piVar4 = iVar5;
    piVar4[1] = 0;
  }
  else {
LAB_00406248:
    if (((DAT_00430050 & 1) == 0) ||
       (piVar4 = (int *)(*(code *)PTR_malloc_00430a84)(), piVar4 == (int *)0x0)) {
      traceRaw("B: malloc failed\n");
      return (int *)0x0;
    }
    *piVar4 = iVar5;
    piVar4[1] = -0x80000000;
  }
  piVar4[1] = piVar4[1] | 0x8124000;
  return piVar4 + 2;
}

