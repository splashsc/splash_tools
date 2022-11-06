
uint FUN_0040d650(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = socketPtr();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 0xac) & 0x80;
  }
  return uVar2;
}

