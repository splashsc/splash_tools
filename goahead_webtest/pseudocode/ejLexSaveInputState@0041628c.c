
void ejLexSaveInputState(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = *param_1;
  (*(code *)PTR_memcpy_00430a90)(param_2,iVar2,0x50,param_4,&_mips_gp0_value);
  if (*(int *)(iVar2 + 0x38) != 0) {
    uVar1 = bstrdup();
    *(undefined4 *)(param_2 + 0x38) = uVar1;
  }
  return;
}

