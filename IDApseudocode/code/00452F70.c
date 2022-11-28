int get_diagnosis_result()
{
  int v0; // $s1
  int v1; // $s2
  int v2; // $s0
  int v3; // $v0
  _BOOL4 v4; // $s2
  _BOOL4 v5; // $v0
  int v6; // $s2
  int v7; // $a3
  int v8; // $s2
  int v9; // $v1
  char *v10; // $v0
  int v11; // $v1
  char *v12; // $s2
  const char *v13; // $v0
  const char *v14; // $v0
  const char *v15; // $v0
  const char *v16; // $v0
  int v17; // $v0
  int v18; // $s2
  int v19; // $s2
  int v20; // $v1
  int v21; // $v0
  _BOOL4 v22; // $s2
  int v23; // $v1
  int v24; // $v0
  int v25; // $s2
  int v26; // $s2
  int v27; // $v1
  _BOOL4 v28; // $s2
  int v29; // $v1
  int v30; // $v0
  int v32; // $a3
  int v33; // $a3
  int v34; // $s2
  int v35; // $v1
  int v36; // $s2
  int v37; // $v1
  int v38; // $s2
  int v39; // $v1
  int v40; // $s2
  int v41; // $v1
  char v42[2048]; // [sp+18h] [-80Ch] BYREF
  int v43[3]; // [sp+818h] [-Ch] BYREF

  v43[0] = 0;
  v0 = cJSON_CreateObject();
  v1 = wan_port_max_speed_get(1);
  if ( v1 <= 0 )
  {
    cJSON_AddNumberToObject(v0, "line", 0, 1072693248);
    v2 = 0;
  }
  else
  {
    cJSON_AddNumberToObject(v0, "line", 0, 0);
    v2 = 1;
  }
  v3 = wan_port_max_speed_get(0);
  v4 = v1 < 4;
  if ( v3 > 0 )
  {
    v5 = v3 < 4;
    if ( !v4 && !v5 )
      goto LABEL_41;
LABEL_5:
    cJSON_AddNumberToObject(v0, "speed", 0, 1072693248);
    goto LABEL_6;
  }
  if ( v4 )
    goto LABEL_5;
LABEL_41:
  cJSON_AddNumberToObject(v0, "speed", 0, 0);
  ++v2;
LABEL_6:
  v6 = wan_proto_check(v43);
  if ( !v6 )
  {
    cJSON_AddNumberToObject(v0, "wan_conf", 0, 1072693248);
    goto LABEL_8;
  }
  cJSON_AddNumberToObject(v0, "wan_conf", 0, 0);
  if ( v6 == 2 )
  {
    if ( v43[0] )
      v32 = 0;
    else
      v32 = 1072693248;
    cJSON_AddNumberToObject(v0, "dhcp_addr", 0, v32);
    if ( v43[0] )
    {
LABEL_39:
      v2 += 2;
      goto LABEL_12;
    }
LABEL_47:
    ++v2;
    goto LABEL_12;
  }
  if ( v6 == 4 )
  {
    if ( v43[0] )
      v33 = 0;
    else
      v33 = 1072693248;
    cJSON_AddNumberToObject(v0, "pppoe_addr", 0, v33);
    if ( v43[0] )
      goto LABEL_39;
    goto LABEL_47;
  }
  ++v2;
LABEL_8:
  if ( v43[0] )
    v7 = 0;
  else
    v7 = 1072693248;
  cJSON_AddNumberToObject(v0, "static_addr", 0, v7);
  if ( v43[0] )
    ++v2;
LABEL_12:
  v8 = wan_lan_confilict();
  cJSON_AddNumberToObject(v0, "wan_lan_confilict", v8, v9);
  if ( !v8 )
    ++v2;
  if ( !get_log_data_in_time(27, v42, 2048, 10) )
  {
    cJSON_AddNumberToObject(v0, "broadcast_loop", 0, 0);
LABEL_49:
    cJSON_AddNumberToObject(v0, "ip_confilict", 0, 0);
    v2 += 2;
    goto LABEL_18;
  }
  v12 = strstr(v42, byte_6455B0);
  v10 = strstr(v42, byte_6455BC);
  if ( !v10 )
  {
    cJSON_AddNumberToObject(v0, "broadcast_loop", 0, v11);
    if ( v12 )
    {
      cJSON_AddNumberToObject(v0, "ip_confilict", 0, 0);
      ++v2;
      goto LABEL_18;
    }
    goto LABEL_49;
  }
  cJSON_AddNumberToObject(v0, "broadcast_loop", v10, v11);
  cJSON_AddNumberToObject(v0, "ip_confilict", 0, 1072693248);
  if ( !v12 )
    ++v2;
LABEL_18:
  v13 = (const char *)nvram_get("dhcp_ck_state");
  if ( v13 )
  {
    if ( !strcmp(v13, "1") )
    {
      v34 = nvram_get_int("dhcp_ck_num");
      cJSON_AddNumberToObject(v0, "dhcp_confilict", v34, v35);
      if ( !v34 )
        ++v2;
    }
  }
  v14 = (const char *)nvram_get("wan_http_ck_state");
  if ( v14 )
  {
    if ( !strcmp(v14, "1") )
    {
      v36 = nvram_get_int("wan_http_ck_err");
      cJSON_AddNumberToObject(v0, "route_conf", v36, v37);
      if ( !v36 )
        ++v2;
    }
  }
  v15 = (const char *)nvram_get("wan_gw_ck_state");
  if ( v15 )
  {
    if ( !strcmp(v15, "1") )
    {
      v38 = nvram_get_int("wan_gw_ck_err");
      cJSON_AddNumberToObject(v0, "next_route", v38, v39);
      if ( !v38 )
        ++v2;
    }
  }
  v16 = (const char *)nvram_get("wan_dns_ck_state");
  if ( v16 )
  {
    if ( !strcmp(v16, "1") )
    {
      v40 = nvram_get_int("wan_dns_ck_err");
      cJSON_AddNumberToObject(v0, "dns_conf", v40, v41);
      if ( !v40 )
        ++v2;
    }
  }
  v18 = ct_low_limit_check(100);
  v17 = ct_default_low_limit_check(100, 1000, 10000);
  v19 = v18 + v17;
  cJSON_AddNumberToObject(v0, "ct_check", v17, v20);
  if ( !v19 )
    ++v2;
  v21 = get_dhcp_left_num();
  v22 = v21 < 10;
  cJSON_AddNumberToObject(v0, "dhcp_pool", v21, v23);
  if ( !v22 )
    ++v2;
  v25 = qos_low_limit_check(100);
  v24 = qos_default_low_limit_check(100);
  v26 = v25 + v24;
  cJSON_AddNumberToObject(v0, "qos_check", v24, v27);
  if ( !v26 )
    ++v2;
  v28 = ai_is_running(1);
  cJSON_AddNumberToObject(v0, "ai_conf", v28, v29);
  v30 = 4 * v2;
  if ( v28 )
  {
    ++v2;
    v30 = 4 * v2;
  }
  nvram_set_int("vue_health_score", 5 * (v30 + 16 * v2) / 15);
  return v0;
}
// 4530FC: variable 'v9' is possibly undefined
// 4531A0: variable 'v11' is possibly undefined
// 453338: variable 'v20' is possibly undefined
// 453390: variable 'v23' is possibly undefined
// 453400: variable 'v27' is possibly undefined
// 453458: variable 'v29' is possibly undefined
// 453668: variable 'v35' is possibly undefined
// 4536C8: variable 'v37' is possibly undefined
// 453728: variable 'v39' is possibly undefined
// 453788: variable 'v41' is possibly undefined
// 6A81B0: using guessed type int get_dhcp_left_num(void);
// 6A81B4: using guessed type int __fastcall nvram_get_int(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8258: using guessed type int cJSON_CreateObject(void);
// 6A8328: using guessed type int __fastcall get_log_data_in_time(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84A4: using guessed type int __fastcall ct_low_limit_check(_DWORD);
// 6A8650: using guessed type int __fastcall qos_low_limit_check(_DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A87A4: using guessed type int __fastcall wan_proto_check(_DWORD);
// 6A87C8: using guessed type int __fastcall cJSON_AddNumberToObject(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8810: using guessed type int wan_lan_confilict(void);
// 6A8960: using guessed type int __fastcall ct_default_low_limit_check(_DWORD, _DWORD, _DWORD);
// 6A899C: using guessed type int __fastcall qos_default_low_limit_check(_DWORD);

