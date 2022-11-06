
void dbClose(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  
  dbZero();
  for (iVar3 = 0; iVar3 < DAT_00430c64; iVar3 = iVar3 + 1) {
    puVar4 = *(undefined4 **)(DAT_00430c60 + iVar3 * 4);
    if (puVar4 != (undefined4 *)0x0) {
      iVar1 = puVar4[1];
      iVar5 = 0;
      if (iVar1 != 0) {
        while( true ) {
          iVar2 = iVar5 * 4;
          if (iVar1 <= iVar5) break;
          iVar5 = iVar5 + 1;
          bfreeSafe(*(undefined4 *)(puVar4[2] + iVar2));
          iVar1 = puVar4[1];
        }
        bfreeSafe();
        bfreeSafe(puVar4[3]);
      }
      bfreeSafe(*puVar4);
      bfreeSafe(puVar4);
      hFree(&DAT_00430c60,iVar3);
    }
  }
  if (DAT_00430c60 != 0) {
    bfree();
  }
  DAT_00430c60 = 0;
  DAT_00430c64 = 0;
  return;
}

