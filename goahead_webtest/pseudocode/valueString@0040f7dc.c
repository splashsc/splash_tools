
undefined4 valueString(undefined4 param_1,undefined4 param_2,uint param_3)

{
  undefined4 uVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined2 local_c;
  
  local_18 = 0;
  local_14 = 0;
  local_c = 1;
  local_10 = 10;
  uVar1 = param_2;
  if ((param_3 & 1) != 0) {
    local_c = 0x101;
    uVar1 = bstrdup(param_2);
  }
  local_18 = uVar1;
  (*(code *)PTR_memcpy_00430a90)(param_1,&local_18,0xe);
  return param_1;
}

