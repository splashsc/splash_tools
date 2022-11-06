
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 ejOpenEngine(int param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  iVar2 = hAllocEntry(PTR_ejHandles_0043070c,&DAT_00430070,0x30);
  puVar1 = PTR_ejHandles_0043070c;
  uVar6 = 0xffffffff;
  if (-1 < iVar2) {
    iVar5 = *(int *)(*(int *)PTR_ejHandles_0043070c + iVar2 * 4);
    *(int *)(iVar5 + 0x24) = iVar2;
    iVar2 = hAlloc(iVar5 + 8);
    if (iVar2 < 0) {
      DAT_00430070 = hFree(puVar1,*(undefined4 *)(iVar5 + 0x24));
    }
    else {
      if (*(int *)(iVar5 + 0xc) <= iVar2) {
        *(int *)(iVar5 + 0xc) = iVar2 + 1;
      }
      iVar4 = *(int *)(iVar5 + 8);
      if (param_1 == -1) {
        iVar3 = symOpen(0x40);
        *(int *)(iVar4 + iVar2 * 4) = iVar3 + 1;
        *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 2;
      }
      else {
        *(int *)(iVar4 + iVar2 * 4) = param_1 + 1;
      }
      if (param_2 == -1) {
        uVar6 = symOpen(0x40);
        *(undefined4 *)(iVar5 + 4) = uVar6;
        *(uint *)(iVar5 + 0x28) = *(uint *)(iVar5 + 0x28) | 4;
      }
      else {
        *(int *)(iVar5 + 4) = param_2;
      }
      ejLexOpen(iVar5);
      FUN_00409028(*(undefined4 *)(iVar5 + 0x24),&DAT_0041dcfc,0);
      uVar6 = *(undefined4 *)(iVar5 + 0x24);
    }
  }
  return uVar6;
}

