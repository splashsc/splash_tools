
int ejSetGlobalFunctionDirect(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  
  valueInteger(&local_20,param_3);
  iVar1 = symEnter(param_1,param_2,local_20,local_1c,local_18,local_14,0);
  return (iVar1 != 0) - 1;
}

