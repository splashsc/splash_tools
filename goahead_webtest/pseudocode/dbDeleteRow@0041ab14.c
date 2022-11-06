
undefined4 dbDeleteRow(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  
  iVar1 = FUN_0041a750(0);
  uVar2 = 0xfffffffa;
  if (((-1 < iVar1) && (iVar1 < DAT_00430c64)) &&
     (iVar1 = *(int *)(DAT_00430c60 + iVar1 * 4), iVar1 != 0)) {
    iVar4 = *(int *)(iVar1 + 4);
    if ((param_3 < 0) || (*(int *)(iVar1 + 0x10) <= param_3)) {
      trace(3,"DB: Unable to delete row <%d> from table <%s>\n",param_3);
      uVar2 = 0xffffffff;
    }
    else {
      piVar3 = *(int **)(*(int *)(iVar1 + 0x14) + param_3 * 4);
      uVar2 = 0;
      if (piVar3 != (int *)0x0) {
        piVar6 = piVar3;
        for (iVar5 = 0; iVar5 < iVar4; iVar5 = iVar5 + 1) {
          if ((*piVar6 != 0) && (*(int *)(*(int *)(iVar1 + 0xc) + iVar5 * 4) == 1)) {
            bfree();
          }
          piVar6 = piVar6 + 1;
        }
        (*(code *)PTR_memset_004309cc)(piVar3,0);
        bfreeSafe(piVar3);
        uVar2 = hFree(iVar1 + 0x14,param_3);
        *(undefined4 *)(iVar1 + 0x10) = uVar2;
        trace(5,"DB: Deleted row <%d> from table <%s>\n",param_3,param_2);
        uVar2 = 0;
      }
    }
  }
  return uVar2;
}

