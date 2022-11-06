
void valueFree(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if (((*(char *)(param_1 + 0xc) != '\0') && (*(char *)(param_1 + 0xd) != '\0')) &&
     (*(int *)(param_1 + 8) == 10)) {
    uVar1 = param_1 + 3 & 3;
    uVar2 = param_1 & 3;
    if (((*(int *)((param_1 + 3) - uVar1) << (3 - uVar1) * 8 |
         param_1 & 0xffffffffU >> (uVar1 + 1) * 8) & -1 << (4 - uVar2) * 8 |
        *(uint *)(param_1 - uVar2) >> uVar2 * 8) != 0) {
      bfree();
    }
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined *)(param_1 + 0xc) = 0;
  *(undefined *)(param_1 + 0xd) = 0;
  return;
}

