int __fastcall sub_4BD3A8(int a1)
{
  char *v2; // $s7
  char *v3; // $s6
  char *v4; // $s5
  char *v5; // $fp
  char *v6; // $s1
  char *v7; // $v0
  char *v8; // $v1
  const char *v9; // $v0
  int v10; // $t0
  int v11; // $a3
  int v12; // $a2
  int v13; // $a1
  char *v15; // $a1
  const char *v16; // $v0
  int v17; // $s4
  const char *v18; // $a1
  const char *v19; // $v0
  const char *v20; // $v0
  const char *v21; // $v0
  int v22; // $fp
  const char *v23; // $v0
  const char *v24; // $v0
  int v25; // $fp
  const char *v26; // $a1
  int v27; // $s7
  const char *v28; // $v0
  const char *v29; // $v0
  const char *v30; // $v0
  const char *v31; // $s4
  const char *v32; // $v0
  const char *v33; // $v0
  const char *v34; // $v0
  int v35; // $a0
  const char *v36; // $v0
  int v37; // $s6
  const char *v38; // $v0
  const char *v39; // $v0
  const char *v40; // $v0
  int v41; // $v0
  char v42[1024]; // [sp+18h] [-550h] BYREF
  char v43[256]; // [sp+418h] [-150h] BYREF
  const char *v44; // [sp+518h] [-50h] BYREF
  const char *v45; // [sp+51Ch] [-4Ch]
  char *v46; // [sp+520h] [-48h]
  int v47; // [sp+524h] [-44h]
  int v48; // [sp+528h] [-40h]
  const char *v49; // [sp+52Ch] [-3Ch]
  const char *v50; // [sp+530h] [-38h]
  const char *v51; // [sp+534h] [-34h]
  int v52; // [sp+538h] [-30h]
  char *v53; // [sp+540h] [-28h]
  char *v54; // [sp+544h] [-24h]
  int v55; // [sp+548h] [-20h]
  char *v56; // [sp+54Ch] [-1Ch]
  char *v57; // [sp+550h] [-18h]
  char *v58; // [sp+554h] [-14h]
  char *v59; // [sp+558h] [-10h]
  char *v60; // [sp+55Ch] [-Ch]
  const char *v61; // [sp+560h] [-8h]
  const char *v62; // [sp+564h] [-4h]

  memset(v43, 0, sizeof(v43));
  v2 = httpd_get_parm(a1, "enable");
  v3 = httpd_get_parm(a1, "mode");
  v4 = httpd_get_parm(a1, "lan_gateway");
  v54 = httpd_get_parm(a1, "lan_dns");
  v5 = httpd_get_parm(a1, "debug");
  v6 = httpd_get_parm(a1, "action");
  v53 = httpd_get_parm(a1, "server_type");
  v7 = httpd_get_parm(a1, "opt");
  if ( !v7 || strcmp(v7, "proxy") )
  {
    if ( v6 )
    {
      if ( !strcmp(v6, "restart") )
      {
        exec_service("ac_server-restart");
      }
      else if ( !strcmp(v6, "stop") )
      {
        exec_service("ac_server-stop");
      }
      else if ( !strcmp(v6, "start") )
      {
        exec_service("ac_server-start");
      }
      goto LABEL_8;
    }
    if ( !v5 || (v21 = (const char *)nvram_get("ac_server_debug")) != 0 && !strcmp(v21, v5) )
    {
      v22 = 0;
    }
    else
    {
      nvram_set("ac_server_debug", v5);
      v22 = 1;
    }
    if ( v2 )
    {
      v23 = (const char *)nvram_get("ac_server_enable");
      if ( !v23 || strcmp(v23, v2) )
      {
        nvram_set("ac_server_enable", v2);
        memset(v42, 0, sizeof(v42));
        nvram_set("proxy_ac_status", "0");
        v24 = (const char *)nvram_get("proxy_ac_pid");
        if ( !v24 )
          v24 = "-1";
        v25 = J_atoi(v24);
        if ( v25 > 0 )
        {
          memset(v42, 0, sizeof(v42));
          snprintf(v42, 1024, "kill -9 %d &", v25);
          jhl_system(v42);
          if ( get_web_language_type(a1) )
            v26 = "This function is not enabled";
          else
            v26 = (const char *)&unk_645EF8;
          nvram_set("proxy_ac_msg", v26);
          nvram_set("proxy_ac_pid", "-1");
          nvram_set("proxy_ac_port", "");
        }
        v22 = 1;
      }
    }
    v27 = 0;
    if ( v3 )
    {
      v28 = (const char *)nvram_get("ac_server_mode");
      if ( !v28 || (v27 = 0, strcmp(v28, v3)) )
      {
        nvram_set("ac_server_mode", v3);
        v27 = 1;
        v22 = 1;
      }
      v29 = (const char *)nvram_get("ac_server_enable");
      if ( v29 )
      {
        if ( !strcmp(v29, "1") )
        {
          v36 = (const char *)nvram_get("ac_server_mode");
          if ( v36 )
          {
            if ( !strcmp(v36, "1") )
            {
              nvram_set("rzglType", "0");
              start_rzgl(0);
              v55 = sq_file_get_max_wan();
              if ( v55 > 0 )
              {
                v56 = "a";
                v37 = 0;
                v57 = "1\"";
                v58 = "a";
                v59 = "disable";
                v61 = "wan_conn";
                v62 = "restart";
                do
                {
                  v39 = (const char *)jhl_nvget("wan_proto", v37);
                  if ( strcmp(v56 + 12644, v39) || (v38 = (const char *)nvram_get(v57 - 20284)) == 0 || strcmp(v59, v38) )
                  {
                    v40 = (const char *)jhl_nvget("wan_proto", v37);
                    if ( strcmp(v58 + 12448, v40) )
                    {
                      v41 = jhl_nvget("wan_new_proto", v37);
                      nvram_set(v41, v58 + 12448);
                      v60 = v42;
                      sprintf(v42, "%d", v37);
                      v44 = v61;
                      v45 = v62;
                      v46 = v60;
                      v47 = 0;
                      eval_nowait(&v44, 0, 0, 0);
                    }
                  }
                  ++v37;
                }
                while ( v55 != v37 );
              }
              nvram_set("dhcp_type", &off_63F984);
              v22 = 1;
              start_dhcp_server();
            }
          }
        }
      }
    }
    if ( v4 )
    {
      v30 = (const char *)nvram_get("lan_gateway");
      if ( !v30 || strcmp(v30, v4) )
      {
        nvram_set("lan_gateway", v4);
        v27 = 1;
      }
    }
    v31 = v54;
    if ( v54 )
    {
      v32 = (const char *)nvram_get("lan_get_dns");
      if ( !v32 || strcmp(v32, v31) )
      {
        nvram_set("lan_get_dns", v54);
        v27 = 1;
      }
    }
    v33 = (const char *)nvram_get("ac_server_mode");
    if ( v33 && !strcmp(v33, "1") )
    {
      wan_webset(a1);
      lan_webset(a1);
    }
    if ( !v53 || (v34 = (const char *)nvram_get("server_type")) != 0 && !strcmp(v34, v53) )
    {
      if ( !v22 )
      {
        if ( !v27 )
          goto LABEL_8;
        goto LABEL_62;
      }
    }
    else
    {
      nvram_set("ac_server_type", v53);
    }
    exec_service("ac_server-restart");
    jhl_start_firewall();
LABEL_62:
    lanip_change();
    jhl_parm_commit(v35);
    goto LABEL_8;
  }
  memset(v42, 0, sizeof(v42));
  v15 = httpd_get_parm(a1, "status");
  if ( v15 )
    nvram_set("proxy_ac_status", v15);
  v16 = (const char *)nvram_get("proxy_ac_pid");
  if ( !v16 )
    v16 = "-1";
  v17 = J_atoi(v16);
  if ( v17 > 0 )
  {
    memset(v42, 0, sizeof(v42));
    snprintf(v42, 1024, "kill -9 %d", v17);
    system(v42);
    if ( get_web_language_type(a1) )
      v18 = "This function is not enabled";
    else
      v18 = (const char *)&unk_645EF8;
    nvram_set("proxy_ac_msg", v18);
    nvram_set("proxy_ac_pid", "-1");
    nvram_set("proxy_ac_port", "");
  }
  v19 = (const char *)nvram_get("proxy_ac_status");
  if ( v19 )
  {
    if ( !strcmp(v19, "1") )
    {
      v20 = (const char *)nvram_get("ac_server_enable");
      if ( v20 )
      {
        if ( !strcmp(v20, "1") )
        {
          v44 = "proxy_client";
          v45 = (const char *)jhl_nv_get_only_def("proxy_http_srv");
          v46 = (char *)jhl_nv_get_only_def("proxy_http_srvport");
          v47 = jhl_nv_get_def("lan_ipaddr");
          v48 = jhl_nv_get_def("acserver_http_port");
          v49 = "proxy_ac_port";
          v50 = "proxy_ac_msg";
          v51 = "proxy_ac_pid";
          v52 = 0;
          eval_nowait(&v44, 0, 0, 0);
        }
      }
    }
  }
LABEL_8:
  v8 = v43;
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
  return httpd_cgi_ret(a1, v43, 33, 4);
}
// 4BDD84: variable 'v35' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A84B8: using guessed type int start_dhcp_server(void);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A8594: using guessed type int __fastcall jhl_system(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A86D0: using guessed type int lanip_change(void);
// 6A86F4: using guessed type int __fastcall jhl_nv_get_only_def(_DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

