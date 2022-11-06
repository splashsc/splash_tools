
void FUN_004052d0(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  undefined4 *puVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int unaff_s3;
  char local_d8 [64];
  char acStack152 [128];
  
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    uVar1 = (*(code *)PTR_sys_uptime_seconds_00430a50)();
    (*(code *)PTR_dbgPrintf_00430a20)(&DAT_0041d520,uVar1);
    (*(code *)PTR_logPrintf_00430a1c)(7,"%s]","formUploadFileTest");
    (*(code *)PTR_logPrintf_00430a1c)(7,"\n");
  }
  (*(code *)PTR_memset_004309cc)(local_d8,0,0x40);
  (*(code *)PTR_memset_004309cc)(acStack152,0,0x80);
  (*(code *)PTR_dxmlGetStr_004309b8)(acStack152,"/onetouch/tempdirecory");
  iVar2 = (*(code *)PTR_strlen_0043095c)(acStack152);
  if (acStack152[iVar2] != '/') {
    (*(code *)PTR_strcat_00430a3c)(acStack152,"/");
  }
  (*(code *)PTR_dxmlGetStr_004309b8)(local_d8,"/fwupgradeinfo/fwupgradefn");
  if (local_d8[0] == '\0') {
    (*(code *)PTR_strcpy_00430ad8)(local_d8,"upld.bin");
    (*(code *)PTR_dxmlSetStr_00430954)(local_d8,"/fwupgradeinfo/fwupgradefn");
  }
  (*(code *)PTR_strcat_00430a3c)(acStack152,local_d8);
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    (*(code *)PTR_logPrintf_00430a1c)(7,"savedfn=\'%s\'...........................\n\n",acStack152);
  }
  websHeader(param_1);
  pcVar3 = (char *)websGetVar(param_1,"filename",&DAT_0041ed68);
  pcVar5 = (char *)0x0;
  if ((pcVar3 != (char *)0x0) && (*pcVar3 != '\0')) {
    iVar2 = (*(code *)PTR_strrchr_00430a58)(pcVar3,0x2f);
    pcVar5 = (char *)(iVar2 + 1);
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_strrchr_00430a58)(pcVar3,0x5c);
      pcVar5 = (char *)(iVar2 + 1);
      if (iVar2 == 0) {
        pcVar5 = pcVar3;
      }
    }
  }
  if (6 < *(int *)PTR_daemon_log_level_00430990) {
    (*(code *)PTR_logPrintf_00430a1c)(7,"fn=%s, bn=%s  .......\n",pcVar3,pcVar5);
  }
  websWrite(param_1,"Filename = %s<br>Size = %d bytes<br>",pcVar5,*(undefined4 *)(param_1 + 0x110));
  iVar2 = (*(code *)PTR_fopen_004309d4)(acStack152,&DAT_0041d6e4);
  if (iVar2 == 0) {
    websWrite(param_1,"File open failed!<br>");
  }
  else {
    iVar7 = 0;
    for (iVar6 = *(int *)(param_1 + 0x110); 0 < iVar6; iVar6 = iVar6 - unaff_s3) {
      unaff_s3 = (*(code *)PTR_fwrite_00430980)(*(int *)(param_1 + 0xec) + iVar7,1,iVar6,iVar2);
      iVar7 = iVar7 + unaff_s3;
      if (unaff_s3 < iVar6) {
        iVar7 = iVar7 - unaff_s3;
        uVar1 = (*(code *)PTR_ferror_00430a18)(iVar2);
        websWrite(param_1,
                  "File write failed.<br>  ferror=%d locWrite=%d numLeft=%d numWrite=%d Size=%d bytes<br>"
                  ,uVar1,iVar7,iVar6,unaff_s3,*(undefined4 *)(param_1 + 0x110));
        goto LAB_004056fc;
      }
    }
    if (iVar6 == 0) {
      iVar2 = (*(code *)PTR_fclose_004309c8)(iVar2);
      uVar1 = *(undefined4 *)(param_1 + 0x110);
      if (iVar2 == 0) {
        websWrite(param_1,"File Size Written = %d bytes<br>",uVar1);
      }
      else {
        puVar4 = (undefined4 *)(*(code *)PTR___errno_location_00430978)();
        websWrite(param_1,
                  "File close failed.<br>  errno=%d locWrite=%d numLeft=%d numWrite=%d Size=%d bytes<br>"
                  ,*puVar4,iVar7,0,unaff_s3,uVar1);
      }
    }
    else {
LAB_004056fc:
      websWrite(param_1,"numLeft=%d locWrite=%d Size=%d bytes<br>",iVar6,iVar7,
                *(undefined4 *)(param_1 + 0x110));
    }
  }
  FUN_00404fac(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

