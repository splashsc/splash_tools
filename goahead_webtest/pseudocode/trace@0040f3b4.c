
void trace(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_res8;
  undefined4 local_resc;
  undefined4 local_10;
  undefined4 *local_c;
  
  local_c = &local_res8;
  local_res8 = param_3;
  local_resc = param_4;
  fmtValloc(&local_10,0xfd0,param_2,local_c,&_mips_gp0_value);
  if (PTR_FUN_004300a4 != (undefined *)0x0) {
    (*(code *)PTR_FUN_004300a4)(param_1,local_10);
  }
  bfreeSafe(local_10);
  return;
}

