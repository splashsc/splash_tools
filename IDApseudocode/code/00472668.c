int __fastcall sub_472668(int a1)
{
  int v2; // $a2
  int v3; // $v0
  int v4; // $a0
  char *v5; // $v1
  const char *v6; // $v0
  int v7; // $t1
  int v8; // $t0
  int v9; // $a3
  int v10; // $a2
  char v12[1024]; // [sp+18h] [-400h] BYREF

  nvram_set("wt_router_id", "");
  nvram_set("wt_dev_addr", "");
  nvram_set("wt_dev_cont", "");
  nvram_set("wt_dev_tel", "");
  nvram_set("wt_dev_name", "");
  nvram_set("wt_dev_dinate", "");
  nvram_set("wt_agent_id", "");
  nvram_set("wt_dev_pwd", "");
  nvram_set("wt_route_type", "0");
  nvram_set("wt_dev_replace_id", "0");
  nvram_set("wt_dev_routerid", "0");
  nvram_set("wt_dev_randid", "0");
  v3 = _GET_LANG_TEXT(53, *(unsigned __int8 *)(a1 + 210102), v2);
  nvram_set("ac_mng_state", v3);
  nvram_set("wt_dev_type", "0");
  nvram_set("wt_dev_offlinenotauth", "65");
  nvram_set("wt_third_agent_id", "");
  nvram_set("wt_nofeel_auth_id", "56");
  nvram_set("rzglType", "0");
  start_rzgl(0);
  wt_client_restart(0);
  mng_client_restart(0);
  jhl_parm_commit(v4);
  v5 = v12;
  v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v7 = *(_DWORD *)v6;
    v8 = *((_DWORD *)v6 + 1);
    v9 = *((_DWORD *)v6 + 2);
    v10 = *((_DWORD *)v6 + 3);
    v6 += 16;
    *(_DWORD *)v5 = v7;
    *((_DWORD *)v5 + 1) = v8;
    *((_DWORD *)v5 + 2) = v9;
    *((_DWORD *)v5 + 3) = v10;
    v5 += 16;
  }
  while ( v6 != "}" );
  *(_WORD *)v5 = *(_WORD *)v6;
  return httpd_cgi_ret(a1, v12, 33, 4);
}
// 4727F8: variable 'v2' is possibly undefined
// 472908: variable 'v4' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8354: using guessed type int __fastcall wt_client_restart(_DWORD);
// 6A83A0: using guessed type int __fastcall mng_client_restart(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

