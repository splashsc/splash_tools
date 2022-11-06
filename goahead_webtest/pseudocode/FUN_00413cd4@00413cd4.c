
uint FUN_00413cd4(int param_1,int *param_2,int *param_3)

{
  char *pcVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined *puVar6;
  char *pcVar7;
  int iVar8;
  undefined *puVar9;
  char *local_948;
  int local_944;
  undefined auStack2368 [256];
  undefined auStack2112 [2048];
  char *local_40;
  int local_3c;
  int local_38;
  char *local_34;
  char *local_30;
  int local_2c;
  
  *param_2 = 0;
  *param_3 = 0;
  local_944 = 0;
  if (*(int *)(param_1 + 0xfc) == 8) {
    iVar8 = *(int *)(param_1 + 0x108);
    if (iVar8 < 0x7ff) {
      if (iVar8 < 1) goto LAB_00413dec;
    }
    else {
      iVar8 = 0x7fe;
    }
    iVar8 = socketRead(*(undefined4 *)(param_1 + 0xf0),auStack2112,iVar8);
    if (iVar8 < 0) {
      websDone(param_1,0);
      return 0xffffffff;
    }
    if (iVar8 != 0) {
      auStack2112[iVar8] = 0;
      local_944 = ballocAscToUni(auStack2112,iVar8);
      if (local_944 == 0) {
        websError(param_1,0x1f7,"Insufficient memory");
        return 0xffffffff;
      }
LAB_00414960:
      *param_2 = local_944;
      *param_3 = iVar8;
      return 1;
    }
    iVar8 = socketEof(*(undefined4 *)(param_1 + 0xf0));
    if (iVar8 == 0) {
      return 0xffffffff;
    }
  }
  else {
LAB_00413dec:
    iVar8 = socketGets(*(undefined4 *)(param_1 + 0xf0),&local_944);
    if (-1 < iVar8) {
      if (iVar8 == 0) {
        if (*(int *)(param_1 + 0xfc) != 2) {
          return 0xffffffff;
        }
        FUN_00411dc4(param_1,"HTTP_AUTHORIZATION",&DAT_0041ed68);
        pcVar1 = *(char **)(param_1 + 4);
LAB_004148f4:
        while( true ) {
          while( true ) {
            while( true ) {
              do {
                if ((pcVar1 == (char *)0x0) || (*pcVar1 == '\0')) {
                  if ((*(uint *)(param_1 + 0x100) & 0x20) == 0) {
                    websUrlHandlerRequest(param_1);
                    return 0xffffffff;
                  }
                  if ((*(uint *)(param_1 + 0x100) & 0x400) == 0) {
                    *(undefined4 *)(param_1 + 0xfc) = 4;
                    return 0;
                  }
                  *(undefined4 *)(param_1 + 0xfc) = 8;
                  return (uint)(*(int *)(param_1 + 0x108) < 1);
                }
                iVar8 = (*(code *)PTR_strchr_00430950)(pcVar1,10);
                local_30 = (char *)((uint)(iVar8 != 0) + iVar8);
                iVar8 = (*(code *)PTR_strtok_004309f0)(pcVar1,&DAT_0041ed64);
                pcVar1 = local_30;
              } while (iVar8 == 0);
              pcVar1 = (char *)(*(code *)PTR_strtok_004309f0)(0,"\n");
              if (pcVar1 == (char *)0x0) {
                pcVar1 = &DAT_0041ed68;
              }
              do {
                pcVar7 = pcVar1;
                pcVar1 = pcVar7 + 1;
              } while ((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + *pcVar7 * 2) & 0x20) != 0);
              strlower(iVar8);
              iVar2 = (*(code *)PTR_strlen_0043095c)(iVar8);
              fmtAlloc(&local_948,iVar2 + 6,"HTTP_%s",iVar8);
              for (pcVar1 = local_948; *pcVar1 != '\0'; pcVar1 = pcVar1 + 1) {
                if (*pcVar1 == '-') {
                  *pcVar1 = '_';
                }
              }
              strupper(local_948);
              FUN_00411dc4(param_1,local_948,pcVar7);
              bfree(local_948);
              iVar2 = (*(code *)PTR_strcmp_004309b4)(iVar8,"user-agent");
              if (iVar2 != 0) break;
              uVar3 = bstrdup(pcVar7);
              *(undefined4 *)(param_1 + 0xdc) = uVar3;
              pcVar1 = local_30;
            }
            iVar2 = strcmpci(iVar8,"authorization");
            if (iVar2 == 0) break;
            iVar2 = (*(code *)PTR_strcmp_004309b4)(iVar8,"content-length");
            if (iVar2 == 0) {
              iVar8 = (*(code *)PTR_atoi_0043096c)(pcVar7);
              *(int *)(param_1 + 0x108) = iVar8;
              if (iVar8 < 1) {
                *(undefined4 *)(param_1 + 0x108) = 0;
                pcVar1 = local_30;
              }
              else {
                *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x400;
                FUN_00411dc4(param_1,"CONTENT_LENGTH",pcVar7);
                pcVar1 = local_30;
              }
            }
            else {
              iVar2 = (*(code *)PTR_strcmp_004309b4)(iVar8,"content-type");
              if (iVar2 == 0) {
                FUN_00411dc4(param_1,"CONTENT_TYPE",pcVar7);
                iVar8 = (*(code *)PTR_strncmp_00430a08)(pcVar7,"multipart/form-data",0x13);
                puVar6 = PTR_strstr_00430a14;
                pcVar1 = local_30;
                if (iVar8 == 0) {
                  *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x80000;
                  iVar8 = (*(code *)puVar6)(pcVar7,"boundary=");
                  pcVar1 = local_30;
                  if (iVar8 != 0) {
                    local_2c = iVar8 + 9;
                    iVar8 = (*(code *)PTR_strlen_0043095c)(iVar8 + 9);
                    uVar3 = balloc(iVar8 + 2);
                    puVar6 = PTR_sprintf_004309a0;
                    *(undefined4 *)(param_1 + 0xe0) = uVar3;
                    (*(code *)puVar6)(uVar3,&DAT_0041ee3c,local_2c);
                    pcVar1 = local_30;
                  }
                }
              }
              else {
                iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar8,"cookie");
                pcVar1 = local_30;
                if (iVar8 == 0) {
                  *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 8;
                  uVar3 = bstrdup(pcVar7);
                  *(undefined4 *)(param_1 + 0xd8) = uVar3;
                  pcVar1 = local_30;
                }
              }
            }
          }
          pcVar4 = (char *)bstrdup(pcVar7);
          pcVar1 = pcVar4;
          do {
            pcVar5 = pcVar1;
            pcVar1 = pcVar5 + 1;
          } while ((*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + *pcVar5 * 2) & 4) != 0);
          *pcVar5 = '\0';
          uVar3 = bstrdup(pcVar4);
          *(undefined4 *)(param_1 + 0xcc) = uVar3;
          bfree(pcVar4);
          iVar8 = strcmpci(*(undefined4 *)(param_1 + 0xcc),"basic");
          if (iVar8 != 0) break;
          puVar6 = (undefined *)(*(code *)PTR_strchr_00430950)(pcVar7,0x20);
          if (puVar6 != (undefined *)0x0) {
            *puVar6 = 0;
            bfree(*(undefined4 *)(param_1 + 0xcc));
            uVar3 = bstrdup(pcVar7);
            *(undefined4 *)(param_1 + 0xcc) = uVar3;
            pcVar7 = puVar6 + 1;
          }
          websDecode64(auStack2368,pcVar7,0xfe);
          puVar6 = (undefined *)(*(code *)PTR_strchr_00430950)(auStack2368,0x3a);
          puVar9 = puVar6 + 1;
          if ((puVar6 == (undefined *)0x0) || (*puVar6 = 0, puVar9 == (undefined *)0x0)) {
            uVar3 = bstrdup(&DAT_0041ed68);
            *(undefined4 *)(param_1 + 0xd4) = uVar3;
            puVar9 = &DAT_0041ed68;
          }
          else {
            uVar3 = bstrdup(auStack2368);
            *(undefined4 *)(param_1 + 0xd4) = uVar3;
          }
          uVar3 = bstrdup(puVar9);
          *(undefined4 *)(param_1 + 0xd0) = uVar3;
          *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x10000;
          pcVar1 = local_30;
        }
        *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x20000;
        do {
          while ((((pcVar4 = pcVar7, iVar8 = (int)*pcVar4,
                   (*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + iVar8 * 2) & 0x800) != 0 ||
                   (iVar8 == 0x2f)) || (iVar8 == 0x5f)) || (iVar8 == 0x2e))) {
            pcVar7 = pcVar4 + 1;
          }
          pcVar7 = pcVar4 + 1;
        } while (iVar8 == 0x2d);
        for (; ((iVar8 = (int)*pcVar4,
                (*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + iVar8 * 2) & 0x800) == 0 &&
                (iVar8 != 0x2f)) && ((iVar8 != 0x5f && ((iVar8 != 0x2e && (iVar8 != 0x2d))))));
            pcVar4 = pcVar4 + 1) {
        }
        pcVar7 = (char *)(*(code *)PTR_strchr_00430950)(pcVar4,0x3d);
LAB_0041474c:
        puVar6 = PTR___ctype_b_00430aa4;
        pcVar1 = local_30;
        if (pcVar7 != (char *)0x0) {
          for (local_34 = pcVar4;
              (((local_3c = (int)*local_34,
                (*(ushort *)(*(int *)PTR___ctype_b_00430aa4 + local_3c * 2) & 0x800) != 0 ||
                (local_3c == 0x2f)) || (local_3c == 0x5f)) ||
              ((local_3c == 0x2e || (local_3c == 0x2d)))); local_34 = local_34 + 1) {
          }
          *local_34 = '\0';
          while( true ) {
            pcVar7 = pcVar7 + 1;
            iVar8 = (int)*pcVar7;
            pcVar1 = pcVar7;
            if (((*(ushort *)(*(int *)puVar6 + iVar8 * 2) & 0x800) != 0) || (iVar8 == 0x2f)) break;
            if ((iVar8 == 0x5f) || ((iVar8 == 0x2e || (iVar8 == 0x2d)))) break;
          }
          do {
            while ((pcVar5 = pcVar1, local_38 = (int)*pcVar5,
                   (*(ushort *)(*(int *)puVar6 + local_38 * 2) & 0x800) != 0 ||
                   (((local_38 == 0x2f || (local_38 == 0x5f)) || (local_38 == 0x2e))))) {
              pcVar1 = pcVar5 + 1;
            }
            pcVar1 = pcVar5 + 1;
          } while (local_38 == 0x2d);
          *pcVar5 = '\0';
          local_40 = pcVar7;
          iVar8 = strcmpci(pcVar4,"username");
          if (iVar8 == 0) {
            uVar3 = bstrdup(local_40);
            *(undefined4 *)(param_1 + 0xd4) = uVar3;
          }
          else {
            iVar8 = strcmpci(pcVar4,"response");
            if (iVar8 == 0) {
              uVar3 = bstrdup(local_40);
              *(undefined4 *)(param_1 + 0x130) = uVar3;
            }
            else {
              iVar8 = strcmpci(pcVar4,"opaque");
              if (iVar8 == 0) {
                uVar3 = bstrdup(local_40);
                *(undefined4 *)(param_1 + 0x138) = uVar3;
              }
              else {
                iVar8 = strcmpci(pcVar4,&DAT_0041edb8);
                if (iVar8 == 0) {
                  uVar3 = bstrdup(local_40);
                  *(undefined4 *)(param_1 + 0x134) = uVar3;
                }
                else {
                  iVar8 = strcmpci(pcVar4,"realm");
                  if (iVar8 == 0) {
                    uVar3 = bstrdup(local_40);
                    *(undefined4 *)(param_1 + 0x128) = uVar3;
                  }
                  else {
                    iVar8 = strcmpci(pcVar4,"nonce");
                    if (iVar8 == 0) {
                      uVar3 = bstrdup(local_40);
                      *(undefined4 *)(param_1 + 300) = uVar3;
                    }
                    else {
                      iVar8 = strcmpci(pcVar4,&DAT_0041edcc);
                      if (iVar8 == 0) {
                        uVar3 = bstrdup(local_40);
                        *(undefined4 *)(param_1 + 0x13c) = uVar3;
                      }
                      else {
                        iVar8 = strcmpci(pcVar4,"cnonce");
                        if (iVar8 == 0) {
                          uVar3 = bstrdup(local_40);
                          *(undefined4 *)(param_1 + 0x140) = uVar3;
                        }
                        else {
                          iVar8 = strcmpci(pcVar4,&DAT_0041edd8);
                          if (iVar8 == 0) {
                            uVar3 = bstrdup(local_40);
                            *(undefined4 *)(param_1 + 0x144) = uVar3;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
          puVar6 = PTR___ctype_b_00430aa4;
          *local_34 = (char)local_3c;
          *pcVar5 = (char)local_38;
          do {
            while( true ) {
              pcVar4 = pcVar5;
              iVar8 = (int)*pcVar4;
              if (iVar8 == 0) goto LAB_004146f4;
              if ((((*(ushort *)(*(int *)puVar6 + iVar8 * 2) & 0x800) == 0) && (iVar8 != 0x2f)) &&
                 ((iVar8 != 0x5f && (iVar8 != 0x2e)))) break;
              pcVar5 = pcVar4 + 1;
            }
            pcVar5 = pcVar4 + 1;
          } while (iVar8 == 0x2d);
LAB_004146f4:
          do {
            iVar8 = (int)*pcVar4;
            if (iVar8 == 0) goto LAB_00414744;
            if ((((*(ushort *)(*(int *)puVar6 + iVar8 * 2) & 0x800) != 0) || (iVar8 == 0x2f)) ||
               ((iVar8 == 0x5f || ((iVar8 == 0x2e || (iVar8 == 0x2d)))))) {
              pcVar7 = (char *)(*(code *)PTR_strchr_00430950)(pcVar4,0x3d);
              goto LAB_0041474c;
            }
            pcVar4 = pcVar4 + 1;
          } while( true );
        }
        goto LAB_004148f4;
      }
      goto LAB_00414960;
    }
    iVar8 = socketEof(*(undefined4 *)(param_1 + 0xf0));
    if (iVar8 == 0) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0xfc) == 4) {
      websUrlHandlerRequest(param_1);
      return 0xffffffff;
    }
  }
  websDone(param_1,0);
  return 0xffffffff;
LAB_00414744:
  pcVar7 = (char *)0x0;
  goto LAB_0041474c;
}

