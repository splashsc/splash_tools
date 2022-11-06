
undefined4 FUN_00415e10(int *param_1,char param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = *param_1;
  iVar1 = ringqPutc(iVar3,(int)param_2,param_3,param_4,&_mips_gp0_value);
  if (iVar1 < 0) {
    ejError(param_1,"Token too big");
    uVar2 = 0xffffffff;
  }
  else {
    **(undefined **)(iVar3 + 8) = 0;
    param_1[7] = *(int *)(iVar3 + 4);
    uVar2 = 0;
  }
  return uVar2;
}

