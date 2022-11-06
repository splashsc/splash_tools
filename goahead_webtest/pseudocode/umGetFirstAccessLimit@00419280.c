
char * umGetFirstAccessLimit(void)

{
  int iVar1;
  int iVar2;
  char *apcStack40 [3];
  
  apcStack40[0] = (char *)0x0;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    iVar1 = dbReadStr(DAT_004304f8,"access","name",iVar1,apcStack40);
    if ((iVar1 != 0) && (iVar1 != -5)) {
      return (char *)0x0;
    }
    iVar1 = iVar2;
  } while ((apcStack40[0] == (char *)0x0) || (*apcStack40[0] == '\0'));
  return apcStack40[0];
}

