int __fastcall proxy_client_data(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s6
  const char *v5; // $s1
  const char *v6; // $s3
  const char *v7; // $s4
  const char *v8; // $s7
  const char *v9; // $s5
  const char *v10; // $v0
  int v11; // $s3
  int v12; // $v0
  int v13; // $a2
  int result; // $v0
  const char *v15; // $v0
  unsigned int v16; // $v0
  char v17[256]; // [sp+30h] [-100h] BYREF

  _mem_malloc(10240, "proxy_client_data", 870);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v4 = (const char *)nvram_get("proxy_en");
    if ( !v4 )
      v4 = "0";
    v5 = (const char *)nvram_get("proxy_srv");
    if ( !v5 )
      v5 = "";
    v6 = (const char *)nvram_get("proxy_srvport");
    if ( !v6 )
      v6 = "";
    v7 = (const char *)nvram_get("proxy_port");
    if ( !v7 )
      v7 = "";
    v8 = (const char *)nvram_get("proxy_msg");
    if ( !v8 )
    {
      if ( get_web_language_type(a1) )
        v8 = "This function is not enabled";
      else
        v8 = (const char *)&unk_645EF8;
    }
    v9 = (const char *)nvram_get("proxy_lanip");
    if ( !v9 )
      v9 = "";
    v10 = (const char *)nvram_get("proxy_lanport");
    if ( !v10 )
      v10 = "";
    v11 = sprintf(
            v3 + 29,
            "\"proxy_en\":%s,\"proxy_srv\":\"%s\",\"proxy_srvport\":%s,\"proxy_port\":\"%s\",\"proxy_msg\":\"%s\",\"proxy"
            "_lanip\":\"%s\",\"proxy_lanport\":%s",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v10)
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
// 45BB44: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

