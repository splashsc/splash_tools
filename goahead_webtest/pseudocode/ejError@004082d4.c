
void ejError(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined *puVar2;
  undefined4 local_20;
  int local_1c;
  undefined4 *local_18;
  
  iVar1 = *param_1;
  local_18 = &local_res8;
  puVar2 = &_mips_gp0_value;
  local_20 = 0;
  local_res8 = param_3;
  local_resc = param_4;
  fmtValloc(&local_20,0x1000,param_2);
  if (iVar1 != 0) {
    fmtAlloc(&local_1c,0x1000,"%s\n At line %d, line => \n\n%s\n",local_20,
             *(undefined4 *)(iVar1 + 0x48),*(undefined4 *)(iVar1 + 0x40),puVar2);
    bfreeSafe(param_1[6]);
    param_1[6] = local_1c;
  }
  bfreeSafe(local_20);
  return;
}

