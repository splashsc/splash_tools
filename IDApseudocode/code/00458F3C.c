int __fastcall sub_458F3C(int a1)
{
  char *v2; // $s6
  char *v3; // $fp
  char *v4; // $s7
  char *v5; // $s5
  const char *v6; // $v0
  _BOOL4 v7; // $s2
  const char *v8; // $v0
  const char *v9; // $v0
  const char *v10; // $v0
  char *v11; // $s1
  const char *v12; // $v0
  char *v13; // $s5
  const char *v14; // $v0
  char *v15; // $s3
  const char *v16; // $v0
  char *v17; // $s4
  const char *v18; // $v0
  int v19; // $a0
  const char *v20; // $v0
  int v21; // $s3
  unsigned int v22; // $v0
  unsigned int v23; // $a2
  int v25; // $s1
  char *v26; // $v0
  const char *v27; // $v0
  char *v28; // $s3
  char v29[512]; // [sp+20h] [-200h] BYREF

  v2 = httpd_get_parm(a1, "http_passwd");
  v3 = httpd_get_parm(a1, "http_username");
  v4 = httpd_get_parm(a1, "http_gpwd");
  v5 = httpd_get_parm(a1, "http_gname");
  if ( v3 )
  {
    v6 = (const char *)nvram_get("http_username");
    if ( v6 )
      v7 = strcmp(v6, v3) != 0;
    else
      v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  if ( v2 )
  {
    v8 = (const char *)nvram_get("http_passwd");
    if ( !v8 || strcmp(v8, v2) )
      v7 = 1;
  }
  if ( v5 )
  {
    v9 = (const char *)nvram_get("http_gname");
    if ( !v9 || strcmp(v9, v5) )
    {
      if ( !v4 )
        goto LABEL_15;
      v7 = 1;
LABEL_13:
      v10 = (const char *)nvram_get("http_gpwd");
      if ( !v10 || strcmp(v10, v4) )
        goto LABEL_15;
      goto LABEL_35;
    }
  }
  if ( v4 )
    goto LABEL_13;
LABEL_35:
  if ( !v7 )
  {
    if ( save_variables(a1, 0) )
      goto LABEL_16;
    goto LABEL_37;
  }
LABEL_15:
  nvram_set("user_pwd_mod", "0");
  v7 = 1;
  if ( save_variables(a1, 0) )
  {
LABEL_16:
    v11 = httpd_get_parm(a1, "http_lanport");
    if ( !v11 || (v12 = (const char *)nvram_get("http_lanport")) != 0 && !strcmp(v12, v11) )
      v11 = 0;
    v13 = httpd_get_parm(a1, "https_lanport");
    if ( !v13 || (v14 = (const char *)nvram_get("https_lanport")) != 0 && !strcmp(v14, v13) )
      v13 = 0;
    v15 = httpd_get_parm(a1, "tggl_port");
    if ( !v15 || (v16 = (const char *)nvram_get("tggl_port")) != 0 && !strcmp(v16, v15) )
      v15 = 0;
    v17 = httpd_get_parm(a1, "allow_ips");
    if ( !v17 || (v18 = (const char *)nvram_get("allow_ips")) != 0 && !strcmp(v18, v17) )
    {
      v17 = 0;
      if ( !save_variables(a1, 1) )
        goto LABEL_29;
    }
    else if ( !save_variables(a1, 1) )
    {
LABEL_29:
      strcpy(v29, "{\"code\":0,\"error\":\"\",\"data\":{");
      if ( v11 )
      {
        v20 = (const char *)nvram_get("lan_ipaddr");
        v21 = sprintf(&v29[29], "\"lan_ipaddr\":\"%s:%s\",\"mod_passwd\":\"%d\"", v20, v11, v7) + 29;
      }
      else
      {
        v21 = sprintf(&v29[29], "\"mod_passwd\":\"%d\"", v7) + 29;
      }
      v22 = snprintf(&v29[v21], 512 - v21, "}}");
      v23 = v22 + v21;
      if ( v22 >= 512 - v21 )
        v23 = 511;
      return httpd_cgi_ret(a1, v29, v23, 4);
    }
    jhl_parm_commit(v19);
    if ( httpd_get_parm(a1, "shortset_flag") )
    {
      nvram_unset("shortset_flag");
      goto LABEL_29;
    }
    jhl_setwanxx();
    if ( v11 )
    {
      start_rzgl(0);
      v28 = "jadmin-restart";
    }
    else
    {
      if ( v15 || v13 )
      {
        start_rzgl(0);
      }
      else if ( !v17 )
      {
        v28 = "admin-restart";
        goto LABEL_50;
      }
      v28 = "jadmin-restart";
    }
LABEL_50:
    jhl_httpd_reset_user();
    jhl_gl_restart_jhttpd(v28, 200);
    goto LABEL_29;
  }
LABEL_37:
  v25 = *(unsigned __int8 *)(a1 + 210102);
  v26 = resmsg_get();
  v27 = (const char *)_GET_LANG_TEXT(12, v25, v26);
  v23 = snprintf(v29, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
  if ( v23 >= 0x200 )
    v23 = 511;
  return httpd_cgi_ret(a1, v29, v23, 4);
}
// 459480: variable 'v19' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82B8: using guessed type int jhl_setwanxx(void);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

