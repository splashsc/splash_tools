int __fastcall ip_allow_to_access_jhttpd(uint32_t a1)
{
  char *v2; // $s2
  int v4; // $s5
  int v5; // $s3
  char *v6; // $v0
  char *v7; // $s1
  char v8[1024]; // [sp+18h] [-54Ch] BYREF
  char v9[256]; // [sp+418h] [-14Ch] BYREF
  char v10[64]; // [sp+518h] [-4Ch] BYREF
  uint32_t v11; // [sp+558h] [-Ch] BYREF
  uint32_t netlong[2]; // [sp+55Ch] [-8h] BYREF

  memset(v8, 0, sizeof(v8));
  memset(v10, 0, sizeof(v10));
  jhl_parm_get("allow_ips", v8, 1024);
  v2 = v9;
  if ( v8[0] )
  {
    v4 = split_string(v8, 44, v9, 64);
    if ( v4 <= 0 )
      return 0;
    v5 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        netlong[0] = 0;
        v11 = 0;
        memset(v10, 0, sizeof(v10));
        strlcpy(v10, *(_DWORD *)v2, 64);
        v6 = strchr(v10, 45);
        v7 = v6;
        if ( v6 )
        {
          *v6 = 0;
          inet_aton(v10, (struct in_addr *)netlong);
          inet_aton(v7 + 1, (struct in_addr *)&v11);
        }
        else
        {
          inet_aton(v10, (struct in_addr *)netlong);
          inet_aton(v10, (struct in_addr *)&v11);
        }
        ++v5;
        if ( a1 >= ntohl(netlong[0]) )
          break;
        v2 += 4;
        if ( v4 == v5 )
          return 0;
      }
      if ( ntohl(v11) >= a1 )
        break;
      v2 += 4;
      if ( v4 == v5 )
        return 0;
    }
  }
  return 1;
}
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

