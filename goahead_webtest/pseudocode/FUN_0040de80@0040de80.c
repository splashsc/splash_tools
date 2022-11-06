
undefined4 FUN_0040de80(int param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)(param_1 + 0xa0);
  *(uint *)(param_1 + 0xa0) = param_2 | uVar5;
  do {
    iVar1 = socketSelect(*(undefined4 *)(param_1 + 0xa4),1000);
    uVar3 = *(uint *)(param_1 + 0xbc);
    if (iVar1 == 0) break;
  } while (((param_2 | 8) & uVar3) == 0);
  *(uint *)(param_1 + 0xa0) = uVar5;
  uVar4 = 0xffffffff;
  if ((((uVar3 & 8) == 0) && (uVar4 = 1, (param_2 & uVar3) == 0)) &&
     (uVar4 = 0, param_3 != (undefined4 *)0x0)) {
    puVar2 = (undefined4 *)(*(code *)PTR___errno_location_00430978)();
    *puVar2 = 0xb;
    *param_3 = 0xb;
  }
  return uVar4;
}

