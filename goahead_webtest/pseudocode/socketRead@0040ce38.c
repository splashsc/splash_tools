
int socketRead(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_30 [3];
  
  iVar1 = socketPtr();
  iVar5 = -1;
  if ((iVar1 != 0) && (iVar5 = 0, (*(uint *)(iVar1 + 0xac) & 1) == 0)) {
    iVar6 = iVar1 + 0x40;
    while (0 < param_3) {
      iVar2 = ringqLen(iVar6);
      iVar3 = param_3;
      if ((iVar2 < param_3) && (iVar3 = ringqLen(iVar6), iVar3 < 1)) {
        if (((*(uint *)(iVar1 + 0xac) & 0x80) != 0) && (iVar5 != 0)) {
          return iVar5;
        }
        ringqFlush(iVar6);
        uVar4 = ringqPutBlkMax(iVar6);
        iVar3 = socketGetInput(param_1,*(undefined4 *)(iVar1 + 0x48),uVar4,local_30);
        if (-1 < iVar3) {
          if (iVar3 == 0) {
            if (iVar5 != 0) {
              return iVar5;
            }
            *(uint *)(iVar1 + 0xac) = *(uint *)(iVar1 + 0xac) | 1;
            return 0;
          }
          ringqPutBlkAdj(iVar6,iVar3);
          if (param_3 < iVar3) {
            iVar3 = param_3;
          }
          goto LAB_0040cfd0;
        }
        if (local_30[0] != 0xb) {
          return -1;
        }
        if ((*(uint *)(iVar1 + 0xac) & 0x80) == 0) {
          return iVar5;
        }
        if (iVar5 != 0) {
          return iVar5;
        }
      }
      else {
LAB_0040cfd0:
        (*(code *)PTR_memcpy_00430a90)(param_2 + iVar5,*(undefined4 *)(iVar1 + 0x44),iVar3);
        param_3 = param_3 - iVar3;
        iVar5 = iVar5 + iVar3;
        ringqGetBlkAdj(iVar6,iVar3);
      }
    }
  }
  return iVar5;
}

