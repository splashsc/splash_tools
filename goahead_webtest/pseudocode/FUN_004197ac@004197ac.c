
int FUN_004197ac(void)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  
  iVar5 = 0;
  pcVar2 = (char *)bstrdup();
  iVar3 = (*(code *)PTR_strlen_0043095c)(pcVar2);
  while ((iVar3 != 0 && (iVar5 == 0))) {
    iVar4 = umAccessLimitExists(pcVar2);
    if (iVar4 == 0) {
      pcVar6 = pcVar2 + iVar3;
      while( true ) {
        pcVar6 = pcVar6 + -1;
        bVar1 = pcVar6 < pcVar2;
        if ((bVar1) || ((*pcVar6 != '/' && (bVar1 = pcVar6 < pcVar2, *pcVar6 != '\\')))) break;
        *pcVar6 = '\0';
      }
      while ((!bVar1 && ((*pcVar6 != '/' && (*pcVar6 != '\\'))))) {
        *pcVar6 = '\0';
        pcVar6 = pcVar6 + -1;
        bVar1 = pcVar6 < pcVar2;
      }
      iVar3 = (*(code *)PTR_strlen_0043095c)(pcVar2);
    }
    else {
      iVar5 = bstrdup(pcVar2);
    }
  }
  bfree();
  return iVar5;
}

