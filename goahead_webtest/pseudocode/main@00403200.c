
/* WARNING: Restarted to delay deadcode elimination for space: ram */

undefined4 main(int param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  int iVar8;
  
  iVar2 = (*(code *)PTR_dxmlGetInt_00430a40)("/onetouch/debuglevel");
  puVar1 = PTR_daemon_log_level_00430990;
  *(int *)PTR_daemon_log_level_00430990 = iVar2;
  if (iVar2 < 1) {
    *(undefined4 *)puVar1 = 99;
  }
  (*(code *)PTR_strcpy_00430ad8)(PTR_daemon_log_header_00430ab0,&DAT_0041d3a8);
  iVar2 = (*(code *)PTR_dxmlGetInt_00430a40)("/onetouch/debuglogsize_k");
  puVar1 = PTR_daemon_log_file_size_k_00430998;
  *(int *)PTR_daemon_log_file_size_k_00430998 = iVar2;
  if (iVar2 < 0) {
    *(undefined4 *)puVar1 = 300;
  }
  iVar2 = 0;
  puVar7 = param_2;
  for (iVar6 = 1; iVar6 < param_1; iVar6 = iVar6 + 1) {
    iVar8 = (*(code *)PTR_strcmp_004309b4)(puVar7[1],"-demo");
    iVar2 = iVar2 + (uint)(iVar8 == 0);
    puVar7 = puVar7 + 1;
  }
  iVar6 = (*(code *)PTR_dxmlGetInt_00430a40)("/onetouch/rsshttpport");
  if (0 < iVar6) {
    DAT_00430030 = iVar6;
  }
  iVar8 = 1;
  puVar7 = param_2;
  while( true ) {
    if (param_1 <= iVar8) {
      (*(code *)PTR_logPrintf_00430a1c)(0,"RSS-HTTP Port=%d, ver:%s\n",DAT_00430030,"1.4b191");
      if (iVar6 != DAT_00430030) {
        (*(code *)PTR_dxmlSetInt_00430968)(DAT_00430030,"/onetouch/rsshttpport");
      }
      (*(code *)PTR_dxmlSetStr_00430954)("1.4b191","/runtime/VerInfo/Web");
      uVar5 = (*(code *)PTR_uiDefaultUserID_00430a24)();
      (*(code *)PTR_dxmlSetStr_00430954)(uVar5,"/runtime/sys/default_id");
      uVar5 = (*(code *)PTR_uiDefaultUserPW_00430ad0)();
      (*(code *)PTR_dxmlSetStr_00430954)(uVar5,"/runtime/sys/default_pw");
      bopen(0,0xf000,1);
      (*(code *)PTR_signal_00430a10)(0xd,1);
      (*(code *)PTR_signal_00430a10)(2,&LAB_00403850);
      (*(code *)PTR_signal_00430a10)(0xf,&LAB_00403850);
      iVar2 = FUN_00403974(iVar2);
      if (iVar2 < 0) {
        (*(code *)PTR_puts_00430a8c)("initWebs error");
        uVar5 = 0xffffffff;
      }
      else {
        DAT_00430b20 = 0;
        while (DAT_00430b20 == 0) {
          iVar2 = socketReady(0xffffffff);
          if ((iVar2 != 0) || (iVar2 = socketSelect(0xffffffff,1000), iVar2 != 0)) {
            socketProcess(0xffffffff);
          }
          websCgiCleanup();
          emfSchedProcess();
        }
        websCloseServer();
        socketClose();
        bclose();
        uVar5 = 0;
      }
      return uVar5;
    }
    uVar5 = puVar7[1];
    iVar3 = (*(code *)PTR_strcmp_004309b4)(uVar5,&DAT_0041d3e8);
    if (iVar3 == 0) break;
    iVar3 = (*(code *)PTR_strcmp_004309b4)(uVar5,&DAT_0041d4a8);
    if ((iVar3 == 0) && (iVar3 = (*(code *)PTR_atoi_0043096c)(puVar7[2]), 0 < iVar3)) {
      DAT_00430030 = iVar3;
    }
    iVar8 = iVar8 + 1;
    puVar7 = puVar7 + 1;
  }
  (*(code *)PTR_msgPrintf_00430a54)("Usage: %s [OPTIONS]\n",*param_2);
  uVar5 = (*(code *)PTR_starterLibVersion_00430970)();
  uVar4 = (*(code *)PTR_rssSpecVersion_004309f4)();
  (*(code *)PTR_msgPrintf_00430a54)
            ("  Info: ver:%s, StarterLib ver:%s, RssSpec ver:%s\n","1.4b191",uVar5,uVar4);
  (*(code *)PTR_msgPrintf_00430a54)("  -h \t\t\t\tshow this help message.\n");
  (*(code *)PTR_msgPrintf_00430a54)
            ("  -p <port_no>\t\tset the port number used by daemon, default: %d\n",DAT_00430030);
  return 0;
}

