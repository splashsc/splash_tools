
char * FUN_0040b0a0(char *param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar1 = param_1;
  pcVar3 = param_1;
  if (param_1 != (char *)0x0) {
    for (; (*param_1 != '\0' && (*pcVar3 != '\0')); pcVar3 = pcVar3 + 1) {
      do {
        pcVar2 = param_1;
        param_1 = pcVar2 + 1;
        if (*pcVar2 != '/') break;
      } while (pcVar2[1] == '/');
      if (pcVar3 != pcVar2) {
        *pcVar3 = *pcVar2;
      }
    }
    if (pcVar3 != param_1) {
      *pcVar3 = '\0';
    }
  }
  return pcVar1;
}

