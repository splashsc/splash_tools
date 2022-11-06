
char * umGetFirstGroup(void)

{
  int iVar1;
  int iVar2;
  char *local_28 [3];
  
  local_28[0] = (char *)0x0;
  iVar1 = 0;
  do {
    iVar2 = iVar1 + 1;
    iVar1 = dbReadStr(DAT_004304f8,"groups","name",iVar1,local_28);
    if ((iVar1 != 0) && (iVar1 != -5)) {
      return (char *)0x0;
    }
    iVar1 = iVar2;
  } while ((local_28[0] == (char *)0x0) || (*local_28[0] == '\0'));
  return local_28[0];
}

