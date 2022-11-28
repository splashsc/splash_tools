int __fastcall sub_46F4CC(int a1)
{
  const char *v2; // $s0
  const char *v3; // $s1
  const char *v4; // $s2
  const char *v5; // $s4
  const char *v6; // $s5
  const char *v7; // $s6
  const char *v8; // $s7
  const char *v9; // $fp
  const char *v10; // $v0
  int v11; // $s1
  unsigned int v12; // $v0
  char v14[1024]; // [sp+40h] [-408h] BYREF
  const char *v15; // [sp+440h] [-8h]
  const char *v16; // [sp+444h] [-4h]

  strcpy(v14, "{\"code\":0,\"error\":\"\",\"data\":{");
  v16 = (const char *)jhl_nv_get_def("rd_en");
  v2 = (const char *)jhl_nv_get_def("rd_auth");
  v3 = (const char *)jhl_nv_get_def("rd_acct");
  v4 = (const char *)jhl_nv_get_def("rd_key");
  v5 = (const char *)jhl_nv_get_def("rd_ip");
  v6 = (const char *)jhl_nv_get_def("rd_id");
  v7 = (const char *)jhl_nv_get_def("rd_coa");
  v8 = (const char *)jhl_nv_get_def("rd_dev");
  v9 = (const char *)jhl_nv_get_def("rd_get_user");
  v15 = (const char *)jhl_nv_get_def(&unk_647E00);
  v10 = (const char *)jhl_nv_get_def("rd_list");
  v11 = sprintf(
          &v14[29],
          "\"en\":\"%s\",\"auth\":\"%s\",\"acct\":\"%s\",\"key\":\"%s\",\"ip\":\"%s\",\"id\":\"%s\",\"coa\":\"%s\",\"dev\""
          ":\"%s\",\"get_user\":\"%s\",\"auth_mode\":\"%s\",\"list\":\"%s\"",
          v16,
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v8,
          v9,
          v15,
          v10)
      + 29;
  v12 = snprintf(&v14[v11], 1024 - v11, "}}");
  if ( v12 >= 1024 - v11 )
    v12 = 1023 - v11;
  return httpd_cgi_ret(a1, v14, v12 + v11, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

