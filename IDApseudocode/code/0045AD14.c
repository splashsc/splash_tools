int __fastcall sub_45AD14(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s3
  const char *v5; // $s1
  const char *v6; // $s4
  const char *v7; // $s5
  const char *v8; // $s6
  const char *v9; // $fp
  const char *v10; // $v0
  int v11; // $s3
  int v12; // $v0
  int v13; // $a2
  int result; // $v0
  const char *v15; // $v0
  unsigned int v16; // $v0
  char v17[256]; // [sp+40h] [-110h] BYREF
  const char *v18; // [sp+140h] [-10h]
  const char *v19; // [sp+144h] [-Ch]
  const char *v20; // [sp+148h] [-8h]
  const char *v21; // [sp+14Ch] [-4h]

  _mem_malloc(10240, "http_proxy_client_data", 657);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v4 = (const char *)nvram_get("proxy_http_status");
    if ( !v4 )
      v4 = "0";
    v5 = (const char *)nvram_get("proxy_http_port");
    if ( !v5 )
      v5 = "0";
    v6 = (const char *)nvram_get("proxy_http_msg");
    if ( !v6 )
    {
      if ( get_web_language_type(a1) )
        v6 = "This function is not enabled";
      else
        v6 = (const char *)&unk_645EF8;
    }
    v7 = (const char *)jhl_nv_get_only_def("proxy_http_srv");
    v8 = (const char *)jhl_nv_get_def("proxy_email_en");
    v9 = (const char *)jhl_nv_get_def("proxy_email_name");
    v21 = (const char *)jhl_nv_get_def("proxy_email_url");
    v20 = (const char *)jhl_nv_get_def("proxy_email_mode");
    v19 = (const char *)jhl_nv_get_def("proxy_email_time");
    v18 = (const char *)jhl_nv_get_def(&unk_645FA8);
    v10 = (const char *)jhl_nv_get_def(&unk_645FBC);
    v11 = sprintf(
            v3 + 29,
            "\"proxy_http_status\":\"%s\", \"proxy_http_port\":\"%s\",\"proxy_http_msg\":\"%s\",\"proxy_http_server\":\"%"
            "s\",\"enable\":\"%s\",\"name\":\"%s\",\"email\":\"%s\",\"mode\":\"%s\",\"time\":\"%s\",\"hour\":\"%s\",\"pho"
            "ne\":\"%s\",\"only_https\":%d",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v21,
            v20,
            v19,
            v18,
            v10,
            0)
        + 29;
    v12 = snprintf(&v3[v11], 10240 - v11, "}}");
    if ( v12 >= 10240 - v11 )
      v13 = 10239 - v11;
    else
      v13 = v12;
    result = httpd_cgi_ret(a1, v3, v13 + v11, 8);
  }
  else
  {
    v15 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v16 = snprintf(v17, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v15);
    if ( v16 >= 0x100 )
      v16 = 255;
    result = httpd_cgi_ret(a1, v17, v16, 4);
  }
  return result;
}
// 45AD74: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A86F4: using guessed type int __fastcall jhl_nv_get_only_def(_DWORD);

