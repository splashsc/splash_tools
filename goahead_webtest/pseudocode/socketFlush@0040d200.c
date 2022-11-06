
undefined4 socketFlush(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 local_38;
  ushort local_36;
  undefined4 local_34;
  undefined4 local_28;
  
  iVar1 = socketPtr();
  uVar5 = 0xffffffff;
  if (iVar1 != 0) {
    iVar6 = iVar1 + 0x5c;
    if ((*(uint *)(iVar1 + 0xac) & 0x80) == 0) {
      *(uint *)(iVar1 + 0xac) = *(uint *)(iVar1 + 0xac) | 0x10;
    }
LAB_0040d3d8:
    do {
      iVar3 = ringqLen(iVar6);
      if (iVar3 < 1) {
        iVar3 = ringqLen();
        if (iVar3 == 0) {
          ringqFlush(iVar6);
        }
        if (-1 < *(int *)(iVar1 + 0xc4)) {
          socketRegisterInterest(iVar1);
          *(undefined4 *)(iVar1 + 0xc4) = 0xffffffff;
        }
        *(uint *)(iVar1 + 0xac) = *(uint *)(iVar1 + 0xac) & 0xffffffef;
        return 0;
      }
      iVar3 = ringqGetBlkMax(iVar6);
      uVar5 = *(undefined4 *)(iVar1 + 0x60);
      if ((*(uint *)(iVar1 + 0xac) & 4) == 0) {
        if ((*(uint *)(iVar1 + 0xac) & 0x20) != 0) {
          local_38 = 2;
          local_28 = uVar5;
          local_34 = (*(code *)PTR_inet_addr_00430a34)(iVar1);
          local_36 = (ushort)*(byte *)(iVar1 + 0xa9) | (ushort)(*(int *)(iVar1 + 0xa8) << 8);
          uVar4 = *(undefined4 *)(iVar1 + 0xb0);
          uVar5 = local_28;
          goto LAB_0040d314;
        }
        iVar2 = (*(code *)PTR_send_00430a64)(*(undefined4 *)(iVar1 + 0xb0),uVar5,iVar3,0);
      }
      else {
        uVar4 = *(undefined4 *)(iVar1 + 0xb0);
        local_36 = (ushort)*(byte *)(iVar1 + 0xa9) | (ushort)(*(int *)(iVar1 + 0xa8) << 8);
        local_38 = 2;
        local_34 = 0xffffffff;
LAB_0040d314:
        iVar2 = (*(code *)PTR_sendto_004309fc)(uVar4,uVar5,iVar3,0,&local_38,0x10);
      }
      if (iVar2 < 0) {
        iVar3 = socketGetError();
      }
      else {
        if ((iVar2 != 0) || (iVar3 == 0)) {
          ringqGetBlkAdj(iVar6,iVar2);
          goto LAB_0040d3d8;
        }
        iVar3 = 0xb;
      }
    } while (iVar3 == 4);
    uVar5 = 0xffffffff;
    if ((iVar3 == 0xb) && (uVar5 = 0, *(int *)(iVar1 + 0xc4) < 0)) {
      *(uint *)(iVar1 + 0xc4) = *(uint *)(iVar1 + 0xa0);
      socketRegisterInterest(iVar1,*(uint *)(iVar1 + 0xa0) | 4);
    }
  }
  return uVar5;
}

