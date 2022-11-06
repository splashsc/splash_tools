
void websDefaultClose(void)

{
  if (DAT_00430ba4 != 0) {
    bfree();
    DAT_00430ba4 = 0;
  }
  if (DAT_00430ba0 != 0) {
    bfree();
    DAT_00430ba0 = 0;
  }
  return;
}

