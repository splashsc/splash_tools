
void websPageOpen(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_open_00430958)(param_2,param_4,param_5,param_4,&_mips_gp0_value);
  *(undefined4 *)(param_1 + 0x118) = uVar1;
  return;
}

