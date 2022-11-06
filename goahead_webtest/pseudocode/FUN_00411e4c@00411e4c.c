
bool FUN_00411e4c(int param_1,char *param_2)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if ((param_2 != (char *)0x0) && (*param_2 != '\0')) {
    iVar2 = symLookup(*(undefined4 *)(param_1 + 0x20));
    bVar1 = iVar2 != 0;
  }
  return bVar1;
}

