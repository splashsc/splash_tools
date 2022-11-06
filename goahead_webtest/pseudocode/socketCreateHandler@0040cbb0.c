
void socketCreateHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  
  iVar1 = socketPtr();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x98) = param_3;
    *(undefined4 *)(iVar1 + 0x9c) = param_4;
    socketRegisterInterest(iVar1,param_2);
    return;
  }
  return;
}

