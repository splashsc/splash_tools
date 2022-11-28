int __fastcall sub_45805C(int a1)
{
  int v2; // $v0
  int v3; // $s1
  int v4; // $s4
  int v5; // $s0
  int v6; // $s2
  int v7; // $v0
  char *v8; // $s6
  int v9; // $v0
  const char *v10; // $v0
  int v11; // $v0
  _BYTE *v12; // $v0
  int v13; // $v0
  int i; // $s0
  int v15; // $v0
  const char *v16; // $v0
  int v17; // $v0
  const char *v18; // $v0
  const char *v19; // $s4
  const char *v20; // $s5
  const char *v21; // $s0
  const char *v22; // $s3
  const char *v23; // $v0
  int v24; // $s2
  int v25; // $v0
  int v26; // $a2
  int result; // $v0
  const char *v28; // $v0
  unsigned int v29; // $a2
  char v30[256]; // [sp+28h] [-110h] BYREF
  const char *v31; // [sp+128h] [-10h]
  char *format; // [sp+12Ch] [-Ch]
  char *v33; // [sp+130h] [-8h]

  _mem_malloc(0x200000, "qos_data", 702);
  if ( v2 )
  {
    v3 = v2;
    v4 = sq_file_get_max_wan();
    strcpy((char *)v3, "{\"code\":0,\"error\":\"\",\"data\":{\"wans\":\"");
    qmemcpy((void *)v3, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v3 + 24) = 975331700;
    *(_BYTE *)(v3 + 32) = 110;
    if ( v4 <= 0 )
    {
      v6 = 37;
    }
    else
    {
      v33 = "a";
      v31 = "qos_dk";
      v5 = 0;
      v6 = 37;
      format = "%d|%s<";
      while ( 1 )
      {
        v7 = jhl_nvget("wan_ifname", v5);
        v8 = (char *)nvram_get(v7);
        if ( !v8 )
          v8 = "";
        if ( !*v8 )
          break;
        v9 = jhl_nvget("wan_down", v5);
        v10 = (const char *)nvram_get(v9);
        if ( v10 && !strcmp(v10, "1") || jhl_iface_link_up_check(v8, v5) )
        {
          if ( v4 == ++v5 )
            break;
        }
        else
        {
          v11 = jhl_nvget(v31, v5);
          v12 = (_BYTE *)nvram_get(v11);
          if ( !v12 || !*v12 )
            v12 = v33 + 20488;
          v13 = sprintf((char *)(v3 + v6), format, v5++, v12);
          v6 += v13;
          if ( v4 == v5 )
            break;
        }
      }
    }
    for ( i = 0; i != 5; ++i )
    {
      v15 = jhl_vpnget("vpn_proto", i);
      v16 = (const char *)nvram_get(v15);
      if ( !v16 || strcmp(v16, (const char *)&off_63F984) )
      {
        v17 = jhl_vpnget("vpnqos_dk", i);
        v18 = (const char *)nvram_get(v17);
        if ( !v18 || !*v18 )
          v18 = "on|hi|0|0|75|85|1000|2000|5|10|4|1500|8|16";
        v6 += sprintf((char *)(v3 + v6), "%d|%s<", i + 101, v18);
      }
    }
    v19 = (const char *)nvram_get("qosFip");
    if ( !v19 )
      v19 = "not";
    v20 = (const char *)jhl_nv_get_def("qosDns");
    v21 = (const char *)nvram_get("qosProt");
    if ( !v21 )
      v21 = "not";
    v22 = (const char *)nvram_get("qosInip");
    if ( !v22 )
      v22 = "not";
    v23 = (const char *)jhl_nv_get_def("qos_tmctl_en");
    v24 = v6
        + sprintf(
            (char *)(v3 + v6),
            "\",\"fip\":\"%s\",\"dns\":\"%s\",\"prot\":\"%s\",\"inip\":\"%s\",\"qos_tm_ctl\":\"%s\"",
            v19,
            v20,
            v21,
            v22,
            v23);
    v25 = snprintf((char *)(v3 + v24), 0x200000 - v24, "}}");
    if ( v25 >= 0x200000 - v24 )
      v26 = 0x1FFFFF - v24;
    else
      v26 = v25;
    result = httpd_cgi_ret(a1, (char *)v3, v26 + v24, 8);
  }
  else
  {
    v28 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v29 = snprintf(v30, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
    if ( v29 >= 0x100 )
      v29 = 255;
    result = httpd_cgi_ret(a1, v30, v29, 4);
  }
  return result;
}
// 4580B8: variable 'v2' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

