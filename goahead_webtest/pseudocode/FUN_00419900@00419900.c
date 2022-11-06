
undefined4 FUN_00419900(void)

{
  int iVar1;
  undefined4 uVar2;
  char *pcVar3;
  
  iVar1 = FUN_004197ac();
  uVar2 = 1;
  if (iVar1 != 0) {
    pcVar3 = (char *)FUN_00419690(iVar1);
    if ((pcVar3 == (char *)0x0) || (*pcVar3 == '\0')) {
      uVar2 = FUN_0041944c(iVar1);
    }
    else {
      uVar2 = FUN_00418c64(pcVar3);
    }
    bfree(iVar1);
  }
  return uVar2;
}

