
int FUN_0041a750(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  while( true ) {
    if (DAT_00430c64 <= iVar3) {
      return -1;
    }
    puVar1 = *(undefined4 **)(DAT_00430c60 + iVar3 * 4);
    if ((puVar1 != (undefined4 *)0x0) &&
       (iVar2 = (*(code *)PTR_strcmp_004309b4)(param_2,*puVar1), iVar2 == 0)) break;
    iVar3 = iVar3 + 1;
  }
  return iVar3;
}

