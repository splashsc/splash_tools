int __fastcall sub_45195C(int a1)
{
  char *v2; // $s1
  char *v3; // $s0
  int v4; // $v0
  int v5; // $v0
  char *v6; // $s1
  int v7; // $a0
  int v8; // $a2
  const char *v10; // $v0
  int *v11; // $v1
  int v12; // $t0
  int v13; // $a3
  int v14; // $a2
  int v15; // $a1
  const char *v16; // $v0
  int *v17; // $v1
  int v18; // $t0
  int v19; // $a3
  int v20; // $a2
  int v21; // $a1
  __int16 v22; // $a0
  char v23; // $v0
  int v24[256]; // [sp+18h] [-40Ch] BYREF
  int v25; // [sp+418h] [-Ch]

  v2 = httpd_get_parm(a1, "iface");
  v3 = httpd_get_parm(a1, "type");
  if ( v2 )
  {
    v4 = J_atoi(v2);
  }
  else
  {
    v4 = get_speed_test_iface();
    if ( v4 < 0 )
    {
      v16 = "{\"code\":\"-1\",\"msg\":\"There is no interface for speed measurement!\"}";
      v17 = v24;
      do
      {
        v18 = *(_DWORD *)v16;
        v19 = *((_DWORD *)v16 + 1);
        v20 = *((_DWORD *)v16 + 2);
        v21 = *((_DWORD *)v16 + 3);
        v16 += 16;
        *v17 = v18;
        v17[1] = v19;
        v17[2] = v20;
        v17[3] = v21;
        v17 += 4;
      }
      while ( v16 != "\"}" );
      v22 = *(_WORD *)v16;
      v23 = v16[2];
      *(_WORD *)v17 = v22;
      *((_BYTE *)v17 + 2) = v23;
      v8 = 66;
      return httpd_cgi_ret(a1, (char *)v24, v8, 4);
    }
  }
  v5 = jhl_nvget("wan_name", v4);
  v6 = (char *)nvram_get(v5);
  if ( v6 )
  {
    if ( v3 )
      goto LABEL_5;
  }
  else
  {
    v6 = "";
    if ( v3 )
    {
LABEL_5:
      if ( !strcmp(v3, "stop") )
      {
        killall_tk("speedTest");
        v25 = speed_test_info_get((char *)v24, 1024);
        nvram_set("speed_test_result", "");
        v8 = v25;
        return httpd_cgi_ret(a1, (char *)v24, v8, 4);
      }
      nvram_set("speed_test_iface", v6);
      nvram_set("speed_test_result", "");
      if ( !strcmp(v3, "start") )
      {
        nvram_set("speed_test_isp", "");
        nvram_set("speed_test_server", "");
        nvram_set("speed_test_download", "");
        nvram_set("speed_test_upload", "");
        killall_tk("speedTest");
        v24[0] = (int)"speedTest";
        v24[1] = (int)v6;
        v24[2] = 0;
        eval_nowait(v24, 0, 0, 0);
      }
      else if ( !strcmp(v3, "result") || !strcmp(v3, "info") )
      {
        goto LABEL_10;
      }
      jhl_parm_commit(v7);
LABEL_10:
      v8 = speed_test_info_get((char *)v24, 1024);
      return httpd_cgi_ret(a1, (char *)v24, v8, 4);
    }
  }
  v10 = "{\"code\":\"-1\",\"msg\":\"type null!\"}";
  v11 = v24;
  do
  {
    v12 = *(_DWORD *)v10;
    v13 = *((_DWORD *)v10 + 1);
    v14 = *((_DWORD *)v10 + 2);
    v15 = *((_DWORD *)v10 + 3);
    v10 += 16;
    *v11 = v12;
    v11[1] = v13;
    v11[2] = v14;
    v11[3] = v15;
    v11 += 4;
  }
  while ( v10 != "" );
  v8 = 32;
  *(_BYTE *)v11 = *v10;
  return httpd_cgi_ret(a1, (char *)v24, v8, 4);
}
// 451AE0: variable 'v7' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82E4: using guessed type int __fastcall killall_tk(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

