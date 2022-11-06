
int strcmpci(char *param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (((param_1 != (char *)0x0) && (param_2 != (char *)0x0)) && (param_1 != param_2)) {
    do {
      iVar1 = (int)*(short *)(*(int *)PTR___ctype_tolower_00430944 + *param_1 * 2) -
              (int)*(short *)(*(int *)PTR___ctype_tolower_00430944 + *param_2 * 2);
      if (*param_1 == 0) {
        return iVar1;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    } while (iVar1 == 0);
  }
  return iVar1;
}

