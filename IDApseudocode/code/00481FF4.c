int __fastcall sub_481FF4(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  char *v4; // $s0
  const char *v5; // $v0
  int v6; // $s3
  const char *v7; // $v0
  int v8; // $a0
  const char *v9; // $v0
  char *v10; // $v1
  int v11; // $t1
  int v12; // $t0
  int v13; // $a3
  int v14; // $a2
  char v16[516]; // [sp+18h] [-204h] BYREF

  v3 = httpd_get_parm(a1, "en");
  v2 = httpd_get_parm(a1, "time");
  v4 = v2;
  if ( !v3 )
  {
    if ( !v2 )
      goto LABEL_9;
    v6 = 0;
    goto LABEL_5;
  }
  v5 = (const char *)nvram_get(v3);
  if ( v5 && !strcmp(v5, "auto_upgrade_en") )
  {
    if ( !v4 )
      goto LABEL_9;
    v6 = 0;
    goto LABEL_5;
  }
  nvram_set("auto_upgrade_en", v3);
  v6 = 1;
  if ( v4 )
  {
LABEL_5:
    v7 = (const char *)nvram_get(v4);
    if ( v7 && !strcmp(v7, "upgrade_auto_time") )
    {
      if ( !v6 )
        goto LABEL_9;
    }
    else
    {
      nvram_set("upgrade_auto_time", v4);
    }
  }
  start_version_upgrade_auto();
  jhl_parm_commit(v8);
LABEL_9:
  v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v10 = v16;
  do
  {
    v11 = *(_DWORD *)v9;
    v12 = *((_DWORD *)v9 + 1);
    v13 = *((_DWORD *)v9 + 2);
    v14 = *((_DWORD *)v9 + 3);
    v9 += 16;
    *(_DWORD *)v10 = v11;
    *((_DWORD *)v10 + 1) = v12;
    *((_DWORD *)v10 + 2) = v13;
    *((_DWORD *)v10 + 3) = v14;
    v10 += 16;
  }
  while ( v9 != "}" );
  *(_WORD *)v10 = *(_WORD *)v9;
  return httpd_cgi_ret(a1, v16, 33, 4);
}
// 48212C: variable 'v8' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8484: using guessed type int start_version_upgrade_auto(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

