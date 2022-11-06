
void ejLexCloseScript(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 0x38) != 0) {
    bfree();
    *(undefined4 *)(iVar1 + 0x38) = 0;
  }
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  if (*(int *)(iVar1 + 0x40) != 0) {
    bfree();
    *(undefined4 *)(iVar1 + 0x40) = 0;
  }
  ringqClose(iVar1);
  ringqClose(iVar1 + 0x1c);
  bfree(iVar1);
  return;
}

