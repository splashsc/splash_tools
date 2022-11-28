int __fastcall sub_44C388(int a1)
{
  char *v1; // $v0
  char *v2; // $s0
  char *v3; // $fp
  char *v4; // $s1
  char *v5; // $s2
  char *v6; // $s3
  char *v7; // $s4
  char *v8; // $s5
  char *v9; // $s6
  char *v10; // $s7
  char *v11; // $v1
  char *v12; // $v0
  int v13; // $v0
  int v14; // $v0
  int v15; // $s1
  const char *v16; // $s3
  int v17; // $s2
  const char *v18; // $v0
  int v19; // $v0
  int v20; // $s1
  int v21; // $v0
  int v22; // $a2
  const char *v24; // $v0
  unsigned int v25; // $v0
  char *v26; // [sp+58h] [-140h]
  char v27[256]; // [sp+68h] [-130h] BYREF
  int v28; // [sp+168h] [-30h]
  char *v29; // [sp+16Ch] [-2Ch]
  char *v30; // [sp+170h] [-28h]
  char *v31; // [sp+174h] [-24h]
  char *v32; // [sp+178h] [-20h]
  char *v33; // [sp+17Ch] [-1Ch]
  const char *v34; // [sp+180h] [-18h]
  char *v35; // [sp+184h] [-14h]
  int v36; // [sp+188h] [-10h]
  int v37; // [sp+18Ch] [-Ch]
  char *v38; // [sp+190h] [-8h]

  memset(v27, 0, sizeof(v27));
  v36 = nvram_get_int("mqtt_ai_server_mode");
  _mem_malloc(204800, "wys_ai_state_data", 640);
  v2 = v1;
  if ( v1 )
  {
    strcpy(v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v1, "{\"code\":0,\"error", 16);
    v3 = (char *)jhl_nv_get_def("mqtt_ai_enable");
    v28 = (int)(v2 + 29);
    if ( !v3 )
      v3 = "";
    v28 = jhl_nv_get_def("wys_mqtt_ai_v3_addr");
    if ( !v28 )
      v28 = (int)"";
    v29 = (char *)jhl_nv_get_def("wys_mqtt_ai_v3_port");
    if ( !v29 )
      v29 = "";
    v30 = (char *)jhl_nv_get_def("mqtt_ai_ping_addr1");
    if ( !v30 )
      v30 = "";
    v31 = (char *)jhl_nv_get_def("mqtt_ai_ping_addr2");
    if ( !v31 )
      v31 = "";
    v32 = (char *)jhl_nv_get_def("wys_mqtt_ai_state");
    if ( !v32 )
      v32 = "";
    v33 = (char *)jhl_nv_get_def("wys_mqtt_ai_online");
    if ( !v33 )
      v33 = "";
    v34 = (const char *)nvram_get("mqtt_ai_sdwan_iface");
    if ( !v34 )
      v34 = "65535";
    v35 = (char *)jhl_nv_get_def("mqtt_ai_pversion");
    if ( !v35 )
      v35 = "";
    v4 = (char *)jhl_nv_get_def("mqtt_ai_login_count");
    if ( !v4 )
      v4 = "";
    v5 = (char *)jhl_nv_get_def("mqtt_ai_user_id");
    if ( !v5 )
      v5 = "";
    v6 = (char *)jhl_nv_get_def("mqtt_ai_user_name");
    if ( !v6 )
      v6 = "";
    v7 = (char *)jhl_nv_get_def("mqtt_ai_user_mobile");
    if ( !v7 )
      v7 = "";
    v8 = (char *)jhl_nv_get_def("mqtt_ai_scene_name");
    if ( !v8 )
      v8 = "";
    v9 = (char *)jhl_nv_get_def("mqtt_ai_client_mode");
    if ( !v9 )
      v9 = "";
    v10 = (char *)jhl_nv_get_def("mqtt_ai_main_mode");
    if ( !v10 )
      v10 = "";
    v37 = get_sn();
    v11 = (char *)jhl_nv_get_def("mqtt_ai_server_url");
    if ( !v11 )
      v11 = "";
    v38 = v11;
    v12 = (char *)jhl_nv_get_def("mqtt_sdwan_mode");
    if ( !v12 )
      v12 = "";
    v26 = v12;
    v13 = v28;
    v28 = 196608;
    v14 = snprintf(
            v2 + 29,
            204771,
            aEnSSrvAddrSSrv,
            v3,
            v13,
            v29,
            v30,
            v31,
            v32,
            v33,
            v34,
            v35,
            v4,
            v5,
            v6,
            v7,
            v8,
            v36,
            v9,
            v10,
            v37,
            v38,
            v26,
            0);
    if ( v14 >= (v28 | 0x1FE3) )
      v14 = v28 + 8162;
    v15 = v14 + 29 + get_wans_data(&v2[v14 + 29], 204800 - (v14 + 29));
    v16 = (const char *)jhl_nv_get_def("mqtt_ai_sdwan_link");
    v17 = 204800 - v15;
    if ( v16 )
    {
      v18 = (const char *)jhl_nv_get_def("mqtt_ai_sdwan_state");
      if ( v18 )
      {
LABEL_42:
        v19 = snprintf(&v2[v15], v17, ",\"sdwan_link\":[%s],\"sdwan_state\":\"%s\"", v16, v18);
        if ( v19 >= v17 )
          v19 = 204799 - v15;
        v20 = v19 + v15;
        v21 = snprintf(&v2[v20], 204800 - v20, "}}");
        if ( v21 >= 204800 - v20 )
          v22 = 204799 - v20;
        else
          v22 = v21;
        return httpd_cgi_ret(a1, v2, v22 + v20, 8);
      }
    }
    else
    {
      v18 = (const char *)jhl_nv_get_def("mqtt_ai_sdwan_state");
      v16 = "";
      if ( v18 )
        goto LABEL_42;
    }
    v18 = "";
    goto LABEL_42;
  }
  v24 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 204800);
  v25 = snprintf(v27, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
  if ( v25 >= 0x100 )
    v25 = 255;
  return httpd_cgi_ret(a1, v27, v25, 4);
}
// 44C424: variable 'v1' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81D8: using guessed type int get_sn(void);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);

