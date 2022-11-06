
void FUN_00408214(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_1[2];
  iVar3 = iVar2 << 2;
  while( true ) {
    iVar2 = iVar2 + -1;
    iVar3 = iVar3 + -4;
    if (iVar2 < 0) break;
    bfree(*(undefined4 *)(param_1[1] + iVar3));
    iVar1 = hFree(param_1 + 1,iVar2);
    param_1[2] = iVar1;
  }
  if (*param_1 != 0) {
    bfree();
    *param_1 = 0;
  }
  return;
}

