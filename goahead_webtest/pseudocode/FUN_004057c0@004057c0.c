
char * FUN_004057c0(char *param_1)

{
  char *pcVar1;
  
  if (param_1 != (char *)0x0) {
    pcVar1 = param_1;
    do {
      param_1 = pcVar1;
      if (*param_1 == 0) {
        return param_1;
      }
      pcVar1 = param_1 + 1;
    } while ((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + *param_1 * 2) & 0x20) != 0);
  }
  return param_1;
}

