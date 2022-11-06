
void websSetTimeMark(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = (*(code *)PTR_time_004309c0)(0);
  *(undefined4 *)(param_1 + 0x28) = uVar1;
  return;
}

