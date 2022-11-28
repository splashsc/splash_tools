int __fastcall sub_47481C(int a1)
{
  char *v2; // $s2
  char *v3; // $s4
  char *v4; // $s0
  char *v5; // $s1
  const char *v6; // $v0
  int v7; // $s2
  const char *v8; // $v0
  const char *v9; // $v0
  const char *v10; // $v0
  int v11; // $a0
  const char *v12; // $v0
  const char *v13; // $v0
  char *v14; // $v1
  int v15; // $t1
  int v16; // $t0
  int v17; // $a3
  int v18; // $a2
  char v20[1028]; // [sp+18h] [-404h] BYREF

  v2 = httpd_get_parm(a1, "fip");
  v3 = httpd_get_parm(a1, "dns");
  v4 = httpd_get_parm(a1, "host");
  v5 = httpd_get_parm(a1, (char *)&off_646724);
  if ( !v2 )
    goto LABEL_33;
  if ( (*v2 & 0xDF) == 0 )
    v2 = "";
  v6 = (const char *)nvram_get("rzglFip");
  if ( v6 && !strcmp(v6, v2) )
  {
LABEL_33:
    v7 = 0;
  }
  else
  {
    jhl_parm_set("rzglFip", v2);
    v7 = 1;
  }
  if ( v4 )
  {
    if ( (*v4 & 0xDF) == 0 )
      v4 = "";
    v8 = (const char *)nvram_get("rzglDns");
    if ( v8 && v3 && !strcmp(v8, v3) )
    {
      if ( !v5 )
      {
        nvram_get("rzglMac");
LABEL_23:
        jhl_parm_set("rzglMac", v5);
        goto LABEL_24;
      }
      goto LABEL_15;
    }
    jhl_parm_set("rzglDns", v3);
    v7 = 1;
  }
  if ( !v5 )
    goto LABEL_25;
LABEL_15:
  if ( (*v5 & 0xDF) == 0 )
    v5 = "";
  v9 = (const char *)nvram_get("rzglHost");
  if ( v9 && v4 && !strcmp(v9, v4) )
  {
LABEL_25:
    if ( v3 )
    {
      v12 = (const char *)nvram_get("rzglMac");
      if ( !v12 || !v5 || strcmp(v12, v5) )
        goto LABEL_23;
    }
    goto LABEL_29;
  }
  jhl_parm_set("rzglHost", v4);
  if ( v3 )
  {
    v10 = (const char *)nvram_get("rzglMac");
    if ( !v10 )
      goto LABEL_23;
    v7 = 1;
    if ( strcmp(v10, v5) )
      goto LABEL_23;
LABEL_29:
    if ( !v7 )
      goto LABEL_30;
  }
LABEL_24:
  start_rzgl(1);
  restart_third_rzgl();
  jhl_parm_commit(v11);
LABEL_30:
  v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v14 = v20;
  do
  {
    v15 = *(_DWORD *)v13;
    v16 = *((_DWORD *)v13 + 1);
    v17 = *((_DWORD *)v13 + 2);
    v18 = *((_DWORD *)v13 + 3);
    v13 += 16;
    *(_DWORD *)v14 = v15;
    *((_DWORD *)v14 + 1) = v16;
    *((_DWORD *)v14 + 2) = v17;
    *((_DWORD *)v14 + 3) = v18;
    v14 += 16;
  }
  while ( v13 != "}" );
  *(_WORD *)v14 = *(_WORD *)v13;
  return httpd_cgi_ret(a1, v20, 33, 4);
}
// 474AA8: variable 'v11' is possibly undefined
// 646724: using guessed type void *off_646724;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8514: using guessed type int restart_third_rzgl(void);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

