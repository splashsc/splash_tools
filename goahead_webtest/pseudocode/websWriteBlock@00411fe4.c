
int websWriteBlock(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = ballocUniToAsc(param_2,param_3,param_3,param_4,&_mips_gp0_value);
  iVar3 = 0;
  iVar4 = iVar1;
  while( true ) {
    if (param_3 < 1) {
      bfree(iVar1);
      return iVar3;
    }
    iVar2 = socketWrite(*(undefined4 *)(param_1 + 0xf0),iVar4,param_3);
    if (iVar2 < 0) break;
    param_3 = param_3 - iVar2;
    iVar4 = iVar4 + iVar2;
    socketFlush(*(undefined4 *)(param_1 + 0xf0));
    iVar3 = iVar3 + iVar2;
  }
  bfree(iVar1);
  return -1;
}

