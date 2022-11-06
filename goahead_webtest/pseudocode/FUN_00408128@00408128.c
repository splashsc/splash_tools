
void FUN_00408128(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *param_1;
  if (iVar3 != 0) {
    iVar1 = (*(code *)PTR_strlen_0043095c)();
    iVar2 = (*(code *)PTR_strlen_0043095c)(iVar3);
    iVar3 = brealloc(iVar3,iVar1 + iVar2 + 1);
    *param_1 = iVar3;
                    /* WARNING: Could not recover jumptable at 0x004081d8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_strcpy_00430ad8)(iVar3 + iVar2,param_2);
    return;
  }
  iVar3 = bstrdup(param_2);
  *param_1 = iVar3;
  return;
}

