
/* WARNING: Removing unreachable block (ram,0x00415a58) */

int emfSchedCallback(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = hAllocEntry(&DAT_00430c30,&DAT_00430c34,0x10);
  puVar1 = PTR_time_004309c0;
  if (iVar2 < 0) {
    iVar2 = -1;
  }
  else {
    puVar4 = *(undefined4 **)(DAT_00430c30 + iVar2 * 4);
    *puVar4 = param_2;
    puVar4[1] = param_3;
    puVar4[3] = iVar2;
    iVar3 = (*(code *)puVar1)(0);
    puVar4[2] = (param_1 + 500) / 1000 + iVar3;
  }
  return iVar2;
}

