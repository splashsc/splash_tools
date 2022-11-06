
int FUN_0040932c(int param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 local_188;
  undefined4 local_184;
  undefined4 local_180;
  undefined4 local_17c;
  undefined4 local_178;
  undefined auStack372 [56];
  undefined4 local_13c;
  undefined auStack292 [56];
  undefined4 local_ec;
  undefined auStack212 [56];
  undefined4 local_9c;
  undefined auStack132 [56];
  undefined4 local_4c;
  int local_30;
  uint local_2c;
  
  local_9c = 0;
  local_ec = 0;
  local_13c = 0;
  local_4c = 0;
switchD_004093cc_caseD_c:
  iVar1 = ejLexGetToken(param_1,param_2);
  switch(iVar1) {
  case 0:
  case 4:
  case 7:
  case 8:
  case 0xf:
  case 0x11:
  case 0x13:
    break;
  case 1:
    if (param_2 != 6) goto LAB_00409d00;
    iVar1 = FUN_00409df4(param_1,4,param_3);
    param_2 = -1;
    if (iVar1 != 5) goto LAB_00409d88;
    iVar1 = ejLexGetToken(param_1,6);
    if (iVar1 == 2) {
      return 7;
    }
    goto LAB_00409d8c;
  case 2:
    ejLexPutbackToken(param_1,2,*(undefined4 *)(param_1 + 0x1c));
    goto LAB_00409bcc;
  case 3:
    if ((((param_2 != 8) || (iVar1 = ejLexGetToken(param_1,8), iVar1 != 1)) ||
        (iVar1 = FUN_00409df4(param_1,2,param_3), iVar1 != 3)) ||
       (iVar1 = ejLexGetToken(param_1,8), iVar1 != 2)) goto LAB_00409d88;
    if (**(char **)(param_1 + 0x14) == '1') {
      uVar3 = param_3;
      param_3 = param_3 & 0xfffffffe;
    }
    else {
      uVar3 = param_3 & 0xfffffffe;
    }
    iVar1 = FUN_00409df4(param_1,8,uVar3);
    if (iVar1 == 9) goto LAB_00409844;
    goto LAB_004098b8;
  case 5:
    if (param_2 == 8) {
      do {
        iVar1 = FUN_00409df4(param_1,8,param_3);
      } while (iVar1 == 9);
      if (iVar1 == 0x14) {
        return 0x14;
      }
      iVar1 = ejLexGetToken(param_1,iVar1);
      if (iVar1 == 6) {
        return 9;
      }
    }
    goto LAB_00409d88;
  case 6:
    if (param_2 == 8) {
      ejLexPutbackToken(param_1,6,*(undefined4 *)(param_1 + 0x1c));
      return 10;
    }
    goto LAB_00409d88;
  case 9:
    if (param_2 == 8) goto LAB_00409d00;
    iVar7 = 9;
    goto LAB_00409b4c;
  case 10:
    FUN_004080c8(param_1 + 0x14,*(undefined4 *)(param_1 + 0x1c));
    goto LAB_00409780;
  case 0xb:
    local_17c = 0;
    local_178 = 0;
    uVar5 = *(undefined4 *)(param_1 + 0x10);
    local_180 = 0;
    FUN_004080c8(&local_180,*(undefined4 *)(param_1 + 0x1c));
    *(undefined4 **)(param_1 + 0x10) = &local_180;
    FUN_004080c8(param_1 + 0x14,&DAT_0041ed68);
    iVar7 = ejLexGetToken(param_1,param_2);
    if (iVar7 != 1) {
      FUN_00408214(&local_180);
      goto LAB_00409d88;
    }
    iVar7 = FUN_00409df4(param_1,0xb,param_3);
    if (iVar7 == 0xc) {
      if ((param_3 & 1) == 0) {
LAB_0040974c:
        FUN_00408214(&local_180);
        *(undefined4 *)(param_1 + 0x10) = uVar5;
        iVar7 = ejLexGetToken(param_1,param_2);
        if (iVar7 == 2) goto LAB_00409780;
        goto LAB_00409d88;
      }
      iVar7 = symLookup(*(undefined4 *)(param_1 + 4),**(undefined4 **)(param_1 + 0x10));
      puVar4 = *(undefined4 **)(param_1 + 0x10);
      if ((iVar7 == 0) || (*(code **)(iVar7 + 0x12) == (code *)0x0)) {
        ejError(param_1,"Undefined procedure %s",*puVar4);
      }
      else {
        iVar7 = (**(code **)(iVar7 + 0x12))
                          (*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_1 + 0x2c),puVar4[2]
                           ,puVar4[1]);
        if (-1 < iVar7) goto LAB_0040974c;
      }
    }
    FUN_00408214(&local_180);
    *(undefined4 *)(param_1 + 0x10) = uVar5;
    goto LAB_00409d88;
  case 0xd:
    local_188 = 0;
    FUN_004080c8(&local_188,*(undefined4 *)(param_1 + 0x1c));
    iVar1 = ejLexGetToken(param_1,param_2);
    if (iVar1 == 0x11) {
      iVar7 = FUN_00409df4(param_1,4,param_3);
      if (iVar7 != 5) {
        FUN_00408080(&local_188);
        goto LAB_00409d88;
      }
      if ((param_3 & 1) != 0) {
        uVar5 = *(undefined4 *)(param_1 + 0x24);
        if (param_2 == 0x12) {
          uVar8 = *(undefined4 *)(param_1 + 0x14);
        }
        else {
          iVar7 = FUN_00409260(uVar5,local_188,&local_184);
          uVar5 = *(undefined4 *)(param_1 + 0x24);
          uVar8 = *(undefined4 *)(param_1 + 0x14);
          if (iVar7 < 1) {
LAB_00409530:
            FUN_00409028(uVar5,local_188,uVar8);
            goto LAB_00409608;
          }
        }
LAB_00409520:
        FUN_00408f78(uVar5,local_188,uVar8);
      }
    }
    else {
      local_184 = 0;
      if (iVar1 == 0x13) {
        if ((param_3 & 1) == 0) goto LAB_00409608;
        iVar7 = FUN_00409260(*(undefined4 *)(param_1 + 0x24),local_188,&local_184);
        if (iVar7 < 0) {
          ejError(param_1,"Undefined variable %s\n",local_188);
          goto LAB_00409d88;
        }
        FUN_004080c8(param_1 + 0x14,local_184);
        iVar2 = FUN_004086ac(param_1,local_184,(int)**(char **)(param_1 + 0x1c),&DAT_0041eb34);
        if (-1 < iVar2) {
          uVar5 = *(undefined4 *)(param_1 + 0x24);
          uVar8 = *(undefined4 *)(param_1 + 0x14);
          if (iVar7 == 0) goto LAB_00409530;
          goto LAB_00409520;
        }
        param_2 = -1;
        goto switchD_004093cc_caseD_c;
      }
      if (param_2 == 0x12) {
        iVar7 = FUN_00409260(*(undefined4 *)(param_1 + 0x24),local_188,&local_184);
        if (0 < iVar7) {
          pcVar6 = "Variable already declared";
LAB_004095c4:
          param_2 = -1;
          ejError(param_1,pcVar6,local_188);
          FUN_00408080(&local_188);
          goto LAB_00409d00;
        }
        FUN_00408f78(*(undefined4 *)(param_1 + 0x24),local_188,0);
      }
      else if (((param_3 & 1) != 0) &&
              (iVar7 = FUN_00409260(*(undefined4 *)(param_1 + 0x24),local_188,&local_184), iVar7 < 0
              )) {
        pcVar6 = "Undefined variable %s\n";
        goto LAB_004095c4;
      }
      FUN_004080c8(param_1 + 0x14,local_184);
      ejLexPutbackToken(param_1,iVar1,*(undefined4 *)(param_1 + 0x1c));
    }
LAB_00409608:
    FUN_00408080(&local_188);
LAB_00409780:
    if (param_2 != 8) goto LAB_00409d00;
    iVar1 = ejLexGetToken(param_1,8);
    if ((iVar1 == 9) || (iVar1 == 0xc)) goto LAB_00409cd4;
    goto switchD_004093cc_caseD_ffffffff;
  case 0xe:
    param_2 = 1;
    goto LAB_00409d00;
  case 0x10:
    iVar7 = FUN_00409df4(param_1,0x10,param_3);
    if (iVar7 != 0x11) goto LAB_00409d88;
    goto LAB_00409d00;
  case 0x12:
    if (((param_2 != 8) || (iVar7 = ejLexGetToken(param_1,8), iVar7 != 1)) ||
       (iVar7 = FUN_00409df4(param_1,6,param_3), iVar7 != 7)) goto LAB_00409ddc;
    iVar7 = ejLexGetToken(param_1,8);
    if (iVar7 != 9) goto LAB_00409ddc;
    ejLexSaveInputState(param_1,auStack132);
    iVar7 = FUN_00409df4(param_1,2,param_3);
    if (iVar7 != 3) goto LAB_00409ddc;
    local_30 = (int)**(char **)(param_1 + 0x14);
    iVar7 = ejLexGetToken(param_1,8);
    if (iVar7 != 9) goto LAB_00409ddc;
    ejLexSaveInputState(param_1,auStack372);
    iVar7 = FUN_00409df4(param_1,6,param_3 & 0xfffffffe);
    if (iVar7 != 7) goto LAB_00409ddc;
    iVar7 = ejLexGetToken(param_1,8);
    if (iVar7 != 2) goto LAB_00409ddc;
    ejLexSaveInputState(param_1,auStack292);
    iVar7 = FUN_00409df4(param_1,8,param_3 & 0xfffffffe);
    if (iVar7 != 9) goto LAB_00409ddc;
    local_2c = (uint)(local_30 != 0x30);
    ejLexSaveInputState(param_1,auStack212);
    uVar3 = local_2c;
    goto LAB_00409af4;
  case 0x14:
    iVar1 = FUN_00409df4(param_1,4,param_3);
    if (iVar1 == 5) goto code_r0x00409c74;
    goto LAB_00409d88;
  case -1:
    goto switchD_004093cc_caseD_ffffffff;
  }
  iVar7 = 8;
  goto LAB_00409b4c;
code_r0x00409c74:
  if ((param_3 & 1) != 0) {
    do {
      iVar1 = ejLexGetToken(param_1,param_2);
    } while (iVar1 != 0xe);
    return 0x14;
  }
  goto switchD_004093cc_caseD_c;
LAB_00409af4:
  if ((uVar3 == 0) || ((param_3 & 1) == 0)) goto LAB_00409b08;
  ejLexRestoreInputState(param_1,auStack292);
  iVar7 = FUN_00409df4(param_1,8,param_3);
  if (iVar7 == 9) {
    ejLexRestoreInputState(param_1,auStack372);
    iVar7 = FUN_00409df4(param_1,6,param_3);
    if (iVar7 != 7) goto LAB_00409ddc;
    ejLexRestoreInputState(param_1,auStack132);
    iVar7 = FUN_00409df4(param_1,2,param_3);
    if (iVar7 != 3) goto LAB_00409ddc;
    uVar3 = (uint)(**(char **)(param_1 + 0x14) != '0');
    goto LAB_00409af4;
  }
  if (iVar7 == 0x14) {
    return 0x14;
  }
LAB_00409ddc:
  param_2 = -1;
  goto LAB_00409d08;
LAB_00409b08:
  ejLexRestoreInputState(param_1,auStack212);
  goto LAB_00409d00;
LAB_00409844:
  do {
    iVar1 = ejLexGetToken(param_1,8);
  } while (iVar1 == 0xc);
  ejLexPutbackToken(param_1,iVar1,*(undefined4 *)(param_1 + 0x1c));
  iVar7 = ejLexGetToken(param_1,8);
  iVar1 = iVar7;
  if (iVar7 != 4) goto LAB_00409b4c;
  iVar1 = FUN_00409df4(param_1,8,param_3);
  if (iVar1 == 9) goto LAB_00409d64;
LAB_004098b8:
  if (iVar1 == 0x14) {
    return 0x14;
  }
LAB_00409d88:
  param_2 = -1;
  goto LAB_00409d8c;
switchD_004093cc_caseD_ffffffff:
  param_2 = -1;
  goto LAB_00409d00;
LAB_00409cd4:
  do {
    iVar7 = ejLexGetToken(param_1,8);
  } while (iVar7 == 0xc);
LAB_00409b4c:
  ejLexPutbackToken(param_1,iVar7,*(undefined4 *)(param_1 + 0x1c));
LAB_00409d00:
  if (iVar1 == 0x12) {
LAB_00409d08:
    ejLexFreeInputState(param_1,auStack132);
    ejLexFreeInputState(param_1,auStack372);
    ejLexFreeInputState(param_1,auStack212);
    ejLexFreeInputState(param_1,auStack292);
  }
LAB_00409d64:
  if (param_2 == 8) {
    param_2 = 9;
  }
  else if (param_2 == 0x12) {
    param_2 = 0x13;
  }
  else if (param_2 == 6) {
LAB_00409bcc:
    param_2 = 7;
  }
  else {
LAB_00409d8c:
    if (param_2 != 1) {
      param_2 = -1;
    }
  }
  return param_2;
}

