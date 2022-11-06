
undefined4 FUN_0040e7cc(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = *(int **)PTR_socketList_0043076c;
  iVar1 = 0;
  while( true ) {
    if (*(int *)PTR_socketMax_00430768 <= iVar1) {
      return 0;
    }
    if ((*piVar3 != 0) && (*(int *)(*piVar3 + 0xb0) == param_1)) break;
    iVar1 = iVar1 + 1;
    piVar3 = piVar3 + 1;
  }
  uVar2 = socketInputBuffered(iVar1);
  return uVar2;
}

