
/* WARNING: Removing unreachable block (ram,0x00415b14) */

void emfReschedCallback(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((DAT_00430c30 != 0) && (param_1 != -1)) && (param_1 < DAT_00430c34)) &&
     (iVar2 = *(int *)(DAT_00430c30 + param_1 * 4), iVar2 != 0)) {
    iVar1 = (*(code *)PTR_time_004309c0)(0);
    *(int *)(iVar2 + 8) = (param_2 + 500) / 1000 + iVar1;
  }
  return;
}

