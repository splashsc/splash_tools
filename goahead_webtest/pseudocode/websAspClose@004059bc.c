
void websAspClose(void)

{
  DAT_00430b30 = DAT_00430b30 + -1;
  if ((DAT_00430b30 < 1) && (DAT_00430040 != -1)) {
    symClose();
    DAT_00430040 = -1;
  }
  return;
}

