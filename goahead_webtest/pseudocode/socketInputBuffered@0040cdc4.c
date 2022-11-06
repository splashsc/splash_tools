
undefined4 socketInputBuffered(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = socketPtr();
  if (iVar1 != 0) {
    iVar2 = socketEof(param_1);
    if (iVar2 == 0) {
      uVar3 = ringqLen(iVar1 + 0x40);
      return uVar3;
    }
  }
  return 0xffffffff;
}

