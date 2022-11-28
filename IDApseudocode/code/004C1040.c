int __fastcall sub_4C1040(int a1)
{
  char *v1; // $v0
  char *v3; // $s0
  const char **v4; // $v1
  const char *v5; // $v0
  const char *v6; // $t0
  const char *v7; // $a3
  const char *v8; // $a2
  const char *v9; // $a1
  int v11; // $a0
  const char *v12; // [sp+18h] [-80h] BYREF
  int v13; // [sp+1Ch] [-7Ch]

  v1 = httpd_get_parm(a1, "gw_en");
  if ( v1 )
  {
    v3 = v1;
    if ( !nvram_match_def("ping_wan_gw", v1) )
    {
      nvram_set("ping_wan_gw", v3);
      killall_tk("ping_wangw_ck");
      killall_tk("ping_wangw_run");
      if ( nvram_match_def("ping_wan_gw", "1") )
      {
        v12 = "ping_wangw_ck";
        v13 = 0;
        eval_nowait(&v12, 0, 0, 0);
      }
      v12 = "ping_wangw_run";
      v13 = 0;
      eval_nowait(&v12, 0, 0, 0);
      jhl_parm_commit(v11);
    }
  }
  v4 = &v12;
  v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v6 = *(const char **)v5;
    v7 = (const char *)*((_DWORD *)v5 + 1);
    v8 = (const char *)*((_DWORD *)v5 + 2);
    v9 = (const char *)*((_DWORD *)v5 + 3);
    v5 += 16;
    *v4 = v6;
    v4[1] = v7;
    v4[2] = v8;
    v4[3] = v9;
    v4 += 4;
  }
  while ( v5 != "}" );
  *(_WORD *)v4 = *(_WORD *)v5;
  return httpd_cgi_ret(a1, (char *)&v12, 33, 4);
}
// 4C11CC: variable 'v11' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

