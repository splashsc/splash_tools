
longlong websUrlHandlerDelete(int param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  piVar1 = DAT_00430bb4;
  uVar2 = 0;
  do {
    uVar4 = uVar2;
    piVar3 = piVar1;
    if (DAT_00430bb8 <= (int)uVar4) {
      return CONCAT44(uVar4,0xffffffff);
    }
    piVar1 = piVar3 + 6;
    uVar2 = uVar4 + 1;
  } while (*piVar3 != param_1);
  *piVar3 = 0;
  return (ulonglong)uVar4 << 0x20;
}

