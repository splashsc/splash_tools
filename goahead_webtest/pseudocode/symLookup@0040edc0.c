
undefined4 * symLookup(int param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar4 = *(int *)(DAT_00430bf8 + param_1 * 4);
  puVar3 = (undefined4 *)0x0;
  if (((iVar4 != 0) && (param_2 != (char *)0x0)) && (cVar1 = *param_2, cVar1 != '\0')) {
    iVar2 = FUN_0040e920(iVar4);
    for (puVar3 = *(undefined4 **)(*(int *)(iVar4 + 8) + iVar2 * 4); puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      if ((*(char *)puVar3[1] == cVar1) &&
         (iVar4 = (*(code *)PTR_strcmp_004309b4)((char *)puVar3[1],param_2), iVar4 == 0)) {
        return puVar3;
      }
    }
  }
  return puVar3;
}

