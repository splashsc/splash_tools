
void FUN_00404b90(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = websGetVar(param_1,"name","Joe Smith",param_4,&_mips_gp0_value);
  uVar2 = websGetVar(param_1,"address","1212 Milky Way Ave.");
  websHeader(param_1);
  websWrite(param_1,"<body><h2>Name: %s, Address: %s</h2>\n",uVar1,uVar2);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

