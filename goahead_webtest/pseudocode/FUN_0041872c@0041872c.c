
undefined4 FUN_0041872c(undefined4 param_1,short param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = dbSearchStr(DAT_004304f8,"users","name",param_1,0);
  uVar2 = 0xfffffffe;
  if (-1 < iVar1) {
    uVar2 = dbWriteInt(DAT_004304f8,"users",&DAT_0041fc14,iVar1,(int)param_2);
  }
  return uVar2;
}
