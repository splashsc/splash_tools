
undefined4 websFormHandler(undefined4 param_1)

{
  int iVar1;
  undefined *puVar2;
  int iVar3;
  undefined4 in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined uStack272;
  undefined auStack271 [259];
  
  puVar2 = PTR_strncpy_00430a04;
  *(int *)(PTR_websStats_00430694 + 0x24) = *(int *)(PTR_websStats_00430694 + 0x24) + 1;
  (*(code *)puVar2)(&uStack272,in_stack_00000014,0xfe);
  iVar1 = (*(code *)PTR_strchr_00430950)(auStack271,0x2f);
  iVar3 = iVar1 + 1;
  if (iVar1 == 0) {
    websError(param_1,200,"Missing form name");
  }
  else {
    puVar2 = (undefined *)(*(code *)PTR_strchr_00430950)(iVar3,0x2f);
    if (puVar2 != (undefined *)0x0) {
      *puVar2 = 0;
    }
    iVar1 = symLookup(DAT_00430080,iVar3);
    if (iVar1 == 0) {
      websError(param_1,0x194,"Form %s is not defined",iVar3);
    }
    else if (*(code **)(iVar1 + 0x12) != (code *)0x0) {
      (**(code **)(iVar1 + 0x12))(param_1,iVar3,in_stack_00000018);
    }
  }
  return 1;
}

