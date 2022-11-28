_BYTE *__fastcall asp_jhl_dns(_BYTE *a1, int a2)
{
  int *v3; // $fp
  char *v4; // $s6
  int v5; // $s1
  int v6; // $s0
  const char *v7; // $s7
  struct in_addr v8; // $a0
  char *v9; // $v0
  _BYTE *v10; // $s1

  v3 = (int *)jhl_get_dns(a2);
  *a1 = 91;
  a1[1] = 32;
  a1[2] = 0;
  v4 = a1 + 2;
  if ( *v3 <= 0 )
  {
    v5 = 2;
  }
  else
  {
    v5 = 2;
    v6 = 0;
    v7 = "";
    while ( 1 )
    {
      v8.s_addr = v3[++v6];
      v9 = inet_ntoa(v8);
      v5 += sprintf(v4, "%s\"%s\"", v7, v9);
      if ( v6 >= *v3 )
        break;
      v4 = &a1[v5];
      if ( v6 )
        v7 = &byte_643D4C;
      else
        v7 = "";
    }
  }
  v10 = &a1[v5];
  *v10 = 93;
  v10[1] = 0;
  return a1;
}
// 643D4C: using guessed type char byte_643D4C;
// 6A857C: using guessed type int __fastcall jhl_get_dns(_DWORD);

