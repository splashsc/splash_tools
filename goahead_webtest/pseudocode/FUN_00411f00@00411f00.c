
bool FUN_00411f00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = websGetVar(param_1,param_2," __UNDEF__ ");
  iVar2 = (*(code *)PTR_strcmp_004309b4)(param_3,uVar1);
  return iVar2 == 0;
}

