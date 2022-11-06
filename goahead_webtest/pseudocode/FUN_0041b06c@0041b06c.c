
void FUN_0041b06c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  
  if (DAT_00430c68 != 0) {
    bfree();
  }
  iVar1 = bstrdup(param_1);
  DAT_00430c68 = iVar1;
  iVar2 = (*(code *)PTR_strlen_0043095c)(iVar1);
  if ((0 < iVar2) && (pcVar3 = (char *)(iVar1 + iVar2 + -1), *pcVar3 == '/')) {
    *pcVar3 = '\0';
  }
  return;
}

