int __fastcall sub_450844(int a1)
{
  char *v1; // $v0
  int v2; // $s2
  char *v3; // $s4
  int v4; // $s1
  unsigned int v5; // $s0
  int v6; // $s5
  int v7; // $v0
  const char *v8; // $fp
  int v9; // $v0
  int v10; // $s7
  int v11; // $fp
  int v12; // $s0
  int v13; // $a0
  int v14; // $a1
  int v15; // $v0
  int v16; // $a2
  int result; // $v0
  int v18; // $v0
  const char *v19; // $v0
  int v20; // $v0
  int v21; // $v0
  int v22; // $v0
  int v23; // $v0
  int v24; // $v0
  int v25; // $s7
  int v26; // $v0
  int v27; // $s5
  const char *v28; // $a3
  int v29; // $v0
  int v30; // $s5
  int v31; // $v0
  int v32; // $s5
  int v33; // $v0
  int v34; // $s5
  const char *v35; // $a3
  int v36; // $v0
  int v37; // $v0
  int v38; // $s7
  const char *v39; // $v0
  int v40; // $s5
  int v41; // $v0
  int v42; // $v0
  int v43; // $s7
  const char *v44; // $v0
  int v45; // $s5
  int v46; // $v0
  int v47; // $v0
  int v48; // $s7
  const char *v49; // $v0
  int v50; // $s5
  int v51; // $v0
  int v52; // $v0
  int v53; // $s7
  const char *v54; // $v0
  int v55; // $s5
  int v56; // $v0
  int v57; // $v0
  int v58; // $s7
  char *v59; // $v0
  int v60; // $v0
  const char *v61; // $v0
  const char *v62; // $s7
  const char *v63; // $v0
  const char *v64; // $s7
  int v65; // $v0
  const char *v66; // $v0
  int v67; // $v0
  int v68; // $a3
  int v69; // $v0
  int v70; // $v0
  const char *v71; // $s7
  const char *v72; // $v0
  int v73; // $v0
  int v74; // $v0
  const char *v75; // $s7
  const char *v76; // $v0
  int v77; // $v0
  int v78; // $v0
  const char *v79; // $v0
  int v80; // $v0
  int v81; // $v0
  const char *v82; // [sp+10h] [-718h]
  char v83[1024]; // [sp+20h] [-708h] BYREF
  char v84[512]; // [sp+420h] [-308h] BYREF
  __int16 v85[64]; // [sp+620h] [-108h] BYREF
  const char *v86[2]; // [sp+6A0h] [-88h] BYREF
  const char *v87; // [sp+6A8h] [-80h]
  int v88; // [sp+6ACh] [-7Ch]
  char v89[36]; // [sp+6DCh] [-4Ch] BYREF
  const char *v90; // [sp+700h] [-28h]
  const char *v91; // [sp+704h] [-24h]
  char *v92; // [sp+708h] [-20h]
  const char *v93; // [sp+70Ch] [-1Ch]
  const char **v94; // [sp+710h] [-18h]
  char *v95; // [sp+714h] [-14h]
  int v96; // [sp+718h] [-10h]
  const char *v97; // [sp+71Ch] [-Ch]
  char *v98; // [sp+720h] [-8h]

  memset(v83, 0, sizeof(v83));
  v2 = sq_file_get_max_wan();
  _mem_malloc(0x200000, "ai_wan_info", 852);
  v3 = v1;
  if ( v1 )
  {
    *v1 = 91;
    v1[1] = 0;
    if ( v2 <= 0 )
    {
      v14 = 0x1FFFFF;
      v12 = 0x1FFFFF;
      v13 = 1;
      v6 = 1;
    }
    else
    {
      v90 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
      v92 = "a";
      v4 = 1;
      v91 = "wan_ipaddr";
      v5 = 0;
      v6 = 1;
      v93 = "0.0.0.0";
      do
      {
        v7 = jhl_nvget("wan_ifname", v5);
        v8 = (const char *)nvram_get(v7);
        if ( !v8 )
          v8 = v90 - 1556;
        v9 = jhl_get_wan_proto(v5);
        v10 = v9;
        if ( !*v8 )
          break;
        if ( (unsigned int)(v9 - 10) < 3
          || (v18 = jhl_nvget("wan_down", v5), (v19 = (const char *)nvram_get(v18)) != 0) && !strcmp(v19, "1")
          || jhl_iface_link_up_check(v8, v5) )
        {
          v11 = v4;
        }
        else
        {
          v20 = jhl_nvget(v91, v5);
          v95 = (char *)nvram_get(v20);
          if ( !v95 )
            v95 = (char *)v93;
          v21 = jhl_nvget(v92 + 6792, v5);
          v97 = (const char *)nvram_get(v21);
          if ( !v97 )
            v97 = v93;
          v22 = jhl_nvget("wan_gateway", v5);
          v96 = nvram_get(v22);
          if ( !v96 )
            v96 = (int)v93;
          if ( v10 == 4 )
          {
            if ( (v78 = jhl_nvget("ppp_demand_run", v5), (v79 = (const char *)nvram_get(v78)) != 0) && !strcmp(v79, "1")
              || (v94 = (const char **)jhl_check_wanup(v5)) == 0 )
            {
              v94 = 0;
              v96 = (int)v93;
              v97 = v93;
              v95 = (char *)v93;
            }
            else
            {
              v80 = jhl_nvget("ppp_get_ip", v5);
              v95 = (char *)nvram_get(v80);
              v81 = jhl_nvget("ppp_gw", v5);
              v96 = nvram_get(v81);
              if ( !v96 )
                v96 = (int)v95;
              v97 = "255.255.255.255";
            }
          }
          else
          {
            v94 = (const char **)jhl_check_wanup(v5);
            if ( !v94 )
            {
              v96 = (int)v93;
              v97 = v93;
              v95 = (char *)v93;
            }
          }
          v98 = v89;
          sprintf(v89, "WAN%d", v4);
          v82 = v98;
          v98 = (char *)(0x200000 - v6);
          v23 = snprintf(&v3[v6], 0x200000 - v6, "{\"iface\":%d,\"wan_name\":\"%s\",", v5, v82);
          v11 = v4;
          if ( v23 >= (int)v98 )
            v23 = 0x1FFFFF - v6;
          v25 = v23 + v6;
          v24 = jhl_link_uptime_s(v5, (int)v94);
          v98 = (char *)(0x200000 - v25);
          v26 = snprintf(&v3[v25], 0x200000 - v25, "\"connect_time\":\"%ld\",", v24);
          if ( v26 >= (int)v98 )
            v26 = 0x1FFFFF - v25;
          v27 = v26 + v25;
          v28 = v95;
          v95 = (char *)(0x200000 - (v26 + v25));
          v29 = snprintf(&v3[v26 + v25], (int)v95, "\"wan_ip\":\"%s\",", v28);
          if ( v29 >= (int)v95 )
            v29 = 0x1FFFFF - v27;
          v30 = v29 + v27;
          v95 = (char *)(0x200000 - v30);
          v31 = snprintf(&v3[v30], 0x200000 - v30, "\"wan_mask\":\"%s\",", v97);
          if ( v31 >= (int)v95 )
            v31 = 0x1FFFFF - v30;
          v32 = v31 + v30;
          v95 = (char *)(0x200000 - v32);
          v33 = snprintf(&v3[v32], 0x200000 - v32, "\"wan_gateway\":\"%s\",", (const char *)v96);
          if ( v33 >= (int)v95 )
            v33 = 0x1FFFFF - v32;
          v95 = (char *)v85;
          v34 = v33 + v32;
          memset(v85, 0, sizeof(v85));
          v35 = (const char *)v85;
          if ( v94 )
          {
            v94 = (const char **)v95;
            asp_jhl_dns(v95, v5);
            v35 = (const char *)v94;
          }
          else
          {
            v85[0] = 23899;
            v95[2] = 0;
          }
          v94 = (const char **)(0x200000 - v34);
          v36 = snprintf(&v3[v34], 0x200000 - v34, "\"dns\":%s,", v35);
          if ( v36 >= (int)v94 )
            v36 = 0x1FFFFF - v34;
          v38 = v36 + v34;
          v37 = jhl_nvget("mac_wan", v5);
          v39 = (const char *)nvram_get(v37);
          v40 = 0x200000 - v38;
          if ( !v39 )
            v39 = v90 - 1556;
          v41 = snprintf(&v3[v38], v40, "\"wan_mac\":\"%s\",", v39);
          if ( v41 >= v40 )
            v41 = 0x1FFFFF - v38;
          v43 = v41 + v38;
          v42 = jhl_nvget("wan_proto", v5);
          v44 = (const char *)nvram_get(v42);
          v45 = 0x200000 - v43;
          if ( !v44 )
            v44 = v90 - 1556;
          v46 = snprintf(&v3[v43], v45, "\"connect_ype\":\"%s\",", v44);
          if ( v46 >= v45 )
            v46 = 0x1FFFFF - v43;
          v48 = v46 + v43;
          v47 = jhl_nvget("ppp_username", v5);
          v49 = (const char *)nvram_get(v47);
          v50 = 0x200000 - v48;
          if ( !v49 )
            v49 = v90 - 1556;
          v51 = snprintf(&v3[v48], v50, "\"pppoe_username\":\"%s\",", v49);
          if ( v51 >= v50 )
            v51 = 0x1FFFFF - v48;
          v53 = v51 + v48;
          v52 = jhl_nvget("ppp_passwd", v5);
          v54 = (const char *)nvram_get(v52);
          v55 = 0x200000 - v53;
          if ( !v54 )
            v54 = v90 - 1556;
          v56 = snprintf(&v3[v53], v55, "\"pppoe_password\":\"%s\",", v54);
          if ( v56 >= v55 )
            v56 = 0x1FFFFF - v53;
          v58 = v56 + v53;
          v57 = jhl_nvget("mr_parm", v5);
          v59 = (char *)nvram_get(v57);
          if ( !v59 || !*v59 )
            v59 = " ";
          strlcpy(v84, v59, 512);
          v94 = v86;
          v60 = split_string(v84, 60, v86, 14);
          mr_parm_default(v60, v94, v5);
          v95 = (char *)(0x200000 - v58);
          v96 = 0x200000;
          v61 = (const char *)snprintf(&v3[v58], 0x200000 - v58, "\"zc_en\":\"%s\",", v86[0]);
          if ( (int)v61 >= (int)v95 )
            v61 = (const char *)(v96 - 1 - v58);
          v62 = &v61[v58];
          v95 = (char *)(0x200000 - (_DWORD)v62);
          v96 = 0x200000;
          v63 = (const char *)snprintf((char *)&v62[(_DWORD)v3], 0x200000 - (_DWORD)v62, "\"jh_en\":\"%s\",", v87);
          if ( (int)v63 >= (int)v95 )
            v63 = (const char *)(v96 - 1 - (_DWORD)v62);
          v64 = &v62[(_DWORD)v63];
          if ( v5 < 0x65 )
            v65 = jhl_nvget("qos_dk", v5);
          else
            v65 = jhl_vpnget("vpnqos_dk", v5 - 101);
          v66 = (const char *)nvram_get(v65);
          if ( !v66 || !*v66 )
            v66 = "on|hi|0|0|75|85|1000|2000|5|10|4|1500|8|16";
          strlcpy(v84, v66, 512);
          split_string(v84, 124, v94, 14);
          v94 = (const char **)J_atoi(v87);
          v67 = J_atoi(v88);
          v68 = (int)v94;
          v94 = (const char **)(0x200000 - (_DWORD)v64);
          v69 = snprintf((char *)&v64[(_DWORD)v3], 0x200000 - (_DWORD)v64, "\"qos_dk\":\"%lu|%lu\",", v68, v67);
          if ( v69 >= (int)v94 )
            v69 = 0x1FFFFF - (_DWORD)v64;
          v71 = &v64[v69];
          v70 = jhl_nvget("mtu_enable", v5);
          v72 = (const char *)nvram_get(v70);
          if ( !v72 )
            v72 = v90 - 1556;
          v73 = snprintf((char *)&v71[(_DWORD)v3], 0x200000 - (_DWORD)v71, "\"mtu_enable\":\"%s\",", v72);
          if ( v73 >= 0x200000 - (int)v71 )
            v73 = 0x1FFFFF - (_DWORD)v71;
          v75 = &v71[v73];
          v74 = jhl_nvget("wan_mtu", v5);
          v76 = (const char *)nvram_get(v74);
          if ( !v76 )
            v76 = v90 - 1556;
          v77 = snprintf((char *)&v75[(_DWORD)v3], 0x200000 - (_DWORD)v75, "\"mtu\":\"%s\"},", v76);
          if ( v77 >= 0x200000 - (int)v75 )
            v77 = 0x1FFFFF - (_DWORD)v75;
          v6 = (int)&v75[v77];
        }
        ++v5;
        ++v4;
      }
      while ( v11 < v2 );
      if ( v6 >= 4 )
        --v6;
      v12 = 0x200000 - v6;
      v13 = v6;
      v14 = 0x200000 - v6;
    }
    v15 = snprintf(&v3[v13], v14, &byte_6445A0);
    if ( v15 >= v12 )
      v16 = 0x1FFFFF - v6;
    else
      v16 = v15;
    result = httpd_cgi_ret(a1, v3, v6 + v16, 8);
  }
  else
  {
    strcpy(v83, "[]");
    result = httpd_cgi_ret(a1, v83, 2, 4);
  }
  return result;
}
// 4508DC: variable 'v1' is possibly undefined
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8270: using guessed type int __fastcall mr_parm_default(_DWORD, _DWORD, _DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

