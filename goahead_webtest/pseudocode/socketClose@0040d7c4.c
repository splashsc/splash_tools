
void socketClose(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = PTR_socketList_0043076c;
  DAT_00430bc0 = DAT_00430bc0 + -1;
  if (DAT_00430bc0 < 1) {
    iVar2 = *(int *)PTR_socketMax_00430768;
    iVar3 = iVar2 << 2;
    for (; -1 < iVar2; iVar2 = iVar2 + -1) {
      if ((*(int *)puVar1 != 0) && (*(int *)(*(int *)puVar1 + iVar3) != 0)) {
        socketCloseConnection(iVar2);
      }
      iVar3 = iVar3 + -4;
    }
    DAT_00430bc0 = 0;
  }
  return;
}

