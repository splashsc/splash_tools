
int bmemdup(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  iVar1 = balloc(param_2);
  if (iVar1 != 0) {
    pcVar2 = (code *)PTR_memcpy_00430a90;
    if (param_1 == 0) {
      param_1 = 0;
      pcVar2 = (code *)PTR_memset_004309cc;
    }
    (*pcVar2)(iVar1,param_1,param_2);
  }
  return iVar1;
}

