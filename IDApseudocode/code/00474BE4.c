int __fastcall sub_474BE4(int a1)
{
  char *v2; // $s2
  char *v3; // $s3
  char *v4; // $s4
  char *v5; // $s5
  const char *v6; // $v0
  int v7; // $a0
  const char *v8; // $v0
  int v9; // $s3
  bool v10; // dc
  char *v11; // $v1
  const char *v12; // $v0
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  int v16; // $a1
  int v18; // $v0
  int v19; // $a2
  const char *v20; // $v0
  unsigned int v21; // $v0
  char v22[256]; // [sp+20h] [-100h] BYREF

  memset(v22, 0, sizeof(v22));
  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "rname");
  v4 = httpd_get_parm(a1, "dev_pwd");
  v5 = httpd_get_parm(a1, "ipoff_en");
  v6 = (const char *)jhl_nv_get_def("dual_lan_mode");
  if ( !strcmp(v6, "1") || (v8 = (const char *)nvram_get("wt_base_enable")) == 0 || strcmp(v8, "1") || !J_atoi(v2) )
  {
    if ( v3 && !nvram_match_def("billing_rname", v3) )
    {
      nvram_set("billing_rname", v3);
      v9 = 1;
    }
    else
    {
      v9 = 0;
    }
    if ( v4 && !nvram_match_def("billing_dev_pwd", v4) )
    {
      nvram_set("billing_dev_pwd", v4);
      v9 = 1;
    }
    if ( v5 && !nvram_match_def("billing_no_ipoff", v5) )
    {
      nvram_set("billing_no_ipoff", v5);
      if ( !v2 || nvram_match_def("billing_en", v2) )
        goto LABEL_21;
    }
    else if ( !v2 || nvram_match_def("billing_en", v2) )
    {
      v10 = v9 != 0;
      v9 = 1;
      if ( !v10 )
      {
LABEL_15:
        v11 = v22;
        v12 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v13 = *(_DWORD *)v12;
          v14 = *((_DWORD *)v12 + 1);
          v15 = *((_DWORD *)v12 + 2);
          v16 = *((_DWORD *)v12 + 3);
          v12 += 16;
          *(_DWORD *)v11 = v13;
          *((_DWORD *)v11 + 1) = v14;
          *((_DWORD *)v11 + 2) = v15;
          *((_DWORD *)v11 + 3) = v16;
          v11 += 16;
        }
        while ( v12 != "}" );
        *(_WORD *)v11 = *(_WORD *)v12;
        return httpd_cgi_ret(a1, v22, 33, 4);
      }
LABEL_21:
      jhl_parm_commit(v7);
      if ( v9 )
        restart_wys_billing();
      goto LABEL_15;
    }
    nvram_set("billing_en", v2);
    v9 = 1;
    v18 = reset_billing_rzgl_parm(v2);
    start_rzgl(v18);
    goto LABEL_21;
  }
  v20 = (const char *)_GET_LANG_TEXT(54, *(unsigned __int8 *)(a1 + 210102), v19);
  v21 = snprintf(v22, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v20);
  if ( v21 >= 0x100 )
    v21 = 255;
  return httpd_cgi_ret(a1, v22, v21, 4);
}
// 474EDC: variable 'v7' is possibly undefined
// 474F6C: variable 'v19' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82B0: using guessed type int __fastcall reset_billing_rzgl_parm(_DWORD);
// 6A82BC: using guessed type int restart_wys_billing(void);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

