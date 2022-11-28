int __fastcall sub_4BCC28(int a1)
{
  char *v2; // $s4
  char *v3; // $s3
  int v4; // $a0
  char *v5; // $s1
  const char *v6; // $v0
  int v7; // $s4
  const char *v8; // $v0
  const char *v9; // $v0
  char *v10; // $v1
  const char *v11; // $v0
  int v12; // $t0
  int v13; // $a3
  int v14; // $a2
  int v15; // $a1
  char v17[132]; // [sp+18h] [-84h] BYREF

  memset(v17, 0, 0x80u);
  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "srv_addr");
  v5 = httpd_get_parm(a1, "srv_port");
  if ( !v2 || (v6 = (const char *)nvram_get("sj_en")) != 0 && !strcmp(v6, v2) )
  {
    v7 = 0;
  }
  else
  {
    nvram_set("sj_en", v2);
    v7 = 1;
  }
  if ( !v3 || (v8 = (const char *)nvram_get(&unk_64F814)) != 0 && !strcmp(v8, v3) )
  {
    if ( !v5 )
      goto LABEL_18;
    v9 = (const char *)nvram_get("sj_platform_srv_port");
    if ( !v9 )
      goto LABEL_10;
LABEL_17:
    if ( strcmp(v9, v5) )
      goto LABEL_10;
LABEL_18:
    if ( !v7 )
      goto LABEL_12;
    goto LABEL_11;
  }
  nvram_set(&unk_64F814, v3);
  if ( v5 )
  {
    v9 = (const char *)nvram_get("sj_platform_srv_port");
    v7 = 1;
    if ( !v9 )
    {
LABEL_10:
      nvram_set("sj_platform_srv_port", v5);
      goto LABEL_11;
    }
    goto LABEL_17;
  }
LABEL_11:
  jhl_parm_commit(v4);
  exec_service("wys_sj-restart");
LABEL_12:
  v10 = v17;
  v11 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v12 = *(_DWORD *)v11;
    v13 = *((_DWORD *)v11 + 1);
    v14 = *((_DWORD *)v11 + 2);
    v15 = *((_DWORD *)v11 + 3);
    v11 += 16;
    *(_DWORD *)v10 = v12;
    *((_DWORD *)v10 + 1) = v13;
    *((_DWORD *)v10 + 2) = v14;
    *((_DWORD *)v10 + 3) = v15;
    v10 += 16;
  }
  while ( v11 != "}" );
  *(_WORD *)v10 = *(_WORD *)v11;
  return httpd_cgi_ret(a1, v17, 33, 4);
}
// 4BCDC8: variable 'v4' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

