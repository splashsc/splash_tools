
void bclose(void)

{
  DAT_00430b40 = DAT_00430b40 + -1;
  if ((DAT_00430b40 < 1) && ((DAT_00430050 & 2) == 0)) {
    (*(code *)PTR_free_00430934)(DAT_00430b50);
    DAT_00430b40 = 0;
  }
  return;
}

