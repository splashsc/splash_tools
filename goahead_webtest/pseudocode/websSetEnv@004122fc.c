
void websSetEnv(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  int iVar6;
  undefined4 local_40;
  undefined4 local_3c;
  undefined *local_38;
  undefined auStack52 [12];
  int local_28;
  
  FUN_00411dc4(param_1,"QUERY_STRING",*(undefined4 *)(param_1 + 0xc4));
  FUN_00411dc4(param_1,"GATEWAY_INTERFACE","CGI/1.1");
  FUN_00411dc4(param_1,"SERVER_HOST",PTR_websHost_00430844);
  FUN_00411dc4(param_1,"SERVER_NAME",PTR_websHost_00430844);
  FUN_00411dc4(param_1,"SERVER_URL",DAT_00430c14);
  FUN_00411dc4(param_1,"REMOTE_HOST",param_1 + 0x30);
  FUN_00411dc4(param_1,"REMOTE_ADDR",param_1 + 0x30);
  FUN_00411dc4(param_1,"PATH_INFO",*(undefined4 *)(param_1 + 0xb4));
  stritoa(*(undefined4 *)PTR_websPort_00430840,auStack52,8);
  FUN_00411dc4(param_1,"SERVER_PORT",auStack52);
  FUN_00411dc4(param_1,"SERVER_ADDR",param_1 + 0x50);
  fmtAlloc(&local_38,0xfe,"%s/%s","RSS-Webs","1.4b191");
  FUN_00411dc4(param_1,"SERVER_SOFTWARE",local_38);
  bfreeSafe(local_38);
  FUN_00411dc4(param_1,"SERVER_PROTOCOL",*(undefined4 *)(param_1 + 0xe8));
  if ((*(uint *)(param_1 + 0x100) & 0x80000) == 0) {
    if (*(int *)(param_1 + 0xec) != 0) {
      pcVar5 = *(char **)(param_1 + 0xc4);
      iVar2 = *(int *)(param_1 + 0x110);
      if (pcVar5 == (char *)0x0) {
        iVar2 = balloc(iVar2 + 1);
        *(int *)(param_1 + 0xc4) = iVar2;
        if (iVar2 != 0) {
          (*(code *)PTR_memcpy_00430a90)
                    (iVar2,*(undefined4 *)(param_1 + 0xec),*(undefined4 *)(param_1 + 0x110));
          *(undefined *)(*(int *)(param_1 + 0xc4) + *(int *)(param_1 + 0x110)) = 0;
        }
      }
      else {
        if (*pcVar5 == '\0') {
          iVar3 = (*(code *)PTR_strlen_0043095c)(pcVar5);
          iVar2 = brealloc(pcVar5,iVar3 + iVar2 + 1);
          *(int *)(param_1 + 0xc4) = iVar2;
          iVar6 = iVar2 + iVar3;
          if (iVar2 == 0) goto LAB_0041260c;
        }
        else {
          iVar3 = (*(code *)PTR_strlen_0043095c)();
          iVar2 = brealloc(pcVar5,iVar3 + iVar2 + 2);
          *(int *)(param_1 + 0xc4) = iVar2;
          if (iVar2 == 0) goto LAB_0041260c;
          *(undefined *)(iVar2 + iVar3) = 0x26;
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
    iVar2 = FUN_0041128c(param_1,&local_40);
    if (iVar2 != 0) {
      local_28 = iVar2;
      bfree(*(undefined4 *)(param_1 + 0xec));
      *(int *)(param_1 + 0xec) = local_28;
      *(undefined4 *)(param_1 + 0x110) = local_40;
    }
  }
LAB_0041260c:
  uVar4 = bstrdup(*(undefined4 *)(param_1 + 0xc4));
  *(undefined4 *)(param_1 + 200) = uVar4;
  pcVar5 = (char *)(*(code *)PTR_strtok_004309f0)(uVar4,&DAT_0041eb28);
  while (pcVar5 != (char *)0x0) {
    local_38 = (undefined *)(*(code *)PTR_strchr_00430950)(pcVar5,0x3d);
    puVar1 = PTR_strlen_0043095c;
    if (local_38 == (undefined *)0x0) {
      local_38 = &DAT_0041ed68;
    }
    else {
      *local_38 = 0;
      local_38 = local_38 + 1;
      uVar4 = (*(code *)puVar1)(pcVar5);
      websDecodeUrl(pcVar5,pcVar5,uVar4);
      puVar1 = local_38;
      uVar4 = (*(code *)PTR_strlen_0043095c)(local_38);
      websDecodeUrl(puVar1,puVar1,uVar4);
    }
    if (*pcVar5 != '\0') {
      iVar2 = websGetVar(param_1,pcVar5,0);
      if (iVar2 == 0) {
        FUN_00411dc4(param_1,pcVar5,local_38,0);
      }
      else {
        fmtAlloc(&local_3c,0x100,"%s %s",iVar2,local_38);
        FUN_00411dc4(param_1,pcVar5,local_3c);
        bfreeSafe(local_3c);
      }
    }
    pcVar5 = (char *)(*(code *)PTR_strtok_004309f0)(0,&DAT_0041eb28);
  }
  return;
}

