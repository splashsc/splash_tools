
int FUN_0040b438(undefined4 param_1,char **param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  
  iVar3 = 0;
  do {
    while( true ) {
      if (DAT_00430bb8 <= iVar3) {
        return 0;
      }
      piVar2 = (int *)(DAT_00430bb4 + iVar3 * 0x18);
      pcVar4 = (char *)piVar2[2];
      if ((*pcVar4 != '\0') && (*piVar2 != 0)) break;
      iVar3 = iVar3 + 1;
    }
    iVar1 = (*(code *)PTR_strncmp_00430a08)(pcVar4,param_1,piVar2[3]);
    iVar3 = iVar3 + 1;
  } while (iVar1 != 0);
  if (param_2 != (char **)0x0) {
    *param_2 = pcVar4;
  }
  return piVar2[1];
}

