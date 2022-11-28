int __fastcall sub_436A40(int a1)
{
  char *v2; // $s2
  char *v3; // $s1
  int v4; // $s2
  _BYTE *v5; // $v0
  int v6; // $a0
  _BYTE *v7; // $v0
  int v8; // $s3
  int *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  unsigned int v15; // $a2
  int v17; // $s1
  char *v18; // $v0
  const char *v19; // $v0
  int v20[257]; // [sp+20h] [-404h] BYREF

  v2 = httpd_get_parm(a1, "H323_en");
  v3 = httpd_get_parm(a1, "sip_en");
  if ( v2 && strcmp(v2, "undefined") )
  {
    nvram_set("h323_enable", v2);
    v4 = 1;
  }
  else
  {
    v4 = 0;
  }
  if ( v3 && strcmp(v3, "undefined") )
  {
    nvram_set("sip_enable", v3);
    v4 = 1;
  }
  if ( save_variables(a1, 0) )
  {
    v5 = (_BYTE *)jhl_nv_get_def("router_domain");
    if ( v5 && *v5 )
    {
      dns_url_del(v5);
      if ( !save_variables(a1, 1) )
      {
LABEL_11:
        if ( !v4 )
          goto LABEL_12;
        goto LABEL_21;
      }
    }
    else if ( !save_variables(a1, 1) )
    {
      goto LABEL_11;
    }
LABEL_21:
    jhl_parm_commit(v6);
    set_host_domain_name();
LABEL_12:
    if ( nvram_get_int("billing_en") == 1 && nvram_get_int("mqtt_cbg_settlement_mode") == 1 )
    {
      nvram_reset_def("router_domain");
      puts("billing enabled and settlement_mode is 1, can not modify router domain");
    }
    v7 = (_BYTE *)jhl_nv_get_def("router_domain");
    v8 = (int)v7;
    if ( v7 && *v7 )
      dns_url_add(v7, 0, 1);
    v20[0] = (int)"wys";
    v20[1] = (int)"router_domain";
    v20[2] = (int)"set";
    v20[3] = v8;
    v20[4] = 0;
    eval(v20, 0, 0, 0);
    v9 = v20;
    v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v11 = *(_DWORD *)v10;
      v12 = *((_DWORD *)v10 + 1);
      v13 = *((_DWORD *)v10 + 2);
      v14 = *((_DWORD *)v10 + 3);
      v10 += 16;
      *v9 = v11;
      v9[1] = v12;
      v9[2] = v13;
      v9[3] = v14;
      v9 += 4;
    }
    while ( v10 != "}" );
    v15 = 33;
    *(_WORD *)v9 = *(_WORD *)v10;
    return httpd_cgi_ret(a1, (char *)v20, v15, 4);
  }
  v17 = *(unsigned __int8 *)(a1 + 210102);
  v18 = resmsg_get();
  v19 = (const char *)_GET_LANG_TEXT(12, v17, v18);
  v15 = snprintf((char *)v20, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
  if ( v15 >= 0x400 )
    v15 = 1023;
  return httpd_cgi_ret(a1, (char *)v20, v15, 4);
}
// 436CA0: variable 'v6' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E0: using guessed type int __fastcall nvram_reset_def(_DWORD);
// 6A8410: using guessed type int set_host_domain_name(void);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8548: using guessed type int __fastcall dns_url_add(_DWORD, _DWORD, _DWORD);
// 6A8884: using guessed type int __fastcall dns_url_del(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

