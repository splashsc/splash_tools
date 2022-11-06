
undefined4 ringqPutc(undefined4 *param_1,undefined param_2)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = ringqPutBlkMax();
  if ((iVar1 < 1) && (iVar1 = FUN_004170b0(param_1), iVar1 == 0)) {
    return 0xffffffff;
  }
  puVar2 = (undefined *)param_1[2];
  *puVar2 = param_2;
  puVar2 = puVar2 + 1;
  param_1[2] = puVar2;
  if ((undefined *)param_1[3] <= puVar2) {
    param_1[2] = *param_1;
  }
  return 0;
}

