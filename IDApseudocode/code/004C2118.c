int __fastcall sub_4C2118(int a1)
{
  char *v1; // $s5
  char *v2; // $s0
  char *v3; // $s2
  char *v4; // $s6
  int v5; // $a0
  int v6; // $s0
  int v7; // $v0
  int v8; // $v0
  _BOOL4 v9; // $s4
  int v10; // $s2
  int v11; // $v0
  int v12; // $a1
  char *v13; // $a1
  int v14; // $s3
  int v15; // $s1
  int v16; // $v0
  _DWORD *v17; // $s7
  const char *v18; // $s0
  char *v19; // $s1
  char *v20; // $v0
  char *v21; // $s0
  int v22; // $v0
  const char *v23; // $s0
  int v24; // $a2
  int v25; // $v0
  const char *v26; // $a1
  char *v27; // $s1
  char *v28; // $s1
  char *v29; // $v0
  const char *v30; // $s3
  const char *v31; // $s7
  int v32; // $s3
  int v33; // $v0
  int v34; // $v0
  char *v35; // $v0
  int v36; // $v0
  int v37; // $a1
  int (__fastcall *v38)(const char *, int); // $t9
  const char *v39; // $a0
  int v40; // $v0
  int v41; // $s0
  char *v42; // $v0
  unsigned int v43; // $v0
  bool v44; // dc
  unsigned int v45; // $s0
  char *v46; // $v1
  char *v47; // $s0
  int v48; // $v0
  int v49; // $v0
  int v50; // $v0
  int v51; // $v0
  int v52; // $v0
  int v53; // $s0
  char *v54; // $v1
  const char *v55; // $v0
  int v56; // $t0
  int v57; // $a3
  int v58; // $a2
  int v59; // $a1
  int v61; // $v0
  int v62; // $v0
  int v63; // $s1
  int v64; // $v0
  const char *v65; // $s1
  int v66; // $v0
  const char *v67; // $v0
  int v68; // $v0
  int v69; // $v0
  const char *v70; // $s3
  int v71; // $v0
  const char *v72; // $s1
  int v73; // $v0
  const char *v74; // $v0
  int v75; // $v0
  int v76; // $v0
  int v77; // $v0
  char *v78; // $v0
  const char *v79; // [sp+48h] [-490h] BYREF
  const char *v80; // [sp+4Ch] [-48Ch]
  const char *v81; // [sp+50h] [-488h]
  char *v82; // [sp+54h] [-484h]
  char *v83; // [sp+58h] [-480h]
  int v84; // [sp+5Ch] [-47Ch]
  char v85[200]; // [sp+248h] [-290h] BYREF
  const char *v86; // [sp+310h] [-1C8h] BYREF
  const char *v87; // [sp+314h] [-1C4h]
  const char *v88; // [sp+318h] [-1C0h]
  int *v89; // [sp+31Ch] [-1BCh]
  void *v90; // [sp+320h] [-1B8h]
  int v91; // [sp+324h] [-1B4h]
  const char *v92; // [sp+328h] [-1B0h]
  char *v93; // [sp+32Ch] [-1ACh]
  int v94; // [sp+330h] [-1A8h]
  int *v95; // [sp+334h] [-1A4h]
  char *v96; // [sp+338h] [-1A0h]
  char *v97; // [sp+33Ch] [-19Ch]
  char *v98; // [sp+340h] [-198h]
  int v99; // [sp+344h] [-194h]
  int v100; // [sp+348h] [-190h]
  int v101; // [sp+34Ch] [-18Ch]
  int v102; // [sp+350h] [-188h]
  int v103[16]; // [sp+354h] [-184h] BYREF
  char v104[64]; // [sp+394h] [-144h] BYREF
  int v105; // [sp+3D4h] [-104h] BYREF
  int v106; // [sp+3D8h] [-100h]
  int v107; // [sp+3DCh] [-FCh]
  int v108; // [sp+3E0h] [-F8h]
  int v109; // [sp+3E4h] [-F4h]
  int v110; // [sp+3E8h] [-F0h]
  int v111; // [sp+3ECh] [-ECh]
  int v112; // [sp+3F0h] [-E8h]
  char v113; // [sp+3F4h] [-E4h] BYREF
  int v114; // [sp+414h] [-C4h] BYREF
  int v115; // [sp+418h] [-C0h]
  int v116; // [sp+41Ch] [-BCh]
  int v117; // [sp+420h] [-B8h]
  int v118; // [sp+424h] [-B4h]
  int v119; // [sp+428h] [-B0h]
  char v120; // [sp+42Ch] [-ACh] BYREF
  char *v121; // [sp+440h] [-98h]
  const char *v122; // [sp+444h] [-94h]
  int v123; // [sp+448h] [-90h]
  const char *v124; // [sp+44Ch] [-8Ch]
  char *v125; // [sp+450h] [-88h]
  char *v126; // [sp+454h] [-84h]
  char *v127; // [sp+458h] [-80h]
  char *v128; // [sp+45Ch] [-7Ch]
  int v129; // [sp+460h] [-78h]
  unsigned int v130; // [sp+464h] [-74h]
  char *v131; // [sp+468h] [-70h]
  char *v132; // [sp+46Ch] [-6Ch]
  char *v133; // [sp+470h] [-68h]
  int v134; // [sp+474h] [-64h]
  const char **v135; // [sp+478h] [-60h]
  char *v136; // [sp+47Ch] [-5Ch]
  int *v137; // [sp+480h] [-58h]
  char *v138; // [sp+484h] [-54h]
  int v139; // [sp+488h] [-50h]
  char *v140; // [sp+48Ch] [-4Ch]
  char *v141; // [sp+490h] [-48h]
  char *v142; // [sp+494h] [-44h]
  const char *v143; // [sp+498h] [-40h]
  const char *v144; // [sp+49Ch] [-3Ch]
  const char *v145; // [sp+4A0h] [-38h]
  char *v146; // [sp+4A4h] [-34h]
  char *v147; // [sp+4A8h] [-30h]
  char *v148; // [sp+4ACh] [-2Ch]
  char *v149; // [sp+4B0h] [-28h]
  char *v150; // [sp+4B4h] [-24h]
  char *v151; // [sp+4B8h] [-20h]
  char *v152; // [sp+4BCh] [-1Ch]
  char *v153; // [sp+4C0h] [-18h]
  char *v154; // [sp+4C4h] [-14h]
  char *v155; // [sp+4C8h] [-10h]
  char *v156; // [sp+4CCh] [-Ch]
  const char *v157; // [sp+4D0h] [-8h]

  v1 = httpd_get_parm(a1, "mode");
  v2 = httpd_get_parm(a1, "onlywan");
  v3 = httpd_get_parm(a1, "onlywan_tcp");
  v4 = httpd_get_parm(a1, "ct_rule_name");
  v126 = v104;
  v134 = httpd_get_json_parm(a1, (int)"wans");
  v114 = 0;
  v115 = 0;
  v116 = 0;
  v117 = 0;
  v118 = 0;
  v119 = 0;
  v105 = 0;
  v106 = 0;
  v107 = 0;
  v108 = 0;
  v109 = 0;
  v110 = 0;
  v111 = 0;
  v112 = 0;
  v137 = v103;
  memset(v104, 0, sizeof(v104));
  memset(v103, 0, sizeof(v103));
  if ( v4 )
    nvram_set("mr_ct_rule_name", v4);
  if ( v1 && (!strcmp(v1, "hi") || !strcmp(v1, "ct")) )
    nvram_set("mr_mode", v1);
  v124 = "wys";
  v79 = "wys";
  v80 = "mr";
  v81 = "mode";
  v122 = "mr";
  v82 = (char *)jhl_nv_get_def("mr_mode");
  v135 = &v79;
  v83 = (char *)jhl_nv_get_def("mr_ct_rule_name");
  v84 = 0;
  eval(&v79, 0, 0, 0);
  if ( v2 && (!strcmp(v2, "1") || !strcmp(v2, "0")) )
  {
    if ( !v3 )
      v3 = (char *)jhl_nv_get_def("mr_onlywan_tcp");
    goto LABEL_10;
  }
  if ( !v3 )
    goto LABEL_11;
  if ( !strcmp(v3, "1") )
  {
    if ( v2 )
      goto LABEL_10;
  }
  else
  {
    if ( strcmp(v3, "0") )
      goto LABEL_11;
    if ( v2 )
      goto LABEL_10;
  }
  v2 = (char *)jhl_nv_get_def("mr_onlywan");
LABEL_10:
  nvram_set("mr_onlywan_tcp", v3);
  nvram_set("mr_onlywan", v2);
  v79 = v124;
  v80 = v122;
  v81 = "onlywan";
  v82 = v2;
  v83 = v3;
  v84 = 0;
  eval(v135, 0, 0, 0);
LABEL_11:
  if ( v134 )
  {
    v139 = cJSON_GetArraySize(v134);
    if ( v139 > 0 )
    {
      v125 = "a";
      v142 = "a";
      v123 = 0;
      v146 = "1\"";
      v147 = "a";
      v138 = "a";
      v140 = "1\"";
      v149 = &v113;
      v141 = "a";
      v150 = &v120;
      v148 = "1\"";
      v157 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
      v131 = v85;
      v143 = "jh";
      v144 = "val";
      v145 = "zc";
      v121 = "qz";
      v127 = "zc_en";
      v133 = "tm";
      while ( 1 )
      {
        v6 = cJSON_GetArrayItem(v134, v123);
        v7 = cJSON_GetObjectItem(v6, v142 + 13148);
        v8 = cJSON_GetIntvalue(v7);
        v9 = v8 < 101;
        v10 = v8;
        if ( v8 >= 101 )
        {
          v63 = v8 - 101;
          jhl_vpnclient_route_id(v8 - 101, v150);
          v64 = jhl_vpnget(v148 + 1368, v63);
          v13 = (char *)nvram_get(v64);
          v130 = -10;
          v129 = 0;
          if ( !v13 )
            v13 = (char *)(v157 - 1556);
        }
        else
        {
          jhl_wan_route_id(v8, v150);
          v11 = jhl_nvget("mr_parm", v10);
          v12 = nvram_get(v11);
          if ( !v12 )
            v12 = (int)(v157 - 1556);
          v128 = (char *)v12;
          v129 = jhl_get_wan_proto(v10);
          v13 = v128;
          v130 = v129 - 10;
        }
        if ( !*v13 )
          v13 = " ";
        v14 = (int)v135;
        strlcpy(v135, v13, 512);
        v15 = (int)v137;
        v16 = split_string(v14, 60, v137, 14);
        mr_parm_default(v16, v15, v10);
        v17 = *(_DWORD **)(v6 + 8);
        if ( v17 )
        {
          v156 = "1\"";
          v128 = 0;
          v132 = "times";
          v136 = "act";
          v151 = "su";
          v152 = "gw_en";
          v153 = "srv_en";
          v154 = "srv_ip";
          v155 = "gw_ip";
          while ( 1 )
          {
            v18 = (const char *)v17[8];
            v19 = (char *)v17[4];
            v17 = (_DWORD *)*v17;
            if ( !strcmp(v18, "jh_en") )
            {
              v103[0] = (int)v19;
LABEL_24:
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v121) )
            {
              if ( !*v19 )
                goto LABEL_24;
              v103[1] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v127) )
            {
              v103[2] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v133) )
            {
              v103[3] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v132) )
            {
              v103[4] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v136) )
            {
              v103[5] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v151) )
            {
              v103[6] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v152) )
            {
              v103[7] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v153) )
            {
              v103[8] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v154) )
            {
              v103[9] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v155) )
            {
              v103[10] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, v156 + 1556) )
            {
              v103[11] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, "host") )
            {
              v103[12] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else if ( !strcmp(v18, "ct") )
            {
              v103[13] = (int)v19;
              if ( !v17 )
                goto LABEL_25;
            }
            else
            {
              if ( strcmp(v18, "flow") )
                goto LABEL_24;
              v128 = v19;
              if ( !v17 )
                goto LABEL_25;
            }
          }
        }
        v128 = 0;
LABEL_25:
        if ( sq_file_get_state() == 1 )
        {
          v20 = (char *)v103[2];
        }
        else
        {
          v20 = "0";
          v103[2] = (int)"0";
        }
        v21 = v131;
        sprintf(
          v131,
          v146 + 1572,
          v103[0],
          v103[1],
          v20,
          v103[3],
          v103[4],
          v103[5],
          v103[6],
          v103[7],
          v103[8],
          v103[9],
          v103[10],
          v103[11],
          v103[12],
          v103[13]);
        if ( v9 )
        {
          v22 = jhl_nvget("mr_parm", v10);
          nvram_set(v22, v21);
          if ( J_atoi(v103[1]) )
          {
            v23 = (const char *)v103[1];
            v114 = 0;
            v115 = 0;
            v116 = 0;
            v117 = 0;
            v118 = 0;
            v119 = 0;
          }
          else
          {
            v114 = 0;
            v115 = 0;
            v116 = 0;
            v117 = 0;
            v118 = 0;
            v119 = 0;
            v23 = "100000";
          }
          v24 = v10 + 1;
        }
        else
        {
          v75 = jhl_vpnget(v148 + 1368, v10 - 101);
          nvram_set(v75, v131);
          if ( J_atoi(v103[1]) )
          {
            v23 = (const char *)v103[1];
            v114 = 0;
            v115 = 0;
            v116 = 0;
            v117 = 0;
            v118 = 0;
            v119 = 0;
          }
          else
          {
            v114 = 0;
            v115 = 0;
            v116 = 0;
            v117 = 0;
            v118 = 0;
            v119 = 0;
            v23 = "100000";
          }
          v24 = v10;
        }
        sprintf((char *)&v114, v147 + 24872, v24);
        v105 = 0;
        v106 = 0;
        v107 = 0;
        v108 = 0;
        v109 = 0;
        v110 = 0;
        v111 = 0;
        v112 = 0;
        if ( strcmp((const char *)v103[7], v125 + 9340) )
          break;
        if ( StrToIp(v103[10]) )
        {
          v26 = (const char *)v103[10];
        }
        else if ( v9 )
        {
          v26 = (const char *)jhl_get_wangw(v10);
        }
        else
        {
          v25 = jhl_vpnget("vpn_peerip", v10);
          v26 = (const char *)nvram_get(v25);
          if ( !v26 )
            v26 = "0.0.0.0";
        }
        strlcpy(&v105, v26, 32);
        if ( v9 )
          goto LABEL_84;
LABEL_37:
        v27 = v126;
        memset(v126, 0, 0x40u);
        if ( !strcmp((const char *)v103[8], v125 + 9340) )
        {
          snprintf(v27, 64, "%s", (const char *)v103[9]);
          if ( v130 >= 3 )
            goto LABEL_39;
        }
        else
        {
          *(_WORD *)v126 = 48;
          if ( v130 >= 3 )
          {
LABEL_39:
            v28 = "0";
            if ( v9 )
              goto LABEL_77;
            goto LABEL_40;
          }
        }
        v28 = v125 + 9340;
        if ( v9 )
        {
LABEL_77:
          v61 = jhl_nvget("wan_proto", v10);
          v30 = (const char *)nvram_get(v61);
          if ( !v30 )
            v30 = v157 - 1556;
          v62 = jhl_nvget("ppp_demand_run", v10);
          v29 = (char *)nvram_get(v62);
          if ( !v29 )
            v29 = (char *)(v157 - 1556);
          goto LABEL_41;
        }
LABEL_40:
        v29 = "0";
        v30 = "vpn";
LABEL_41:
        v31 = v124;
        v87 = v122;
        v90 = (void *)v103[0];
        v93 = v29;
        v88 = v143;
        v91 = v103[12];
        v92 = v30;
        v86 = v124;
        v89 = &v114;
        v94 = v103[13];
        v95 = 0;
        eval(&v86, 0, 0, 0);
        v88 = v144;
        v86 = v31;
        v87 = v122;
        v89 = &v114;
        v90 = (void *)v23;
        v91 = v103[11];
        v92 = 0;
        eval(&v86, 0, 0, 0);
        v32 = (int)v128;
        if ( v128 )
        {
          if ( v9 )
          {
            v33 = jhl_nvget("wan_flow_all", v10);
            nvram_set(v33, v32);
            v34 = jhl_nvget("wan_flow_all", v10);
            v35 = (char *)nvram_get(v34);
            if ( !v35 )
              v35 = "0";
            v36 = J_atoi(v35);
            v37 = v10;
            v38 = (int (__fastcall *)(const char *, int))&jhl_nvget;
            v39 = "wan_flow_use";
          }
          else
          {
            v76 = jhl_vpnget("vpn_flow_all", v10 - 101);
            nvram_set(v76, v128);
            v77 = jhl_vpnget("vpn_flow_all", v10 - 101);
            v78 = (char *)nvram_get(v77);
            if ( !v78 )
              v78 = "0";
            v36 = J_atoi(v78);
            v37 = v10 - 101;
            v38 = (int (__fastcall *)(const char *, int))&jhl_vpnget;
            v39 = "vpn_flow_use";
          }
          v41 = v36;
          v40 = v38(v39, v37);
          v42 = (char *)nvram_get(v40);
          if ( !v42 )
            v42 = "0";
          v43 = J_atoi(v42);
          v44 = v41 == 0;
          v45 = v41 << 10;
          if ( v44 || v43 < v45 )
            v46 = "0";
          else
            v46 = v125 + 9340;
          v86 = v124;
          v87 = v122;
          v88 = "flow";
          v89 = &v114;
          v90 = v46;
          v91 = 0;
          eval(&v86, 0, 0, 0);
        }
        v47 = v149;
        snprintf(v149, 32, v140 - 15580, v129);
        v86 = v124;
        v87 = v122;
        v89 = &v114;
        v88 = v145;
        v95 = &v105;
        v90 = (void *)v103[2];
        v97 = v28;
        v91 = v103[5];
        v98 = v47;
        v92 = (const char *)v103[3];
        v93 = (char *)v103[4];
        v94 = v103[6];
        v96 = v126;
        v48 = jhl_nvget(v138 + 12484, v10);
        v49 = nvram_get(v48);
        if ( !v49 )
          v49 = (int)(v157 - 1556);
        v99 = v49;
        v50 = jhl_nvget(v141 + 6804, v10);
        v51 = nvram_get(v50);
        if ( !v51 )
          v51 = (int)(v157 - 1556);
        v100 = v51;
        v52 = jhl_get_wanip(v10);
        ++v123;
        v101 = v52;
        v102 = 0;
        v53 = v123;
        eval(&v86, 0, 0, 0);
        if ( v139 == v53 )
          goto LABEL_57;
      }
      LOWORD(v105) = 48;
      if ( !v9 )
        goto LABEL_37;
LABEL_84:
      if ( StrToIp(v103[10]) )
        v65 = (const char *)v103[10];
      else
        v65 = (const char *)jhl_get_wangw(v10);
      v66 = jhl_nvget("wan_pinggw", v10);
      v67 = (const char *)nvram_get(v66);
      if ( !v67 || !v65 || strcmp(v67, v65) )
      {
        v68 = jhl_nvget("wan_pinggw", v10);
        nvram_set(v68, v65);
        if ( nvram_match_def("ping_wan_gw", v125 + 9340) )
        {
          ping_wan_gw_stop(v10);
          v69 = jhl_nvget(v138 + 12484, v10);
          v70 = (const char *)nvram_get(v69);
          if ( !v70 )
            v70 = v157 - 1556;
          if ( *v70 )
          {
            v71 = jhl_nvget("wan_name", v10);
            v72 = (const char *)nvram_get(v71);
            if ( !v72 )
              v72 = v157 - 1556;
            if ( *v72 )
            {
              v73 = jhl_nvget("wan_down", v10);
              v74 = (const char *)nvram_get(v73);
              if ( (!v74 || strcmp(v74, v125 + 9340)) && !jhl_iface_link_up_check(v70, v10) && jhl_check_wanup(v10) )
                ping_wan_gw_start(v10, v72);
            }
          }
        }
      }
      goto LABEL_37;
    }
  }
  v131 = v85;
LABEL_57:
  jhl_parm_commit(v5);
  v54 = v131;
  v55 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v56 = *(_DWORD *)v55;
    v57 = *((_DWORD *)v55 + 1);
    v58 = *((_DWORD *)v55 + 2);
    v59 = *((_DWORD *)v55 + 3);
    v55 += 16;
    *(_DWORD *)v54 = v56;
    *((_DWORD *)v54 + 1) = v57;
    *((_DWORD *)v54 + 2) = v58;
    *((_DWORD *)v54 + 3) = v59;
    v54 += 16;
  }
  while ( v55 != "}" );
  *(_WORD *)v54 = *(_WORD *)v55;
  return httpd_cgi_ret(a1, v131, 33, 4);
}
// 4C2CBC: variable 'v5' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8270: using guessed type int __fastcall mr_parm_default(_DWORD, _DWORD, _DWORD);
// 6A82F4: using guessed type int __fastcall jhl_iface_link_up_check(_DWORD, _DWORD);
// 6A8388: using guessed type int __fastcall ping_wan_gw_start(_DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8460: using guessed type int __fastcall jhl_get_wan_proto(_DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A8538: using guessed type int __fastcall jhl_check_wanup(_DWORD);
// 6A862C: using guessed type int __fastcall StrToIp(_DWORD);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8700: using guessed type int sq_file_get_state(void);
// 6A8710: using guessed type int __fastcall jhl_get_wanip(_DWORD);
// 6A8744: using guessed type int __fastcall cJSON_GetIntvalue(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8864: using guessed type int __fastcall jhl_vpnclient_route_id(_DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8920: using guessed type int __fastcall jhl_get_wangw(_DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);
// 6A89A4: using guessed type int __fastcall ping_wan_gw_stop(_DWORD);
// 6A89B0: using guessed type int __fastcall jhl_wan_route_id(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

