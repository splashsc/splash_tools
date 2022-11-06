
void FUN_0040b85c(undefined4 param_1,int param_2,uint param_3,uint param_4,uint param_5,uint param_6
                 )

{
  bool bVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  
  if ((int)param_3 < 0) {
    param_3 = 0xffffffff;
    if (-1 < (int)param_5) {
      param_3 = param_5;
    }
    uVar2 = (*(code *)PTR_strlen_0043095c)(param_2);
    if (uVar2 <= param_3) goto LAB_0040b8f0;
  }
  else if ((-1 < (int)param_5) && ((int)param_5 < (int)param_3)) {
    param_3 = param_5;
  }
  uVar2 = param_3;
LAB_0040b8f0:
  iVar4 = 0;
  if ((int)uVar2 < (int)param_4) {
    bVar1 = 0 < (int)uVar2;
    uVar5 = uVar2;
    if ((param_6 & 1) != 0) goto LAB_0040b93c;
    do {
      uVar5 = uVar5 + 1;
      FUN_0040b770(param_1,0x20);
    } while (uVar5 != param_4);
    iVar4 = 0;
  }
  while( true ) {
    bVar1 = iVar4 < (int)uVar2;
LAB_0040b93c:
    pcVar3 = (char *)(param_2 + iVar4);
    if (!bVar1) break;
    iVar4 = iVar4 + 1;
    FUN_0040b770(param_1,(int)*pcVar3);
  }
  if (((int)uVar2 < (int)param_4) && ((param_6 & 1) != 0)) {
    do {
      uVar2 = uVar2 + 1;
      FUN_0040b770(param_1,0x20);
    } while (uVar2 != param_4);
  }
  return;
}

