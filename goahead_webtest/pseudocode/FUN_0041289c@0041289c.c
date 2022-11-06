
undefined4 FUN_0041289c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_30;
  undefined auStack44 [4];
  undefined4 local_28;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_4;
  local_14 = param_2;
  iVar2 = FUN_00412798();
  puVar1 = PTR_strlen_0043095c;
  if (iVar2 < 0) {
    return 0xffffffff;
  }
  iVar5 = *(int *)(*(int *)PTR_webs_00430854 + iVar2 * 4);
  *(undefined4 *)(iVar5 + 0xf4) = local_18;
  iVar2 = (*(code *)puVar1)(local_14);
  iVar6 = iVar5 + 0x30;
  uVar4 = 0x20;
  if (iVar2 + 1U < 0x21) {
    uVar4 = iVar2 + 1U;
  }
  ascToUni(iVar6,local_14,uVar4);
  local_30 = 0x10;
  iVar2 = (*(code *)PTR_getsockname_00430930)
                    (*(undefined4 *)(*(int *)(*(int *)PTR_socketList_0043076c + param_1 * 4) + 0xb0)
                     ,auStack44,&local_30);
  if (-1 < iVar2) {
    local_14 = (*(code *)PTR_inet_ntoa_004309c4)(local_28);
    uVar3 = (*(code *)PTR_strlen_0043095c)(local_14);
    (*(code *)PTR_strncpy_00430a04)(iVar5 + 0x50,local_14,uVar3);
    iVar2 = (*(code *)PTR_strcmp_004309b4)(iVar6,&DAT_0041eb2c);
    if (((iVar2 == 0) ||
        (iVar2 = (*(code *)PTR_strcmp_004309b4)(iVar6,PTR_websIpaddr_00430848), iVar2 == 0)) ||
       (iVar2 = (*(code *)PTR_strcmp_004309b4)(iVar6,PTR_websHost_00430844), iVar2 == 0)) {
      *(uint *)(iVar5 + 0x100) = *(uint *)(iVar5 + 0x100) | 0x40;
    }
    socketCreateHandler(param_1,2,FUN_00415820,iVar5);
    uVar3 = emfSchedCallback(60000,FUN_00413240,iVar5);
    *(undefined4 *)(iVar5 + 0x2c) = uVar3;
    trace(8,"webs: accept request\n");
    return 0;
  }
  return 0xffffffff;
}

