
void ringqGetBlkAdj(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(int *)(param_1 + 4) + param_2;
  *(uint *)(param_1 + 4) = uVar1;
  if (*(uint *)(param_1 + 0xc) <= uVar1) {
    *(uint *)(param_1 + 4) = uVar1 - *(int *)(param_1 + 0x10);
  }
  if (*(uint *)(param_1 + 0xc) <= *(uint *)(param_1 + 4)) {
    error("../ringq.c",500,2,"Bad serv pointer",&_mips_gp0_value);
    ringqFlush(param_1);
    return;
  }
  return;
}

