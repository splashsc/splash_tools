
void websTimeoutCancel(int param_1)

{
  if (-1 < *(int *)(param_1 + 0x2c)) {
    emfUnschedCallback();
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
  }
  return;
}

