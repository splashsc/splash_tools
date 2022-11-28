int __fastcall sub_4A2640(int a1)
{
  char *v2; // $s4
  char *v3; // $s3
  char *v4; // $s2
  int v5; // $a0
  char *v6; // $s5
  int v7; // $s4
  char *v8; // $v1
  const char *v9; // $v0
  int v10; // $t0
  int v11; // $a3
  int v12; // $a2
  int v13; // $a1
  char v15[256]; // [sp+18h] [-110h] BYREF
  int v16[4]; // [sp+118h] [-10h] BYREF

  memset(v15, 0, sizeof(v15));
  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "name");
  v4 = httpd_get_parm(a1, "phone");
  v6 = httpd_get_parm(a1, "type");
  if ( v2 && !nvram_match_def("alert_weixin_en", v2) )
  {
    nvram_set("alert_weixin_en", v2);
    if ( nvram_match_def("alert_weixin_en", "1") )
    {
      v16[0] = (int)"alert_log_send";
      v16[1] = (int)"0";
      v16[2] = 0;
      eval_nowait(v16, 0, 0, 0);
    }
    else
    {
      killall_tk("alert_log_send");
    }
    v7 = 1;
  }
  else
  {
    v7 = 0;
  }
  if ( v3 && !nvram_match_def("alert_weixin_name", v3) )
  {
    nvram_set("alert_weixin_name", v3);
    ++v7;
  }
  if ( v4 && !nvram_match_def("alert_weixin_phone", v4) )
  {
    nvram_set("alert_weixin_phone", v4);
    if ( !v6 || nvram_match_def("alert_weixin_type", v6) )
      goto LABEL_18;
    goto LABEL_17;
  }
  if ( v6 && !nvram_match_def("alert_weixin_type", v6) )
  {
LABEL_17:
    nvram_set("alert_weixin_type", v6);
    goto LABEL_18;
  }
  if ( v7 )
LABEL_18:
    jhl_parm_commit(v5);
  v8 = v15;
  v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v10 = *(_DWORD *)v9;
    v11 = *((_DWORD *)v9 + 1);
    v12 = *((_DWORD *)v9 + 2);
    v13 = *((_DWORD *)v9 + 3);
    v9 += 16;
    *(_DWORD *)v8 = v10;
    *((_DWORD *)v8 + 1) = v11;
    *((_DWORD *)v8 + 2) = v12;
    *((_DWORD *)v8 + 3) = v13;
    v8 += 16;
  }
  while ( v9 != "}" );
  *(_WORD *)v8 = *(_WORD *)v9;
  return httpd_cgi_ret(a1, v15, 33, 4);
}
// 4A2890: variable 'v5' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

