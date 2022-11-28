int __fastcall wan_ping_data(int a1)
{
  const char *v2; // $v0
  int v3; // $s1
  unsigned int v4; // $v0
  char v6[516]; // [sp+18h] [-204h] BYREF

  strcpy(v6, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("wan_ping");
  v3 = sprintf(&v6[29], "\"wan_ping\":%s", v2) + 29;
  v4 = snprintf(&v6[v3], 512 - v3, "}}");
  if ( v4 >= 512 - v3 )
    v4 = 511 - v3;
  return httpd_cgi_ret(a1, v6, v4 + v3, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

