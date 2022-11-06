
undefined4 FUN_00404c64(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_a0;
  char local_9c [132];
  undefined4 local_18;
  
  local_18 = param_4;
  (*(code *)PTR_memset_004309cc)(local_9c,0,0x80);
  iVar1 = ejArgs(param_3,local_18,"%s",&local_a0);
  if (iVar1 < 1) {
    websError(param_2,400,"Insufficient args\n");
    uVar2 = 0;
  }
  else {
    uVar2 = 1;
    (*(code *)PTR_dxmlGetStr_004309b8)(local_9c,local_a0);
    if (local_9c[0] != '\0') {
      FUN_00403860(local_9c);
      websWrite(param_2,"%s",local_9c);
    }
  }
  return uVar2;
}

