int __fastcall httpd_check_user(int a1, unsigned int a2)
{
  int v4; // $v0
  _BOOL4 v5; // $v0
  int v6; // $s1
  signed int v7; // $s4
  const char *v8; // $s2
  int v9; // $a2
  int v10; // $v0
  int v11; // $v0
  bool v13; // dc
  const char *v14; // $v0
  char v15[128]; // [sp+20h] [-80h] BYREF

  if ( !httpd_check_aitoken(a1) )
  {
    v6 = 0;
    v11 = *(_DWORD *)(a1 + 205408);
    if ( !v11 || v11 == https_fd )
      return 0;
    return v6;
  }
  v4 = *(_DWORD *)(a1 + 205408);
  if ( v4 )
  {
    v13 = v4 == https_fd;
    v5 = a2 < 2;
    if ( !v13 )
      return a2 != 0;
  }
  else
  {
    v5 = a2 < 2;
  }
  if ( v5 || *(_BYTE *)(a1 + 43) == 1 && *(_DWORD *)(a1 + 205588) >= (signed int)a2 )
    return 0;
  v6 = -1;
  if ( httpd_user_auth_cookie(a1) )
    return v6;
  v7 = *(_DWORD *)(a1 + 205588);
  if ( v7 >= (int)a2 )
    return 0;
  v8 = *(const char **)(a1 + 44);
  if ( !strstr(v8, ".asp") && !strstr(v8, ".data") && !strstr(v8, ".cgi") && !strstr(v8, ".php") && !strstr(v8, ".xml") )
  {
    if ( v7 == 2 )
    {
      httpd_send_info(a1, "<html><head></head><body></body></html>", 0);
    }
    else
    {
      v10 = _GET_LANG_TEXT(2, *(unsigned __int8 *)(a1 + 210102), 0);
      httpd_send_info(
        a1,
        "<html><head></head><body><script type='text/javascript'>alert('%s');</script></body></html>",
        v10);
    }
    return v6;
  }
  v14 = (const char *)_GET_LANG_TEXT(2, *(unsigned __int8 *)(a1 + 210102), v9);
  snprintf(v15, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
  httpd_send_info(a1, v15, 0);
  return -1;
}
// 424D28: variable 'v9' is possibly undefined
// 67BD44: using guessed type int https_fd;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

