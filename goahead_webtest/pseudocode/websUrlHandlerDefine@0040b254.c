
undefined4
websUrlHandlerDefine
          (undefined4 param_1,undefined1 *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  DAT_00430bb4 = brealloc(DAT_00430bb4,(DAT_00430bb8 + 1) * 0x18);
  uVar3 = 0xffffffff;
  if (DAT_00430bb4 != 0) {
    iVar5 = DAT_00430bb8 * 0x18;
    DAT_00430bb8 = DAT_00430bb8 + 1;
    puVar4 = (undefined4 *)(DAT_00430bb4 + iVar5);
    (*(code *)PTR_memset_004309cc)(puVar4,0,0x18);
    uVar3 = bstrdup(param_1);
    puVar1 = PTR_strlen_0043095c;
    puVar4[2] = uVar3;
    uVar3 = (*(code *)puVar1)(uVar3);
    puVar4[3] = uVar3;
    if (param_2 == (undefined1 *)0x0) {
      param_2 = &DAT_0041ed68;
    }
    uVar3 = bstrdup(param_2);
    puVar4[1] = uVar3;
    iVar2 = DAT_00430bb8;
    iVar5 = DAT_00430bb4;
    puVar1 = PTR_qsort_00430a98;
    *puVar4 = param_4;
    puVar4[4] = param_3;
    puVar4[5] = param_5;
    (*(code *)puVar1)(iVar5,iVar2,0x18,&LAB_0040afe4);
    uVar3 = 0;
  }
  return uVar3;
}

