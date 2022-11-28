int __fastcall sub_49D12C(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $s2
  int v5; // $v0
  int v6; // $a2
  int result; // $v0
  const char *v8; // $v0
  unsigned int v9; // $v0
  char v10[128]; // [sp+20h] [-80h] BYREF

  memset(v10, 0, sizeof(v10));
  _mem_malloc(0x200000, "pppoe_br_session_list_data", 1619);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v4 = pppoe_br_session_get_state(v2 + 29, 2097123) + 29;
    v5 = snprintf(&v3[v4], 0x200000 - v4, "]}");
    if ( v5 >= 0x200000 - v4 )
      v6 = 0x1FFFFF - v4;
    else
      v6 = v5;
    result = jhl_data_giz(a1, v3, v6 + v4, 0x200000);
  }
  else
  {
    v8 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v9 = snprintf(v10, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
    if ( v9 >= 0x80 )
      v9 = 127;
    result = httpd_cgi_ret(a1, v10, v9, 4);
  }
  return result;
}
// 49D198: variable 'v2' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

