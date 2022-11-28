int __fastcall sub_436E0C(int a1)
{
  char *v2; // $v0
  int v3; // $v0
  char *v4; // $s0
  const char *v5; // $v0
  int v6; // $v0
  bool v7; // dc
  char *v8; // $v0
  char *v9; // $v0
  uint32_t v10; // $v0
  uint32_t v11; // $v0
  int v12; // $s4
  const char *v13; // $v0
  const char *v14; // $s4
  const char *v15; // $s5
  const char *v16; // $s7
  const char *v17; // $fp
  const char *v18; // $a2
  int v19; // $v0
  int v20; // $v0
  int v21; // $v0
  int v22; // $s2
  int v23; // $s1
  int v24; // $v0
  int v25; // $s2
  int v26; // $v0
  int v27; // $s2
  int v28; // $v0
  int v29; // $s2
  int v30; // $v0
  int v31; // $s1
  int v32; // $v0
  int v33; // $s1
  int v34; // $v0
  int v35; // $s1
  char *v36; // $a0
  int v37; // $v0
  int v38; // $s1
  int v39; // $v0
  int v40; // $a2
  int result; // $v0
  const char *v42; // $v0
  unsigned int v43; // $v0
  const char *v44; // [sp+68h] [-350h]
  char v45[256]; // [sp+C8h] [-2F0h] BYREF
  char v46[128]; // [sp+1C8h] [-1F0h] BYREF
  char v47[128]; // [sp+248h] [-170h] BYREF
  char v48[64]; // [sp+2C8h] [-F0h] BYREF
  int v49[10]; // [sp+308h] [-B0h] BYREF
  int v50[8]; // [sp+330h] [-88h] BYREF
  int v51[4]; // [sp+350h] [-68h] BYREF
  unsigned int v52; // [sp+360h] [-58h]
  char *v53; // [sp+364h] [-54h]
  char *v54; // [sp+368h] [-50h]
  const char *v55; // [sp+36Ch] [-4Ch]
  const char *v56; // [sp+370h] [-48h]
  const char *v57; // [sp+374h] [-44h]
  const char *v58; // [sp+378h] [-40h]
  time_t v59; // [sp+37Ch] [-3Ch]
  int v60; // [sp+380h] [-38h]
  int v61; // [sp+384h] [-34h]
  int v62; // [sp+388h] [-30h]
  const char *v63; // [sp+38Ch] [-2Ch]
  const char *v64; // [sp+390h] [-28h]
  int v65; // [sp+394h] [-24h]
  int v66; // [sp+398h] [-20h]
  int v67; // [sp+39Ch] [-1Ch]
  int v68; // [sp+3A0h] [-18h]
  int v69; // [sp+3A4h] [-14h]
  int v70; // [sp+3A8h] [-10h]
  int v71; // [sp+3ACh] [-Ch]
  int v72; // [sp+3B0h] [-8h]
  const char *v73; // [sp+3B4h] [-4h]

  memset(v46, 0, sizeof(v46));
  v50[0] = 0;
  v50[1] = 0;
  v50[2] = 0;
  v50[3] = 0;
  v50[4] = 0;
  v50[5] = 0;
  v50[6] = 0;
  v50[7] = 0;
  memset(v48, 0, sizeof(v48));
  memset(v45, 0, sizeof(v45));
  _mem_malloc(0x200000, "base_data", 460);
  if ( v2 )
  {
    v4 = v2;
    v3 = get_web_language_type(a1);
    if ( v3 == 1 || v3 == 99 )
      sq_file_get_ssid_en(v46, 128);
    else
      sq_file_get_id(v46, 128);
    v53 = v47;
    get_uptime_sys(v47);
    get_memory(v51);
    sys_runinfo_get(v49);
    v5 = (const char *)custom_tb_version();
    v6 = sprintf(v48, "%s", v5);
    v7 = v6 <= 0;
    v8 = &v45[v6];
    if ( !v7 )
      v8[511] = 0;
    v9 = (char *)jhl_nv_get_def("lan_netmask");
    if ( !v9 )
      v9 = "";
    v52 = (unsigned int)"";
    v10 = StrToIp(v9);
    v11 = htonl(v10);
    v12 = get_netmask_wei(v11);
    v13 = (const char *)jhl_nv_get_def("lan_ipaddr");
    if ( !v13 )
      v13 = (const char *)v52;
    v64 = (const char *)v50;
    snprintf((char *)v50, 32, "%s/%d", v13, v12);
    strcpy(v4, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v4, "{\"code\":0,\"error\":\"\"", 20);
    v55 = (const char *)wayos_version;
    v56 = (const char *)tomato_buildtime;
    v57 = (const char *)wys_svn_info;
    v58 = (const char *)jhl_nv_get_def("http_hadmin_en");
    v59 = time(0);
    v60 = v51[0];
    v61 = v51[1];
    v14 = (const char *)nvram_get("lan_hwaddr");
    v54 = v4 + 29;
    if ( !v14 )
      v14 = "00:00:00:00:00:00";
    v62 = user_num_get();
    v15 = (const char *)nvram_get("device_cpu_rate");
    if ( !v15 )
      v15 = "1";
    v63 = (const char *)nvram_get("tm_sel");
    v16 = (const char *)nvram_get("vue_health_score");
    v54 = "0";
    if ( !v16 )
      v16 = "0";
    v17 = (const char *)nvram_get("acserver_http_port");
    if ( !v17 )
      v17 = v54;
    v18 = (const char *)nvram_get("http_lanport");
    if ( !v18 )
      v18 = (const char *)v52;
    v73 = v18;
    v72 = v49[2];
    v71 = v49[3];
    v70 = v49[0];
    v69 = v49[1];
    v68 = v49[4];
    v67 = v49[5];
    v65 = get_devmg_lan_id();
    v19 = nvram_get_int("mqttvpn_sdwan_total_node");
    v66 = v65 - v19;
    v65 = get_devmg_lan_id();
    v20 = nvram_get_int("tr069_httpd_port");
    v44 = (const char *)v52;
    v52 = 2031616;
    v21 = snprintf(
            v4 + 29,
            2097123,
            "\"sn\":\"%s\",\"tbv\":\"%s\",\"pt\":\"%s\",\"ver\":\"%s\",\"vtm\":\"%s\",\"svn\":\"%s\",\"isap\":%s,\"ap_fla"
            "g\":%d,\"http_hadmin_en\":%s,\"rttm\":\"%u\",\"atime\":\"%s\",\"memall\":\"%lu\",\"memfree\":\"%lu\",\"lanip"
            "\":\"%s\",\"lanmac\":\"%s\",\"usernum\":\"%d\",\"cpurate\":\"%s\",\"tm_sel\":\"%s\",\"wififlag\":\"%d\",\"he"
            "alth_score\":\"%s\",\"dev_type\":%d,\"acport\":%s,\"acstate\":%d,\"apname\":\"%s\",\"gwsn\":\"%s\",\"gwip\":"
            "\"%s\",\"gwport\":%s,\"user_2g\":%d,\"user_5g\":%d,\"vpn_port\":%d,\"ct_max\":%u,\"ct_num\":%u,\"rt_max\":%u"
            ",\"rt_num\":%u,\"skb_zong\":%u,\"skb_data\":%u,\"ipv6\":%d,\"cpu_temp\":\"%s\",\"sdwan_port\":%d,\"lan_port\""
            ":%d,\"ai\":%d,\"tr069_acsport\":%d,\"bill\":%d,\"show_port\":%d",
            v46,
            v48,
            "ralink",
            v55,
            v56,
            v57,
            v54,
            0,
            v58,
            v59,
            v53,
            v60,
            v61,
            v64,
            v14,
            v62,
            v15,
            v63,
            0,
            v16,
            1,
            v17,
            0,
            v44,
            v46,
            "127.0.0.1",
            v73,
            0,
            0,
            101,
            v72,
            v71,
            v70,
            v69,
            v68,
            v67,
            1,
            v45,
            v66,
            v65,
            3,
            v20,
            2,
            1);
    if ( v21 >= (int)(v52 | 0xFFE3) )
      v21 = v52 | 0xFFE2;
    v22 = v21 + 29;
    v23 = 0x200000 - (v21 + 29);
    v24 = snprintf(&v4[v21 + 29], v23, &byte_643D4C);
    if ( v24 >= v23 )
      v24 = 0x1FFFFF - v22;
    v25 = v24 + v22 + get_nvarms((const char **)base_ident_nvarms, (int)&v4[v24 + v22], 0x200000 - (v24 + v22));
    v26 = snprintf(&v4[v25], 0x200000 - v25, "\"wans\":");
    if ( v26 >= 0x200000 - v25 )
      v26 = 0x1FFFFF - v25;
    v27 = v26 + v25 + get_wans_data(&v4[v26 + v25], 0x200000 - (v26 + v25));
    v28 = snprintf(&v4[v27], 0x200000 - v27, ",\"link_stat\":");
    if ( v28 >= 0x200000 - v27 )
      v28 = 0x1FFFFF - v27;
    v29 = v28 + v27 + miitool_data_buf(&v4[v28 + v27], 0x200000 - (v28 + v27));
    v30 = snprintf(&v4[v29], 0x200000 - v29, ",\"x86\":%d,\"common\":%d", 0, 0);
    if ( v30 >= 0x200000 - v29 )
      v30 = 0x1FFFFF - v29;
    v31 = v30 + v29;
    v32 = snprintf(&v4[v30 + v29], 0x200000 - (v30 + v29), ",\"oem\":%d,\"oem_type\":%d", 0, 10);
    if ( v32 >= 0x200000 - v31 )
      v32 = 0x1FFFFF - v31;
    v33 = v32 + v31;
    v34 = snprintf(&v4[v33], 0x200000 - v33, ",\"mr\":[");
    if ( v34 >= 0x200000 - v33 )
      v34 = 0x1FFFFF - v33;
    v35 = v34 + v33 + cgi_signal_to_kernel(10, 5, 1024000);
    v36 = &v4[v35];
    if ( v35 > 0 && *(v36 - 1) == 44 )
      v36 = &v4[--v35];
    *v36 = 0;
    v37 = snprintf(v36, 0x200000 - v35, &byte_6445A0);
    if ( v37 >= 0x200000 - v35 )
      v37 = 0x1FFFFF - v35;
    v38 = v35 + v37;
    v39 = snprintf(&v4[v38], 0x200000 - v38, "}}");
    if ( v39 >= 0x200000 - v38 )
      v40 = 0x1FFFFF - v38;
    else
      v40 = v39;
    result = httpd_cgi_ret(a1, v4, v40 + v38, 8);
  }
  else
  {
    v42 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v53 = v47;
    v43 = snprintf(v47, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v42);
    if ( v43 >= 0x80 )
      v43 = 127;
    result = httpd_cgi_ret(a1, v53, v43, 4);
  }
  return result;
}
// 436EDC: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 643D4C: using guessed type char byte_643D4C;
// 6445A0: using guessed type char byte_6445A0;
// 66D240: using guessed type char *base_ident_nvarms[5];
// 6A81AC: using guessed type int __fastcall get_netmask_wei(_DWORD);
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81E4: using guessed type int __fastcall sys_runinfo_get(_DWORD);
// 6A82D0: using guessed type int __fastcall miitool_data_buf(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83F8: using guessed type int get_devmg_lan_id(void);
// 6A8444: using guessed type int __fastcall get_uptime_sys(_DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A84E4: using guessed type int __fastcall sq_file_get_id(_DWORD, _DWORD);
// 6A85CC: using guessed type int __fastcall get_memory(_DWORD);
// 6A862C: using guessed type int __fastcall StrToIp(_DWORD);
// 6A8764: using guessed type int __fastcall cgi_signal_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A8788: using guessed type int custom_tb_version(void);
// 6A87CC: using guessed type int user_num_get(void);
// 6A8800: using guessed type int __fastcall sq_file_get_ssid_en(_DWORD, _DWORD);

