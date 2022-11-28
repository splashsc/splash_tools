int __fastcall sub_4C1360(int a1)
{
  int v1; // $v0
  int v2; // $s4
  char *v3; // $s1
  int v4; // $s3
  int v5; // $s0
  int v6; // $v0
  char *v7; // $s2
  int v8; // $v0
  const char *v9; // $v0
  int v10; // $v0
  const char *v11; // $v0
  const char *v12; // $s7
  int v13; // $s3
  int v14; // $v0
  int v15; // $s3
  char *v16; // $v0
  int v17; // $s7
  int v18; // $v0
  const char *v19; // $s2
  const char *v20; // $s7
  const char *v21; // $fp
  int v22; // $v0
  const char *v23; // $v0
  int v24; // $s0
  int v25; // $v0
  const char *v26; // $v0
  int v27; // $v0
  int v28; // $s2
  char *v29; // $v0
  int v30; // $v0
  int v31; // $s6
  int v32; // $s7
  int v33; // $v0
  int v34; // $v0
  int v35; // $s3
  char *v36; // $v0
  const char *v37; // $v0
  int v38; // $s0
  const char *v39; // $v0
  int v40; // $s0
  const char *v41; // $s3
  const char *v42; // $s2
  const char *v43; // $v0
  int v44; // $s0
  int v45; // $v0
  int v46; // $a2
  const char *v48; // $a1
  const char *v49; // $v0
  unsigned int v50; // $a2
  char v51[512]; // [sp+50h] [-288h] BYREF
  int v52[16]; // [sp+250h] [-88h] BYREF
  int *v53; // [sp+290h] [-48h]
  char *v54; // [sp+294h] [-44h]
  const char *v55; // [sp+298h] [-40h]
  char *format; // [sp+29Ch] [-3Ch]
  char *v57; // [sp+2A0h] [-38h]
  const char *v58; // [sp+2A4h] [-34h]
  const char *v59; // [sp+2A8h] [-30h]
  const char *v60; // [sp+2ACh] [-2Ch]
  const char *v61; // [sp+2B0h] [-28h]
  const char *v62; // [sp+2B4h] [-24h]
  const char *v63; // [sp+2B8h] [-20h]
  const char *v64; // [sp+2BCh] [-1Ch]
  const char *v65; // [sp+2C0h] [-18h]
  const char *v66; // [sp+2C4h] [-14h]
  char *v67; // [sp+2C8h] [-10h]
  char *v68; // [sp+2CCh] [-Ch]
  char *v69; // [sp+2D0h] [-8h]

  v53 = v52;
  memset(v52, 0, sizeof(v52));
  v2 = sq_file_get_max_wan();
  _mem_malloc(0x200000, "mr_data", 75);
  v3 = (char *)v1;
  if ( !v1 )
  {
    v49 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v50 = snprintf(v51, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v49);
    if ( v50 >= 0x100 )
      v50 = 255;
    return httpd_cgi_ret(a1, v51, v50, 4);
  }
  strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
  qmemcpy((void *)v1, "{\"code\":0,\"error", 16);
  *(_DWORD *)(v1 + 20) = 1633952300;
  v4 = sprintf((char *)(v1 + 29), "\"pppoe_br\":\"%d\",\"igmp\":\"%d\",\"mr_qos\":%d,\"wans\":[", 1, 1, 0) + 29;
  if ( v2 <= 0 )
    goto LABEL_30;
  v54 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
  v57 = "1\"";
  v5 = 0;
  v55 = "wan_proto";
  format = "{\"iface\":%d,\"wan_ifname\":\"%s\",";
  while ( 1 )
  {
    v6 = jhl_nvget("wan_ifname", v5);
    v7 = (char *)nvram_get(v6);
    if ( !v7 )
      v7 = v54 - 1556;
    if ( !*v7 )
      break;
    v8 = jhl_nvget("wan_down", v5);
    v9 = (const char *)nvram_get(v8);
    if ( v9 && !strcmp(v9, "1") || jhl_iface_link_up_check(v7, v5) )
      goto LABEL_4;
    v10 = jhl_nvget(v55, v5);
    v11 = (const char *)nvram_get(v10);
    v12 = v11;
    if ( v11 )
    {
      if ( strcmp("3G", v11) || (v48 = (const char *)nvram_get("wan_3g_enable")) == 0 || strcmp("disable", v48) )
      {
        if ( !strncmp(v12, "3G", 2u) )
          v12 = "4G";
        goto LABEL_15;
      }
LABEL_4:
      if ( v2 == ++v5 )
        break;
    }
    else
    {
      v12 = v54 - 1556;
LABEL_15:
      v13 = sprintf(&v3[v4], format, v5, v7) + v4;
      v15 = v13 + sprintf(&v3[v13], v57 + 824, v12);
      v14 = jhl_nvget("mr_parm", v5);
      v16 = (char *)nvram_get(v14);
      if ( !v16 || !*v16 )
        v16 = " ";
      strlcpy(v51, v16, 512);
      v17 = (int)v53;
      v18 = split_string(v51, 60, v53, 14);
      mr_parm_default(v18, v17, v5);
      v68 = (char *)v52[3];
      v67 = (char *)v52[4];
      v66 = (const char *)v52[5];
      v65 = (const char *)v52[6];
      v64 = (const char *)v52[7];
      v63 = (const char *)v52[8];
      v62 = (const char *)v52[9];
      v61 = (const char *)v52[10];
      v60 = (const char *)v52[11];
      v59 = (const char *)v52[12];
      v58 = (const char *)v52[13];
      v19 = (const char *)v52[0];
      v20 = (const char *)v52[1];
      v21 = (const char *)v52[2];
      v22 = jhl_nvget("wan_flow_all", v5);
      v23 = (const char *)nvram_get(v22);
      if ( !v23 )
        v23 = "0";
      ++v5;
      v4 = v15
         + sprintf(
             &v3[v15],
             "\"jh_en\":\"%s\",\"qz\":\"%s\",\"zc_en\":\"%s\",\"tm\":\"%s\",\"times\":\"%s\",\"act\":\"%s\",\"su\":\"%s\""
             ",\"gw_en\":\"%s\",\"srv_en\":\"%s\",\"srv_ip\":\"%s\",\"gw_ip\":\"%s\",\"qz_t\":\"%s\",\"host\":\"%s\",\"ct"
             "\":\"%s\",\"flow\":\"%s\"},",
             v19,
             v20,
             v21,
             v68,
             v67,
             v66,
             v65,
             v64,
             v63,
             v62,
             v61,
             v60,
             v59,
             v58,
             v23);
      if ( v2 == v5 )
        break;
    }
  }
  v54 = "{\"iface\":%d,";
  v24 = 0;
  v67 = "1\"";
  v68 = "\"jh_en\":\"%s\",\"qz\":\"%s\",\"zc_en\":\"%s\",\"tm\":\"%s\",\"times\":\"%s\",\"act\":\"%s\",\"su\":\"%s\",\"gw"
        "_en\":\"%s\",\"srv_en\":\"%s\",\"srv_ip\":\"%s\",\"gw_ip\":\"%s\",\"qz_t\":\"%s\",\"host\":\"%s\",\"ct\":\"%s\","
        "\"flow\":\"%s\",\"vpn_port\":\"%d\"},";
  v69 = "a";
  do
  {
    v25 = jhl_vpnget("vpn_proto", v24);
    v26 = (const char *)nvram_get(v25);
    if ( !v26 || strcmp(v26, (const char *)&off_63F984) )
    {
      v28 = sprintf(&v3[v4], v54, v24 + 101);
      v27 = jhl_vpnget("vpnmr_parm", v24);
      v29 = (char *)nvram_get(v27);
      if ( !v29 || !*v29 )
        v29 = " ";
      strlcpy(v51, v29, 512);
      v30 = split_string(v51, 60, v53, 14);
      mr_parm_default(v30, v53, v24 + 101);
      v66 = (const char *)v52[0];
      v65 = (const char *)v52[3];
      v64 = (const char *)v52[4];
      v63 = (const char *)v52[5];
      v62 = (const char *)v52[6];
      v61 = (const char *)v52[7];
      v60 = (const char *)v52[8];
      v59 = (const char *)v52[9];
      v58 = (const char *)v52[10];
      v57 = (char *)v52[11];
      format = (char *)v52[12];
      v55 = (const char *)v52[13];
      v31 = v52[1];
      v32 = v52[2];
      v33 = jhl_vpnget(v67 - 308, v24);
      v35 = v28 + v4;
      v34 = nvram_get(v33);
      if ( !v34 )
        v34 = (int)(v69 + 14076);
      v4 = v35
         + sprintf(&v3[v35], v68, v66, v31, v32, v65, v64, v63, v62, v61, v60, v59, v58, v57, format, v55, v34, 101);
    }
    ++v24;
  }
  while ( v24 != 5 && v2 != v24 );
LABEL_30:
  v36 = &v3[v4];
  if ( v4 > 0 && *(v36 - 1) == 44 )
    v36 = &v3[--v4];
  *v36 = 93;
  v36[1] = 44;
  v36[2] = 0;
  v37 = (const char *)jhl_nv_get_def("mr_mode");
  v38 = v4 + 2 + sprintf(&v3[v4 + 2], "\"mode\":\"%s\",", v37);
  v39 = (const char *)jhl_nv_get_def("mr_onlywan_tcp");
  v40 = v38 + sprintf(&v3[v38], "\"onlywan_tcp\":\"%s\",", v39);
  v41 = (const char *)jhl_nv_get_def("mr_onlywan");
  v42 = (const char *)jhl_nv_get_def("mr_zn_val");
  v43 = (const char *)jhl_nv_get_def("mr_ct_rule_name");
  v44 = v40
      + sprintf(
          &v3[v40],
          "\"onlywan\":\"%s\",\"zn_val\":\"%s\",\"ct_rule_name\":\"%s\",\"flag\":\"%d\"",
          v41,
          v42,
          v43,
          1);
  v45 = snprintf(&v3[v44], 0x200000 - v44, "}}");
  if ( v45 >= 0x200000 - v44 )
    v46 = 0x1FFFFF - v44;
  else
    v46 = v45;
  return httpd_cgi_ret(a1, v3, v46 + v44, 8);
}
// 4C13FC: variable 'v1' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8270: using guessed type int __fastcall mr_parm_default(_DWORD, _DWORD, _DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

