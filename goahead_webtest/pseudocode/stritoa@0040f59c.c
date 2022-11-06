
/* WARNING: Removing unreachable block (ram,0x0040f61c) */

void stritoa(int param_1,char *param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  char local_21 [17];
  int local_10;
  
  if (param_2 == (char *)0x0) {
    if (param_3 == 0) {
      param_3 = 10;
    }
    local_10 = param_3;
    param_2 = (char *)balloc(param_3 + 1);
    param_3 = local_10;
    if (param_2 == (char *)0x0) {
      return;
    }
  }
  bVar1 = param_1 < 0;
  if (bVar1) {
    param_1 = -param_1;
    param_3 = param_3 + -1;
  }
  pcVar3 = local_21 + 1;
  pcVar4 = pcVar3 + param_3 + -1;
  while( true ) {
    cVar2 = (char)param_1;
    if (param_1 < 10) break;
    if (pcVar4 <= pcVar3) goto LAB_0040f678;
    param_1 = param_1 / 10;
    *pcVar3 = cVar2 + '0' + (char)param_1 * -10;
    pcVar3 = pcVar3 + 1;
  }
  if (pcVar4 > pcVar3) {
    *pcVar3 = cVar2 + '0';
    pcVar3 = pcVar3 + 1;
  }
LAB_0040f678:
  if (bVar1) {
    *param_2 = '-';
    param_2 = param_2 + 1;
  }
  while (bVar1 = local_21 + 1 < pcVar3, pcVar3 = pcVar3 + -1, bVar1) {
    *param_2 = *pcVar3;
    param_2 = param_2 + 1;
  }
  *param_2 = '\0';
  return;
}

