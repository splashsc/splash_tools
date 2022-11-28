int __fastcall sub_49F2B8(int a1)
{
  bool v2; // dc
  int result; // $v0
  int v4; // $v0
  char *v5; // $s0
  int v6; // $s2
  int v7; // $v0
  int v8; // $a2
  const char *v9; // $v0
  unsigned int v10; // $v0
  char v11[128]; // [sp+20h] [-80h] BYREF

  v2 = pppoe_bridge_check_token(a1) == 0;
  result = 0;
  if ( v2 )
  {
    _mem_malloc(0x200000, "pppoe_bridge_user_data", 2311);
    v5 = (char *)v4;
    if ( v4 )
    {
      strcpy((char *)v4, "{\"code\":0,\"error\":\"\",\"data\":[");
      qmemcpy((void *)v4, "{\"code\":0,\"error\":\"\"", 20);
      *(_DWORD *)(v4 + 24) = 975331700;
      v6 = pppoe_br_user_get_state((char *)(v4 + 29), 0x1FFFE3u) + 29;
      v7 = snprintf(&v5[v6], 0x200000 - v6, "]}");
      if ( v7 >= 0x200000 - v6 )
        v8 = 0x1FFFFF - v6;
      else
        v8 = v7;
      result = jhl_data_giz(a1, v5, v8 + v6, 0x200000);
    }
    else
    {
      v9 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
      v10 = snprintf(v11, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
      if ( v10 >= 0x80 )
        v10 = 127;
      result = httpd_cgi_ret(a1, v11, v10, 4);
    }
  }
  return result;
}
// 49F33C: variable 'v4' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

