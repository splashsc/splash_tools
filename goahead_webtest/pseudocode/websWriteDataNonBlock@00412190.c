
undefined4 websWriteDataNonBlock(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = socketWrite(*(undefined4 *)(param_1 + 0xf0));
  socketFlush(*(undefined4 *)(param_1 + 0xf0));
  return uVar1;
}

