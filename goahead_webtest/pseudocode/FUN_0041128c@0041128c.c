
undefined4 FUN_0041128c(int param_1,int *param_2)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 uVar10;
  char local_830 [1024];
  undefined auStack1072 [1024];
  uint local_30;
  
  if (*(int *)(param_1 + 0xe0) == 0) {
    uVar8 = 0;
    if (*(int *)(param_1 + 0xec) != 0) {
      pcVar7 = *(char **)(param_1 + 0xc4);
      iVar9 = *(int *)(param_1 + 0x110);
      if (pcVar7 == (char *)0x0) {
        iVar9 = balloc(iVar9 + 1);
        *(int *)(param_1 + 0xc4) = iVar9;
        if (iVar9 != 0) {
          (*(code *)PTR_memcpy_00430a90)
                    (iVar9,*(undefined4 *)(param_1 + 0xec),*(undefined4 *)(param_1 + 0x110));
          *(undefined *)(*(int *)(param_1 + 0xc4) + *(int *)(param_1 + 0x110)) = 0;
        }
      }
      else {
        if (*pcVar7 == '\0') {
          iVar3 = (*(code *)PTR_strlen_0043095c)(pcVar7);
          iVar9 = brealloc(pcVar7,iVar3 + iVar9 + 1);
          *(int *)(param_1 + 0xc4) = iVar9;
          iVar6 = iVar9 + iVar3;
          if (iVar9 == 0) {
            return 0;
          }
        }
        else {
          iVar3 = (*(code *)PTR_strlen_0043095c)();
          iVar9 = brealloc(pcVar7,iVar3 + iVar9 + 2);
          *(int *)(param_1 + 0xc4) = iVar9;
          if (iVar9 == 0) {
            return 0;
          }
          *(undefined *)(iVar9 + iVar3) = 0x26;
          iVar3 = iVar3 + 1;
          iVar6 = *(int *)(param_1 + 0xc4) + iVar3;
        }
        (*(code *)PTR_memcpy_00430a90)
                  (iVar6,*(undefined4 *)(param_1 + 0xec),*(undefined4 *)(param_1 + 0x110));
        *(undefined *)(*(int *)(param_1 + 0xc4) + iVar3 + *(int *)(param_1 + 0x110)) = 0;
      }
    }
  }
  else {
    bVar1 = false;
    uVar8 = 0;
    iVar9 = *(int *)(param_1 + 0xec);
LAB_004118a8:
    iVar3 = iVar9;
    if (iVar3 != 0) {
      uVar10 = *(undefined4 *)(param_1 + 0xe0);
      iVar9 = (*(code *)PTR_strstr_00430a14)(iVar3,uVar10);
      if (iVar9 == 0) {
        return uVar8;
      }
      iVar9 = (*(code *)PTR_strchr_00430950)(iVar9,10);
      iVar6 = iVar9 + 1;
      if (iVar9 == 0) {
        return uVar8;
      }
      iVar4 = (*(code *)PTR_strstr_00430a14)(iVar6,"Content-Disposition");
      iVar9 = iVar6;
      if ((iVar4 != 0) &&
         (iVar4 = (*(code *)PTR_strchr_00430950)(iVar6,10), iVar9 = iVar3, iVar4 != 0)) {
        iVar4 = iVar4 - iVar6;
        if (0x3ff < iVar4) {
          iVar4 = 0x3ff;
        }
        (*(code *)PTR_strncpy_00430a04)(auStack1072,iVar6,iVar4);
        auStack1072[iVar4] = 0;
        do {
          iVar3 = (*(code *)PTR_strchr_00430950)(iVar6,10);
          if (iVar3 == 0) {
            return uVar8;
          }
          iVar6 = iVar3 + 1;
          if (*(char *)(iVar3 + 1) == '\n') {
            iVar3 = iVar3 + 2;
            goto LAB_004114d8;
          }
        } while ((*(char *)(iVar3 + 1) != '\r') || (*(char *)(iVar3 + 2) != '\n'));
        iVar3 = iVar3 + 3;
LAB_004114d8:
        local_830[0] = '\0';
        iVar9 = xmemstr(iVar3,uVar10,(*(int *)(param_1 + 0xec) - iVar3) + *(int *)(param_1 + 0x110))
        ;
        if (iVar9 == 0) {
          return uVar8;
        }
        iVar6 = (*(code *)PTR_strstr_00430a14)(auStack1072,"filename=");
        if (iVar6 == 0) {
          uVar5 = (*(code *)PTR_strstr_00430a14)(auStack1072,"form-data; name=");
          if (uVar5 == 0) goto LAB_004118a8;
          local_30 = uVar5;
          iVar6 = (*(code *)PTR_strchr_00430950)(uVar5 + 0x11,0x22);
          iVar4 = iVar6 - (uVar5 + 0x11);
          if ((iVar6 != 0) && (0 < iVar4)) {
            if (0x3ff < iVar4) {
              iVar4 = 0x3ff;
            }
            (*(code *)PTR_strncpy_00430a04)(local_830,local_30 + 0x11,iVar4);
            local_830[iVar4] = '\0';
            (*(code *)PTR_strcat_00430a3c)(local_830,"=");
            uVar5 = (iVar9 - iVar3) - 2;
            if (0 < (int)uVar5) {
              local_30 = uVar5;
              iVar6 = (*(code *)PTR_strlen_0043095c)(local_830);
              uVar5 = local_30;
              if (0x400U - iVar6 <= local_30) {
                uVar5 = 0x3ff - iVar6;
              }
              (*(code *)PTR_strncat_004309dc)(local_830,iVar3,uVar5);
            }
          }
        }
        else if (!bVar1) {
          iVar6 = iVar6 + 10;
          iVar4 = (*(code *)PTR_strchr_00430950)(iVar6,0x22);
          if (iVar4 != 0) {
            iVar4 = iVar4 - iVar6;
            if (0 < iVar4) {
              (*(code *)PTR_strcpy_00430ad8)(local_830,"filename=");
              if (0x3ff < iVar4) {
                iVar4 = 0x3ff;
              }
              (*(code *)PTR_strncat_004309dc)(local_830,iVar6,iVar4);
            }
          }
          *param_2 = (iVar9 - iVar3) + -2;
          uVar8 = balloc();
          bVar1 = true;
          (*(code *)PTR_memcpy_00430a90)(uVar8,iVar3,*param_2);
        }
        if (local_830[0] != '\0') {
          pcVar7 = *(char **)(param_1 + 0xc4);
          if (pcVar7 != (char *)0x0) {
            if (*pcVar7 == '\0') {
              iVar3 = (*(code *)PTR_strlen_0043095c)(pcVar7);
              iVar6 = (*(code *)PTR_strlen_0043095c)(local_830);
              iVar6 = brealloc(pcVar7,iVar3 + iVar6 + 1);
              *(int *)(param_1 + 0xc4) = iVar6;
              if (iVar6 == 0) goto LAB_004118a8;
              uVar10 = (*(code *)PTR_strlen_0043095c)(local_830);
              iVar6 = iVar6 + iVar3;
            }
            else {
              iVar3 = (*(code *)PTR_strlen_0043095c)();
              iVar6 = (*(code *)PTR_strlen_0043095c)(local_830);
              iVar6 = brealloc(pcVar7,iVar3 + iVar6 + 2);
              *(int *)(param_1 + 0xc4) = iVar6;
              puVar2 = PTR_strlen_0043095c;
              if (iVar6 == 0) goto LAB_004118a8;
              *(undefined *)(iVar6 + iVar3) = 0x26;
              uVar10 = (*(code *)puVar2)(local_830);
              iVar3 = iVar3 + 1;
              iVar6 = *(int *)(param_1 + 0xc4) + iVar3;
            }
            (*(code *)PTR_memcpy_00430a90)(iVar6,local_830,uVar10);
            iVar6 = (*(code *)PTR_strlen_0043095c)(local_830);
            *(undefined *)(*(int *)(param_1 + 0xc4) + iVar3 + iVar6) = 0;
            goto LAB_004118a8;
          }
          iVar3 = (*(code *)PTR_strlen_0043095c)(local_830);
          iVar3 = balloc(iVar3 + 1);
          *(int *)(param_1 + 0xc4) = iVar3;
          if (iVar3 != 0) {
            uVar10 = (*(code *)PTR_strlen_0043095c)(local_830);
            (*(code *)PTR_memcpy_00430a90)(iVar3,local_830,uVar10);
            iVar3 = (*(code *)PTR_strlen_0043095c)(local_830);
            *(undefined *)(*(int *)(param_1 + 0xc4) + iVar3) = 0;
          }
        }
      }
      goto LAB_004118a8;
    }
  }
  return uVar8;
}

