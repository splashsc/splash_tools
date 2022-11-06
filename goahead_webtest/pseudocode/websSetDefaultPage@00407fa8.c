
void websSetDefaultPage(undefined4 param_1)

{
  if (DAT_00430ba4 != 0) {
    bfree();
  }
  DAT_00430ba4 = bstrdup(param_1);
  return;
}

