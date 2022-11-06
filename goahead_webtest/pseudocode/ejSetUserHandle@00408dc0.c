
void ejSetUserHandle(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_004083a0();
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x2c) = param_2;
  }
  return;
}

