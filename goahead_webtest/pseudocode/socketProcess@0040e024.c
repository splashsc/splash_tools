
void socketProcess(int param_1)

{
  bool bVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  int iVar12;
  int iVar13;
  undefined4 local_40;
  undefined auStack60 [2];
  ushort local_3a;
  undefined4 local_38;
  
  puVar4 = PTR_socketHighestFd_004307a4;
  puVar3 = PTR_socketList_0043076c;
  puVar2 = PTR_socketMax_00430768;
  bVar1 = -1 < param_1;
  if (!bVar1) {
    param_1 = 0;
  }
  iVar13 = param_1 << 2;
  do {
    if (*(int *)puVar2 <= param_1) {
      return;
    }
    iVar12 = *(int *)(*(int *)puVar3 + iVar13);
    if ((iVar12 != 0) && (iVar5 = socketReady(param_1), iVar5 != 0)) {
      iVar5 = *(int *)(iVar12 + 0xa4);
      if ((*(uint *)(iVar12 + 0xbc) & 2) == 0) {
        if (((*(uint *)(iVar12 + 0xa0) & 2) != 0) && (iVar6 = socketInputBuffered(iVar5), 0 < iVar6)
           ) {
          *(uint *)(iVar12 + 0xbc) = *(uint *)(iVar12 + 0xbc) | 2;
        }
LAB_0040e230:
        if (((*(uint *)(iVar12 + 0xbc) & 4) != 0) && ((*(uint *)(iVar12 + 0xac) & 0x10) != 0)) {
          iVar6 = ringqLen(iVar12 + 0x5c);
          if (iVar6 < 1) {
            *(uint *)(iVar12 + 0xac) = *(uint *)(iVar12 + 0xac) & 0xffffffef;
          }
          else {
            socketFlush(*(undefined4 *)(iVar12 + 0xa4));
          }
        }
        if ((*(code **)(iVar12 + 0x98) != (code *)0x0) &&
           (uVar8 = *(uint *)(iVar12 + 0xbc) & *(uint *)(iVar12 + 0xa0), uVar8 != 0)) {
          (**(code **)(iVar12 + 0x98))(iVar5,uVar8,*(undefined4 *)(iVar12 + 0x9c));
          if ((*(int *)puVar3 != 0) &&
             ((iVar5 < *(int *)puVar2 && (*(int *)(*(int *)puVar3 + iVar5 * 4) == iVar12))))
          goto LAB_0040e308;
        }
      }
      else {
        if ((*(uint *)(iVar12 + 0xac) & 0x100) == 0) goto LAB_0040e230;
        local_40 = 0x10;
        iVar5 = (*(code *)PTR_accept_00430a60)(*(undefined4 *)(iVar12 + 0xb0),auStack60,&local_40);
        if (-1 < iVar5) {
          (*(code *)PTR_fcntl_00430948)(iVar5,2,1);
          iVar7 = *(int *)puVar4;
          iVar6 = iVar5;
          if (iVar5 < iVar7) {
            iVar6 = iVar7;
          }
          uVar9 = *(undefined4 *)(iVar12 + 0xa8);
          uVar10 = *(undefined4 *)(iVar12 + 0x94);
          uVar11 = *(undefined4 *)(iVar12 + 0xac);
          *(int *)puVar4 = iVar6;
          iVar6 = socketAlloc(iVar12,uVar9,uVar10,uVar11);
          iVar7 = *(int *)(*(int *)puVar3 + iVar6 * 4);
          uVar8 = *(uint *)(iVar7 + 0xac);
          *(int *)(iVar7 + 0xb0) = iVar5;
          *(uint *)(iVar7 + 0xac) = uVar8 & 0xfffffeff;
          socketSetBlock(iVar6,(uVar8 & 0x80) != 0);
          if (*(int *)(iVar12 + 0x94) != 0) {
            uVar9 = (*(code *)PTR_inet_ntoa_004309c4)(local_38);
            iVar5 = (**(code **)(iVar12 + 0x94))
                              (iVar6,uVar9,(uint)(local_3a >> 8) | (local_3a & 0xff) << 8,
                               *(undefined4 *)(iVar12 + 0xa4));
            if (iVar5 < 0) {
              socketFree(iVar6);
              *(undefined4 *)(iVar12 + 0xbc) = 0;
              goto LAB_0040e30c;
            }
          }
        }
LAB_0040e308:
        *(undefined4 *)(iVar12 + 0xbc) = 0;
      }
    }
LAB_0040e30c:
    param_1 = param_1 + 1;
    if (bVar1) {
      return;
    }
    iVar13 = iVar13 + 4;
  } while( true );
}

