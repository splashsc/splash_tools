int __fastcall sub_44E0C4(int a1)
{
  char *v2; // $v0
  char *v3; // $v0
  char *v4; // $s6
  char *v5; // $v0
  const char *v6; // $s4
  char *v7; // $v0
  char *v8; // $v0
  char *v9; // $v0
  const char *v10; // $s5
  int v11; // $v0
  unsigned int v12; // $s3
  unsigned int v13; // $s1
  unsigned int v14; // $v0
  int v15; // $s3
  unsigned int v16; // $v0
  int v18; // $s6
  int v19; // $v0
  int v20; // $v0
  const char *v21; // $v0
  int v22; // $v0
  const char *v23; // $v0
  int v24; // $v0
  int v25; // $a0
  int v26; // $v0
  int v27; // $v0
  const char *v28; // $v0
  int v29; // $v0
  int v30; // $v0
  int v31; // $v0
  int v32; // $v0
  int v33; // $v0
  int v34; // $v0
  char v35[1024]; // [sp+18h] [-470h] BYREF
  int v36[8]; // [sp+418h] [-70h] BYREF
  int v37[6]; // [sp+438h] [-50h] BYREF
  char *s; // [sp+450h] [-38h]
  char *v39; // [sp+454h] [-34h]
  char *v40; // [sp+458h] [-30h]
  char *v41; // [sp+45Ch] [-2Ch]
  int *v42; // [sp+460h] [-28h]
  char *v43; // [sp+464h] [-24h]
  char *v44; // [sp+468h] [-20h]
  char *v45; // [sp+46Ch] [-1Ch]
  char *v46; // [sp+470h] [-18h]
  char *v47; // [sp+474h] [-14h]
  char *v48; // [sp+478h] [-10h]
  char *v49; // [sp+47Ch] [-Ch]
  char *v50; // [sp+480h] [-8h]
  char *v51; // [sp+484h] [-4h]

  memset(v35, 0, sizeof(v35));
  v2 = httpd_get_parm(a1, "iface");
  v49 = "a";
  v4 = v2;
  v3 = httpd_get_parm(a1, "wan_proto");
  v50 = "a";
  v6 = v3;
  v5 = httpd_get_parm(a1, "wan_dns");
  v51 = "a";
  v48 = v5;
  v40 = httpd_get_parm(a1, "wan_ipaddr");
  v7 = httpd_get_parm(a1, "wan_netmask");
  v44 = "a";
  v43 = v7;
  v8 = httpd_get_parm(a1, "wan_getway");
  v45 = "a";
  v47 = v8;
  v39 = httpd_get_parm(a1, "ppp_username");
  v41 = httpd_get_parm(a1, "ppp_passwd");
  v9 = httpd_get_parm(a1, "callback");
  v42 = v36;
  v36[0] = 0;
  v36[1] = 0;
  v36[2] = 0;
  v36[3] = 0;
  v36[4] = 0;
  v36[5] = 0;
  v36[6] = 0;
  v36[7] = 0;
  v10 = v9;
  sprintf((char *)v36, "%d", 0);
  v11 = jhl_nvget("wan_new_proto", 0);
  nvram_unset(v11);
  if ( v10 )
  {
    v12 = snprintf(v35, 1024, "%s(", v10);
    if ( v12 >= 0x400 )
    {
      v12 = 1023;
      s = &v35[1023];
      v13 = 1;
    }
    else
    {
      s = &v35[v12];
      v13 = 1024 - v12;
    }
  }
  else
  {
    v13 = 1024;
    s = v35;
    v12 = 0;
  }
  if ( !v6 || (v46 = "a", strcmp(v6, "static")) && strcmp(v6, "dhcp") && strcmp(v6, "pppoe") )
  {
    v14 = snprintf(s, v13, "{\"ret\":\"0\",\"msg\":\"wan_proto error!\"}");
    goto LABEL_9;
  }
  if ( !v4 || !*v4 )
  {
    v14 = snprintf(s, v13, "{\"ret\":\"0\",\"msg\":\"iface error!\"}");
    goto LABEL_9;
  }
  v18 = J_atoi(v4);
  if ( !strcmp(v6, v46 + 17216) )
  {
    if ( !v40 && !v43 && !v47 && !v48 )
    {
      v14 = snprintf(s, v13, "{\"ret\":\"0\",\"msg\":\"static param error!\"}");
      goto LABEL_9;
    }
    if ( !strcmp(v50 + 6780, v40) )
    {
      v40 = 0;
    }
    else
    {
      v33 = jhl_nvget("wan_ipaddr", v18);
      nvram_set(v33, v40);
      v40 = (char *)1;
    }
    if ( strcmp(v51 + 6792, v43) )
    {
      v32 = jhl_nvget("wan_netmask", v18);
      nvram_set(v32, v43);
      v40 = (char *)1;
    }
    v43 = "a";
    if ( strcmp("wan_gateway", v47) )
    {
      v34 = jhl_nvget(v43 + 6804, v18);
      nvram_set(v34, v47);
      v40 = (char *)1;
    }
    if ( strcmp(v49 + 7028, v48) )
    {
      v26 = jhl_nvget("wan_dns", v18);
      nvram_set(v26, v48);
      v40 = (char *)1;
    }
  }
  else
  {
    v40 = 0;
  }
  v43 = "a";
  if ( !strcmp(v6, "pppoe") )
  {
    if ( !v39 && !v41 )
    {
      v14 = snprintf(s, v13, "{\"ret\":\"0\",\"msg\":\"pppoe param error!\"}");
      goto LABEL_9;
    }
    if ( strcmp(v44 + 6864, v39) )
    {
      v31 = jhl_nvget("ppp_username", v18);
      nvram_set(v31, v39);
      v40 = (char *)1;
    }
    if ( strcmp(v45 + 6880, v41) )
    {
      v30 = jhl_nvget("ppp_passwd", v18);
      nvram_set(v30, v41);
      v40 = (char *)1;
    }
  }
  v19 = jhl_nvget("wan_new_proto", v18);
  nvram_unset(v19);
  if ( (!strcmp(v6, v43 + 13636)
     || (v20 = jhl_nvget("wan_proto", v18), (v21 = (const char *)nvram_get(v20)) != 0) && !strcmp(v21, "pppoe"))
    && (v27 = jhl_nvget("ppp_demand", v18), (v28 = (const char *)nvram_get(v27)) != 0)
    && !strcmp(v28, "2") )
  {
    jhl_stop_wan(0);
    v29 = jhl_nvget("wan_proto", v18);
    nvram_set(v29, v6);
  }
  else
  {
    v22 = jhl_nvget("wan_proto", v18);
    v23 = (const char *)nvram_get(v22);
    if ( !v23 || strcmp(v23, v6) )
    {
      v24 = jhl_nvget("wan_new_proto", v18);
      nvram_set(v24, v6);
    }
    v37[0] = (int)"wan_conn";
    v37[1] = (int)"restart";
    v37[2] = (int)v42;
    v37[3] = (int)"wys_ai_wx_network_set_asp";
    v37[4] = 0;
    eval_nowait(v37, 0, 0, 0);
  }
  if ( v40 )
    jhl_parm_commit(v25);
  v14 = snprintf(s, v13, "{\"ret\":\"1\",\"msg\":\"ok!\"}");
LABEL_9:
  if ( v14 >= v13 )
    v14 = 1023 - v12;
  v15 = v14 + v12;
  if ( v10 )
  {
    v16 = snprintf(&v35[v15], 1024 - v15, ")");
    if ( v16 >= 1024 - v15 )
      v16 = 1023 - v15;
    v15 += v16;
  }
  return httpd_cgi_ret(a1, v35, v15, 4);
}
// 44E834: variable 'v25' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A87E8: using guessed type int __fastcall jhl_stop_wan(_DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

