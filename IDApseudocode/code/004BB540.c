int __fastcall sub_4BB540(int a1)
{
  int v2; // $v0
  char *v3; // $a0
  int v4; // $v0
  char *v5; // $a0
  int v6; // $v0
  int v7; // $s6
  const char *v8; // $s1
  _BYTE *v9; // $v0
  const char *v10; // $s0
  const char *v11; // $s2
  const char *v12; // $s3
  const char *v13; // $s4
  const char *v14; // $a1
  const char *v15; // $v0
  int v16; // $v0
  int v17; // $s0
  int v18; // $s1
  int v19; // $v0
  int v20; // $a2
  const char *v22; // $v0
  unsigned int v23; // $v0
  char v24[256]; // [sp+90h] [-198h] BYREF
  char v25[32]; // [sp+190h] [-98h] BYREF
  char v26[32]; // [sp+1B0h] [-78h] BYREF
  const char *v27; // [sp+1D0h] [-58h]
  const char *v28; // [sp+1D4h] [-54h]
  const char *v29; // [sp+1D8h] [-50h]
  const char *v30; // [sp+1DCh] [-4Ch]
  const char *v31; // [sp+1E0h] [-48h]
  const char *v32; // [sp+1E4h] [-44h]
  const char *v33; // [sp+1E8h] [-40h]
  const char *v34; // [sp+1ECh] [-3Ch]
  const char *v35; // [sp+1F0h] [-38h]
  const char *v36; // [sp+1F4h] [-34h]
  const char *v37; // [sp+1F8h] [-30h]
  const char *v38; // [sp+1FCh] [-2Ch]
  const char *v39; // [sp+200h] [-28h]
  const char *v40; // [sp+204h] [-24h]
  const char *v41; // [sp+208h] [-20h]
  const char *v42; // [sp+20Ch] [-1Ch]
  const char *v43; // [sp+210h] [-18h]
  const char *v44; // [sp+214h] [-14h]
  const char *v45; // [sp+218h] [-10h]
  const char *v46; // [sp+21Ch] [-Ch]
  const char *v47; // [sp+220h] [-8h]
  const char *v48; // [sp+224h] [-4h]

  v2 = jhl_nv_get_def("sj_des_key");
  if ( v2 )
    v3 = (char *)v2;
  else
    v3 = "";
  jhl_string_encoding_json(v3, v26, 32);
  v4 = jhl_nv_get_def("sj_des_iv");
  if ( v4 )
    v5 = (char *)v4;
  else
    v5 = "";
  jhl_string_encoding_json(v5, v25, 32);
  _mem_malloc(10240, "sj_state_data", 1135);
  v7 = v6;
  if ( v6 )
  {
    strcpy((char *)v6, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v6, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v6 + 24) = 975331700;
    v27 = (const char *)jhl_nv_get_def("sj_en");
    v28 = (const char *)jhl_nv_get_def("sj_ftp_srvaddr");
    v29 = (const char *)jhl_nv_get_def("sj_ftp_user");
    v30 = (const char *)jhl_nv_get_def("sj_ftp_pass");
    v31 = (const char *)jhl_nv_get_def("sj_ftp_port");
    v32 = (const char *)jhl_nv_get_def("sj_state");
    v33 = (const char *)jhl_nv_get_def("sj_other_srvaddr");
    v34 = (const char *)jhl_nv_get_def("sj_other_port");
    v35 = (const char *)jhl_nv_get_def("sj_other_udpport");
    v36 = (const char *)jhl_nv_get_def("sj_other_tcpport");
    v37 = (const char *)jhl_nv_get_def("sj_heart_udpport");
    v8 = (const char *)nvram_get("sj_srv_type");
    v38 = (const char *)(v7 + 29);
    if ( !v8 )
      v8 = "";
    v38 = (const char *)jhl_nv_get_def("sj_ftp_srvaddr2");
    v39 = (const char *)jhl_nv_get_def("sj_ftp_user2");
    v40 = (const char *)jhl_nv_get_def("sj_ftp_pass2");
    v41 = (const char *)jhl_nv_get_def("sj_ftp_port2");
    v42 = (const char *)jhl_nv_get_def("sj_send_data_info");
    v43 = (const char *)jhl_nv_get_def("sj_send_data_tim");
    v9 = (_BYTE *)nvram_get("sj_real_dev_sn");
    if ( v9 && !*v9 )
    {
      v10 = (const char *)nvram_get("sj_palce_code");
      if ( v10 )
        goto LABEL_11;
    }
    else
    {
      v10 = (const char *)nvram_get("sj_real_dev_sn");
      if ( v10 )
      {
LABEL_11:
        v11 = (const char *)nvram_get("sj_real_tz_sn");
        if ( !v11 )
          v11 = "";
        v44 = (const char *)jhl_nv_get_def("sj_ftp_en2");
        v45 = (const char *)jhl_nv_get_def("sj_create_time");
        v46 = (const char *)jhl_nv_get_def("sj_ztcp_srvaddr");
        v47 = (const char *)jhl_nv_get_def("sj_ztcp_srvport");
        v12 = (const char *)nvram_get("sj_title");
        if ( !v12 )
          v12 = "";
        v13 = (const char *)nvram_get("sj_subtype");
        if ( !v13 )
          v13 = "";
        v14 = (const char *)nvram_get("yh_platform_addr");
        if ( !v14 )
          v14 = "";
        v48 = v14;
        v15 = (const char *)nvram_get("yh_platform_port");
        if ( !v15 )
          v15 = "";
        v16 = snprintf(
                (char *)(v7 + 29),
                10211,
                "\"enable\":\"%s\",\"srv_addr\":\"%s\",\"srv_user\":\"%s\",\"srv_pwd\":\"%s\",\"srv_port\":\"%s\",\"statu"
                "s\":\"%s\",\"other_srv_addr\":\"%s\",\"other_srv_port\":\"%s\",\"udp_srv_port\":\"%s\",\"tcp_srv_port\":"
                "\"%s\",\"heart_udp_port\":\"%s\",\"srv_type\":\"%s\",\"srv_addr2\":\"%s\",\"srv_user2\":\"%s\",\"srv_pwd"
                "2\":\"%s\",\"srv_port2\":\"%s\",\"senddata_info\":\"%s\",\"senddata_tim\":\"%s\",\"dev_sn\":\"%s\",\"tz_"
                "sn\":\"%s\",\"enable2\":\"%s\",\"create_time\":\"%s\",\"ztcp_srv_addr\":\"%s\",\"ztcp_srv_port\":\"%s\","
                "\"des_key\":\"%s\",\"des_iv\":\"%s\",\"sj_title\":\"%s\",\"sj_subtype\":\"%s\",\"yh_platform_addr\":\"%s"
                "\",\"yh_platform_port\":\"%s\"",
                v27,
                v28,
                v29,
                v30,
                v31,
                v32,
                v33,
                v34,
                v35,
                v36,
                v37,
                v8,
                v38,
                v39,
                v40,
                v41,
                v42,
                v43,
                v10,
                v11,
                v44,
                v45,
                v46,
                v47,
                v26,
                v25,
                v12,
                v13,
                v48,
                v15);
        if ( v16 >= 10211 )
          v16 = 10210;
        v17 = v16 + 29;
        v18 = 10240 - (v16 + 29);
        v19 = snprintf((char *)(v7 + v16 + 29), v18, "}}");
        if ( v19 >= v18 )
          v20 = 10239 - v17;
        else
          v20 = v19;
        return httpd_cgi_ret(a1, (char *)v7, v20 + v17, 8);
      }
    }
    v10 = "";
    goto LABEL_11;
  }
  v22 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 10240);
  v23 = snprintf(v24, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v22);
  if ( v23 >= 0x100 )
    v23 = 255;
  return httpd_cgi_ret(a1, v24, v23, 4);
}
// 4BB618: variable 'v6' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A87FC: using guessed type int __fastcall jhl_string_encoding_json(_DWORD, _DWORD, _DWORD);

