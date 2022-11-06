
void FUN_00411dc4(int param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  
  if (param_3 == (undefined1 *)0x0) {
    param_3 = &DAT_0041ed68;
  }
  valueString(&local_20,param_3,1);
  symEnter(*(undefined4 *)(param_1 + 0x20),param_2,local_20,local_1c,local_18,local_14,0);
  return;
}

