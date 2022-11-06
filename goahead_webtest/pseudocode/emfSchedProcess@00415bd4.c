
void emfSchedProcess(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (0 < DAT_00430c34) {
    uVar2 = DAT_00430c38;
    if (DAT_00430c34 <= (int)DAT_00430c38) {
      DAT_00430c38 = 0;
      uVar2 = DAT_00430c38;
    }
    do {
      iVar1 = *(int *)(DAT_00430c30 + uVar2 * 4);
      if ((iVar1 != 0) &&
         (iVar3 = *(int *)(iVar1 + 8), iVar1 = (*(code *)PTR_time_004309c0)(0), iVar3 <= iVar1)) {
        FUN_00415998(uVar2);
        DAT_00430c38 = uVar2 + 1;
        return;
      }
      uVar2 = uVar2 + 1 & -(uint)((int)(uVar2 + 1) < DAT_00430c34);
    } while (uVar2 != DAT_00430c38);
  }
  return;
}

