
undefined4 FUN_00417b80(char *param_1)

{
  char cVar1;
  
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    do {
      cVar1 = *param_1;
      if (cVar1 == 0) {
        return 1;
      }
      param_1 = param_1 + 1;
    } while ((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + cVar1 * 2) & 0x20) == 0);
  }
  return 0;
}

