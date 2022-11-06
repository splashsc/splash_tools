
undefined4 FUN_004058d8(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = 0;
  while( true ) {
    if (param_3 <= iVar4) {
      return 0;
    }
    uVar3 = *param_4;
    uVar1 = (*(code *)PTR_strlen_0043095c)(uVar3);
    iVar2 = websWriteBlock(param_2,uVar3,uVar1);
    iVar4 = iVar4 + 1;
    if (iVar2 < 0) break;
    if ((iVar4 < param_3) && (iVar2 = websWriteBlock(param_2,&DAT_0041d840,2), iVar2 < 0)) {
      return 0xffffffff;
    }
    param_4 = param_4 + 1;
  }
  return 0xffffffff;
}

