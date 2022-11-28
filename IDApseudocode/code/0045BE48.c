int __fastcall sub_45BE48(int a1)
{
  char *v2; // $s6
  char *v3; // $s5
  char *v4; // $s4
  char *v5; // $s3
  char *v6; // $s7
  int v7; // $s6
  const char *v9; // $v0
  int v10; // $s4
  char *v11; // $s5
  const char *v12; // $v0
  char *v13; // $v0
  char *v14; // $v0
  char v15[1024]; // [sp+18h] [-440h] BYREF
  int v16[10]; // [sp+418h] [-40h] BYREF
  char *v17; // [sp+440h] [-18h]
  char *v18; // [sp+444h] [-14h]
  char *v19; // [sp+448h] [-10h]
  char *v20; // [sp+44Ch] [-Ch]
  char *v21; // [sp+450h] [-8h]

  v19 = "a";
  v20 = "a";
  v2 = httpd_get_parm(a1, "proxy_en");
  v17 = httpd_get_parm(a1, "proxy_srv");
  v18 = "a";
  v3 = httpd_get_parm(a1, "proxy_srvport");
  v4 = httpd_get_parm(a1, "proxy_lanip");
  v5 = httpd_get_parm(a1, "proxy_lanport");
  v21 = v15;
  v6 = httpd_get_parm(a1, "proxy_port");
  memset(v15, 0, sizeof(v15));
  if ( v2 && !nvram_match_def("proxy_en", v2) )
  {
    nvram_set("proxy_en", v2);
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  if ( v17 && !nvram_match_def(v19 + 24976, v17) )
    v7 = 1;
  if ( v3 && !nvram_match_def(v20 + 24988, v3) )
  {
    nvram_set("proxy_srvport", v3);
    v7 = 1;
  }
  if ( v4 && !nvram_match_def("proxy_lanip", v4) )
  {
    nvram_set("proxy_lanip", v4);
    v7 = 1;
  }
  if ( v5 && !nvram_match_def(v18 + 25040, v5) )
  {
    nvram_set("proxy_lanport", v5);
    if ( !v6 || nvram_match_def("proxy_port", v6) )
      goto LABEL_23;
  }
  else if ( !v6 || nvram_match_def("proxy_port", v6) )
  {
    if ( !v7 )
      return proxy_client_data(a1);
    goto LABEL_23;
  }
  nvram_set("proxy_port", v6);
LABEL_23:
  v9 = (const char *)nvram_get("proxy_pid");
  if ( !v9 )
    v9 = "-1";
  v10 = J_atoi(v9);
  if ( v10 > 0 )
  {
    v11 = v21;
    memset(v21, 0, 0x400u);
    snprintf(v11, 1024, "kill -9 %d", v10);
    system(v11);
    if ( !nvram_get("proxy_msg") )
      get_web_language_type(a1);
    nvram_set("proxy_pid", "-1");
    nvram_set("proxy_port", "");
  }
  v12 = (const char *)nvram_get("proxy_en");
  if ( v12 && !strcmp(v12, "1") )
  {
    v16[0] = (int)"proxy_client";
    v16[1] = jhl_nv_get_def(v19 + 24976);
    v16[2] = jhl_nv_get_def(v20 + 24988);
    v13 = (char *)nvram_get("proxy_lanip");
    if ( !v13 )
      v13 = "";
    v16[3] = (int)v13;
    v14 = (char *)nvram_get(v18 + 25040);
    if ( !v14 )
      v14 = "";
    v16[4] = (int)v14;
    v16[5] = (int)"proxy_port";
    v16[6] = (int)"proxy_msg";
    v16[7] = (int)"proxy_pid";
    v16[8] = 0;
    eval_nowait(v16, 0, 0, 0);
  }
  return proxy_client_data(a1);
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

