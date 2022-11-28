int __fastcall sub_477F98(int a1)
{
  char *v2; // $s3
  char *v3; // $v0
  int v4; // $a0
  const char **v5; // $v1
  const char *v6; // $v0
  const char *v7; // $t0
  const char *v8; // $a3
  const char *v9; // $a2
  const char *v10; // $a1
  int v12; // $a0
  const char *v13; // $v0
  int v14; // $s2
  const char *v15; // $v0
  const char *v16; // $v0
  const char *v17; // $v0
  const char *v18; // $v0
  const char *v19; // $v0
  const char *v20; // $v0
  const char *v21; // $v0
  const char *v22; // $v0
  const char *v23; // $v0
  const char *v24; // $v0
  const char *v25; // $v0
  const char *v26; // $v0
  const char *v27; // $v0
  const char *v28; // $v0
  const char *v29; // $v0
  const char *v30; // $v0
  const char *v31; // $v0
  const char *v32; // $v0
  const char *v33; // $v0
  const char *v34; // $v0
  const char *v35; // $v0
  const char *v36; // $v0
  const char *v37; // $v0
  const char *v38; // $s6
  const char *v39; // $s5
  const char *v40; // $s7
  const char *v41; // $s4
  const char *v42; // $v0
  const char *v43; // $v0
  const char *v44; // $v0
  const char *v45; // $v0
  int v46; // $a2
  const char *v47; // $v0
  unsigned int v48; // $v0
  const char *v49; // [sp+20h] [-480h] BYREF
  const char *v50; // [sp+24h] [-47Ch]
  const char *v51; // [sp+28h] [-478h]
  char *v52; // [sp+2Ch] [-474h]
  char *v53; // [sp+30h] [-470h]
  int v54; // [sp+34h] [-46Ch]
  int v55; // [sp+38h] [-468h]
  char *v56; // [sp+420h] [-80h]
  char *v57; // [sp+424h] [-7Ch]
  char *v58; // [sp+428h] [-78h]
  char *v59; // [sp+42Ch] [-74h]
  char *v60; // [sp+430h] [-70h]
  char *v61; // [sp+434h] [-6Ch]
  char *v62; // [sp+438h] [-68h]
  char *v63; // [sp+43Ch] [-64h]
  char *v64; // [sp+440h] [-60h]
  char *v65; // [sp+444h] [-5Ch]
  char *v66; // [sp+448h] [-58h]
  char *v67; // [sp+44Ch] [-54h]
  char *v68; // [sp+450h] [-50h]
  char *v69; // [sp+454h] [-4Ch]
  char *v70; // [sp+458h] [-48h]
  char *v71; // [sp+45Ch] [-44h]
  char *v72; // [sp+460h] [-40h]
  char *v73; // [sp+464h] [-3Ch]
  char *v74; // [sp+468h] [-38h]
  char *v75; // [sp+46Ch] [-34h]
  char *v76; // [sp+470h] [-30h]
  char *v77; // [sp+474h] [-2Ch]
  char *v78; // [sp+478h] [-28h]
  char *v79; // [sp+47Ch] [-24h]
  char *v80; // [sp+480h] [-20h]
  char *v81; // [sp+484h] [-1Ch]
  char *v82; // [sp+488h] [-18h]
  char *v83; // [sp+48Ch] [-14h]
  char *v84; // [sp+490h] [-10h]
  char *v85; // [sp+494h] [-Ch]
  char *v86; // [sp+498h] [-8h]

  v66 = httpd_get_parm(a1, "server_mode");
  v67 = httpd_get_parm(a1, "ac_mng_srv_host_custom");
  v68 = httpd_get_parm(a1, "ac_mng_srv_port_custom");
  v69 = httpd_get_parm(a1, "wt_base_addr_custom");
  v70 = httpd_get_parm(a1, "wt_base_port_custom");
  v61 = httpd_get_parm(a1, "hide");
  v59 = httpd_get_parm(a1, "en");
  v62 = httpd_get_parm(a1, "fbs_en");
  v65 = httpd_get_parm(a1, "addr");
  v71 = httpd_get_parm(a1, "port");
  v63 = httpd_get_parm(a1, "router_addr");
  v72 = httpd_get_parm(a1, "router_cont");
  v73 = httpd_get_parm(a1, "router_tel");
  v74 = httpd_get_parm(a1, "router_name");
  v75 = httpd_get_parm(a1, "router_dinate");
  v76 = httpd_get_parm(a1, "router_agents");
  v77 = httpd_get_parm(a1, "router_pwd");
  v85 = "a";
  v78 = httpd_get_parm(a1, "route_type");
  v79 = httpd_get_parm(a1, "route_replace_id");
  v80 = httpd_get_parm(a1, "wt_dev_type");
  v86 = "a";
  v81 = httpd_get_parm(a1, "wt_dev_offlinenotauth");
  v82 = httpd_get_parm(a1, "new_router_agents");
  v83 = httpd_get_parm(a1, "wt_nofeel_auth_id");
  v60 = httpd_get_parm(a1, "rzgl_pc_no_auth");
  v84 = httpd_get_parm(a1, "wtqr_ServerEnable");
  v64 = httpd_get_parm(a1, "re_conn");
  v2 = httpd_get_parm(a1, "debug");
  v56 = httpd_get_parm(a1, "third_mode");
  v58 = httpd_get_parm(a1, "redirct_mode");
  v57 = httpd_get_parm(a1, "redirct_time");
  v3 = httpd_get_parm(a1, "timeout");
  if ( v2 )
  {
    nvram_set("wt_clt_debug", v2);
LABEL_3:
    nvram_set("wt_config_modify", "1");
    start_rzgl(0);
    wt_client_restart(0);
    mng_client_restart(0);
    jhl_parm_commit(v4);
    goto LABEL_4;
  }
  if ( v56 )
  {
    nvram_set("rzgl_third_mode", v56);
    v49 = "wys";
    v50 = "third";
    v51 = "mode";
    v52 = "set";
    v53 = v56;
    v54 = 0;
LABEL_9:
    eval(&v49, 0, 0, 0);
    jhl_parm_commit(v12);
    goto LABEL_4;
  }
  if ( v57 )
  {
    if ( !J_atoi(v57) )
      v57 = "1";
    nvram_set("rzgl_redirct_time", v57);
    if ( !v58 )
      goto LABEL_15;
    goto LABEL_14;
  }
  if ( v58 )
  {
LABEL_14:
    nvram_set("rzgl_redirct_mode", v58);
LABEL_15:
    v49 = "wys";
    v50 = "third";
    v51 = "redirct_mode";
    v52 = "set";
    v53 = (char *)jhl_nv_get_def("rzgl_redirct_mode");
    v54 = jhl_nv_get_def("rzgl_redirct_time");
    v55 = 0;
    goto LABEL_9;
  }
  if ( v3 )
  {
    nvram_set("wt_clt_timeout", v3);
    goto LABEL_3;
  }
  if ( !v60 || (v13 = (const char *)nvram_get("rzgl_pc_no_auth")) != 0 && !strcmp(v13, v60) )
  {
    v14 = 0;
  }
  else
  {
    nvram_set("rzgl_pc_no_auth", v60);
    v14 = 1;
  }
  if ( v64 && !strcmp(v64, "1") )
    goto LABEL_3;
  if ( !v59 )
  {
    if ( !v63 )
      goto LABEL_150;
    goto LABEL_30;
  }
  v15 = (const char *)jhl_nv_get_def("dual_lan_mode");
  if ( !strcmp(v15, "1") || !nvram_match_def("billing_en", "1") || !J_atoi(v59) )
  {
    if ( !v63 )
      goto LABEL_34;
LABEL_30:
    v16 = (const char *)nvram_get("wt_dev_addr");
    if ( !v16 || strcmp(v16, v63) )
    {
      nvram_set("wt_dev_addr", v63);
      v14 = 1;
      nvram_set(&unk_648DD0, "1");
    }
    if ( v59 )
    {
LABEL_34:
      v17 = (const char *)nvram_get("wt_base_enable");
      if ( !v17 || strcmp(v17, v59) )
      {
        nvram_set("wt_base_enable", v59);
        v14 = 1;
      }
      if ( !v62 )
        goto LABEL_42;
      goto LABEL_38;
    }
LABEL_150:
    if ( !v62 )
      goto LABEL_43;
LABEL_38:
    v18 = (const char *)nvram_get("wt_dev_server_fbs");
    if ( !v18 || strcmp(v18, v62) )
    {
      nvram_set("wt_dev_server_fbs", v62);
      v14 = 1;
    }
    if ( !v59 )
    {
LABEL_43:
      if ( v65 )
      {
        v19 = (const char *)nvram_get("wt_base_addr");
        if ( !v19 || strcmp(v19, v65) )
        {
          nvram_set("wt_base_addr", v65);
          if ( !strcmp("yd.wayos.com", v65) )
          {
            nvram_set("ac_mng_srv_host", "acad.wayos.com");
          }
          else if ( !strcmp("client.wamwifi.com", v65) )
          {
            nvram_set("ac_mng_srv_host", "client.wamwifi.com");
          }
          nvram_set("wt_base_srv_ip", "");
          nvram_set("wt_auth_srv_ip", "");
          nvram_set(&unk_648DBC, "");
          v14 = 1;
        }
      }
      if ( v71 )
      {
        v20 = (const char *)nvram_get("wt_base_port");
        if ( !v20 || strcmp(v20, v71) )
        {
          nvram_set("wt_base_port", v71);
          v14 = 1;
          nvram_set("wt_base_srv_ip", "");
          nvram_set("wt_auth_srv_ip", "");
          nvram_set(&unk_648DBC, "");
        }
      }
      if ( v72 )
      {
        v21 = (const char *)nvram_get("wt_dev_cont");
        if ( !v21 || strcmp(v21, v72) )
        {
          nvram_set("wt_dev_cont", v72);
          v14 = 1;
        }
      }
      if ( v73 )
      {
        v22 = (const char *)nvram_get("wt_dev_tel");
        if ( !v22 || strcmp(v22, v73) )
        {
          nvram_set("wt_dev_tel", v73);
          v14 = 1;
        }
      }
      if ( v74 )
      {
        v23 = (const char *)nvram_get("wt_dev_name");
        if ( !v23 || strcmp(v23, v74) )
        {
          nvram_set("wt_dev_name", v74);
          v14 = 1;
        }
      }
      if ( v75 )
      {
        v24 = (const char *)nvram_get("wt_dev_dinate");
        if ( !v24 || strcmp(v24, v75) )
        {
          nvram_set("wt_dev_dinate", v75);
          v14 = 1;
        }
      }
      if ( v76 )
      {
        v25 = (const char *)nvram_get("wt_agent_id");
        if ( !v25 || strcmp(v25, v76) )
        {
          nvram_set("wt_agent_id", v76);
          v14 = 1;
        }
      }
      if ( v77 )
      {
        v26 = (const char *)nvram_get("wt_dev_pwd");
        if ( !v26 || strcmp(v26, v77) )
        {
          nvram_set("wt_dev_pwd", v77);
          v14 = 1;
        }
      }
      if ( v78 )
      {
        v27 = (const char *)nvram_get("wt_route_type");
        if ( !v27 || strcmp(v27, v78) )
        {
          nvram_set("wt_route_type", v78);
          v14 = 1;
        }
      }
      if ( v79 )
      {
        v28 = (const char *)nvram_get("wt_dev_replace_id");
        if ( !v28 || strcmp(v28, v79) )
        {
          nvram_set("wt_dev_replace_id", v79);
          v14 = 1;
        }
      }
      if ( v80 )
      {
        v29 = (const char *)nvram_get(v85 + 30500);
        if ( !v29 || strcmp(v29, v80) )
        {
          nvram_set(v85 + 30500, v80);
          v14 = 1;
        }
      }
      if ( v81 )
      {
        v30 = (const char *)nvram_get("wt_dev_offlinenotauth");
        if ( !v30 || strcmp(v30, v81) )
        {
          nvram_set("wt_dev_offlinenotauth", v81);
          v14 = 1;
        }
      }
      if ( v82 )
      {
        v31 = (const char *)nvram_get("wt_third_agent_id");
        if ( !v31 || strcmp(v31, v82) )
        {
          nvram_set("wt_third_agent_id", v82);
          v14 = 1;
        }
      }
      if ( v83 )
      {
        v32 = (const char *)nvram_get(v86 + 30556);
        if ( !v32 || strcmp(v32, v83) )
        {
          nvram_set(v86 + 30556, v83);
          v14 = 1;
        }
      }
      if ( v84 && !nvram_match_def("wtQR_SrvEnable", v84) )
      {
        if ( J_atoi(v84) == 1 )
          nvram_set("wtQR_SrvEnable", "1");
        else
          nvram_set("wtQR_SrvEnable", "0");
        v14 = 1;
      }
      if ( v66 )
      {
        v33 = (const char *)nvram_get("wt_server_mode");
        if ( !v33 || strcmp(v33, v66) )
        {
          nvram_set("wt_server_mode", v66);
          v14 = 1;
        }
      }
      if ( v67 )
      {
        v34 = (const char *)nvram_get("ac_mng_srv_host_custom");
        if ( !v34 || strcmp(v34, v67) )
        {
          nvram_set("ac_mng_srv_host_custom", v67);
          v14 = 1;
        }
      }
      if ( v68 )
      {
        v35 = (const char *)nvram_get("ac_mng_srv_port_custom");
        if ( !v35 || strcmp(v35, v68) )
        {
          nvram_set("ac_mng_srv_port_custom", v68);
          v14 = 1;
        }
      }
      if ( v69 )
      {
        v36 = (const char *)nvram_get("wt_base_addr_custom");
        if ( !v36 || strcmp(v36, v69) )
        {
          nvram_set("wt_base_addr_custom", v69);
          v14 = 1;
        }
      }
      if ( v70 )
      {
        v37 = (const char *)nvram_get("wt_base_port_custom");
        if ( !v37 || strcmp(v37, v70) )
        {
          nvram_set("wt_base_port_custom", v70);
          v14 = 1;
        }
      }
      if ( v61 && J_atoi(v61) == 1 )
        goto LABEL_145;
      if ( nvram_match_def("wt_server_mode", "1") )
      {
        v38 = (const char *)jhl_nv_get_def("wt_base_addr_custom");
        v39 = (const char *)jhl_nv_get_def("wt_base_port_custom");
        v40 = (const char *)jhl_nv_get_def("ac_mng_srv_host_custom");
        v41 = (const char *)jhl_nv_get_def("ac_mng_srv_port_custom");
        if ( !v38 )
        {
LABEL_131:
          if ( v39 )
          {
            v43 = (const char *)nvram_get("wt_base_port");
            if ( !v43 || strcmp(v43, v39) )
            {
              nvram_set("wt_base_port", v39);
              v14 = 1;
            }
          }
          if ( v40 )
          {
            v44 = (const char *)nvram_get("ac_mng_srv_host");
            if ( !v44 || strcmp(v44, v40) )
            {
              nvram_set("ac_mng_srv_host", v40);
              if ( !v41 )
                goto LABEL_3;
              v14 = 1;
              goto LABEL_140;
            }
          }
          if ( v41 )
          {
LABEL_140:
            v45 = (const char *)nvram_get("ac_mng_srv_port");
            if ( !v45 || strcmp(v45, v41) )
            {
              nvram_set("ac_mng_srv_port", v41);
              goto LABEL_3;
            }
          }
LABEL_145:
          if ( v14 )
            goto LABEL_3;
LABEL_4:
          v5 = &v49;
          v6 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          do
          {
            v7 = *(const char **)v6;
            v8 = (const char *)*((_DWORD *)v6 + 1);
            v9 = (const char *)*((_DWORD *)v6 + 2);
            v10 = (const char *)*((_DWORD *)v6 + 3);
            v6 += 16;
            *v5 = v7;
            v5[1] = v8;
            v5[2] = v9;
            v5[3] = v10;
            v5 += 4;
          }
          while ( v6 != "}" );
          *(_WORD *)v5 = *(_WORD *)v6;
          return httpd_cgi_ret(a1, (char *)&v49, 33, 4);
        }
      }
      else if ( nvram_match_def("wt_server_mode", "2") )
      {
        v38 = "r.wamwifi.com";
        v41 = "28862";
        v39 = "3800";
        v40 = "r.wamwifi.com";
      }
      else
      {
        v38 = "client.wamwifi.com";
        v41 = "58862";
        v39 = "5500";
        v40 = "client.wamwifi.com";
      }
      v42 = (const char *)nvram_get("wt_base_addr");
      if ( !v42 || strcmp(v42, v38) )
      {
        nvram_set("wt_base_addr", v38);
        v14 = 1;
      }
      goto LABEL_131;
    }
LABEL_42:
    reset_wtclient_rzgl_parm(v59);
    nvram_get("wt_base_enable");
    goto LABEL_43;
  }
  v47 = (const char *)_GET_LANG_TEXT(52, *(unsigned __int8 *)(a1 + 210102), v46);
  v48 = snprintf((char *)&v49, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v47);
  if ( v48 >= 0x400 )
    v48 = 1023;
  return httpd_cgi_ret(a1, (char *)&v49, v48, 4);
}
// 4783D8: variable 'v4' is possibly undefined
// 478504: variable 'v12' is possibly undefined
// 479498: variable 'v46' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8354: using guessed type int __fastcall wt_client_restart(_DWORD);
// 6A83A0: using guessed type int __fastcall mng_client_restart(_DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85F0: using guessed type int __fastcall reset_wtclient_rzgl_parm(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

