int __fastcall sub_49FEC4(int a1)
{
  bool v2; // dc
  int result; // $v0
  int v4; // $s2
  int v5; // $s0
  const char *v6; // $v0
  unsigned int v7; // $v0
  const char *v8; // $v0
  char v9[1024]; // [sp+18h] [-428h] BYREF
  int v10; // [sp+418h] [-28h] BYREF
  char v11[12]; // [sp+41Ch] [-24h] BYREF
  int v12; // [sp+438h] [-8h]

  memset(v9, 0, sizeof(v9));
  v2 = pppoe_bridge_check_token(a1) == 0;
  result = 0;
  if ( !v2 )
    return result;
  strcpy(v9, "{\"code\":0,\"error\":\"\",\"data\":[");
  v4 = 2;
  v5 = 29;
  v12 = 1869639792;
  while ( v4 == 2 )
  {
    v10 = v12;
    strcpy(v11, "e_br_wan");
    v8 = (const char *)jhl_nv_get_def(&v10);
    v5 += sprintf(&v9[v5], "\"%s\",", v8);
LABEL_13:
    ++v4;
  }
  sprintf((char *)&v10, "pppoe_br_wan%d", 2);
  v6 = (const char *)jhl_nv_get_def(&v10);
  v5 += sprintf(&v9[v5], "\"%s\",", v6);
  if ( v4 != 3 )
    goto LABEL_13;
  if ( v5 > 0 && v9[v5 - 1] == 44 )
    --v5;
  v9[v5] = 0;
  v7 = snprintf(&v9[v5], 1024 - v5, "]}");
  if ( v7 >= 1024 - v5 )
    v7 = 1023 - v5;
  return httpd_cgi_ret(a1, v9, v7 + v5, 4);
}
// 642A04: using guessed type __int16 word_642A04;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

