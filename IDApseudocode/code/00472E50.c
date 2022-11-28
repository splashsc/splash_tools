int __fastcall sub_472E50(int a1)
{
  char *v2; // $s5
  char *v3; // $s4
  char *v4; // $s3
  char *v5; // $s6
  int v6; // $a0
  char *v7; // $s2
  int v8; // $s5
  int v9; // $s4
  char *v10; // $v1
  const char *v11; // $v0
  int v12; // $t0
  int v13; // $a3
  int v14; // $a2
  int v15; // $a1
  char v17[260]; // [sp+18h] [-104h] BYREF

  memset(v17, 0, 0x100u);
  v2 = httpd_get_parm(a1, "svr_host");
  v3 = httpd_get_parm(a1, "svr_port");
  v4 = httpd_get_parm(a1, "agt_host");
  v5 = httpd_get_parm(a1, "api_port");
  v7 = httpd_get_parm(a1, "api_type");
  if ( v2 && !nvram_match_def("mqtt_cbg_svr_host", v2) )
  {
    nvram_set("mqtt_cbg_svr_host", v2);
    v8 = 1;
  }
  else
  {
    v8 = 0;
  }
  if ( v3 && !nvram_match_def("mqtt_cbg_svr_port", v3) )
  {
    nvram_set("mqtt_cbg_svr_port", v3);
    v9 = 1;
  }
  else
  {
    v9 = v8;
  }
  if ( v4 && !nvram_match_def(&unk_6487EC, v4) )
  {
    nvram_set(&unk_6487EC, v4);
    v9 = 1;
  }
  if ( !v7 || nvram_match_def("billing_api_type", v7) )
  {
    if ( !v5 || nvram_match_def("billing_api_port", v5) )
    {
      if ( !v9 )
        goto LABEL_15;
      goto LABEL_21;
    }
    goto LABEL_20;
  }
  nvram_set("billing_api_type", v7);
  if ( v5 && !nvram_match_def("billing_api_port", v5) )
LABEL_20:
    nvram_set("billing_api_port", v5);
LABEL_21:
  jhl_parm_commit(v6);
  if ( nvram_match_def("billing_en", "1") )
  {
    start_rzgl(v8);
    restart_wys_billing();
  }
LABEL_15:
  v10 = v17;
  v11 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v12 = *(_DWORD *)v11;
    v13 = *((_DWORD *)v11 + 1);
    v14 = *((_DWORD *)v11 + 2);
    v15 = *((_DWORD *)v11 + 3);
    v11 += 16;
    *(_DWORD *)v10 = v12;
    *((_DWORD *)v10 + 1) = v13;
    *((_DWORD *)v10 + 2) = v14;
    *((_DWORD *)v10 + 3) = v15;
    v10 += 16;
  }
  while ( v11 != "}" );
  *(_WORD *)v10 = *(_WORD *)v11;
  return httpd_cgi_ret(a1, v17, 33, 4);
}
// 4730F0: variable 'v6' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82BC: using guessed type int restart_wys_billing(void);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);

