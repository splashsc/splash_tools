
void FUN_00410804(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  
  uVar1 = websGetVar(param_1,&DAT_0041e570,&DAT_0041ed68,param_4,&_mips_gp0_value);
  uVar2 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68);
  websHeader(param_1);
  FUN_0040f910(param_1);
  iVar3 = strcmpci(uVar2,&DAT_0041e1a8);
  if (iVar3 == 0) {
    iVar3 = umUserExists(uVar1);
    if (iVar3 == 0) {
      pcVar4 = "ERROR: User \"%s\" not found";
    }
    else {
      iVar3 = umGetUserProtected(uVar1);
      if (iVar3 == 0) {
        iVar3 = umDeleteUser(uVar1);
        if (iVar3 == 0) {
          pcVar4 = "User, \"%s\" was successfully deleted.";
        }
        else {
          pcVar4 = "ERROR: Unable to delete user, \"%s\" ";
        }
      }
      else {
        pcVar4 = "ERROR: User, \"%s\" is delete-protected.";
      }
    }
    websWrite(param_1,pcVar4,uVar1);
  }
  else {
    websWrite(param_1,"Delete User Cancelled");
  }
  FUN_0040f928(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

