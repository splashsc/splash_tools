
undefined4 websUrlHandlerOpen(void)

{
  bool bVar1;
  int iVar2;
  
  iVar2 = DAT_00430bb0 + 1;
  bVar1 = DAT_00430bb0 == 0;
  DAT_00430bb0 = iVar2;
  if (bVar1) {
    websAspOpen();
    DAT_00430bb4 = 0;
    DAT_00430bb8 = 0;
  }
  return 0;
}

