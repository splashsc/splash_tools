
void websSetDefaultDir(undefined4 param_1)

{
  if (DAT_00430ba0 != 0) {
    bfree();
  }
  DAT_00430ba0 = bstrdup(param_1);
  return;
}

