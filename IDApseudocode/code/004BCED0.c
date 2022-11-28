int __fastcall sub_4BCED0(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s2
  const char *v5; // $s4
  const char *v6; // $s5
  const char *v7; // $s6
  const char *v8; // $s7
  const char *v9; // $fp
  const char *v10; // $v1
  const char *v11; // $v0
  int v12; // $s1
  const char *v13; // $s4
  const char *v14; // $s2
  const char *v15; // $s5
  const char *v16; // $v0
  int v17; // $s1
  int v18; // $s1
  const char *v19; // $v0
  int v20; // $s1
  int v21; // $v0
  int v22; // $v0
  int v23; // $s1
  int v24; // $s1
  int v25; // $v0
  int v26; // $a2
  int result; // $v0
  const char *v28; // $v0
  unsigned int v29; // $v0
  char v30[1024]; // [sp+38h] [-408h] BYREF
  const char *v31; // [sp+438h] [-8h]
  char *v32; // [sp+43Ch] [-4h]

  _mem_malloc(10240, "wayos_ac_server_data", 23);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\",\"da", 24);
    v4 = (const char *)jhl_nv_get_def("ac_server_enable");
    v5 = (const char *)jhl_nv_get_def("ac_server_mode");
    v6 = (const char *)jhl_nv_get_def("lan_gateway");
    v7 = (const char *)jhl_nv_get_def("lan_get_dns");
    v8 = (const char *)jhl_nv_get_def("lan_ipaddr");
    v9 = (const char *)jhl_nv_get_def("acserver_http_port");
    v10 = (const char *)nvram_get("ac_server_debug");
    if ( !v10 )
      v10 = "0";
    v32 = v3 + 29;
    v31 = v10;
    v11 = (const char *)jhl_nv_get_def("lan_ipaddr");
    v12 = sprintf(
            v3 + 29,
            "\"enable\":\"%s\",\"mode\":\"%s\",\"lan_gateway\":\"%s\",\"lan_dns\":\"%s\",\"server_addr\":\"%s://%s:%s\",\""
            "debug\":\"%s\",\"lan_ipaddr\":\"%s\"",
            v4,
            v5,
            v6,
            v7,
            "http",
            v8,
            v9,
            v31,
            v11)
        + 29;
    v13 = (const char *)nvram_get("proxy_ac_status");
    if ( !v13 )
      v13 = "0";
    v14 = (const char *)nvram_get("proxy_ac_port");
    if ( !v14 )
      v14 = "0";
    v15 = (const char *)nvram_get("proxy_ac_msg");
    if ( !v15 )
    {
      if ( get_web_language_type(a1) )
        v15 = "This function is not enabled";
      else
        v15 = (const char *)&unk_645EF8;
    }
    v16 = (const char *)jhl_nv_get_only_def("proxy_http_srv");
    v17 = v12
        + sprintf(
            &v3[v12],
            ",\"proxy_status\":\"%s\", \"proxy_port\":\"%s\",\"proxy_msg\":\"%s\",\"proxy_server\":\"%s\"",
            v13,
            v14,
            v15,
            v16);
    v18 = v17 + sprintf(&v3[v17], ",\"proxy_en\":\"%d\"", 1);
    v19 = (const char *)nvram_get("ac_server_run");
    if ( !v19 )
      v19 = "0";
    v20 = v18 + sprintf(&v3[v18], ",\"state\":\"%s\"", v19);
    v21 = nvram_get_int("ac_server_type");
    v23 = v20 + sprintf(&v3[v20], ",\"show_merge\":%d,\"server_type\":%d", 0, v21);
    v22 = get_log_data_in_sometime(27, v30, 1024);
    v24 = v23 + sprintf(&v3[v23], ",\"arp_err\":%d", v22 != 0);
    v25 = snprintf(&v3[v24], 10240 - v24, "}}");
    if ( v25 >= 10240 - v24 )
      v26 = 10239 - v24;
    else
      v26 = v25;
    result = httpd_cgi_ret(a1, v3, v26 + v24, 8);
  }
  else
  {
    v28 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v29 = snprintf(v30, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
    if ( v29 >= 0x100 )
      v29 = 255;
    result = httpd_cgi_ret(a1, v30, v29, 4);
  }
  return result;
}
// 4BCF30: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A86F4: using guessed type int __fastcall jhl_nv_get_only_def(_DWORD);
// 6A8730: using guessed type int __fastcall get_log_data_in_sometime(_DWORD, _DWORD, _DWORD);

