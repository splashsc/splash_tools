
undefined4 FUN_0041ad9c(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  puVar4 = &_mips_gp0_value;
  iVar1 = FUN_0041a750(0);
  uVar3 = 0xfffffffa;
  if (((-1 < iVar1) && (iVar1 < DAT_00430c64)) &&
     (iVar1 = *(int *)(DAT_00430c60 + iVar1 * 4), iVar1 != 0)) {
    if (*(int *)(iVar1 + 0x10) < param_3) {
      trace(4,"DB: Setting rows to <%d> in table <%s>\n",param_3,param_2,puVar4);
      do {
        if (param_3 <= *(int *)(iVar1 + 0x10)) {
          return 0;
        }
        iVar2 = dbAddRow(param_1,param_2);
        uVar3 = 0xffffffff;
      } while (-1 < iVar2);
    }
    else {
      trace(4,"DB: Ignoring row set to <%d> in table <%s>\n",param_3,param_2,puVar4);
      uVar3 = 0;
    }
  }
  return uVar3;
}

