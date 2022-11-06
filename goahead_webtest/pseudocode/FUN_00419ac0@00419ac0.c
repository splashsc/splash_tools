
undefined4 FUN_00419ac0(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  undefined4 uVar4;
  int iVar5;
  byte local_a0 [16];
  char local_90 [32];
  undefined local_70;
  undefined auStack108 [92];
  undefined4 local_10;
  
  local_10 = param_2;
  psMd5Init(auStack108);
  psMd5Update(auStack108,param_1,local_10);
  psMd5Final(auStack108,local_a0);
  iVar5 = 0;
  pcVar3 = local_90;
  do {
    bVar1 = local_a0[iVar5];
    iVar5 = iVar5 + 1;
    cVar2 = "0123456789abcdef"[bVar1 & 0xf];
    *pcVar3 = "0123456789abcdef"[bVar1 >> 4];
    pcVar3[1] = cVar2;
    pcVar3 = pcVar3 + 2;
  } while (iVar5 != 0x10);
  local_70 = 0;
  uVar4 = balloc(0x21);
  (*(code *)PTR_strncpy_00430a04)(uVar4,local_90,0x21);
  return uVar4;
}

