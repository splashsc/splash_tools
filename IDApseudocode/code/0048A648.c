int __fastcall sub_48A648(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  const char *v4; // $s0
  const char *v5; // $v0
  int v6; // $s3
  const char *v7; // $v0
  int v8; // $a0
  int v9; // $s1
  unsigned int v10; // $v0
  char v12[1028]; // [sp+18h] [-404h] BYREF

  v3 = httpd_get_parm(a1, "enable");
  v2 = httpd_get_parm(a1, "srv_path");
  v4 = v2;
  if ( v3 )
  {
    v5 = (const char *)nvram_get("url_update_en");
    if ( v5 && !strcmp(v5, v3) )
    {
      v6 = 0;
      if ( !v4 )
        goto LABEL_9;
    }
    else
    {
      nvram_set("url_update_en", v3);
      v6 = 1;
      if ( !v4 )
      {
LABEL_8:
        nvram_unset("url_modify_time");
        exec_service("url_update-restart");
        jhl_parm_commit(v8);
        goto LABEL_9;
      }
    }
  }
  else
  {
    v6 = 0;
    if ( !v2 )
      goto LABEL_9;
  }
  v7 = (const char *)nvram_get("url_update_path");
  if ( !v7 || strcmp(v7, v4) )
  {
    nvram_set("url_update_path", v4);
    goto LABEL_8;
  }
  if ( v6 )
    goto LABEL_8;
LABEL_9:
  strcpy(v12, "{\"code\":0,\"error\":\"\",\"data\":{");
  v9 = get_url_update_data(&v12[29]) + 29;
  v10 = snprintf(&v12[v9], 1024 - v9, "}}");
  if ( v10 >= 1024 - v9 )
    v10 = 1023 - v9;
  return httpd_cgi_ret(a1, v12, v10 + v9, 4);
}
// 48A798: variable 'v8' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

