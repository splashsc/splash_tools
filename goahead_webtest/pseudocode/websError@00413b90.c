
void websError(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_resc;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 *local_20;
  undefined4 local_18;
  undefined4 local_14;
  
  uVar2 = *(undefined4 *)(param_1 + 0xb8);
  *(int *)PTR_websStats_00430694 = *(int *)PTR_websStats_00430694 + 1;
  local_resc = param_4;
  local_14 = param_3;
  local_18 = FUN_004110e0(uVar2);
  bfreeSafe(*(undefined4 *)(param_1 + 0xb8));
  local_20 = &local_resc;
  *(undefined4 *)(param_1 + 0xb8) = local_18;
  local_24 = 0;
  fmtValloc(&local_24,0x3c0,local_14);
  uVar2 = FUN_004110e0(local_24);
  bfreeSafe(local_24);
  local_28 = 0;
  local_24 = uVar2;
  uVar1 = FUN_00411fa0(param_2);
  fmtAlloc(&local_28,0x3c0,
           "<html><head><title>Document Error: %s</title></head>\r\n\t\t<body><h2>Access Error: %s</h2>\r\n\t\t<p>%s</p></body></html>\r\n"
           ,uVar1,uVar1,uVar2);
  FUN_00413894(param_1,param_2,local_28,0);
  bfreeSafe(local_28);
  bfreeSafe(local_24);
  return;
}

