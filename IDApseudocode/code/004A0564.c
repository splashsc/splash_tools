int __fastcall sub_4A0564(int a1)
{
  char *v2; // $s2
  char *v3; // $v0
  char *v4; // $s3
  const char *v5; // $s1
  int v6; // $v0
  const char *v7; // $a0
  const char **v8; // $v1
  const char *v9; // $v0
  const char *v10; // $t0
  const char *v11; // $a3
  const char *v12; // $a2
  const char *v13; // $a1
  unsigned int v14; // $a2
  const char *v16; // $t0
  const char *v17; // $a3
  const char *v18; // $a2
  const char *v19; // $a1
  int v20; // $a1
  const char *v21; // $a2
  const char *v22; // $v0
  const char *v23; // [sp+20h] [-84h] BYREF
  const char *v24; // [sp+24h] [-80h]
  int v25; // [sp+28h] [-7Ch]
  int v26; // [sp+2Ch] [-78h]
  int v27; // [sp+30h] [-74h]

  v2 = httpd_get_parm(a1, "iface");
  v4 = httpd_get_parm(a1, "time");
  v3 = httpd_get_parm(a1, "opt");
  if ( !v3 )
    goto LABEL_18;
  v5 = v3;
  if ( !strcmp(v3, "stop") )
  {
    killall_tk("speedTest");
    nvram_set("speed_test_result", "");
    v8 = &v23;
    v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v16 = *(const char **)v9;
      v17 = (const char *)*((_DWORD *)v9 + 1);
      v18 = (const char *)*((_DWORD *)v9 + 2);
      v19 = (const char *)*((_DWORD *)v9 + 3);
      v9 += 16;
      *v8 = v16;
      v8[1] = v17;
      v8[2] = v18;
      v8[3] = v19;
      v8 += 4;
    }
    while ( v9 != "}" );
    goto LABEL_10;
  }
  if ( v2 )
  {
    if ( v4 )
    {
      nvram_set("speed_test_time", v4);
      nvram_set("speed_test_iface", v2);
      nvram_set("speed_test_result", "");
      if ( !strcmp(v5, "save") )
      {
        v23 = "speed_test_del.sh";
        v24 = "speed_test";
        v25 = 0;
        eval(&v23, 0, 0, 0);
        v6 = strcmp(v4, "OFF");
        v7 = "speed_test_time";
        if ( v6 )
        {
          v23 = "speed_test_add.sh";
          v24 = "speed_test";
          v25 = jhl_nv_get_def("speed_test_time");
          v26 = jhl_nv_get_def("speed_test_iface");
          v27 = 0;
          eval(&v23, 0, 0, 0);
        }
LABEL_8:
        jhl_parm_commit(v7);
        v8 = &v23;
        v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v10 = *(const char **)v9;
          v11 = (const char *)*((_DWORD *)v9 + 1);
          v12 = (const char *)*((_DWORD *)v9 + 2);
          v13 = (const char *)*((_DWORD *)v9 + 3);
          v9 += 16;
          *v8 = v10;
          v8[1] = v11;
          v8[2] = v12;
          v8[3] = v13;
          v8 += 4;
        }
        while ( v9 != "}" );
LABEL_10:
        v14 = 33;
        *(_WORD *)v8 = *(_WORD *)v9;
        return httpd_cgi_ret(a1, (char *)&v23, v14, 4);
      }
LABEL_13:
      if ( !strcmp(v5, "speedtest") )
      {
        killall_tk("speedTest");
        v23 = "speedTest";
        v24 = v2;
        v25 = 0;
        eval_nowait(&v23, 0, 0, 0);
      }
      goto LABEL_8;
    }
    nvram_set("speed_test_iface", v2);
    nvram_set("speed_test_result", "");
    if ( strcmp(v5, "save") )
      goto LABEL_13;
    v20 = *(unsigned __int8 *)(a1 + 210102);
    v21 = (const char *)&unk_646EE4;
  }
  else
  {
LABEL_18:
    v20 = *(unsigned __int8 *)(a1 + 210102);
    v21 = "not opt or iface";
  }
  v22 = (const char *)_GET_LANG_TEXT(12, v20, v21);
  v14 = snprintf((char *)&v23, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v22);
  if ( v14 >= 0x80 )
    v14 = 127;
  return httpd_cgi_ret(a1, (char *)&v23, v14, 4);
}
// 4A06F8: variable 'v7' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

