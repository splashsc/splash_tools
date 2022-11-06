
int FUN_004083a0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (((param_1 < 0) || (DAT_00430070 <= param_1)) ||
     (iVar1 = *(int *)(*(int *)PTR_ejHandles_0043070c + param_1 * 4), iVar1 == 0)) {
    ejError(0,"Bad handle %d",param_1,param_4,&_mips_gp0_value);
    iVar1 = 0;
  }
  return iVar1;
}

