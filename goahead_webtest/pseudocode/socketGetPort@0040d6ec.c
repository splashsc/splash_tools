
undefined4 socketGetPort(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = socketPtr();
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = *(undefined4 *)(iVar1 + 0xa8);
  }
  return uVar2;
}

