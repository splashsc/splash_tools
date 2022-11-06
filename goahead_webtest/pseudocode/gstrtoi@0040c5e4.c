
int gstrtoi(char *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  
  if ((*param_1 == '0') && ((param_1[1] == 'x' || (param_1[1] == 'X')))) {
    pcVar4 = param_1 + 2;
    if ((*pcVar4 == '0') && ((param_1[3] == 'x' || (param_1[3] == 'X')))) {
      pcVar4 = param_1 + 4;
    }
    iVar1 = 0;
    while( true ) {
      iVar2 = (int)*pcVar4;
      pcVar4 = pcVar4 + 1;
      if ((iVar2 == 0) ||
         (((uVar3 = iVar2 - 0x30, 9 < uVar3 && (uVar3 = iVar2 - 0x57, 5 < iVar2 - 0x61U)) &&
          (uVar3 = iVar2 - 0x37, 5 < iVar2 - 0x41U)))) break;
      iVar1 = uVar3 + iVar1 * 0x10;
    }
    return iVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0040c620. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_atoi_0043096c)();
  return iVar1;
}

