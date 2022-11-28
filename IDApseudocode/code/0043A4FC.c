int __fastcall sub_43A4FC(int a1)
{
  char *v2; // $v0
  char *v3; // $v0
  char *v4; // $s1
  const char *v5; // $s2
  const char *v6; // $s6
  int v7; // $v0
  int v8; // $a2
  int v9; // $s7
  unsigned int v10; // $v0
  unsigned int v11; // $s3
  unsigned int v12; // $s5
  unsigned int v13; // $v0
  unsigned int v14; // $s2
  int result; // $v0
  const char *v16; // $v0
  char v17[2048]; // [sp+20h] [-80Ch] BYREF
  int v18; // [sp+820h] [-Ch]
  int v19; // [sp+824h] [-8h] BYREF

  memset(v17, 0, sizeof(v17));
  v18 = 0;
  v2 = httpd_get_parm(a1, "sdfwv23s");
  if ( v2 && !strcmp(v2, "df234") || *(_BYTE *)(a1 + 40) == 2 )
  {
    v4 = httpd_get_parm(a1, "user");
    v3 = httpd_get_parm(a1, "password");
    v5 = v3;
    if ( v3 )
      v6 = v3;
    else
      v6 = "";
    if ( !v4 || !*v4 )
    {
      if ( gl_httpd_high_admin_en && !strcmp(v3, gl_httpd_high_adminpwd) )
      {
        v4 = gl_httpd_high_admin;
      }
      else if ( gl_httpd_admin_en && !strcmp(v5, gl_httpd_adminpwd) )
      {
        v4 = gl_httpd_admin;
      }
      else if ( gl_httpd_user_en && !strcmp(v5, gl_httpd_password) )
      {
        v4 = gl_httpd_user;
      }
      else if ( gl_httpd_guest_user_en && !strcmp(v5, gl_httpd_guest_pwd) )
      {
        v4 = gl_httpd_guest_user;
      }
      else
      {
        v4 = "";
      }
    }
    v7 = httpd_cgi_user_check(v4, v6, &v19);
    v9 = v7;
    if ( v7 <= 0 )
    {
      v14 = 0;
      if ( !v7 )
      {
        v16 = (const char *)_GET_LANG_TEXT(10, *(unsigned __int8 *)(a1 + 210102), v8);
        v14 = snprintf(v17, 2048, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
        if ( v14 >= 0x800 )
          v14 = 2047;
      }
      jhl_user_login_add((_DWORD *)(a1 + 205460), (void *)0x64, v4, 1);
    }
    else
    {
      strcpy(v17, "{\"code\":0,\"error\":\"\",\"data\":{");
      v10 = snprintf(&v17[29], 2019, "\"token\":\"%s\"", "");
      if ( v10 >= 0x7E3 )
        v10 = 2018;
      v11 = v10 + 29;
      v12 = 2048 - (v10 + 29);
      v13 = snprintf(&v17[v10 + 29], v12, "}}");
      if ( v13 >= v12 )
        v13 = 2047 - v11;
      v14 = v13 + v11;
      *(_DWORD *)(a1 + 36) |= 0x1000u;
    }
    ai_send_router_login(a1, v4, v6, v9 > 0, "web");
    result = httpd_cgi_ret(a1, v17, v14, 4);
  }
  else
  {
    httpd_conn_close((int *)a1);
    result = -1;
  }
  return result;
}
// 43A8D4: variable 'v8' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 666170: using guessed type int gl_httpd_admin_en;
// 67D090: using guessed type int gl_httpd_guest_user_en;
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 67D098: using guessed type int gl_httpd_user_en;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

