int __fastcall dns_more_check_data(int a1)
{
  const char *v2; // $s1
  const char *v3; // $s0
  const char *v4; // $v0
  int v5; // $s1
  unsigned int v6; // $v0
  char v8[1028]; // [sp+20h] [-404h] BYREF

  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("dns_more_check_en");
  v3 = (const char *)jhl_nv_get_def("dns_more_check_path2");
  v4 = (const char *)jhl_nv_get_def("dns_more_modify_time");
  v5 = sprintf(&v8[29], "\"enable\":%s,\"srv_path\":\"%s\",\"mod_time\":\"%s\"", v2, v3, v4) + 29;
  v6 = snprintf(&v8[v5], 1024 - v5, "}}");
  if ( v6 >= 1024 - v5 )
    v6 = 1023 - v5;
  return httpd_cgi_ret(a1, v8, v6 + v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

