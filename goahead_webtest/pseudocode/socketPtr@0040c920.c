
int socketPtr(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  if (((-1 < param_1) && (param_1 < *(int *)PTR_socketMax_00430768)) &&
     (iVar1 = *(int *)(*(int *)PTR_socketList_0043076c + param_1 * 4), iVar1 != 0)) {
    return iVar1;
  }
  puVar2 = (undefined4 *)(*(code *)PTR___errno_location_00430978)();
  *puVar2 = 9;
  return 0;
}

