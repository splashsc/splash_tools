
void websFormClose(void)

{
  if (DAT_00430080 != -1) {
    symClose();
    DAT_00430080 = -1;
  }
  return;
}

