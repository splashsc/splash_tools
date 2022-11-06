
char * xmemstr(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  if (*param_2 == '\0') {
    return param_1;
  }
  do {
    do {
      iVar6 = param_3;
      pcVar3 = param_1;
      if (iVar6 < 1) {
        return (char *)0x0;
      }
      param_1 = pcVar3 + 1;
      param_3 = iVar6 + -1;
    } while (*pcVar3 != *param_2);
    pcVar4 = param_2 + 1;
    pcVar5 = param_1;
    do {
      cVar2 = *pcVar4;
      pcVar4 = pcVar4 + 1;
      if (cVar2 == '\0') {
        return pcVar3;
      }
      if (pcVar4 == param_2 + iVar6 + 1) {
        return (char *)0x0;
      }
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 == cVar2);
  } while( true );
}

