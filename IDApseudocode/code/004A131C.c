int __fastcall sub_4A131C(int a1)
{
  char *v2; // $s3
  char *v3; // $s5
  char *v4; // $s4
  char *v5; // $s2
  char *v6; // $v0
  char *v7; // $s1
  char *v8; // $s2
  int v9; // $s2
  const char *v11; // $v0
  char *v12; // $v1
  int v13; // $t0
  int v14; // $a3
  int v15; // $a2
  int v16; // $a1
  const char *v17; // $s6
  int *v18; // $v0
  int v19; // $v0
  int v20; // $s3
  unsigned int v21; // $v0
  int v22; // $a1
  int v23; // $v0
  int v24; // $a1
  char v25[256]; // [sp+20h] [-18Ch] BYREF
  int v26[32]; // [sp+120h] [-8Ch] BYREF
  int v27[3]; // [sp+1A0h] [-Ch] BYREF

  v27[0] = 0;
  v2 = httpd_get_parm(a1, "addr");
  v3 = httpd_get_parm(a1, "count");
  v4 = httpd_get_parm(a1, "size");
  v5 = httpd_get_parm(a1, "dev");
  v7 = httpd_get_parm(a1, "opt");
  v6 = httpd_get_parm(a1, "ipv");
  if ( !v7 )
  {
    v17 = v6;
    if ( !v5 )
      goto LABEL_15;
    if ( !*v5 )
    {
      v5 = 0;
      goto LABEL_15;
    }
    if ( strnicmp(v5, &off_645568, 3) )
    {
      if ( !strcmp(v5, (const char *)&off_64CCE8) )
      {
        v5 = (char *)nvram_get("lan_ifname");
        if ( !v5 )
        {
LABEL_35:
          v5 = "";
          goto LABEL_15;
        }
      }
      else
      {
        if ( !strnicmp(v5, "vpn", 3) )
        {
          v24 = atoi(v5 + 3) - 1;
          v23 = jhl_vpnget(&unk_645880, v24);
LABEL_34:
          v5 = (char *)nvram_get(v23);
          if ( v5 )
            goto LABEL_15;
          goto LABEL_35;
        }
        if ( !strcmp(v5, "3G") || !strcmp(v5, "4G") || !strcmp(v5, "5G") )
        {
          v22 = jhl_get_3g_iface();
          if ( v22 >= 0 )
          {
LABEL_33:
            v23 = jhl_nvget("wan_name", v22);
            goto LABEL_34;
          }
        }
      }
LABEL_15:
      v18 = v26;
      do
        *v18++ = 0;
      while ( v18 != &v26[12] );
      v26[0] = (int)"ping";
      if ( v17 && !strcmp(v17, "6") )
        v26[1] = (int)&unk_64CCF0;
      else
        v26[1] = (int)&unk_64CCF4;
      v26[3] = (int)v3;
      v26[2] = (int)"-c";
      v26[5] = (int)v4;
      v26[4] = (int)"-s";
      if ( v5 )
      {
        v26[7] = (int)v5;
        v26[6] = (int)&unk_64CCF8;
        v19 = 8;
      }
      else
      {
        v19 = 6;
      }
      *(_DWORD *)&v25[4 * v19 + 256] = v2;
      eval_nowait_file(v26, &unk_64CCFC, 0, v27);
      strcpy(v25, "{\"code\":0,\"error\":\"\",\"data\":{");
      v20 = sprintf(&v25[29], "\"msg\":\"ping...\",\"pid\":\"%d\"", v27[0]) + 29;
      v21 = snprintf(&v25[v20], 256 - v20, "}}");
      if ( v21 >= 256 - v20 )
        v21 = 255 - v20;
      httpd_cgi_ret(a1, v25, v21 + v20, 4);
      return 0;
    }
    v22 = atoi(v5 + 3) - 1;
    goto LABEL_33;
  }
  v8 = httpd_get_parm(a1, (char *)&off_64CC40);
  memset(v26, 0, sizeof(v26));
  if ( v8 )
  {
    v9 = J_atoi(v8);
    if ( !strcmp(v7, "stop") )
    {
      if ( v9 >= 2 )
      {
        kill_by_pid_name(v9, "ping", 15, 9, 0);
        return ping_data(a1);
      }
    }
    else if ( !strcmp(v7, "back") && v9 >= 2 )
    {
      kill_by_pid_name(v9, "ping", 15, 9, 0);
      sprintf((char *)v26, "/tmp/ping/ping_%d", v9);
      unlink((const char *)v26);
    }
  }
  v11 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v12 = v25;
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
  return httpd_cgi_ret(a1, v25, 33, 4);
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

