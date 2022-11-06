
undefined4 *
symEnter(int param_1,char *param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
        undefined4 param_6,undefined4 param_7)

{
  undefined *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_res8;
  undefined4 local_resc;
  undefined auStack48 [20];
  
  iVar5 = *(int *)(DAT_00430bf8 + param_1 * 4);
  local_res8 = param_3;
  local_resc = param_4;
  iVar2 = FUN_0040e920(iVar5);
  puVar3 = *(undefined4 **)(*(int *)(iVar5 + 8) + iVar2 * 4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)balloc(0x24);
    if (puVar3 != (undefined4 *)0x0) {
      *(undefined4 **)(*(int *)(iVar5 + 8) + iVar2 * 4) = puVar3;
      iVar2 = FUN_0040e920(iVar5,param_2);
      puVar1 = PTR_memcpy_00430a90;
      *(undefined4 **)(*(int *)(iVar5 + 8) + iVar2 * 4) = puVar3;
      *puVar3 = 0;
      (*(code *)puVar1)((int)puVar3 + 0x12,&local_res8,0xe);
      puVar3[8] = param_7;
      valueString(auStack48,param_2,1);
      (*(code *)PTR_memcpy_00430a90)(puVar3 + 1,auStack48,0xe);
    }
  }
  else {
    do {
      puVar4 = puVar3;
      if ((*(char *)puVar4[1] == *param_2) &&
         (iVar2 = (*(code *)PTR_strcmp_004309b4)((char *)puVar4[1],param_2), iVar2 == 0)) {
        if (*(char *)((int)puVar4 + 0x1e) != '\0') {
          valueFree((int)puVar4 + 0x12);
        }
        (*(code *)PTR_memcpy_00430a90)((int)puVar4 + 0x12,&local_res8,0xe);
        puVar4[8] = param_7;
        return puVar4;
      }
      puVar3 = (undefined4 *)*puVar4;
    } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
    puVar3 = (undefined4 *)balloc(0x24);
    if (puVar3 != (undefined4 *)0x0) {
      valueString(auStack48,param_2,1);
      (*(code *)PTR_memcpy_00430a90)(puVar3 + 1,auStack48,0xe);
      (*(code *)PTR_memcpy_00430a90)((int)puVar3 + 0x12,&local_res8,0xe);
      *puVar3 = 0;
      puVar3[8] = param_7;
      *puVar4 = puVar3;
    }
  }
  return puVar3;
}

