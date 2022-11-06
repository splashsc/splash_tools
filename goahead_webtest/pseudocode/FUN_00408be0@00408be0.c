
undefined4 FUN_00408be0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_004083a0();
  if (iVar1 != 0) {
    uVar2 = symDelete(*(undefined4 *)(iVar1 + 4),param_2);
    return uVar2;
  }
  return 0xffffffff;
}

