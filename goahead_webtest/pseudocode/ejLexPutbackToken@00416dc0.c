
void ejLexPutbackToken(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  if (*(int *)(iVar2 + 0x38) != 0) {
    bfree();
  }
  *(undefined4 *)(iVar2 + 0x3c) = param_2;
  uVar1 = bstrdup(param_3);
  *(undefined4 *)(iVar2 + 0x38) = uVar1;
  return;
}

