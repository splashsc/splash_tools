
int ballocAscToUni(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = balloc(param_2 + 1);
  if (iVar1 != 0) {
    (*(code *)PTR_memcpy_00430a90)(iVar1,param_1,param_2 + 1);
    *(undefined *)(iVar1 + param_2) = 0;
  }
  return iVar1;
}

