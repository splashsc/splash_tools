int __fastcall sub_4BAC7C(int a1)
{
  char *v2; // $s2
  char *v3; // $s5
  char *v4; // $s4
  char *v5; // $s3
  const char *v6; // $v0
  int v7; // $a2
  int v8; // $a0
  const char *v9; // $v0
  unsigned int v10; // $v0
  const char *v12; // $v0
  int v13; // $s2
  const char *v14; // $v0
  const char *v15; // $v0
  const char *v16; // $v0
  char *v17; // $v1
  const char *v18; // $v0
  int v19; // $t0
  int v20; // $a3
  int v21; // $a2
  int v22; // $a1
  char v23[1024]; // [sp+20h] [-400h] BYREF

  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "appid");
  v4 = httpd_get_parm(a1, "closeid");
  v5 = httpd_get_parm(a1, "remark");
  memset(v23, 0, sizeof(v23));
  v6 = (const char *)nvram_get("sj_ctrl_connect_state");
  if ( v6 && !strcmp(v6, "1") )
  {
    if ( !v2 || (v12 = (const char *)nvram_get("sj_state_en")) != 0 && !strcmp(v12, v2) )
    {
      v13 = 0;
    }
    else
    {
      syslog(7, "%s[%d]:  set sj_en=%s\n", "shenji_asp", 998, v2);
      nvram_set("sj_en", v2);
      nvram_set("sj_ftp_en2", v2);
      nvram_set("sj_state_en", v2);
      v13 = 1;
      exec_service("wys_sj-restart");
    }
    if ( v3 )
    {
      v14 = (const char *)nvram_get("sj_app_id");
      if ( !v14 || strcmp(v14, v3) )
      {
        nvram_set("sj_app_id", v3);
        v13 = 1;
      }
    }
    if ( !v4 || (v15 = (const char *)nvram_get("sj_app_closeid")) != 0 && !strcmp(v15, v4) )
    {
      if ( !v5 )
      {
LABEL_28:
        if ( !v13 )
        {
LABEL_24:
          v17 = v23;
          v18 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          do
          {
            v19 = *(_DWORD *)v18;
            v20 = *((_DWORD *)v18 + 1);
            v21 = *((_DWORD *)v18 + 2);
            v22 = *((_DWORD *)v18 + 3);
            v18 += 16;
            *(_DWORD *)v17 = v19;
            *((_DWORD *)v17 + 1) = v20;
            *((_DWORD *)v17 + 2) = v21;
            *((_DWORD *)v17 + 3) = v22;
            v17 += 16;
          }
          while ( v18 != "}" );
          *(_WORD *)v17 = *(_WORD *)v18;
          return httpd_cgi_ret(a1, v23, 33, 4);
        }
LABEL_23:
        jhl_parm_commit(v8);
        goto LABEL_24;
      }
    }
    else
    {
      nvram_set("sj_app_closeid", v4);
      if ( !v5 )
        goto LABEL_23;
      v13 = 1;
    }
    v16 = (const char *)nvram_get("sj_app_remark");
    if ( !v16 || strcmp(v16, v5) )
    {
      nvram_set("sj_app_remark", v5);
      goto LABEL_23;
    }
    goto LABEL_28;
  }
  v9 = (const char *)_GET_LANG_TEXT(66, *(unsigned __int8 *)(a1 + 210102), v7);
  v10 = snprintf(v23, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
  if ( v10 >= 0x400 )
    v10 = 1023;
  return httpd_cgi_ret(a1, v23, v10, 4);
}
// 4BAD90: variable 'v7' is possibly undefined
// 4BB000: variable 'v8' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

