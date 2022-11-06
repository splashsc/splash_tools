
void FUN_00403860(int param_1)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  char local_120 [256];
  
  (*(code *)PTR_memset_004309cc)(local_120,0,0xff);
  uVar4 = 0;
  iVar3 = 0;
  do {
    uVar2 = (*(code *)PTR_strlen_0043095c)(param_1);
    if (uVar2 <= uVar4) {
      local_120[iVar3] = '\0';
      (*(code *)PTR_strcpy_00430ad8)(param_1,local_120);
      return;
    }
    cVar1 = *(char *)(param_1 + uVar4);
    if (cVar1 == '\"') {
      local_120[iVar3] = '\\';
      local_120[iVar3 + 1] = '\"';
LAB_004038fc:
      iVar3 = iVar3 + 2;
    }
    else {
      if (cVar1 == '\\') {
        local_120[iVar3] = '\\';
        local_120[iVar3 + 1] = '\\';
        goto LAB_004038fc;
      }
      local_120[iVar3] = cVar1;
      iVar3 = iVar3 + 1;
    }
    uVar4 = uVar4 + 1;
  } while( true );
}

