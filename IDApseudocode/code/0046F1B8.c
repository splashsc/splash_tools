int __fastcall sub_46F1B8(int a1)
{
  const char *v2; // $s6
  const char *v3; // $s7
  const char *v4; // $s0
  const char *v5; // $s3
  const char *v6; // $s4
  const char *v7; // $s5
  const char *v8; // $v0
  int v9; // $s0
  const char *v10; // $v0
  unsigned int v11; // $v0
  const char *v12; // $v0
  unsigned int v13; // $s0
  unsigned int v14; // $v0
  const char *v15; // $v0
  unsigned int v16; // $s0
  unsigned int v17; // $v0
  unsigned int v18; // $s0
  unsigned int v19; // $v0
  char v21[516]; // [sp+30h] [-204h] BYREF

  memset(v21, 0, 0x200u);
  strcpy(v21, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("billing_en");
  v3 = (const char *)jhl_nv_get_def("billing_rname");
  v4 = (const char *)jhl_nv_get_def("billing_dev_pwd");
  v5 = (const char *)jhl_nv_get_def("billing_state");
  v6 = (const char *)jhl_nv_get_def("billing_scene");
  v7 = (const char *)jhl_nv_get_def("billing_syn_state");
  v8 = (const char *)jhl_nv_get_def("billing_no_ipoff");
  v9 = sprintf(
         &v21[29],
         "\"en\":\"%s\",\"rname\":\"%s\",\"dev_pwd\":\"%s\",\"state\":\"%s\",\"scene\":\"%s\",\"syn_state\":\"%s\",\"ipoff_en\":\"%s\"",
         v2,
         v3,
         v4,
         v5,
         v6,
         v7,
         v8)
     + 29;
  v10 = (const char *)jhl_nv_get_def("mqtt_cbg_svr_host");
  v11 = snprintf(&v21[v9], 512 - v9, ",\"cbg_url\":\"%s\"", v10);
  if ( v11 >= 512 - v9 )
    v11 = 511 - v9;
  v13 = v11 + v9;
  v12 = (const char *)jhl_nv_get_def("billing_api_port");
  v14 = snprintf(&v21[v13], 512 - v13, ",\"api_port\":\"%s\"", v12);
  if ( v14 >= 512 - v13 )
    v14 = 511 - v13;
  v16 = v14 + v13;
  v15 = (const char *)jhl_nv_get_def("billing_api_type");
  v17 = snprintf(&v21[v16], 512 - v16, ",\"api_type\":\"%s\"", v15);
  if ( v17 >= 512 - v16 )
    v17 = 511 - v16;
  v18 = v17 + v16;
  v19 = snprintf(&v21[v18], 512 - v18, "}}");
  if ( v19 >= 512 - v18 )
    v19 = 511 - v18;
  return httpd_cgi_ret(a1, v21, v19 + v18, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

