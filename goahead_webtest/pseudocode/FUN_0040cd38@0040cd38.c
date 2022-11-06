
int FUN_0040cd38(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = socketPtr();
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar2 = *(int *)(iVar1 + 0x6c);
    iVar1 = ringqLen(iVar1 + 0x5c);
    iVar2 = (iVar2 - iVar1) + -1;
  }
  return iVar2;
}

