
int socketGetInput(undefined4 param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *param_4 = 0;
  iVar1 = socketPtr();
  iVar2 = -1;
  if (iVar1 != 0) {
    iVar2 = 0;
    if ((*(uint *)(iVar1 + 0xac) & 1) == 0) {
      if ((*(uint *)(iVar1 + 0xac) & 0x20) == 0) {
        iVar2 = (*(code *)PTR_recv_00430ac0)(*(undefined4 *)(iVar1 + 0xb0),param_2,param_3,0);
      }
      else {
        iVar2 = (*(code *)PTR_recvfrom_00430a80)();
      }
      if (iVar2 < 0) {
        iVar3 = socketGetError();
        *param_4 = iVar3;
        iVar2 = -1;
        if (iVar3 == 0x83) {
          *(uint *)(iVar1 + 0xac) = *(uint *)(iVar1 + 0xac) | 0x400;
          iVar2 = 0;
        }
      }
    }
  }
  return iVar2;
}

