
undefined4
websPageStat(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined auStack168 [20];
  uint local_94;
  undefined4 local_74;
  undefined4 local_64;
  undefined4 *local_10;
  
  local_10 = param_4;
  iVar1 = (*(code *)PTR_stat_00430984)(param_2,auStack168,param_3,param_4,&_mips_gp0_value);
  uVar2 = 0xffffffff;
  if (-1 < iVar1) {
    uVar2 = 0;
    *local_10 = local_74;
    local_10[2] = local_64;
    local_10[1] = local_94 & 0x4000;
  }
  return uVar2;
}

