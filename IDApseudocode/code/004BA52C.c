int __fastcall sub_4BA52C(int a1)
{
  const char *v2; // $s1
  const char *v3; // $s3
  const char *v4; // $s4
  const char *v5; // $s5
  const char *v6; // $s6
  const char *v7; // $s7
  _BYTE *v8; // $v0
  const char *v9; // $fp
  const char *v10; // $s0
  const char *v11; // $v0
  int v12; // $s1
  unsigned int v13; // $v0
  char v15[1024]; // [sp+38h] [-400h] BYREF

  strcpy(v15, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("sj_ctrl_en");
  v3 = (const char *)jhl_nv_get_def("sj_ctrl_addr");
  v4 = (const char *)jhl_nv_get_def("sj_ctrl_port");
  v5 = (const char *)jhl_nv_get_def("sj_ctrl_state");
  v6 = (const char *)jhl_nv_get_def("sj_state");
  v7 = (const char *)jhl_nv_get_def("sj_send_data_info");
  v9 = (const char *)jhl_nv_get_def("sj_send_data_tim");
  v8 = (_BYTE *)nvram_get("sj_real_dev_sn");
  if ( !v8 || *v8 )
  {
    v10 = (const char *)nvram_get("sj_real_dev_sn");
    if ( v10 )
      goto LABEL_4;
LABEL_9:
    v11 = (const char *)nvram_get("sj_real_tz_sn");
    v10 = "";
    if ( v11 )
      goto LABEL_5;
    goto LABEL_10;
  }
  v10 = (const char *)nvram_get("sj_palce_code");
  if ( !v10 )
    goto LABEL_9;
LABEL_4:
  v11 = (const char *)nvram_get("sj_real_tz_sn");
  if ( v11 )
    goto LABEL_5;
LABEL_10:
  v11 = "";
LABEL_5:
  v12 = sprintf(
          &v15[29],
          "\"en\":\"%s\",\"addr\":\"%s\",\"port\":\"%s\",\"ctrl_state\":\"%s\",\"sj_state\":\"%s\",\"sj_sendnum\":\"%s\","
          "\"sj_sendtm\":\"%s\",\"sj_code\":\"%s %s\"",
          v2,
          v3,
          v4,
          v5,
          v6,
          v7,
          v9,
          v10,
          v11)
      + 29;
  v13 = snprintf(&v15[v12], 1024 - v12, "}}");
  if ( v13 >= 1024 - v12 )
    v13 = 1023 - v12;
  return httpd_cgi_ret(a1, v15, v13 + v12, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

