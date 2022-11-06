
undefined4 websFormDefine(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined2 local_14;
  
  uVar1 = DAT_00430080;
  uVar2 = 0xffffffff;
  if (param_2 != 0) {
    valueInteger(&local_20);
    symEnter(uVar1,param_1,local_20,local_1c,local_18,local_14,0);
    uVar2 = 0;
  }
  return uVar2;
}

