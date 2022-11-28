int __fastcall httpd_unix_cmd_do(int a1, int a2, const char *a3, int a4)
{
  int *v6; // $v0
  int *v8; // $s0
  int v9; // $s2
  int v10; // $s1
  int v12; // $s5
  char *v13; // $v0
  char *v14; // $s7
  int v15; // $s0
  int v16; // $v0
  int v17; // $s3
  int v18; // $s5
  int v19; // $a2
  const char *v20; // $v0
  unsigned int v21; // $a2
  char v22[260]; // [sp+20h] [-104h] BYREF

  v6 = _httpd_conn_find(a2);
  if ( v6 )
  {
    v8 = v6 + 49152;
    v9 = v6[52524];
    v10 = (int)v6;
    if ( v9 == a1 )
    {
      v12 = a4 + 1024;
      v6[52524] = 0;
      _mem_malloc(a4 + 1024, "httpd_unix_cmd_do", 201);
      v14 = v13;
      if ( v13 )
      {
        switch ( v9 )
        {
          case 10021:
          case 10022:
          case 10024:
          case 10025:
          case 10028:
            v15 = snprintf(v13, a4 + 1024, "{\"code\":0,\"error\":\"\",\"data\":");
            if ( v15 >= v12 )
              v15 = a4 + 1023;
            v16 = snprintf(&v14[v15], v12 - v15, "%s", a3);
            if ( v16 >= v12 - v15 )
              v16 = v12 - v15 - 1;
            v17 = v15 + v16;
            v18 = v12 - (v15 + v16);
            v19 = snprintf(&v14[v15 + v16], v18, "}");
            if ( v19 >= v18 )
              v19 = v18 - 1;
            httpd_cgi_ret(v10, v14, v19 + v17, 4);
            break;
          case 10023:
            ai_check_upgrade_data(v10);
            break;
          default:
            break;
        }
        _mem_free(v14);
      }
      else
      {
        v20 = (const char *)_GET_LANG_TEXT(4, *((unsigned __int8 *)v8 + 13494), a4 + 1024);
        v21 = snprintf(v22, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v20);
        if ( v21 >= 0x100 )
          v21 = 255;
        httpd_cgi_ret(v10, v22, v21, 4);
      }
    }
  }
  return 0;
}
// 433C68: variable 'v13' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

