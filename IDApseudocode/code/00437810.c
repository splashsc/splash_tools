int __fastcall sub_437810(int a1)
{
  char *v2; // $s0
  const char *v3; // $v0
  int v4; // $s5
  char *v5; // $v0
  int v6; // $a0
  char *v7; // $s4
  const char *v8; // $s0
  const char *v9; // $v0
  int v10; // $s3
  const char *v11; // $v0
  int v12; // $a0
  int v13; // $a3
  unsigned int v14; // $v0
  int v15; // $s0
  unsigned int v16; // $v0
  char v18[516]; // [sp+18h] [-204h] BYREF

  v2 = httpd_get_parm(a1, "tz");
  set_nvrams(a1, base_ident_nvarms, 1);
  if ( v2 )
  {
    v3 = (const char *)nvram_get("tm_sel");
    if ( !v3 || strcmp(v3, v2) )
      nvram_set("tm_sel", v2);
  }
  v4 = wan_webset_json(a1);
  v7 = httpd_get_parm(a1, "http_passwd");
  v5 = httpd_get_parm(a1, "http_username");
  v8 = v5;
  if ( v7 )
  {
    v9 = (const char *)nvram_get("http_passwd");
    if ( v9 && !strcmp(v9, v7) )
    {
      v10 = 0;
      if ( !v8 )
        goto LABEL_21;
    }
    else
    {
      nvram_set("http_passwd", v7);
      v10 = 1;
      if ( !v8 )
      {
LABEL_12:
        nvram_set("user_pwd_mod", "0");
        jhl_parm_commit(v12);
        jhl_setwanxx();
        jhl_httpd_reset_user();
        jhl_gl_restart_jhttpd("admin-restart", 200);
        v13 = 1;
        goto LABEL_13;
      }
    }
  }
  else
  {
    v10 = 0;
    if ( !v5 )
    {
      if ( !v4 )
        goto LABEL_22;
      goto LABEL_25;
    }
  }
  v11 = (const char *)nvram_get("http_username");
  if ( !v11 || strcmp(v11, v8) )
  {
    nvram_set("http_username", v8);
    goto LABEL_12;
  }
  if ( v10 )
    goto LABEL_12;
LABEL_21:
  if ( !v4 )
  {
LABEL_22:
    v13 = 0;
    goto LABEL_13;
  }
LABEL_25:
  jhl_parm_commit(v6);
  v13 = 0;
LABEL_13:
  strcpy(v18, "{\"code\":0,\"error\":\"\",\"data\":{");
  v14 = snprintf(&v18[29], 483, "\"relogin\":%d", v13);
  v15 = v14 + 29;
  if ( v14 >= 0x1E3 )
    v15 = 511;
  v16 = snprintf(&v18[v15], 512 - v15, "}}");
  if ( v16 >= 512 - v15 )
    v16 = 511 - v15;
  return httpd_cgi_ret(a1, v18, v16 + v15, 4);
}
// 4379EC: variable 'v12' is possibly undefined
// 437B78: variable 'v6' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 66D240: using guessed type char *base_ident_nvarms[5];
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82B8: using guessed type int jhl_setwanxx(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

