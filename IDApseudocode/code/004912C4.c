int __fastcall get_vpns_iface(_BYTE *a1)
{
  int v2; // $s6
  int v3; // $s0
  int v4; // $s1
  int v5; // $v0
  const char *v6; // $v0
  int v7; // $v1
  int v8; // $v0
  _BYTE *v9; // $s2

  v2 = sq_file_get_max_wan();
  *a1 = 91;
  a1[1] = 0;
  if ( v2 <= 0 )
  {
    v8 = 0;
    v7 = 1;
    v4 = 1;
LABEL_10:
    if ( a1[v8] == 44 )
      v7 = --v4;
    goto LABEL_12;
  }
  v3 = 0;
  v4 = 1;
  do
  {
    v5 = jhl_vpnget("vpn_proto", v3);
    v6 = (const char *)nvram_get(v5);
    if ( !v6 || strcmp(v6, (const char *)&off_63F984) )
      v4 += sprintf(&a1[v4], "{\"iface\":%d},", v3);
    ++v3;
  }
  while ( v3 != 5 && v2 != v3 );
  v7 = v4;
  if ( v4 > 0 )
  {
    v8 = v4 - 1;
    goto LABEL_10;
  }
LABEL_12:
  v9 = &a1[v7];
  *v9 = 93;
  v9[1] = 0;
  return v4 + 1;
}
// 63F984: using guessed type void *off_63F984;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

