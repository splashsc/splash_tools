int __fastcall sub_46769C(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s2
  const char *v5; // $v0
  int v6; // $v0
  int v7; // $s1
  int v8; // $v0
  int v9; // $a2
  int result; // $v0
  const char *v11; // $v0
  unsigned int v12; // $v0
  char v13[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(102400, "qq_hbmd_data", 1513);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\"", 20);
    v4 = (const char *)jhl_nv_get_def("hbmd_def_commqq");
    v5 = (const char *)jhl_nv_get_def(&unk_646F64);
    v6 = snprintf(v3 + 29, 102371, "\"act\":\"%s\",\"log\":\"%s\",\"account_log\":\"%d\",\"all\":", v4, v5, 1);
    if ( v6 >= 102371 )
      v6 = 102370;
    v7 = v6 + 29 + get_hbmd_data("commqq", &v3[v6 + 29], 102400 - (v6 + 29));
    v8 = snprintf(&v3[v7], 102400 - v7, "}}");
    if ( v8 >= 102400 - v7 )
      v9 = 102399 - v7;
    else
      v9 = v8;
    result = httpd_cgi_ret(a1, v3, v9 + v7, 8);
  }
  else
  {
    v11 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v12 = snprintf(v13, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
    if ( v12 >= 0x100 )
      v12 = 255;
    result = httpd_cgi_ret(a1, 0, v12, 4);
  }
  return result;
}
// 4676F0: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

