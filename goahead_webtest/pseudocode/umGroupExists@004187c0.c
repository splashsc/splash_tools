
uint umGroupExists(undefined4 param_1)

{
  uint uVar1;
  
  uVar1 = dbSearchStr(DAT_004304f8,"groups","name",param_1,0);
  return ~uVar1 >> 0x1f;
}

