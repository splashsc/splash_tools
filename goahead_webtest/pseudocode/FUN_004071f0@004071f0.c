
void FUN_004071f0(undefined4 param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = websGetRequestFlags();
  uVar1 = uVar1 & 0x100;
  websSetTimeMark(param_1);
  iVar2 = websGetRequestWritten(param_1);
  if (uVar1 == 0) {
    iVar3 = websGetRequestBytes(param_1);
    iVar4 = balloc(0x200);
    if (iVar4 == 0) {
      websError(param_1,200,"Can\'t get memory");
    }
    else {
      do {
        uVar5 = websPageReadData(param_1,iVar4,0x200);
        if ((int)uVar5 < 1) {
          if (uVar5 == 0) {
            iVar2 = iVar3;
          }
          goto LAB_00407330;
        }
        uVar1 = websWriteDataNonBlock(param_1,iVar4,uVar5);
        if ((int)uVar1 < 0) goto LAB_00407330;
        iVar2 = iVar2 + uVar1;
      } while (uVar1 == uVar5);
      websPageSeek(param_1,uVar1 - uVar5);
LAB_00407330:
      bfree(iVar4);
    }
  }
  else {
    iVar3 = 0;
    uVar1 = 0;
  }
  websSetRequestWritten(param_1,iVar2);
  if ((-1 < (int)uVar1) && (iVar2 < iVar3)) {
    return;
  }
  websDone(param_1,200);
  return;
}

