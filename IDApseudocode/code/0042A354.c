int __fastcall jhl_data_giz(int a1, char *a2, int a3, int a4)
{
  int v7; // $s2
  const char *v9; // $v0
  int v10; // $v0
  int v11; // $a2

  f_write("/tmp/webdata", a2, a3, 0, 0);
  system("gzip /tmp/webdata");
  v7 = f_read("/tmp/webdata.gz", a2, a4);
  system("rm -f /tmp/webdata.gz");
  if ( v7 > 0 )
    return httpd_cgi_ret(a1, a2, v7, 32);
  v9 = (const char *)_GET_LANG_TEXT(5, *(unsigned __int8 *)(a1 + 210102), v7);
  v10 = snprintf(a2, a4, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
  if ( v10 >= a4 )
    v11 = a4 - 1;
  else
    v11 = v10;
  return httpd_cgi_ret(a1, a2, v11, 8);
}
// 6A8204: using guessed type int __fastcall f_write(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A869C: using guessed type int __fastcall f_read(_DWORD, _DWORD, _DWORD);

