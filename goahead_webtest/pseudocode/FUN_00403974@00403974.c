
undefined4 FUN_00403974(int param_1)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined auStack656 [128];
  undefined auStack528 [128];
  char local_190 [128];
  undefined auStack272 [128];
  undefined auStack144 [128];
  undefined4 local_10;
  
  socketOpen();
  (*(code *)PTR_getcwd_004309a8)(auStack272,0x80);
  puVar1 = (undefined *)(*(code *)PTR_strrchr_00430a58)(auStack272,0x2f);
  if (puVar1 != (undefined *)0x0) {
    *puVar1 = 0;
  }
  if (param_1 == 0) {
    (*(code *)PTR_dxmlGetStr_004309b8)(local_190,"/onetouch/rsshttproot");
    if (local_190[0] == '\0') {
      (*(code *)PTR_sprintf_004309a0)(local_190,&DAT_0041d158,&DAT_0041d15c);
    }
    else if (local_190[0] != '/') {
      (*(code *)PTR_sprintf_004309a0)(auStack656,&DAT_0041d158,local_190);
      (*(code *)PTR_strcpy_00430ad8)(local_190,auStack656);
    }
    (*(code *)PTR_dxmlSetStr_00430954)(local_190,"/onetouch/rsshttproot");
  }
  else {
    (*(code *)PTR_sprintf_004309a0)(local_190,"%s/%s",auStack272,"wwwdemo");
  }
  websSetDefaultDir(local_190);
  local_10 = (*(code *)PTR_inet_ntoa_004309c4)(0);
  iVar2 = (*(code *)PTR_strlen_0043095c)(local_10);
  uVar3 = 0x80;
  if (iVar2 + 1U < 0x80) {
    uVar3 = iVar2 + 1U;
  }
  ascToUni(auStack528,local_10,uVar3);
  websSetIpaddr(auStack528);
  iVar2 = (*(code *)PTR_strlen_0043095c)(auStack144);
  uVar3 = 0x80;
  if (iVar2 + 1U < 0x80) {
    uVar3 = iVar2 + 1U;
  }
  ascToUni(auStack528,auStack144,uVar3);
  websSetHost(auStack528);
  websSetDefaultPage("default.asp");
  websSetPassword(&DAT_0041ed68);
  websOpenServer(DAT_00430030,5);
  websUrlHandlerDefine(&DAT_0041ed68,0,0,PTR_websSecurityHandler_004305e0,1);
  websUrlHandlerDefine("/goform",0,0,PTR_websFormHandler_004305e4,0);
  websUrlHandlerDefine("/cgi-bin",0,0,PTR_websCgiHandler_004305e8,0);
  websUrlHandlerDefine(&DAT_0041ed68,0,0,PTR_websDefaultHandler_004305ec,2);
  websAspDefine("aspTest",FUN_00404d54);
  websFormDefine("formTest",FUN_00404b90);
  websFormDefine("formUploadFileTest.xgi",FUN_004052d0);
  websFormDefine("rssfwupgd.xgi",FUN_00405150);
  websAspDefine("ConfigGet",FUN_00404c64);
  websAspDefine("ConfigGetArray",FUN_0040401c);
  websAspDefine("ConfigGetPath",FUN_00403ec4);
  websAspDefine("Generate_Key",FUN_00403e78);
  websAspDefine("ConfigRssGet",FUN_00403e24);
  formDefineUserMgmt();
  websUrlHandlerDefine("/",0,0,FUN_00403dac,0);
  return 0;
}

