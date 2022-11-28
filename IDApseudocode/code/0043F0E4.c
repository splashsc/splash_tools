int __fastcall sub_43F0E4(int a1)
{
  char *v2; // $s4
  char *v3; // $s3
  int v4; // $a0
  char *v5; // $s2
  const char *v6; // $v0
  int v7; // $s4
  const char *v8; // $v0
  const char *v9; // $v0
  unsigned int v10; // $v0
  char v12[1028]; // [sp+18h] [-404h] BYREF

  memset(v12, 0, 0x400u);
  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "vid");
  v5 = httpd_get_parm(a1, "port");
  if ( !v2 || (v6 = (const char *)nvram_get("wan_itv_en")) != 0 && !strcmp(v6, v2) )
  {
    v7 = 0;
  }
  else
  {
    nvram_set("wan_itv_en", v2);
    v7 = 1;
  }
  if ( !v3 || (v8 = (const char *)nvram_get("wan_itv_vid")) != 0 && !strcmp(v8, v3) )
  {
    if ( !v5 )
      goto LABEL_18;
    v9 = (const char *)nvram_get("wan_itv_port");
    if ( !v9 )
      goto LABEL_10;
  }
  else
  {
    nvram_set("wan_itv_vid", v3);
    if ( !v5 )
    {
LABEL_11:
      jhl_parm_commit(v4);
      jhl_gl_net_restart_timer(1000);
      v10 = snprintf(v12, 4, "{\"code\":4,\"error\":\"\",\"data\":null}");
      goto LABEL_12;
    }
    v9 = (const char *)nvram_get("wan_itv_port");
    v7 = 1;
    if ( !v9 )
    {
LABEL_10:
      nvram_set("wan_itv_port", v5);
      goto LABEL_11;
    }
  }
  if ( strcmp(v9, v5) )
    goto LABEL_10;
LABEL_18:
  if ( v7 )
    goto LABEL_11;
  v10 = snprintf(v12, 4, "{\"code\":0,\"error\":\"\",\"data\":null}");
LABEL_12:
  if ( v10 >= 4 )
    v10 = 3;
  return httpd_cgi_ret(a1, v12, v10, 4);
}
// 43F284: variable 'v4' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

