int __fastcall sub_48BF9C(int a1)
{
  char *v1; // $v0
  char *v3; // $s1
  char *v4; // $s2
  char *v5; // $fp
  char *v6; // $s7
  char *v7; // $s6
  char *v8; // $s5
  int v9; // $a0
  char *v10; // $v1
  const char *v11; // $v0
  int v12; // $t0
  int v13; // $a3
  int v14; // $a2
  int v15; // $a1
  unsigned int v16; // $a2
  const char *v17; // $v0
  const char *v19; // $v0
  char v20[1024]; // [sp+20h] [-408h] BYREF
  char *v21; // [sp+420h] [-8h]

  v1 = httpd_get_parm(a1, "opt");
  if ( v1 && !strcmp(v1, "enable") )
  {
    v3 = httpd_get_parm(a1, "enable");
    v4 = httpd_get_parm(a1, "psk_key");
    v21 = httpd_get_parm(a1, "start_ip");
    v5 = httpd_get_parm(a1, "end_ip");
    v6 = httpd_get_parm(a1, "port");
    v7 = httpd_get_parm(a1, "dns1");
    v8 = httpd_get_parm(a1, "dns2");
    nvram_set("ipsec_l2tp_enable", v3);
    nvram_set("ipsec_l2tp_psk_key", v4);
    nvram_set("ipsec_mode", "l2tp");
    nvram_set("ipsec_road_enable", "0");
    nvram_set("ipsec_net_enable", "0");
    nvram_set("ipsec_l2tp_cli_enable", "0");
    nvram_set("l2tpd_en", v3);
    nvram_set("l2tpd_stip", v21);
    nvram_set("l2tpd_endip", v5);
    nvram_set("l2tpd_port", v6);
    nvram_set("l2tpd_dns1", v7);
    nvram_set("l2tpd_dns2", v8);
    jhl_stop_l2tpd_srv();
    if ( !strcmp(v3, "1") )
    {
      jhl_vpnclient_stop(0);
      jhl_start_l2tpd_srv();
    }
    else
    {
      v19 = (const char *)nvram_get("ipsec_mode");
      if ( v19 && !strcmp(v19, "l2tp") )
        nvram_set("ipsec_mode", "none");
    }
    jhl_setwanxx();
    jhl_parm_commit(v9);
    schedule_ipsec(1, 0);
    v10 = v20;
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
    v16 = 33;
    *(_WORD *)v10 = *(_WORD *)v11;
  }
  else
  {
    v17 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    v16 = snprintf(v20, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
    if ( v16 >= 0x400 )
      v16 = 1023;
  }
  return httpd_cgi_ret(a1, v20, v16, 4);
}
// 48C2B4: variable 'v9' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81F0: using guessed type int jhl_stop_l2tpd_srv(void);
// 6A8210: using guessed type int jhl_start_l2tpd_srv(void);
// 6A82B8: using guessed type int jhl_setwanxx(void);
// 6A82F0: using guessed type int __fastcall jhl_vpnclient_stop(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8724: using guessed type int __fastcall schedule_ipsec(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

