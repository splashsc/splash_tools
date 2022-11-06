
undefined4 dbLoad(undefined4 param_1,undefined4 param_2)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  char *pcVar6;
  undefined *puVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  undefined4 local_d0 [2];
  undefined auStack200 [52];
  int local_94;
  char *local_30;
  char *local_2c;
  
  local_2c = (char *)param_2;
  uVar2 = FUN_0041b110();
  fmtAlloc(local_d0,0xfe,"%s/%s",uVar2,local_2c);
  trace(4,"DB: About to read data file <%s>\n",local_d0[0]);
  iVar3 = (*(code *)PTR_stat_00430984)(local_d0[0],auStack200);
  if (iVar3 < 0) {
    trace(3,"DB: Failed to stat persistent data file.\n");
    bfree(local_d0[0]);
  }
  else {
    iVar3 = (*(code *)PTR_open_00430958)(local_d0[0],0,0x1b6);
    bfree(local_d0[0]);
    if (iVar3 < 0) {
      trace(3,"DB: No persistent data file present.\n");
    }
    else {
      if (local_94 < 1) {
        trace(3,"DB: Persistent data file is empty.\n");
      }
      else {
        iVar4 = balloc(local_94 + 1);
        iVar5 = (*(code *)PTR_read_00430a0c)(iVar3,iVar4,local_94);
        if (iVar5 == local_94) {
          (*(code *)PTR_close_0043093c)(iVar3);
          puVar7 = PTR_strtok_004309f0;
          *(undefined *)(iVar4 + local_94) = 0;
          pcVar6 = (char *)(*(code *)puVar7)(iVar4,"\n");
          iVar11 = 0;
          iVar5 = -1;
          iVar3 = 0;
          pcVar9 = (char *)0xffffffff;
          do {
            local_2c = pcVar6;
            puVar7 = (undefined *)(*(code *)PTR_strrchr_00430a58)(pcVar6,10);
            if ((puVar7 != (undefined *)0x0) ||
               (puVar7 = (undefined *)(*(code *)PTR_strrchr_00430a58)(local_2c,0xd),
               puVar7 != (undefined *)0x0)) {
              *puVar7 = 0;
            }
            pcVar6 = (char *)(*(code *)PTR_strchr_00430950)(local_2c,0x3d);
            puVar7 = PTR___ctype_b_00430aa4;
            pcVar10 = pcVar9;
            if (pcVar6 == (char *)0x0) {
              trace(5,"DB: Failed to crack line %s\n");
            }
            else {
              *pcVar6 = '\0';
              pcVar1 = local_2c;
              do {
                local_2c = pcVar1;
                pcVar1 = local_2c + 1;
                local_30 = pcVar6;
              } while ((*(ushort *)(*(int *)puVar7 + *local_2c * 2) & 0x20) != 0);
              do {
                local_30 = local_30 + 1;
              } while ((*(ushort *)(*(int *)puVar7 + *local_30 * 2) & 0x20) != 0);
              iVar8 = (*(code *)PTR_strcmp_004309b4)(local_2c,"TABLE");
              if (iVar8 == 0) {
                if (iVar3 != 0) {
                  bfree(iVar3);
                }
                iVar11 = 0;
                iVar3 = bstrdup(local_30);
                iVar5 = FUN_0041a750(param_1,iVar3);
                if (-1 < iVar5) {
                  iVar11 = *(int *)(DAT_00430c60 + iVar5 * 4);
                }
              }
              else {
                iVar8 = (*(code *)PTR_strcmp_004309b4)(local_2c,&DAT_0041ff64);
                if (iVar8 == 0) {
                  if (-1 < iVar5) {
                    local_2c = (char *)FUN_0041aab4(param_1,iVar3);
                    iVar8 = FUN_0041ad9c(param_1,iVar3,local_2c + 1);
                    pcVar10 = local_2c;
                    if (iVar8 != 0) {
                      pcVar10 = pcVar9;
                    }
                  }
                }
                else if (((pcVar9 != (char *)0xffffffff) &&
                         (iVar8 = FUN_0041a150(iVar5,local_2c), -1 < iVar8)) && (iVar11 != 0)) {
                  if (*(int *)(*(int *)(iVar11 + 0xc) + iVar8 * 4) == 1) {
                    dbWriteStr(param_1,iVar3,local_2c,pcVar9,local_30);
                  }
                  else {
                    uVar2 = gstrtoi(local_30);
                    dbWriteInt(param_1,iVar3,local_2c,pcVar9,uVar2);
                  }
                }
              }
            }
            pcVar6 = (char *)(*(code *)PTR_strtok_004309f0)(0,"\n");
            pcVar9 = pcVar10;
          } while (pcVar6 != (char *)0x0);
          if (iVar3 != 0) {
            bfree(iVar3);
          }
          bfree(iVar4);
          return 0;
        }
        trace(3,"DB: Persistent data read failed.\n");
        bfree(iVar4);
      }
      (*(code *)PTR_close_0043093c)(iVar3);
    }
  }
  return 0xffffffff;
}

