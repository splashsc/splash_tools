int __fastcall sub_4C9AF8(int a1)
{
  char *v1; // $v0
  const char *v3; // $s2
  const char *v4; // $v0
  char *v5; // $v1
  int v6; // $t0
  int v7; // $a3
  int v8; // $a2
  int v9; // $a1
  unsigned int v10; // $a2
  unsigned int v12; // $v0
  const char *v13; // $v0
  char v14[1024]; // [sp+20h] [-400h] BYREF

  v1 = httpd_get_parm(a1, "sn");
  if ( !v1 )
  {
    v13 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not sn");
    v10 = snprintf(v14, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    if ( v10 >= 0x400 )
      v10 = 1023;
    return httpd_cgi_ret(a1, v14, v10, 4);
  }
  v3 = v1;
  if ( !ai_is_running(0) )
  {
    v4 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v5 = v14;
    do
    {
      v6 = *(_DWORD *)v4;
      v7 = *((_DWORD *)v4 + 1);
      v8 = *((_DWORD *)v4 + 2);
      v9 = *((_DWORD *)v4 + 3);
      v4 += 16;
      *(_DWORD *)v5 = v6;
      *((_DWORD *)v5 + 1) = v7;
      *((_DWORD *)v5 + 2) = v8;
      *((_DWORD *)v5 + 3) = v9;
      v5 += 16;
    }
    while ( v4 != "}" );
    v10 = 33;
    *(_WORD *)v5 = *(_WORD *)v4;
    return httpd_cgi_ret(a1, v14, v10, 4);
  }
  v12 = snprintf(v14, 1024, "{\"sn\":\"%s\"}", v3);
  if ( v12 >= 0x400 )
    v12 = 1023;
  ai_unix_cgi_send(0x2729u, *(_DWORD *)(a1 + 205416), v14, v12);
  *(_DWORD *)(a1 + 210096) = 10025;
  *(_DWORD *)(a1 + 205572) = 0;
  ai_cgi_common_timeout((_DWORD *)a1);
  return 0;
}
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

