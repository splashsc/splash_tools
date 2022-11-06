
int FUN_0041a150(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (((-1 < param_1) && (param_1 < DAT_00430c64)) &&
     (iVar3 = *(int *)(DAT_00430c60 + param_1 * 4), iVar3 != 0)) {
    for (iVar2 = 0; iVar2 < *(int *)(iVar3 + 4); iVar2 = iVar2 + 1) {
      iVar1 = (*(code *)PTR_strcmp_004309b4)
                        (param_2,*(undefined4 *)(*(int *)(iVar3 + 8) + iVar2 * 4));
      if (iVar1 == 0) {
        return iVar2;
      }
    }
  }
  return -1;
}

