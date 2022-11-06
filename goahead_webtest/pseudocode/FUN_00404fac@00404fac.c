
void FUN_00404fac(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    uVar1 = (*(code *)PTR_sys_uptime_seconds_00430a50)();
    (*(code *)PTR_dbgPrintf_00430a20)(&DAT_0041d520,uVar1);
    (*(code *)PTR_logPrintf_00430a1c)(7,"%s]","do_fwupgrade");
    (*(code *)PTR_logPrintf_00430a1c)(7,"\n");
  }
  iVar2 = (*(code *)PTR_exe_ExternalCall_00430a48)(0x80);
  if (iVar2 != 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = (*(code *)PTR_get_ExternalCall_UseSec_00430ab8)(0x80);
  }
  FUN_00404de8(param_1,iVar2 != 0,uVar1);
  (*(code *)PTR_dxmlSetInt_00430968)(0,"/runtime/fwupgradeinfo/state");
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    uVar1 = (*(code *)PTR_sys_uptime_seconds_00430a50)();
    (*(code *)PTR_dbgPrintf_00430a20)(&DAT_0041d520,uVar1);
    (*(code *)PTR_logPrintf_00430a1c)(7,"%s]","do_fwupgrade");
    (*(code *)PTR_logPrintf_00430a1c)(7,"done\n");
  }
  return;
}

