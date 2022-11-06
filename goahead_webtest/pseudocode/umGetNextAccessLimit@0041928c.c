
char * umGetNextAccessLimit(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  char *apcStack48 [2];
  
  apcStack48[0] = (char *)0x0;
  iVar1 = 0;
  do {
    iVar3 = iVar1 + 1;
    iVar1 = dbReadStr(DAT_004304f8,"access","name",iVar1,apcStack48);
    if ((iVar1 != 0) && (iVar1 != -5)) break;
    iVar1 = iVar3;
  } while ((apcStack48[0] == (char *)0x0) ||
          (iVar2 = (*(code *)PTR_strcmp_004309b4)(apcStack48[0],param_1), iVar2 != 0));
  pcVar4 = (char *)0x0;
  if ((apcStack48[0] != (char *)0x0) &&
     (iVar1 = (*(code *)PTR_strcmp_004309b4)(apcStack48[0],param_1), iVar1 == 0)) {
    do {
      iVar1 = dbReadStr(DAT_004304f8,"access","name",iVar3,apcStack48);
      pcVar4 = apcStack48[0];
      iVar3 = iVar3 + 1;
      if ((iVar1 != 0) && (iVar1 != -5)) {
        return (char *)0x0;
      }
    } while (((apcStack48[0] == (char *)0x0) || (*apcStack48[0] == '\0')) ||
            (iVar1 = (*(code *)PTR_strcmp_004309b4)(apcStack48[0],param_1), iVar1 == 0));
  }
  return pcVar4;
}

