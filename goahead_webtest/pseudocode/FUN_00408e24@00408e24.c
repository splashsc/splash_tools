
undefined4 FUN_00408e24(void)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_004083a0();
  uVar2 = 0xffffffff;
  if (piVar1 != (int *)0x0) {
    uVar2 = *(undefined4 *)(*piVar1 + 0x48);
  }
  return uVar2;
}

