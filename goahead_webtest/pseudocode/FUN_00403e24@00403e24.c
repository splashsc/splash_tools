
void FUN_00403e24(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_getRssVar_Encode_00430938)(*param_4,2,param_3,param_4,&_mips_gp0_value);
  websWrite(param_2,"%s",uVar1);
  return;
}

