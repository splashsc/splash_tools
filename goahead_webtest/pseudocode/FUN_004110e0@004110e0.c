
char * FUN_004110e0(char *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  uint uVar5;
  char *pcVar6;
  uint uVar7;
  
  if (param_1 == (char *)0x0) {
    pcVar3 = (char *)0x0;
  }
  else {
    uVar5 = 0;
    pcVar3 = param_1;
    while (iVar2 = (*(code *)PTR_strchr_00430950)(pcVar3,0x3c), iVar2 != 0) {
      uVar5 = uVar5 + 1;
      pcVar3 = (char *)(iVar2 + 1);
    }
    uVar7 = 0;
    pcVar3 = param_1;
    while( true ) {
      iVar2 = (*(code *)PTR_strchr_00430950)(pcVar3,0x3e);
      pcVar3 = (char *)(iVar2 + 1);
      if (iVar2 == 0) break;
      uVar7 = uVar7 + 1;
    }
    iVar2 = (*(code *)PTR_strlen_0043095c)(param_1);
    if ((uVar7 | uVar5) == 0) {
      pcVar3 = (char *)bstrdup(param_1);
      return pcVar3;
    }
    pcVar3 = (char *)balloc(iVar2 + uVar5 * 4 + uVar7 * 4);
    if (pcVar3 != (char *)0x0) {
      pcVar6 = pcVar3;
      while (cVar1 = *param_1, cVar1 != '\0') {
        puVar4 = &DAT_0041e99c;
        if (cVar1 == '<') {
LAB_004111ec:
          (*(code *)PTR_strcpy_00430ad8)(pcVar6,puVar4);
          param_1 = param_1 + 1;
          pcVar6 = pcVar6 + 4;
        }
        else {
          if (cVar1 == '>') {
            puVar4 = &DAT_0041e9a4;
            goto LAB_004111ec;
          }
          *pcVar6 = cVar1;
          pcVar6 = pcVar6 + 1;
          param_1 = param_1 + 1;
        }
      }
      *pcVar6 = '\0';
    }
  }
  return pcVar3;
}

