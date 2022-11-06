
void websCloseServer(void)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  DAT_00430c18 = DAT_00430c18 + -1;
  if (DAT_00430c18 < 1) {
    FUN_00411d38();
    puVar1 = PTR_webs_00430854;
    iVar2 = *(int *)PTR_websMax_00430858;
    iVar3 = iVar2 << 2;
    for (; (*(int *)puVar1 != 0 && (-1 < iVar2)); iVar2 = iVar2 + -1) {
      iVar4 = *(int *)(*(int *)puVar1 + iVar3);
      if (iVar4 != 0) {
        socketCloseConnection(*(undefined4 *)(iVar4 + 0xf0));
        FUN_00412aa0(iVar4);
      }
      iVar3 = iVar3 + -4;
    }
    if (-1 < DAT_00430c1c) {
      (*(code *)PTR_close_0043093c)();
      DAT_00430c1c = -1;
    }
    if (-1 < DAT_00430c20) {
      (*(code *)PTR_close_0043093c)();
      DAT_00430c20 = -1;
    }
    websDefaultClose();
    symClose(*(undefined4 *)PTR_websMime_0043085c);
    websFormClose();
    websUrlHandlerClose();
    return;
  }
  return;
}

