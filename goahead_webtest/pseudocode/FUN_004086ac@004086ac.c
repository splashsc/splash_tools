
undefined4 FUN_004086ac(int param_1,char *param_2,undefined4 param_3,char *param_4)

{
  char cVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined auStack40 [16];
  char *local_18;
  
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar4 = param_4;
    if (cVar1 == 0) goto LAB_00408730;
    pcVar3 = pcVar3 + 1;
  } while ((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + cVar1 * 2) & 8) != 0);
  goto code_r0x00408758;
  while (pcVar4 = pcVar4 + 1, (*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + cVar1 * 2) & 8) != 0) {
LAB_00408730:
    cVar1 = *pcVar4;
    if (cVar1 == 0) {
      local_18 = (char *)param_3;
      uVar6 = (*(code *)PTR_atoi_0043096c)(param_2);
      uVar7 = (*(code *)PTR_atoi_0043096c)(param_4);
      switch(local_18) {
      case (char *)0x1:
        uVar8 = (uint)((int)uVar6 < (int)uVar7);
        goto LAB_00408934;
      case (char *)0x2:
        bVar2 = (int)uVar7 < (int)uVar6;
        break;
      case (char *)0x3:
        uVar8 = (uint)((int)uVar7 < (int)uVar6);
        goto LAB_00408934;
      case (char *)0x4:
        bVar2 = (int)uVar6 < (int)uVar7;
        break;
      case (char *)0x5:
        uVar8 = (uint)(uVar6 == uVar7);
        goto LAB_00408934;
      case (char *)0x6:
        uVar8 = (uint)(uVar6 != uVar7);
        goto LAB_00408934;
      case (char *)0x7:
        uVar8 = uVar6 + uVar7;
        goto LAB_00408934;
      case (char *)0x8:
        uVar8 = uVar6 - uVar7;
        goto LAB_00408934;
      case (char *)0x9:
        uVar8 = 0;
        if ((uVar7 != 0) && (uVar8 = (int)uVar6 / (int)uVar7, uVar7 == 0)) {
          trap(0x1c00);
        }
        goto LAB_00408934;
      case (char *)0xa:
        uVar8 = 0;
        if ((uVar7 != 0) && (uVar8 = (int)uVar6 % (int)uVar7, uVar7 == 0)) {
          trap(0x1c00);
        }
        goto LAB_00408934;
      case (char *)0xb:
        uVar8 = uVar6 << (uVar7 & 0x1f);
        goto LAB_00408934;
      case (char *)0xc:
        uVar8 = (int)uVar6 >> (uVar7 & 0x1f);
        goto LAB_00408934;
      case (char *)0xd:
        uVar8 = uVar6 * uVar7;
        goto LAB_00408934;
      case (char *)0xe:
      default:
        ejError(param_1,"Bad operator %d");
        return 0xffffffff;
      case (char *)0xf:
        uVar8 = uVar6 + 1;
        goto LAB_00408934;
      case (char *)0x10:
        uVar8 = uVar6 - 1;
        goto LAB_00408934;
      case (char *)0x11:
        goto switchD_004089c4_caseD_11;
      }
      uVar8 = bVar2 ^ 1;
      goto LAB_00408934;
    }
  }
code_r0x00408758:
  switch(param_3) {
  case 1:
    uVar8 = (*(code *)PTR_strcmp_004309b4)(param_2,param_4);
    uVar8 = uVar8 >> 0x1f;
    break;
  case 2:
    iVar5 = (*(code *)PTR_strcmp_004309b4)(param_2,param_4);
    uVar8 = (uint)(iVar5 < 1);
    break;
  case 3:
    iVar5 = (*(code *)PTR_strcmp_004309b4)(param_2,param_4);
    uVar8 = (uint)(0 < iVar5);
    break;
  case 4:
    uVar7 = (*(code *)PTR_strcmp_004309b4)(param_2,param_4);
    uVar8 = ~uVar7 >> 0x1f;
    break;
  case 5:
    uVar7 = (*(code *)PTR_strcmp_004309b4)(param_2,param_4);
switchD_004089c4_caseD_11:
    uVar8 = (uint)(uVar7 == 0);
    break;
  case 6:
    iVar5 = (*(code *)PTR_strcmp_004309b4)(param_2,param_4);
    uVar8 = (uint)(iVar5 != 0);
    break;
  case 7:
    param_1 = param_1 + 0x14;
    local_18 = param_2;
    FUN_00408080(param_1);
    FUN_00408128(param_1,local_18);
    FUN_00408128(param_1,param_4);
    return 0;
  default:
    ejError(param_1,"Bad operator");
    return 0xffffffff;
  }
LAB_00408934:
  stritoa(uVar8,auStack40,0x10);
  FUN_004080c8(param_1 + 0x14,auStack40);
  return 0;
}

