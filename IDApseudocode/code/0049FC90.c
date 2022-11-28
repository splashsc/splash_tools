int __fastcall sub_49FC90(int a1)
{
  char *v2; // $s2
  bool v3; // dc
  int result; // $v0
  char *v5; // $v0
  char *v6; // $s0
  int v7; // $v0
  int v8; // $s3
  int v9; // $v0
  int v10; // $a2
  const char *v11; // $v0
  unsigned int v12; // $v0
  char v13[104]; // [sp+20h] [-68h] BYREF

  v2 = httpd_get_parm(a1, "all");
  v3 = pppoe_bridge_check_token(a1) == 0;
  result = 0;
  if ( v3 )
  {
    _mem_malloc(0x200000, "pppoe_bridge_session_data", 2526);
    v6 = v5;
    if ( v5 )
    {
      strcpy(v5, "{\"code\":0,\"error\":\"\",\"data\":[");
      qmemcpy(v5, "{\"code\":0,\"error\":\"\"", 20);
      v7 = J_atoi(v2);
      v8 = pppoe_bridge_session_get_state((int)(v6 + 29), 2097123, v7) + 29;
      v9 = snprintf(&v6[v8], 0x200000 - v8, "]}");
      if ( v9 >= 0x200000 - v8 )
        v10 = 0x1FFFFF - v8;
      else
        v10 = v9;
      result = jhl_data_giz(a1, v6, v10 + v8, 0x200000);
    }
    else
    {
      v11 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
      v12 = snprintf(v13, 100, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
      if ( v12 >= 0x64 )
        v12 = 99;
      result = httpd_cgi_ret(a1, v13, v12, 4);
    }
  }
  return result;
}
// 49FD34: variable 'v5' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

