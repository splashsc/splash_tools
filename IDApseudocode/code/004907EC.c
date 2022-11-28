int __fastcall sub_4907EC(int a1)
{
  int v1; // $a0
  int v2; // $v0
  int v3; // $s0
  int v4; // $v0
  _DWORD *v5; // $s0
  int v6; // $s4
  char *v7; // $s2
  int v8; // $s6
  int v9; // $s5
  const char *v10; // $s1
  char *v11; // $v1
  int v12; // $v0
  const char *v13; // $v0
  char *v15; // $v1
  const char *v16; // $v0
  int v17; // $t0
  int v18; // $a3
  int v19; // $a2
  int v20; // $a1
  int v22; // $v0
  const char *v23; // $v0
  int v24; // $v0
  int v25; // $v0
  int v26; // $v0
  int v27; // $v0
  const char *v28; // $v0
  int v29; // $v0
  int v30; // $v0
  int v31; // $v0
  int v32; // $v0
  int v33; // $v0
  const char *v34; // $v0
  int v35; // $v0
  char v36[1024]; // [sp+18h] [-460h] BYREF
  int v37[8]; // [sp+418h] [-60h] BYREF
  int v38[6]; // [sp+438h] [-40h] BYREF
  char *v39; // [sp+450h] [-28h]
  int v40; // [sp+454h] [-24h]
  int v41; // [sp+458h] [-20h]
  char *v42; // [sp+45Ch] [-1Ch]
  char *v43; // [sp+460h] [-18h]
  char *v44; // [sp+464h] [-14h]
  int v45; // [sp+468h] [-10h]
  int v46; // [sp+46Ch] [-Ch]
  char *v47; // [sp+470h] [-8h]
  char *v48; // [sp+474h] [-4h]

  v48 = v36;
  memset(v36, 0, sizeof(v36));
  v45 = httpd_get_json_parm(a1, (int)"wans");
  v46 = cJSON_GetArraySize(v45);
  if ( v46 <= 0 )
    goto LABEL_21;
  v42 = "1\"";
  v44 = "a";
  v40 = 0;
  v39 = "l2tp";
  do
  {
    v3 = cJSON_GetArrayItem(v45, v40);
    v2 = cJSON_GetObjectItem(v3, "iface");
    v4 = cJSON_GetIntvalue(v2);
    v5 = *(_DWORD **)(v3 + 8);
    v6 = v4;
    if ( !v5 )
      continue;
    v7 = (char *)v5[4];
    v8 = 0;
    if ( !v7 )
      continue;
    v41 = 0;
    v9 = 0;
    v43 = 0;
    do
    {
      v10 = (const char *)v5[8];
      if ( !strcmp(v10, "iface") )
        goto LABEL_15;
      if ( !strcmp(v10, "vpnqos_dk") )
      {
        v8 = (int)v7;
      }
      else
      {
        v22 = jhl_vpnget(v10, v6);
        v23 = (const char *)nvram_get(v22);
        if ( !v23 || strcmp(v23, v7) )
        {
          v24 = strcmp(v10, v44 + 10188);
          v11 = "a";
          if ( v24 )
          {
            v47 = "a";
            v32 = jhl_vpnget(v10, v6);
            nvram_set(v32, v7);
            v41 = 1;
            v11 = v47;
          }
          else
          {
            v43 = v7;
            v41 = 1;
          }
          goto LABEL_10;
        }
      }
      v11 = "a";
LABEL_10:
      v12 = jhl_vpnget(v11 + 10188, v6);
      v13 = (const char *)nvram_get(v12);
      if ( v13 && !strcmp(v13, v39) )
        v9 = 1;
      if ( !strcmp(v10, "ipsec_l2tp_cli_enable") || !strcmp(v10, v42 - 18968) )
        v9 = 1;
LABEL_15:
      v5 = (_DWORD *)*v5;
      if ( !v5 )
        break;
      v7 = (char *)v5[4];
    }
    while ( v7 );
    if ( v8 )
      qos_parm_apply(v6 + 101, v8, 1);
    if ( v41 )
    {
      v37[0] = 0;
      v37[1] = 0;
      v37[2] = 0;
      v37[3] = 0;
      v37[4] = 0;
      v37[5] = 0;
      v37[6] = 0;
      v37[7] = 0;
      sprintf((char *)v37, "%d", v6);
      v25 = jhl_vpnget("vpn_new_proto", v6);
      nvram_unset(v25);
      v26 = jhl_vpnget("vpn_ipsec_l2tp", v6);
      if ( v9 )
        nvram_set(v26, "1");
      else
        nvram_unset(v26);
      if ( v43 )
      {
        if ( !strcmp(v43, v39) )
        {
          v33 = jhl_vpnget("vpn_port", v6);
          nvram_set(v33, "1701");
          v34 = (const char *)nvram_get("l2tpd_en");
          if ( v34 && !strcmp(v34, "1") )
          {
            nvram_set("l2tpd_en", "0");
            jhl_stop_l2tpd_srv();
          }
        }
        else if ( !strcmp(v43, "pptp") )
        {
          v35 = jhl_vpnget("vpn_port", v6);
          nvram_set(v35, "1723");
        }
        v27 = jhl_vpnget(v44 + 10188, v6);
        v28 = (const char *)nvram_get(v27);
        if ( !v28 || strcmp(v28, v43) )
        {
          v29 = jhl_vpnget("vpn_new_proto", v6);
          nvram_set(v29, v43);
        }
      }
      v30 = jhl_vpnget("vpn_conn_cnt", v6);
      nvram_set_int(v30, 0);
      v31 = jhl_vpnget("vpn_run_wan", v6);
      nvram_unset(v31);
      v38[0] = (int)"vpn_conn";
      v38[1] = (int)"restart";
      v38[2] = (int)v37;
      v38[3] = (int)"vpn_client_asp";
      v38[4] = 0;
      eval_nowait(v38, 0, 0, 0);
    }
  }
  while ( v46 != ++v40 );
LABEL_21:
  jhl_parm_commit(v1);
  v15 = v48;
  v16 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v17 = *(_DWORD *)v16;
    v18 = *((_DWORD *)v16 + 1);
    v19 = *((_DWORD *)v16 + 2);
    v20 = *((_DWORD *)v16 + 3);
    v16 += 16;
    *(_DWORD *)v15 = v17;
    *((_DWORD *)v15 + 1) = v18;
    *((_DWORD *)v15 + 2) = v19;
    *((_DWORD *)v15 + 3) = v20;
    v15 += 16;
  }
  while ( v16 != "}" );
  *(_WORD *)v15 = *(_WORD *)v16;
  return httpd_cgi_ret(a1, v48, 33, 4);
}
// 490A6C: variable 'v1' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81F0: using guessed type int jhl_stop_l2tpd_srv(void);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8744: using guessed type int __fastcall cJSON_GetIntvalue(_DWORD);
// 6A878C: using guessed type int __fastcall nvram_set_int(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

