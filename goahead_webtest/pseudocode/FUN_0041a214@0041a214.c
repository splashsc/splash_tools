
int FUN_0041a214(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int local_18 [2];
  int local_10;
  
  fmtAlloc(local_18,0x1000,"%s=%s\n",param_2,param_3);
  local_10 = 0xffffffff;
  if (local_18[0] != 0) {
    local_10 = local_18[0];
    uVar1 = (*(code *)PTR_strlen_0043095c)(local_18[0]);
    local_10 = (*(code *)PTR_write_00430a4c)(param_1,local_10,uVar1);
    bfree(local_18[0]);
  }
  return local_10;
}

