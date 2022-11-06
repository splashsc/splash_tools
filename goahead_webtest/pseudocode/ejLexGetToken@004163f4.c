
int ejLexGetToken(int *param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar8 = *param_1;
  param_1[8] = -1;
  param_1[7] = (int)&DAT_0041ed68;
  ringqFlush(iVar8);
  if (*(int *)(iVar8 + 0x3c) < 1) {
    iVar2 = FUN_00415e9c(param_1);
    iVar7 = 0xe;
    if (-1 < iVar2) {
LAB_004164b8:
      puVar1 = PTR___ctype_b_00430aa4;
      if (iVar2 == 0x2a) {
        uVar4 = 0xd;
        goto LAB_00416700;
      }
      if (iVar2 < 0x2b) {
        if (iVar2 == 0x21) {
          iVar8 = FUN_00415e9c(param_1);
          if (-1 < iVar8) {
            uVar4 = 6;
            if (iVar8 != 0x3d) {
              FUN_00415f84(param_1,iVar8);
              uVar4 = 0x11;
            }
            goto LAB_00416700;
          }
        }
        else {
          if (iVar2 < 0x22) {
            if (iVar2 == 10) {
              iVar7 = 0xc;
              goto LAB_00416d88;
            }
            if (iVar2 < 0xb) {
              iVar7 = 9;
              if (iVar2 == -1) {
                iVar7 = 0xe;
                goto LAB_00416d88;
              }
LAB_00416504:
              if (iVar2 != iVar7) goto LAB_00416b7c;
            }
            else {
              iVar7 = 0x20;
              if (iVar2 != 0xd) goto LAB_00416504;
            }
            do {
              iVar2 = FUN_00415e9c(param_1);
              if (iVar2 < 0) break;
            } while (((iVar2 == 0x20) || (iVar2 == 9)) || (iVar2 == 0xd));
            goto LAB_004164b8;
          }
          if (iVar2 == 0x26) {
            iVar8 = FUN_00415e9c(param_1);
            uVar4 = 1;
            if (iVar8 != 0x26) goto LAB_00416958;
LAB_0041692c:
            iVar7 = 7;
            FUN_00415e10(param_1,uVar4);
            goto LAB_00416d88;
          }
          if (iVar2 < 0x27) {
            if (iVar2 != 0x22) {
              if (iVar2 == 0x25) {
                uVar4 = 10;
                goto LAB_00416700;
              }
              goto LAB_00416b7c;
            }
          }
          else {
            if (iVar2 == 0x28) {
              FUN_00415e10(param_1,0x28);
              iVar7 = 1;
              goto LAB_00416d88;
            }
            if (0x28 < iVar2) {
              FUN_00415e10(param_1,0x29);
              iVar7 = 2;
              goto LAB_00416d88;
            }
          }
          iVar8 = FUN_00415e9c(param_1);
          puVar1 = PTR___ctype_b_00430aa4;
          if (-1 < iVar8) goto LAB_00416b04;
        }
LAB_00416958:
        pcVar5 = "Syntax Error";
        goto LAB_00416adc;
      }
      if (iVar2 == 0x3b) {
        FUN_00415e10(param_1,0x3b);
        iVar7 = 9;
        goto LAB_00416d88;
      }
      if (iVar2 < 0x3c) {
        if (iVar2 != 0x2d) {
          if (iVar2 < 0x2e) {
            if (iVar2 == 0x2b) {
              iVar8 = FUN_00415e9c(param_1);
              if (iVar8 < 0) goto LAB_00416958;
              if (iVar8 == 0x2b) {
                uVar4 = 0xf;
                goto LAB_00416710;
              }
              FUN_00415f84(param_1,iVar8);
              uVar4 = 7;
              goto LAB_00416700;
            }
            if (iVar2 != 0x2c) goto LAB_00416b7c;
            FUN_00415e10(param_1,0x2c);
            iVar7 = 0xf;
            goto LAB_00416d88;
          }
          if (iVar2 != 0x2f) {
            if ((iVar2 < 0x2f) || (0x39 < iVar2)) goto LAB_00416b7c;
            goto LAB_00416b18;
          }
          iVar7 = FUN_00415e9c(param_1);
          if (iVar7 < 0) goto LAB_00416958;
          if ((iVar7 != 0x2a) && (iVar7 != 0x2f)) {
            FUN_00415f84(param_1,iVar7);
            uVar4 = 9;
            goto LAB_00416700;
          }
          do {
            while( true ) {
              do {
                while( true ) {
                  iVar2 = FUN_00415e9c(param_1);
                  if (iVar2 < 0) goto LAB_00416958;
                  if (iVar2 != 10) break;
                  if (iVar7 == 0x2f) goto LAB_004167c0;
                }
              } while (iVar2 != 0x2a);
              iVar2 = FUN_00415e9c(param_1);
              if (iVar7 != 0x2f) break;
              if (iVar2 == 10) goto LAB_004167c0;
            }
          } while (iVar2 != 0x2f);
LAB_004167c0:
          iVar2 = FUN_00415e9c(param_1);
          if (iVar2 < 0) goto code_r0x004167d4;
          goto LAB_004164b8;
        }
        iVar8 = FUN_00415e9c(param_1);
        if (iVar8 < 0) goto LAB_00416958;
        uVar4 = 0x10;
        if (iVar8 == 0x2d) {
LAB_00416710:
          iVar7 = 0x13;
          FUN_00415e10(param_1,uVar4);
          goto LAB_00416d88;
        }
        FUN_00415f84(param_1,iVar8);
        uVar4 = 8;
      }
      else {
        if (iVar2 == 0x3e) {
          iVar8 = FUN_00415e9c(param_1);
          if (iVar8 < 0) goto LAB_00416958;
          if (iVar8 == 0x3e) {
            uVar4 = 0xc;
            goto LAB_00416700;
          }
          uVar4 = 4;
          if (iVar8 == 0x3d) goto LAB_00416700;
          uVar4 = 3;
LAB_00416850:
          FUN_00415e10(param_1,uVar4);
          FUN_00415f84(param_1,iVar8);
LAB_00416708:
          iVar7 = 8;
          goto LAB_00416d88;
        }
        if (0x3e < iVar2) {
          if (iVar2 != 0x7c) {
            if (iVar2 == 0x7d) {
              FUN_00415e10(param_1,0x7d);
              iVar7 = 6;
            }
            else {
              if (iVar2 != 0x7b) goto LAB_00416b7c;
              FUN_00415e10(param_1,0x7b);
              iVar7 = 5;
            }
            goto LAB_00416d88;
          }
          iVar8 = FUN_00415e9c(param_1);
          uVar4 = 2;
          if (iVar8 == 0x7c) goto LAB_0041692c;
          goto LAB_00416958;
        }
        if (iVar2 == 0x3c) {
          iVar8 = FUN_00415e9c(param_1);
          if (iVar8 < 0) goto LAB_00416958;
          if (iVar8 == 0x3c) {
            uVar4 = 0xb;
          }
          else {
            uVar4 = 2;
            if (iVar8 != 0x3d) {
              uVar4 = 1;
              goto LAB_00416850;
            }
          }
          goto LAB_00416700;
        }
        if (iVar2 != 0x3d) goto LAB_00416b7c;
        iVar8 = FUN_00415e9c(param_1);
        if (iVar8 < 0) goto LAB_00416958;
        uVar4 = 5;
        if (iVar8 != 0x3d) {
          FUN_00415f84(param_1,iVar8);
          iVar7 = 0x11;
          goto LAB_00416d88;
        }
      }
LAB_00416700:
      FUN_00415e10(param_1,uVar4);
      goto LAB_00416708;
    }
  }
  else {
    ringqPutStr(iVar8,*(undefined4 *)(iVar8 + 0x38));
    iVar7 = *(int *)(iVar8 + 0x3c);
    *(undefined4 *)(iVar8 + 0x3c) = 0;
    param_1[7] = *(int *)(iVar8 + 4);
  }
  goto LAB_00416d88;
LAB_00416b04:
  do {
    if (iVar8 == iVar2) {
      iVar7 = 10;
      goto LAB_00416d88;
    }
    if (iVar8 == 0x5c) {
      iVar8 = FUN_00415e9c(param_1);
      if ((*(ushort *)(*(int *)puVar1 + iVar8 * 2) & 8) == 0) {
        if (iVar8 == 0x6e) {
          iVar8 = 10;
        }
        else if (iVar8 < 0x6f) {
          if (iVar8 == 0x62) {
            iVar8 = 8;
          }
          else if (iVar8 < 99) {
            if (((iVar8 != 0x27) && (iVar8 != 0x5c)) && (iVar8 != 0x22)) {
LAB_00416aa0:
              pcVar5 = "Invalid Escape Sequence";
              goto LAB_00416adc;
            }
          }
          else {
            if (iVar8 != 0x66) goto LAB_00416aa0;
            iVar8 = 0xc;
          }
        }
        else if (iVar8 == 0x74) {
          iVar8 = 9;
        }
        else if (iVar8 < 0x75) {
          if (iVar8 != 0x72) goto LAB_00416aa0;
          iVar8 = 0xd;
        }
        else {
          if (iVar8 != 0x75) {
            if (iVar8 == 0x78) {
              uVar4 = 0x10;
              uVar6 = 2;
              goto LAB_00416a60;
            }
            goto LAB_00416aa0;
          }
          iVar7 = FUN_00415fec(param_1,0x10,2);
          iVar8 = FUN_00415fec(param_1,0x10,2);
          iVar8 = iVar7 * 0x10 + iVar8;
        }
      }
      else {
        FUN_00415f84(param_1,iVar8);
        uVar4 = 8;
        uVar6 = 3;
LAB_00416a60:
        iVar8 = FUN_00415fec(param_1,uVar4,uVar6);
      }
    }
    iVar8 = FUN_00415e10(param_1,iVar8);
    if (iVar8 < 0) goto LAB_00416d84;
    iVar8 = FUN_00415e9c(param_1);
  } while (-1 < iVar8);
  pcVar5 = "Unmatched Quote";
LAB_00416adc:
  ejError(param_1,pcVar5);
LAB_00416c34:
  iVar7 = -1;
  goto LAB_00416d88;
LAB_00416d84:
  iVar7 = -1;
  goto LAB_00416d88;
code_r0x004167d4:
  iVar7 = 0xe;
  goto LAB_00416d88;
LAB_00416b7c:
  while ((iVar2 == 0x5c || (iVar7 = FUN_00415e10(param_1,iVar2), -1 < iVar7))) {
    while( true ) {
      iVar2 = FUN_00415e9c(param_1);
      if (iVar2 < 0) goto LAB_00416be4;
      if ((((*(ushort *)(*(int *)puVar1 + iVar2 * 2) & 0x800) != 0) || (iVar2 == 0x24)) ||
         (iVar2 == 0x5f)) break;
      if (iVar2 != 0x5c) goto LAB_00416be4;
    }
  }
LAB_00416be4:
  uVar3 = (uint)**(byte **)(iVar8 + 4);
  if ((((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + uVar3 * 2) & 4) != 0) || (uVar3 == 0x24)) ||
     (uVar3 == 0x5f)) {
    if (param_2 == 8) {
      iVar9 = param_1[7];
      iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar9,&DAT_0041f330);
      iVar7 = 3;
      if (iVar8 == 0) goto LAB_00416d88;
      iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar9,&DAT_0041f334);
      iVar7 = 4;
      if (iVar8 == 0) goto LAB_00416d88;
      iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar9,&DAT_0041f33c);
      iVar7 = 0x10;
      if (iVar8 == 0) goto LAB_00416d88;
      iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar9,&DAT_0041f340);
      iVar7 = 0x12;
      if (iVar8 == 0) goto LAB_00416d88;
      iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar9,"return");
      if (iVar8 == 0) {
        if ((iVar2 == 0x3b) || (iVar7 = 0x14, iVar2 == 0x28)) {
          FUN_00415f84(param_1,iVar2);
          iVar7 = 0x14;
        }
        goto LAB_00416d88;
      }
    }
    do {
      if ((((iVar2 != 0x20) && (iVar2 != 9)) && (iVar2 != 0xd)) && (iVar2 != 10)) {
        iVar7 = 0xd;
        if (iVar2 == 0x28) {
          iVar7 = 0xb;
        }
        goto LAB_00416d60;
      }
      iVar2 = FUN_00415e9c(param_1);
    } while (-1 < iVar2);
    iVar7 = 0xd;
LAB_00416d60:
    FUN_00415f84(param_1,iVar2);
    goto LAB_00416d88;
  }
  ejError(param_1,"Invalid identifier %s");
  goto LAB_00416c34;
  while ((iVar2 = FUN_00415e9c(param_1), -1 < iVar2 &&
         ((*(ushort *)(*(int *)puVar1 + iVar2 * 2) & 8) != 0))) {
LAB_00416b18:
    iVar8 = FUN_00415e10(param_1,iVar2);
    if (iVar8 < 0) goto LAB_00416d84;
  }
  FUN_00415f84(param_1,iVar2);
  iVar7 = 10;
LAB_00416d88:
  param_1[8] = iVar7;
  return iVar7;
}

