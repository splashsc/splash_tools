
int socketOpenConnection(int param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 local_38;
  int local_34;
  undefined2 local_30;
  ushort local_2e;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  if (0xffff < param_2) {
    return -1;
  }
  iVar1 = socketAlloc();
  if (iVar1 < 0) {
    return -1;
  }
  iVar7 = *(int *)(*(int *)PTR_socketList_0043076c + iVar1 * 4);
  local_30 = 2;
  local_2e = (ushort)((uint)param_2 >> 8) & 0xff | (ushort)(param_2 << 8);
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  if ((param_1 != 0) && (local_2c = (*(code *)PTR_inet_addr_00430a34)(param_1), local_2c == -1)) {
    iVar2 = (*(code *)PTR_gethostbyname_004309a4)(param_1);
    if (iVar2 == 0) {
      uVar3 = basicGetAddress();
      uVar4 = (*(code *)PTR_strlen_0043095c)(uVar3);
      uVar3 = ballocUniToAsc(uVar3,uVar4);
      local_2c = (*(code *)PTR_inet_addr_00430a34)(uVar3);
      bfree(uVar3);
      if (local_2c == -1) {
        puVar5 = (undefined4 *)(*(code *)PTR___errno_location_00430978)();
        *puVar5 = 6;
        goto LAB_0040e698;
      }
    }
    else {
      (*(code *)PTR_memcpy_00430a90)
                (&local_2c,**(undefined4 **)(iVar2 + 0x10),*(undefined4 *)(iVar2 + 0xc));
    }
  }
  uVar9 = *(uint *)(iVar7 + 0xac) & 4;
  if (uVar9 != 0) {
    *(uint *)(iVar7 + 0xac) = *(uint *)(iVar7 + 0xac) | 0x20;
  }
  uVar8 = *(uint *)(iVar7 + 0xac) & 0x20;
  iVar2 = (*(code *)PTR_socket_00430a7c)(2,(uVar8 == 0) + '\x01',0);
  *(int *)(iVar7 + 0xb0) = iVar2;
  if (iVar2 < 0) {
LAB_0040e698:
    socketFree(iVar1);
    return -1;
  }
  (*(code *)PTR_fcntl_00430948)(iVar2,2,1);
  iVar6 = *(int *)(iVar7 + 0xb0);
  iVar2 = *(int *)PTR_socketHighestFd_004307a4;
  if (*(int *)PTR_socketHighestFd_004307a4 < iVar6) {
    iVar2 = iVar6;
  }
  *(int *)PTR_socketHighestFd_004307a4 = iVar2;
  if (uVar9 != 0) {
    local_38 = 1;
    iVar2 = (*(code *)PTR_setsockopt_00430a28)(iVar6,0xffff,0x20,&local_38,4);
    if (iVar2 < 0) goto LAB_0040e698;
  }
  if (param_1 == 0) {
    local_34 = 1;
    (*(code *)PTR_setsockopt_00430a28)(*(undefined4 *)(iVar7 + 0xb0),0xffff,4,&local_34,4);
    iVar2 = (*(code *)PTR_bind_00430a38)(*(undefined4 *)(iVar7 + 0xb0),&local_30,0x10);
    if (iVar2 < 0) goto LAB_0040e698;
    if (uVar8 == 0) {
      iVar2 = (*(code *)PTR_listen_004309ec)(*(undefined4 *)(iVar7 + 0xb0),0x80);
      if (iVar2 < 0) goto LAB_0040e698;
      *(uint *)(iVar7 + 0xac) = *(uint *)(iVar7 + 0xac) | 0x100;
    }
    *(uint *)(iVar7 + 0xa0) = *(uint *)(iVar7 + 0xa0) | 2;
  }
  else if (uVar8 == 0) {
    if ((*(uint *)(iVar7 + 0xac) & 0x80) == 0) {
      socketSetBlock(iVar1,1);
    }
    local_34 = (*(code *)PTR_connect_00430abc)(*(undefined4 *)(iVar7 + 0xb0),&local_30,0x10);
    if (local_34 < 0) {
      local_34 = -1;
      goto LAB_0040e698;
    }
  }
  socketSetBlock(iVar1,(param_4 & 0x80) != 0);
  return iVar1;
}

