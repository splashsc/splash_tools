int __fastcall sub_43C2EC(int a1)
{
  char *v1; // $s6
  int v2; // $v0
  int v3; // $s3
  int v4; // $s7
  int v5; // $fp
  const char *v6; // $v0
  unsigned int v7; // $v0
  int v8; // $v0
  unsigned int v9; // $v0
  char v11[1024]; // [sp+18h] [-C08h] BYREF
  char v12[1024]; // [sp+418h] [-808h] BYREF
  char v13[1024]; // [sp+818h] [-408h] BYREF
  char *v14; // [sp+C18h] [-8h]

  memset(v13, 0, sizeof(v13));
  memset(v12, 0, sizeof(v12));
  jhl_parm_get_def("port_desc", v12, 1024);
  v1 = v11;
  v14 = v11;
  strcpy(v13, "{\"code\":0,\"error\":\"\",\"data\":[");
  v2 = split_string(v12, 124, v11, 256);
  if ( v2 <= 0 )
  {
    v8 = 28;
    v5 = 29;
LABEL_7:
    if ( v14[v8 + 2048] == 44 )
      v5 = v8;
    goto LABEL_9;
  }
  v3 = v2;
  v4 = 0;
  v5 = 29;
  do
  {
    v6 = (const char *)get_json_data(*(_DWORD *)v1);
    v7 = snprintf(&v13[v5], 1024 - v5, "\"%s\",", v6);
    ++v4;
    if ( v7 >= 1024 - v5 )
      v7 = 1023 - v5;
    v5 += v7;
    v1 += 4;
  }
  while ( v3 != v4 );
  v8 = v5 - 1;
  if ( v5 > 0 )
    goto LABEL_7;
LABEL_9:
  v14[v5 + 2048] = 0;
  v9 = snprintf(&v13[v5], 1024 - v5, "]}");
  if ( v9 >= 1024 - v5 )
    v9 = 1023 - v5;
  return httpd_cgi_ret(a1, v13, v9 + v5, 4);
}
// 642A04: using guessed type __int16 word_642A04;
// 6A871C: using guessed type int __fastcall get_json_data(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8988: using guessed type int __fastcall jhl_parm_get_def(_DWORD, _DWORD, _DWORD);

