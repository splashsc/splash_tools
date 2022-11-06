
undefined4 FUN_00419f3c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = 0;
  fmtAlloc(&local_24,0xff,"%s:%s:%s",*(undefined4 *)(param_1 + 0xd4),
           *(undefined4 *)(param_1 + 0x128),*(undefined4 *)(param_1 + 0xd0));
  uVar1 = FUN_00419bac(local_24);
  bfreeSafe(local_24);
  local_20 = websGetVar(param_1,"REQUEST_METHOD",0);
  iVar2 = (*(code *)PTR_strlen_0043095c)(local_20);
  iVar3 = (*(code *)PTR_strlen_0043095c)(*(undefined4 *)(param_1 + 0xb8));
  uVar4 = balloc(iVar2 + iVar3 + 2);
  (*(code *)PTR_sprintf_004309a0)(uVar4,"%s:%s",local_20,*(undefined4 *)(param_1 + 0xb8));
  uVar5 = FUN_00419bac(uVar4);
  bfreeSafe(uVar4);
  local_28 = 0;
  if (*(int *)(param_1 + 0x144) == 0) {
    fmtAlloc(&local_28,0xff,"%s:%s:%s",uVar1,*(undefined4 *)(param_1 + 300),uVar5);
  }
  else {
    fmtAlloc(&local_28,0xff,"%s:%s:%s:%s:%s:%s",uVar1,*(undefined4 *)(param_1 + 300),
             *(undefined4 *)(param_1 + 0x13c),*(undefined4 *)(param_1 + 0x140),
             *(int *)(param_1 + 0x144),uVar5);
  }
  local_20 = FUN_00419bac(local_28);
  bfreeSafe(uVar1);
  bfreeSafe(uVar5);
  bfreeSafe(local_28);
  return local_20;
}

