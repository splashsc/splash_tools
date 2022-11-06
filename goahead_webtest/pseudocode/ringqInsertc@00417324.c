
undefined4 ringqInsertc(uint *param_1,undefined param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ringqPutBlkMax();
  if ((iVar1 < 1) && (iVar1 = FUN_004170b0(param_1), iVar1 == 0)) {
    return 0xffffffff;
  }
  if (param_1[1] <= *param_1) {
    param_1[1] = param_1[3];
  }
  uVar2 = param_1[1];
  *(undefined *)(uVar2 - 1) = param_2;
  param_1[1] = uVar2 - 1;
  return 0;
}

