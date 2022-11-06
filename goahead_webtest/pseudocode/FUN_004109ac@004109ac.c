
void FUN_004109ac(undefined4 param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char *pcVar6;
  undefined4 uVar7;
  int iVar8;
  
  uVar2 = websGetVar(param_1,&DAT_0041e570,&DAT_0041ed68);
  uVar3 = websGetVar(param_1,"password",&DAT_0041ed68);
  uVar4 = websGetVar(param_1,"passconf",&DAT_0041ed68);
  uVar5 = websGetVar(param_1,"group",&DAT_0041ed68);
  pcVar6 = (char *)websGetVar(param_1,"enabled",&DAT_0041ed68);
  uVar7 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68);
  websHeader(param_1);
  FUN_0040f910(param_1);
  iVar8 = strcmpci(uVar7,&DAT_0041e1a8);
  if (iVar8 == 0) {
    iVar8 = (*(code *)PTR_strcmp_004309b4)(uVar3,uVar4);
    if (iVar8 == 0) {
      bVar1 = true;
      if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
        iVar8 = (*(code *)PTR_strcmp_004309b4)(pcVar6,&DAT_0041e520);
        bVar1 = iVar8 != 0;
      }
      iVar8 = umAddUser(uVar2,uVar3,uVar5,0,bVar1);
      if (iVar8 == 0) {
        websWrite(param_1,"User, \"%s\" was successfully added.",uVar2);
        goto LAB_00410c28;
      }
      if (iVar8 == -6) {
        pcVar6 = "Invalid user name.";
      }
      else if (iVar8 < -5) {
        if (iVar8 == -7) {
          pcVar6 = "Invalid password.";
        }
        else {
LAB_00410bdc:
          pcVar6 = "Error writing user record.";
        }
      }
      else if (iVar8 == -4) {
        pcVar6 = "User already exists.";
      }
      else {
        if (iVar8 != -2) goto LAB_00410bdc;
        pcVar6 = "Invalid or unselected group.";
      }
      websWrite(param_1,"Unable to add user, \"%s\".  %s",uVar2,pcVar6);
      goto LAB_00410c28;
    }
    pcVar6 = "Confirmation Password did not match.";
  }
  else {
    pcVar6 = "Add User Cancelled";
  }
  websWrite(param_1,pcVar6);
LAB_00410c28:
  FUN_0040f928(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

