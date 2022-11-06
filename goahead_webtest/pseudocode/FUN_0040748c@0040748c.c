
undefined4 FUN_0040748c(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined *puVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int *piVar11;
  int local_50 [8];
  undefined4 local_30;
  
  local_30 = param_2;
  pcVar3 = (char *)websGetRequestDir();
  uVar4 = 0xffffffff;
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    pcVar5 = (char *)bstrdup(local_30);
    uVar4 = (*(code *)PTR_strlen_0043095c)(pcVar5);
    websDecodeUrl(pcVar5,pcVar5,uVar4);
    local_50[0] = 0;
    for (puVar6 = (undefined *)(*(code *)PTR_strchr_00430950)(pcVar5,0x5c);
        puVar2 = PTR_strchr_00430950, puVar6 != (undefined *)0x0;
        puVar6 = (undefined *)(*(code *)puVar2)(puVar6,0x5c)) {
      *puVar6 = 0x2f;
    }
    iVar7 = (*(code *)PTR_strtok_004309f0)(pcVar5,"/");
    iVar9 = 0;
    iVar10 = 0;
    while (iVar7 != 0) {
      if (7 < iVar9) goto LAB_00407758;
      iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar7,&DAT_0041dac8);
      if (iVar8 == 0) {
        iVar9 = iVar9 - (uint)(iVar9 != 0);
      }
      else {
        iVar8 = (*(code *)PTR_strcmp_004309b4)(iVar7,".");
        if (iVar8 != 0) {
          local_50[iVar9] = iVar7;
          iVar7 = (*(code *)PTR_strlen_0043095c)(iVar7);
          iVar10 = iVar10 + 1 + iVar7;
          iVar9 = iVar9 + 1;
        }
      }
      iVar7 = (*(code *)PTR_strtok_004309f0)(0,"/");
    }
    if (((iVar9 == 0) && (iVar7 = (*(code *)PTR_strcmp_004309b4)(pcVar5,"/"), iVar7 != 0)) &&
       (*pcVar5 != '\0')) {
LAB_00407758:
      bfree(pcVar5);
      return 0xffffffff;
    }
    iVar7 = (*(code *)PTR_strlen_0043095c)(pcVar3);
    piVar11 = local_50;
    uVar4 = balloc(iVar10 + 2 + iVar7);
    iVar7 = 0;
    (*(code *)PTR_strcpy_00430ad8)(uVar4,pcVar3);
    bVar1 = 0 < iVar9;
    while (bVar1) {
      (*(code *)PTR_strcat_00430a3c)(uVar4,"/");
      iVar10 = *piVar11;
      iVar7 = iVar7 + 1;
      piVar11 = piVar11 + 1;
      (*(code *)PTR_strcat_00430a3c)(uVar4,iVar10);
      bVar1 = iVar7 < iVar9;
    }
    websSetRequestLpath(param_1,uVar4);
    bfree(pcVar5);
    bfree(uVar4);
    uVar4 = 0;
  }
  return uVar4;
}

