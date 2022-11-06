
void websDecodeUrl(char *param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  
  puVar3 = PTR___ctype_b_00430aa4;
  puVar2 = PTR___ctype_tolower_00430944;
  for (; (cVar1 = *param_2, cVar1 != '\0' && (0 < param_3)); param_3 = param_3 + -1) {
    if (cVar1 == '+') {
      *param_1 = ' ';
    }
    else if (((cVar1 == '%') && ((*(ushort *)(*(int *)puVar3 + param_2[1] * 2) & 0x10) != 0)) &&
            (iVar5 = 0, (*(ushort *)(*(int *)puVar3 + param_2[2] * 2) & 0x10) != 0)) {
      iVar4 = 0;
      pcVar7 = param_2;
      do {
        iVar6 = (int)*(short *)(*(int *)puVar2 + pcVar7[1] * 2);
        iVar4 = iVar6 + iVar4 * 0x10;
        if (iVar6 - 0x61U < 6) {
          iVar4 = iVar4 + -0x57;
        }
        else {
          iVar4 = iVar4 + -0x30;
        }
        iVar5 = iVar5 + 1;
        pcVar7 = param_2 + iVar5;
      } while (iVar5 != 2);
      *param_1 = (char)iVar4;
      param_2 = param_2 + 2;
    }
    else {
      *param_1 = cVar1;
    }
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  *param_1 = '\0';
  return;
}

