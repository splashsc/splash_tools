
undefined4
dbWriteStr(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  iVar1 = FUN_0041a750(0);
  uVar2 = 0xfffffffa;
  if (-1 < iVar1) {
    iVar3 = *(int *)(DAT_00430c60 + iVar1 * 4);
    uVar2 = 0xfffffff9;
    if (iVar3 != 0) {
      iVar1 = FUN_0041a150(iVar1,param_3);
      uVar2 = 0xfffffffe;
      if (-1 < iVar1) {
        uVar2 = 0xfffffff8;
        if (((*(int *)(*(int *)(iVar3 + 0xc) + iVar1 * 4) == 1) &&
            (uVar2 = 0xfffffffc, -1 < param_4)) && (param_4 < *(int *)(iVar3 + 0x10))) {
          iVar3 = *(int *)(*(int *)(iVar3 + 0x14) + param_4 * 4);
          uVar2 = 0xfffffffb;
          if (iVar3 != 0) {
            piVar4 = (int *)(iVar3 + iVar1 * 4);
            if (*piVar4 != 0) {
              bfree();
            }
            iVar1 = bstrdup(param_5);
            *piVar4 = iVar1;
            uVar2 = 0;
          }
        }
      }
    }
  }
  return uVar2;
}

