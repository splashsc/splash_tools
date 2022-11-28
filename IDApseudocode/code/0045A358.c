int __fastcall sub_45A358(int a1)
{
  char *v2; // $s5
  char *v3; // $s4
  char *v4; // $s3
  char *v5; // $s1
  int v6; // $a0
  char *v7; // $s6
  int v8; // $s5
  char *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  char v16[516]; // [sp+18h] [-204h] BYREF

  memset(v16, 0, 0x200u);
  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "time");
  v4 = httpd_get_parm(a1, "mode");
  v5 = httpd_get_parm(a1, "run_day");
  v7 = httpd_get_parm(a1, "run_tm");
  if ( v2 && !nvram_match_def("auto_reboot_enable", v2) )
  {
    nvram_set("auto_reboot_enable", v2);
    v8 = 1;
  }
  else
  {
    v8 = 0;
  }
  if ( v3 && !nvram_match_def("auto_reboot_time", v3) )
  {
    nvram_set("auto_reboot_time", v3);
    v8 = 1;
  }
  if ( v4 && !nvram_match_def("auto_reboot_mode", v4) )
  {
    nvram_set("auto_reboot_mode", v4);
    v8 = 1;
  }
  if ( v5 )
  {
    if ( !J_atoi(v5) )
      v5 = "1";
    if ( !nvram_match_def("auto_reboot_runday", v5) )
    {
      nvram_set("auto_reboot_runday", v5);
      if ( !v7 || nvram_match_def("auto_reboot_runtm", v7) )
        goto LABEL_24;
      goto LABEL_23;
    }
  }
  if ( v7 && !nvram_match_def("auto_reboot_runtm", v7) )
  {
LABEL_23:
    nvram_set("auto_reboot_runtm", v7);
    goto LABEL_24;
  }
  if ( v8 )
  {
LABEL_24:
    jhl_parm_commit(v6);
    start_auto_reboot(0);
  }
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
// 45A670: variable 'v6' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A83C0: using guessed type int __fastcall start_auto_reboot(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

