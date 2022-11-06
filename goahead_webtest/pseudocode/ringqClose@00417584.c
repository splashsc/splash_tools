
void ringqClose(undefined4 *param_1)

{
  if (param_1 != (undefined4 *)0x0) {
    ringqFlush();
    bfree(*param_1);
    *param_1 = 0;
  }
  return;
}

