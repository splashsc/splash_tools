
void socketFree(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined auStack272 [260];
  
  iVar1 = socketPtr();
  if (iVar1 != 0) {
    socketRegisterInterest(iVar1,0);
    if (-1 < *(int *)(iVar1 + 0xb0)) {
      socketSetBlock(param_1,0);
      iVar2 = (*(code *)PTR_shutdown_004309b0)(*(undefined4 *)(iVar1 + 0xb0),1);
      if (-1 < iVar2) {
        (*(code *)PTR_recv_00430ac0)(*(undefined4 *)(iVar1 + 0xb0),auStack272,0x100,0);
      }
      (*(code *)PTR_close_0043093c)(*(undefined4 *)(iVar1 + 0xb0));
    }
    if ((*(uint *)(iVar1 + 0xac) & 0x800) == 0) {
      ringqClose(iVar1 + 0x40);
      ringqClose(iVar1 + 0x5c);
    }
    ringqClose(iVar1 + 0x78);
    bfree(iVar1);
    iVar1 = hFree(PTR_socketList_0043076c,param_1);
    *(int *)PTR_socketMax_00430768 = iVar1;
    piVar3 = *(int **)PTR_socketList_0043076c;
    socketHighestFd = -1;
    for (iVar2 = 0; iVar2 < iVar1; iVar2 = iVar2 + 1) {
      if ((*piVar3 != 0) && (iVar4 = *(int *)(*piVar3 + 0xb0), socketHighestFd < iVar4)) {
        socketHighestFd = iVar4;
      }
      piVar3 = piVar3 + 1;
    }
  }
  return;
}

