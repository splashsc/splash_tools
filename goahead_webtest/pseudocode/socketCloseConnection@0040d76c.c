
void socketCloseConnection(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = socketPtr();
  if (iVar1 != 0) {
    socketFree(param_1);
    return;
  }
  return;
}

