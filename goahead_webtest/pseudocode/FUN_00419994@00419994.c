
bool FUN_00419994(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  bool bVar5;
  
  iVar1 = umUserExists();
  bVar5 = false;
  if ((iVar1 != 0) && (iVar1 = umGetUserEnabled(param_1), iVar1 != 0)) {
    iVar1 = umGetUserGroup(param_1);
    iVar2 = FUN_00418d8c(iVar1);
    if ((iVar2 != 0) &&
       ((iVar2 = FUN_00418eb0(iVar1), iVar2 != 0 && (iVar2 = FUN_00418c64(iVar1), iVar2 != 0)))) {
      iVar2 = FUN_004197ac(param_2);
      bVar5 = true;
      if (iVar2 != 0) {
        iVar3 = FUN_0041944c(iVar2);
        pcVar4 = (char *)FUN_00419690(iVar2);
        bVar5 = false;
        bfree(iVar2);
        if ((((iVar3 != 0) && (bVar5 = true, pcVar4 != (char *)0x0)) && (*pcVar4 != '\0')) &&
           (iVar1 != 0)) {
          iVar1 = (*(code *)PTR_strcmp_004309b4)(pcVar4,iVar1);
          bVar5 = iVar1 == 0;
        }
      }
    }
  }
  return bVar5;
}

