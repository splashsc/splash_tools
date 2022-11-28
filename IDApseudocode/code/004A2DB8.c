int __fastcall sub_4A2DB8(int a1)
{
  int v2; // $a2
  int result; // $v0
  const char *v4; // $v0
  unsigned int v5; // $v0
  int v6[256]; // [sp+20h] [-40Ch] BYREF
  int v7; // [sp+420h] [-Ch]

  memset(v6, 0, sizeof(v6));
  v6[0] = 5;
  v6[3] = 10;
  v6[1] = 1024;
  v6[5] = 0;
  v6[6] = 0;
  v6[7] = 0;
  v6[8] = 0;
  if ( jianhl_order_opt_fun(v6, 1024, v2) )
  {
    v4 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
    v5 = snprintf((char *)v6, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v4);
    if ( v5 >= 0x400 )
      result = httpd_cgi_ret(a1, (char *)v6, 1023, 4);
    else
      result = httpd_cgi_ret(a1, (char *)v6, v5, 4);
  }
  else
  {
    v7 = 0;
    *(_DWORD *)(a1 + 205572) = 0;
    dhcp_detect_list_data_timeout((_DWORD *)a1);
    result = v7;
  }
  return result;
}
// 4A2E28: variable 'v2' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);

