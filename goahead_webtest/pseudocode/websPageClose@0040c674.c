
void websPageClose(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x118)) {
    (*(code *)PTR_close_0043093c)();
    *(undefined4 *)(param_1 + 0x118) = 0xffffffff;
  }
  return;
}

