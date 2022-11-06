
int FUN_00415e9c(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  iVar1 = ringqLen(iVar3 + 0x1c);
  iVar4 = -1;
  if (iVar1 != 0) {
    iVar4 = ringqGetc(iVar3 + 0x1c);
    if (iVar4 == 10) {
      *(undefined4 *)(iVar3 + 0x4c) = 0;
      *(int *)(iVar3 + 0x48) = *(int *)(iVar3 + 0x48) + 1;
    }
    else {
      if (*(int *)(iVar3 + 0x44) <= *(int *)(iVar3 + 0x4c) + 2) {
        *(int *)(iVar3 + 0x44) = *(int *)(iVar3 + 0x44) + 0x6e;
        uVar2 = brealloc(*(undefined4 *)(iVar3 + 0x40));
        *(undefined4 *)(iVar3 + 0x40) = uVar2;
      }
      iVar1 = *(int *)(iVar3 + 0x4c);
      *(char *)(*(int *)(iVar3 + 0x40) + iVar1) = (char)iVar4;
      iVar1 = iVar1 + 1;
      *(int *)(iVar3 + 0x4c) = iVar1;
      *(undefined *)(*(int *)(iVar3 + 0x40) + iVar1) = 0;
    }
  }
  return iVar4;
}

