
undefined1 * FUN_00411fa0(int param_1)

{
  int *piVar1;
  int *piVar2;
  
  piVar1 = &DAT_00430180;
  do {
    piVar2 = piVar1;
    if (*piVar2 == 0) {
      return &DAT_0041ed68;
    }
    piVar1 = piVar2 + 2;
  } while (param_1 != *piVar2);
  return (undefined1 *)piVar2[1];
}

