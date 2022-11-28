int __fastcall sub_48B02C(int a1)
{
  char *v2; // $a1
  int v3; // $a0
  char *v4; // $v1
  const char *v5; // $v0
  int v6; // $t1
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  char v11[256]; // [sp+18h] [-100h] BYREF

  v2 = httpd_get_parm(a1, "debug");
  if ( !v2 )
  {
    if ( jhl_web_save_parms(a1, pptp_parms, 1) )
    {
      jhl_stop_pptpd_srv();
      jhl_start_pptpd_srv();
      if ( !jhl_web_save_parms(a1, l2tp_parms, 1) )
        goto LABEL_9;
    }
    else if ( !jhl_web_save_parms(a1, l2tp_parms, 1) )
    {
      goto LABEL_3;
    }
    jhl_stop_l2tpd_srv();
    jhl_start_l2tpd_srv();
LABEL_9:
    jhl_setwanxx();
    goto LABEL_3;
  }
  nvram_set("debug_pppd", v2);
LABEL_3:
  jhl_parm_commit(v3);
  v4 = v11;
  v5 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v6 = *(_DWORD *)v5;
    v7 = *((_DWORD *)v5 + 1);
    v8 = *((_DWORD *)v5 + 2);
    v9 = *((_DWORD *)v5 + 3);
    v5 += 16;
    *(_DWORD *)v4 = v6;
    *((_DWORD *)v4 + 1) = v7;
    *((_DWORD *)v4 + 2) = v8;
    *((_DWORD *)v4 + 3) = v9;
    v4 += 16;
  }
  while ( v5 != "}" );
  *(_WORD *)v4 = *(_WORD *)v5;
  return httpd_cgi_ret(a1, v11, 33, 4);
}
// 48B08C: variable 'v3' is possibly undefined
// 672EF4: using guessed type char *l2tp_parms[6];
// 672F14: using guessed type char *pptp_parms[8];
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81A8: using guessed type int jhl_start_pptpd_srv(void);
// 6A81F0: using guessed type int jhl_stop_l2tpd_srv(void);
// 6A8210: using guessed type int jhl_start_l2tpd_srv(void);
// 6A82B8: using guessed type int jhl_setwanxx(void);
// 6A85E8: using guessed type int jhl_stop_pptpd_srv(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

