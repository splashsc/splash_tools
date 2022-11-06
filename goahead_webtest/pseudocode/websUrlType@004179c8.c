
undefined4 websUrlType(char *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14 [2];
  
  if (((param_1 != (char *)0x0) && (*param_1 != '\0')) &&
     (iVar1 = websUrlParse(param_1,&local_18,0,0,0,0,0,0,local_14), -1 < iVar1)) {
    strlower(local_14[0]);
    iVar1 = symLookup(*(undefined4 *)PTR_websMime_0043085c,local_14[0]);
    if (iVar1 == 0) {
      (*(code *)PTR_strcpy_00430ad8)(param_2,"text/plain");
    }
    else {
      (*(code *)PTR_strncpy_00430a04)(param_2,*(undefined4 *)(iVar1 + 0x12),param_3);
    }
    bfree(local_18);
    return param_2;
  }
  (*(code *)PTR_strcpy_00430ad8)(param_2,"text/plain");
  return param_2;
}

