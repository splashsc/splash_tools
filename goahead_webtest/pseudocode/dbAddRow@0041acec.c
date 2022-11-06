
undefined4 dbAddRow(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  
  puVar3 = &_mips_gp0_value;
  iVar1 = FUN_0041a750(0);
  if (((-1 < iVar1) && (iVar1 < DAT_00430c64)) &&
     (iVar1 = *(int *)(DAT_00430c60 + iVar1 * 4), iVar1 != 0)) {
    trace(5,"DB: Adding a row to table <%s>\n",param_2,param_4,puVar3);
    uVar2 = hAllocEntry(iVar1 + 0x14,iVar1 + 0x10,*(int *)(iVar1 + 4) << 2);
    return uVar2;
  }
  return 0xfffffffa;
}

