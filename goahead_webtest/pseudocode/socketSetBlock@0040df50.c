
uint socketSetBlock(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar1 = socketPtr();
  uVar3 = 0;
  if (iVar1 != 0) {
    uVar3 = *(uint *)(iVar1 + 0xac) & 0x80;
    uVar2 = *(uint *)(iVar1 + 0xac) & 0xffffff7f;
    *(uint *)(iVar1 + 0xac) = uVar2;
    if (param_2 != 0) {
      *(uint *)(iVar1 + 0xac) = uVar2 | 0x80;
    }
    uVar4 = *(undefined4 *)(iVar1 + 0xb0);
    if ((*(uint *)(iVar1 + 0xac) & 0x80) == 0) {
      uVar2 = (*(code *)PTR_fcntl_00430948)(uVar4,3);
      uVar2 = uVar2 | 0x80;
    }
    else {
      uVar2 = (*(code *)PTR_fcntl_00430948)();
      uVar2 = uVar2 & 0xffffff7f;
    }
    (*(code *)PTR_fcntl_00430948)(uVar4,4,uVar2);
  }
  return uVar3;
}

