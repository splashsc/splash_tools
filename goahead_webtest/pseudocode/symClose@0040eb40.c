
void symClose(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  iVar1 = *(int *)(DAT_00430bf8 + param_1 * 4);
  puVar5 = &_mips_gp0_value;
  iVar3 = 0;
  if (iVar1 == 0) {
    return;
  }
  while( true ) {
    if (*(int *)(iVar1 + 4) <= iVar3) break;
    piVar2 = (int *)*(int *)(*(int *)(iVar1 + 8) + iVar3 * 4);
    while (piVar2 != (int *)0x0) {
      iVar4 = *piVar2;
      valueFree(piVar2 + 1);
      valueFree((int)piVar2 + 0x12);
      bfree(piVar2);
      piVar2 = (int *)iVar4;
    }
    iVar3 = iVar3 + 1;
  }
  bfree();
  DAT_00430bf4 = hFree(&DAT_00430bf8,param_1,param_3,param_4,puVar5);
  bfree(iVar1);
  return;
}

