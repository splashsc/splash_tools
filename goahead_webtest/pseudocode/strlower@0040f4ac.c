
char * strlower(char *param_1)

{
  undefined *puVar1;
  undefined *puVar2;
  char *pcVar3;
  int iVar4;
  
  puVar2 = PTR___ctype_b_00430aa4;
  puVar1 = PTR___ctype_tolower_00430944;
  pcVar3 = param_1;
  if (param_1 != (char *)0x0) {
    for (; *param_1 != 0; param_1 = param_1 + 1) {
      iVar4 = *param_1 * 2;
      if ((*(ushort *)(*(int *)puVar2 + iVar4) & 1) != 0) {
        *param_1 = (char)*(undefined2 *)(*(int *)puVar1 + iVar4);
      }
    }
    *param_1 = '\0';
  }
  return pcVar3;
}

