
void emfUnschedCallback(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  
  puVar1 = &_mips_gp0_value;
  if ((((DAT_00430c30 != 0) && (param_1 != -1)) && (param_1 < DAT_00430c34)) &&
     (*(int *)(DAT_00430c30 + param_1 * 4) != 0)) {
    bfree();
    DAT_00430c34 = hFree(&DAT_00430c30,param_1,param_3,param_4,puVar1);
  }
  return;
}

