
/* WARNING: Restarted to delay deadcode elimination for space: ram */

void FUN_00414b20(int param_1)

{
  undefined *puVar1;
  int iVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  undefined4 local_118;
  undefined4 local_114;
  undefined4 local_110;
  undefined4 local_10c;
  undefined4 local_108;
  undefined4 local_104;
  undefined4 local_100;
  int local_fc;
  char *local_f8;
  char local_f4 [64];
  char acStack180 [132];
  char *local_30;
  int local_2c;
  
  (*(code *)PTR_memset_004309cc)(local_f4,0,0x40);
  (*(code *)PTR_memset_004309cc)(acStack180,0,0x80);
  websSetTimeMark(param_1);
  local_f8 = (char *)0x0;
  iVar10 = -1;
LAB_00414bbc:
  while( true ) {
    while( true ) {
      if (local_f8 != (char *)0x0) {
        bfree();
        local_f8 = (char *)0x0;
      }
      while (iVar2 = FUN_00413cd4(param_1,&local_f8,&local_fc), pcVar3 = local_f8, iVar4 = local_fc,
            iVar2 == 0) {
        (*(code *)PTR_usleep_00430aa0)(100);
      }
      if (iVar2 < 0) goto LAB_004157b4;
      iVar2 = *(int *)(param_1 + 0xfc);
      if (iVar2 != 2) break;
      iVar4 = ringqLen(param_1);
      if (0 < iVar4) {
        ringqPutStr(param_1,"\n");
      }
      ringqPutStr(param_1,local_f8);
    }
    if (iVar2 < 3) break;
    if (iVar2 == 4) {
      if ((*(uint *)(param_1 + 0x100) & 0x4000) == 0) {
        pcVar3 = *(char **)(param_1 + 0xc4);
        if (((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) ||
           ((*(uint *)(param_1 + 0x100) & 0x2000) != 0)) {
          uVar8 = bstrdup(local_f8);
          *(undefined4 *)(param_1 + 0xc4) = uVar8;
        }
        else {
          iVar4 = (*(code *)PTR_strlen_0043095c)(pcVar3);
          iVar2 = (*(code *)PTR_strlen_0043095c)(local_f8);
          iVar2 = brealloc(pcVar3,iVar4 + iVar2 + 2);
          *(int *)(param_1 + 0xc4) = iVar2;
          if (iVar2 != 0) {
            *(undefined *)(iVar2 + iVar4) = 0x26;
            (*(code *)PTR_strcpy_00430ad8)(*(int *)(param_1 + 0xc4) + iVar4 + 1,local_f8);
          }
        }
      }
      else {
        if (iVar10 == -1) {
          iVar10 = (*(code *)PTR_open_00430958)(*(undefined4 *)(param_1 + 0x114),0x101,0x1b6);
        }
        (*(code *)PTR_write_00430a4c)(iVar10,local_f8,local_fc);
        (*(code *)PTR_write_00430a4c)(iVar10,"\n",1);
      }
      *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x2000;
      goto LAB_004157b4;
    }
    if (iVar2 != 8) goto LAB_00415798;
    if ((*(uint *)(param_1 + 0x100) & 0x4000) == 0) {
      if ((*(uint *)(param_1 + 0x100) & 0x100000) != 0) {
        if (DAT_00430130 == -1) {
          do_prepare_fwupload(param_1);
          (*(code *)PTR_dxmlGetStr_004309b8)(acStack180,"/onetouch/tempdirecory");
          iVar2 = (*(code *)PTR_strlen_0043095c)(acStack180);
          if (acStack180[iVar2] != '/') {
            (*(code *)PTR_strcat_00430a3c)(acStack180,"/");
          }
          (*(code *)PTR_dxmlGetStr_004309b8)(local_f4,"/fwupgradeinfo/fwupgradefn");
          if (local_f4[0] == '\0') {
            (*(code *)PTR_strcpy_00430ad8)(local_f4,"upld.bin");
            (*(code *)PTR_dxmlSetStr_00430954)(local_f4,"/fwupgradeinfo/fwupgradefn");
          }
          (*(code *)PTR_strcat_00430a3c)(acStack180,local_f4);
          if (6 < *(int *)PTR_daemon_log_level_00430990) {
            (*(code *)PTR_logPrintf_00430a1c)
                      (7,"\nsavedfn=\'%s\' ....................................\n\n",acStack180);
          }
          DAT_00430130 = (*(code *)PTR_open_00430958)(acStack180,0x101,0x1b6);
          local_30 = local_f8;
          pcVar7 = (char *)(*(code *)PTR_strstr_00430a14)(local_f8,"Content-Type:");
          pcVar3 = local_30;
          if (pcVar7 != (char *)0x0) {
            if (6 < *(int *)PTR_daemon_log_level_00430990) {
              local_30 = pcVar7;
              (*(code *)PTR_logPrintf_00430a1c)
                        (7,"text=\'%s\' upgrade_len=%d nbytes=%d\n\n",pcVar3,iVar4,local_fc);
              pcVar7 = local_30;
            }
            pcVar3 = (char *)(*(code *)PTR_strstr_00430a14)(pcVar7,&DAT_0041eff8);
            if (pcVar3 != (char *)0x0) {
              *pcVar3 = '\0';
              local_30 = pcVar3;
              iVar4 = (*(code *)PTR_strlen_0043095c)(local_f8);
              local_f8 = local_30 + 4;
              iVar4 = (local_fc + -4) - iVar4;
            }
            if (6 < *(int *)PTR_daemon_log_level_00430990) {
              (*(code *)PTR_logPrintf_00430a1c)
                        (7,"text=\'%s\' upgrade_len=%d nbytes=%d\n\n",local_f8,iVar4,local_fc);
            }
          }
        }
        iVar2 = DAT_00430130;
        if ((*(int *)(param_1 + 0x108) - local_fc < local_fc) && (*(int *)(param_1 + 0xe0) != 0)) {
          if (6 < *(int *)PTR_daemon_log_level_00430990) {
            (*(code *)PTR_logPrintf_00430a1c)(7,"wp->multiPartBoundary=%s, nbytes=%d\n\n");
          }
          pcVar3 = local_f8;
          for (iVar9 = 0; iVar2 = DAT_00430130, iVar9 <= local_fc; iVar9 = iVar9 + 1) {
            if ((*pcVar3 != '\0') &&
               (local_30 = pcVar3, local_2c = iVar9,
               pcVar7 = (char *)(*(code *)PTR_strstr_00430a14)
                                          (pcVar3,*(undefined4 *)(param_1 + 0xe0)),
               pcVar3 = local_30, puVar1 = PTR_strlen_0043095c, iVar9 = local_2c,
               pcVar7 != (char *)0x0)) {
              *pcVar7 = '\0';
              local_30 = pcVar7;
              iVar4 = (*(code *)puVar1)(pcVar3);
              iVar4 = iVar4 + -2 + local_2c;
              iVar2 = DAT_00430130;
              if (6 < *(int *)PTR_daemon_log_level_00430990) {
                (*(code *)PTR_logPrintf_00430a1c)
                          (7,"ptr2=\'%s\' upgrade_len=%d #### nbytes=%d\n\n",local_30 + 1,iVar4,
                           local_fc);
                iVar2 = DAT_00430130;
              }
              break;
            }
            pcVar3 = pcVar3 + 1;
          }
        }
        goto LAB_00415498;
      }
      if (*(int *)(param_1 + 0xec) == 0) {
        uVar8 = bmemdup(local_f8,local_fc);
        *(undefined4 *)(param_1 + 0xec) = uVar8;
        iVar4 = local_fc;
LAB_004155b0:
        *(int *)(param_1 + 0x110) = iVar4;
      }
      else {
        if (local_f8 != (char *)0x0) {
          local_30 = *(char **)(param_1 + 0xc4);
          iVar4 = (*(code *)PTR_strlen_0043095c)(local_30);
          iVar2 = (*(code *)PTR_strlen_0043095c)(pcVar3);
          iVar2 = brealloc(local_30,iVar4 + iVar2 + 1);
          *(int *)(param_1 + 0xc4) = iVar2;
          if (iVar2 != 0) {
            (*(code *)PTR_strcpy_00430ad8)(iVar2 + iVar4,local_f8);
          }
        }
        iVar4 = brealloc(*(undefined4 *)(param_1 + 0xec),*(int *)(param_1 + 0x110) + local_fc + 1);
        *(int *)(param_1 + 0xec) = iVar4;
        if (iVar4 != 0) {
          (*(code *)PTR_memcpy_00430a90)(iVar4 + *(int *)(param_1 + 0x110),local_f8,local_fc);
          iVar4 = *(int *)(param_1 + 0x110) + local_fc;
          goto LAB_004155b0;
        }
      }
    }
    else {
      iVar2 = iVar10;
      if (iVar10 == -1) {
        iVar2 = (*(code *)PTR_open_00430958)(*(undefined4 *)(param_1 + 0x114),0x101,0x1b6);
        iVar4 = local_fc;
        iVar10 = iVar2;
      }
LAB_00415498:
      (*(code *)PTR_write_00430a4c)(iVar2,local_f8,iVar4);
    }
    *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x2000;
    iVar4 = *(int *)(param_1 + 0x108) - local_fc;
    *(int *)(param_1 + 0x108) = iVar4;
    if (iVar4 < 1) {
      if (iVar10 != -1) {
        (*(code *)PTR_close_0043093c)(iVar10);
      }
      if (DAT_00430130 != -1) {
        (*(code *)PTR_close_0043093c)();
        DAT_00430130 = -1;
      }
      iVar10 = -1;
      websUrlHandlerRequest(param_1);
      goto LAB_004157b4;
    }
    if (local_fc < 1) {
LAB_004157b4:
      if (iVar10 != -1) {
        (*(code *)PTR_close_0043093c)(iVar10);
      }
      if (local_f8 != (char *)0x0) {
        bfree();
      }
      return;
    }
  }
  if (iVar2 == 1) {
    pcVar3 = (char *)(*(code *)PTR_strtok_004309f0)(local_f8,&DAT_0041ef1c);
    if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
      iVar4 = (*(code *)PTR_strcmp_004309b4)(pcVar3,&DAT_0041eb58);
      if (iVar4 != 0) {
        iVar4 = (*(code *)PTR_strcmp_004309b4)(pcVar3,&DAT_0041eb50);
        if (iVar4 == 0) {
          uVar5 = *(uint *)(param_1 + 0x100) | 0x20;
        }
        else {
          iVar4 = (*(code *)PTR_strcmp_004309b4)(pcVar3,&DAT_0041eb5c);
          if (iVar4 != 0) {
            uVar8 = 400;
            pcVar3 = "Bad request type";
            goto LAB_004157a4;
          }
          uVar5 = *(uint *)(param_1 + 0x100) | 0x200;
        }
        *(uint *)(param_1 + 0x100) = uVar5;
      }
      FUN_00411dc4(param_1,"REQUEST_METHOD",pcVar3);
      pcVar3 = (char *)(*(code *)PTR_strtok_004309f0)(0,&DAT_0041ef58);
      if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
        uVar8 = (*(code *)PTR_strtok_004309f0)(0,&DAT_0041ef58);
        local_114 = 0;
        local_108 = 0;
        local_100 = 0;
        local_110 = 0;
        local_10c = 0;
        local_104 = 0;
        iVar4 = websUrlParse(pcVar3,&local_118,&local_104,&local_10c,&local_110,&local_108,
                             &local_100,0,&local_114);
        if (iVar4 < 0) {
          uVar8 = 400;
          pcVar3 = "Bad URL format";
          goto LAB_004157a4;
        }
        uVar6 = bstrdup(pcVar3);
        *(undefined4 *)(param_1 + 0xb8) = uVar6;
        iVar4 = (*(code *)PTR_strstr_00430a14)(pcVar3,"rssfwupgd.xgi");
        if (iVar4 != 0) {
          iVar4 = (*(code *)PTR_dxmlGetInt_00430a40)("/runtime/fwupgradeinfo/state");
          if (0 < iVar4) goto LAB_004157b4;
          *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x100000;
          if (6 < *(int *)PTR_daemon_log_level_00430990) {
            uVar6 = (*(code *)PTR_sys_uptime_seconds_00430a50)();
            (*(code *)PTR_dbgPrintf_00430a20)(&DAT_0041d520,uVar6);
            (*(code *)PTR_logPrintf_00430a1c)(7,"%s]","websParseFirst");
            (*(code *)PTR_logPrintf_00430a1c)(7,"FW Upgrade: url=%s\n",pcVar3);
          }
        }
        iVar4 = (*(code *)PTR_strstr_00430a14)(pcVar3,"cgi-bin");
        if ((iVar4 != 0) &&
           (uVar5 = *(uint *)(param_1 + 0x100), *(uint *)(param_1 + 0x100) = uVar5 | 0x4000,
           (uVar5 & 0x20) != 0)) {
          uVar6 = websGetCgiCommName();
          *(undefined4 *)(param_1 + 0x114) = uVar6;
        }
        uVar6 = bstrdup(local_108);
        *(undefined4 *)(param_1 + 0xc4) = uVar6;
        uVar6 = bstrdup(local_104);
        *(undefined4 *)(param_1 + 0xbc) = uVar6;
        uVar6 = bstrdup(local_10c);
        *(undefined4 *)(param_1 + 0xb4) = uVar6;
        uVar6 = bstrdup(local_100);
        *(undefined4 *)(param_1 + 0xe4) = uVar6;
        uVar8 = bstrdup(uVar8);
        *(undefined4 *)(param_1 + 0xe8) = uVar8;
        *(undefined4 *)(param_1 + 0xec) = 0;
        *(undefined4 *)(param_1 + 0x110) = 0;
        iVar4 = socketGetPort(*(undefined4 *)(param_1 + 0xf4));
        if (iVar4 < 0) {
          iVar4 = (*(code *)PTR_atoi_0043096c)(local_110);
        }
        puVar1 = PTR_strcmp_004309b4;
        *(int *)(param_1 + 0xf8) = iVar4;
        iVar4 = (*(code *)puVar1)(local_114,&DAT_0041ef80);
        if (iVar4 == 0) {
          *(uint *)(param_1 + 0x100) = *(uint *)(param_1 + 0x100) | 0x100;
        }
        bfree(local_118);
        websUrlType(pcVar3,param_1 + 0x70,0x40);
        ringqFlush(param_1);
        *(undefined4 *)(param_1 + 0xfc) = 2;
        goto LAB_00414bbc;
      }
    }
    uVar8 = 400;
    pcVar3 = "Bad HTTP request";
  }
  else {
LAB_00415798:
    uVar8 = 0x194;
    pcVar3 = "Bad state";
  }
LAB_004157a4:
  websError(param_1,uVar8,pcVar3);
  goto LAB_004157b4;
}

