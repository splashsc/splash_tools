
void FUN_0041010c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char *pcVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  pcVar1 = (char *)websGetVar(param_1,"group",&DAT_0041ed68,param_4,&_mips_gp0_value);
  uVar2 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68);
  websHeader(param_1);
  FUN_0040f910(param_1);
  iVar3 = strcmpci(uVar2,&DAT_0041e1a8);
  if (iVar3 == 0) {
    if ((pcVar1 != (char *)0x0) && (*pcVar1 != '\0')) {
      iVar3 = umGetGroupProtected(pcVar1);
      if (iVar3 == 0) {
        iVar3 = umGetGroupInUse(pcVar1);
        if (iVar3 == 0) {
          iVar3 = umDeleteGroup(pcVar1);
          if (iVar3 == 0) {
            pcVar4 = "Group, \"%s\" was successfully deleted.";
          }
          else {
            pcVar4 = "ERROR: Unable to delete group, \"%s\" ";
          }
        }
        else {
          pcVar4 = "ERROR: Group, \"%s\" is being used.";
        }
      }
      else {
        pcVar4 = "ERROR: Group, \"%s\" is delete-protected.";
      }
      websWrite(param_1,pcVar4,pcVar1);
      goto LAB_00410294;
    }
    pcVar1 = "ERROR: No group was selected.";
  }
  else {
    pcVar1 = "Delete Group Cancelled.";
  }
  websWrite(param_1,pcVar1);
LAB_00410294:
  FUN_0040f928(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

