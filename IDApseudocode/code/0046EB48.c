int __fastcall sub_46EB48(int a1)
{
  int v2; // $v0
  char *v3; // $s3
  const char *v4; // $fp
  const char *v5; // $s0
  const char *v6; // $s4
  const char *v7; // $s5
  const char *v8; // $s6
  const char *v9; // $s1
  const char *v10; // $a1
  const char *v11; // $v0
  int v12; // $s1
  int v13; // $v0
  int v14; // $a2
  int result; // $v0
  const char *v16; // $v0
  unsigned int v17; // $v0
  char v18[256]; // [sp+60h] [-138h] BYREF
  const char *v19; // [sp+160h] [-38h]
  const char *v20; // [sp+164h] [-34h]
  const char *v21; // [sp+168h] [-30h]
  const char *v22; // [sp+16Ch] [-2Ch]
  const char *v23; // [sp+170h] [-28h]
  const char *v24; // [sp+174h] [-24h]
  const char *v25; // [sp+178h] [-20h]
  const char *v26; // [sp+17Ch] [-1Ch]
  const char *v27; // [sp+180h] [-18h]
  const char *v28; // [sp+184h] [-14h]
  const char *v29; // [sp+188h] [-10h]
  const char *v30; // [sp+18Ch] [-Ch]
  const char *v31; // [sp+190h] [-8h]

  _mem_malloc(10240, "mng_platform_data", 3882);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v4 = (const char *)jhl_nv_get_def("wt_base_enable");
    v19 = (const char *)jhl_nv_get_def("ac_mng_srv_host");
    v20 = (const char *)jhl_nv_get_def("ac_mng_srv_port");
    v5 = (const char *)nvram_get("ac_mng_state");
    if ( !v5 )
      v5 = "";
    v21 = (const char *)jhl_nv_get_def("wt_dev_routerid");
    v22 = (const char *)jhl_nv_get_def("wt_dev_addr");
    v23 = (const char *)jhl_nv_get_def("wt_dev_cont");
    v24 = (const char *)jhl_nv_get_def("wt_dev_tel");
    v25 = (const char *)jhl_nv_get_def("wt_dev_name");
    v26 = (const char *)jhl_nv_get_def("wt_dev_dinate");
    v27 = (const char *)jhl_nv_get_def("wt_agent_id");
    v6 = (const char *)jhl_nv_get_def("wt_dev_pwd");
    v7 = (const char *)jhl_nv_get_def("wt_route_type");
    v8 = (const char *)jhl_nv_get_def("wt_dev_replace_id");
    v9 = (const char *)jhl_nv_get_def("wt_dev_randid");
    v10 = (const char *)nvram_get("ac_mng_state");
    if ( !v10 )
      v10 = "";
    v31 = v10;
    v30 = (const char *)jhl_nv_get_def("wt_dev_type");
    v29 = (const char *)jhl_nv_get_def("wt_dev_offlinenotauth");
    v28 = (const char *)jhl_nv_get_def("wt_third_agent_id");
    v11 = (const char *)jhl_nv_get_def("wt_nofeel_auth_id");
    v12 = sprintf(
            v3 + 29,
            "\"en\":\"%s\",\"addr\":\"%s\",\"port\":\"%s\",\"state\":\"%s\",\"route_id\":\"%s\",\"router_addr\":\"%s\",\""
            "router_cont\":\"%s\",\"router_tel\":\"%s\",\"router_name\":\"%s\",\"router_dinate\":\"%s\",\"router_agents\""
            ":\"%s\",\"router_pwd\":\"%s\", \"route_type\":\"%s\",\"route_replace_id\":\"%s\", \"wt_dev_randid\":\"%s\",\""
            "ac_mng_state\":\"%s\",\"wt_dev_type\":\"%s\", \"wt_dev_offlinenotauth\":\"%s\",\"new_router_agents\":\"%s\","
            "\"wt_nofeel_auth_id\":\"%s\"",
            v4,
            v19,
            v20,
            v5,
            v21,
            v22,
            v23,
            v24,
            v25,
            v26,
            v27,
            v6,
            v7,
            v8,
            v9,
            v31,
            v30,
            v29,
            v28,
            v11)
        + 29;
    v13 = snprintf(&v3[v12], 10240 - v12, "}}");
    if ( v13 >= 10240 - v12 )
      v14 = 10239 - v12;
    else
      v14 = v13;
    result = httpd_cgi_ret(a1, v3, v14 + v12, 8);
  }
  else
  {
    v16 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
    v17 = snprintf(v18, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
    if ( v17 >= 0x100 )
      v17 = 255;
    result = httpd_cgi_ret(a1, v18, v17, 4);
  }
  return result;
}
// 46EBA8: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

