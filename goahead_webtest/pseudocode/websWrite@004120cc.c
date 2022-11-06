
int websWrite(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_res8;
  undefined4 local_resc;
  int local_18;
  undefined4 *local_14;
  int local_10;
  
  local_14 = &local_res8;
  local_18 = 0;
  local_res8 = param_3;
  local_resc = param_4;
  iVar1 = fmtValloc(&local_18,0x3c0,param_2);
  if (0x3bf < iVar1) {
    trace(0,"webs: websWrite lost data, buffer overflow\n");
  }
  local_10 = 0;
  if (local_18 != 0) {
    local_10 = local_18;
    uVar2 = (*(code *)PTR_strlen_0043095c)(local_18);
    local_10 = websWriteBlock(param_1,local_10,uVar2);
    bfree(local_18);
  }
  return local_10;
}

