
int ringqLen(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 4);
  uVar3 = *(uint *)(param_1 + 8);
  iVar1 = uVar3 - uVar2;
  if (uVar3 < uVar2) {
    iVar1 = (uVar3 + *(int *)(param_1 + 0x10)) - uVar2;
  }
  return iVar1;
}

