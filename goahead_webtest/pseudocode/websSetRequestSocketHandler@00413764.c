
void websSetRequestSocketHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x124) = param_3;
  socketCreateHandler(*(undefined4 *)(param_1 + 0xf0),4,FUN_00415820,param_1);
  return;
}

