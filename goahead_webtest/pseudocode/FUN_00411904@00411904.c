
void FUN_00411904(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 < 4) {
    iVar1 = (*(code *)PTR_strlen_0043095c)(param_2);
    uVar2 = ballocUniToAsc(param_2,iVar1 + 1);
    (*(code *)PTR_write_00430a4c)(DAT_00430c20,uVar2,iVar1);
    bfreeSafe(uVar2);
    return;
  }
  return;
}

