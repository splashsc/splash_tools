
int socketAlloc(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = hAllocEntry(PTR_socketList_0043076c,PTR_socketMax_00430768,0xcc);
  if (iVar1 < 0) {
    iVar1 = -1;
  }
  else {
    iVar2 = *(int *)(*(int *)PTR_socketList_0043076c + iVar1 * 4);
    *(int *)(iVar2 + 0xa4) = iVar1;
    *(undefined4 *)(iVar2 + 0x94) = param_3;
    *(undefined4 *)(iVar2 + 0xa8) = param_2;
    *(undefined4 *)(iVar2 + 0xb4) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0xc4) = 0xffffffff;
    if (param_1 != 0) {
      (*(code *)PTR_strncpy_00430a04)(iVar2,param_1,0x40);
    }
    *(uint *)(iVar2 + 0xac) = param_4 & 0x9a4;
    if ((param_4 & 0x800) == 0) {
      ringqOpen(iVar2 + 0x40,0x400,0x400);
      ringqOpen(iVar2 + 0x5c,0x401,0x401);
    }
    else {
      (*(code *)PTR_memset_004309cc)(iVar2 + 0x40,0,0x1c);
      (*(code *)PTR_memset_004309cc)(iVar2 + 0x5c,0,0x1c);
    }
    ringqOpen(iVar2 + 0x78,0x400,0xffffffff);
  }
  return iVar1;
}

