int __fastcall sub_439B9C(int a1)
{
  int v2; // $s5
  _BOOL4 v3; // $s2
  int v4; // $v0
  char *v5; // $s0
  int v6; // $v0
  int v7; // $s4
  int v8; // $s1
  int v9; // $v0
  int v10; // $s4
  int v11; // $v0
  int v12; // $s2
  int v13; // $s1
  int v14; // $v0
  const char *v15; // $v0
  int v16; // $v0
  _BYTE *v17; // $v0
  int v18; // $v0
  char *v19; // $a0
  int v20; // $v0
  int v21; // $s1
  int v22; // $s2
  int v23; // $v0
  int v24; // $s1
  char *v25; // $a0
  int v26; // $v0
  int v27; // $s1
  const char *v28; // $v0
  int v29; // $v0
  int v30; // $s1
  const char *v31; // $v0
  int v32; // $v0
  int v33; // $s1
  int v34; // $v0
  int v35; // $a2
  int result; // $v0
  const char *v37; // $v0
  unsigned int v38; // $v0
  char v39[128]; // [sp+20h] [-88h] BYREF
  int v40; // [sp+A0h] [-8h]

  memset(v39, 0, sizeof(v39));
  v2 = sq_file_get_max_wan();
  if ( nvram_get_int("mqtt_cli_enable") || nvram_get_int("wysz_wan_out_en") )
    v3 = 1;
  else
    v3 = nvram_get_int("ac_server_128_en") != 0;
  _mem_malloc(0x200000, "sdwan_hi_data", 1462);
  v5 = (char *)v4;
  if ( v4 )
  {
    strcpy((char *)v4, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v4, "{\"code\":0,\"error", 16);
    *(_DWORD *)(v4 + 24) = 975331700;
    v6 = snprintf((char *)(v4 + 29), 2097123, "\"en\":\"%d\"", v3);
    if ( v6 >= 2097123 )
      v6 = 2097122;
    v7 = v6 + 29;
    v8 = 0x200000 - (v6 + 29);
    v9 = snprintf(&v5[v6 + 29], v8, (char *)&dword_6448E0);
    if ( v9 >= v8 )
      v9 = 0x1FFFFF - v7;
    v10 = v9 + v7 + get_wans_data(&v5[v9 + v7], 0x200000 - (v9 + v7));
    v11 = snprintf(&v5[v10], 0x200000 - v10, ",\"vpns\":[ ");
    if ( v11 >= 0x200000 - v10 )
      v11 = 0x1FFFFF - v10;
    v12 = v11 + v10;
    if ( v2 > 0 )
    {
      v13 = 0;
      do
      {
        v14 = jhl_vpnget("vpn_proto", v13);
        v15 = (const char *)nvram_get(v14);
        if ( !v15 || strcmp(v15, (const char *)&off_63F984) )
        {
          v16 = jhl_vpnget("vpn_proto", v13);
          v17 = (_BYTE *)nvram_get(v16);
          if ( !v17 || *v17 )
          {
            v40 = 0x200000;
            v18 = snprintf(&v5[v12], 0x200000 - v12, "{\"iface\":%d,\"id\":%d},", v13, v13 + 101);
            if ( v18 >= 0x200000 - v12 )
              v18 = v40 - 1 - v12;
            v12 += v18;
          }
        }
        ++v13;
      }
      while ( v13 != 5 && v2 != v13 );
    }
    v19 = &v5[v12];
    if ( v5[v12 - 1] == 44 )
      v19 = &v5[--v12];
    v20 = snprintf(v19, 0x200000 - v12, &byte_6445A0);
    if ( v20 >= 0x200000 - v12 )
      v20 = 0x1FFFFF - v12;
    v21 = v12 + v20;
    v22 = 0x200000 - (v12 + v20);
    v23 = snprintf(&v5[v21], v22, ",\"sdwans\":[");
    if ( v23 >= v22 )
      v23 = 0x1FFFFF - v21;
    v24 = v23 + v21 + shared_get_sdwans_data(&v5[v23 + v21], 0x200000 - (v23 + v21));
    v25 = &v5[v24];
    if ( v5[v24 - 1] == 44 )
      v25 = &v5[--v24];
    v26 = snprintf(v25, 0x200000 - v24, &byte_6445A0);
    if ( v26 >= 0x200000 - v24 )
      v26 = 0x1FFFFF - v24;
    v27 = v24 + v26;
    v28 = (const char *)nvram_get("ssid_mr_rule");
    if ( !v28 )
      v28 = "[]";
    v29 = snprintf(&v5[v27], 0x200000 - v27, ",\"ssid_mr_rule\":%s", v28);
    if ( v29 >= 0x200000 - v27 )
      v29 = 0x1FFFFF - v27;
    v30 = v29 + v27;
    v31 = (const char *)nvram_get("ssid_mr_rule_5g");
    if ( !v31 )
      v31 = "[]";
    v32 = snprintf(&v5[v30], 0x200000 - v30, ",\"ssid_mr_rule_5g\":%s", v31);
    if ( v32 >= 0x200000 - v30 )
      v32 = 0x1FFFFF - v30;
    v33 = v32 + v30;
    v34 = snprintf(&v5[v33], 0x200000 - v33, "}}");
    if ( v34 >= 0x200000 - v33 )
      v35 = 0x1FFFFF - v33;
    else
      v35 = v34;
    result = httpd_cgi_ret(a1, v5, v35 + v33, 8);
  }
  else
  {
    v37 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v38 = snprintf(v39, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v37);
    if ( v38 >= 0x80 )
      v38 = 127;
    result = httpd_cgi_ret(a1, v39, v38, 4);
  }
  return result;
}
// 439C58: variable 'v4' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6448E0: using guessed type int dword_6448E0;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8380: using guessed type int __fastcall shared_get_sdwans_data(_DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

