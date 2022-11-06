
int ringqPutBlkMax(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = *(uint *)(param_1 + 8);
  iVar1 = uVar2 - *(uint *)(param_1 + 4);
  if (uVar2 < *(uint *)(param_1 + 4)) {
    iVar1 = *(int *)(param_1 + 0x10) + iVar1;
  }
  iVar1 = (*(int *)(param_1 + 0x10) - iVar1) + -1;
  iVar3 = *(int *)(param_1 + 0xc) - uVar2;
  if (iVar3 < iVar1) {
    iVar1 = iVar3;
  }
  return iVar1;
}

