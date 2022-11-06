
undefined4 umDeleteGroup(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  trace(3,"UM: Deleting Group <%s>\n",param_1);
  iVar1 = umGetGroupInUse(param_1);
  uVar2 = 0xfffffffb;
  if (iVar1 == 0) {
    iVar1 = umGetGroupProtected(param_1);
    if (iVar1 == 0) {
      iVar1 = dbSearchStr(DAT_004304f8,"groups","name",param_1,0);
      if (-1 < iVar1) {
        uVar2 = dbDeleteRow(DAT_004304f8,"groups",iVar1);
        return uVar2;
      }
      uVar2 = 0xfffffffe;
    }
    else {
      uVar2 = 0xfffffffd;
    }
  }
  return uVar2;
}

