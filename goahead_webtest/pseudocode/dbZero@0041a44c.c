
void dbZero(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  for (iVar6 = 0; iVar6 < DAT_00430c64; iVar6 = iVar6 + 1) {
    iVar4 = *(int *)(DAT_00430c60 + iVar6 * 4);
    if (iVar4 != 0) {
      iVar8 = *(int *)(iVar4 + 4);
      iVar7 = *(int *)(iVar4 + 0x10);
      for (iVar5 = 0; iVar5 < iVar7; iVar5 = iVar5 + 1) {
        puVar3 = *(undefined4 **)(*(int *)(iVar4 + 0x14) + iVar5 * 4);
        if (puVar3 != (undefined4 *)0x0) {
          puVar2 = puVar3;
          for (iVar1 = 0; iVar1 < iVar8; iVar1 = iVar1 + 1) {
            if (*(int *)(*(int *)(iVar4 + 0xc) + iVar1 * 4) == 1) {
              bfreeSafe(*puVar2);
              *puVar2 = 0;
            }
            puVar2 = puVar2 + 1;
          }
          bfreeSafe(puVar3);
          hFree(iVar4 + 0x14,iVar5);
        }
      }
      *(undefined4 *)(iVar4 + 0x14) = 0;
      *(undefined4 *)(iVar4 + 0x10) = 0;
    }
  }
  return;
}

