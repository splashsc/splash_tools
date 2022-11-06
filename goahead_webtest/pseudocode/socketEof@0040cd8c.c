
uint socketEof(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = socketPtr();
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    uVar2 = *(uint *)(iVar1 + 0xac) & 1;
  }
  return uVar2;
}

