
void ejLexFreeInputState(undefined4 param_1,int param_2)

{
  if (*(int *)(param_2 + 0x38) != 0) {
    bfree();
    *(undefined4 *)(param_2 + 0x38) = 0;
  }
  return;
}

