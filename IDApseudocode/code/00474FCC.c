int __fastcall sub_474FCC(int a1)
{
  char *v2; // $s2
  char *v3; // $fp
  char *v4; // $s7
  char *v5; // $s3
  const char *v6; // $v0
  const char *v7; // $v0
  int v8; // $s1
  const char *v9; // $v0
  const char *v10; // $v0
  const char *v11; // $v0
  const char *v12; // $v0
  const char *v13; // $v0
  const char *v14; // $v0
  const char *v15; // $v0
  const char *v16; // $v0
  const char *v17; // $v0
  const char *v18; // $v0
  const char *v19; // $v0
  const char *v20; // $v0
  const char *v21; // $v0
  const char *v22; // $v0
  const char *v23; // $v0
  int v24; // $a0
  const char *v25; // $v0
  char *v26; // $v1
  int v27; // $t0
  int v28; // $a3
  int v29; // $a2
  int v30; // $a1
  int v32; // $a2
  const char *v33; // $v0
  unsigned int v34; // $v0
  char v35[1024]; // [sp+20h] [-438h] BYREF
  char *v36; // [sp+420h] [-38h]
  char *v37; // [sp+424h] [-34h]
  char *v38; // [sp+428h] [-30h]
  char *v39; // [sp+42Ch] [-2Ch]
  char *v40; // [sp+430h] [-28h]
  char *v41; // [sp+434h] [-24h]
  char *v42; // [sp+438h] [-20h]
  char *v43; // [sp+43Ch] [-1Ch]
  char *v44; // [sp+440h] [-18h]
  char *v45; // [sp+444h] [-14h]
  char *v46; // [sp+448h] [-10h]
  char *v47; // [sp+44Ch] [-Ch]
  char *v48; // [sp+450h] [-8h]

  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "addr");
  v4 = httpd_get_parm(a1, "port");
  v37 = httpd_get_parm(a1, "router_addr");
  v38 = httpd_get_parm(a1, "router_cont");
  v39 = httpd_get_parm(a1, "router_tel");
  v40 = httpd_get_parm(a1, "router_name");
  v41 = httpd_get_parm(a1, "router_dinate");
  v42 = httpd_get_parm(a1, "router_agents");
  v43 = httpd_get_parm(a1, "router_pwd");
  v44 = httpd_get_parm(a1, "route_type");
  v45 = httpd_get_parm(a1, "route_replace_id");
  v46 = httpd_get_parm(a1, "wt_dev_type");
  v47 = httpd_get_parm(a1, "wt_dev_offlinenotauth");
  v36 = httpd_get_parm(a1, "new_router_agents");
  v5 = httpd_get_parm(a1, "wt_nofeel_auth_id");
  if ( !v2 )
  {
    v8 = 0;
    goto LABEL_7;
  }
  v6 = (const char *)jhl_nv_get_def("dual_lan_mode");
  if ( !strcmp(v6, "1") || !nvram_match_def("billing_en", "1") || !J_atoi(v2) )
  {
    v48 = "a";
    v7 = (const char *)nvram_get("wt_base_enable");
    if ( !v7 || (v8 = 0, strcmp(v7, v2)) )
    {
      nvram_set(v48 + 30268, v2);
      v8 = 1;
    }
    reset_wtclient_rzgl_parm(v2);
    nvram_get(v48 + 30268);
LABEL_7:
    if ( v3 )
    {
      v9 = (const char *)nvram_get("ac_mng_srv_host");
      if ( !v9 || strcmp(v9, v3) )
      {
        nvram_set("ac_mng_srv_host", v3);
        v8 = 1;
      }
    }
    if ( v4 )
    {
      v10 = (const char *)nvram_get("ac_mng_srv_port");
      if ( !v10 || strcmp(v10, v4) )
      {
        nvram_set("ac_mng_srv_port", v4);
        v8 = 1;
      }
    }
    if ( v37 )
    {
      v11 = (const char *)nvram_get("wt_dev_addr");
      if ( !v11 || strcmp(v11, v37) )
      {
        nvram_set("wt_dev_addr", v37);
        v8 = 1;
      }
    }
    if ( v38 )
    {
      v12 = (const char *)nvram_get("wt_dev_cont");
      if ( !v12 || strcmp(v12, v38) )
      {
        nvram_set("wt_dev_cont", v38);
        v8 = 1;
      }
    }
    if ( v39 )
    {
      v13 = (const char *)nvram_get("wt_dev_tel");
      if ( !v13 || strcmp(v13, v39) )
      {
        nvram_set("wt_dev_tel", v39);
        v8 = 1;
      }
    }
    if ( v40 )
    {
      v14 = (const char *)nvram_get("wt_dev_name");
      if ( !v14 || strcmp(v14, v40) )
      {
        nvram_set("wt_dev_name", v40);
        v8 = 1;
      }
    }
    if ( v41 )
    {
      v15 = (const char *)nvram_get("wt_dev_dinate");
      if ( !v15 || strcmp(v15, v41) )
      {
        nvram_set("wt_dev_dinate", v41);
        v8 = 1;
      }
    }
    if ( v42 )
    {
      v16 = (const char *)nvram_get("wt_agent_id");
      if ( !v16 || strcmp(v16, v42) )
      {
        nvram_set("wt_agent_id", v42);
        v8 = 1;
      }
    }
    if ( v43 )
    {
      v17 = (const char *)nvram_get("wt_dev_pwd");
      if ( !v17 || strcmp(v17, v43) )
      {
        nvram_set("wt_dev_pwd", v43);
        v8 = 1;
      }
    }
    if ( v44 )
    {
      v18 = (const char *)nvram_get("wt_route_type");
      if ( !v18 || strcmp(v18, v44) )
      {
        nvram_set("wt_route_type", v44);
        v8 = 1;
      }
    }
    if ( v45 )
    {
      v19 = (const char *)nvram_get("wt_dev_replace_id");
      if ( !v19 || strcmp(v19, v45) )
      {
        nvram_set("wt_dev_replace_id", v45);
        v8 = 1;
      }
    }
    if ( v46 )
    {
      v20 = (const char *)nvram_get("wt_dev_type");
      if ( !v20 || strcmp(v20, v46) )
      {
        nvram_set("wt_dev_type", v46);
        v8 = 1;
      }
    }
    if ( v47 )
    {
      v21 = (const char *)nvram_get("wt_dev_offlinenotauth");
      if ( !v21 || strcmp(v21, v47) )
      {
        nvram_set("wt_dev_offlinenotauth", v47);
        v8 = 1;
      }
    }
    if ( !v36 || (v22 = (const char *)nvram_get("wt_third_agent_id")) != 0 && !strcmp(v22, v36) )
    {
      if ( !v5 )
      {
LABEL_77:
        if ( !v8 )
        {
LABEL_67:
          v25 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          v26 = v35;
          do
          {
            v27 = *(_DWORD *)v25;
            v28 = *((_DWORD *)v25 + 1);
            v29 = *((_DWORD *)v25 + 2);
            v30 = *((_DWORD *)v25 + 3);
            v25 += 16;
            *(_DWORD *)v26 = v27;
            *((_DWORD *)v26 + 1) = v28;
            *((_DWORD *)v26 + 2) = v29;
            *((_DWORD *)v26 + 3) = v30;
            v26 += 16;
          }
          while ( v25 != "}" );
          *(_WORD *)v26 = *(_WORD *)v25;
          return httpd_cgi_ret(a1, v35, 33, 4);
        }
LABEL_66:
        nvram_set("wt_config_modify", "1");
        start_rzgl(0);
        wt_client_restart(0);
        mng_client_restart(0);
        jhl_parm_commit(v24);
        goto LABEL_67;
      }
    }
    else
    {
      nvram_set("wt_third_agent_id", v36);
      v8 = 1;
      if ( !v5 )
        goto LABEL_66;
    }
    v23 = (const char *)nvram_get("wt_nofeel_auth_id");
    if ( !v23 || strcmp(v23, v5) )
    {
      nvram_set("wt_nofeel_auth_id", v5);
      goto LABEL_66;
    }
    goto LABEL_77;
  }
  v33 = (const char *)_GET_LANG_TEXT(52, *(unsigned __int8 *)(a1 + 210102), v32);
  v34 = snprintf(v35, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v33);
  if ( v34 >= 0x400 )
    v34 = 1023;
  return httpd_cgi_ret(a1, v35, v34, 4);
}
// 4758AC: variable 'v24' is possibly undefined
// 475994: variable 'v32' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8354: using guessed type int __fastcall wt_client_restart(_DWORD);
// 6A83A0: using guessed type int __fastcall mng_client_restart(_DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85F0: using guessed type int __fastcall reset_wtclient_rzgl_parm(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

