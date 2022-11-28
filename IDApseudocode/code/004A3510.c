int __fastcall sub_4A3510(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  const char *v4; // $a1
  int v5; // $s2
  int v6; // $v0
  int v7; // $a2
  int result; // $v0
  const char *v9; // $v0
  unsigned int v10; // $v0
  char v11[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(0x200000, "menus_data", 216);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    v4 = menu_js_router_str;
    *(_DWORD *)(v2 + 24) = *(_DWORD *)"ta\":";
    v5 = menus_js_replace_text(a1, v4, v2 + 28, 2097124) + 28;
    v6 = snprintf(&v3[v5], 0x200000 - v5, "}");
    if ( v6 >= 0x200000 - v5 )
      v7 = 0x1FFFFF - v5;
    else
      v7 = v6;
    result = jhl_data_giz(a1, v3, v7 + v5, 0x200000);
  }
  else
  {
    v9 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v10 = snprintf(v11, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 >= 0x100 )
      v10 = 255;
    result = httpd_cgi_ret(a1, v11, v10, 4);
  }
  return result;
}
// 4A3560: variable 'v2' is possibly undefined
// 67BF24: using guessed type char *menu_js_router_str;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

