
void FUN_00415f84(int *param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = *param_1;
  ringqInsertc(iVar1 + 0x1c,(int)param_2,param_3,param_4,&_mips_gp0_value);
  if (0 < *(int *)(iVar1 + 0x4c)) {
    *(int *)(iVar1 + 0x4c) = *(int *)(iVar1 + 0x4c) + -1;
  }
  *(undefined *)(*(int *)(iVar1 + 0x40) + *(int *)(iVar1 + 0x4c)) = 0;
  return;
}

