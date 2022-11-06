
void psMd5Update(int *param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  while (param_3 != 0) {
    uVar1 = 0x40 - param_1[6];
    uVar3 = param_3;
    if (uVar1 < param_3) {
      uVar3 = uVar1;
    }
    (*(code *)PTR_memcpy_00430a90)((int)param_1 + param_1[6] + 0x1c,param_2,uVar3);
    iVar2 = param_1[6];
    param_2 = param_2 + uVar3;
    param_1[6] = uVar3 + iVar2;
    param_3 = param_3 - uVar3;
    if (uVar3 + iVar2 == 0x40) {
      FUN_0041ba70(param_1);
      uVar3 = param_1[1] + 0x200;
      if (uVar3 < (uint)param_1[1]) {
        *param_1 = *param_1 + 1;
      }
      param_1[1] = uVar3;
      param_1[6] = 0;
    }
  }
  return;
}

