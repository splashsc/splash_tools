int __fastcall sub_48295C(int a1)
{
  char *v2; // $s1
  char *v3; // $s7
  char *v4; // $s5
  char *v5; // $s6
  const char *v6; // $v0
  int v7; // $s4
  const char *v8; // $v0
  const char *v9; // $v0
  const char *v10; // $v0
  int v11; // $a0
  const char **v12; // $v1
  const char *v13; // $v0
  const char *v14; // $t0
  const char *v15; // $a3
  const char *v16; // $a2
  const char *v17; // $a1
  const char *v19; // [sp+18h] [-204h] BYREF
  char *v20; // [sp+1Ch] [-200h]
  char *v21; // [sp+20h] [-1FCh]
  int v22; // [sp+24h] [-1F8h]

  v2 = httpd_get_parm(a1, "time_upgrade_en");
  v3 = httpd_get_parm(a1, "time_upgrade_bb");
  v4 = httpd_get_parm(a1, "time_upgrade_path");
  v5 = httpd_get_parm(a1, "time");
  if ( !v2 || (v6 = (const char *)nvram_get("time_upgrade_en")) != 0 && !strcmp(v6, v2) )
  {
    v7 = 0;
  }
  else
  {
    nvram_set("time_upgrade_en", v2);
    v7 = 1;
  }
  if ( v3 )
  {
    v8 = (const char *)nvram_get("time_upgrade_bb");
    if ( !v8 || strcmp(v8, v3) )
    {
      nvram_set("time_upgrade_bb", v3);
      v7 = 1;
    }
  }
  if ( !v4 || (v9 = (const char *)nvram_get("time_upgrade_path")) != 0 && !strcmp(v9, v4) )
  {
    if ( !v5 )
      goto LABEL_26;
  }
  else
  {
    nvram_set("time_upgrade_path", v4);
    if ( !v5 )
      goto LABEL_17;
    v7 = 1;
  }
  v10 = (const char *)nvram_get("time_upgrade_time");
  if ( v10 && !strcmp(v10, v5) )
  {
LABEL_26:
    if ( !v7 )
      goto LABEL_21;
    goto LABEL_17;
  }
  nvram_set("time_upgrade_time", v5);
LABEL_17:
  v19 = "time_version_upgrade_del.sh";
  v20 = 0;
  eval(&v19, 0, 0, 0);
  if ( v2 && J_atoi(v2) == 1 )
  {
    v19 = "time_version_upgrade_add.sh";
    v20 = v5;
    v21 = v4;
    v22 = 0;
    eval(&v19, 0, 0, 0);
  }
  jhl_parm_commit(v11);
LABEL_21:
  v12 = &v19;
  v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v14 = *(const char **)v13;
    v15 = (const char *)*((_DWORD *)v13 + 1);
    v16 = (const char *)*((_DWORD *)v13 + 2);
    v17 = (const char *)*((_DWORD *)v13 + 3);
    v13 += 16;
    *v12 = v14;
    v12[1] = v15;
    v12[2] = v16;
    v12[3] = v17;
    v12 += 4;
  }
  while ( v13 != "}" );
  *(_WORD *)v12 = *(_WORD *)v13;
  return httpd_cgi_ret(a1, (char *)&v19, 33, 4);
}
// 482BC4: variable 'v11' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

