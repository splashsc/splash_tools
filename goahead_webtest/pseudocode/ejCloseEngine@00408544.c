
void ejCloseEngine(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = FUN_004083a0();
  if (iVar1 != 0) {
    bfreeSafe(*(undefined4 *)(iVar1 + 0x18));
    *(undefined4 *)(iVar1 + 0x18) = 0;
    bfreeSafe(*(undefined4 *)(iVar1 + 0x14));
    *(undefined4 *)(iVar1 + 0x14) = 0;
    ejLexClose(iVar1);
    iVar3 = *(int *)(iVar1 + 0xc) + -1;
    iVar4 = iVar3 * 4;
    for (; -1 < iVar3; iVar3 = iVar3 + -1) {
      if ((*(uint *)(iVar1 + 0x28) & 2) != 0) {
        symClose(*(int *)(*(int *)(iVar1 + 8) + iVar4) + -1);
      }
      uVar2 = hFree(iVar1 + 8,iVar3);
      iVar4 = iVar4 + -4;
      *(undefined4 *)(iVar1 + 0xc) = uVar2;
    }
    if ((*(uint *)(iVar1 + 0x28) & 4) != 0) {
      symClose(*(undefined4 *)(iVar1 + 4));
    }
    DAT_00430070 = hFree(PTR_ejHandles_0043070c,*(undefined4 *)(iVar1 + 0x24));
    bfree(iVar1);
    return;
  }
  return;
}

