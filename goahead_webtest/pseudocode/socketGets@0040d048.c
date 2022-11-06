
int socketGets(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  char local_28 [8];
  
  puVar5 = &_mips_gp0_value;
  *param_2 = 0;
  iVar1 = socketPtr();
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar4 = iVar1 + 0x78;
    while (iVar2 = socketRead(param_1,local_28,1,param_4,puVar5), -1 < iVar2) {
      if (iVar2 == 0) {
        iVar2 = ringqLen(iVar4);
        if (iVar2 < 1) {
          return -1;
        }
        if ((*(uint *)(iVar1 + 0xac) & 1) == 0) {
          return -1;
        }
        local_28[0] = '\n';
      }
      iVar2 = ringqLen(iVar4);
      if (0x800 < iVar2) {
        local_28[0] = '\n';
      }
      if (local_28[0] == '\n') {
        iVar2 = ringqLen(iVar4);
        if (iVar2 < 1) {
          *param_2 = 0;
        }
        else {
          uVar3 = ballocAscToUni(*(undefined4 *)(iVar1 + 0x7c),iVar2);
          *param_2 = uVar3;
        }
        ringqFlush(iVar4);
        return iVar2;
      }
      if (local_28[0] != '\r') {
        ringqPutc(iVar4);
      }
    }
  }
  return iVar2;
}

