
void ringqPutStr(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined *puVar2;
  
  puVar2 = &_mips_gp0_value;
  uVar1 = (*(code *)PTR_strlen_0043095c)(param_2);
  ringqPutBlk(param_1,param_2,uVar1,param_4,puVar2);
  **(undefined **)(param_1 + 8) = 0;
  return;
}

