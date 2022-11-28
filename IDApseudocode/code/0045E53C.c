int __fastcall mac_filter_data(int a1)
{
  char *v2; // $v0
  char *v3; // $v0
  char *v4; // $s0
  char *v5; // $s2
  int v6; // $s1
  int v7; // $v0
  int v8; // $s1
  int result; // $v0
  const char *v10; // $v0
  unsigned int v11; // $v0
  char v12[256]; // [sp+20h] [-120h] BYREF
  int v13[8]; // [sp+120h] [-20h] BYREF

  v13[0] = 0;
  v13[1] = 0;
  v13[2] = 0;
  v13[3] = 0;
  v13[4] = 0;
  v13[5] = 0;
  v13[6] = 0;
  v13[7] = 0;
  _mem_malloc(0x200000, "mac_filter_data", 737);
  v4 = v3;
  _mem_malloc(0x100000, "mac_filter_data", 738);
  v5 = v2;
  if ( v4 && v2 )
  {
    jhl_parm_get("macfilterAll", v2, 0x100000);
    jhl_parm_get("macfilterAct", v13, 32);
    if ( !LOBYTE(v13[0]) )
      LOWORD(v13[0]) = 48;
    strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v4, "{\"code\":0,\"error\":\"\",\"da", 24);
    v6 = sprintf(v4 + 29, "\"def\":\"%s\",\"all\":\"%s\"", (const char *)v13, v5) + 29;
    v7 = snprintf(&v4[v6], 0x200000 - v6, "}}");
    if ( v7 >= 0x200000 - v6 )
      v7 = 0x1FFFFF - v6;
    v8 = v7 + v6;
    _mem_free(v5);
    result = httpd_cgi_ret(a1, v4, v8, 8);
  }
  else
  {
    _mem_free(v4);
    _mem_free(v5);
    v10 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v11 = snprintf(v12, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
    if ( v11 >= 0x100 )
      result = httpd_cgi_ret(a1, v12, 255, 4);
    else
      result = httpd_cgi_ret(a1, v12, v11, 4);
  }
  return result;
}
// 45E5C4: variable 'v3' is possibly undefined
// 45E5D0: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

