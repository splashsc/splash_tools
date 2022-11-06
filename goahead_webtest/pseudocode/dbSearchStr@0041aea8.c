
int dbSearchStr(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_0041a750(0);
  iVar3 = -6;
  if (((-1 < iVar1) && (iVar1 < DAT_00430c64)) &&
     (iVar5 = *(int *)(DAT_00430c60 + iVar1 * 4), iVar5 != 0)) {
    iVar3 = *(int *)(iVar5 + 0x10);
    iVar1 = FUN_0041a150(iVar1,param_3);
    if (iVar1 < 0) {
      iVar3 = -2;
      trace(3,"DB: Unable to find column <%s> in table <%s>\n",param_3,param_2);
    }
    else {
      for (iVar4 = 0; iVar4 < iVar3; iVar4 = iVar4 + 1) {
        iVar2 = *(int *)(*(int *)(iVar5 + 0x14) + iVar4 * 4);
        if ((iVar2 != 0) && (iVar2 = *(int *)(iVar2 + iVar1 * 4), iVar2 != 0)) {
          if (param_5 == 1) {
            iVar2 = strcmpci();
          }
          else {
            iVar2 = (*(code *)PTR_strcmp_004309b4)(iVar2,param_4);
          }
          if (iVar2 == 0) {
            return iVar4;
          }
        }
      }
      iVar3 = -1;
    }
  }
  return iVar3;
}

