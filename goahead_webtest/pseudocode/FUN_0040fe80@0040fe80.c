
void FUN_0040fe80(undefined4 param_1)

{
  short sVar1;
  char *pcVar2;
  undefined4 uVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  
  pcVar2 = (char *)websGetVar(param_1,&DAT_0041e280,&DAT_0041ed68);
  uVar3 = websGetVar(param_1,"group",&DAT_0041ed68);
  pcVar4 = (char *)websGetVar(param_1,"method",&DAT_0041ed68);
  pcVar5 = (char *)websGetVar(param_1,"secure",&DAT_0041ed68);
  uVar6 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68);
  websHeader(param_1);
  FUN_0040f910(param_1);
  iVar7 = strcmpci(uVar6,&DAT_0041e1a8);
  if (iVar7 == 0) {
    if ((pcVar2 != (char *)0x0) && (*pcVar2 != '\0')) {
      iVar7 = umAccessLimitExists(pcVar2);
      if (iVar7 == 0) {
        uVar6 = 1;
        if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
          uVar6 = (*(code *)PTR_atoi_0043096c)(pcVar4);
        }
        iVar7 = 0;
        if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {
          sVar1 = (*(code *)PTR_atoi_0043096c)(pcVar5,uVar6,0);
          iVar7 = (int)sVar1;
        }
        iVar7 = umAddAccessLimit(pcVar2,uVar6,iVar7,uVar3);
        if (iVar7 == 0) {
          pcVar4 = "Access limit for [%s], was successfully added.";
        }
        else {
          pcVar4 = "Unable to add Access Limit for [%s]";
        }
      }
      else {
        pcVar4 = "ERROR:  An Access Limit for [%s] already exists.";
      }
      websWrite(param_1,pcVar4,pcVar2);
      goto LAB_004100b4;
    }
    pcVar2 = "ERROR:  No URL was entered.";
  }
  else {
    pcVar2 = "Add Access Limit Cancelled.";
  }
  websWrite(param_1,pcVar2);
LAB_004100b4:
  FUN_0040f928(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

