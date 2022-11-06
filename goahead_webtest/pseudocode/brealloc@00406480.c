
int brealloc(int param_1,int param_2)

{
  int iVar1;
  
  if (param_1 == 0) {
    iVar1 = balloc(param_2);
    return iVar1;
  }
  iVar1 = param_1;
  if (*(int *)(param_1 + -8) < param_2) {
    iVar1 = balloc(param_2);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      (*(code *)PTR_memcpy_00430a90)(iVar1,param_1,*(undefined4 *)(param_1 + -8));
      bfree(param_1);
    }
  }
  return iVar1;
}

