
int FUN_00410c84(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = &_mips_gp0_value;
  iVar1 = umGetFirstAccessLimit();
  iVar2 = websWrite(param_2,"<SELECT NAME=\"url\" SIZE=\"3\" TITLE=\"Select a URL\">");
  iVar3 = 0;
  while ((iVar1 != 0 && (0 < iVar2))) {
    iVar2 = websWrite(param_2,"<OPTION VALUE=\"%s\">%s\n",iVar1,iVar1,puVar4);
    iVar3 = iVar3 + iVar2;
    iVar1 = umGetNextAccessLimit(iVar1);
  }
  iVar1 = websWrite(param_2,"</SELECT>");
  return iVar3 + iVar1;
}

