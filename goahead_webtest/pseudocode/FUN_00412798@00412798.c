
int FUN_00412798(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = hAllocEntry(PTR_webs_00430854,PTR_websMax_00430858,0x148);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    iVar3 = *(int *)(*(int *)PTR_webs_00430854 + iVar1 * 4);
    *(undefined4 *)(iVar3 + 0xfc) = 1;
    *(int *)(iVar3 + 0x10c) = iVar1;
    *(undefined4 *)(iVar3 + 0xf0) = param_1;
    *(undefined4 *)(iVar3 + 0x118) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x2c) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0xb0) = 0;
    *(undefined4 *)(iVar3 + 0xcc) = 0;
    *(undefined4 *)(iVar3 + 0xe4) = 0;
    *(undefined4 *)(iVar3 + 0xe8) = 0;
    *(undefined4 *)(iVar3 + 0xd0) = 0;
    *(undefined4 *)(iVar3 + 0xd4) = 0;
    *(undefined4 *)(iVar3 + 0x128) = 0;
    *(undefined4 *)(iVar3 + 300) = 0;
    *(undefined4 *)(iVar3 + 0x130) = 0;
    *(undefined4 *)(iVar3 + 0x134) = 0;
    *(undefined4 *)(iVar3 + 0x138) = 0;
    *(undefined4 *)(iVar3 + 0x13c) = 0;
    *(undefined4 *)(iVar3 + 0x140) = 0;
    *(undefined4 *)(iVar3 + 0x144) = 0;
    *(undefined4 *)(iVar3 + 0xe0) = 0;
    ringqOpen(iVar3,0x200,0x1400);
    uVar2 = symOpen(0x40);
    *(undefined4 *)(iVar3 + 0x20) = uVar2;
  }
  return iVar1;
}

