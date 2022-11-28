int __fastcall main(int a1, char **a2, char **a3)
{
  unsigned int v4; // $v0
  const char *v6; // $s2
  unsigned int v7; // $a0
  int v8; // $a0
  int v9; // $a1
  int v10; // $a2
  const char *v11; // $v0
  const char *v12; // $v0
  int v14; // $s1
  int v15; // [sp+28h] [-8h] BYREF

  v15 = 0;
  v4 = get_random_seed(a1, a2, a3);
  srand(v4);
  gl_hs_speed = nvram_get_int("jhttpd_hs_speed");
  nvram_unset("wan_webset_run");
  if ( a1 >= 2 )
  {
    v6 = a2[1];
    if ( !strcmp(v6, "wait") )
    {
      if ( a1 == 2 )
        v7 = 15;
      else
        v7 = J_atoi(a2[2]);
      sleep(v7);
    }
    else
    {
      debug_level = atoi(v6);
    }
  }
  register_signal();
  _get_cpu_uptime(&dword_67D0C8);
  jhl_httpd_reset_user();
  httpd_cgi_user_check_admin(v8, v9, v10);
  if ( debug_level > 0 )
    printf(
      "%s:%d user %s pwd %s port %u https port %u\n",
      "main",
      1817,
      gl_httpd_user,
      gl_httpd_password,
      (unsigned __int16)gl_httpd_port,
      (unsigned __int16)gl_httpd_https_port);
  v11 = (const char *)jhl_nv_get_def("usb_passwd");
  usb_httpd_passwd_md5(gl_usb_password_md5, v11);
  v12 = (const char *)jhl_nv_get_def("usb_hpasswd");
  usb_httpd_passwd_md5(gl_usb_hpassword_md5, v12);
  mem_init_fun();
  httpd_find_type2_init();
  if ( !httpd_sever_init(0, gl_httpd_port, 10000)
    && !https_ssl_init()
    && !https_sever_init(0, gl_httpd_https_port, 10000) )
  {
    if ( gl_httpd_tggl_port && gl_httpd_port != gl_httpd_tggl_port )
      httpd_tggl_init(0, gl_httpd_tggl_port, 10000);
    if ( !httpd_unix_init() && !httpd_poll_init() )
    {
      init_diagnosis_timer();
      switch_reboot_auto_timer_init();
      g_wsc_configured = nvram_getdef_int("WscConfigured", "1");
      v14 = 0;
      g_Raix_wsc_configured = nvram_getdef_int("WscConfigured_5g", "1");
      while ( !dword_67D0C4 && !httpd_poll(30) )
      {
        run_timers();
        get_uptime2(&v15);
        if ( (unsigned int)(v15 - v14) >= 4 )
        {
          cpu_rate_set();
          v14 = v15;
        }
      }
    }
  }
  exit_clean();
  return 0;
}
// 40B5C8: variable 'v8' is possibly undefined
// 40B5C8: variable 'v9' is possibly undefined
// 40B5C8: variable 'v10' is possibly undefined
// 666174: using guessed type __int16 gl_httpd_https_port;
// 666176: using guessed type __int16 gl_httpd_tggl_port;
// 666178: using guessed type __int16 gl_httpd_port;
// 67D0A0: using guessed type int gl_hs_speed;
// 67D0B4: using guessed type int g_Raix_wsc_configured;
// 67D0B8: using guessed type int g_wsc_configured;
// 67D0BC: using guessed type int debug_level;
// 67D0C4: using guessed type int dword_67D0C4;
// 67D0C8: using guessed type int dword_67D0C8;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A8344: using guessed type int run_timers(void);
// 6A8400: using guessed type int __fastcall _get_cpu_uptime(_DWORD);
// 6A845C: using guessed type int __fastcall get_random_seed(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A8804: using guessed type int __fastcall get_uptime2(_DWORD);
// 6A8828: using guessed type int __fastcall nvram_getdef_int(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

