
void FUN_0040cc18(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = socketPtr();
  if (iVar1 != 0) {
    if (-1 < param_2) {
      ringqClose(iVar1 + 0x40);
      ringqOpen(iVar1 + 0x40,param_2 + 1,param_2 + 1);
    }
    if (-1 < param_3) {
      ringqClose(iVar1 + 0x78);
      ringqOpen(iVar1 + 0x78,param_3 + 1,param_3 + 1);
    }
    if (-1 < param_4) {
      ringqClose(iVar1 + 0x5c);
      ringqOpen(iVar1 + 0x5c,param_4 + 1,param_4 + 1);
      return;
    }
  }
  return;
}

