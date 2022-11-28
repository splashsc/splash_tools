int __fastcall sub_44CCC4(int a1)
{
  char *v1; // $v0
  const char *v3; // $s0
  int v4; // $s2
  char *v5; // $v0
  char *v6; // $s0
  char *v8; // $s3
  char *v9; // $v0
  int v10; // $a2
  char *v11; // $v1
  int v12; // $v0
  _WORD *v13; // $s3
  char *v14; // $s2
  _WORD *v15; // $v0
  int v16; // $a2
  int v17; // $a1
  int v18; // $s2
  _WORD *v19; // $v0
  int v20; // $a2
  int v21; // $a1
  int v22; // $s2
  int v23; // $s2
  int v24; // $v0
  int v25; // $v0
  char v26[104]; // [sp+18h] [-68h] BYREF

  v1 = httpd_get_parm(a1, "type");
  if ( !v1 )
  {
    strcpy(v26, "{\"err\":\"type err\"}");
    return httpd_cgi_ret(a1, v26, 18, 4);
  }
  v3 = v1;
  v4 = 1;
  if ( strcmp(v1, "arp") )
  {
    v4 = 3;
    if ( strcmp(v3, "wan") )
    {
      v4 = 4;
      if ( strcmp(v3, "prog") )
      {
        v4 = 5;
        if ( strcmp(v3, "ddos") )
        {
          v4 = 6;
          if ( strcmp(v3, "pppoe") )
          {
            v4 = 7;
            if ( strcmp(v3, "web") )
            {
              v4 = 8;
              if ( strcmp(v3, "dhcp") )
              {
                v4 = 9;
                if ( strcmp(v3, (const char *)&off_644A94) )
                {
                  v4 = 10;
                  if ( strcmp(v3, "tg") )
                  {
                    v4 = 11;
                    if ( strcmp(v3, "mrzc") )
                    {
                      v4 = 12;
                      if ( strcmp(v3, "url") )
                      {
                        v4 = 14;
                        if ( strcmp(v3, "urlrd") )
                        {
                          v4 = 15;
                          if ( strcmp(v3, "pg2") )
                          {
                            v4 = 18;
                            if ( strcmp(v3, "homepage") )
                            {
                              if ( !strcmp(v3, "vpn") )
                              {
                                _mem_malloc(0x200000, "ai_device_log", 1236);
                                v6 = (char *)v12;
                                if ( !v12 )
                                  goto LABEL_4;
                                v13 = (_WORD *)(v12 + 1);
                                *(_WORD *)v12 = 91;
                                v14 = read_vpnmessage_file((char *)(v12 + 1), 0x1FFFFF);
                                v9 = &read_ipsec_file(&v14[(_DWORD)v13], 0x1FFFFF)[(_DWORD)v14];
                                v4 = 2;
                              }
                              else
                              {
                                v4 = 19;
                                if ( !strcmp(v3, "dns") )
                                  goto LABEL_3;
                                v4 = 20;
                                if ( !strcmp(v3, "wifidog") )
                                  goto LABEL_3;
                                v4 = 21;
                                if ( !strcmp(v3, "ac_server") )
                                  goto LABEL_3;
                                v4 = 23;
                                if ( !strcmp(v3, "wan_err") )
                                  goto LABEL_3;
                                v4 = 24;
                                if ( !strcmp(v3, "lan_pppoe_err") )
                                  goto LABEL_3;
                                if ( !strcmp(v3, "vpn_error") )
                                {
                                  _mem_malloc(0x200000, "ai_device_log", 1236);
                                  v6 = (char *)v25;
                                  if ( !v25 )
                                    goto LABEL_4;
                                  v13 = (_WORD *)(v25 + 1);
                                  *(_WORD *)v25 = 91;
                                  v9 = read_error_by_ipsec_file((char *)(v25 + 1), 0x1FFFFF);
                                  v4 = 26;
                                }
                                else if ( !strcmp(v3, "ipsec_debug") )
                                {
                                  _mem_malloc(0x200000, "ai_device_log", 1236);
                                  v6 = (char *)v24;
                                  if ( !v24 )
                                    goto LABEL_4;
                                  v13 = (_WORD *)(v24 + 1);
                                  *(_WORD *)v24 = 91;
                                  v9 = read_ipsec_file((char *)(v24 + 1), 0x1FFFFF);
                                  v4 = 28;
                                }
                                else if ( !strcmp(v3, "sys") )
                                {
                                  _mem_malloc(0x200000, "ai_device_log", 1236);
                                  v6 = (char *)v19;
                                  if ( !v19 )
                                    goto LABEL_4;
                                  *v19 = 91;
                                  v13 = (_WORD *)((char *)v19 + 1);
                                  if ( nvram_match_def("usblogd_en", "1") )
                                  {
                                    v22 = read_sysmessage_file("/var/log/messages2", v6 + 1, 0x1FFFFF);
                                    v21 = v22;
                                    v20 = 0x1FFFFF - v22;
                                  }
                                  else
                                  {
                                    v20 = 0x1FFFFF;
                                    v21 = 0;
                                    v22 = 0;
                                  }
                                  v23 = v22 + read_sysmessage_file("/var/log/messages.0", (char *)v13 + v21, v20);
                                  v9 = (char *)(v23
                                              + read_sysmessage_file(
                                                  "/var/log/messages",
                                                  (char *)v13 + v23,
                                                  0x1FFFFF - v23));
                                  v4 = -1;
                                }
                                else
                                {
                                  if ( strcmp(v3, "ovpn") )
                                  {
                                    v4 = 25;
                                    if ( strcmp(v3, "offline") )
                                    {
                                      v4 = 33;
                                      if ( strcmp(v3, "gongx") )
                                      {
                                        v4 = 34;
                                        if ( strcmp(v3, "voip") )
                                        {
                                          v4 = 35;
                                          if ( strcmp(v3, "av") )
                                          {
                                            if ( strcmp(v3, "ips") )
                                            {
                                              strcpy(v26, "{\"err\":\"id err\"}");
                                              return httpd_cgi_ret(a1, v26, 16, 4);
                                            }
                                            v4 = 36;
                                          }
                                        }
                                      }
                                    }
                                    goto LABEL_3;
                                  }
                                  _mem_malloc(0x200000, "ai_device_log", 1236);
                                  v6 = (char *)v15;
                                  if ( !v15 )
                                    goto LABEL_4;
                                  *v15 = 91;
                                  v13 = (_WORD *)((char *)v15 + 1);
                                  if ( nvram_match_def("usblogd_en", "1") )
                                  {
                                    v18 = read_ovpn_file("/var/log/openvpn2.log", v6 + 1, 0x1FFFFF);
                                    v17 = v18;
                                    v16 = 0x1FFFFF - v18;
                                  }
                                  else
                                  {
                                    v16 = 0x1FFFFF;
                                    v17 = 0;
                                    v18 = 0;
                                  }
                                  v9 = (char *)(v18 + read_ovpn_file("/var/log/openvpn.log", (char *)v13 + v17, v16));
                                  v4 = -2;
                                }
                              }
                              v11 = &v9[(_DWORD)v13];
                              if ( !v9 )
                              {
                                *v13 = 93;
                                v10 = 2;
                                return httpd_cgi_ret(a1, v6, v10, 8);
                              }
                              goto LABEL_37;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LABEL_3:
  _mem_malloc(0x200000, "ai_device_log", 1236);
  v6 = v5;
  if ( v5 )
  {
    v8 = v5 + 1;
    *(_WORD *)v5 = 91;
    v9 = (char *)read_log_data(v4, v5 + 1, 0x1FFFFF, 0);
    v10 = 2;
    if ( !v9 )
      goto LABEL_38;
    v11 = &v9[(_DWORD)v8];
LABEL_37:
    v8 = v11 - 1;
    *(v11 - 1) = 0;
    v10 = (int)(v9 + 1);
LABEL_38:
    *v8 = 93;
    v8[1] = 0;
    if ( v4 == 34 )
      *(_DWORD *)(a1 + 36) |= 0x8000u;
    return httpd_cgi_ret(a1, v6, v10, 8);
  }
LABEL_4:
  strcpy(v26, "{\"err\":\"mem_malloc err\"}");
  return httpd_cgi_ret(a1, v26, 24, 4);
}
// 44CD54: variable 'v5' is possibly undefined
// 44D300: variable 'v12' is possibly undefined
// 44D38C: variable 'v15' is possibly undefined
// 44D444: variable 'v19' is possibly undefined
// 44D524: variable 'v24' is possibly undefined
// 44D574: variable 'v25' is possibly undefined
// 644A94: using guessed type void *off_644A94;
// 6A8294: using guessed type int __fastcall read_ovpn_file(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A868C: using guessed type int __fastcall read_sysmessage_file(_DWORD, _DWORD, _DWORD);
// 6A88BC: using guessed type int __fastcall read_log_data(_DWORD, _DWORD, _DWORD, _DWORD);

