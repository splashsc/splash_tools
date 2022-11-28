int __fastcall sub_43CE78(int a1)
{
  const char *v1; // $s0
  char *v2; // $v0
  int v3; // $s2
  char *v4; // $v0
  const char *v5; // $s1
  int v6; // $s1
  unsigned int v7; // $v0
  int v9; // $s0
  int v10; // $s7
  int v11; // $s5
  int v12; // $v0
  int v13[1024]; // [sp+28h] [-1170h] BYREF
  char v14[256]; // [sp+1028h] [-170h] BYREF
  char v15[64]; // [sp+1128h] [-70h] BYREF
  char *nptr[2]; // [sp+1168h] [-30h] BYREF
  int v17; // [sp+1170h] [-28h]
  int v18; // [sp+1174h] [-24h]
  int v19; // [sp+1180h] [-18h] BYREF
  char *v20; // [sp+1188h] [-10h]
  char *format; // [sp+118Ch] [-Ch]
  const char *v22; // [sp+1190h] [-8h]

  memset(v13, 0, sizeof(v13));
  v1 = v14;
  memset(v14, 0, sizeof(v14));
  v2 = (char *)nvram_get("port_mode");
  if ( !v2 )
    v2 = "0|0>1|0>2|0>3|0>4|0>5|0>6|0>7|0>8|0>9|0>";
  strcpy(v14, v2);
  v3 = 44;
  qmemcpy(v13, "{\"code\":0,\"error\":\"\",\"data\":{\"poe\":0,\"all", 41);
  *(int *)((char *)&v13[10] + 1) = (int)&unk_5B3A22;
  format = "{\"n\":\"%s\",\"m\":%s,\"s\":%d,\"d\":\"%s\",\"p\":%lu,\"port\":%d},";
  v22 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
  while ( *v1 )
  {
    v4 = strchr(v1, 62);
    if ( !v4 )
    {
      v5 = 0;
      if ( split_string(v1, 124, nptr, 4) < 2 )
        break;
      goto LABEL_15;
    }
    *v4 = 0;
    v5 = v4 + 1;
    if ( split_string(v1, 124, nptr, 4) >= 2 )
    {
LABEL_15:
      v9 = atoi(nptr[0]);
      get_ifname_by_id(v9, v15);
      get_link_status_by_id(v9, &v19);
      v10 = v17;
      v11 = v19;
      if ( !v17 )
        v10 = (int)(v22 - 1556);
      v20 = nptr[1];
      v12 = J_atoi(v18);
      v3 += sprintf((char *)v13 + v3, format, v15, v20, v11, v10, v12, v9);
      v1 = v5;
      if ( !v5 )
        break;
    }
    else
    {
      v1 = v5;
      if ( !v5 )
        break;
    }
  }
  if ( v3 > 0 && *((_BYTE *)v13 + v3 - 1) == 44 )
    --v3;
  v6 = v3 + 1;
  *(_WORD *)((char *)v13 + v3) = 93;
  v7 = snprintf((char *)v13 + v3 + 1, 4096 - (v3 + 1), "}}");
  if ( v7 >= 4096 - (v3 + 1) )
    v7 = 4095 - v6;
  return httpd_cgi_ret(a1, (char *)v13, v7 + v6, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8218: using guessed type int __fastcall get_link_status_by_id(_DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8968: using guessed type int __fastcall get_ifname_by_id(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

