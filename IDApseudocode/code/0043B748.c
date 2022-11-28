int __fastcall sub_43B748(int a1)
{
  int *v1; // $v0
  int v2; // $a2
  char *v3; // $v0
  char *v4; // $s1
  int *v5; // $fp
  int *v6; // $s0
  int v7; // $s7
  int v8; // $s2
  const char *v9; // $v0
  int v10; // $a0
  int v11; // $v0
  char *v12; // $a0
  int v13; // $v0
  int v14; // $s2
  int result; // $v0
  const char *v16; // $v0
  int v17; // $s0
  const char *v18; // $v0
  unsigned int v19; // $v0
  char v20[128]; // [sp+20h] [-88h] BYREF
  uint32_t v21; // [sp+A0h] [-8h]

  _mem_malloc(0x200000, "qqlist_data", 2036);
  v4 = v3;
  _mem_malloc(0x100000, "qqlist_data", 2037);
  v5 = v1;
  if ( !v4 || !v1 )
  {
    _mem_free(v4);
    _mem_free(v5);
    v18 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v19 = snprintf(v20, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v18);
    if ( v19 >= 0x80 )
      result = httpd_cgi_ret(a1, v20, 127, 4);
    else
      result = httpd_cgi_ret(a1, v20, v19, 4);
    return result;
  }
  *v1 = 13;
  v1[3] = 15;
  v1[1] = 0x100000;
  if ( jianhl_order_opt_fun(v1, 0x100000, v2) )
  {
    v16 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
    v17 = snprintf(v4, 0x200000, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
    _mem_free(v5);
    if ( v17 >= 0x200000 )
      result = httpd_cgi_ret(a1, v4, 0x1FFFFF, 8);
    else
      result = httpd_cgi_ret(a1, v4, v17, 8);
    return result;
  }
  strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":[");
  qmemcpy(v4, "{\"code\":0,\"error", 16);
  v6 = v5 + 6;
  if ( v5[5] <= 0 )
  {
    v11 = 28;
    v10 = 29;
    v8 = 29;
LABEL_9:
    if ( v4[v11] == 44 )
      v10 = --v8;
    goto LABEL_11;
  }
  v7 = 0;
  v8 = 29;
  do
  {
    v21 = ntohl(v6[1]);
    v9 = (const char *)IpaddrToStr(v20, v6);
    ++v7;
    v8 += sprintf(
            &v4[v8],
            "{\"ip\":%u,\"ip6\":\"%s\",\"tp\":\"%s\",\"dt\":\"%s\"},",
            v21,
            v9,
            (const char *)v6 + 20,
            (const char *)v6 + 36);
    v6 += 25;
  }
  while ( v7 < v5[5] );
  v10 = v8;
  if ( v8 > 0 )
  {
    v11 = v8 - 1;
    goto LABEL_9;
  }
LABEL_11:
  v12 = &v4[v10];
  *v12 = 0;
  v13 = snprintf(v12, 0x200000 - v8, "]}");
  if ( v13 >= 0x200000 - v8 )
    v13 = 0x1FFFFF - v8;
  v14 = v8 + v13;
  _mem_free(v5);
  return jhl_data_giz(a1, v4, v14, 0x200000);
}
// 43B7B8: variable 'v3' is possibly undefined
// 43B7C4: variable 'v1' is possibly undefined
// 43B7EC: variable 'v2' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

