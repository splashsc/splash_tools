
void ejLexRestoreInputState(int *param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  (*(code *)PTR_memcpy_00430a90)(iVar2,param_2,0x1c);
  (*(code *)PTR_memcpy_00430a90)(iVar2 + 0x1c,param_2 + 0x1c,0x1c);
  *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(param_2 + 0x3c);
  if (*(int *)(iVar2 + 0x38) != 0) {
    bfree();
  }
  if (*(int *)(param_2 + 0x38) != 0) {
    uVar1 = bstrdup();
    *(undefined4 *)(iVar2 + 0x38) = uVar1;
  }
  return;
}

