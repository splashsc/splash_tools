
void FUN_004080c8(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (*param_1 != 0) {
    bfree();
  }
  iVar1 = bstrdup(param_2);
  *param_1 = iVar1;
  return;
}

