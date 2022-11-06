
uint umGetGroupInUse(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = dbSearchStr(DAT_004304f8,"users","group",param_1,0);
  uVar2 = 1;
  if (iVar1 < 0) {
    uVar2 = dbSearchStr(DAT_004304f8,"access","group",param_1,0);
    uVar2 = ~uVar2 >> 0x1f;
  }
  return uVar2;
}

