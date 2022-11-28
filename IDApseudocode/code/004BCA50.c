int __fastcall sub_4BCA50(int a1)
{
  const char *v2; // $s4
  const char *v3; // $s1
  const char *v4; // $s3
  int v5; // $v0
  const char *v6; // $v0
  const char *v7; // $s0
  int v8; // $s1
  unsigned int v9; // $v0
  char v11[1024]; // [sp+28h] [-400h] BYREF

  strcpy(v11, "{\"code\":0,\"error\":\"\",\"data\":{");
  v2 = (const char *)jhl_nv_get_def("sj_en");
  v3 = (const char *)jhl_nv_get_def(&unk_64F814);
  v4 = (const char *)jhl_nv_get_def("sj_platform_srv_port");
  v5 = nvram_get("sj_state");
  if ( v5 )
  {
    v7 = (const char *)v5;
    v6 = (const char *)nvram_get("sj_send_last_time");
    if ( v6 )
      goto LABEL_3;
  }
  else
  {
    v6 = (const char *)nvram_get("sj_send_last_time");
    v7 = (const char *)&unk_64F808;
    if ( v6 )
      goto LABEL_3;
  }
  v6 = "";
LABEL_3:
  v8 = sprintf(
         &v11[29],
         "\"enable\":\"%s\",\"srv_addr\":\"%s\",\"srv_port\":\"%s\",\"status\":\"%s\",\"last_time\":\"%s\"",
         v2,
         v3,
         v4,
         v7,
         v6)
     + 29;
  v9 = snprintf(&v11[v8], 1024 - v8, "}}");
  if ( v9 >= 1024 - v8 )
    v9 = 1023 - v8;
  return httpd_cgi_ret(a1, v11, v9 + v8, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

