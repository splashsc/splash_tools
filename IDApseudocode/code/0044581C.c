int __fastcall sub_44581C(int a1)
{
  char **v1; // $v0
  char *v2; // $v1
  char *v3; // $t0
  char *v4; // $a3
  char *v5; // $a2
  char *v6; // $a1
  char *v7; // $a2
  char *v8; // $a1
  char *v9; // $v0
  const char *v10; // $fp
  int v11; // $v0
  int v12; // $v0
  int v13; // $s0
  int v14; // $s6
  char *v15; // $s0
  const char *v16; // $v0
  const char *v17; // $v0
  const char *v18; // $v0
  int v19; // $a0
  char *v20; // $v1
  const char *v21; // $v0
  int v22; // $t0
  int v23; // $a3
  int v24; // $a2
  int v25; // $a1
  unsigned int v26; // $a2
  int v28; // $s1
  int v29; // $s2
  int v30; // $s0
  int v31; // $s7
  int v32; // $s6
  int v33; // $fp
  int v34; // $s5
  int v35; // $s3
  int v36; // $s4
  int v37; // $v0
  int v38; // $a0
  int v39; // $v0
  int v40; // $s0
  unsigned int v41; // $v0
  const char *v42; // $v0
  const char *v43; // $v0
  int v44; // $s1
  char *v45; // $s4
  int v46; // $s0
  int v47; // $v0
  int v48; // $s2
  _DWORD *v49; // $s3
  int v50; // $s4
  const char *v51; // $s0
  char *v52; // $s1
  int v53; // $v0
  const char *v54; // $v0
  int v55; // $v0
  int v56; // $v0
  const char *v57; // $v0
  int v58; // $v0
  unsigned int v59; // $s0
  char *v60; // $v0
  unsigned int v61; // $v0
  char *v62; // $s3
  char *v63; // $s7
  char *v64; // $s0
  int v65; // $v0
  int v66; // $v0
  unsigned int v67; // $v0
  unsigned int v68; // $v0
  unsigned int v70; // $s1
  unsigned int v71; // $v0
  int v72; // $v0
  const char *v73; // $v0
  int v74; // $v0
  int v75; // $v0
  const char *v76; // $v0
  int v77; // $v0
  int v78; // $v0
  const char *v79; // $v0
  int v80; // $v0
  int v81; // $v0
  const char *v82; // $v0
  int v83; // $v0
  int v84; // $v0
  const char *v85; // $v0
  int v86; // $v0
  int v87; // $v0
  const char *v88; // $v0
  int v89; // $v0
  int v90; // $v0
  const char *v91; // $v0
  char *v92; // $v0
  char *j; // $v0
  int v94; // $v0
  int v95; // $v0
  const char *v96; // $v0
  int v97; // $v0
  int v98; // $v0
  const char *v99; // $v0
  char *v100; // $v0
  char *i; // $v0
  int v102; // $v0
  int v103; // $v0
  const char *v104; // $v0
  int v105; // $v0
  int v106; // $v0
  const char *v107; // $v0
  int v108; // $v0
  int v109; // $v0
  const char *v110; // $v0
  int v111; // $v0
  int v112; // $v0
  const char *v113; // $v0
  int v114; // $v0
  int v115; // $v0
  const char *v116; // $v0
  int v117; // $v0
  int v118; // $v0
  const char *v119; // $v0
  int v120; // $v0
  int v121; // $v0
  const char *v122; // $v0
  int v123; // $v0
  int v124; // $v0
  const char *v125; // $v0
  int v126; // $v0
  int v127; // $v0
  const char *v128; // $v0
  int v129; // $v0
  int v130; // $v0
  const char *v131; // $v0
  int v132; // $v0
  int v133; // $v0
  const char *v134; // $v0
  int v135; // $v0
  const char *v136; // $s2
  const char *v137; // $v0
  int v138; // $a1
  const char *v139; // $a2
  const char *v140; // $v0
  char v141[10240]; // [sp+50h] [-4920h] BYREF
  char v142[8192]; // [sp+2850h] [-2120h] BYREF
  char v143; // [sp+4850h] [-120h] BYREF
  char v144; // [sp+4858h] [-118h] BYREF
  char v145; // [sp+48ACh] [-C4h] BYREF
  char *v146; // [sp+48B0h] [-C0h]
  char *v147; // [sp+48B4h] [-BCh]
  char *v148; // [sp+48B8h] [-B8h]
  char *v149; // [sp+48BCh] [-B4h]
  char *v150; // [sp+48C0h] [-B0h]
  char *v151; // [sp+48C4h] [-ACh]
  char *v152; // [sp+48C8h] [-A8h]
  char *v153; // [sp+48CCh] [-A4h]
  char *v154; // [sp+48D0h] [-A0h]
  char *v155; // [sp+48D4h] [-9Ch]
  char *v156; // [sp+48D8h] [-98h]
  char *v157; // [sp+48DCh] [-94h]
  char *v158; // [sp+48E0h] [-90h]
  char *v159; // [sp+48E4h] [-8Ch]
  char *v160; // [sp+48E8h] [-88h]
  char *v161; // [sp+48ECh] [-84h]
  char *v162; // [sp+48F0h] [-80h]
  char *v163; // [sp+48F4h] [-7Ch]
  char *v164; // [sp+48F8h] [-78h]
  char *v165; // [sp+48FCh] [-74h]
  char *v166; // [sp+4900h] [-70h]
  const char *v167; // [sp+4904h] [-6Ch]
  const char *v168; // [sp+4908h] [-68h]
  const char *v169; // [sp+490Ch] [-64h]
  char *v170; // [sp+4910h] [-60h]
  char *format; // [sp+4914h] [-5Ch]
  const char *v172; // [sp+4918h] [-58h]
  char *v173; // [sp+491Ch] [-54h]
  int v174; // [sp+4920h] [-50h]
  int v175; // [sp+4924h] [-4Ch]
  int v176; // [sp+4928h] [-48h]
  int v177; // [sp+492Ch] [-44h]
  char *v178; // [sp+4930h] [-40h]
  const char *v179; // [sp+4934h] [-3Ch]
  int v180; // [sp+4938h] [-38h]
  char *v181; // [sp+493Ch] [-34h]
  char *v182; // [sp+4940h] [-30h]
  char *v183; // [sp+4944h] [-2Ch]
  char *v184; // [sp+4948h] [-28h]
  char *v185; // [sp+494Ch] [-24h]
  char *v186; // [sp+4950h] [-20h]
  char *v187; // [sp+4954h] [-1Ch]
  char *v188; // [sp+4958h] [-18h]
  int v189; // [sp+495Ch] [-14h]
  int v190; // [sp+4960h] [-10h]
  char *v191; // [sp+4964h] [-Ch]
  char *v192; // [sp+4968h] [-8h]

  v1 = off_66D294;
  v2 = &v143;
  do
  {
    v3 = *v1;
    v4 = v1[1];
    v5 = v1[2];
    v6 = v1[3];
    v1 += 4;
    *(_DWORD *)v2 = v3;
    *((_DWORD *)v2 + 1) = v4;
    *((_DWORD *)v2 + 2) = v5;
    *((_DWORD *)v2 + 3) = v6;
    v2 += 16;
  }
  while ( v1 != off_66D2E4 );
  v7 = *v1;
  v8 = v1[1];
  v9 = v1[2];
  v10 = v142;
  *(_DWORD *)v2 = v7;
  *((_DWORD *)v2 + 1) = v8;
  *((_DWORD *)v2 + 2) = v9;
  memset(v142, 0, sizeof(v142));
  v173 = "a";
  v11 = httpd_get_json_parm(a1, (int)"lans");
  v181 = "a";
  v176 = v11;
  v12 = httpd_get_json_parm(a1, (int)"dual_lan_list");
  v154 = "a";
  v190 = v12;
  v13 = v12;
  format = httpd_get_parm(a1, "dual_lan_mode");
  v146 = httpd_get_parm(a1, "dhcp_bind_ipmac_en");
  _lan_vlan_asp(a1);
  v14 = 0;
  if ( v13 )
  {
    if ( !cJSON_IsArray(v13) )
      goto LABEL_5;
    v172 = (const char *)cJSON_GetArraySize(v190);
    if ( (int)v172 > 0 )
    {
      v159 = "a";
      v158 = "a";
      v161 = "a";
      v157 = "a";
      v169 = "dhcp_end";
      v156 = "a";
      v160 = "a";
      v162 = "a";
      v163 = "a";
      v164 = "a";
      v28 = 0;
      v165 = "a";
      v29 = 0;
      v155 = "a";
      v167 = "dhcp_dns0";
      v166 = "a";
      v168 = "dhcp_dns1";
      format = "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<";
      v170 = v142;
      while ( 1 )
      {
        v30 = cJSON_GetArrayItem(v190, v29);
        v31 = cJSON_GetObjectItem(v30, v167);
        v153 = (char *)cJSON_GetObjectItem(v30, v168);
        v152 = (char *)cJSON_GetObjectItem(v30, v169);
        v151 = (char *)cJSON_GetObjectItem(v30, v159 + 14932);
        v32 = cJSON_GetObjectItem(v30, v158 + 14944);
        v150 = (char *)cJSON_GetObjectItem(v30, v161 + 14960);
        v33 = cJSON_GetObjectItem(v30, v157 + 14980);
        v34 = cJSON_GetObjectItem(v30, v156 + 14996);
        v149 = (char *)cJSON_GetObjectItem(v30, v160 + 15012);
        v35 = cJSON_GetObjectItem(v30, v162 + 15028);
        v36 = cJSON_GetObjectItem(v30, v163 + 15044);
        v148 = (char *)cJSON_GetObjectItem(v30, v164 + 15060);
        v147 = (char *)cJSON_GetObjectItem(v30, v165 + 15072);
        v37 = cJSON_GetObjectItem(v30, v155 + 15080);
        v38 = v30;
        v40 = v37;
        v39 = cJSON_GetObjectItem(v38, v166 + 15092);
        if ( !v31 )
          break;
        if ( !v153 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643A30;
          goto LABEL_265;
        }
        if ( !v152 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643A40;
          goto LABEL_265;
        }
        if ( !v151 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643A50;
          goto LABEL_265;
        }
        if ( !v32 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643A5C;
          goto LABEL_265;
        }
        if ( !v150 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643A6C;
          goto LABEL_265;
        }
        if ( !v33 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643A80;
          goto LABEL_265;
        }
        if ( !v34 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643A90;
          goto LABEL_265;
        }
        if ( !v149 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643AA0;
          goto LABEL_265;
        }
        if ( !v35 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643AB0;
          goto LABEL_265;
        }
        if ( !v36 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643AC0;
          goto LABEL_265;
        }
        if ( !v148 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643AD0;
          goto LABEL_265;
        }
        if ( !v147 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = "not mem";
          goto LABEL_265;
        }
        if ( !v40 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = (const char *)&unk_643AE4;
          goto LABEL_265;
        }
        if ( !v39 )
        {
          v138 = *(unsigned __int8 *)(a1 + 210102);
          v139 = "not vlanid";
          goto LABEL_265;
        }
        v41 = snprintf(
                &v170[v28],
                0x2000 - v28,
                format,
                *(_DWORD *)(v39 + 16),
                *(_DWORD *)(v35 + 16),
                *(_DWORD *)(v36 + 16),
                *(_DWORD *)(v34 + 16),
                *(_DWORD *)(v32 + 16),
                *(_DWORD *)(v33 + 16),
                *((_DWORD *)v152 + 4),
                *((_DWORD *)v151 + 4),
                *((_DWORD *)v149 + 4),
                *(_DWORD *)(v31 + 16),
                *((_DWORD *)v153 + 4),
                *((_DWORD *)v148 + 4),
                *(_DWORD *)(v40 + 16),
                *((_DWORD *)v147 + 4),
                *((_DWORD *)v150 + 4));
        if ( v41 >= 0x2000 - v28 )
          v41 = 0x1FFF - v28;
        v28 += v41;
        if ( v172 == (const char *)++v29 )
        {
          v10 = v170;
          format = "1";
          goto LABEL_51;
        }
      }
      v138 = *(unsigned __int8 *)(a1 + 210102);
      v139 = (const char *)&unk_643A20;
LABEL_265:
      v140 = (const char *)_GET_LANG_TEXT(12, v138, v139);
      v26 = snprintf(v141, 10240, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v140);
      if ( v26 >= 0x2800 )
        v26 = 10239;
      return httpd_cgi_ret(a1, v141, v26, 4);
    }
LABEL_51:
    v42 = (const char *)nvram_get(v173 + 13664);
    if ( v42 && !strcmp(v42, v10) )
    {
LABEL_5:
      v14 = 0;
    }
    else
    {
      nvram_set(v173 + 13664, v10);
      v14 = 1;
    }
  }
  v15 = v146;
  if ( !v146 || (v16 = (const char *)nvram_get(v154 + 7972)) != 0 && !strcmp(v16, v15) )
  {
    v175 = 0;
  }
  else
  {
    nvram_set(v154 + 7972, v146);
    v175 = 1;
    v14 = 1;
  }
  v191 = "a";
  if ( jhl_web_save_parm(a1, "duolanlist", 0) || jhl_web_save_parm(a1, "duolan_enble", 0) )
  {
    v189 = 1;
    v14 = 1;
  }
  else
  {
    v189 = 0;
  }
  if ( !v176 || !cJSON_IsArray(v176) || (v182 = (char *)cJSON_GetArraySize(v176), (int)v182 <= 0) )
  {
    v180 = 0;
    v174 = 0;
    goto LABEL_15;
  }
  v187 = "a";
  v149 = "a";
  v188 = "a";
  v172 = "dhcp_filter";
  v184 = "a";
  v183 = "a";
  v146 = "lan_ipaddr";
  v185 = "1\"";
  v147 = "lan_netmask";
  v192 = "a";
  v186 = &v144;
  v180 = 0;
  v174 = 0;
  v170 = 0;
  v173 = 0;
  v148 = "mac_lan";
  v45 = &v145;
  do
  {
    v46 = cJSON_GetArrayItem(v176, v173);
    v47 = cJSON_GetObjectItem(v46, v187 + 13148);
    v48 = cJSON_GetIntvalue(v47);
    v177 = cJSON_GetObjectItem(v46, v188 + 14348);
    if ( !cJSON_GetObjectItem(v46, v149 + 7992) )
    {
      v133 = jhl_langet(v172, v48);
      v134 = (const char *)nvram_get(v133);
      if ( !v134 || strcmp(v134, v192 + 14076) )
      {
        v135 = jhl_langet(v149 + 7992, v48);
        nvram_set(v135, "0");
        if ( !v48 )
          v175 = 1;
        v14 = 1;
      }
    }
    v49 = *(_DWORD **)(v46 + 8);
    if ( v49 )
    {
      v158 = "a";
      v161 = "a";
      v165 = "a";
      v150 = "a";
      v162 = "a";
      v160 = "a";
      v151 = "a";
      v163 = "a";
      v152 = "a";
      v156 = "a";
      v159 = "a";
      v153 = "a";
      v154 = "a";
      v157 = "a";
      v167 = "dhcp_lease";
      v178 = v45;
      v50 = v175;
      v179 = v10;
      v155 = "a";
      v164 = "a";
      v166 = "dhcp_type";
      v168 = "dhcp_start";
      v169 = "dhcp_end";
      while ( 1 )
      {
        v51 = (const char *)v49[8];
        v52 = (char *)v49[4];
        v49 = (_DWORD *)*v49;
        if ( strcmp(v51, v146)
          || (v75 = jhl_langet(v146, v48), (v76 = (const char *)nvram_get(v75)) != 0) && v52 && !strcmp(v76, v52) )
        {
          if ( strcmp(v51, v147) )
            goto LABEL_70;
        }
        else
        {
          v77 = jhl_langet(v146, v48);
          nvram_set(v77, v52);
          if ( !v48 )
          {
            v180 = 1;
            v174 = 1;
          }
          v14 = 1;
          if ( strcmp(v51, v147) )
          {
LABEL_70:
            if ( strcmp(v51, v148) )
              goto LABEL_71;
LABEL_149:
            v81 = jhl_langet(v148, v48);
            v82 = (const char *)nvram_get(v81);
            if ( !v82 || !v52 || strcmp(v82, v52) )
            {
              v83 = jhl_langet(v148, v48);
              nvram_set(v83, v52);
              v14 = 1;
            }
            goto LABEL_71;
          }
        }
        v78 = jhl_langet(v147, v48);
        v79 = (const char *)nvram_get(v78);
        if ( v79 && v52 && !strcmp(v79, v52) )
          goto LABEL_70;
        v80 = jhl_langet(v147, v48);
        nvram_set(v80, v52);
        if ( !v48 )
          v174 = 1;
        v14 = 1;
        if ( !strcmp(v51, v148) )
          goto LABEL_149;
LABEL_71:
        if ( !strcmp(v51, v157 + 14996) )
        {
          v130 = jhl_langet(v166, v48);
          v131 = (const char *)nvram_get(v130);
          if ( !v131 || !v52 || strcmp(v131, v52) )
          {
            v132 = jhl_langet(v157 + 14996, v48);
            nvram_set(v132, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v156 + 14944) )
        {
          v127 = jhl_langet(v167, v48);
          v128 = (const char *)nvram_get(v127);
          if ( !v128 || !v52 || strcmp(v128, v52) )
          {
            v129 = jhl_langet(v156 + 14944, v48);
            nvram_set(v129, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v155 + 14980) )
        {
          v124 = jhl_langet(v168, v48);
          v125 = (const char *)nvram_get(v124);
          if ( !v125 || !v52 || strcmp(v125, v52) )
          {
            v126 = jhl_langet(v155 + 14980, v48);
            nvram_set(v126, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v149 + 7992) )
        {
          v121 = jhl_langet(v172, v48);
          v122 = (const char *)nvram_get(v121);
          if ( !v122 || !v52 || strcmp(v122, v52) )
          {
            v123 = jhl_langet(v149 + 7992, v48);
            nvram_set(v123, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v154 + 14916) )
        {
          v118 = jhl_langet(v169, v48);
          v119 = (const char *)nvram_get(v118);
          if ( !v119 || !v52 || strcmp(v119, v52) )
          {
            v120 = jhl_langet(v154 + 14916, v48);
            nvram_set(v120, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v159 + 14932) )
        {
          v115 = jhl_langet("dhcp_gw", v48);
          v116 = (const char *)nvram_get(v115);
          if ( !v116 || !v52 || strcmp(v116, v52) )
          {
            v117 = jhl_langet(v159 + 14932, v48);
            nvram_set(v117, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v158 + 15012) )
        {
          v112 = jhl_langet("dhcp_mask", v48);
          v113 = (const char *)nvram_get(v112);
          if ( !v113 || !v52 || strcmp(v113, v52) )
          {
            v114 = jhl_langet(v158 + 15012, v48);
            nvram_set(v114, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v161 + 14884) )
        {
          v109 = jhl_langet("dhcp_dns0", v48);
          v110 = (const char *)nvram_get(v109);
          if ( !v110 || !v52 || strcmp(v110, v52) )
          {
            v111 = jhl_langet(v161 + 14884, v48);
            nvram_set(v111, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v160 + 14900) )
        {
          v106 = jhl_langet("dhcp_dns1", v48);
          v107 = (const char *)nvram_get(v106);
          if ( !v107 || !v52 || strcmp(v107, v52) )
          {
            v108 = jhl_langet(v160 + 14900, v48);
            nvram_set(v108, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v150 + 14248) )
        {
          v103 = jhl_langet("dhcp_static_en", v48);
          v104 = (const char *)nvram_get(v103);
          if ( !v104 || !v52 || strcmp(v104, v52) )
          {
            v105 = jhl_langet(v150 + 14248, v48);
            nvram_set(v105, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v162 + 14264) )
        {
          v98 = jhl_langet("dhcp_static_addr", v48);
          v99 = (const char *)nvram_get(v98);
          if ( !v99 )
            goto LABEL_186;
          if ( v52 )
          {
            if ( !strcmp(v99, v52) )
              goto LABEL_82;
LABEL_186:
            v100 = v52;
          }
          else
          {
            v100 = 0;
          }
          while ( 1 )
          {
            v100 = strchr(v100, 62);
            if ( !v100 )
              break;
            *v100 = 60;
          }
          for ( i = v52; ; *i = 124 )
          {
            i = strchr(i, 44);
            if ( !i )
              break;
          }
          v102 = jhl_langet(v162 + 14264, v48);
          nvram_set(v102, v52);
          if ( !v48 )
            v50 = 1;
          v14 = 1;
        }
LABEL_82:
        if ( !strcmp(v51, v151 + 14284) )
        {
          v95 = jhl_langet("dhcp_notan_en", v48);
          v96 = (const char *)nvram_get(v95);
          if ( !v96 || !v52 || strcmp(v96, v52) )
          {
            v97 = jhl_langet(v151 + 14284, v48);
            nvram_set(v97, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( strcmp(v51, v163 + 14300) )
          goto LABEL_84;
        v90 = jhl_langet("dhcp_notan_addr", v48);
        v91 = (const char *)nvram_get(v90);
        if ( !v91 )
        {
LABEL_168:
          v92 = v52;
LABEL_170:
          while ( 1 )
          {
            v92 = strchr(v92, 62);
            if ( !v92 )
              break;
            *v92 = 60;
          }
          for ( j = v52; ; *j = 124 )
          {
            j = strchr(j, 44);
            if ( !j )
              break;
          }
          v94 = jhl_langet(v163 + 14300, v48);
          nvram_set(v94, v52);
          if ( !v48 )
            v50 = 1;
          v14 = 1;
          goto LABEL_84;
        }
        if ( !v52 )
        {
          v92 = 0;
          goto LABEL_170;
        }
        if ( strcmp(v91, v52) )
          goto LABEL_168;
LABEL_84:
        if ( !strcmp(v51, v152 + 14316) )
        {
          v87 = jhl_langet("dhcp_pool_en", v48);
          v88 = (const char *)nvram_get(v87);
          if ( !v88 || !v52 || strcmp(v88, v52) )
          {
            v89 = jhl_langet(v152 + 14316, v48);
            nvram_set(v89, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v153 + 14332) )
        {
          unescape(v52);
          v84 = jhl_langet("dhcp_ip_pool", v48);
          v85 = (const char *)nvram_get(v84);
          if ( !v85 || !v52 || strcmp(v85, v52) )
          {
            v86 = jhl_langet(v153 + 14332, v48);
            nvram_set(v86, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, "dhcp_option43") )
        {
          v72 = jhl_langet("dhcp_option43", v48);
          v73 = (const char *)nvram_get(v72);
          if ( !v73 || !v52 || strcmp(v73, v52) )
          {
            v74 = jhl_langet("dhcp_option43", v48);
            nvram_set(v74, v52);
            if ( !v48 )
              v50 = 1;
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v165 + 15072) || !strcmp(v51, "lan_mem") )
        {
          v53 = jhl_langet("lan_mem", v48);
          v54 = (const char *)nvram_get(v53);
          if ( !v54 || !v52 || strcmp(v54, v52) )
          {
            v55 = jhl_langet("lan_mem", v48);
            nvram_set(v55, v52);
            v14 = 1;
          }
        }
        if ( !strcmp(v51, v164 + 15148) || !strcmp(v51, "lan_ifacebind") )
        {
          v56 = jhl_langet("lan_ifacebind", v48);
          v57 = (const char *)nvram_get(v56);
          if ( !v57 || !v52 || strcmp(v57, v52) )
          {
            if ( strlen(v52) < 3 )
              v52 = "LAN1";
            v58 = jhl_langet("lan_ifacebind", v48);
            nvram_set(v58, v52);
            v14 = 1;
          }
          if ( v48 > 0 && !strcmp(v52, (const char *)&off_63F984) )
            format = "1";
        }
        if ( !v49 )
        {
          v175 = v50;
          v10 = v179;
          v45 = v178;
          break;
        }
      }
    }
    v59 = 0x2000 - (_DWORD)v170;
    if ( v177 )
      v60 = *(char **)(v177 + 16);
    else
      v60 = "";
    v61 = snprintf(&v170[(_DWORD)v10], 0x2000 - (_DWORD)v170, v184 + 15160, v48, v60);
    if ( v61 >= v59 )
      v61 = 0x1FFF - (_DWORD)v170;
    v62 = v186;
    v63 = &v170[v61];
    v64 = v183 + 11516;
    do
    {
      v65 = jhl_langet(*(_DWORD *)v62, v48);
      v66 = nvram_get(v65);
      v67 = snprintf(&v63[(_DWORD)v10], 0x2000 - (_DWORD)v63, v64, v66);
      v62 += 4;
      if ( v67 >= 0x2000 - (int)v63 )
        v67 = 0x1FFF - (_DWORD)v63;
      v63 += v67;
    }
    while ( v45 != v62 );
    v68 = snprintf(&v63[(_DWORD)v10], 0x2000 - (_DWORD)v63, v185 - 17872);
    if ( v68 >= 0x2000 - (int)v63 )
      v68 = 0x1FFF - (_DWORD)v63;
    v170 = &v63[v68];
  }
  while ( v182 != ++v173 );
  if ( (int)v170 > 0 )
    nvram_set("dual_lan_ssid_list", v10);
LABEL_15:
  if ( !format )
    format = "0";
  v17 = (const char *)nvram_get(v181 + 13964);
  if ( (!v17 || strcmp(v17, format)) && v176 && v190 )
  {
    nvram_set(v181 + 13964, format);
    v14 = 1;
    nvram_set("duolan_enble", "0");
  }
  v18 = (const char *)nvram_get(v181 + 13964);
  if ( !v18
    || strcmp(v18, "0")
    || (v43 = (const char *)nvram_get("dual_lan_mode_old")) == 0
    || (v44 = strcmp(v43, "0")) != 0 )
  {
    if ( v189 )
    {
      jhl_web_save_parm(a1, v191 + 7052, 1);
      jhl_web_save_parm(a1, "duolan_enble", 1);
    }
    jhl_parm_commit(v19);
    jhl_gl_lan_restart_timer(1000);
    v20 = v141;
    v21 = "{\"code\":4,\"error\":\"\",\"data\":null}";
    do
    {
      v22 = *(_DWORD *)v21;
      v23 = *((_DWORD *)v21 + 1);
      v24 = *((_DWORD *)v21 + 2);
      v25 = *((_DWORD *)v21 + 3);
      v21 += 16;
      *(_DWORD *)v20 = v22;
      *((_DWORD *)v20 + 1) = v23;
      *((_DWORD *)v20 + 2) = v24;
      *((_DWORD *)v20 + 3) = v25;
      v20 += 16;
    }
    while ( v21 != "}" );
    v26 = 33;
    *(_WORD *)v20 = *(_WORD *)v21;
    return httpd_cgi_ret(a1, v141, v26, 4);
  }
  if ( v189 )
  {
    duolan_undo();
    jhl_web_save_parm(a1, v191 + 7052, 1);
    jhl_web_save_parm(a1, "duolan_enble", 1);
  }
  else if ( !v174 )
  {
    if ( v175 )
    {
      start_dhcp_server();
      goto LABEL_121;
    }
    goto LABEL_122;
  }
  lanip_change();
  start_dhcp_server();
  start_rzgl(0);
  start_arp_sys();
  exec_service("ac_server-restart");
  duolan_do(0);
LABEL_121:
  jhl_start_firewall();
LABEL_122:
  if ( v14 )
  {
    v44 = 4;
    jhl_parm_commit(v19);
    jhl_gl_lan_restart_timer(1000);
  }
  v70 = snprintf(v141, 10240, "{\"code\":%d,\"error\":\"\",\"data\":{", v44);
  if ( v70 >= 0x2800 )
    v70 = 10239;
  if ( v180 )
  {
    v136 = (const char *)nvram_get("lan_ipaddr");
    v137 = (const char *)nvram_get("http_lanport");
    v70 += sprintf(&v141[v70], "\"lan_ipaddr\":\"%s:%s\"", v136, v137);
  }
  v71 = snprintf(&v141[v70], 10240 - v70, "}}");
  if ( v71 >= 10240 - v70 )
    v71 = 10239 - v70;
  return httpd_cgi_ret(a1, v141, v71 + v70, 4);
}
// 445B68: variable 'v19' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 66D294: using guessed type char *off_66D294[23];
// 66D2E4: using guessed type char *off_66D2E4[3];
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81EC: using guessed type int start_arp_sys(void);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8398: using guessed type int duolan_undo(void);
// 6A83CC: using guessed type int __fastcall duolan_do(_DWORD);
// 6A84B8: using guessed type int start_dhcp_server(void);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A86D0: using guessed type int lanip_change(void);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8744: using guessed type int __fastcall cJSON_GetIntvalue(_DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);
// 6A8994: using guessed type int __fastcall jhl_langet(_DWORD, _DWORD);

