
void FUN_00409028(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined2 local_1c;
  int local_18;
  
  local_18 = param_3;
  iVar1 = FUN_004083a0();
  if (iVar1 != 0) {
    valueString(&local_28,local_18,local_18 != 0);
    symEnter(**(int **)(iVar1 + 8) + -1,param_2,local_28,local_24,local_20,local_1c,0);
  }
  return;
}

