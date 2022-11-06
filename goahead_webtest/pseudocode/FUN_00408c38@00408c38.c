
undefined4 FUN_00408c38(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar3 = &_mips_gp0_value;
  uVar2 = 0;
  iVar1 = FUN_004083a0();
  if ((iVar1 != 0) &&
     (iVar1 = symLookup(*(undefined4 *)(iVar1 + 4),param_2,param_3,param_4,puVar3), iVar1 != 0)) {
    uVar2 = *(undefined4 *)(iVar1 + 0x12);
  }
  return uVar2;
}

