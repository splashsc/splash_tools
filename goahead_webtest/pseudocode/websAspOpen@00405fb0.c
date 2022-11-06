
undefined4 websAspOpen(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined *puVar3;
  
  iVar2 = DAT_00430b30 + 1;
  puVar3 = &_mips_gp0_value;
  bVar1 = DAT_00430b30 == 0;
  DAT_00430b30 = iVar2;
  if (bVar1) {
    DAT_00430040 = symOpen(0x80);
    websAspDefine("write",FUN_004058d8,param_3,param_4,puVar3);
  }
  return 0;
}

