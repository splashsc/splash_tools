
bool FUN_0040e720(void)

{
  undefined *puVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = PTR_socketList_0043076c;
  puVar1 = PTR_socketMax_00430768;
  iVar4 = 0;
  while( true ) {
    if (iVar4 >= *(int *)puVar1) {
      return iVar4 < *(int *)puVar1;
    }
    iVar3 = *(int *)(*(int *)puVar2 + iVar4 * 4);
    if (((iVar3 != 0) && ((*(uint *)(iVar3 + 0xa0) & 2) != 0)) &&
       (iVar3 = socketInputBuffered(iVar4), 0 < iVar3)) break;
    iVar4 = iVar4 + 1;
  }
  return true;
}

