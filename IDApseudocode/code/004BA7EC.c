int __fastcall sub_4BA7EC(int a1)
{
  char *v2; // $s3
  char *v3; // $s2
  char *v4; // $s0
  const char *v5; // $v0
  int v6; // $s3
  const char *v7; // $v0
  const char *v8; // $v0
  int v9; // $a0
  const char *v10; // $v0
  char *v11; // $v1
  int v12; // $t1
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  char v17[1024]; // [sp+18h] [-400h] BYREF

  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "addr");
  v4 = httpd_get_parm(a1, "port");
  if ( !v2 || (v5 = (const char *)nvram_get("sj_ctrl_en")) != 0 && !strcmp(v5, v2) )
  {
    v6 = 0;
  }
  else
  {
    nvram_set("sj_ctrl_en", v2);
    v6 = 1;
  }
  if ( !v3 || (v7 = (const char *)nvram_get("sj_ctrl_addr")) != 0 && !strcmp(v7, v3) )
  {
    if ( !v4 )
      goto LABEL_18;
    v8 = (const char *)nvram_get("sj_ctrl_port");
    if ( !v8 )
      goto LABEL_10;
LABEL_17:
    if ( strcmp(v8, v4) )
      goto LABEL_10;
LABEL_18:
    if ( !v6 )
      goto LABEL_12;
    goto LABEL_11;
  }
  nvram_set("sj_ctrl_addr", v3);
  if ( v4 )
  {
    v8 = (const char *)nvram_get("sj_ctrl_port");
    v6 = 1;
    if ( !v8 )
    {
LABEL_10:
      nvram_set("sj_ctrl_port", v4);
      goto LABEL_11;
    }
    goto LABEL_17;
  }
LABEL_11:
  restart_shenji_ctrl();
  jhl_parm_commit(v9);
LABEL_12:
  v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v11 = v17;
  do
  {
    v12 = *(_DWORD *)v10;
    v13 = *((_DWORD *)v10 + 1);
    v14 = *((_DWORD *)v10 + 2);
    v15 = *((_DWORD *)v10 + 3);
    v10 += 16;
    *(_DWORD *)v11 = v12;
    *((_DWORD *)v11 + 1) = v13;
    *((_DWORD *)v11 + 2) = v14;
    *((_DWORD *)v11 + 3) = v15;
    v11 += 16;
  }
  while ( v10 != "}" );
  *(_WORD *)v11 = *(_WORD *)v10;
  return httpd_cgi_ret(a1, v17, 33, 4);
}
// 4BA97C: variable 'v9' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A88A8: using guessed type int restart_shenji_ctrl(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

