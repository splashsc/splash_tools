
int FUN_00410e3c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  
  puVar4 = &_mips_gp0_value;
  websWrite(param_2,"<SELECT NAME=\"group\" SIZE=\"3\" TITLE=\"Select a Group\">",param_3,param_4,
            &_mips_gp0_value);
  iVar1 = websWrite(param_2,"<OPTION VALUE=\"\">[NONE]\n");
  iVar3 = 0;
  iVar2 = umGetFirstGroup();
  while ((iVar2 != 0 && (0 < iVar1))) {
    iVar1 = websWrite(param_2,"<OPTION VALUE=\"%s\">%s\n",iVar2,iVar2,puVar4);
    iVar3 = iVar3 + iVar1;
    iVar2 = umGetNextGroup(iVar2);
  }
  iVar1 = websWrite(param_2,"</SELECT>");
  return iVar3 + iVar1;
}

