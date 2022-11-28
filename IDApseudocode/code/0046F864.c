int __fastcall sub_46F864(int a1)
{
  char *v1; // $v0
  char *v2; // $s0
  int v3; // $a2
  const char *v4; // $fp
  const char *v5; // $s1
  const char *v6; // $s2
  const char *v7; // $s3
  const char *v8; // $s4
  const char *v9; // $s5
  const char *v10; // $s6
  const char *v11; // $s7
  const char *v12; // $v1
  const char *v13; // $v0
  int v14; // $s1
  int v15; // $s1
  int v16; // $s1
  int v17; // $s1
  int v18; // $s1
  const char *v19; // $s7
  const char *v20; // $s2
  const char *v21; // $s3
  const char *v22; // $s4
  const char *v23; // $s5
  const char *v24; // $s6
  const char *v25; // $v0
  int v26; // $s1
  const char *v27; // $s2
  const char *v28; // $v0
  int v29; // $s1
  const char *v30; // $s3
  const char *v31; // $v0
  int v32; // $s1
  const char *v33; // $s3
  const char *v34; // $v0
  char *v36; // $v0
  const char *v37; // $v0
  unsigned int v38; // $v0
  char v39[2048]; // [sp+70h] [-1188h] BYREF
  char v40[1024]; // [sp+870h] [-988h] BYREF
  __int16 v41[256]; // [sp+C70h] [-588h] BYREF
  __int16 v42[128]; // [sp+E70h] [-388h] BYREF
  __int16 v43[128]; // [sp+F70h] [-288h] BYREF
  __int16 v44[128]; // [sp+1070h] [-188h] BYREF
  int v45[8]; // [sp+1170h] [-88h] BYREF
  int v46[14]; // [sp+1190h] [-68h] BYREF
  char *dest; // [sp+11C8h] [-30h]
  char *v48; // [sp+11CCh] [-2Ch]
  char *v49; // [sp+11D0h] [-28h]
  const char *v50; // [sp+11D4h] [-24h]
  char *v51; // [sp+11D8h] [-20h]
  const char *v52; // [sp+11DCh] [-1Ch]
  const char *v53; // [sp+11E0h] [-18h]
  const char *v54; // [sp+11E4h] [-14h]
  const char *v55; // [sp+11E8h] [-10h]
  const char *v56; // [sp+11ECh] [-Ch]
  const char *v57; // [sp+11F0h] [-8h]

  v46[0] = 48;
  v45[0] = 48;
  v46[1] = 0;
  v46[2] = 0;
  v46[3] = 0;
  v46[4] = 0;
  v46[5] = 0;
  v46[6] = 0;
  v46[7] = 0;
  v45[1] = 0;
  v45[2] = 0;
  v45[3] = 0;
  v45[4] = 0;
  v45[5] = 0;
  v45[6] = 0;
  v45[7] = 0;
  v51 = (char *)jhl_nv_get_def("dual_lan_mode");
  _mem_malloc(102400, "rzgl_data", 173);
  v2 = v1;
  if ( !v1 )
  {
    v37 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v38 = snprintf(v39, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v37);
    if ( v38 >= 0x100 )
      v38 = 255;
    httpd_cgi_ret(a1, v39, v38, 4);
    JUMPOUT(0x4701A8);
  }
  v55 = (const char *)v44;
  jhl_parm_get("rzglType", v44, 256);
  v53 = (const char *)v42;
  jhl_parm_get("rzglTq", v42, 256);
  dest = v40;
  jhl_parm_get("rzglMsg", v40, 1024);
  v56 = (const char *)v41;
  jhl_parm_get("rzglLx", v41, 512);
  v54 = (const char *)v43;
  jhl_parm_get("rzglAtype", v43, 256);
  if ( !LOBYTE(v43[0]) )
    v43[0] = 48;
  if ( !LOBYTE(v44[0]) )
    v44[0] = 48;
  if ( !LOBYTE(v42[0]) )
    v42[0] = 55;
  if ( !v40[0] )
  {
    v36 = (char *)_GET_LANG_TEXT(51, *(unsigned __int8 *)(a1 + 210102), v3);
    strcpy(dest, v36);
  }
  if ( !LOBYTE(v41[0]) )
    v41[0] = 32;
  strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":{");
  qmemcpy(v2, "{\"code\":0,\"error", 16);
  v4 = (const char *)nvram_get("rzglUnline");
  v48 = v2 + 29;
  if ( !v4 )
    v4 = "0";
  v48 = (char *)nvram_get("web_exit");
  if ( !v48 )
    v48 = "0";
  v49 = (char *)nvram_get("web_anyuser");
  if ( !v49 )
    v49 = "0";
  v50 = (const char *)nvram_get("rzglFip");
  if ( !v50 )
    v50 = "not";
  v52 = (const char *)jhl_nv_get_def("rzglDns");
  v5 = (const char *)nvram_get("rzglHost");
  if ( !v5 )
    v5 = "not";
  v6 = (const char *)nvram_get("rzglMac");
  if ( !v6 )
    v6 = "not";
  v7 = (const char *)nvram_get("rzgl_web_ageing_time");
  if ( !v7 )
    v7 = "15";
  v8 = (const char *)nvram_get("rzgl_redirct_url");
  if ( !v8 )
    v8 = "http://";
  v9 = (const char *)nvram_get("rzgl_redirct_en");
  if ( !v9 )
    v9 = "0";
  v10 = (const char *)nvram_get("rzgl_third_url");
  if ( !v10 )
    v10 = "http://";
  v11 = (const char *)nvram_get("rzgl_third_timeout");
  if ( !v11 )
    v11 = (const char *)&unk_4D15F8;
  v12 = (const char *)nvram_get("vmiandan_checktime");
  if ( !v12 )
    v12 = "0";
  v57 = v12;
  v13 = (const char *)nvram_get("vmiandan_checkcount");
  if ( !v13 )
    v13 = "3";
  v14 = sprintf(
          v2 + 29,
          "\"type\":%s,\"tq\":%s,\"unline\":%s,\"msg\":\"%s\",\"lx\":\"%s\",\"auto_type\":%s,\"web_exit\":%s,\"web_anyuse"
          "r\":%s,\"web_type\":\"%s\",\"pppoe_type\":\"%s\",\"fip\":\"%s\",\"dns\":\"%s\",\"host\":\"%s\",\"mac\":\"%s\","
          "\"timeout\":\"%s\",\"redirct_url\":\"%s\",\"redirct_en\":\"%s\",\"third_url\":\"%s\",\"third_timeout\":\"%s\","
          "\"vmiandan_checktime\":\"%s\",\"vmiandan_checkcount\":\"%s\",\"third_enable\":\"%d\",\"web_rztz_show\":%d",
          v55,
          v53,
          v4,
          dest,
          v56,
          v54,
          v48,
          v49,
          (const char *)v46,
          (const char *)v45,
          v50,
          v52,
          v5,
          v6,
          v7,
          v8,
          v9,
          v10,
          v11,
          v57,
          v13,
          1,
          1)
      + 29;
  v15 = v14 + sprintf(&v2[v14], ",\"rzgl_localMac\":\"%d\",\"flag\":\"%d\"", 1, 0);
  v16 = v15 + sprintf(&v2[v15], ",\"rzgl_localIp\":\"%d\"", 1);
  v17 = v16 + sprintf(&v2[v16], ",\"userinfo_en\":\"%d\"", 0);
  v18 = v17 + sprintf(&v2[v17], ",\"any_user\":%d", 1);
  v19 = (const char *)jhl_nv_get_def("rzgl_pc_no_auth");
  v20 = (const char *)jhl_nv_get_def("rzgl_noauth_pc");
  v21 = (const char *)jhl_nv_get_def("rzgl_noauth_ssid1");
  v22 = (const char *)jhl_nv_get_def("rzgl_noauth_ssid2");
  v23 = (const char *)jhl_nv_get_def("rzgl_noauth_ssid3");
  v24 = (const char *)jhl_nv_get_def("rzgl_noauth_ssid4");
  v25 = (const char *)jhl_nv_get_def("rzgl_noauth_ssid5");
  v26 = v18
      + sprintf(
          &v2[v18],
          ",\"noauth_show\":\"%d\",\"noauth_en\":%s,\"noauth_pc\":%s,\"noauth_ssid1\":%s,\"noauth_ssid2\":%s,\"noauth_ssi"
          "d3\":%s,\"noauth_ssid4\":%s,\"noauth_ssid5\":%s",
          1,
          v19,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25);
  v27 = (const char *)jhl_nv_get_def("rzgl_mac_en");
  v28 = (const char *)jhl_nv_get_def("rzgl_mac_timeout");
  v29 = v26 + sprintf(&v2[v26], ",\"mac_show\":\"%d\",\"mac_en\":%s,\"mac_timeout\":\"%s\"", 1, v27, v28);
  if ( !strcmp(v51, "1") )
    JUMPOUT(0x4701D8);
  strcpy(&v2[v29], ",\"iface_show\":\"0\"");
  qmemcpy(&v2[v29], ",\"iface_show", 12);
  v30 = (const char *)jhl_nv_get_def("tggl_port");
  v31 = (const char *)jhl_nv_get_def("save_auth_log_usb");
  v32 = v29 + 17 + sprintf(&v2[v29 + 17], ",\"tggl_port\":\"%s\",\"usblog_show\":\"%d\",\"usblog\":\"%s\"", v30, 1, v31);
  v33 = (const char *)jhl_nv_get_def("rzgl_second_auth_en");
  v34 = (const char *)jhl_nv_get_def("rzgl_second_auth_url");
  sprintf(&v2[v32], ",\"second_auth_show\":\"%d\",\"second_auth_en\":\"%s\",\"second_auth_url\":\"%s\"", 0, v33, v34);
  return sub_470000();
}
// 47045C: control flows out of bounds to 4701A8
// 46FEF8: control flows out of bounds to 4701D8
// 46F924: variable 'v1' is possibly undefined
// 4702F0: variable 'v3' is possibly undefined
// 470000: using guessed type int sub_470000(void);
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

