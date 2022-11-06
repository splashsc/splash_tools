
undefined4 umDeleteUser(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  trace(3,"UM: Deleting User <%s>\n",param_1);
  iVar1 = umGetUserProtected(param_1);
  if (iVar1 == 0) {
    iVar1 = dbSearchStr(DAT_004304f8,"users","name",param_1,0);
    if (-1 < iVar1) {
      uVar2 = dbDeleteRow(DAT_004304f8,"users",iVar1);
      return uVar2;
    }
    uVar2 = 0xfffffffe;
  }
  else {
    uVar2 = 0xfffffffd;
  }
  return uVar2;
}

