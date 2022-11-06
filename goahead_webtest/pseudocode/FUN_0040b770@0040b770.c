
void FUN_0040b770(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[1];
  if (iVar1 + -1 <= param_1[3]) {
    iVar2 = iVar1 + 0x40;
    if ((param_1[4] & 1U) == 0) {
      return;
    }
    param_1[1] = iVar2;
    if ((param_1[2] < iVar2) && (0x40 < iVar2)) {
      param_1[1] = iVar1;
      return;
    }
    if (*param_1 == 0) {
      iVar1 = balloc(iVar2);
      *param_1 = iVar1;
    }
    else {
      iVar1 = brealloc();
      *param_1 = iVar1;
    }
  }
  *(char *)(*param_1 + param_1[3]) = (char)param_2;
  if (param_2 != 0) {
    param_1[3] = param_1[3] + 1;
  }
  return;
}

