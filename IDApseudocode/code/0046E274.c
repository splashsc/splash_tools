int __fastcall sub_46E274(int a1)
{
  const char *v2; // $v0
  unsigned int v3; // $v0
  int v4; // $s0
  unsigned int v5; // $v0
  char v7[1028]; // [sp+18h] [-404h] BYREF

  strcpy(v7, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("user_list_enable");
  v3 = snprintf(&v7[29], 995, "\"en\":\"%s\"", v2);
  v4 = v3 + 29;
  if ( v3 >= 0x3E3 )
    v4 = 1023;
  v5 = snprintf(&v7[v4], 1024 - v4, "}}");
  if ( v5 >= 1024 - v4 )
    v5 = 1023 - v4;
  return httpd_cgi_ret(a1, v7, v5 + v4, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

