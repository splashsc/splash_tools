
undefined4 FUN_0041aab4(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0041a750();
  uVar2 = 0xffffffff;
  if (((-1 < iVar1) && (iVar1 < DAT_00430c64)) &&
     (iVar1 = *(int *)(DAT_00430c60 + iVar1 * 4), iVar1 != 0)) {
    uVar2 = *(undefined4 *)(iVar1 + 0x10);
  }
  return uVar2;
}

