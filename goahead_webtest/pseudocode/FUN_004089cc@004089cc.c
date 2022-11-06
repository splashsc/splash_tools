
undefined4 FUN_004089cc(int param_1,char *param_2,int param_3,char *param_4)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  char *pcVar4;
  undefined auStack40 [16];
  char *local_18;
  
  pcVar4 = param_2;
  if (((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + *param_2 * 2) & 8) == 0) ||
     (pcVar4 = param_4, (*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + *param_4 * 2) & 8) == 0)) {
    ejError(param_1,"Conditional must be numeric",pcVar4);
    bVar3 = false;
  }
  else {
    local_18 = param_4;
    uVar1 = (*(code *)PTR_atoi_0043096c)(param_2);
    uVar2 = (*(code *)PTR_atoi_0043096c)(local_18);
    if (param_3 == 1) {
      bVar3 = false;
      if (uVar1 != 0) {
        bVar3 = uVar2 != 0;
      }
    }
    else {
      if (param_3 != 2) {
        ejError(param_1,"Bad operator %d",param_3);
        return 0xffffffff;
      }
      bVar3 = (uVar2 | uVar1) != 0;
    }
  }
  stritoa(bVar3,auStack40,0x10);
  FUN_004080c8(param_1 + 0x14,auStack40);
  return 0;
}

