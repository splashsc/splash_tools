
undefined4 FUN_0041829c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  trace(3,"UM: Attempting to change the password for user <%s>\n",param_1);
  iVar1 = dbSearchStr(DAT_004304f8,"users","name",param_1,0);
  uVar2 = 0xfffffffe;
  if (-1 < iVar1) {
    uVar3 = bstrdup(param_2);
    FUN_00417af0(uVar3);
    uVar2 = dbWriteStr(DAT_004304f8,"users","password",iVar1,uVar3);
    bfree(uVar3);
  }
  return uVar2;
}

