
undefined4 FUN_0040a508(int param_1,int param_2,undefined4 *param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  char *pcVar7;
  undefined auStack184 [52];
  int local_84;
  
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  iVar2 = FUN_004083a0(param_1);
  if (iVar2 != 0) {
    iVar3 = (*(code *)PTR_open_00430958)(param_2,0,0x1b6);
    if (iVar3 < 0) {
      pcVar7 = "Bad handle %d";
      param_2 = param_1;
    }
    else {
      iVar4 = (*(code *)PTR_stat_00430984)(param_2,auStack184);
      if (iVar4 < 0) {
        (*(code *)PTR_close_0043093c)(iVar3);
        pcVar7 = "Cant stat %s";
      }
      else {
        iVar4 = balloc(local_84 + 1);
        if (iVar4 == 0) {
          (*(code *)PTR_close_0043093c)();
          pcVar7 = "Cant malloc %d";
          param_2 = local_84;
        }
        else {
          iVar5 = (*(code *)PTR_read_00430a0c)(iVar3,iVar4,local_84);
          puVar1 = PTR_close_0043093c;
          if (iVar5 == local_84) {
            *(undefined *)(iVar4 + iVar5) = 0;
            (*(code *)puVar1)(iVar3);
            iVar3 = ballocAscToUni(iVar4,local_84);
            if (iVar3 != 0) {
              bfree(iVar4);
              uVar6 = FUN_0040a4a4(param_1,iVar3,param_3);
              bfree(iVar3);
              return uVar6;
            }
            bfree(iVar4);
            pcVar7 = "Cant malloc %d";
            param_2 = local_84 + 1;
          }
          else {
            (*(code *)PTR_close_0043093c)(iVar3);
            bfree(iVar4);
            pcVar7 = "Error reading %s";
          }
        }
      }
    }
    ejError(iVar2,pcVar7,param_2);
  }
  return 0;
}

