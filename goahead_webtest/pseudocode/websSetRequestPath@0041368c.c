
void websSetRequestPath(int param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  
  puVar3 = &_mips_gp0_value;
  if (param_2 != 0) {
    iVar2 = *(int *)(param_1 + 0xb0);
    uVar1 = bstrdup(param_2);
    *(undefined4 *)(param_1 + 0xb0) = uVar1;
    if (iVar2 != 0) {
      bfree(iVar2);
    }
  }
  if (param_3 != 0) {
    iVar2 = *(int *)(param_1 + 0xb4);
    uVar1 = bstrdup(param_3);
    *(undefined4 *)(param_1 + 0xb4) = uVar1;
    FUN_00411dc4(param_1,"PATH_INFO",uVar1,param_4,puVar3);
    if (iVar2 != 0) {
      bfree(iVar2);
      return;
    }
  }
  return;
}

