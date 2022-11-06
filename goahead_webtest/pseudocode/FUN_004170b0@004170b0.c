
undefined4 FUN_004170b0(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  
  puVar6 = &_mips_gp0_value;
  iVar5 = param_1[4];
  if ((param_1[5] < 0) || (uVar2 = 0, iVar5 < param_1[5])) {
    uVar3 = ringqLen(param_1);
    iVar5 = balloc(iVar5 + param_1[6]);
    uVar2 = 0;
    if (iVar5 != 0) {
      uVar2 = ringqLen(param_1);
      FUN_00416fe0(param_1,iVar5,uVar2,param_4,puVar6);
      bfree(*param_1);
      iVar4 = param_1[4];
      param_1[2] = iVar5;
      param_1[1] = iVar5;
      param_1[4] = iVar4 + param_1[6];
      *param_1 = iVar5;
      param_1[3] = iVar5 + iVar4 + param_1[6];
      ringqPutBlk(param_1,iVar5,uVar3);
      iVar5 = 0;
      iVar4 = (param_1[6] << 1) >> 4;
      while (bVar1 = iVar4 != 0, iVar4 = iVar4 >> 1, bVar1) {
        iVar5 = iVar5 + 1;
      }
      param_1[6] = 1 << (iVar5 + 4U & 0x1f);
      uVar2 = 1;
    }
  }
  return uVar2;
}

