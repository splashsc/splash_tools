int __fastcall sub_4AF1A0(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s6
  const char *v5; // $s7
  const char *v6; // $s1
  const char *v7; // $s2
  const char *v8; // $s4
  const char *v9; // $s5
  const char *v10; // $v1
  const char *v11; // $v0
  int v12; // $s1
  const char *v13; // $v0
  int v14; // $s1
  int v15; // $v0
  int v16; // $a2
  int result; // $v0
  const char *v18; // $v0
  unsigned int v19; // $v0
  char v20[256]; // [sp+40h] [-110h] BYREF
  const char *v21; // [sp+140h] [-10h]
  const char *v22; // [sp+144h] [-Ch]
  const char *v23; // [sp+148h] [-8h]
  const char *v24; // [sp+14Ch] [-4h]

  _mem_malloc(10240, "wan_3g_data", 823);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\"", 20);
    v4 = (const char *)jhl_nv_get_def("wan_3g_enable");
    v5 = (const char *)jhl_nv_get_def("wan_3g_isp");
    v6 = (const char *)nvram_get("wan_3g_apn");
    if ( !v6 )
      v6 = "";
    v7 = (const char *)nvram_get("wan_3g_dial");
    if ( !v7 )
      v7 = "";
    v8 = (const char *)nvram_get("wan_3g_pin");
    if ( !v8 )
      v8 = "";
    v9 = (const char *)nvram_get("wan_3g_user");
    if ( !v9 )
      v9 = "";
    v10 = (const char *)nvram_get("wan_3g_pass");
    if ( !v10 )
      v10 = "";
    v24 = v10;
    v23 = (const char *)jhl_nv_get_def("wan_3g_connect_mode");
    v22 = (const char *)jhl_nv_get_def("wan_3g_enable_dk");
    v21 = (const char *)jhl_nv_get_def("g3_warn_bytes");
    v11 = (const char *)jhl_nv_get_def("g3_warn_time");
    v12 = sprintf(
            v3 + 29,
            "\"wan_3g_enable\":\"%s\",\"wan_3g_isp\":\"%s\",\"wan_3g_apn\":\"%s\",\"wan_3g_dial\":\"%s\",\"wan_3g_pin\":\""
            "%s\",\"wan_3g_user\":\"%s\",\"wan_3g_pass\":\"%s\",\"wan_3g_connect_mode\":\"%s\",\"wan_3g_enable_dk\":\"%s\""
            ",\"g3_warn_bytes\":\"%s\",\"g3_warn_time\":\"%s\"",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v24,
            v23,
            v22,
            v21,
            v11)
        + 29;
    v13 = (const char *)nvram_get("wan_3g_user_mode");
    if ( !v13 )
      v13 = "";
    v14 = v12 + sprintf(&v3[v12], ",\"user_mode\":\"%s\"", v13);
    v15 = snprintf(&v3[v14], 10240 - v14, "}}");
    if ( v15 >= 10240 - v14 )
      v16 = 10239 - v14;
    else
      v16 = v15;
    result = httpd_cgi_ret(a1, v3, v16 + v14, 8);
  }
  else
  {
    v18 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v19 = snprintf(v20, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v18);
    if ( v19 >= 0x100 )
      v19 = 255;
    result = httpd_cgi_ret(a1, v20, v19, 4);
  }
  return result;
}
// 4AF200: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

