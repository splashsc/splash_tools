
undefined4 websGetCgiCommName(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(code *)PTR_tempnam_00430960)(0,&DAT_0041d968);
  uVar2 = bstrdup(uVar1);
  (*(code *)PTR_free_00430934)(uVar1);
  return uVar2;
}

