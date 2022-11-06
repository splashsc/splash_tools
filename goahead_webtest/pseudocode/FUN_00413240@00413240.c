
void FUN_00413240(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_time_004309c0)(0);
  iVar1 = iVar1 - *(int *)(param_1 + 0x28);
  if (59999 < iVar1 * 1000) {
    *(int *)(PTR_websStats_00430694 + 0x14) = *(int *)(PTR_websStats_00430694 + 0x14) + 1;
    emfUnschedCallback();
    *(undefined4 *)(param_1 + 0x2c) = 0xffffffff;
    websDone(param_1,0x194);
    return;
  }
  emfReschedCallback(param_2,iVar1 * -1000 + 60000);
  return;
}

