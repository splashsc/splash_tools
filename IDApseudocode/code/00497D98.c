int __fastcall sub_497D98(int a1)
{
  char *v2; // $s1
  char *v3; // $s2
  char *v4; // $s3
  char *v5; // $s5
  char *v6; // $s4
  char *v7; // $fp
  int v8; // $v0
  const char *v9; // $v0
  int v10; // $v0
  char *v11; // $v0
  uint32_t v12; // $v0
  uint32_t v13; // $v0
  char *v14; // $v1
  const char *v15; // $v0
  int v16; // $t0
  int v17; // $a3
  int v18; // $a2
  int v19; // $a1
  int v21; // $s2
  char *v22; // $s3
  char *v23; // $s1
  const char *v24; // $v0
  const char *v25; // $v0
  char v26[5120]; // [sp+50h] [-28A0h] BYREF
  char v27[5120]; // [sp+1450h] [-14A0h] BYREF
  char *v28[18]; // [sp+2850h] [-A0h] BYREF
  char v29[24]; // [sp+2898h] [-58h] BYREF
  char *v30; // [sp+28B0h] [-40h]
  char *v31; // [sp+28B4h] [-3Ch]
  char *v32; // [sp+28B8h] [-38h]
  char *v33; // [sp+28BCh] [-34h]
  char *v34; // [sp+28C0h] [-30h]
  char *v35; // [sp+28C4h] [-2Ch]
  char *v36; // [sp+28C8h] [-28h]
  char *v37; // [sp+28CCh] [-24h]
  char *v38; // [sp+28D0h] [-20h]
  char *v39; // [sp+28D4h] [-1Ch]
  char *v40; // [sp+28D8h] [-18h]
  char *v41; // [sp+28DCh] [-14h]
  char **v42; // [sp+28E0h] [-10h]
  char *v43; // [sp+28E4h] [-Ch]
  char *v44; // [sp+28E8h] [-8h]

  memset(v27, 0, sizeof(v27));
  v42 = v28;
  memset(v28, 0, sizeof(v28));
  memset(v26, 0, sizeof(v26));
  v2 = httpd_get_parm(a1, "en");
  v31 = httpd_get_parm(a1, "acn");
  v3 = httpd_get_parm(a1, "stip");
  v4 = httpd_get_parm(a1, "endip");
  v32 = httpd_get_parm(a1, "chktm");
  v33 = httpd_get_parm(a1, "chkmax");
  v5 = httpd_get_parm(a1, "only_pppoe");
  v37 = httpd_get_parm(a1, "pap_en");
  v38 = httpd_get_parm(a1, "chap_en");
  v39 = httpd_get_parm(a1, "mschap_en");
  v36 = httpd_get_parm(a1, "mschap2_en");
  v40 = httpd_get_parm(a1, "any_acname");
  v6 = httpd_get_parm(a1, "any_user");
  v30 = httpd_get_parm(a1, "any_user_dq");
  v34 = httpd_get_parm(a1, "dns0");
  v35 = httpd_get_parm(a1, "dns1");
  v41 = (char *)jhl_nv_get_def("dual_lan_mode");
  v7 = httpd_get_parm(a1, "stipv6");
  if ( v7 )
  {
    v44 = "1\"";
    v43 = "1\"";
    v8 = lan_name_get2("ipv6.lan", 0, "pppsrv", 0);
    v9 = (const char *)nvram_get(v8);
    if ( !v9 || strcmp(v9, v7) )
    {
      v10 = lan_name_get2(v44 - 16320, 0, v43 - 16328, 0);
      nvram_set(v10, v7);
    }
  }
  v11 = (char *)nvram_get("pppoeBase");
  if ( !v11 )
    v11 = "";
  strlcpy(v26, v11, 5120);
  split_string(v26, 60, v42, 16);
  if ( !v28[0] )
    v28[0] = "";
  if ( !v28[2] )
    v28[2] = "";
  jhl_parm_get("lan_ifname", v29, 20);
  if ( !v2 || strcmp(v2, "on") )
    v2 = (char *)&off_63F984;
  if ( !v5 || strcmp(v5, "on") )
    v5 = (char *)&off_63F984;
  if ( v31 )
  {
    if ( v3 )
      goto LABEL_18;
  }
  else
  {
    v31 = "Router_PPPoE";
    if ( v3 )
      goto LABEL_18;
  }
  v3 = "10.198.0.1";
LABEL_18:
  if ( StrToIp(v3) )
  {
    if ( v4 )
      goto LABEL_20;
  }
  else
  {
    v3 = "10.198.0.1";
    StrToIp("10.198.0.1");
    if ( v4 )
    {
LABEL_20:
      v12 = StrToIp(v4);
      if ( v12 )
        goto LABEL_21;
      goto LABEL_56;
    }
  }
  v4 = "255.255.255.0";
  v12 = StrToIp("255.255.255.0");
  if ( v12 )
  {
LABEL_21:
    if ( v34 )
      goto LABEL_22;
    goto LABEL_57;
  }
LABEL_56:
  v12 = StrToIp("255.255.255.0");
  v4 = "255.255.255.0";
  if ( v34 )
  {
LABEL_22:
    if ( v35 )
      goto LABEL_23;
    goto LABEL_58;
  }
LABEL_57:
  v34 = "0.0.0.0";
  if ( v35 )
  {
LABEL_23:
    if ( v32 )
      goto LABEL_24;
LABEL_59:
    v32 = "3";
    if ( v33 )
      goto LABEL_25;
    goto LABEL_60;
  }
LABEL_58:
  v35 = "0.0.0.0";
  if ( !v32 )
    goto LABEL_59;
LABEL_24:
  if ( v33 )
    goto LABEL_25;
LABEL_60:
  v33 = "3";
LABEL_25:
  v13 = htonl(v12);
  if ( get_netmask_wei(v13) < 16 )
    StrToIp("255.255.255.0");
  if ( v6 && !strcmp(v6, "on") )
  {
    if ( !v30 )
      v30 = "0";
    v36 = "0";
  }
  else
  {
    if ( !v30 )
      v30 = "0";
    v6 = (char *)&off_63F984;
  }
  sprintf(
    v27,
    "%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s",
    v2,
    v31,
    v3,
    v4,
    v32,
    v33,
    v5,
    v37,
    v38,
    v39,
    v36,
    v40,
    v34,
    v35,
    v6,
    v30);
  if ( strcmp(v2, v28[0]) || strcmp(v3, v28[2]) )
  {
    jhl_parm_set("pppoeBase", v27);
    if ( strcmp(v41, "1") )
      goto LABEL_41;
    v21 = 1;
LABEL_47:
    v22 = httpd_get_parm(a1, "iface_en");
    v23 = httpd_get_parm(a1, "iface_list");
    if ( !v22 || (v24 = (const char *)nvram_get("pppoesrv_iface_en")) != 0 && !strcmp(v24, v22) )
    {
      if ( !v23 )
        goto LABEL_62;
      goto LABEL_51;
    }
    nvram_set("pppoesrv_iface_en", v22);
    ++v21;
    if ( v23 )
    {
LABEL_51:
      v25 = (const char *)nvram_get("pppoesrv_iface_list");
      if ( !v25 || strcmp(v25, v23) )
      {
        nvram_set("pppoesrv_iface_list", v23);
        goto LABEL_41;
      }
LABEL_62:
      pppoe_srv_start("0");
      if ( !v21 )
        goto LABEL_36;
      goto LABEL_42;
    }
LABEL_41:
    pppoe_srv_start("0");
LABEL_42:
    start_rzgl(0);
    goto LABEL_36;
  }
  jhl_parm_set("pppoeBase", v27);
  if ( !strcmp(v41, "1") )
  {
    v21 = 0;
    goto LABEL_47;
  }
  pppoe_srv_start("0");
LABEL_36:
  v14 = v27;
  v15 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v16 = *(_DWORD *)v15;
    v17 = *((_DWORD *)v15 + 1);
    v18 = *((_DWORD *)v15 + 2);
    v19 = *((_DWORD *)v15 + 3);
    v15 += 16;
    *(_DWORD *)v14 = v16;
    *((_DWORD *)v14 + 1) = v17;
    *((_DWORD *)v14 + 2) = v18;
    *((_DWORD *)v14 + 3) = v19;
    v14 += 16;
  }
  while ( v15 != "}" );
  *(_WORD *)v14 = *(_WORD *)v15;
  jhl_parm_commit("}");
  return httpd_cgi_ret(a1, v27, 33, 4);
}
// 63F984: using guessed type void *off_63F984;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81AC: using guessed type int __fastcall get_netmask_wei(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C4: using guessed type int __fastcall lan_name_get2(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A862C: using guessed type int __fastcall StrToIp(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A88E4: using guessed type int __fastcall pppoe_srv_start(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

