
undefined4 FUN_00408b98(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004083a0();
  if (iVar1 != 0) {
    uVar2 = ejSetGlobalFunctionDirect(*(undefined4 *)(iVar1 + 4),param_2,param_3);
    return uVar2;
  }
  return 0xffffffff;
}

