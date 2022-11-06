
undefined4 websUrlHandlerRequest(int param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  code **ppcVar6;
  
  socketDeleteHandler(*(undefined4 *)(param_1 + 0xf0));
  *(undefined4 *)(param_1 + 0xfc) = 0x10;
  *(int *)(PTR_websStats_00430694 + 0x2c) = *(int *)(PTR_websStats_00430694 + 0x2c) + 1;
  uVar2 = websGetDefaultDir();
  websSetRequestPath(param_1,uVar2,0);
  FUN_0040b0a0(*(undefined4 *)(param_1 + 0xb4));
  FUN_0040b0a0(*(undefined4 *)(param_1 + 0xb8));
  if ((**(char **)(param_1 + 0xb4) == '/') &&
     (iVar3 = (*(code *)PTR_strchr_00430950)(*(char **)(param_1 + 0xb4),0x5c), iVar3 == 0)) {
    bVar1 = true;
    for (iVar3 = 0; iVar3 < DAT_00430bb8; iVar3 = iVar3 + 1) {
      ppcVar6 = (code **)(DAT_00430bb4 + iVar3 * 0x18);
      if ((*ppcVar6 != (code *)0x0) &&
         (iVar4 = (*(code *)PTR_strncmp_00430a08)
                            (ppcVar6[2],*(undefined4 *)(param_1 + 0xb4),ppcVar6[3]), iVar4 == 0)) {
        if (bVar1) {
          websSetEnv(param_1);
        }
        iVar4 = (**ppcVar6)(param_1,ppcVar6[2],ppcVar6[1],ppcVar6[4],*(undefined4 *)(param_1 + 0xb8)
                            ,*(undefined4 *)(param_1 + 0xb4),*(undefined4 *)(param_1 + 0xc4));
        if (iVar4 != 0) {
          return 1;
        }
        iVar4 = websValid(param_1);
        bVar1 = false;
        if (iVar4 == 0) {
          trace(0,"webs: handler %s called websDone, but didn\'t return 1\n",ppcVar6[2]);
          return 1;
        }
      }
    }
    uVar2 = 200;
    pcVar5 = "No handler for this URL";
  }
  else {
    uVar2 = 400;
    pcVar5 = "Bad request";
  }
  websError(param_1,uVar2,pcVar5);
  return 0;
}

