
void ringqPutBlkAdj(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 8) + param_2;
  *(uint *)(param_1 + 8) = uVar1;
  if (*(uint *)(param_1 + 0xc) <= uVar1) {
    *(uint *)(param_1 + 8) = uVar1 - *(int *)(param_1 + 0x10);
  }
  if (*(uint *)(param_1 + 0xc) <= *(uint *)(param_1 + 8)) {
    error("../ringq.c",0x1dc,2,"Bad end pointer",&_mips_gp0_value);
    ringqFlush(param_1);
    return;
  }
  return;
}

