
uint FUN_00409df4(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int local_38;
  int local_34;
  int local_30;
  
  switch(param_2) {
  case 2:
    FUN_004080c8(param_1 + 0x14,&DAT_0041ed68);
    iVar4 = 0;
    local_34 = 0;
    local_38 = 0;
    while (iVar6 = FUN_00409df4(param_1,4,param_3), iVar6 == 5) {
      if (0 < iVar4) {
        FUN_004080c8(&local_38,*(undefined4 *)(param_1 + 0x14));
        iVar6 = FUN_004089cc(param_1,local_34,iVar4,local_38);
        if (iVar6 < 0) break;
      }
      FUN_004080c8(&local_34,*(undefined4 *)(param_1 + 0x14));
      iVar6 = ejLexGetToken(param_1,5);
      if (iVar6 == 7) {
        iVar4 = (int)**(char **)(param_1 + 0x1c);
      }
      else {
        if ((iVar6 == 2) || (iVar6 == 9)) {
          param_2 = 3;
          ejLexPutbackToken(param_1);
          goto LAB_0040a270;
        }
        ejLexPutbackToken(param_1);
      }
    }
LAB_0040a26c:
    param_2 = 0xffffffff;
    goto LAB_0040a270;
  case 4:
    FUN_004080c8(param_1 + 0x14,&DAT_0041ed68);
    iVar4 = 0;
    local_38 = 0;
    local_34 = 0;
    iVar6 = 0;
    do {
      if (iVar4 == 7) {
        param_2 = FUN_00409df4(param_1,4,param_3);
        if (param_2 != 5) {
          param_2 = 0xffffffff;
          break;
        }
      }
      else {
        param_2 = FUN_00409df4(param_1,6,param_3);
        if (param_2 != 7) goto LAB_0040a26c;
      }
      if (0 < iVar6) {
        FUN_004080c8(&local_34,*(undefined4 *)(param_1 + 0x14));
        if (iVar4 == 7) {
          iVar4 = FUN_004089cc();
        }
        else {
          iVar4 = FUN_004086ac(param_1,local_38,iVar6,local_34);
        }
        if (iVar4 < 0) goto LAB_0040a26c;
      }
      FUN_004080c8(&local_38,*(undefined4 *)(param_1 + 0x14));
      iVar4 = ejLexGetToken(param_1,param_2);
      if (((iVar4 != 8) && (iVar4 != 0x13)) && (iVar4 != 7)) {
        ejLexPutbackToken(param_1,iVar4);
        param_2 = 5;
        break;
      }
      iVar6 = (int)**(char **)(param_1 + 0x1c);
    } while (param_2 == 7);
LAB_0040a270:
    if (local_34 != 0) {
      bfree();
    }
    if (local_38 != 0) {
      bfree();
    }
    break;
  case 6:
    uVar1 = FUN_0040932c(param_1,6,param_3,param_4,&_mips_gp0_value);
    uVar2 = 7;
    goto LAB_00409eb4;
  case 8:
    uVar1 = FUN_0040932c(param_1,8,param_3,param_4,&_mips_gp0_value);
    if (uVar1 == 9) {
      return 9;
    }
    if (uVar1 == 1) {
      return 1;
    }
    uVar3 = 0x14;
    if (uVar1 == 10) {
      return 10;
    }
    goto LAB_00409ebc;
  case 0xb:
    do {
      param_2 = FUN_00409df4(param_1,4,param_3);
      if ((param_2 == 1) || (param_2 == 0xffffffff)) goto LAB_0040a2b8;
      if (param_2 == 5) {
        iVar4 = hAlloc(*(int *)(param_1 + 0x10) + 4);
        iVar6 = *(int *)(*(int *)(param_1 + 0x10) + 4);
        uVar5 = bstrdup(*(undefined4 *)(param_1 + 0x14));
        *(undefined4 *)(iVar6 + iVar4 * 4) = uVar5;
        *(int *)(*(int *)(param_1 + 0x10) + 8) = *(int *)(*(int *)(param_1 + 0x10) + 8) + 1;
      }
      iVar4 = ejLexGetToken(param_1,param_2);
    } while (iVar4 == 0xf);
    local_30 = iVar4;
    ejLexPutbackToken(param_1,iVar4,*(undefined4 *)(param_1 + 0x1c));
    if (local_30 == 2) {
      param_2 = 0xc;
    }
    else {
      param_2 = -(uint)(param_2 != 5) | 0xc;
    }
    break;
  case 0x10:
    do {
      iVar4 = ejLexGetToken(param_1,0x10);
      if (iVar4 != 0xd) break;
      ejLexPutbackToken(param_1,0xd,*(undefined4 *)(param_1 + 0x1c));
      iVar4 = FUN_00409df4(param_1,0x12,param_3);
      if (iVar4 != 0x13) break;
      iVar4 = ejLexGetToken(param_1,0x10);
      if (iVar4 == 9) {
        param_2 = 0x11;
        goto LAB_0040a2b8;
      }
    } while (iVar4 == 0xf);
    param_2 = 0xffffffff;
    break;
  case 0x12:
    uVar1 = FUN_0040932c(param_1,0x12,param_3,param_4,&_mips_gp0_value);
    uVar2 = 0x13;
LAB_00409eb4:
    uVar3 = 1;
    if (uVar1 == uVar2) {
      return uVar1;
    }
LAB_00409ebc:
    if (uVar1 == uVar3) {
      return uVar1;
    }
    goto LAB_0040a2c0;
  }
LAB_0040a2b8:
  if (param_2 == 0xffffffff) {
LAB_0040a2c0:
    param_2 = 0xffffffff;
    if (*(int *)(param_1 + 0x18) == 0) {
      ejError(param_1,"Syntax error");
    }
  }
  return param_2;
}

