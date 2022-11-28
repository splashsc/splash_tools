int __fastcall sub_4B0DA8(int a1)
{
  char *v1; // $v0
  const char *v3; // $s0
  int v4; // $s2
  const char *v5; // $v0
  char *v6; // $v1
  int v7; // $t1
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  char *v12; // $v0
  int v13; // $a0
  char v14[512]; // [sp+18h] [-200h] BYREF

  v1 = httpd_get_parm(a1, "act");
  if ( v1 )
  {
    v3 = v1;
    v4 = jhl_get_3g_iface();
    if ( v4 >= 0 )
    {
      if ( !strcmp(v3, "stop") )
      {
        jhl_stop_3g(v4);
      }
      else if ( !strcmp(v3, "restart") )
      {
        v12 = (char *)nvram_get("wan_3g_connect_mode");
        if ( !v12 )
          v12 = "";
        if ( !memcmp(v12, "manual", 6u) )
          jhl_start_3g(v4);
      }
      else if ( !strcmp(v3, "empty") )
      {
        jhl_stop_3g(v4);
        nvram_set("saved_3g_flow", "0");
        nvram_set("saved_3g_flow_tmp", "0");
        jhl_parm_commit(v13);
      }
    }
  }
  v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v6 = v14;
  do
  {
    v7 = *(_DWORD *)v5;
    v8 = *((_DWORD *)v5 + 1);
    v9 = *((_DWORD *)v5 + 2);
    v10 = *((_DWORD *)v5 + 3);
    v5 += 16;
    *(_DWORD *)v6 = v7;
    *((_DWORD *)v6 + 1) = v8;
    *((_DWORD *)v6 + 2) = v9;
    *((_DWORD *)v6 + 3) = v10;
    v6 += 16;
  }
  while ( v5 != "}" );
  *(_WORD *)v6 = *(_WORD *)v5;
  return httpd_cgi_ret(a1, v14, 33, 4);
}
// 4B0F98: variable 'v13' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8504: using guessed type int __fastcall jhl_stop_3g(_DWORD);
// 6A880C: using guessed type int jhl_get_3g_iface(void);
// 6A884C: using guessed type int __fastcall jhl_start_3g(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

