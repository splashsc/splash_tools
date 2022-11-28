int __fastcall sub_48AE28(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $s1
  int v5; // $s1
  int v6; // $v0
  int v7; // $a2
  int result; // $v0
  const char *v9; // $v0
  unsigned int v10; // $v0
  char v11[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(102400, "vpn_data", 218);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v4 = get_nvarms((const char **)pptp_parms, v2 + 29, 102371) + 29;
    v5 = v4 + get_nvarms((const char **)l2tp_parms, (int)&v3[v4], 102400 - v4) - 1;
    v6 = snprintf(&v3[v5], 102400 - v5, "}}");
    if ( v6 >= 102400 - v5 )
      v7 = 102399 - v5;
    else
      v7 = v6;
    result = httpd_cgi_ret(a1, v3, v7 + v5, 8);
  }
  else
  {
    v9 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v10 = snprintf(v11, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 >= 0x100 )
      v10 = 255;
    result = httpd_cgi_ret(a1, v11, v10, 4);
  }
  return result;
}
// 48AE7C: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 672EF4: using guessed type char *l2tp_parms[6];
// 672F14: using guessed type char *pptp_parms[8];
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

