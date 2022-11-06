
undefined4 websCalcNonce(int param_1)

{
  undefined4 uVar1;
  undefined auStack24 [4];
  undefined4 local_14;
  undefined4 local_10;
  
  (*(code *)PTR_time_004309c0)(auStack24);
  uVar1 = (*(code *)PTR_localtime_004309d0)(auStack24);
  local_14 = 0;
  uVar1 = (*(code *)PTR_asctime_00430ad4)(uVar1);
  fmtAlloc(&local_14,0x100,"%s:%s:%s","onceuponatimeinparadise",uVar1,
           *(undefined4 *)(param_1 + 0x128));
  local_10 = FUN_00419bac(local_14);
  bfreeSafe(local_14);
  return local_10;
}

