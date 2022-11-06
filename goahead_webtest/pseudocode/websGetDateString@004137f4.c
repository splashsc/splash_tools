
undefined4 websGetDateString(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_10 [2];
  
  if (param_1 == 0) {
    (*(code *)PTR_time_004309c0)(local_10);
  }
  else {
    local_10[0] = *(undefined4 *)(param_1 + 8);
  }
  iVar1 = (*(code *)PTR_ctime_00430a44)(local_10);
  uVar2 = 0;
  if (iVar1 != 0) {
    iVar3 = (*(code *)PTR_strlen_0043095c)(iVar1);
    *(undefined *)(iVar1 + iVar3 + -1) = 0;
    uVar2 = bstrdup(iVar1);
  }
  return uVar2;
}

