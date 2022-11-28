int __fastcall sub_46EFF8(int a1)
{
  const char *v2; // $s0
  const char *v3; // $v0
  int v4; // $s0
  const char *v5; // $v0
  int v6; // $s0
  const char *v7; // $v0
  int v8; // $s0
  unsigned int v9; // $v0
  char v11[516]; // [sp+18h] [-204h] BYREF

  memset(v11, 0, 0x200u);
  strcpy(v11, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("mqtt_cbg_svr_host");
  v3 = (const char *)jhl_nv_get_def("mqtt_cbg_svr_port");
  v4 = sprintf(&v11[29], "\"svr_host\":\"%s\",\"svr_port\":\"%s\"", v2, v3) + 29;
  v5 = (const char *)jhl_nv_get_def("billing_api_port");
  v6 = v4 + sprintf(&v11[v4], ",\"api_port\":\"%s\"", v5);
  v7 = (const char *)jhl_nv_get_def("billing_api_type");
  v8 = v6 + sprintf(&v11[v6], ",\"api_type\":\"%s\"", v7);
  v9 = snprintf(&v11[v8], 512 - v8, "}}");
  if ( v9 >= 512 - v8 )
    v9 = 511 - v8;
  return httpd_cgi_ret(a1, v11, v9 + v8, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

