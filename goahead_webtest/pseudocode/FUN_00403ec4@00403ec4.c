
undefined4 FUN_00403ec4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_a0;
  char local_9c [132];
  undefined4 local_18;
  
  local_18 = param_4;
  (*(code *)PTR_memset_004309cc)(local_9c,0,0x80);
  iVar1 = ejArgs(param_3,local_18,"%s",&local_a0);
  if (iVar1 < 1) {
    websError(param_2,400,"Insufficient args\n");
    uVar3 = 0;
  }
  else {
    (*(code *)PTR_dxmlGetStr_004309b8)(local_9c,local_a0);
    iVar1 = (*(code *)PTR_strstr_00430a14)(local_9c,&DAT_0041ee50);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_strchr_00430950)(iVar1 + 4,0x2f);
      if (iVar1 != 0) {
        (*(code *)PTR_strcpy_00430ad8)(local_9c,iVar1);
      }
    }
    uVar3 = 1;
    if (local_9c[0] != '\0') {
      FUN_00403860(local_9c);
      uVar2 = (*(code *)PTR_strChgRssKeywords_00430aa8)(local_9c);
      websWrite(param_2,"%s",uVar2);
    }
  }
  return uVar3;
}

