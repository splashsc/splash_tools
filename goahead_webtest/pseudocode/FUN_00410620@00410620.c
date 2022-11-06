
void FUN_00410620(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar1 = websGetVar(param_1,&DAT_0041e570,&DAT_0041ed68,param_4,&_mips_gp0_value);
  uVar2 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68);
  websHeader(param_1);
  websWrite(param_1,"<body>");
  iVar3 = strcmpci(uVar2,&DAT_0041e1a8);
  if (iVar3 == 0) {
    iVar3 = umUserExists(uVar1);
    if (iVar3 == 0) {
      pcVar4 = "ERROR: User <b>%s</b> not found.\n";
    }
    else {
      websWrite(param_1,"<h2>User ID: <b>%s</b></h2>\n",uVar1);
      uVar2 = umGetUserGroup(uVar1);
      websWrite(param_1,"<h3>User Group: <b>%s</b></h3>\n",uVar2);
      uVar1 = umGetUserEnabled(uVar1);
      pcVar4 = "<h3>Enabled: <b>%d</b></h3>\n";
    }
    websWrite(param_1,pcVar4,uVar1);
  }
  else {
    websWrite(param_1,"Display User Cancelled");
  }
  websWrite(param_1,"</body>\n");
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

