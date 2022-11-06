
undefined4
dbRegisterDBSchema(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  
  trace(4,"DB: Registering database table <%s>\n",*param_1,param_4,&_mips_gp0_value);
  iVar1 = hAllocEntry(&DAT_00430c60,&DAT_00430c64,0x18);
  puVar3 = *(undefined4 **)(DAT_00430c60 + iVar1 * 4);
  uVar2 = bstrdup(*param_1);
  iVar1 = param_1[1];
  *puVar3 = uVar2;
  puVar3[1] = iVar1;
  if (iVar1 < 1) {
    puVar3[2] = 0;
    puVar3[3] = 0;
  }
  else {
    uVar2 = balloc(iVar1 << 2);
    puVar3[2] = uVar2;
    uVar2 = balloc(puVar3[1] << 2);
    puVar3[3] = uVar2;
    for (iVar1 = 0; iVar4 = iVar1 * 4, iVar1 < (int)param_1[1]; iVar1 = iVar1 + 1) {
      iVar5 = puVar3[2];
      uVar2 = bstrdup(*(undefined4 *)(param_1[2] + iVar4));
      *(undefined4 *)(iVar5 + iVar4) = uVar2;
      *(undefined4 *)(puVar3[3] + iVar4) = *(undefined4 *)(param_1[3] + iVar4);
    }
  }
  puVar3[4] = 0;
  puVar3[5] = 0;
  return 0;
}

