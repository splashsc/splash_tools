
void FUN_0040fb0c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  char *pcVar3;
  
  uVar1 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68,param_4,&_mips_gp0_value);
  websHeader(param_1);
  FUN_0040f910(param_1);
  iVar2 = strcmpci(uVar1,&DAT_0041e1a8);
  if (iVar2 == 0) {
    iVar2 = umRestore(0);
    if (iVar2 == 0) {
      pcVar3 = "User configuration was re-loaded successfully.";
    }
    else {
      pcVar3 = "ERROR: Unable to load user configuration.";
    }
  }
  else {
    pcVar3 = "Load Cancelled.";
  }
  websWrite(param_1,pcVar3);
  FUN_0040f928(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

