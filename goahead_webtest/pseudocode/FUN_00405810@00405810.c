
char * FUN_00405810(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)FUN_004057c0();
  iVar3 = (*(code *)PTR_strlen_0043095c)(param_2);
  while( true ) {
    if (iVar3 < 1) {
      return (char *)((uint)pcVar2 & -(uint)(iVar3 == 0));
    }
    cVar1 = *param_2;
    if (*(short *)(*(int *)PTR___ctype_tolower_00430944 + *pcVar2 * 2) !=
        *(short *)(*(int *)PTR___ctype_tolower_00430944 + cVar1 * 2)) break;
    param_2 = param_2 + 1;
    if (cVar1 == 0) {
      return pcVar2;
    }
    pcVar2 = pcVar2 + 1;
    iVar3 = iVar3 + -1;
  }
  return (char *)0x0;
}

