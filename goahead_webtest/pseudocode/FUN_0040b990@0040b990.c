
void FUN_0040b990(undefined4 param_1,uint param_2,uint param_3,int param_4,int param_5,int param_6,
                 int param_7,uint param_8)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined *puVar5;
  
  if (param_3 == 0) {
    trap(0x1c00);
  }
  puVar5 = &_mips_gp0_value;
  iVar3 = 1;
  uVar2 = 1;
  while ((uVar2 < 0xffffffff / param_3 && (uVar2 * param_3 <= param_2))) {
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 * param_3;
  }
  iVar4 = 0;
  if (iVar3 < param_7) {
    iVar4 = param_7 - iVar3;
  }
  param_6 = param_6 - (iVar4 + iVar3);
  if (param_5 != 0) {
    iVar3 = (*(code *)PTR_strlen_0043095c)(param_5);
    param_6 = param_6 - iVar3;
  }
  uVar1 = param_8 & 1;
  if (uVar1 == 0) {
    if ((param_8 & 0x10) == 0) {
      for (; (int)uVar1 < param_6; uVar1 = uVar1 + 1) {
        FUN_0040b770(param_1,0x20);
      }
    }
    else {
      for (; (int)uVar1 < param_6; uVar1 = uVar1 + 1) {
        FUN_0040b770(param_1,0x30);
      }
    }
  }
  if (param_5 != 0) {
    FUN_0040b85c(param_1,param_5,0xffffffff,0,0xffffffff,0,puVar5);
  }
  for (iVar3 = 0; iVar3 < iVar4; iVar3 = iVar3 + 1) {
    FUN_0040b770(param_1,0x30);
  }
  while (uVar2 != 0) {
    if (uVar2 == 0) {
      trap(0x1c00);
    }
    uVar1 = (param_2 / uVar2) % param_3;
    if (param_3 == 0) {
      trap(0x1c00);
    }
    iVar3 = 0x30;
    if ((9 < (int)uVar1) && (iVar3 = 0x57, param_4 != 0)) {
      iVar3 = 0x37;
    }
    FUN_0040b770(param_1,(int)((iVar3 + uVar1) * 0x1000000) >> 0x18);
    uVar2 = uVar2 / param_3;
    if (param_3 == 0) {
      trap(0x1c00);
    }
  }
  if ((param_8 & 1) != 0) {
    for (; (int)uVar2 < param_6; uVar2 = uVar2 + 1) {
      FUN_0040b770(param_1,0x20);
    }
  }
  return;
}

