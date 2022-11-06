
bool socketReady(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  
  puVar3 = PTR_socketList_0043076c;
  puVar2 = PTR_socketMax_00430768;
  bVar1 = -1 < param_1;
  if (!bVar1) {
    param_1 = 0;
  }
  iVar5 = param_1 << 2;
  do {
    if (param_1 >= *(int *)puVar2) {
      return param_1 < *(int *)puVar2;
    }
    iVar4 = *(int *)(*(int *)puVar3 + iVar5);
    if (iVar4 != 0) {
      if ((*(uint *)(iVar4 + 0xac) & 0x400) != 0) {
        socketCloseConnection(param_1);
        return false;
      }
      if ((*(uint *)(iVar4 + 0xa0) & *(uint *)(iVar4 + 0xbc)) != 0) {
        return true;
      }
      if (((*(uint *)(iVar4 + 0xa0) & 2) != 0) && (iVar4 = socketInputBuffered(param_1), 0 < iVar4))
      {
        socketSelect(param_1,0);
        return true;
      }
    }
    param_1 = param_1 + 1;
    if (bVar1) {
      return false;
    }
    iVar5 = iVar5 + 4;
  } while( true );
}

