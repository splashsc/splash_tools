
void ringqFlush(undefined4 *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)*param_1;
  param_1[1] = puVar1;
  param_1[2] = puVar1;
  if (puVar1 != (undefined *)0x0) {
    *puVar1 = 0;
  }
  return;
}

