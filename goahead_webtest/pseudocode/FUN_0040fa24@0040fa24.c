
int FUN_0040fa24(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar1 = websWrite(param_2,"<SELECT NAME=\"method\" SIZE=\"3\" TITLE=\"Select a Method\">",param_3,
                    param_4,&_mips_gp0_value);
  iVar2 = websWrite(param_2,"<OPTION VALUE=\"%d\">FULL ACCESS\n",1);
  iVar3 = websWrite(param_2,"<OPTION VALUE=\"%d\">BASIC ACCESS\n",2);
  iVar4 = websWrite(param_2,"<OPTION VALUE=\"%d\" SELECTED>DIGEST ACCESS\n",3);
  iVar5 = websWrite(param_2,"<OPTION VALUE=\"%d\">NO ACCESS\n",0);
  iVar6 = websWrite(param_2,"</SELECT>");
  return iVar1 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6;
}

