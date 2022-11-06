
void FUN_00405150(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_40;
  undefined auStack60 [52];
  
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    uVar1 = (*(code *)PTR_sys_uptime_seconds_00430a50)();
    (*(code *)PTR_dbgPrintf_00430a20)(&DAT_0041d520,uVar1);
    (*(code *)PTR_logPrintf_00430a1c)(7,"%s]","rssfwupgd");
    (*(code *)PTR_logPrintf_00430a1c)
              (7,"wp->url:%s, wp->cookie:\'%s\'\n",*(undefined4 *)(param_1 + 0xb8),
               *(undefined4 *)(param_1 + 0xd8));
  }
  (*(code *)PTR_remove_TmpXmlFile_00430a6c)("fwupgd_result.xml");
  websXmlHeader(param_1);
  local_40 = 0;
  init_DHttpd_WebsRec(param_1,auStack60);
  iVar2 = (*(code *)PTR_chkByPassLoginPage_00430ab4)();
  if ((iVar2 == 0) &&
     (iVar2 = (*(code *)PTR_checkUserAuth_00430ac4)(auStack60,&local_40), iVar2 != 0)) {
    FUN_00404de8(param_1,2,0);
  }
  else {
    FUN_00404fac(param_1);
  }
  (*(code *)PTR_free_DHttpdWebsRec_004309f8)(auStack60);
  websDone(param_1,200);
  return;
}

