
longlong websValid(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = *(int **)PTR_webs_00430854;
  while( true ) {
    if (*(int *)PTR_websMax_00430858 <= iVar1) {
      return ZEXT48(piVar2) << 0x20;
    }
    if (param_1 == *piVar2) break;
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  }
  return CONCAT44(piVar2 + 1,1);
}

