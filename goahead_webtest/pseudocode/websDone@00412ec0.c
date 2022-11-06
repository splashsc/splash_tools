
/* WARNING: Removing unreachable block (ram,0x00412f80) */

void websDone(int *param_1,int param_2)

{
  undefined *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined auStack128 [4];
  undefined4 local_7c;
  undefined auStack120 [5];
  undefined local_73;
  undefined local_70;
  undefined local_6f;
  undefined local_61;
  undefined auStack96 [27];
  undefined local_45;
  undefined auStack68 [36];
  int local_20;
  int local_18;
  
  socketDeleteHandler(param_1[0x3c]);
  if (param_2 != 200) {
    param_1[0x40] = param_1[0x40] & 0xfffffffd;
  }
  if ((param_1[0x40] & 0x1000U) == 0) {
    local_7c = 0;
    (*(code *)PTR_time_004309c0)(auStack128);
    (*(code *)PTR_localtime_r_0043098c)(auStack128,auStack68);
    (*(code *)PTR_strftime_00430988)(auStack96,0x1c,"%d/%b/%Y:%H:%M:%S",auStack68);
    local_45 = 0;
    (*(code *)PTR_snprintf_00430aac)(auStack120,6,"%+03d00",local_20 / 0xe10);
    local_73 = 0;
    if (param_1[0x48] == 0) {
      local_70 = 0x2d;
      local_6f = 0;
    }
    else {
      (*(code *)PTR_snprintf_00430aac)(&local_70,0x10,"%d");
      local_61 = 0;
    }
    puVar4 = (undefined *)param_1[0x35];
    if (puVar4 == (undefined *)0x0) {
      puVar4 = &DAT_0041dfb8;
    }
    if ((param_1[0x40] & 0x20U) == 0) {
      if ((param_1[0x40] & 0x200U) == 0) {
        puVar1 = &DAT_0041eb58;
      }
      else {
        puVar1 = &DAT_0041eb5c;
      }
    }
    else {
      puVar1 = &DAT_0041eb50;
    }
    fmtAlloc(&local_7c,0x850,"%s - %s [%s %s] \"%s %s %s\" %d %s\n",param_1 + 0xc,puVar4,auStack96,
             auStack120,puVar1,param_1[0x2d],param_1[0x3a],param_2,&local_70);
    uVar2 = local_7c;
    local_18 = (*(code *)PTR_strlen_0043095c)(local_7c);
    uVar2 = ballocUniToAsc(uVar2,local_18 + 1);
    (*(code *)PTR_write_00430a4c)(DAT_00430c1c,uVar2,local_18);
    bfreeSafe(local_7c);
    bfreeSafe(uVar2);
  }
  websPageClose(param_1);
  if ((param_1[0x40] & 2U) == 0) {
    websTimeoutCancel(param_1);
    socketSetBlock(param_1[0x3c],1);
    socketFlush(param_1[0x3c]);
    socketCloseConnection(param_1[0x3c]);
  }
  else {
    iVar3 = socketFlush(param_1[0x3c]);
    if (iVar3 == 0) {
      param_1[0x3f] = 1;
      param_1[0x40] = param_1[0x40] | 0x1000;
      if (*param_1 != 0) {
        ringqFlush(param_1);
      }
      socketCreateHandler(param_1[0x3c],2,FUN_00415820,param_1);
      websTimeoutCancel(param_1);
      iVar3 = emfSchedCallback(60000,FUN_00413240,param_1);
      param_1[0xb] = iVar3;
      return;
    }
  }
  FUN_00412aa0(param_1);
  return;
}

