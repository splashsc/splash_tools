
void FUN_00406530(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined auStack432 [52];
  int local_17c;
  undefined auStack280 [260];
  
  iVar1 = (*(code *)PTR_stat_00430984)(param_1[2],auStack432);
  if ((iVar1 == 0) && ((int)param_1[7] < local_17c)) {
    iVar1 = (*(code *)PTR_open_00430958)(param_1[2],0,0x124);
    if (-1 < iVar1) {
      uVar3 = *param_1;
      if (param_1[7] == 0) {
        websWrite(uVar3,"HTTP/1.0 200 OK\r\n");
      }
      (*(code *)PTR_lseek_00430a68)(iVar1,param_1[7],0);
      while( true ) {
        iVar2 = (*(code *)PTR_read_00430a0c)(iVar1,auStack280,0xfe);
        if (iVar2 < 1) break;
        websWriteBlock(uVar3,auStack280,iVar2);
        param_1[7] = param_1[7] + iVar2;
      }
      (*(code *)PTR_close_0043093c)(iVar1);
    }
  }
  return;
}

