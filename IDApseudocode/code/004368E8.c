int __fastcall sub_4368E8(int a1)
{
  int v2; // $s0
  const char *v3; // $s1
  const char *v4; // $v0
  int v5; // $s0
  unsigned int v6; // $v0
  char v8[2052]; // [sp+18h] [-804h] BYREF

  strcpy(v8, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = get_nvarms((const char **)base_ident_nvarms, (int)&v8[29], 2019) + 29;
  v3 = (const char *)jhl_nv_get_def("h323_enable");
  v4 = (const char *)jhl_nv_get_def("sip_enable");
  v5 = v2 + sprintf(&v8[v2], "H323_en:'%s',sip_en:'%s'", v3, v4);
  v6 = snprintf(&v8[v5], 2048 - v5, "}}");
  if ( v6 >= 2048 - v5 )
    v6 = 2047 - v5;
  return httpd_cgi_ret(a1, v8, v6 + v5, 4);
}
// 642164: using guessed type __int16 word_642164;
// 66D240: using guessed type char *base_ident_nvarms[5];
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

