
void bfree(int param_1)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if ((*(uint *)(param_1 + -4) & 0xffff000) == 0x8124000) {
    iVar2 = 0;
    if (*(int *)(param_1 + -8) != 0) {
      iVar2 = *(int *)(param_1 + -8) + -1 >> 4;
    }
    iVar3 = 0;
    while (bVar1 = iVar2 != 0, iVar2 = iVar2 >> 1, bVar1) {
      iVar3 = iVar3 + 1;
    }
    if ((int)*(uint *)(param_1 + -4) < 0) {
                    /* WARNING: Could not recover jumptable at 0x00406334. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_free_00430934)();
      return;
    }
    *(undefined4 *)(param_1 + -8) = (&DAT_00430b54)[iVar3];
    (&DAT_00430b54)[iVar3] = param_1 + -8;
    *(undefined4 *)(param_1 + -4) = 0x77777777;
  }
  return;
}

