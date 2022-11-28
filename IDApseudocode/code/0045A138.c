int __fastcall sub_45A138(int a1)
{
  const char *v2; // $s0
  const char *v3; // $v0
  int v4; // $v0
  char *v5; // $v1
  int v6; // $s0
  const char *v7; // $s4
  const char *v8; // $s1
  const char *v9; // $v0
  int v10; // $s0
  unsigned int v11; // $v0
  char v13[512]; // [sp+20h] [-200h] BYREF

  memset(v13, 0, sizeof(v13));
  v2 = (const char *)jhl_nv_get_def("auto_reboot_enable");
  v3 = (const char *)jhl_nv_get_def("auto_reboot_time");
  strcpy(v13, "{\"code\":0,\"error\":\"\",\"data\":{");
  v4 = sprintf(&v13[29], "\"enable\":\"%s\",\"time\":\"%s\",\"display\":\"1\"", v2, v3);
  v5 = &v13[v4 + 29];
  strcpy(v5, ",\"wifi_en\":\"0\"");
  qmemcpy(v5, ",\"wifi_en\":\"", 12);
  v6 = v4 + 43;
  v7 = (const char *)jhl_nv_get_def("auto_reboot_mode");
  v8 = (const char *)jhl_nv_get_def("auto_reboot_runday");
  v9 = (const char *)jhl_nv_get_def("auto_reboot_runtm");
  v10 = v6 + sprintf(&v13[v6], ",\"mode\":\"%s\",\"run_day\":\"%s\",\"run_tm\":\"%s\"", v7, v8, v9);
  v11 = snprintf(&v13[v10], 512 - v10, "}}");
  if ( v11 >= 512 - v10 )
    v11 = 511 - v10;
  return httpd_cgi_ret(a1, v13, v11 + v10, 4);
}
// 642164: using guessed type __int16 word_642164;
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

