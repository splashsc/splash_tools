
undefined4
FUN_0040af80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  int iVar1;
  undefined *puVar2;
  
  puVar2 = &_mips_gp0_value;
  iVar1 = (*(code *)PTR_strlen_0043095c)(param_2);
  websSetRequestPath(param_1,param_3,param_6 + iVar1 + 1,param_4,puVar2);
  return 0;
}

