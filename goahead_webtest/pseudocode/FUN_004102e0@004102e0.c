
void FUN_004102e0(undefined4 param_1)

{
  undefined *puVar1;
  bool bVar2;
  ushort uVar3;
  char *pcVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  char *pcVar11;
  
  pcVar4 = (char *)websGetVar(param_1,"group",&DAT_0041ed68);
  pcVar5 = (char *)websGetVar(param_1,"method",&DAT_0041ed68);
  pcVar6 = (char *)websGetVar(param_1,"enabled",&DAT_0041ed68);
  pcVar7 = (char *)websGetVar(param_1,"privilege",&DAT_0041ed68);
  uVar8 = websGetVar(param_1,&DAT_0041e1a8,&DAT_0041ed68);
  websHeader(param_1);
  FUN_0040f910(param_1);
  iVar9 = strcmpci(uVar8,&DAT_0041e1a8);
  if (iVar9 == 0) {
    if ((pcVar4 != (char *)0x0) && (*pcVar4 != '\0')) {
      iVar9 = umGroupExists(pcVar4);
      if (iVar9 == 0) {
        iVar9 = 0;
        if ((pcVar7 != (char *)0x0) && (pcVar11 = pcVar7, *pcVar7 != '\0')) {
          while( true ) {
            puVar1 = PTR_atoi_0043096c;
            if (*pcVar11 == '\0') break;
            if (*pcVar11 == ' ') {
              *pcVar11 = '\0';
              uVar3 = (*(code *)puVar1)(pcVar7);
              iVar9 = (int)(short)((ushort)iVar9 | uVar3);
              *pcVar11 = ' ';
              pcVar7 = pcVar11 + 1;
            }
            pcVar11 = pcVar11 + 1;
          }
          uVar3 = (*(code *)PTR_atoi_0043096c)(pcVar7);
          iVar9 = (int)(short)((ushort)iVar9 | uVar3);
        }
        uVar8 = 1;
        if ((pcVar5 != (char *)0x0) && (*pcVar5 != '\0')) {
          uVar8 = (*(code *)PTR_atoi_0043096c)(pcVar5);
        }
        bVar2 = true;
        if ((pcVar6 != (char *)0x0) && (*pcVar6 != '\0')) {
          iVar10 = (*(code *)PTR_strcmp_004309b4)(pcVar6,&DAT_0041e520);
          bVar2 = iVar10 != 0;
        }
        iVar9 = umAddGroup(pcVar4,iVar9,uVar8,0,bVar2);
        if (iVar9 != 0) {
          websWrite(param_1,"Unable to add group, \"%s\", code: %d ",pcVar4,iVar9);
          goto LAB_004105c4;
        }
        pcVar5 = "Group, \"%s\" was successfully added.";
      }
      else {
        pcVar5 = "ERROR: Group, \"%s\" already exists.";
      }
      websWrite(param_1,pcVar5,pcVar4);
      goto LAB_004105c4;
    }
    pcVar4 = "No Group Name was entered.";
  }
  else {
    pcVar4 = "Add Group Cancelled.";
  }
  websWrite(param_1,pcVar4);
LAB_004105c4:
  FUN_0040f928(param_1);
  websFooter(param_1);
  websDone(param_1,200);
  return;
}

