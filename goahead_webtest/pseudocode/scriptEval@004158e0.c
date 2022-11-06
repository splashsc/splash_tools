
int scriptEval(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = -1;
  if (param_1 == 2) {
    iVar1 = ejEval(param_4);
    iVar1 = -(uint)(iVar1 == 0);
  }
  return iVar1;
}

