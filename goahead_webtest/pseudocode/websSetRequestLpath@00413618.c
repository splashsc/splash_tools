
void websSetRequestLpath(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc0) != 0) {
    bfree();
  }
  uVar1 = bstrdup(param_2);
  *(undefined4 *)(param_1 + 0xc0) = uVar1;
  FUN_00411dc4(param_1,"PATH_TRANSLATED",uVar1);
  return;
}

