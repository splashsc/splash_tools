int __fastcall sub_46E500(int a1)
{
  int v1; // $v0
  char *v2; // $s2
  const char *v3; // $s0
  const char *v4; // $s1
  const char *v5; // $s3
  const char *v6; // $s4
  const char *v7; // $s5
  const char *v8; // $s6
  const char *v9; // $s7
  const char *v10; // $a1
  const char *v11; // $v0
  int v12; // $s0
  const char *v13; // $s1
  const char *v14; // $s3
  const char *v15; // $s4
  const char *v16; // $s5
  const char *v17; // $s6
  const char *v18; // $s7
  const char *v19; // $v0
  int v20; // $s0
  int v21; // $v0
  int v22; // $a2
  int result; // $v0
  const char *v24; // $v0
  unsigned int v25; // $v0
  char v26[256]; // [sp+78h] [-140h] BYREF
  const char *v27; // [sp+178h] [-40h]
  const char *v28; // [sp+17Ch] [-3Ch]
  const char *v29; // [sp+180h] [-38h]
  const char *v30; // [sp+184h] [-34h]
  const char *v31; // [sp+188h] [-30h]
  const char *v32; // [sp+18Ch] [-2Ch]
  const char *v33; // [sp+190h] [-28h]
  const char *v34; // [sp+194h] [-24h]
  const char *v35; // [sp+198h] [-20h]
  const char *v36; // [sp+19Ch] [-1Ch]
  const char *v37; // [sp+1A0h] [-18h]
  const char *v38; // [sp+1A4h] [-14h]
  const char *v39; // [sp+1A8h] [-10h]
  const char *v40; // [sp+1ACh] [-Ch]
  const char *v41; // [sp+1B0h] [-8h]

  _mem_malloc(10240, "wtclient_data", 3236);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    v27 = (const char *)jhl_nv_get_def("wt_base_enable");
    v28 = (const char *)jhl_nv_get_def("wt_base_addr");
    v29 = (const char *)jhl_nv_get_def("wt_base_port");
    v3 = (const char *)nvram_get("wt_state");
    if ( !v3 )
      v3 = "";
    v30 = (const char *)jhl_nv_get_def("wt_dev_routerid");
    v31 = (const char *)jhl_nv_get_def("wt_dev_addr");
    v32 = (const char *)jhl_nv_get_def("wt_dev_cont");
    v33 = (const char *)jhl_nv_get_def("wt_dev_tel");
    v34 = (const char *)jhl_nv_get_def("wt_dev_name");
    v35 = (const char *)jhl_nv_get_def("wt_dev_dinate");
    v36 = (const char *)jhl_nv_get_def("wt_agent_id");
    v37 = (const char *)jhl_nv_get_def("wt_dev_pwd");
    v38 = (const char *)jhl_nv_get_def("wt_route_type");
    v39 = (const char *)jhl_nv_get_def("wt_dev_replace_id");
    v40 = (const char *)jhl_nv_get_def("wt_dev_randid");
    v4 = (const char *)nvram_get("ac_mng_state");
    if ( !v4 )
      v4 = "";
    v5 = (const char *)jhl_nv_get_def("wt_dev_type");
    v6 = (const char *)jhl_nv_get_def("wt_dev_offlinenotauth");
    v7 = (const char *)jhl_nv_get_def("wt_third_agent_id");
    v8 = (const char *)jhl_nv_get_def("wt_nofeel_auth_id");
    v9 = (const char *)jhl_nv_get_def("rzgl_pc_no_auth");
    v10 = (const char *)nvram_get("wt_dev_server_fbs");
    if ( !v10 )
      v10 = "0";
    v41 = v10;
    v11 = (const char *)jhl_nv_get_def("wtQR_SrvEnable");
    v12 = sprintf(
            v2 + 29,
            "\"en\":\"%s\",\"addr\":\"%s\",\"port\":\"%s\",\"state\":\"%s\",\"route_id\":\"%s\",\"router_addr\":\"%s\",\""
            "router_cont\":\"%s\",\"router_tel\":\"%s\",\"router_name\":\"%s\",\"router_dinate\":\"%s\",\"router_agents\""
            ":\"%s\",\"router_pwd\":\"%s\", \"route_type\":\"%s\",\"route_replace_id\":\"%s\", \"wt_dev_randid\":\"%s\",\""
            "ac_mng_state\":\"%s\",\"wt_dev_type\":\"%s\", \"wt_dev_offlinenotauth\":\"%s\",\"new_router_agents\":\"%s\","
            "\"wt_nofeel_auth_id\":\"%s\",\"rzgl_pc_no_auth\":\"%s\", \"fbs_en\":\"%s\",\"lan_state\":\"%d\",\"wtqr_Serve"
            "rEnable\":\"%s\",\"bridge\":\"%d\"",
            v27,
            v28,
            v29,
            v3,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v36,
            v37,
            v38,
            v39,
            v40,
            v4,
            v5,
            v6,
            v7,
            v8,
            v9,
            v41,
            1,
            v11,
            0)
        + 29;
    v13 = (const char *)nvram_get("wt_server_mode");
    if ( !v13 )
      v13 = "2";
    v14 = (const char *)jhl_nv_get_def("ac_mng_srv_host");
    v15 = (const char *)jhl_nv_get_def("ac_mng_srv_port");
    v16 = (const char *)jhl_nv_get_def("wt_base_addr_custom");
    v17 = (const char *)jhl_nv_get_def("wt_base_port_custom");
    v18 = (const char *)jhl_nv_get_def("ac_mng_srv_host_custom");
    v19 = (const char *)jhl_nv_get_def("ac_mng_srv_port_custom");
    v20 = v12
        + sprintf(
            &v2[v12],
            ",\"mode_show\":\"012\",\"server_mode\":\"%s\",\"ac_mng_srv_host\":\"%s\",\"ac_mng_srv_port\":\"%s\",\"wt_bas"
            "e_addr_custom\":\"%s\",\"wt_base_port_custom\":\"%s\",\"ac_mng_srv_host_custom\":\"%s\",\"ac_mng_srv_port_custom\":\"%s\"",
            v13,
            v14,
            v15,
            v16,
            v17,
            v18,
            v19);
    v21 = snprintf(&v2[v20], 10240 - v20, "}}");
    if ( v21 >= 10240 - v20 )
      v22 = 10239 - v20;
    else
      v22 = v21;
    result = httpd_cgi_ret(a1, v2, v22 + v20, 8);
  }
  else
  {
    v24 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v25 = snprintf(v26, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
    if ( v25 >= 0x100 )
      v25 = 255;
    result = httpd_cgi_ret(a1, v26, v25, 4);
  }
  return result;
}
// 46E560: variable 'v1' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

