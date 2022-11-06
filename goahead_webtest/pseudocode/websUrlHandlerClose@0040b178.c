
void websUrlHandlerClose(void)

{
  uint uVar1;
  
  DAT_00430bb0 = DAT_00430bb0 + -1;
  if (DAT_00430bb0 < 1) {
    websAspClose();
    for (uVar1 = DAT_00430bb4; uVar1 < DAT_00430bb4 + DAT_00430bb8 * 0x18; uVar1 = uVar1 + 0x18) {
      bfree(*(undefined4 *)(uVar1 + 8));
      if (*(int *)(uVar1 + 4) != 0) {
        bfree();
      }
    }
    bfree();
    DAT_00430bb8 = 0;
  }
  return;
}

