
undefined4
websUrlParse(undefined4 param_1,char **param_2,char **param_3,char **param_4,char **param_5,
            char **param_6,char **param_7,undefined4 *param_8,int *param_9)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined4 uVar4;
  char *pcVar5;
  undefined *puVar6;
  int iVar7;
  int iVar8;
  char *pcVar9;
  char *pcVar10;
  int iVar11;
  char *pcVar12;
  char *pcVar13;
  char *local_40;
  char *local_3c;
  
  iVar2 = (*(code *)PTR_strlen_0043095c)();
  iVar11 = (iVar2 + 5) * 2;
  pcVar3 = (char *)balloc(iVar11 + 3);
  if (pcVar3 == (char *)0x0) {
    return 0xffffffff;
  }
  websDecodeUrl(pcVar3,param_1,iVar2);
  pcVar12 = pcVar3 + iVar11 + -8;
  uVar4 = websGetPort();
  stritoa(uVar4,pcVar12,10);
  iVar11 = (*(code *)PTR_strncmp_00430a08)(pcVar3,&DAT_0041ee4c,7);
  if (iVar11 == 0) {
    pcVar3[4] = '\0';
    local_40 = pcVar3 + 7;
    pcVar9 = local_40;
    pcVar13 = pcVar12;
    for (pcVar5 = local_40; (cVar1 = *pcVar5, cVar1 != '\0' && (cVar1 != '/')); pcVar5 = pcVar5 + 1)
    {
      if (cVar1 == ':') {
        *pcVar5 = '\0';
        pcVar5 = pcVar5 + 1;
        pcVar9 = pcVar5;
        pcVar13 = pcVar5;
      }
    }
    pcVar5 = (char *)(*(code *)PTR_strchr_00430950)(pcVar9,0x2f);
    puVar6 = PTR_strncpy_00430a04;
    local_3c = pcVar3;
    if (pcVar5 == (char *)0x0) {
      pcVar12 = pcVar13;
      pcVar5 = "/";
    }
    else {
      cVar1 = *pcVar5;
      *pcVar5 = '\0';
      (*(code *)puVar6)(pcVar3 + iVar2 + 1,local_40,iVar2);
      (*(code *)PTR_strncpy_00430a04)(pcVar12,pcVar13,10);
      *pcVar5 = cVar1;
      pcVar9 = pcVar5;
      local_40 = pcVar3 + iVar2 + 1;
    }
  }
  else {
    local_3c = "http";
    local_40 = "localhost";
    pcVar9 = pcVar3;
    pcVar5 = pcVar3;
  }
  puVar6 = (undefined *)(*(code *)PTR_strchr_00430950)(pcVar9,0x3f);
  pcVar13 = puVar6 + 1;
  if (puVar6 == (undefined *)0x0) {
    pcVar13 = &DAT_0041ed68;
    pcVar10 = pcVar9;
  }
  else {
    *puVar6 = 0;
    pcVar10 = pcVar13;
    pcVar5 = pcVar9;
  }
  puVar6 = (undefined *)(*(code *)PTR_strchr_00430950)(pcVar10,0x23);
  if ((puVar6 != (undefined *)0x0) && (*puVar6 = 0, *pcVar13 == '\0')) {
    pcVar5 = pcVar10;
  }
  if ((param_9 != (int *)0x0) && (iVar2 = (*(code *)PTR_strrchr_00430a58)(pcVar5,0x2e), iVar2 != 0))
  {
    iVar11 = (*(code *)PTR_strcspn_0043099c)(iVar2,&DAT_0041fb20);
    iVar7 = (*(code *)PTR_strspn_00430964)((undefined *)(iVar2 + iVar11),&DAT_0041fb20);
    iVar8 = (*(code *)PTR_strlen_0043095c)(iVar2);
    if (iVar11 + iVar7 == iVar8) {
      *(undefined *)(iVar2 + iVar11) = 0;
      goto LAB_0041790c;
    }
  }
  iVar2 = 0x4304b0;
LAB_0041790c:
  if (param_3 != (char **)0x0) {
    *param_3 = local_40;
  }
  if (param_4 != (char **)0x0) {
    *param_4 = pcVar5;
  }
  if (param_5 != (char **)0x0) {
    *param_5 = pcVar12;
  }
  if (param_7 != (char **)0x0) {
    *param_7 = local_3c;
  }
  if (param_6 != (char **)0x0) {
    *param_6 = pcVar13;
  }
  if (param_8 != (undefined4 *)0x0) {
    *param_8 = &DAT_0041ed68;
  }
  if (param_9 != (int *)0x0) {
    *param_9 = iVar2;
  }
  *param_2 = pcVar3;
  return 0;
}

