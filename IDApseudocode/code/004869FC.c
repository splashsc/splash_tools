int __fastcall sub_4869FC(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $v0
  int v5; // $s1
  int v6; // $v0
  int v7; // $a2
  int result; // $v0
  const char *v9; // $v0
  unsigned int v10; // $v0
  char v11[260]; // [sp+20h] [-104h] BYREF

  _mem_malloc(10240, "url_group_data", 58);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{\"all\":");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    *(_BYTE *)(v2 + 32) = 108;
    v4 = get_url_group_data((char *)(v2 + 35), 10205);
    v3[v4 + 35] = 44;
    v5 = v4 + 36 + get_url_update_data(&v3[v4 + 36]);
    v6 = snprintf(&v3[v5], 10240 - v5, "}}");
    if ( v6 >= 10240 - v5 )
      v7 = 10239 - v5;
    else
      v7 = v6;
    result = httpd_cgi_ret(a1, v3, v7 + v5, 8);
  }
  else
  {
    v9 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v10 = snprintf(v11, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 >= 0x100 )
      v10 = 255;
    result = httpd_cgi_ret(a1, v11, v10, 4);
  }
  return result;
}
// 486A48: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6459A8: using guessed type int dword_6459A8;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

