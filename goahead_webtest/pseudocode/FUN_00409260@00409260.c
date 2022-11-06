
int FUN_00409260(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_004083a0();
  iVar3 = -1;
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0xc) + -1;
    iVar2 = symLookup(*(int *)(*(int *)(iVar1 + 8) + iVar3 * 4) + -1,param_2);
    if (iVar2 == 0) {
      iVar2 = symLookup(**(int **)(iVar1 + 8) + -1,param_2);
      if (iVar2 == 0) {
        return -1;
      }
      iVar3 = 0;
    }
    *param_3 = *(undefined4 *)(iVar2 + 0x12);
  }
  return iVar3;
}

