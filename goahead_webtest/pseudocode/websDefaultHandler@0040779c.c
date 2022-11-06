
undefined4 websDefaultHandler(int param_1)

{
  char cVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  char *pcVar7;
  code *pcVar8;
  code *pcVar9;
  int in_stack_00000014;
  undefined4 local_60;
  int local_5c [3];
  undefined auStack80 [32];
  int local_30;
  uint local_2c;
  int local_28;
  int local_24;
  
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    uVar3 = (*(code *)PTR_sys_uptime_seconds_00430a50)();
    (*(code *)PTR_dbgPrintf_00430a20)(&DAT_0041d520,uVar3);
    (*(code *)PTR_logPrintf_00430a1c)(7,"%s]","websDefaultHandler");
    (*(code *)PTR_logPrintf_00430a1c)
              (7,"url:%s,query:%s,cookie:\'%s\'\n",*(undefined4 *)(param_1 + 0xb8),
               *(undefined4 *)(param_1 + 0xc4),*(undefined4 *)(param_1 + 0xd8));
  }
  uVar3 = *(undefined4 *)(param_1 + 0xb8);
  iVar4 = (*(code *)PTR_strncmp_00430a08)(uVar3,"/rssui/",7);
  if (((iVar4 == 0) || (iVar4 = (*(code *)PTR_strncmp_00430a08)(uVar3,"/rsstest/",9), iVar4 == 0))
     || (iVar4 = (*(code *)PTR_strncmp_00430a08)(uVar3,"/tmp/rss",8), iVar4 == 0)) {
LAB_004078ec:
    init_DHttpd_WebsRec(param_1,auStack80);
    iVar4 = (*(code *)PTR_dhttpd_WebsHandler_00430994)(auStack80);
    pcVar8 = (code *)PTR_websHeader2_004306e4;
    if ((iVar4 == 2) || (pcVar8 = (code *)PTR_websXmlHeader_0043061c, iVar4 == 3)) {
      (*pcVar8)(param_1);
      if (local_30 != 0) {
        websWrite(param_1);
      }
      websDone(param_1,200);
    }
    else if (iVar4 == 1) {
      if ((local_28 != 0) && (local_24 != 0)) {
        (*(code *)PTR_strcpy_00430ad8)(PTR_newUserSessionID_004306e0,local_24 + 0x100);
      }
      websRedirect(param_1,local_30);
      if (6 < *(int *)PTR_daemon_log_level_00430990) {
        (*(code *)PTR_logPrintf_00430a1c)(7,"redirect to \'%s\'\n",local_30);
      }
    }
    bVar2 = false;
    (*(code *)PTR_free_DHttpdWebsRec_004309f8)(auStack80);
    if (1 < iVar4 + 1U) {
      return 1;
    }
  }
  else {
    iVar4 = (*(code *)PTR_strncmp_00430a08)(uVar3,"/tmp/OT_log.txt",0xf);
    bVar2 = true;
    if (iVar4 == 0) goto LAB_004078ec;
    local_2c = 0;
  }
  uVar5 = websGetRequestFlags(param_1);
  iVar4 = FUN_0040748c(param_1,in_stack_00000014);
  if (iVar4 < 0) {
    pcVar7 = (char *)0x1f4;
    pcVar8 = (code *)"Invalid URL";
    pcVar9 = (code *)PTR_websError_00430608;
  }
  else {
    iVar4 = websGetRequestLpath(param_1);
    iVar6 = (*(code *)PTR_strlen_0043095c)(iVar4);
    pcVar7 = (char *)(iVar4 + iVar6 + -1);
    cVar1 = *pcVar7;
    if ((cVar1 == '/') || (cVar1 == '\\')) {
      *pcVar7 = '\0';
    }
    iVar6 = websPageIsDirectory(iVar4);
    if (iVar6 != 0) {
      iVar4 = (*(code *)PTR_strlen_0043095c)(in_stack_00000014);
      cVar1 = *(char *)(in_stack_00000014 + iVar4 + -1);
      if ((cVar1 == '/') || (cVar1 == '\\')) {
        iVar4 = iVar4 + -1;
        *(undefined *)(in_stack_00000014 + iVar4) = 0;
      }
      uVar3 = DAT_00430ba4;
      iVar6 = (*(code *)PTR_strlen_0043095c)(DAT_00430ba4);
      fmtAlloc(&local_60,iVar6 + 2 + iVar4,"%s/%s",in_stack_00000014,uVar3);
      websRedirect(param_1,local_60);
      bfreeSafe(local_60);
      return 1;
    }
    if (6 < *(int *)PTR_daemon_log_level_00430990) {
      (*(code *)PTR_logPrintf_00430a1c)(7,"lpath=%s, path=%s\n",iVar4,in_stack_00000014);
    }
    iVar6 = websPageOpen(param_1,iVar4,in_stack_00000014,0,0x1b6);
    if (iVar6 < 0) {
      if (bVar2) {
        uVar3 = (*(code *)PTR_generateLoginUrl_004309bc)();
        websRedirect(param_1,uVar3);
        if (*(int *)PTR_daemon_log_level_00430990 < 7) {
          return 1;
        }
        pcVar8 = *(code **)(param_1 + 0xb8);
        pcVar7 = "Cannot open URL \'%s\', redirect to login page.\n";
        param_1 = 7;
        pcVar9 = (code *)PTR_logPrintf_00430a1c;
      }
      else {
        pcVar7 = (char *)0x194;
        pcVar8 = (code *)"Cannot open URL";
        pcVar9 = (code *)PTR_websError_00430608;
      }
    }
    else {
      iVar6 = websPageStat(param_1,iVar4,in_stack_00000014,local_5c);
      if (-1 < iVar6) {
        *(int *)(PTR_websStats_00430694 + 0x1c) = *(int *)(PTR_websStats_00430694 + 0x1c) + 1;
        iVar6 = websGetDateString(0);
        if (iVar6 != 0) {
          websWrite(param_1,"HTTP/1.0 200 OK\r\nDate: %s\r\n",iVar6);
          websWrite(param_1,"Server: %s/%s\r\n","RSS-Webs","1.4b191");
          bfree(iVar6);
        }
        local_2c = uVar5 & 0x100 | local_2c;
        if (local_2c == 0) {
          iVar6 = websGetDateString(local_5c);
          if (iVar6 != 0) {
            websWrite(param_1,"Last-modified: %s\r\n",iVar6);
            bfree(iVar6);
          }
          if (local_5c[0] != 0) {
            websWrite(param_1,"Content-length: %d\r\n",local_5c[0]);
            websSetRequestBytes(param_1,local_5c[0]);
          }
        }
        else {
          websWrite(param_1,"Pragma: no-cache\r\nCache-Control: no-cache\r\n");
        }
        uVar3 = websGetRequestType(param_1);
        websWrite(param_1,"Content-type: %s\r\n",uVar3);
        if (((uVar5 & 2) != 0) && (local_2c == 0)) {
          websWrite(param_1,"Connection: keep-alive\r\n");
        }
        websWrite(param_1,"\r\n");
        if ((uVar5 & 0x200) == 0) {
          if ((uVar5 & 0x100) == 0) {
            pcVar7 = (char *)0x4;
            pcVar8 = FUN_004071f0;
            pcVar9 = (code *)PTR_websSetRequestSocketHandler_00430704;
            goto LAB_00407edc;
          }
          iVar4 = websAspRequest(param_1,iVar4);
          if (iVar4 < 0) {
            return 1;
          }
        }
        websDone(param_1,200);
        return 1;
      }
      pcVar7 = (char *)0x190;
      pcVar8 = (code *)"Cannot stat page for URL";
      pcVar9 = (code *)PTR_websError_00430608;
    }
  }
LAB_00407edc:
  (*pcVar9)(param_1,pcVar7,pcVar8);
  return 1;
}

