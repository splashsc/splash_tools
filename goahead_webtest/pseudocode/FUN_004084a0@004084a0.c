
int FUN_004084a0(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = -1;
  iVar1 = FUN_004083a0();
  if (iVar1 != 0) {
    iVar2 = hAlloc(iVar1 + 8);
    if (iVar2 < 0) {
      iVar2 = -1;
    }
    else {
      if (*(int *)(iVar1 + 0xc) <= iVar2) {
        *(int *)(iVar1 + 0xc) = iVar2 + 1;
      }
      iVar3 = *(int *)(iVar1 + 8);
      iVar1 = symOpen(0x40);
      *(int *)(iVar3 + iVar2 * 4) = iVar1 + 1;
    }
  }
  return iVar2;
}

