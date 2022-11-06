
uint websPageIsDirectory(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4
                        )

{
  int iVar1;
  uint uVar2;
  undefined auStack160 [20];
  uint local_8c;
  
  iVar1 = (*(code *)PTR_stat_00430984)(param_1,auStack160,param_3,param_4,&_mips_gp0_value);
  uVar2 = 0;
  if (-1 < iVar1) {
    uVar2 = local_8c & 0x4000;
  }
  return uVar2;
}

