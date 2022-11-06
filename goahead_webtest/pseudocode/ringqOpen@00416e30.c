
undefined4 ringqOpen(undefined4 *param_1,int param_2,undefined4 param_3)

{
  bool bVar1;
  undefined *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  param_2 = param_2 >> 4;
  iVar4 = 0;
  while (bVar1 = param_2 != 0, param_2 = param_2 >> 1, bVar1) {
    iVar4 = iVar4 + 1;
  }
  iVar4 = 1 << (iVar4 + 4U & 0x1f);
  puVar2 = (undefined *)balloc(iVar4);
  *param_1 = puVar2;
  uVar3 = 0xffffffff;
  if (puVar2 != (undefined *)0x0) {
    param_1[4] = iVar4;
    param_1[6] = iVar4;
    param_1[5] = param_3;
    param_1[3] = puVar2 + iVar4;
    param_1[1] = puVar2;
    param_1[2] = puVar2;
    uVar3 = 0;
    *puVar2 = 0;
  }
  return uVar3;
}

