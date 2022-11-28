int __fastcall sub_45A930(int a1)
{
  char *v2; // $s2
  char *v3; // $s7
  char *v4; // $s6
  char *v5; // $s4
  char *v6; // $s5
  int v7; // $a0
  char *v8; // $s1
  char *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  char v16[256]; // [sp+18h] [-100h] BYREF

  memset(v16, 0, sizeof(v16));
  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "name");
  v4 = httpd_get_parm(a1, "email");
  v5 = httpd_get_parm(a1, "time");
  v6 = httpd_get_parm(a1, "mode");
  v8 = httpd_get_parm(a1, "hour");
  if ( v2 && !nvram_match_def("parm_email_en", v2) )
    nvram_set("parm_email_en", v2);
  if ( v3 && !nvram_match_def("parm_email_name", v3) )
    nvram_set("parm_email_name", v3);
  if ( v4 && !nvram_match_def("parm_email_url", v4) )
    nvram_set("parm_email_url", v4);
  if ( v6 && !nvram_match_def("parm_email_mode", v6) )
    nvram_set("parm_email_mode", v6);
  if ( v5 && !nvram_match_def("parm_email_time", v5) )
    nvram_set("parm_email_time", v5);
  if ( v8 )
  {
    if ( !J_atoi(v8) )
      v8 = "4";
    if ( !nvram_match_def("parm_email_hour", v8) )
      nvram_set("parm_email_hour", v8);
  }
  if ( v2 )
  {
    stop_parm_auto_send_email();
    if ( nvram_match_def("parm_email_en", "1") )
    {
      start_parm_auto_send_email();
      jhl_system("parm_send_email &");
    }
  }
  jhl_parm_commit(v7);
  v9 = v16;
  v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v11 = *(_DWORD *)v10;
    v12 = *((_DWORD *)v10 + 1);
    v13 = *((_DWORD *)v10 + 2);
    v14 = *((_DWORD *)v10 + 3);
    v10 += 16;
    *(_DWORD *)v9 = v11;
    *((_DWORD *)v9 + 1) = v12;
    *((_DWORD *)v9 + 2) = v13;
    *((_DWORD *)v9 + 3) = v14;
    v9 += 16;
  }
  while ( v10 != "}" );
  *(_WORD *)v9 = *(_WORD *)v10;
  return httpd_cgi_ret(a1, v16, 33, 4);
}
// 45AB98: variable 'v7' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8594: using guessed type int __fastcall jhl_system(_DWORD);
// 6A859C: using guessed type int start_parm_auto_send_email(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A895C: using guessed type int stop_parm_auto_send_email(void);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

