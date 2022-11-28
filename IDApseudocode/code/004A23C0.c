int __fastcall sub_4A23C0(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s1
  const char *v5; // $s2
  const char *v6; // $s4
  const char *v7; // $v0
  int v8; // $v0
  int v9; // $s1
  int v10; // $s2
  int v11; // $v0
  int v12; // $a2
  int result; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[104]; // [sp+30h] [-68h] BYREF

  _mem_malloc(10240, "alert_weixin_data", 1485);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v2, "{\"code\":0,\"error\":\"\",\"da", 24);
    v4 = (const char *)jhl_nv_get_def("alert_weixin_en");
    v5 = (const char *)jhl_nv_get_def("alert_weixin_name");
    v6 = (const char *)jhl_nv_get_def("alert_weixin_phone");
    v7 = (const char *)jhl_nv_get_def("alert_weixin_type");
    v8 = snprintf(
           v3 + 29,
           10211,
           "\"enable\":%s,\"name\":\"%s\",\"phone\":\"%s\",\"type\":%s,\"ac\":%d,\"wtclient\":%d",
           v4,
           v5,
           v6,
           v7,
           1,
           1);
    if ( v8 >= 10211 )
      v8 = 10210;
    v9 = v8 + 29;
    v10 = 10240 - (v8 + 29);
    v11 = snprintf(&v3[v8 + 29], v10, "}}");
    if ( v11 >= v10 )
      v12 = 10239 - v9;
    else
      v12 = v11;
    result = httpd_cgi_ret(a1, v3, v12 + v9, 8);
  }
  else
  {
    v14 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v15 = snprintf(v16, 100, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v15 >= 0x64 )
      v15 = 99;
    result = httpd_cgi_ret(a1, v16, v15, 4);
  }
  return result;
}
// 4A2410: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

