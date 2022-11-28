int __fastcall sub_43D448(int a1)
{
  const char *v2; // $s0
  const char *v3; // $s1
  const char *v4; // $s2
  const char *v5; // $v0
  unsigned int v6; // $v0
  int v7; // $s0
  unsigned int v8; // $v0
  char v10[2052]; // [sp+28h] [-804h] BYREF

  strcpy(v10, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("wan_itv_en");
  v3 = (const char *)jhl_nv_get_def("wan_itv_vid");
  v4 = (const char *)jhl_nv_get_def("wan_itv_port");
  v5 = (const char *)jhl_nv_get_def("vlan_name");
  v6 = snprintf(&v10[29], 2019, "\"en\":%s,\"vid\":%s,\"port\":%s,\"vlan_name\":\"%s\"", v2, v3, v4, v5);
  v7 = v6 + 29;
  if ( v6 >= 0x7E3 )
    v7 = 2047;
  v8 = snprintf(&v10[v7], 2048 - v7, "}}");
  if ( v8 >= 2048 - v7 )
    v8 = 2047 - v7;
  return httpd_cgi_ret(a1, v10, v8 + v7, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

