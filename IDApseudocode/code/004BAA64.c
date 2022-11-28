int __fastcall sub_4BAA64(int a1)
{
  const char *v2; // $s7
  const char *v3; // $s0
  const char *v4; // $s1
  const char *v5; // $s2
  const char *v6; // $s4
  const char *v7; // $s5
  const char *v8; // $s6
  const char *v9; // $v0
  int v10; // $s1
  unsigned int v11; // $v0
  char v13[1028]; // [sp+30h] [-404h] BYREF

  strcpy(v13, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("sj_state_en");
  v3 = (const char *)jhl_nv_get_def("sj_app_id");
  v4 = (const char *)jhl_nv_get_def("sj_app_closeid");
  v5 = (const char *)jhl_nv_get_def("sj_app_remark");
  v6 = (const char *)jhl_nv_get_def("sj_list");
  v7 = (const char *)jhl_nv_get_def("sj_close_list");
  v8 = (const char *)jhl_nv_get_def("sj_state");
  v9 = (const char *)jhl_nv_get_def("sj_ctrl_state");
  v10 = sprintf(
          &v13[29],
          "\"en\":\"%s\",\"appid\":\"%s\",\"closeid\":\"%s\",\"remark\":\"%s\",\"sjlist\":%s,\"close_list\":%s,\"sj_state"
          "\":\"%s\", \"sj_ctrl_state\":\"%s\"",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9)
      + 29;
  v11 = snprintf(&v13[v10], 1024 - v10, "}}");
  if ( v11 >= 1024 - v10 )
    v11 = 1023 - v10;
  return httpd_cgi_ret(a1, v13, v11 + v10, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

