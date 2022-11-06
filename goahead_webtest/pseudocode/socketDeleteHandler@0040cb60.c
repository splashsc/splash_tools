
void socketDeleteHandler(void)

{
  int iVar1;
  
  iVar1 = socketPtr();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x98) = 0;
    socketRegisterInterest(iVar1,0);
    return;
  }
  return;
}

