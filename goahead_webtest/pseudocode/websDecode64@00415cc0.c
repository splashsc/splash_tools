
undefined4 websDecode64(undefined *param_1,char *param_2,int param_3)

{
  uint uVar1;
  undefined *puVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  *param_1 = 0;
  puVar2 = param_1;
  pcVar3 = param_2;
  do {
    if ((*pcVar3 == '\0') || (iVar4 = 0, *pcVar3 == '=')) {
      return 0;
    }
    uVar5 = 0x12;
    uVar8 = 0;
    do {
      uVar7 = (uint)*pcVar3;
      if ((uVar7 == 0) || (uVar7 == 0x3d)) goto LAB_00415d90;
      if ((char)(&DAT_0041f190)[uVar7 & 0xff] == -1) {
        error("../mime64.c",0x48,2,"Bad string: %s at %c index %d",param_2,0xffffffff,iVar4);
        return 0xffffffff;
      }
      uVar1 = uVar5 & 0x1f;
      uVar5 = uVar5 - 6;
      uVar8 = uVar8 | (int)(char)(&DAT_0041f190)[uVar7 & 0xff] << uVar1;
      iVar4 = iVar4 + 1;
      pcVar3 = pcVar3 + 1;
    } while (uVar5 != 0xfffffffa);
    iVar4 = 4;
LAB_00415d90:
    if (param_1 + param_3 <= puVar2 + iVar4 + -1) {
      (*(code *)PTR_strcpy_00430ad8)(param_1,"String too big");
      return 0xffffffff;
    }
    uVar5 = 0x10;
    for (iVar6 = 0; iVar6 < iVar4 + -1; iVar6 = iVar6 + 1) {
      *puVar2 = (char)(uVar8 >> (uVar5 & 0x1f));
      puVar2 = puVar2 + 1;
      uVar5 = uVar5 - 8;
    }
    *puVar2 = 0;
  } while( true );
}

