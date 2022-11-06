
/* WARNING: Removing unreachable block (ram,0x0040e940) */

uint FUN_0040e920(int param_1,char *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  uVar2 = 0;
  for (; *param_2 != 0; param_2 = param_2 + 1) {
    uVar1 = uVar3 & 0x1f;
    uVar3 = (int)(uVar3 + 7) % 0x18;
    uVar2 = uVar2 + ((int)*param_2 << uVar1);
  }
  if (*(uint *)(param_1 + 4) == 0) {
    trap(0x1c00);
  }
  return uVar2 % *(uint *)(param_1 + 4);
}

