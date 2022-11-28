int __fastcall sub_4A1BEC(int a1)
{
  char *v2; // $s4
  char *v3; // $s5
  char *v4; // $s3
  char *v5; // $v0
  char *v6; // $s2
  const char *v7; // $s1
  char *v8; // $s2
  int v9; // $s2
  const char *v11; // $v0
  char *v12; // $v1
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  int v16; // $a1
  int *v17; // $v0
  int v18; // $v0
  int v19; // $s3
  unsigned int v20; // $v0
  int v21; // $a1
  int v22; // $v0
  int v23; // $a1
  char v24[256]; // [sp+20h] [-18Ch] BYREF
  int v25[32]; // [sp+120h] [-8Ch] BYREF
  int v26[3]; // [sp+1A0h] [-Ch] BYREF

  v26[0] = 0;
  v2 = httpd_get_parm(a1, "addr");
  v3 = httpd_get_parm(a1, "hops");
  v4 = httpd_get_parm(a1, "wait");
  v6 = httpd_get_parm(a1, "dev");
  v5 = httpd_get_parm(a1, "opt");
  if ( !v5 )
  {
    if ( !v6 || !*v6 )
      goto LABEL_14;
    if ( !strnicmp(v6, &off_645568, 3) )
    {
      v21 = atoi(v6 + 3) - 1;
    }
    else
    {
      if ( !strcmp(v6, (const char *)&off_64CCE8) )
      {
        v6 = (char *)nvram_get("lan_ifname");
        if ( v6 )
        {
          if ( v3 )
            goto LABEL_16;
          goto LABEL_35;
        }
        goto LABEL_34;
      }
      if ( !strnicmp(v6, "vpn", 3) )
      {
        v23 = atoi(v6 + 3) - 1;
        v22 = jhl_vpnget(&unk_645880, v23);
LABEL_33:
        v6 = (char *)nvram_get(v22);
        if ( !v6 )
        {
LABEL_34:
          v6 = "";
          if ( v3 )
            goto LABEL_16;
          goto LABEL_35;
        }
LABEL_15:
        if ( v3 )
        {
LABEL_16:
          if ( !v4 )
            v4 = "2";
          v17 = v25;
          do
            *v17++ = 0;
          while ( &v25[12] != v17 );
          v25[3] = (int)v3;
          v25[0] = (int)"traceroute";
          v25[5] = (int)v4;
          v25[1] = (int)&unk_64CCF8;
          v25[2] = (int)"-m";
          v25[4] = (int)"-w";
          if ( v6 )
          {
            v25[7] = (int)v6;
            v25[6] = (int)"-i";
            v18 = 8;
          }
          else
          {
            v18 = 6;
          }
          *(_DWORD *)&v24[4 * v18 + 256] = v2;
          eval_nowait_file(v25, ">>/tmp/trace", 0, v26);
          strcpy(v24, "{\"code\":0,\"error\":\"\",\"data\":{");
          v19 = sprintf(&v24[29], "\"msg\":\"trace...\",\"pid\":\"%d\"", v26[0]) + 29;
          v20 = snprintf(&v24[v19], 256 - v19, "}}");
          if ( v20 >= 256 - v19 )
            v20 = 255 - v19;
          httpd_cgi_ret(a1, v24, v20 + v19, 4);
          return 0;
        }
LABEL_35:
        v3 = "20";
        goto LABEL_16;
      }
      if ( strcmp(v6, "3G") && strcmp(v6, "4G") && strcmp(v6, "5G") )
        goto LABEL_15;
      v21 = jhl_get_3g_iface();
      if ( v21 < 0 )
      {
LABEL_14:
        v6 = 0;
        goto LABEL_15;
      }
    }
    v22 = jhl_nvget("wan_name", v21);
    goto LABEL_33;
  }
  v7 = v5;
  v8 = httpd_get_parm(a1, (char *)&off_64CC40);
  memset(v25, 0, sizeof(v25));
  if ( v8 )
  {
    v9 = J_atoi(v8);
    if ( !strcmp(v7, "stop") )
    {
      if ( v9 >= 2 )
      {
        kill_by_pid_name(v9, "traceroute", 15, 9, 0);
        return trace_data(a1);
      }
    }
    else if ( !strcmp(v7, "back") && v9 >= 2 )
    {
      kill_by_pid_name(v9, "traceroute", 15, 9, 0);
      sprintf((char *)v25, "/tmp/trace_%d", v9);
      unlink((const char *)v25);
    }
  }
  v11 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v12 = v24;
  do
  {
    v13 = *(_DWORD *)v11;
    v14 = *((_DWORD *)v11 + 1);
    v15 = *((_DWORD *)v11 + 2);
    v16 = *((_DWORD *)v11 + 3);
    v11 += 16;
    *(_DWORD *)v12 = v13;
    *((_DWORD *)v12 + 1) = v14;
    *((_DWORD *)v12 + 2) = v15;
    *((_DWORD *)v12 + 3) = v16;
    v12 += 16;
  }
  while ( v11 != "}" );
  *(_WORD *)v12 = *(_WORD *)v11;
  return httpd_cgi_ret(a1, v24, 33, 4);
}
// 642164: using guessed type __int16 word_642164;
// 645568: using guessed type void *off_645568;
// 64CC40: using guessed type void *off_64CC40;
// 64CCE8: using guessed type void *off_64CCE8;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8640: using guessed type int __fastcall eval_nowait_file(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A880C: using guessed type int jhl_get_3g_iface(void);
// 6A88B8: using guessed type int __fastcall strnicmp(_DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);
// 6A89A0: using guessed type int __fastcall kill_by_pid_name(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

