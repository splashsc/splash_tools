
void websCgiCleanup(void)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  iVar3 = 0;
LAB_00407130:
  do {
    if (DAT_00430b94 <= iVar3) {
      return;
    }
    puVar2 = *(undefined4 **)(DAT_00430b90 + iVar3 * 4);
    if (puVar2 != (undefined4 *)0x0) {
      uVar6 = *puVar2;
      FUN_00406530(puVar2);
      iVar4 = 0x65;
      iVar1 = FUN_00406f6c(puVar2[6]);
      if (iVar1 != 0) {
        iVar3 = iVar3 + 1;
        goto LAB_00407130;
      }
      while (iVar4 = iVar4 + -1, puVar2[7] == 0) {
        if (iVar4 == 0) {
          websError(uVar6,200,"CGI generated no output");
          goto LAB_00407160;
        }
        FUN_00406530(puVar2);
      }
      websDone(uVar6,200);
LAB_00407160:
      (*(code *)PTR_unlink_00430a00)(puVar2[1]);
      (*(code *)PTR_unlink_00430a00)(puVar2[2]);
      DAT_00430b94 = hFree(&DAT_00430b90,iVar3);
      for (piVar5 = (int *)puVar2[5]; (piVar5 != (int *)0x0 && (*piVar5 != 0)); piVar5 = piVar5 + 1)
      {
        bfreeSafe();
      }
      bfreeSafe(puVar2[3]);
      bfreeSafe(puVar2[4]);
      bfreeSafe(puVar2[5]);
      bfreeSafe(puVar2[2]);
      bfreeSafe(puVar2);
    }
    iVar3 = iVar3 + 1;
  } while( true );
}

