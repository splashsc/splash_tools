int __fastcall sub_459E94(int a1)
{
  int v2; // $a2
  int v3; // $s0
  const char *v4; // $v0
  const char *v5; // $v0
  const char *v6; // $s0
  int v7; // $s3
  unsigned int v8; // $v0
  int result; // $v0
  const char *v10; // $v0
  const char *v11; // $v0
  unsigned int v12; // $v0
  char v13[512]; // [sp+20h] [-20Ch] BYREF
  int v14; // [sp+220h] [-Ch] BYREF
  __int16 v15; // [sp+224h] [-8h]

  v14 = 0;
  v15 = 0;
  v3 = a1 + 196608;
  if ( wys_get_mac_by_ipaddr(a1 + 205460, &v14) )
  {
    v11 = (const char *)_GET_LANG_TEXT(209, *(unsigned __int8 *)(v3 + 13494), v2);
    v12 = snprintf(v13, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
    if ( v12 >= 0x200 )
      result = httpd_cgi_ret(a1, v13, 511, 4);
    else
      result = httpd_cgi_ret(a1, v13, v12, 4);
  }
  else
  {
    defaults_asp_timer_fun();
    jhl_gl_reboot_timer(3000);
    strcpy(v13, "{\"code\":0,\"error\":\"\",\"data\":{");
    v4 = (const char *)nvram_get("http_lanport");
    if ( v4 && !strcmp(v4, "80") )
    {
      v10 = (const char *)nvram_get("lan_ipaddr");
      v7 = sprintf(&v13[29], "\"ip\":\"%s\"", v10) + 29;
    }
    else
    {
      v6 = (const char *)nvram_get("lan_ipaddr");
      v5 = (const char *)nvram_get("http_lanport");
      v7 = sprintf(&v13[29], "\"ip\":\"%s:%s\"", v6, v5) + 29;
    }
    v8 = snprintf(&v13[v7], 512 - v7, "}}");
    if ( v8 >= 512 - v7 )
      v8 = 511 - v7;
    result = httpd_cgi_ret(a1, v13, v8 + v7, 4);
  }
  return result;
}
// 45A0A8: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8438: using guessed type int __fastcall wys_get_mac_by_ipaddr(_DWORD, _DWORD);

