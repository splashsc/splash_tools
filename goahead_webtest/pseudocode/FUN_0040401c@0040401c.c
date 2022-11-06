
undefined4 FUN_0040401c(undefined4 param_1,char *param_2,int param_3,char **param_4)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  undefined *puVar4;
  uint uVar5;
  uint uVar6;
  char *pcVar7;
  uint uVar8;
  char **ppcVar9;
  code *pcVar10;
  ushort local_988;
  ushort local_986;
  undefined auStack2436 [4];
  undefined4 local_980;
  undefined4 local_97c;
  undefined4 local_978;
  undefined4 local_974;
  undefined4 local_970;
  undefined4 local_96c;
  undefined4 local_968;
  undefined4 local_964;
  undefined4 local_960;
  undefined4 local_95c;
  undefined4 local_958;
  undefined4 local_954;
  undefined4 local_950;
  undefined4 local_94c;
  undefined4 local_948;
  undefined4 local_944;
  undefined4 local_940;
  undefined4 local_93c;
  undefined4 local_938;
  undefined4 local_934;
  undefined local_930 [256];
  undefined auStack2096 [256];
  undefined auStack1840 [255];
  char acStack1585 [257];
  undefined auStack1328 [256];
  undefined auStack1072 [512];
  undefined auStack560 [512];
  char *local_30;
  
  (*(code *)PTR_memset_004309cc)(auStack1328,0,0x100);
  pcVar3 = acStack1585 + 1;
  (*(code *)PTR_memset_004309cc)(pcVar3,0,0x100);
  (*(code *)PTR_memset_004309cc)(auStack1840,0,0x100);
  (*(code *)PTR_memset_004309cc)(auStack560,0,0x200);
  local_948 = 0;
  local_944 = 0;
  local_940 = 0;
  local_93c = 0;
  local_938 = 0;
  local_934 = 0;
  local_968 = 0;
  local_964 = 0;
  local_970 = 0;
  local_96c = 0;
  iVar1 = ejArgs(param_3,param_4,"%s",auStack2436);
  if (iVar1 < 1) {
    websError(param_2,400,"Insufficient2 args\n");
    return 0;
  }
  pcVar7 = *param_4;
  iVar1 = (*(code *)PTR_strchr_00430950)(pcVar7,0x23);
  if (iVar1 == 0) {
    iVar1 = (*(code *)PTR_strchr_00430950)(pcVar7,0x3a);
    if (iVar1 != 0) {
      if (*(char *)(iVar1 + 1) == '\0') {
        param_2 = "This is wrong format! ConfigGetArray(%s)!!\n";
        pcVar10 = (code *)PTR_printf_00430ac8;
      }
      else {
        (*(code *)PTR_sscanf_004309e4)(pcVar7,"%[^:]:%s",auStack1328,pcVar3);
        iVar1 = (*(code *)PTR_strchr_00430950)(pcVar3,0x2f);
        if (iVar1 == 0) {
          (*(code *)PTR_strcpy_00430ad8)(&local_948,pcVar3);
          acStack1585[1] = 0x2f;
        }
        else {
          uVar8 = iVar1 - (int)pcVar3 >> 0x1f;
          (*(code *)PTR_strncpy_00430a04)(&local_948,pcVar3,(uVar8 ^ iVar1 - (int)pcVar3) - uVar8);
          (*(code *)PTR_strcpy_00430ad8)(pcVar3,iVar1);
        }
        iVar1 = (*(code *)PTR_strchr_00430950)(&local_948,0x2d);
        if (iVar1 == 0) {
          uVar8 = (*(code *)PTR_atoi_0043096c)(&local_948);
          uVar8 = uVar8 & 0xffff;
          local_986 = (ushort)uVar8;
        }
        else {
          (*(code *)PTR_sscanf_004309e4)(&local_948,"%[^-]-%s",&local_968,&local_970);
          uVar8 = (*(code *)PTR_atoi_0043096c)(&local_968);
          local_986 = (*(code *)PTR_atoi_0043096c)(&local_970);
        }
        if ((int)uVar8 <= (int)(uint)local_986) {
          for (; (int)uVar8 <= (int)(uint)local_986; uVar8 = uVar8 + 1) {
            websWrite(param_2,&DAT_0041d260);
            ppcVar9 = param_4;
            for (iVar1 = 2; iVar1 < param_3; iVar1 = iVar1 + 1) {
              (*(code *)PTR_dxmlGetStr_004309b8)
                        (auStack560,"%s:%d%s%s",auStack1328,uVar8,acStack1585 + 1,ppcVar9[2]);
              FUN_00403860(auStack560);
              puVar4 = &DAT_0041d2d4;
              if (iVar1 == param_3 + -1) {
                puVar4 = &DAT_0041d2dc;
              }
              websWrite(param_2,puVar4,auStack560);
              ppcVar9 = ppcVar9 + 1;
            }
            puVar4 = &DAT_0041d2e8;
            if (uVar8 != local_986) {
              puVar4 = &DAT_0041d2e4;
            }
            websWrite(param_2,puVar4);
          }
          return 0;
        }
        websWrite(param_2,&DAT_0041d260);
        for (iVar1 = 2; iVar1 < param_3; iVar1 = iVar1 + 1) {
          puVar4 = &DAT_0041d26c;
          if (iVar1 == param_3 + -1) {
            puVar4 = &DAT_0041d270;
          }
          websWrite(param_2,puVar4);
        }
        pcVar7 = "]";
        pcVar10 = (code *)PTR_websWrite_00430600;
      }
      goto LAB_00404b54;
    }
    websWrite(param_2,&DAT_0041d260);
    ppcVar9 = param_4;
    for (iVar1 = 2; iVar1 < param_3; iVar1 = iVar1 + 1) {
      local_30 = *param_4;
      iVar2 = (*(code *)PTR_strlen_0043095c)(local_30);
      if (local_30[iVar2 + -1] == '/') {
        pcVar7 = ppcVar9[2];
        pcVar3 = "%s%s";
      }
      else {
        pcVar7 = ppcVar9[2];
        pcVar3 = "%s/%s";
      }
      (*(code *)PTR_snprintf_00430aac)(auStack1840,0x100,pcVar3,local_30,pcVar7);
      (*(code *)PTR_dxmlGetStr_004309b8)(auStack560,auStack1840);
      FUN_00403860(auStack560);
      puVar4 = &DAT_0041d2d4;
      if (iVar1 == param_3 + -1) {
        puVar4 = &DAT_0041d2dc;
      }
      websWrite(param_2,puVar4,auStack560);
      ppcVar9 = ppcVar9 + 1;
    }
  }
  else {
    if (*(char *)(iVar1 + 1) == '\0') {
      (*(code *)PTR_sscanf_004309e4)(pcVar7,"%[^#]#",auStack1328);
      acStack1585[1] = 0;
    }
    else {
      (*(code *)PTR_sscanf_004309e4)(pcVar7,"%[^#]#%s",auStack1328,pcVar3);
    }
    iVar1 = (*(code *)PTR_strlen_0043095c)(acStack1585 + 1);
    if (acStack1585[iVar1] != '/') {
      (*(code *)PTR_strcat_00430a3c)(acStack1585 + 1,"/");
    }
    (*(code *)PTR_dxmlGetRow_00430a74)(&local_986,auStack1328);
    if (999 < local_986) {
      local_986 = 1000;
    }
    uVar8 = 1;
    if (local_986 != 0) {
      do {
        if ((int)(uint)local_986 < (int)uVar8) {
          return 0;
        }
        websWrite(param_2,&DAT_0041d260);
        ppcVar9 = param_4;
        for (iVar1 = 1; iVar1 < param_3; iVar1 = iVar1 + 1) {
          (*(code *)PTR_snprintf_00430aac)
                    (auStack1840,0x200,"%s:%d%s%s",auStack1328,uVar8,acStack1585 + 1,ppcVar9[1]);
          iVar2 = (*(code *)PTR_strchr_00430950)(auStack1840,0x23);
          if (iVar2 == 0) {
            (*(code *)PTR_dxmlGetStr_004309b8)(auStack560,auStack1840);
            FUN_00403860(auStack560);
            puVar4 = &DAT_0041d2d4;
            if (iVar1 == param_3 + -1) {
              puVar4 = &DAT_0041d2dc;
            }
            websWrite(param_2,puVar4,auStack560);
          }
          else {
            websWrite(param_2,&DAT_0041d260);
            (*(code *)PTR_memset_004309cc)(auStack2096,0,0x100);
            (*(code *)PTR_memset_004309cc)(local_930,0,0x100);
            (*(code *)PTR_memset_004309cc)(auStack1072,0,0x200);
            local_960 = 0;
            local_95c = 0;
            local_958 = 0;
            local_954 = 0;
            local_950 = 0;
            local_94c = 0;
            local_978 = 0;
            local_974 = 0;
            local_980 = 0;
            local_97c = 0;
            iVar2 = (*(code *)PTR_strchr_00430950)(auStack1840,0x23);
            if (iVar2 == 0) {
              iVar2 = (*(code *)PTR_strchr_00430950)(auStack1840,0x3a);
              if ((iVar2 != 0) && (*(char *)(iVar2 + 1) != '\0')) {
                (*(code *)PTR_sscanf_004309e4)(auStack1840,"%[^:]:%s",auStack2096,local_930);
                pcVar3 = (char *)(*(code *)PTR_strchr_00430950)(local_930,0x2f);
                if (pcVar3 == (char *)0x0) {
                  (*(code *)PTR_strcpy_00430ad8)(&local_960,local_930);
LAB_00404518:
                  local_930[0] = 0;
                }
                else {
                  uVar5 = (int)pcVar3 - (int)local_930;
                  uVar6 = (int)uVar5 >> 0x1f;
                  local_30 = pcVar3;
                  (*(code *)PTR_strncpy_00430a04)(&local_960,local_930,(uVar6 ^ uVar5) - uVar6);
                  if (local_30[1] == '\0') goto LAB_00404518;
                  (*(code *)PTR_strcpy_00430ad8)(local_930,local_30);
                }
                iVar2 = (*(code *)PTR_strchr_00430950)(&local_960,0x2d);
                if (iVar2 == 0) {
                  uVar6 = (*(code *)PTR_atoi_0043096c)(&local_960);
                  uVar6 = uVar6 & 0xffff;
                  local_988 = (ushort)uVar6;
                }
                else {
                  (*(code *)PTR_sscanf_004309e4)(&local_960,"%[^-]-%s",&local_978,&local_980);
                  uVar6 = (*(code *)PTR_atoi_0043096c)(&local_978);
                  local_988 = (*(code *)PTR_atoi_0043096c)(&local_980);
                }
                goto LAB_004045d0;
              }
              (*(code *)PTR_printf_00430ac8)
                        ("This is wrong format! ConfigGetArrayElement(%s)!!\n",auStack1840);
LAB_00404660:
              websWrite(param_2,&DAT_0041d270);
            }
            else {
              if (*(char *)(iVar2 + 1) == '\0') {
                (*(code *)PTR_sscanf_004309e4)(auStack1840,"%[^#]#",auStack2096);
                local_930[0] = 0;
              }
              else {
                (*(code *)PTR_sscanf_004309e4)(auStack1840,"%[^#]#%s",auStack2096,local_930);
              }
              (*(code *)PTR_dxmlGetRow_00430a74)(&local_988,auStack2096);
              uVar6 = 1;
LAB_004045d0:
              if ((int)(uint)local_988 < (int)uVar6) goto LAB_00404660;
              for (; (int)uVar6 <= (int)(uint)local_988; uVar6 = uVar6 + 1) {
                (*(code *)PTR_dxmlGetStr_004309b8)
                          (auStack1072,"%s:%d%s",auStack2096,uVar6,local_930);
                FUN_00403860(auStack1072);
                puVar4 = &DAT_0041d2d4;
                if (uVar6 == local_988) {
                  puVar4 = &DAT_0041d2dc;
                }
                websWrite(param_2,puVar4,auStack1072);
              }
            }
            websWrite(param_2,"]");
            if (iVar1 != param_3 + -1) {
              websWrite(param_2,&DAT_0041d2d8);
            }
          }
          ppcVar9 = ppcVar9 + 1;
        }
        if (uVar8 == local_986) {
          puVar4 = &DAT_0041d2e8;
        }
        else {
          puVar4 = &DAT_0041d2e4;
        }
        uVar8 = uVar8 + 1;
        websWrite(param_2,puVar4);
      } while( true );
    }
    websWrite(param_2,&DAT_0041d260);
    for (iVar1 = 1; iVar1 < param_3; iVar1 = iVar1 + 1) {
      if (iVar1 == param_3 + -1) {
        iVar2 = (*(code *)PTR_strchr_00430950)(param_4[1],0x23);
        puVar4 = &DAT_0041d270;
      }
      else {
        iVar2 = (*(code *)PTR_strchr_00430950)();
        puVar4 = &DAT_0041d26c;
      }
      if (iVar2 != 0) {
        puVar4 = &DAT_0041d264;
      }
      websWrite(param_2,puVar4);
      param_4 = param_4 + 1;
    }
  }
  pcVar7 = "]";
  pcVar10 = (code *)PTR_websWrite_00430600;
LAB_00404b54:
  (*pcVar10)(param_2,pcVar7);
  return 0;
}

