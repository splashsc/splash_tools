
int bstrdup(undefined1 *param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 == (undefined1 *)0x0) {
    param_1 = &DAT_0041ed68;
  }
  iVar1 = (*(code *)PTR_strlen_0043095c)(param_1);
  iVar2 = balloc(iVar1 + 1);
  if (iVar2 != 0) {
    (*(code *)PTR_strncpy_00430a04)(iVar2,param_1,iVar1 + 1);
  }
  return iVar2;
}

