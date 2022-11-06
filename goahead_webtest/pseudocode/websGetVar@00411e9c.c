
undefined1 * websGetVar(int param_1,undefined4 param_2,undefined1 *param_3)

{
  int iVar1;
  
  iVar1 = symLookup(*(undefined4 *)(param_1 + 0x20));
  if ((iVar1 != 0) && (param_3 = *(undefined1 **)(iVar1 + 0x12), param_3 == (undefined1 *)0x0)) {
    param_3 = &DAT_0041ed68;
  }
  return param_3;
}

