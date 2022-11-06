
void error(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined *local_18;
  
  local_18 = &stack0x00000010;
  puVar1 = &_mips_gp0_value;
  fmtValloc(&local_1c,0x1000,param_4,local_18);
  if (param_3 != 2) {
    if (param_3 == 1) {
      fmtAlloc(&local_20,0x1000,"Assertion %s, failed at %s %d\n",local_1c,param_1,param_2,puVar1);
      goto LAB_0040f340;
    }
    if (param_3 != 3) {
      fmtAlloc(&local_20,0x1000,"Unknown error");
      goto LAB_0040f340;
    }
  }
  fmtAlloc(&local_20,0x1000,"%s\n",local_1c);
LAB_0040f340:
  bfree(local_1c);
  if (PTR_FUN_004300a0 != (undefined *)0x0) {
    (*(code *)PTR_FUN_004300a0)(param_3,local_20);
  }
  bfreeSafe(local_20);
  return;
}

