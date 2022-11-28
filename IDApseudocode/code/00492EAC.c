int __fastcall sub_492EAC(int a1)
{
  char *v2; // $v0
  char *v3; // $s2
  char *v4; // $s0
  const char *v5; // $v0
  int v6; // $s1
  int v7; // $s1
  int v8; // $v0
  int v9; // $a2
  int result; // $v0
  const char *v11; // $v0
  unsigned int v12; // $v0
  char v13[256]; // [sp+20h] [-100h] BYREF

  v3 = httpd_get_parm(a1, "name");
  _mem_malloc(102400, "dns_more_dnstype_data", 474);
  v4 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v5 = (const char *)nvram_get("dns_more_check_en");
    if ( !v5 )
      v5 = "0";
    v6 = sprintf(v4 + 29, "\"enable\":%s,\"all\":", v5) + 29;
    if ( v3 && *v3 )
      v7 = v6 + dns_more_dnstype_search(&v4[v6], 102400 - v6, (int)v3);
    else
      v7 = v6 + dns_more_dnstype_get_json(&v4[v6], 102400 - v6);
    v8 = snprintf(&v4[v7], 102400 - v7, "}}");
    if ( v8 >= 102400 - v7 )
      v9 = 102399 - v7;
    else
      v9 = v8;
    result = httpd_cgi_ret(a1, v4, v7 + v9, 8);
  }
  else
  {
    v11 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v12 = snprintf(v13, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
    if ( v12 >= 0x100 )
      v12 = 255;
    result = httpd_cgi_ret(a1, v13, v12, 4);
  }
  return result;
}
// 492F18: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8934: using guessed type int __fastcall dns_more_dnstype_get_json(_DWORD, _DWORD);

