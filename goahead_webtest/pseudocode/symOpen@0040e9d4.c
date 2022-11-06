
int symOpen(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar1 = hAlloc(&DAT_00430bf8);
  if (-1 < iVar1) {
    iVar2 = balloc(0xc);
    if (iVar2 != 0) {
      (*(code *)PTR_memset_004309cc)(iVar2,0,0xc);
      if (DAT_00430bf4 <= iVar1) {
        DAT_00430bf4 = iVar1 + 1;
      }
      *(int *)(DAT_00430bf8 + iVar1 * 4) = iVar2;
      for (; 0 < param_1; param_1 = param_1 + -1) {
        iVar3 = 2;
        do {
          if (param_1 >> 1 < iVar3) goto LAB_0040eadc;
          iVar5 = param_1 % iVar3;
          if (iVar3 == 0) {
            trap(0x1c00);
          }
          iVar3 = iVar3 + 1;
        } while (iVar5 != 0);
      }
      param_1 = 1;
LAB_0040eadc:
      *(int *)(iVar2 + 4) = param_1;
      uVar4 = balloc(param_1 << 2);
      *(undefined4 *)(iVar2 + 8) = uVar4;
      (*(code *)PTR_memset_004309cc)(uVar4,0,*(int *)(iVar2 + 4) << 2);
      return iVar1;
    }
    DAT_00430bf4 = hFree(&DAT_00430bf8,iVar1);
  }
  return -1;
}

