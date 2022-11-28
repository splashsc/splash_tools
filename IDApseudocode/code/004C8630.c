int __fastcall sub_4C8630(int a1)
{
  char *v2; // $s1
  char *v3; // $s2
  char *v4; // $v0
  char *v5; // $s4
  char *v6; // $s3
  int v7; // $a2
  const char *v9; // $a1
  const char *v10; // $v0
  _DWORD *v11; // $v1
  int v12; // $t0
  int v13; // $a3
  int v14; // $a2
  int v15; // $a1
  const char *v16; // $v0
  _DWORD *v17; // $v1
  int v18; // $t0
  int v19; // $a3
  int v20; // $a2
  int v21; // $a1
  int v22; // $a0
  __int16 v23; // $v0
  const char *v24; // $v0
  _DWORD *v25; // $v1
  int v26; // $t0
  int v27; // $a3
  int v28; // $a2
  int v29; // $a1
  int v30; // $a0
  char v31; // $v0
  _DWORD v32[7]; // [sp+18h] [-400h] BYREF
  const char *v33; // [sp+34h] [-3E4h]
  char *v34; // [sp+38h] [-3E0h]
  int v35; // [sp+3Ch] [-3DCh]

  v2 = httpd_get_parm(a1, "mode");
  v3 = httpd_get_parm(a1, "action");
  v5 = httpd_get_parm(a1, "ip");
  v4 = httpd_get_parm(a1, "port");
  if ( v2 && v3 )
  {
    v6 = v4;
    if ( !strcmp(v2, "server") )
    {
      if ( !strcmp(v3, "start") )
      {
        if ( v6 && J_atoi(v6) )
        {
          v32[0] = "iperf";
          v32[1] = "-s";
          v32[2] = "-p";
          v32[3] = v6;
          v32[4] = "-D";
          v32[5] = 0;
          eval_nowait(v32, 0, 0, 0);
        }
        else
        {
          v32[0] = "iperf";
          v32[1] = "-s";
          v32[2] = "-D";
          v32[3] = 0;
          eval_nowait(v32, 0, 0, 0);
        }
        goto LABEL_8;
      }
      if ( !strcmp(v3, "stop") )
      {
        v9 = "-s";
LABEL_20:
        killall_arg("iperf", v9, 9);
LABEL_8:
        v7 = 16;
        strcpy((char *)v32, "{ret:0,msg:'ok'}");
        return httpd_cgi_ret(a1, (char *)v32, v7, 4);
      }
LABEL_21:
      v10 = "{ret:-1,msg:'aciton is start/stop'}";
      v11 = v32;
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
      while ( v10 != "p'}" );
      v7 = 35;
      *v11 = *(_DWORD *)v10;
      return httpd_cgi_ret(a1, (char *)v32, v7, 4);
    }
    if ( !strcmp(v2, "client") )
    {
      if ( !strcmp(v3, "start") )
      {
        v7 = 25;
        if ( !v5 )
        {
          strcpy((char *)v32, "{ret:-1,msg:'ip is null'}");
          return httpd_cgi_ret(a1, (char *)v32, v7, 4);
        }
        if ( v6 && J_atoi(v6) )
        {
          v32[0] = "iperf";
          v32[1] = "-c";
          v32[3] = "-p";
          v32[5] = "-t";
          v32[6] = "86400000";
          v33 = "-P";
          v32[2] = v5;
          v32[4] = v6;
          v34 = "10";
          v35 = 0;
          eval_nowait(v32, 0, 0, 0);
        }
        else
        {
          v32[0] = "iperf";
          v32[1] = "-c";
          v32[3] = "-t";
          v32[4] = "86400000";
          v32[5] = "-P";
          v32[2] = v5;
          v32[6] = "10";
          v33 = 0;
          eval_nowait(v32, 0, 0, 0);
        }
        goto LABEL_8;
      }
      if ( !strcmp(v3, "stop") )
      {
        v9 = "-c";
        goto LABEL_20;
      }
      goto LABEL_21;
    }
    v24 = "{ret:-1,msg:'mode is server/client'}";
    v25 = v32;
    do
    {
      v26 = *(_DWORD *)v24;
      v27 = *((_DWORD *)v24 + 1);
      v28 = *((_DWORD *)v24 + 2);
      v29 = *((_DWORD *)v24 + 3);
      v24 += 16;
      *v25 = v26;
      v25[1] = v27;
      v25[2] = v28;
      v25[3] = v29;
      v25 += 4;
    }
    while ( v24 != "nt'}" );
    v30 = *(_DWORD *)v24;
    v31 = v24[4];
    *v25 = v30;
    *((_BYTE *)v25 + 4) = v31;
    v7 = 36;
  }
  else
  {
    v16 = "{ret:-1,msg:'mode or action is null'}";
    v17 = v32;
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
    while ( v16 != "ull'}" );
    v22 = *(_DWORD *)v16;
    v23 = *((_WORD *)v16 + 2);
    *v17 = v22;
    *((_WORD *)v17 + 2) = v23;
    v7 = 37;
  }
  return httpd_cgi_ret(a1, (char *)v32, v7, 4);
}
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A866C: using guessed type int __fastcall killall_arg(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

