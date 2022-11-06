
undefined4 FUN_00419bac(char *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar1 = 0;
  if ((param_1 != (char *)0x0) && (*param_1 != '\0')) {
    iVar2 = (*(code *)PTR_strlen_0043095c)();
    uVar3 = ballocUniToAsc(param_1,iVar2 + 1);
    uVar4 = FUN_00419ac0(uVar3,iVar2);
    uVar1 = (*(code *)PTR_strlen_0043095c)(uVar4);
    uVar1 = ballocAscToUni(uVar4,uVar1);
    bfree(uVar3);
    bfree(uVar4);
  }
  return uVar1;
}

