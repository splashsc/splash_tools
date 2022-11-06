
int dbSave(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  char **ppcVar8;
  undefined4 *puVar9;
  int iVar10;
  int *piVar11;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40 [2];
  int local_38;
  int local_34;
  int local_30;
  
  trace(5,"DB: About to save database to file\n");
  uVar1 = FUN_0041b110();
  fmtAlloc(&local_44,0xfe,"%s/data.tmp",uVar1);
  iVar2 = (*(code *)PTR_open_00430958)(local_44,0x301,0x1b6);
  if (iVar2 < 0) {
    trace(1,"WARNING: Failed to open file %s\n",local_44);
    iVar4 = -1;
    bfree(local_44);
  }
  else {
    iVar7 = 0;
    iVar4 = 0;
    while ((iVar7 < DAT_00430c64 && (iVar4 == 0))) {
      puVar5 = *(undefined4 **)(DAT_00430c60 + iVar7 * 4);
      if (puVar5 != (undefined4 *)0x0) {
        FUN_0041a214(iVar2,"TABLE",*puVar5);
        local_38 = puVar5[1];
        local_34 = puVar5[4];
        iVar10 = 0;
LAB_0041b914:
        iVar6 = iVar10;
        if ((iVar6 < local_34) && (iVar4 == 0)) {
          ppcVar8 = *(char ***)(puVar5[5] + iVar6 * 4);
          if ((ppcVar8 != (char **)0x0) && ((*ppcVar8 != (char *)0x0 && (**ppcVar8 != '\0'))))
          goto code_r0x0041b7dc;
          goto LAB_0041b910;
        }
      }
      iVar7 = iVar7 + 1;
    }
    (*(code *)PTR_close_0043093c)(iVar2);
    if (iVar4 == 0) {
      uVar1 = FUN_0041b110();
      fmtAlloc(local_40,0xfe,"%s/%s",uVar1,param_2);
      (*(code *)PTR_unlink_00430a00)(local_40[0]);
      iVar2 = (*(code *)PTR_rename_00430a5c)(local_44,local_40[0]);
      if (iVar2 != 0) {
        trace(1,"WARNING: Failed to rename %s to %s\n",local_44,local_40[0]);
        iVar4 = -1;
      }
      bfree(local_40[0]);
    }
    bfree(local_44);
  }
  return iVar4;
code_r0x0041b7dc:
  fmtAlloc(&local_48,0x14,"%d",iVar6);
  local_30 = FUN_0041a214(iVar2,&DAT_0041ff64,local_48);
  bfreeSafe(local_48);
  puVar9 = (undefined4 *)puVar5[2];
  piVar11 = (int *)puVar5[3];
  iVar3 = local_30;
  for (iVar10 = 0; iVar10 < local_38; iVar10 = iVar10 + 1) {
    if (iVar3 < 0) goto LAB_0041b8f0;
    if (*piVar11 == 1) {
      iVar3 = FUN_0041a214(iVar2,*puVar9,*ppcVar8);
    }
    else {
      fmtAlloc(&local_48,0x14,"%d",*ppcVar8);
      local_30 = FUN_0041a214(iVar2,*puVar9,local_48);
      bfreeSafe(local_48);
      iVar3 = local_30;
    }
    puVar9 = puVar9 + 1;
    piVar11 = piVar11 + 1;
    ppcVar8 = ppcVar8 + 1;
  }
  iVar10 = iVar6 + 1;
  if (iVar3 < 0) {
LAB_0041b8f0:
    trace(1,"WARNING: Failed to write to file %s\n",local_44);
    iVar4 = -1;
LAB_0041b910:
    iVar10 = iVar6 + 1;
  }
  goto LAB_0041b914;
}

