int __fastcall wan_webset_json(int a1)
{
  int v1; // $s0
  int v2; // $s7
  int v3; // $fp
  int v4; // $v0
  int v5; // $s0
  int v6; // $v0
  int v7; // $s2
  int v8; // $v0
  _DWORD *v9; // $s4
  const char *v10; // $s3
  const char *v11; // $s0
  _DWORD *v12; // $s1
  char *v13; // $s4
  const char *v14; // $s1
  char *v15; // $v0
  int v16; // $v0
  const char *v17; // $v0
  int v18; // $v0
  int v19; // $s0
  int v20; // $v0
  const char *v21; // $v0
  int v22; // $v0
  int v23; // $v0
  int v24; // $v0
  char *v25; // $v0
  int v26; // $v0
  char *v27; // $v0
  int v28; // $v0
  const char *v29; // $v0
  int v30; // $v0
  char *v31; // $v0
  int v33; // $v0
  int v34; // $v0
  const char *v35; // $v0
  int v36; // $v0
  const char *v37; // $v0
  int v38; // $v0
  int v39; // $v0
  const char *v40; // $v0
  int v41; // $v0
  const char *v42; // $v0
  int v43; // $v0
  int v44; // $v0
  const char *v45; // $v0
  int v46; // $v0
  const char *v47; // $v0
  int v48; // $v0
  size_t v49; // $v0
  char v50[512]; // [sp+18h] [-290h] BYREF
  const char *v51; // [sp+218h] [-90h] BYREF
  const char *v52; // [sp+21Ch] [-8Ch]
  char *v53; // [sp+220h] [-88h]
  char *v54; // [sp+224h] [-84h]
  char *v55; // [sp+228h] [-80h]
  const char *v56; // [sp+22Ch] [-7Ch]
  char *v57; // [sp+230h] [-78h]
  int v58; // [sp+234h] [-74h]
  int v59[6]; // [sp+238h] [-70h] BYREF
  char *v60; // [sp+250h] [-58h]
  char *v61; // [sp+254h] [-54h]
  char *v62; // [sp+258h] [-50h]
  char *v63; // [sp+25Ch] [-4Ch]
  char *v64; // [sp+260h] [-48h]
  char *v65; // [sp+264h] [-44h]
  char *v66; // [sp+268h] [-40h]
  char *v67; // [sp+26Ch] [-3Ch]
  int v68; // [sp+270h] [-38h]
  char *v69; // [sp+274h] [-34h]
  char *v70; // [sp+278h] [-30h]
  char *v71; // [sp+27Ch] [-2Ch]
  char *v72; // [sp+280h] [-28h]
  char *v73; // [sp+284h] [-24h]
  char *v74; // [sp+288h] [-20h]
  char *v75; // [sp+28Ch] [-1Ch]
  int v76; // [sp+290h] [-18h]
  int v77; // [sp+294h] [-14h]
  int v78; // [sp+298h] [-10h]
  char *v79; // [sp+29Ch] [-Ch]
  char *v80; // [sp+2A0h] [-8h]
  const char *v81; // [sp+2A4h] [-4h]

  v1 = httpd_get_json_parm(a1, (int)"wans");
  v76 = v1;
  if ( v1 )
  {
    v81 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
    nvram_set("wan_webset_run", "1");
    v77 = cJSON_GetArraySize(v1);
    v2 = 0;
    if ( v77 <= 0 )
    {
      v3 = 0;
      goto LABEL_53;
    }
    v72 = "a";
    v80 = "a";
    v65 = "qos_dk";
    v3 = 0;
    v64 = "wan_time";
    v79 = "mr_jh_en";
    while ( 1 )
    {
      v5 = cJSON_GetArrayItem(v76, v2);
      v4 = cJSON_GetObjectItem(v5, "iface");
      v7 = cJSON_GetIntvalue(v4);
      v6 = cJSON_GetObjectItem(v5, "base64");
      v8 = cJSON_GetIntvalue(v6);
      v9 = *(_DWORD **)(v5 + 8);
      v78 = v8;
      if ( !v9 )
      {
        v69 = 0;
        v67 = 0;
        v63 = 0;
        v73 = 0;
        v74 = 0;
        v75 = 0;
        v70 = 0;
        v68 = 0;
        goto LABEL_34;
      }
      v66 = 0;
      v69 = 0;
      v71 = 0;
      v62 = 0;
      v60 = 0;
      v10 = 0;
      v67 = 0;
      v61 = 0;
      v63 = 0;
      v73 = 0;
      v74 = 0;
      v75 = 0;
      v70 = 0;
      v68 = 0;
      do
      {
        while ( 1 )
        {
          while ( 1 )
          {
            while ( 1 )
            {
              while ( 1 )
              {
                while ( 1 )
                {
                  while ( 1 )
                  {
                    while ( 1 )
                    {
                      v11 = (const char *)v9[8];
                      v12 = (_DWORD *)*v9;
                      if ( !strcmp(v11, "iface") || !strcmp(v11, "base64") )
                        goto LABEL_15;
                      v13 = (char *)v9[4];
                      if ( strcmp(v11, v65) )
                        break;
                      v61 = v13;
                      v9 = v12;
                      if ( !v12 )
                        goto LABEL_16;
                    }
                    if ( strcmp(v11, v64) )
                      break;
                    v10 = v13;
                    v9 = v12;
                    if ( !v12 )
                      goto LABEL_16;
                  }
                  if ( strcmp(v11, v72 + 13564) )
                    break;
                  v60 = v13;
                  v9 = v12;
                  if ( !v12 )
                    goto LABEL_16;
                }
                if ( strcmp(v11, v79) )
                  break;
                v62 = v13;
                v9 = v12;
                if ( !v12 )
                  goto LABEL_16;
              }
              if ( strcmp(v11, v80 + 13588) )
                break;
              v66 = v13;
              v9 = v12;
              if ( !v12 )
                goto LABEL_16;
            }
            if ( strcmp(v11, "host") )
              break;
            v71 = v13;
LABEL_15:
            v9 = v12;
            if ( !v12 )
              goto LABEL_16;
          }
          if ( strcmp(v11, "port_speed") )
            break;
          v69 = v13;
          v9 = v12;
          if ( !v12 )
            goto LABEL_16;
        }
        if ( !strcmp(v11, "wan_dns") )
        {
          v70 = v13;
        }
        else if ( !strcmp(v11, "ppp_passwd") )
        {
          if ( !v78 )
            goto LABEL_100;
          v68 = (int)v50;
          memset(v50, 0, sizeof(v50));
          v49 = strlen(v13);
          base64_decode(v13, v68, v49);
          v13 = (char *)v68;
          v68 = 1;
        }
        else if ( !strcmp(v11, "dns_v") )
        {
          v75 = v13;
        }
        else if ( !strcmp(v11, "jb_en") )
        {
          v74 = v13;
        }
        else if ( !strcmp(v11, "wk_mode") )
        {
          v63 = v13;
        }
        else
        {
          if ( strcmp(v11, "wan_isp") )
          {
LABEL_100:
            v68 = 1;
            goto LABEL_110;
          }
          v67 = v13;
        }
LABEL_110:
        if ( strcmp(v11, "wan_proto") )
        {
          v46 = jhl_nvget(v11, v7);
          v47 = (const char *)nvram_get(v46);
          if ( !v47 || !v13 || strcmp(v47, v13) )
          {
            v48 = jhl_nvget(v11, v7);
            nvram_set(v48, v13);
            v3 = 1;
          }
          goto LABEL_15;
        }
        v73 = v13;
        v9 = v12;
      }
      while ( v12 );
LABEL_16:
      v14 = v10;
      if ( v10 )
      {
        if ( *v10 )
        {
          do
          {
            v15 = strchr(v14++, 124);
            if ( v15 )
              *v15 = 44;
          }
          while ( *v14 );
        }
        v16 = jhl_nvget(v64, v7);
        v17 = (const char *)nvram_get(v16);
        if ( v17 && !strcmp(v17, v10) )
        {
          if ( v60 )
          {
            v19 = 0;
            goto LABEL_25;
          }
        }
        else
        {
          v18 = jhl_nvget(v64, v7);
          nvram_set(v18, v10);
          v3 = 1;
          if ( !v60 )
            goto LABEL_28;
          v19 = 1;
LABEL_25:
          v20 = jhl_nvget(v72 + 13564, v7);
          v21 = (const char *)nvram_get(v20);
          if ( v21 && !strcmp(v21, v60) )
          {
            if ( v19 )
              goto LABEL_29;
          }
          else
          {
            v22 = jhl_nvget(v72 + 13564, v7);
            nvram_set(v22, v60);
LABEL_28:
            v3 = 1;
LABEL_29:
            restart_wan_auto_conn(v7);
          }
        }
      }
      else if ( v60 )
      {
        v19 = 0;
        goto LABEL_25;
      }
      if ( v61 )
      {
        qos_parm_apply(v7, (int)v61, 1);
        v3 = 1;
      }
      if ( v62 || v66 || v71 )
      {
        mr_set_by_jh_en(v7, v62, v66, v71);
        v3 = 1;
      }
LABEL_34:
      if ( v69 )
      {
        v23 = J_atoi(v69);
        set_port_mode(v7, 1, v23);
        v3 = 1;
      }
      if ( v67 )
        v3 = 1;
      if ( v70 || v75 )
      {
        jhl_mr_set_dns(v7);
        v3 = 1;
        jhl_ctreate_dmresolv();
      }
      if ( v63 || v74 || v67 )
      {
        v51 = "wys";
        v52 = "devmg";
        v53 = "set";
        v24 = jhl_nvget("wan_name", v7);
        v25 = (char *)nvram_get(v24);
        if ( !v25 )
          v25 = "";
        v54 = v25;
        v26 = jhl_nvget("jb_en", v7);
        v27 = (char *)nvram_get(v26);
        if ( !v27 )
          v27 = "0";
        v55 = v27;
        v28 = jhl_nvget("wk_mode", v7);
        v29 = (const char *)nvram_get(v28);
        if ( !v29 )
          v29 = "gateway";
        v56 = v29;
        v30 = jhl_nvget("wan_isp", v7);
        v31 = (char *)nvram_get(v30);
        if ( !v31 )
          v31 = "0";
        v57 = v31;
        v58 = 0;
        eval(&v51, 0, 0, 0);
        if ( v63 )
        {
          v3 = 1;
          jhl_start_firewall();
          goto LABEL_51;
        }
        v3 = 1;
        if ( v68 )
          goto LABEL_73;
        goto LABEL_52;
      }
LABEL_51:
      if ( !v68 )
        goto LABEL_52;
LABEL_73:
      v51 = 0;
      v52 = 0;
      v53 = 0;
      v54 = 0;
      v55 = 0;
      v56 = 0;
      v57 = 0;
      v58 = 0;
      sprintf((char *)&v51, "%d", v7);
      v33 = jhl_nvget("wan_new_proto", v7);
      nvram_unset(v33);
      if ( !v73 )
      {
        v44 = jhl_nvget("wan_proto", v7);
        v45 = (const char *)nvram_get(v44);
        if ( v45 && !strcmp(v45, "pppoe") )
          goto LABEL_87;
LABEL_80:
        v59[0] = (int)"wan_conn";
        v59[1] = (int)"restart";
        v59[2] = (int)&v51;
        v59[3] = (int)"wan_webset_json";
        v59[4] = 0;
        eval_nowait(v59, 0, 0, 0);
        v3 = 1;
        goto LABEL_52;
      }
      if ( !strcmp(v73, "pppoe") )
      {
        v34 = jhl_nvget("ppp_demand", v7);
        v35 = (const char *)nvram_get(v34);
        if ( !v35 || strcmp(v35, "2") )
          goto LABEL_77;
        jhl_stop_wan(v7);
LABEL_95:
        v43 = jhl_nvget("wan_proto", v7);
        nvram_set(v43, v73);
        v3 = 1;
        goto LABEL_52;
      }
      v39 = jhl_nvget("wan_proto", v7);
      v40 = (const char *)nvram_get(v39);
      if ( !v40 || strcmp(v40, "pppoe") )
        goto LABEL_77;
LABEL_87:
      v41 = jhl_nvget("ppp_demand", v7);
      v42 = (const char *)nvram_get(v41);
      if ( !v42 || strcmp(v42, "2") )
      {
        if ( v73 )
        {
LABEL_77:
          v36 = jhl_nvget("wan_proto", v7);
          v37 = (const char *)nvram_get(v36);
          if ( !v37 || strcmp(v37, v73) )
          {
            v38 = jhl_nvget("wan_new_proto", v7);
            nvram_set(v38, v73);
          }
        }
        goto LABEL_80;
      }
      jhl_stop_wan(v7);
      if ( v73 )
        goto LABEL_95;
      v3 = 1;
LABEL_52:
      if ( v77 == ++v2 )
      {
LABEL_53:
        nvram_unset(v81 + 8180);
        return v3;
      }
    }
  }
  return 0;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81C8: using guessed type int __fastcall jhl_mr_set_dns(_DWORD);
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A81E8: using guessed type int jhl_ctreate_dmresolv(void);
// 6A83A4: using guessed type int __fastcall mr_set_by_jh_en(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A852C: using guessed type int __fastcall eval_nowait(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8744: using guessed type int __fastcall cJSON_GetIntvalue(_DWORD);
// 6A87E8: using guessed type int __fastcall jhl_stop_wan(_DWORD);
// 6A889C: using guessed type int __fastcall set_port_mode(_DWORD, _DWORD, _DWORD);
// 6A88F4: using guessed type int __fastcall restart_wan_auto_conn(_DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

