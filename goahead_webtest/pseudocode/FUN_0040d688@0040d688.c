
undefined4 FUN_0040d688(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = socketPtr();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0xac);
  }
  return uVar2;
}

