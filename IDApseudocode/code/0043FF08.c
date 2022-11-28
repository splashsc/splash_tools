int __fastcall get_wans_data(char *a1, int a2)
{
  int v3; // $s6
  int v4; // $fp
  int v5; // $s1
  int v6; // $v0
  const char *v7; // $s3
  int v8; // $v0
  const char *v9; // $v0
  bool v10; // dc
  _BOOL4 v11; // $v0
  int v12; // $v0
  const char *v13; // $v0
  int v14; // $v0
  const char *v15; // $v0
  int v16; // $v0
  const char *v17; // $v0
  int v18; // $v0
  const char *v19; // $s2
  char *v20; // $a0
  int v21; // $v0
  int v23; // $v0
  const char *v24; // $s2
  int v25; // $v0
  int v26; // $a1
  int v27; // $v0
  int v28; // $v0
  int v29; // $v0
  int v30; // $v0
  int v31; // $v0
  int v32; // $v0
  int v33; // $v0
  const char *v34; // $v0
  int v35; // $v0
  int v36; // $fp
  int v37; // $s2
  const char *v38; // $v0
  const char *v39; // $v1
  int v40; // $v0
  int v41; // $v0
  int v42; // $s2
  int v43; // $s3
  const char *v44; // $fp
  int v45; // $v0
  char *v46; // $v0
  int v47; // $v0
  const char *v48; // $v0
  int v49; // $v0
  int v50; // $s3
  int v51; // $s2
  int v52; // $v0
  int v53; // $s2
  int v54; // $fp
  int v55; // $v0
  int v56; // $fp
  int v57; // $s0
  int v58; // $v0
  int v59; // $v0
  const char *v60; // $v0
  int v61; // $v0
  int v62; // $v0
  const char *v63; // $v0
  int v64; // $v0
  int v65; // $v0
  int v66; // $v0
  char v67[128]; // [sp+38h] [-148h] BYREF
  char v68[128]; // [sp+B8h] [-C8h] BYREF
  char *v69; // [sp+138h] [-48h]
  const char *v70; // [sp+13Ch] [-44h]
  const char *v71; // [sp+140h] [-40h]
  int v72; // [sp+144h] [-3Ch]
  char *v73; // [sp+148h] [-38h]
  const char *v74; // [sp+14Ch] [-34h]
  const char *v75; // [sp+150h] [-30h]
  char *v76; // [sp+154h] [-2Ch]
  int v77; // [sp+158h] [-28h]
  const char *v78; // [sp+15Ch] [-24h]
  const char *v79; // [sp+160h] [-20h]
  const char *v80; // [sp+164h] [-1Ch]
  char *v81; // [sp+168h] [-18h]
  int v82; // [sp+16Ch] [-14h]
  const char *v83; // [sp+170h] [-10h]
  const char *v84; // [sp+174h] [-Ch]
  char *v85; // [sp+178h] [-8h]

  v3 = sq_file_get_max_wan();
  v4 = snprintf(a1, a2, (char *)&word_642A04);
  if ( v4 >= a2 )
    v4 = a2 - 1;
  if ( v3 > 0 && v4 < a2 - 99 )
  {
    v5 = 1;
    v69 = "a";
    v71 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
    v70 = "wan_down";
    v74 = "ipv6.wan_proto";
    v85 = "a";
    v84 = "0.0.0.0";
    while ( 1 )
    {
      v6 = jhl_nvget(v69 + 12484, v5 - 1);
      v7 = (const char *)nvram_get(v6);
      if ( v7 )
      {
        if ( !*v7 )
          break;
      }
      else
      {
        v7 = v71 - 1556;
        if ( !*(v71 - 1556) )
          break;
      }
      v8 = jhl_nvget(v70, v5 - 1);
      v9 = (const char *)nvram_get(v8);
      if ( v9 )
      {
        v10 = strcmp(v9, "1") == 0;
        v11 = v5 < v3;
        if ( v10 )
          goto LABEL_6;
      }
      v10 = jhl_iface_link_up_check(v7, v5 - 1) != 0;
      v11 = v5 < v3;
      if ( v10 )
        goto LABEL_6;
      v77 = jhl_get_wan_proto(v5 - 1);
      if ( v77 == 4
        && (v62 = jhl_nvget("ppp_demand_run", v5 - 1), (v63 = (const char *)nvram_get(v62)) != 0)
        && !strcmp(v63, "1") )
      {
        v72 = 0;
      }
      else
      {
        v72 = jhl_check_wanup(v5 - 1);
      }
      v12 = jhl_nvget(v74, v5 - 1);
      v13 = (const char *)nvram_get(v12);
      if ( v13 && !strcmp(v13, "staticv6") )
      {
        v23 = jhl_nvget("ipv6.wan_static_ip6", v5 - 1);
        v73 = (char *)nvram_get(v23);
        v24 = v71 - 1556;
        if ( !v73 )
          v73 = (char *)(v71 - 1556);
        v25 = jhl_nvget("ipv6.wan_static_gw6", v5 - 1);
        v75 = (const char *)nvram_get(v25);
        v83 = v24;
        if ( !v75 )
          v75 = v24;
      }
      else
      {
        v14 = jhl_nvget(v74, v5 - 1);
        v15 = (const char *)nvram_get(v14);
        if ( v15 && !strcmp(v15, "6in4") )
        {
          v61 = jhl_nvget("ipv6.wan_local_ip6", v5 - 1);
          v73 = (char *)nvram_get(v61);
          if ( !v73 )
            goto LABEL_21;
          v83 = v71 - 1556;
          v75 = v71 - 1556;
        }
        else
        {
          v16 = jhl_nvget(v74, v5 - 1);
          v17 = (const char *)nvram_get(v16);
          if ( !v17 || strcmp(v17, v85 + 12580) )
          {
LABEL_21:
            v83 = v71 - 1556;
            v75 = v71 - 1556;
            v73 = (char *)(v71 - 1556);
            if ( v72 )
              goto LABEL_36;
            goto LABEL_22;
          }
          v64 = jhl_nvget("ipv6.wan_get_ip", v5 - 1);
          v73 = (char *)nvram_get(v64);
          if ( !v73 )
            v73 = (char *)(v71 - 1556);
          v65 = jhl_nvget("ipv6.wan_get_gw", v5 - 1);
          v75 = (const char *)nvram_get(v65);
          if ( !v75 )
            v75 = v71 - 1556;
          v66 = jhl_nvget("ipv6.wan_get_dns", v5 - 1);
          v83 = (const char *)nvram_get(v66);
          if ( !v83 )
            v83 = v71 - 1556;
        }
      }
      if ( v72 )
      {
LABEL_36:
        v26 = v5 - 1;
        if ( v77 == 4 || v77 == 10 )
        {
          v30 = jhl_nvget("ppp_get_ip", v26);
          v78 = (const char *)nvram_get(v30);
          if ( !v78 )
            v78 = v84;
          v31 = jhl_nvget("ppp_gw", v5 - 1);
          v79 = (const char *)nvram_get(v31);
          if ( !v79 )
            v79 = v78;
          v80 = "255.255.255.255";
        }
        else
        {
          v27 = jhl_nvget("wan_ipaddr", v26);
          v78 = (const char *)nvram_get(v27);
          if ( !v78 )
            v78 = v84;
          v28 = jhl_nvget("wan_netmask", v5 - 1);
          v80 = (const char *)nvram_get(v28);
          if ( !v80 )
            v80 = v84;
          v29 = jhl_nvget("wan_gateway", v5 - 1);
          v79 = (const char *)nvram_get(v29);
          if ( !v79 )
            v79 = v84;
        }
        v32 = jhl_nvget("wan_proto", v5 - 1);
        v19 = (const char *)nvram_get(v32);
        if ( !v19 )
        {
          v76 = v67;
          memset(v67, 0, sizeof(v67));
          v19 = "disabled";
LABEL_53:
          asp_jhl_dns(v76, v5 - 1);
          goto LABEL_54;
        }
        goto LABEL_50;
      }
LABEL_22:
      v18 = jhl_nvget("wan_proto", v5 - 1);
      v19 = (const char *)nvram_get(v18);
      if ( !v19 )
      {
        v76 = v67;
        memset(v67, 0, sizeof(v67));
        v79 = v84;
        v19 = "disabled";
        v80 = v84;
        v78 = v84;
        goto LABEL_88;
      }
      v79 = v84;
      v80 = v84;
      v78 = v84;
LABEL_50:
      if ( !strncmp(v19, "3G", 2u) )
      {
        v19 = "4G";
      }
      else
      {
        v76 = "a";
        if ( !strncmp(v19, "4G", 2u) )
          v19 = v76 + 12444;
      }
      v76 = v67;
      memset(v67, 0, sizeof(v67));
      if ( v72 )
        goto LABEL_53;
LABEL_88:
      strcpy(v67, "[]");
LABEL_54:
      v81 = v68;
      jhl_link_uptime(v68, v5 - 1, v72);
      v33 = jhl_nvget("wan_name", v5 - 1);
      v34 = (const char *)nvram_get(v33);
      if ( !v34 )
        v34 = v71 - 1556;
      v82 = a2 - v4;
      v35 = snprintf(
              &a1[v4],
              a2 - v4,
              "{\"iface\":%d,\"wan_type\":\"%s\",\"wan_ifname\":\"%s\",\"wan_name\":\"%s\",",
              v5 - 1,
              v19,
              v7,
              v34);
      if ( v35 >= v82 )
        v35 = v82 - 1;
      v36 = v35 + v4;
      v37 = a2 - v36;
      if ( *v73 )
        v38 = "<br/>";
      else
        v38 = v71 - 1556;
      if ( *v75 )
        v39 = "<br/>";
      else
        v39 = v71 - 1556;
      v40 = snprintf(
              &a1[v36],
              a2 - v36,
              "\"wan_ipaddr\":\"%s%s%s\",\"wan_netmask\":\"%s%s\",\"wan_gw\":\"%s%s%s\",\"dns6\":[\"%s\"],",
              v78,
              v38,
              v73,
              v80,
              v38,
              v79,
              v39,
              v75,
              v83);
      if ( v40 >= v37 )
        v40 = v37 - 1;
      v42 = v40 + v36;
      v41 = jhl_nvget("wan_hwaddr", v5 - 1);
      v43 = a2 - v42;
      v44 = (const char *)nvram_get(v41);
      v73 = &a1[v42];
      if ( !v44 )
        v44 = "00:00:00:00:00:00";
      v73 = (char *)jhl_get_wanstatus(v5 - 1);
      v45 = jhl_nvget("wan_run_mtu", v5 - 1);
      v46 = (char *)nvram_get(v45);
      if ( !v46 )
        v46 = "0";
      v75 = (const char *)J_atoi(v46);
      v47 = jhl_nvget("wan_mem", v5 - 1);
      v48 = (const char *)nvram_get(v47);
      if ( !v48 )
        v48 = v71 - 1556;
      v49 = snprintf(
              &a1[v42],
              a2 - v42,
              "\"wan_mac\":\"%s\",\"wan_up\":%d,\"wan_state\":\"%s\",\"wan_time\":\"%s\",\"dns\":%s,\"wan_mtu\":%d,\"wan_mem\":\"%s\"",
              v44,
              v72,
              v73,
              v81,
              v76,
              v75,
              v48);
      if ( v49 >= v43 )
        v49 = v43 - 1;
      v50 = v49 + v42;
      if ( (unsigned int)(v77 - 10) >= 3 )
      {
        v59 = jhl_nvget("wan_group", v5 - 1);
        v51 = a2 - v50;
        v60 = (const char *)nvram_get(v59);
        if ( !v60 )
          v60 = v71 - 1556;
        v52 = snprintf(&a1[v50], a2 - v50, ",\"wan_group\":\"%s\"", v60);
        if ( v52 < v51 )
          goto LABEL_74;
LABEL_82:
        v52 = v51 - 1;
        goto LABEL_74;
      }
      v51 = a2 - v50;
      v52 = snprintf(&a1[v50], a2 - v50, ",\"wan_group\":\"\"");
      if ( v52 >= a2 - v50 )
        goto LABEL_82;
LABEL_74:
      v53 = v52 + v50;
      v54 = a2 - (v52 + v50);
      v55 = snprintf(&a1[v52 + v50], v54, ",\"n\":\"WAN%d\"", v5);
      if ( v55 >= v54 )
        v55 = v54 - 1;
      v56 = v53 + v55 + get_iface_increase_data(v5 - 1, &a1[v53 + v55], a2 - (v53 + v55));
      v57 = v56 + get_iface_pppoe_br_data(v5 - 1, &a1[v56], a2 - v56);
      v58 = snprintf(&a1[v57], a2 - v57, &byte_65078C);
      if ( v58 >= a2 - v57 )
        v58 = a2 - v57 - 1;
      v4 = v58 + v57;
      v11 = v5 < v3;
LABEL_6:
      if ( v11 )
      {
        ++v5;
        if ( v4 < a2 - 99 )
          continue;
      }
      break;
    }
  }
  v20 = &a1[v4];
  if ( v4 > 0 && *(v20 - 1) == 44 )
    v20 = &a1[--v4];
  *v20 = 0;
  v21 = snprintf(v20, a2 - v4, &byte_6445A0);
  if ( v21 >= a2 - v4 )
    v21 = a2 - v4 - 1;
  return v4 + v21;
}
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 65078C: using guessed type char byte_65078C;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A84E0: using guessed type int __fastcall jhl_get_wanstatus(_DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

