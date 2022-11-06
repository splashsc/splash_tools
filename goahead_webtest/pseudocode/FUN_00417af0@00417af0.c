
int FUN_00417af0(byte *param_1)

{
  byte *pbVar1;
  undefined *puVar2;
  int iVar3;
  byte *pbVar4;
  byte bVar5;
  
  puVar2 = PTR___ctype_b_00430aa4;
  iVar3 = 0;
  pbVar4 = &DAT_0041fb24;
  while (*param_1 != 0) {
    bVar5 = *param_1 ^ *pbVar4;
    if (((char)bVar5 != 0) && ((*(ushort *)(*(int *)puVar2 + (char)bVar5 * 2) & 0x20) == 0)) {
      *param_1 = bVar5;
    }
    pbVar1 = pbVar4 + 1;
    param_1 = param_1 + 1;
    iVar3 = iVar3 + 1;
    pbVar4 = pbVar4 + 1;
    if (*pbVar1 == 0) {
      pbVar4 = &DAT_0041fb24;
    }
  }
  return iVar3;
}

