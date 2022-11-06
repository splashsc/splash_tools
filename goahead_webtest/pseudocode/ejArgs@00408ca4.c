
int ejArgs(undefined4 param_1,int param_2,char *param_3,int *param_4)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *local_resc;
  int **local_30;
  
  local_30 = &local_resc;
  iVar3 = 0;
  local_resc = param_4;
  if (param_2 != 0) {
    while (param_3 != (char *)0x0) {
      cVar1 = *param_3;
      if (cVar1 == '\0') {
        return iVar3;
      }
      iVar2 = *(int *)(param_2 + iVar3 * 4);
      if (iVar2 == 0) {
        return iVar3;
      }
      param_3 = param_3 + 1;
      if (cVar1 == '%') {
        if (*param_3 == 'd') {
          iVar2 = (*(code *)PTR_atoi_0043096c)();
          **local_30 = iVar2;
          local_30 = local_30 + 1;
        }
        else if (*param_3 == 's') {
          **local_30 = iVar2;
          local_30 = local_30 + 1;
        }
        iVar3 = iVar3 + 1;
      }
    }
  }
  return iVar3;
}

