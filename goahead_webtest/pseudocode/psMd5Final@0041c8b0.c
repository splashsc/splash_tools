
undefined4 psMd5Final(int *param_1,undefined *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  
  uVar2 = 0xffffffff;
  if (param_2 != (undefined *)0x0) {
    uVar3 = param_1[6];
    uVar7 = uVar3 * 8 + param_1[1];
    if (uVar7 < (uint)param_1[1]) {
      *param_1 = *param_1 + 1;
    }
    param_1[1] = uVar7;
    *param_1 = *param_1 + (uVar3 >> 0x1d);
    param_1[6] = uVar3 + 1;
    *(undefined *)((int)param_1 + uVar3 + 0x1c) = 0x80;
    if (0x38 < uVar3 + 1) {
      while( true ) {
        uVar3 = param_1[6];
        if (0x3f < uVar3) break;
        *(undefined *)((int)param_1 + uVar3 + 0x1c) = 0;
        param_1[6] = uVar3 + 1;
      }
      FUN_0041ba70(param_1);
      param_1[6] = 0;
    }
    while( true ) {
      uVar3 = param_1[6];
      if (0x37 < uVar3) break;
      *(undefined *)((int)param_1 + uVar3 + 0x1c) = 0;
      param_1[6] = uVar3 + 1;
    }
    iVar4 = param_1[1];
    *(char *)((int)param_1 + 0x57) = (char)((uint)iVar4 >> 0x18);
    *(char *)((int)param_1 + 0x56) = (char)((uint)iVar4 >> 0x10);
    *(char *)(param_1 + 0x15) = (char)iVar4;
    iVar5 = *param_1;
    *(char *)((int)param_1 + 0x55) = (char)((uint)iVar4 >> 8);
    *(char *)((int)param_1 + 0x5b) = (char)((uint)iVar5 >> 0x18);
    *(char *)((int)param_1 + 0x5a) = (char)((uint)iVar5 >> 0x10);
    *(char *)((int)param_1 + 0x59) = (char)((uint)iVar5 >> 8);
    *(char *)(param_1 + 0x16) = (char)iVar5;
    FUN_0041ba70(param_1);
    iVar4 = 4;
    piVar6 = param_1;
    do {
      iVar4 = iVar4 + -1;
      param_2[3] = *(undefined *)((int)piVar6 + 0xb);
      param_2[2] = (char)*(undefined2 *)((int)piVar6 + 10);
      param_2[1] = (char)((uint)piVar6[2] >> 8);
      piVar1 = piVar6 + 2;
      piVar6 = piVar6 + 1;
      *param_2 = (char)*piVar1;
      param_2 = param_2 + 4;
    } while (iVar4 != 0);
    iVar4 = 0x5d;
    while (iVar4 = iVar4 + -1, iVar4 != 0) {
      *(undefined *)param_1 = 0;
      param_1 = (int *)((int)param_1 + 1);
    }
    uVar2 = 0x10;
  }
  return uVar2;
}

