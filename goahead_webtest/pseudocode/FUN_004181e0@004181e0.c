
undefined4 FUN_004181e0(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_18 [2];
  
  iVar1 = dbSearchStr(DAT_004304f8,"users","name",param_1,0);
  uVar2 = 0;
  if (-1 < iVar1) {
    local_18[0] = 0;
    dbReadStr(DAT_004304f8,"users","password",iVar1,local_18);
    uVar2 = bstrdup(local_18[0]);
    FUN_00417af0(uVar2);
  }
  return uVar2;
}

