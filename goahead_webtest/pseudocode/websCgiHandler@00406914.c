
undefined4 websCgiHandler(int param_1)

{
  int iVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  char *pcVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  code *pcVar12;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  int local_2d0 [2];
  undefined auStack712 [20];
  uint local_2b4;
  undefined auStack560 [256];
  undefined uStack304;
  undefined auStack303 [255];
  int local_30;
  undefined4 local_2c;
  
  puVar2 = PTR_strncpy_00430a04;
  *(int *)(PTR_websStats_00430694 + 0x28) = *(int *)(PTR_websStats_00430694 + 0x28) + 1;
  (*(code *)puVar2)(&uStack304,in_stack_00000014,0xfe);
  iVar1 = (*(code *)PTR_strchr_00430950)(auStack303,0x2f);
  iVar10 = iVar1 + 1;
  if (iVar1 == 0) {
    websError(param_1,200,"Missing CGI name");
  }
  else {
    puVar2 = (undefined *)(*(code *)PTR_strchr_00430950)(iVar10,0x2f);
    if (puVar2 != (undefined *)0x0) {
      *puVar2 = 0;
    }
    uVar3 = websGetDefaultDir();
    fmtAlloc(local_2d0,0xfe,"%s/%s/%s",uVar3,"cgi-bin",iVar10);
    iVar1 = (*(code *)PTR_stat_00430984)(local_2d0[0],auStack712);
    if ((iVar1 == 0) && ((local_2b4 & 0x8000) != 0)) {
      iVar1 = (*(code *)PTR_access_0043097c)(local_2d0[0],1);
      if (iVar1 == 0) {
        (*(code *)PTR_getcwd_004309a8)(auStack560,0xfe);
        puVar2 = (undefined *)(*(code *)PTR_strrchr_00430a58)(local_2d0[0],0x2f);
        if (puVar2 != (undefined *)0x0) {
          *puVar2 = 0;
          (*(code *)PTR_chdir_00430a2c)(local_2d0[0]);
          *puVar2 = 0x2f;
        }
        iVar11 = 1;
        piVar4 = (int *)balloc(0x28);
        puVar2 = PTR_strchr_00430950;
        *piVar4 = local_2d0[0];
        iVar1 = (*(code *)puVar2)(in_stack_00000018,0x3d);
        if (iVar1 == 0) {
          uVar3 = (*(code *)PTR_strlen_0043095c)(in_stack_00000018);
          websDecodeUrl(in_stack_00000018,in_stack_00000018,uVar3);
          iVar5 = (*(code *)PTR_strtok_004309f0)(in_stack_00000018,&DAT_0041d840);
          iVar1 = 10;
          while (iVar5 != 0) {
            piVar6 = piVar4 + iVar11;
            iVar11 = iVar11 + 1;
            *piVar6 = iVar5;
            iVar9 = iVar1;
            if (iVar1 <= iVar11) {
              iVar9 = iVar1 << 1;
              piVar4 = (int *)brealloc(piVar4,iVar1 << 3);
            }
            iVar5 = (*(code *)PTR_strtok_004309f0)(0,&DAT_0041d840);
            iVar1 = iVar9;
          }
        }
        piVar4[iVar11] = 0;
        piVar6 = (int *)balloc(0x100);
        fmtAlloc(piVar6,0xfe,"%s=%s","PATH_TRANSLATED",local_2d0[0]);
        fmtAlloc(piVar6 + 1,0xfe,"%s=%s/%s","SCRIPT_NAME","cgi-bin",iVar10);
        fmtAlloc(piVar6 + 2,0xfe,"%s=%s","REMOTE_USER",*(undefined4 *)(param_1 + 0xd4));
        fmtAlloc(piVar6 + 3,0xfe,"%s=%s","AUTH_TYPE",*(undefined4 *)(param_1 + 0xcc));
        iVar10 = symFirst(*(undefined4 *)(param_1 + 0x20));
        iVar11 = 4;
        iVar1 = 0x40;
        while (iVar10 != 0) {
          iVar5 = iVar1;
          if ((*(char *)(iVar10 + 0x1e) != '\0') && (*(int *)(iVar10 + 0x1a) == 10)) {
            local_2c = *(undefined4 *)(iVar10 + 4);
            local_30 = iVar10;
            iVar10 = (*(code *)PTR_strcmp_004309b4)(local_2c,"REMOTE_HOST");
            if (iVar10 != 0) {
              iVar10 = (*(code *)PTR_strcmp_004309b4)(local_2c,"HTTP_AUTHORIZATION");
              if (iVar10 != 0) {
                piVar7 = piVar6 + iVar11;
                iVar11 = iVar11 + 1;
                fmtAlloc(piVar7,0xfe,"%s=%s",local_2c,*(undefined4 *)(local_30 + 0x12));
                if (iVar1 <= iVar11) {
                  iVar5 = iVar1 << 1;
                  piVar6 = (int *)brealloc(piVar6,iVar1 << 3);
                }
              }
            }
          }
          iVar10 = symNext(*(undefined4 *)(param_1 + 0x20));
          iVar1 = iVar5;
        }
        piVar6[iVar11] = 0;
        if (*(int *)(param_1 + 0x114) == 0) {
          uVar3 = websGetCgiCommName();
          *(undefined4 *)(param_1 + 0x114) = uVar3;
        }
        iVar11 = *(int *)(param_1 + 0x114);
        iVar1 = websGetCgiCommName();
        iVar10 = FUN_004066d0(local_2d0[0],piVar4,piVar6,iVar11,iVar1);
        if (iVar10 == -1) {
          websError(param_1,200,"failed to spawn CGI task");
          for (piVar7 = piVar6; *piVar7 != 0; piVar7 = piVar7 + 1) {
            bfreeSafe();
          }
          bfreeSafe(local_2d0[0]);
          bfreeSafe(piVar4);
          bfreeSafe(piVar6);
          param_1 = iVar1;
          pcVar12 = (code *)PTR_bfreeSafe_00430680;
        }
        else {
          iVar5 = hAllocEntry(&DAT_00430b90,&DAT_00430b94,0x20);
          pcVar12 = (code *)PTR_websTimeoutCancel_004306b4;
          piVar7 = *(int **)(DAT_00430b90 + iVar5 * 4);
          piVar7[6] = iVar10;
          piVar7[1] = iVar11;
          piVar7[2] = iVar1;
          piVar7[3] = local_2d0[0];
          piVar7[4] = (int)piVar4;
          piVar7[5] = (int)piVar6;
          *piVar7 = param_1;
          piVar7[7] = 0;
        }
        (*pcVar12)(param_1);
        (*(code *)PTR_chdir_00430a2c)(auStack560);
        return 1;
      }
      uVar3 = 200;
      pcVar8 = "CGI process file is not executable";
    }
    else {
      uVar3 = 0x194;
      pcVar8 = "CGI process file does not exist";
    }
    websError(param_1,uVar3,pcVar8);
    bfree(local_2d0[0]);
  }
  return 1;
}

