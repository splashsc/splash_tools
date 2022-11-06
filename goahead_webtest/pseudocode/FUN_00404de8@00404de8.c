
void FUN_00404de8(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined auStack40 [10];
  undefined auStack30 [14];
  
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    uVar1 = (*(code *)PTR_sys_uptime_seconds_00430a50)();
    (*(code *)PTR_dbgPrintf_00430a20)(&DAT_0041d520,uVar1);
    (*(code *)PTR_logPrintf_00430a1c)(7,"%s]","write_fwxml");
    (*(code *)PTR_logPrintf_00430a1c)(7,"result:%d sec:%d\n",param_2,param_3);
  }
  websWrite(param_1,"<?xml version=\"1.0\" ?>\n");
  websWrite(param_1,"<root>\n");
  websWrite(param_1,"<FwUpgdResult>%d</FwUpgdResult>\n",param_2);
  websWrite(param_1,"<RssGetWaitSec>%d</RssGetWaitSec>\n",param_3);
  websWrite(param_1,"</root>\n");
  (*(code *)PTR_sprintf_004309a0)(auStack40,"%d",param_2);
  (*(code *)PTR_sprintf_004309a0)(auStack30,"%d",param_3);
  (*(code *)PTR_write_TmpXmlFile_00430a94)("fwupgd_result.xml","FwUpgdResult",auStack40,0);
  (*(code *)PTR_write_TmpXmlFile_00430a94)("fwupgd_result.xml","RssGetWaitSec",auStack30,1);
  return;
}

