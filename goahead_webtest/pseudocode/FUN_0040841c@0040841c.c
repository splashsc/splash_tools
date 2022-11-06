
undefined4 FUN_0040841c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar3 = &_mips_gp0_value;
  iVar1 = FUN_004083a0();
  uVar2 = 0xffffffff;
  if (iVar1 != 0) {
    symClose(*(int *)(*(int *)(iVar1 + 8) + param_2 * 4) + -1);
    uVar2 = hFree(iVar1 + 8,param_2,param_3,param_4,puVar3);
    *(undefined4 *)(iVar1 + 0xc) = uVar2;
    uVar2 = 0;
  }
  return uVar2;
}

