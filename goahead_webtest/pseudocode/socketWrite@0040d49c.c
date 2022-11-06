
int socketWrite(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  puVar5 = &_mips_gp0_value;
  iVar1 = socketPtr();
  iVar3 = -1;
  if (iVar1 != 0) {
    iVar4 = iVar1 + 0x5c;
    iVar3 = 0;
    do {
      while( true ) {
        if (param_3 < 1) {
          return iVar3;
        }
        iVar2 = ringqPutBlkMax(iVar4);
        if (iVar2 == 0) break;
        if (param_3 < iVar2) {
          iVar2 = param_3;
        }
        ringqPutBlk(iVar4,param_2,iVar2,param_4,puVar5);
        iVar3 = iVar3 + iVar2;
        param_3 = param_3 - iVar2;
        param_2 = param_2 + iVar2;
      }
      iVar2 = socketFlush(param_1);
      if (iVar2 < 0) {
        return -1;
      }
      iVar2 = ringqPutBlkMax(iVar4);
    } while ((iVar2 != 0) || ((*(uint *)(iVar1 + 0xac) & 0x80) != 0));
  }
  return iVar3;
}

