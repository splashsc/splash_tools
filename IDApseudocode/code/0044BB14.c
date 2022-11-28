int __fastcall sub_44BB14(int a1, int a2)
{
  int *v3; // $s3
  int v4; // $s0
  int v5; // $s1
  char *v6; // $v0

  v3 = (int *)jhl_get_dns(a2);
  v4 = 0;
  if ( *v3 > 0 )
  {
    v5 = 0;
    do
    {
      v6 = inet_ntoa((struct in_addr)v3[++v5]);
      v4 += sprintf((char *)(a1 + v4), "%s ", v6);
    }
    while ( v5 < *v3 );
    if ( v4 > 0 && *(_BYTE *)(a1 + v4 - 1) == 32 )
      --v4;
  }
  *(_BYTE *)(a1 + v4) = 0;
  return a1;
}
// 6A857C: using guessed type int __fastcall jhl_get_dns(_DWORD);

