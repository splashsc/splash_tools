
int FUN_00415fec(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  
  puVar1 = PTR___ctype_b_00430aa4;
  puVar6 = &_mips_gp0_value;
  iVar4 = 0;
  iVar5 = 0;
  while( true ) {
    if (param_3 <= iVar5) {
      return iVar4;
    }
    iVar2 = FUN_00415e9c(param_1);
    if (iVar2 < 0) {
      return iVar4;
    }
    iVar3 = iVar2 + -0x30;
    if (((*(ushort *)(*(int *)puVar1 + iVar2 * 2) & 8) == 0) &&
       (iVar3 = iVar2 + -0x57, 5 < iVar2 - 0x61U)) {
      if (5 < iVar2 - 0x41U) break;
      iVar3 = iVar2 + -0x37;
    }
    if (param_2 <= iVar3) break;
    iVar5 = iVar5 + 1;
    iVar4 = iVar4 * param_2 + iVar3;
  }
  FUN_00415f84(param_1,iVar2,param_3,param_4,puVar6);
  return iVar4;
}

