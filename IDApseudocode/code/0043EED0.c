int __fastcall sub_43EED0(int a1)
{
  char *v2; // $v0
  char *v3; // $s3
  const char *v4; // $s0
  const char *v5; // $v0
  int v6; // $s4
  const char *v7; // $v0
  int v8; // $a0
  char *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  char v16[128]; // [sp+18h] [-80h] BYREF

  memset(v16, 0, sizeof(v16));
  v3 = httpd_get_parm(a1, "mode");
  v2 = httpd_get_parm(a1, "ips");
  v4 = v2;
  if ( !v3 )
  {
    if ( !v2 )
      goto LABEL_9;
    v6 = 0;
    goto LABEL_5;
  }
  v5 = (const char *)nvram_get("igmp_snooping_mode");
  if ( v5 && !strcmp(v5, v3) )
  {
    if ( !v4 )
      goto LABEL_9;
    v6 = 0;
    goto LABEL_5;
  }
  nvram_set("igmp_snooping_mode", v3);
  v6 = 1;
  if ( v4 )
  {
LABEL_5:
    v7 = (const char *)nvram_get("igmp_snooping_ips");
    if ( v7 && !strcmp(v7, v4) )
    {
      if ( !v6 )
        goto LABEL_9;
    }
    else
    {
      nvram_set("igmp_snooping_ips", v4);
    }
  }
  start_igmp_snooping();
  jhl_parm_commit(v8);
LABEL_9:
  v9 = v16;
  v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v11 = *(_DWORD *)v10;
    v12 = *((_DWORD *)v10 + 1);
    v13 = *((_DWORD *)v10 + 2);
    v14 = *((_DWORD *)v10 + 3);
    v10 += 16;
    *(_DWORD *)v9 = v11;
    *((_DWORD *)v9 + 1) = v12;
    *((_DWORD *)v9 + 2) = v13;
    *((_DWORD *)v9 + 3) = v14;
    v9 += 16;
  }
  while ( v10 != "}" );
  *(_WORD *)v9 = *(_WORD *)v10;
  return httpd_cgi_ret(a1, v16, 33, 4);
}
// 43F028: variable 'v8' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8760: using guessed type int start_igmp_snooping(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

