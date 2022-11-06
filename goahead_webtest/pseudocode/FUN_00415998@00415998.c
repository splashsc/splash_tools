
void FUN_00415998(int param_1)

{
  code **ppcVar1;
  
  ppcVar1 = *(code ***)(DAT_00430c30 + param_1 * 4);
                    /* WARNING: Could not recover jumptable at 0x004159bc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**ppcVar1)(ppcVar1[1],ppcVar1[3]);
  return;
}

