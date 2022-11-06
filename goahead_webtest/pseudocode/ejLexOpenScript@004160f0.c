
undefined4 ejLexOpenScript(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = balloc(0x50);
  *param_1 = iVar1;
  uVar3 = 0xffffffff;
  if (iVar1 != 0) {
    (*(code *)PTR_memset_004309cc)(iVar1,0,0x50);
    iVar2 = ringqOpen(iVar1,0x6e,0xffffffff);
    if ((-1 < iVar2) && (iVar2 = ringqOpen(iVar1 + 0x1c,0x3ff,0xffffffff), -1 < iVar2)) {
      ringqPutStr(iVar1 + 0x1c,param_2);
      *(undefined4 *)(iVar1 + 0x48) = 1;
      *(undefined4 *)(iVar1 + 0x44) = 0;
      *(undefined4 *)(iVar1 + 0x4c) = 0;
      *(undefined4 *)(iVar1 + 0x40) = 0;
      uVar3 = 0;
    }
  }
  return uVar3;
}

