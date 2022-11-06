
int ejEval(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined *puVar8;
  
  puVar8 = &_mips_gp0_value;
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  piVar1 = (int *)FUN_004083a0();
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  FUN_004080c8(piVar1 + 5,&DAT_0041ed68);
  iVar5 = 0;
  iVar7 = *piVar1;
  ejLexOpenScript(piVar1,param_2);
  iVar6 = 0;
  do {
    iVar2 = FUN_00409df4(piVar1,8,1,param_4,puVar8);
    if (iVar2 == 0x14) {
      iVar2 = 1;
    }
    iVar3 = *(int *)(*piVar1 + 0x20);
    if (iVar6 == iVar3) {
      if (10 < iVar5) {
        ejError(piVar1,"Syntax error");
        iVar2 = -1;
LAB_0040a420:
        ejLexCloseScript(piVar1);
        if ((iVar2 == -1) && (param_3 != (undefined4 *)0x0)) {
          uVar4 = bstrdup(piVar1[6]);
          *param_3 = uVar4;
        }
        *piVar1 = iVar7;
        if ((iVar2 != 1) && (iVar2 == -1)) {
          return 0;
        }
        return piVar1[5];
      }
      iVar5 = iVar5 + 1;
      iVar3 = iVar6;
    }
    else {
      iVar5 = 0;
    }
    if ((iVar2 == 1) || (iVar6 = iVar3, iVar2 == -1)) goto LAB_0040a420;
  } while( true );
}

