
uint ringqGetc(undefined4 *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  pcVar3 = (char *)param_1[1];
  uVar2 = 0xffffffff;
  if (pcVar3 != (char *)param_1[2]) {
    cVar1 = *pcVar3;
    param_1[1] = pcVar3 + 1;
    if ((char *)param_1[3] <= pcVar3 + 1) {
      param_1[1] = *param_1;
    }
    uVar2 = (int)cVar1 & 0xff;
  }
  return uVar2;
}

