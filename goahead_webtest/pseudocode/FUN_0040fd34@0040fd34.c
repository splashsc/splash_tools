
void FUN_0040fd34(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar1 = websGetVar(param_1,&DAT_0041e280,&DAT_0041ed68,param_4,&_mips_gp0_value);
  uVar2 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68);
  websHeader(param_1);
  FUN_0040f910(param_1);
  iVar3 = strcmpci(uVar2,&DAT_0041e1a8);
  if (iVar3 == 0) {
    iVar3 = umDeleteAccessLimit(uVar1);
    if (iVar3 == 0) {
      pcVar4 = "Access Limit for [%s], was successfully deleted.";
    }
    else {
      pcVar4 = "ERROR: Unable to delete Access Limit for [%s]";
    }
    websWrite(param_1,pcVar4,uVar1);
  }
  else {
    websWrite(param_1,"Delete Access Limit Cancelled");
  }
  FUN_0040f928(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

