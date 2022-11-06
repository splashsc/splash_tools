
void FUN_00415820(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = websValid(param_3);
  if (iVar1 != 0) {
    if ((param_2 & 2) != 0) {
      FUN_00414b20(param_3);
    }
    if ((((param_2 & 4) != 0) && (iVar1 = websValid(param_3), iVar1 != 0)) &&
       (*(code **)(param_3 + 0x124) != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x00415890. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (**(code **)(param_3 + 0x124))(param_3);
      return;
    }
  }
  return;
}

