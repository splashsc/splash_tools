int __fastcall sub_4C6758(int a1)
{
  char *v2; // $fp
  char *v3; // $s7
  char *v4; // $s6
  int v5; // $a0
  char *v6; // $s2
  int v7; // $v0
  const char *v8; // $v0
  int v9; // $v0
  int v10; // $s3
  int v11; // $v0
  const char *v12; // $v0
  int v13; // $v0
  int v14; // $v0
  const char *v15; // $v0
  int v16; // $v0
  const char *v17; // $s7
  int v18; // $v0
  const char *v19; // $v0
  int v20; // $v0
  int v21; // $v0
  const char *v22; // $v0
  int v23; // $v0
  int v24; // $v0
  const char *v25; // $v0
  int v26; // $v0
  char *v27; // $v1
  const char *v28; // $v0
  int v29; // $t0
  int v30; // $a3
  int v31; // $a2
  int v32; // $a1
  char v34[128]; // [sp+18h] [-90h] BYREF
  char *v35; // [sp+98h] [-10h]
  char *v36; // [sp+9Ch] [-Ch]
  char *v37; // [sp+A0h] [-8h]

  v37 = v34;
  memset(v34, 0, sizeof(v34));
  v2 = httpd_get_parm(a1, "ip");
  v3 = httpd_get_parm(a1, "ra_type");
  v4 = httpd_get_parm(a1, "dhcp_type");
  v36 = httpd_get_parm(a1, "ndp_type");
  v35 = httpd_get_parm(a1, (char *)&off_6508E4);
  v6 = httpd_get_parm(a1, "dns");
  if ( !v2 || (v7 = lan_name_get2("ipv6.lan", 0, "ip", 0), (v8 = (const char *)nvram_get(v7)) != 0) && !strcmp(v8, v2) )
  {
    v10 = 0;
  }
  else
  {
    v9 = lan_name_get2("ipv6.lan", 0, "ip", 0);
    nvram_set(v9, v2);
    v10 = 1;
  }
  if ( v3 )
  {
    v11 = lan_name_get2("ipv6.lan", 0, &unk_4D0FF8, 0);
    v12 = (const char *)nvram_get(v11);
    if ( !v12 || strcmp(v12, v3) )
    {
      v13 = lan_name_get2("ipv6.lan", 0, &unk_4D0FF8, 0);
      nvram_set(v13, v3);
      v10 = 1;
    }
  }
  if ( v4 )
  {
    v14 = lan_name_get2("ipv6.lan", 0, "dhcp", 0);
    v15 = (const char *)nvram_get(v14);
    if ( !v15 || strcmp(v15, v4) )
    {
      v16 = lan_name_get2("ipv6.lan", 0, "dhcp", 0);
      nvram_set(v16, v4);
      v10 = 1;
    }
  }
  v17 = v36;
  if ( v36 )
  {
    v18 = lan_name_get2("ipv6.lan", 0, "ndp", 0);
    v19 = (const char *)nvram_get(v18);
    if ( !v19 || strcmp(v19, v17) )
    {
      v20 = lan_name_get2("ipv6.lan", 0, "ndp", 0);
      nvram_set(v20, v36);
      v10 = 1;
    }
  }
  if ( !v35
    || (v21 = lan_name_get2("ipv6.lan", 0, &off_6508E4, 0), (v22 = (const char *)nvram_get(v21)) != 0)
    && !strcmp(v22, v35) )
  {
    if ( !v6 )
      goto LABEL_30;
    goto LABEL_23;
  }
  v23 = lan_name_get2("ipv6.lan", 0, &off_6508E4, 0);
  nvram_set(v23, v35);
  if ( v6 )
  {
    v10 = 1;
LABEL_23:
    v24 = lan_name_get2("ipv6.lan", 0, "dns", 0);
    v25 = (const char *)nvram_get(v24);
    if ( !v25 || strcmp(v25, v6) )
    {
      v26 = lan_name_get2("ipv6.lan", 0, "dns", 0);
      nvram_set(v26, v6);
      goto LABEL_26;
    }
LABEL_30:
    if ( !v10 )
      goto LABEL_27;
  }
LABEL_26:
  jhl_parm_commit(v5);
  ipv6lan_set_all();
  dhcp6s_restart();
LABEL_27:
  v27 = v37;
  v28 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v29 = *(_DWORD *)v28;
    v30 = *((_DWORD *)v28 + 1);
    v31 = *((_DWORD *)v28 + 2);
    v32 = *((_DWORD *)v28 + 3);
    v28 += 16;
    *(_DWORD *)v27 = v29;
    *((_DWORD *)v27 + 1) = v30;
    *((_DWORD *)v27 + 2) = v31;
    *((_DWORD *)v27 + 3) = v32;
    v27 += 16;
  }
  while ( v28 != "}" );
  *(_WORD *)v27 = *(_WORD *)v28;
  return httpd_cgi_ret(a1, v37, 33, 4);
}
// 4C6C28: variable 'v5' is possibly undefined
// 6508E4: using guessed type void *off_6508E4;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84C4: using guessed type int __fastcall lan_name_get2(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A85FC: using guessed type int dhcp6s_restart(void);
// 6A8630: using guessed type int ipv6lan_set_all(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

