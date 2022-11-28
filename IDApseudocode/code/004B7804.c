int __fastcall sj_dev_info_asp(int a1)
{
  int v2; // $s0
  char *v3; // $s1
  char *v4; // $s2
  char *v5; // $s3
  char *v6; // $s5
  char *v7; // $s7
  int v8; // $a2
  int v9; // $v0
  const char *v10; // $v0
  const char *v11; // $v0
  int v12; // $s7
  const char *v13; // $v0
  const char *v14; // $s2
  const char *v15; // $v0
  const char *v16; // $s2
  const char *v17; // $v0
  const char *v18; // $s2
  const char *v19; // $v0
  const char *v20; // $s2
  const char *v21; // $v0
  const char *v22; // $s2
  const char *v23; // $v0
  const char *v24; // $s2
  const char *v25; // $v0
  const char *v26; // $v0
  const char *v27; // $v0
  const char *v28; // $v0
  const char *v29; // $v0
  const char *v30; // $v0
  const char *v31; // $s2
  const char *v32; // $v0
  const char *v33; // $s2
  const char *v34; // $v0
  const char *v35; // $s2
  const char *v36; // $v0
  const char *v37; // $s2
  const char *v38; // $v0
  const char *v39; // $s2
  const char *v40; // $v0
  const char *v41; // $s2
  const char *v42; // $v0
  size_t v43; // $s3
  void *v44; // $v0
  void *v45; // $s1
  const char *v46; // $v0
  char *v47; // $s1
  const char *v48; // $v0
  const char *v49; // $a1
  int v50; // $s1
  const char *v51; // $v0
  const char *v52; // $v0
  const char *v53; // $v0
  const char *v54; // $v0
  const char *v55; // $v0
  const char *v56; // $v0
  int v57; // $a2
  const char *v58; // $s3
  const char *v59; // $v0
  const char *v60; // $s3
  const char *v61; // $v0
  const char *v62; // $s3
  const char *v63; // $v0
  const char *v64; // $s3
  const char *v65; // $v0
  const char *v66; // $s3
  const char *v67; // $v0
  const char *v68; // $s3
  const char *v69; // $v0
  const char *v70; // $s3
  const char *v71; // $v0
  const char *v72; // $s3
  const char *v73; // $v0
  const char *v74; // $s3
  const char *v75; // $v0
  const char *v76; // $s3
  const char *v77; // $v0
  const char *v78; // $s3
  const char *v79; // $v0
  const char *v80; // $s3
  const char *v81; // $v0
  const char *v82; // $s3
  const char *v83; // $v0
  const char *v84; // $s3
  const char *v85; // $v0
  const char *v86; // $s3
  const char *v87; // $v0
  const char *v88; // $s3
  const char *v89; // $v0
  char *v90; // $s3
  const char *v91; // $v0
  const char *v92; // $v0
  const char *v93; // $s3
  const char *v94; // $v0
  const char *v95; // $s3
  const char *v96; // $v0
  const char *v97; // $s3
  const char *v98; // $v0
  const char *v99; // $s3
  const char *v100; // $v0
  const char *v101; // $s3
  const char *v102; // $v0
  const char *v103; // $s3
  const char *v104; // $v0
  const char *v105; // $s3
  const char *v106; // $v0
  const char *v107; // $s3
  const char *v108; // $v0
  const char *v109; // $s3
  const char *v110; // $v0
  const char *v111; // $s3
  const char *v112; // $v0
  const char *v113; // $s3
  const char *v114; // $v0
  const char *v115; // $s3
  const char *v116; // $v0
  const char *v117; // $s3
  const char *v118; // $v0
  const char *v119; // $s3
  const char *v120; // $v0
  const char *v121; // $v0
  const char *v122; // $v0
  const char *v123; // $v0
  unsigned int v124; // $a2
  char *v126; // $s7
  int v127; // $v0
  int v128; // $s0
  char *v129; // $s6
  int v130; // $v0
  int v131; // $v0
  int v132; // $a2
  const char *v133; // $v0
  const char *v134; // $v0
  unsigned int v135; // $v0
  const char *v136; // $v0
  int v137; // $a0
  int v138; // $a2
  int v139[64]; // [sp+20h] [-268h] BYREF
  char v140[128]; // [sp+120h] [-168h] BYREF
  char *v141; // [sp+1A0h] [-E8h]
  void *v142; // [sp+1A4h] [-E4h]
  char *v143; // [sp+1A8h] [-E0h]
  char *v144; // [sp+1ACh] [-DCh]
  char *v145; // [sp+1B0h] [-D8h]
  char *v146; // [sp+1B4h] [-D4h]
  char *v147; // [sp+1B8h] [-D0h]
  char *v148; // [sp+1BCh] [-CCh]
  char *v149; // [sp+1C0h] [-C8h]
  char *v150; // [sp+1C4h] [-C4h]
  char *v151; // [sp+1C8h] [-C0h]
  char *v152; // [sp+1CCh] [-BCh]
  char *v153; // [sp+1D0h] [-B8h]
  char *v154; // [sp+1D4h] [-B4h]
  char *v155; // [sp+1D8h] [-B0h]
  char *v156; // [sp+1DCh] [-ACh]
  char *v157; // [sp+1E0h] [-A8h]
  char *v158; // [sp+1E4h] [-A4h]
  char *v159; // [sp+1E8h] [-A0h]
  char *v160; // [sp+1ECh] [-9Ch]
  char *v161; // [sp+1F0h] [-98h]
  char *v162; // [sp+1F4h] [-94h]
  char *v163; // [sp+1F8h] [-90h]
  char *v164; // [sp+1FCh] [-8Ch]
  char *v165; // [sp+200h] [-88h]
  char *v166; // [sp+204h] [-84h]
  char *v167; // [sp+208h] [-80h]
  char *v168; // [sp+20Ch] [-7Ch]
  char *v169; // [sp+210h] [-78h]
  char *v170; // [sp+214h] [-74h]
  char *v171; // [sp+218h] [-70h]
  char *v172; // [sp+21Ch] [-6Ch]
  char *v173; // [sp+220h] [-68h]
  char *v174; // [sp+224h] [-64h]
  char *v175; // [sp+228h] [-60h]
  char *v176; // [sp+22Ch] [-5Ch]
  char *v177; // [sp+230h] [-58h]
  char *v178; // [sp+234h] [-54h]
  char *v179; // [sp+238h] [-50h]
  char *v180; // [sp+23Ch] [-4Ch]
  char *v181; // [sp+240h] [-48h]
  char *v182; // [sp+244h] [-44h]
  char *v183; // [sp+248h] [-40h]
  char *v184; // [sp+24Ch] [-3Ch]
  char *v185; // [sp+250h] [-38h]
  char *v186; // [sp+254h] [-34h]
  char *v187; // [sp+258h] [-30h]
  char *v188; // [sp+25Ch] [-2Ch]
  char *v189; // [sp+260h] [-28h]
  char *v190; // [sp+264h] [-24h]
  char *v191; // [sp+268h] [-20h]
  char *v192; // [sp+26Ch] [-1Ch]
  char *v193; // [sp+270h] [-18h]
  char *v194; // [sp+274h] [-14h]
  char *v195; // [sp+278h] [-10h]
  char *v196; // [sp+27Ch] [-Ch]
  char *v197; // [sp+280h] [-8h]
  char *v198; // [sp+284h] [-4h]

  v198 = v140;
  memset(v140, 0, sizeof(v140));
  v2 = (int)httpd_get_parm(a1, "dev_sn");
  v3 = httpd_get_parm(a1, "dev_name");
  v4 = httpd_get_parm(a1, "dev_addr");
  v156 = httpd_get_parm(a1, "dev_type");
  v157 = httpd_get_parm(a1, "xt_enable");
  v158 = httpd_get_parm(a1, "xt_wdsz");
  v159 = httpd_get_parm(a1, "xt_trail");
  v160 = httpd_get_parm(a1, "xt_placesn");
  v161 = httpd_get_parm(a1, "dev_lable");
  v150 = httpd_get_parm(a1, "fixed_type");
  v162 = httpd_get_parm(a1, "info_num");
  v5 = httpd_get_parm(a1, "dev_longitude");
  v143 = httpd_get_parm(a1, "dev_latitude");
  v151 = httpd_get_parm(a1, "jwd_type");
  v145 = httpd_get_parm(a1, "dev_radius");
  v163 = httpd_get_parm(a1, "floor_str");
  v164 = httpd_get_parm(a1, "station_info");
  v165 = httpd_get_parm(a1, "dev_car_number");
  v166 = httpd_get_parm(a1, "dev_metro_way");
  v167 = httpd_get_parm(a1, "dev_metro_car");
  v168 = httpd_get_parm(a1, "dev_metro_carriage");
  v142 = httpd_get_parm(a1, "aps_list");
  v144 = httpd_get_parm(a1, "caiji_type");
  v6 = httpd_get_parm(a1, "place_num");
  v155 = httpd_get_parm(a1, "place_type");
  v141 = httpd_get_parm(a1, "place_num_dst");
  v169 = httpd_get_parm(a1, "ssq_type");
  v170 = httpd_get_parm(a1, "province_name");
  v171 = httpd_get_parm(a1, "city_name");
  v172 = httpd_get_parm(a1, "area_name");
  v173 = httpd_get_parm(a1, "police_code");
  v147 = httpd_get_parm(a1, "loc_name");
  v152 = httpd_get_parm(a1, "sj_place_uscc");
  v149 = httpd_get_parm(a1, "loc_addr");
  v174 = httpd_get_parm(a1, "loc_longitude");
  v175 = httpd_get_parm(a1, "loc_latitude");
  v176 = httpd_get_parm(a1, "loc_bussiness_type");
  v177 = httpd_get_parm(a1, "loc_owner");
  v178 = httpd_get_parm(a1, "loc_owner_cer_type");
  v179 = httpd_get_parm(a1, "loc_owner_code");
  v180 = httpd_get_parm(a1, "loc_contact_way");
  v181 = httpd_get_parm(a1, "loc_start");
  v182 = httpd_get_parm(a1, "loc_end");
  v183 = httpd_get_parm(a1, "access_type");
  v184 = httpd_get_parm(a1, "operator_net");
  v185 = httpd_get_parm(a1, "netsite_type");
  v186 = httpd_get_parm(a1, "business_nature");
  v187 = httpd_get_parm(a1, "data_type");
  v188 = httpd_get_parm(a1, "terminal_netenv");
  v189 = httpd_get_parm(a1, "fz_name");
  v190 = httpd_get_parm(a1, "fz_cardid");
  v191 = httpd_get_parm(a1, "fz_phone");
  v192 = httpd_get_parm(a1, "place_state");
  v193 = httpd_get_parm(a1, "dev_caiji_class");
  v194 = httpd_get_parm(a1, "caiji_company");
  v146 = httpd_get_parm(a1, "place_code");
  v153 = httpd_get_parm(a1, "sj_area_num");
  v148 = httpd_get_parm(a1, "auth_servicecode");
  v7 = httpd_get_parm(a1, "opt");
  v195 = httpd_get_parm(a1, "onlinedev_num");
  v196 = httpd_get_parm(a1, "baozhuangdev_num");
  v197 = httpd_get_parm(a1, "dev_detail_id");
  if ( v7 )
  {
    v154 = "1\"";
    if ( !strcmp(v7, "reset") )
    {
      v126 = httpd_get_parm(a1, v154 - 4340);
      if ( !v126 )
        v126 = "all";
      v141 = "address";
      v127 = *v126;
      v128 = 0;
      v142 = "company";
      if ( v127 )
      {
        do
        {
          v129 = strchr(v126, 44);
          if ( !v129 )
            v129 = &v126[strlen(v126)];
          v130 = v129 - v126;
          if ( v129 - v126 == 6 )
          {
            if ( !memcmp("device", v126, 6u) )
              v128 |= 1u;
          }
          else if ( v130 == 5 )
          {
            if ( !memcmp("place", v126, 5u) )
              v128 |= 2u;
          }
          else if ( v130 == 7 )
          {
            if ( !memcmp(v141, v126, 7u) )
            {
              v128 |= 4u;
            }
            else if ( !memcmp(v142, v126, 7u) )
            {
              v128 |= 8u;
            }
          }
          else if ( v130 == 3 && !memcmp("all", v126, 3u) )
          {
            v128 = -1;
          }
          v131 = *v129;
          if ( *v129 )
            v131 = *++v129;
          v126 = v129;
        }
        while ( v131 );
      }
      if ( reset_sj_param(v128) < 0 )
      {
        v136 = (const char *)_GET_LANG_TEXT(63, *(unsigned __int8 *)(a1 + 210102), v132);
        snprintf((char *)v139, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v136);
        v124 = 27;
        v139[0] = 1952805499;
        v139[1] = 1697395002;
        v139[2] = 658141810;
        v139[3] = -37040462;
        v139[4] = -1009329962;
        v139[5] = -592402486;
        v139[6] = 8202017;
        return httpd_cgi_ret(a1, (char *)v139, v124, 4);
      }
      v133 = (const char *)_GET_LANG_TEXT(63, *(unsigned __int8 *)(a1 + 210102), v132);
LABEL_279:
      v124 = snprintf((char *)v139, 256, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v133);
      if ( v124 < 0x100 )
        return httpd_cgi_ret(a1, (char *)v139, v124, 4);
      return httpd_cgi_ret(a1, (char *)v139, 255, 4);
    }
  }
  if ( !v3 || !v4 )
  {
LABEL_282:
    v9 = a1 + 196608;
    goto LABEL_283;
  }
  v9 = a1 + 196608;
  if ( v5 )
  {
    if ( !v143 || !v145 || !v147 || !v149 || (!v6 || !v155 || !v141) && !v146 )
      goto LABEL_282;
    if ( v2 )
    {
      v10 = (const char *)nvram_get("sj_dev_sn");
      if ( v10 && !strcmp(v10, (const char *)v2) )
      {
        v2 = 0;
      }
      else
      {
        nvram_set("sj_dev_sn", v2);
        v2 = 1;
      }
    }
    v11 = (const char *)nvram_get("sj_dev_name");
    if ( v11 && !strcmp(v11, v3) )
    {
      v12 = 0;
    }
    else
    {
      nvram_set("sj_dev_name", v3);
      v12 = 1;
      v2 = 1;
    }
    v13 = (const char *)nvram_get("sj_dev_addr");
    if ( !v13 || strcmp(v13, v4) )
    {
      nvram_set("sj_dev_addr", v4);
      v2 = 1;
    }
    v14 = v156;
    if ( v156 )
    {
      v15 = (const char *)nvram_get("sj_dev_type");
      if ( !v15 || strcmp(v15, v14) )
      {
        nvram_set("sj_dev_type", v156);
        v12 = 1;
        v2 = 1;
      }
    }
    v16 = v158;
    if ( v158 )
    {
      v17 = (const char *)nvram_get("sj_xt_wdsz");
      if ( !v17 || strcmp(v17, v16) )
      {
        nvram_set("sj_xt_wdsz", v158);
        v12 = 1;
        v2 = 1;
      }
    }
    v18 = v157;
    if ( v157 )
    {
      v19 = (const char *)nvram_get("sj_xt_enable");
      if ( !v19 || strcmp(v19, v18) )
      {
        nvram_set("sj_xt_enable", v157);
        v12 = 1;
        v2 = 1;
      }
    }
    v20 = v159;
    if ( v159 )
    {
      v21 = (const char *)nvram_get("sj_xt_trail");
      if ( !v21 || strcmp(v21, v20) )
      {
        nvram_set("sj_xt_trail", v159);
        v12 = 1;
        v2 = 1;
      }
    }
    v22 = v160;
    if ( v160 )
    {
      v23 = (const char *)nvram_get("sj_xt_placesn");
      if ( !v23 || strcmp(v23, v22) )
      {
        nvram_set("sj_xt_placesn", v160);
        v12 = 1;
        v2 = 1;
      }
    }
    v24 = v161;
    if ( v161 )
    {
      v25 = (const char *)nvram_get("sj_dev_lable");
      if ( !v25 || strcmp(v25, v24) )
      {
        nvram_set("sj_dev_lable", v161);
        v12 = 1;
        v2 = 1;
      }
    }
    if ( v150 )
    {
      v26 = (const char *)nvram_get("sj_fixed_type");
      if ( !v26 || strcmp(v26, v150) )
      {
        nvram_set("sj_fixed_type", v150);
        v2 = 1;
      }
    }
    v27 = (const char *)nvram_get("sj_dev_longitude");
    if ( !v27 || strcmp(v27, v5) )
    {
      nvram_set("sj_dev_longitude", v5);
      v12 = 1;
      v2 = 1;
    }
    v28 = (const char *)nvram_get("sj_dev_latitude");
    if ( v28 && !strcmp(v28, v143) )
    {
      if ( !v151 )
        goto LABEL_62;
    }
    else
    {
      nvram_set("sj_dev_latitude", v143);
      v12 = 1;
      if ( !v151 )
        goto LABEL_61;
      v2 = 1;
    }
    v29 = (const char *)nvram_get("sj_jwd_type");
    if ( v29 && !strcmp(v29, v151) )
    {
LABEL_62:
      v30 = (const char *)nvram_get("sj_dev_radius");
      if ( !v30 || strcmp(v30, v145) )
      {
        nvram_set("sj_dev_radius", v145);
        v12 = 1;
        v2 = 1;
      }
      v31 = v163;
      if ( v163 )
      {
        v32 = (const char *)nvram_get("sj_dev_floor");
        if ( !v32 || strcmp(v32, v31) )
        {
          nvram_set("sj_dev_floor", v163);
          v12 = 1;
          v2 = 1;
        }
      }
      v33 = v164;
      if ( v164 )
      {
        v34 = (const char *)nvram_get("sj_dev_station");
        if ( !v34 || strcmp(v34, v33) )
        {
          nvram_set("sj_dev_station", v164);
          v12 = 1;
          v2 = 1;
        }
      }
      v35 = v165;
      if ( v165 )
      {
        v36 = (const char *)nvram_get("sj_dev_car_num");
        if ( !v36 || strcmp(v36, v35) )
        {
          nvram_set("sj_dev_car_num", v165);
          v12 = 1;
          v2 = 1;
        }
      }
      v37 = v166;
      if ( v166 )
      {
        v38 = (const char *)nvram_get("sj_dev_metro");
        if ( !v38 || strcmp(v38, v37) )
        {
          nvram_set("sj_dev_metro", v166);
          v12 = 1;
          v2 = 1;
        }
      }
      v39 = v167;
      if ( v167 )
      {
        v40 = (const char *)nvram_get("sj_dev_metro_car");
        if ( !v40 || strcmp(v40, v39) )
        {
          nvram_set("sj_dev_metro_car", v167);
          v12 = 1;
          v2 = 1;
        }
      }
      v41 = v168;
      if ( v168 )
      {
        v42 = (const char *)nvram_get("sj_dev_metro_box");
        if ( !v42 || strcmp(v42, v41) )
        {
          nvram_set("sj_dev_metro_box", v168);
          v12 = 1;
          v2 = 1;
        }
      }
      if ( v142 )
      {
        v43 = strlen((const char *)v142) + 1;
        _mem_malloc(v43, "sj_dev_info_asp", 338);
        v45 = v44;
        if ( v44 )
        {
          memset(v44, 0, v43);
          if ( jhl_check_and_tran_unicode2312(v142, v45) < 0 )
          {
            _mem_free(v45);
            v45 = v142;
          }
          v46 = (const char *)nvram_get("sj_aps_list");
          if ( !v46 || strcmp(v46, (const char *)v45) )
          {
            nvram_set("sj_aps_list", v45);
            v12 = 1;
            v2 = 1;
          }
          if ( v142 != v45 )
            _mem_free(v45);
        }
      }
      if ( v6 )
      {
        if ( v155 )
        {
          v47 = v198;
          snprintf(v198, 128, "%s%s", v6, v155);
          v48 = (const char *)nvram_get("sj_palce_code");
          v49 = v47;
          if ( !v48 || (v50 = 0, strcmp(v48, v49)) )
          {
            nvram_set("sj_palce_code", v198);
            v50 = 1;
            v2 = 1;
          }
        }
        else
        {
          v50 = 0;
        }
        if ( !v146 )
          goto LABEL_108;
      }
      else
      {
        v50 = 0;
        if ( !v146 )
        {
          v50 = 0;
          goto LABEL_111;
        }
      }
      v51 = (const char *)nvram_get("sj_palce_code");
      if ( !v51 || strcmp(v51, v146) )
      {
        nvram_set("sj_palce_code", v146);
        v50 = 1;
        v2 = 1;
      }
      if ( !v6 )
      {
LABEL_111:
        if ( v141 )
        {
          v53 = (const char *)nvram_get("sj_palce_num_dst");
          if ( !v53 || strcmp(v53, v141) )
          {
            nvram_set("sj_palce_num_dst", v141);
            v2 = 1;
          }
        }
        v54 = (const char *)nvram_get("sj_palce_name");
        if ( v54 && !strcmp(v54, v147) )
        {
          if ( !v152 )
            goto LABEL_123;
        }
        else
        {
          nvram_set("sj_palce_name", v147);
          v50 = 1;
          if ( !v152 )
            goto LABEL_122;
          v2 = 1;
        }
        v55 = (const char *)nvram_get("sj_place_uscc");
        if ( v55 && !strcmp(v55, v152) )
        {
LABEL_123:
          v56 = (const char *)nvram_get("sj_palce_addr");
          if ( !v56 || strcmp(v56, v149) )
          {
            nvram_set("sj_palce_addr", v149);
            v50 = 1;
            v2 = 1;
          }
          v58 = v174;
          if ( v174 )
          {
            v59 = (const char *)nvram_get("sj_palce_longitude");
            if ( !v59 || strcmp(v59, v58) )
            {
              nvram_set("sj_palce_longitude", v174);
              v50 = 1;
              v2 = 1;
            }
          }
          v60 = v175;
          if ( v175 )
          {
            v61 = (const char *)nvram_get("sj_palce_latitude");
            if ( !v61 || strcmp(v61, v60) )
            {
              nvram_set("sj_palce_latitude", v175);
              v50 = 1;
              v2 = 1;
            }
          }
          v62 = v176;
          if ( v176 )
          {
            v63 = (const char *)nvram_get("sj_palce_nature");
            if ( !v63 || strcmp(v63, v62) )
            {
              nvram_set("sj_palce_nature", v176);
              v50 = 1;
              v2 = 1;
            }
          }
          v64 = v177;
          if ( v177 )
          {
            v65 = (const char *)nvram_get("sj_palce_worker");
            if ( !v65 || strcmp(v65, v64) )
            {
              nvram_set("sj_palce_worker", v177);
              v2 = 1;
            }
          }
          v66 = v178;
          if ( v178 )
          {
            v67 = (const char *)nvram_get("sj_palce_worker_cardtype");
            if ( !v67 || strcmp(v67, v66) )
            {
              nvram_set("sj_palce_worker_cardtype", v178);
              v50 = 1;
              v2 = 1;
            }
          }
          v68 = v179;
          if ( v179 )
          {
            v69 = (const char *)nvram_get("sj_palce_worker_cardid");
            if ( !v69 || strcmp(v69, v68) )
            {
              nvram_set("sj_palce_worker_cardid", v179);
              v50 = 1;
              v2 = 1;
            }
          }
          v70 = v180;
          if ( v180 )
          {
            v71 = (const char *)nvram_get("sj_palce_phone");
            if ( !v71 || strcmp(v71, v70) )
            {
              nvram_set("sj_palce_phone", v180);
              v2 = 1;
            }
          }
          v72 = v181;
          if ( v181 )
          {
            v73 = (const char *)nvram_get("sj_palce_start_time");
            if ( !v73 || strcmp(v73, v72) )
            {
              nvram_set("sj_palce_start_time", v181);
              v50 = 1;
              v2 = 1;
            }
          }
          v74 = v182;
          if ( v182 )
          {
            v75 = (const char *)nvram_get("sj_palce_end_time");
            if ( !v75 || strcmp(v75, v74) )
            {
              nvram_set("sj_palce_end_time", v182);
              v50 = 1;
              v2 = 1;
            }
          }
          v76 = v183;
          if ( v183 )
          {
            v77 = (const char *)nvram_get("sj_access_type");
            if ( !v77 || strcmp(v77, v76) )
            {
              nvram_set("sj_access_type", v183);
              v2 = 1;
            }
          }
          v78 = v184;
          if ( v184 )
          {
            v79 = (const char *)nvram_get("sj_operator_net");
            if ( !v79 || strcmp(v79, v78) )
            {
              nvram_set("sj_operator_net", v184);
              v2 = 1;
            }
          }
          v80 = v188;
          if ( v188 )
          {
            v81 = (const char *)nvram_get("sj_terminal_netenv");
            if ( !v81 || strcmp(v81, v80) )
            {
              nvram_set("sj_terminal_netenv", v188);
              v2 = 1;
            }
          }
          v82 = v185;
          if ( v185 )
          {
            v83 = (const char *)nvram_get("sj_netsite_type");
            if ( !v83 || strcmp(v83, v82) )
            {
              nvram_set("sj_netsite_type", v185);
              v2 = 1;
            }
          }
          v84 = v186;
          if ( v186 )
          {
            v85 = (const char *)nvram_get("sj_business_nature");
            if ( !v85 || strcmp(v85, v84) )
            {
              nvram_set("sj_business_nature", v186);
              v2 = 1;
            }
          }
          v86 = v162;
          if ( v162 )
          {
            v87 = (const char *)nvram_get("sj_dev_sid");
            if ( !v87 || strcmp(v87, v86) )
            {
              nvram_set("sj_dev_sid", v162);
              v2 = 1;
            }
          }
          v88 = v187;
          if ( v187 )
          {
            v89 = (const char *)nvram_get("sj_data_caiji_type");
            if ( !v89 || strcmp(v89, v88) )
            {
              nvram_set("sj_data_caiji_type", v187);
              v2 = 1;
            }
          }
          v90 = v144;
          if ( v144 )
          {
            v91 = (const char *)nvram_get("sj_caiji_type");
            if ( !v91 || strcmp(v91, v90) )
            {
              nvram_set("sj_caiji_type", v144);
              v50 = 1;
              v2 = 1;
            }
            v92 = (const char *)nvram_get("sj_caiji_type");
            if ( !v92 || strcmp(v92, v144) )
            {
              nvram_set("sj_caiji_type", v144);
              v2 = 1;
            }
          }
          v93 = v169;
          if ( v169 )
          {
            v94 = (const char *)nvram_get("sj_ssq_type");
            if ( !v94 || strcmp(v94, v93) )
            {
              nvram_set("sj_ssq_type", v169);
              v2 = 1;
            }
          }
          v95 = v170;
          if ( v170 )
          {
            v96 = (const char *)nvram_get("sj_province_name");
            if ( !v96 || strcmp(v96, v95) )
            {
              nvram_set("sj_province_name", v170);
              v2 = 1;
            }
          }
          v97 = v171;
          if ( v171 )
          {
            v98 = (const char *)nvram_get("sj_city_name");
            if ( !v98 || strcmp(v98, v97) )
            {
              nvram_set("sj_city_name", v171);
              v2 = 1;
            }
          }
          v99 = v172;
          if ( v172 )
          {
            v100 = (const char *)nvram_get("sj_area_name");
            if ( !v100 || strcmp(v100, v99) )
            {
              nvram_set("sj_area_name", v172);
              v2 = 1;
            }
          }
          v101 = v173;
          if ( v173 )
          {
            v102 = (const char *)nvram_get("sj_police_code");
            if ( !v102 || strcmp(v102, v101) )
            {
              nvram_set("sj_police_code", v173);
              v2 = 1;
            }
          }
          v103 = v189;
          if ( v189 )
          {
            v104 = (const char *)nvram_get("sj_fz_name");
            if ( !v104 || strcmp(v104, v103) )
            {
              nvram_set("sj_fz_name", v189);
              v2 = 1;
            }
          }
          v105 = v190;
          if ( v190 )
          {
            v106 = (const char *)nvram_get("sj_fz_cardid");
            if ( !v106 || strcmp(v106, v105) )
            {
              nvram_set("sj_fz_cardid", v190);
              v2 = 1;
            }
          }
          v107 = v191;
          if ( v191 )
          {
            v108 = (const char *)nvram_get("sj_fz_phone");
            if ( !v108 || strcmp(v108, v107) )
            {
              nvram_set("sj_fz_phone", v191);
              v2 = 1;
            }
          }
          v109 = v192;
          if ( v192 )
          {
            v110 = (const char *)nvram_get("sj_palce_state");
            if ( !v110 || strcmp(v110, v109) )
            {
              nvram_set("sj_palce_state", v192);
              v2 = 1;
            }
          }
          v111 = v193;
          if ( v193 )
          {
            v112 = (const char *)nvram_get("sj_dev_caiji_class");
            if ( !v112 || strcmp(v112, v111) )
            {
              nvram_set("sj_dev_caiji_class", v193);
              v2 = 1;
            }
          }
          v113 = v194;
          if ( v194 )
          {
            v114 = (const char *)nvram_get("sj_caiji_company");
            if ( !v114 || strcmp(v114, v113) )
            {
              nvram_set("sj_caiji_company", v194);
              v2 = 1;
            }
          }
          v115 = v195;
          if ( v195 )
          {
            v116 = (const char *)nvram_get("sj_onlinedev_num");
            if ( !v116 || strcmp(v116, v115) )
            {
              nvram_set("sj_onlinedev_num", v195);
              v2 = 1;
            }
          }
          v117 = v196;
          if ( v196 )
          {
            v118 = (const char *)nvram_get("sj_baozhuangdev_num");
            if ( !v118 || strcmp(v118, v117) )
            {
              nvram_set("sj_baozhuangdev_num", v196);
              v2 = 1;
            }
          }
          v119 = v197;
          if ( v197 )
          {
            v120 = (const char *)nvram_get("sj_dev_detail_id");
            if ( !v120 || strcmp(v120, v119) )
            {
              nvram_set("sj_dev_detail_id", v197);
              v2 = 1;
            }
          }
          if ( !v153 || (v121 = (const char *)nvram_get("sj_area_num")) != 0 && !strcmp(v121, v153) )
          {
            if ( v148 )
              goto LABEL_257;
            if ( !v2 )
              goto LABEL_261;
          }
          else
          {
            nvram_set("sj_area_num", v153);
            v2 = 1;
            if ( v148 )
            {
LABEL_257:
              v122 = (const char *)nvram_get("sj_auth_servicecode");
              if ( !v122 || strcmp(v122, v148) )
                nvram_set("sj_auth_servicecode", v148);
              if ( !v2 )
              {
LABEL_261:
                v123 = (const char *)_GET_LANG_TEXT(62, *(unsigned __int8 *)(a1 + 210102), v57);
                v124 = snprintf((char *)v139, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v123);
                if ( v124 < 0x100 )
                  return httpd_cgi_ret(a1, (char *)v139, v124, 4);
                return httpd_cgi_ret(a1, (char *)v139, 255, 4);
              }
              goto LABEL_295;
            }
          }
LABEL_295:
          mng_client_restart(0);
          nvram_set("sj_mod_flag", "1");
          if ( v50 )
            nvram_set("sj_place_mod_flag", "1");
          if ( v12 )
            nvram_set("sj_dev_mod_flag", "1");
          jhl_parm_commit(v137);
          v133 = (const char *)_GET_LANG_TEXT(65, *(unsigned __int8 *)(a1 + 210102), v138);
          goto LABEL_279;
        }
        nvram_set("sj_place_uscc", v152);
LABEL_122:
        v50 = 1;
        v2 = 1;
        goto LABEL_123;
      }
LABEL_108:
      v52 = (const char *)nvram_get("sj_palce_num");
      if ( !v52 || strcmp(v52, v6) )
      {
        nvram_set("sj_palce_num", v6);
        v2 = 1;
      }
      goto LABEL_111;
    }
    nvram_set("sj_jwd_type", v151);
LABEL_61:
    v12 = 1;
    v2 = 1;
    goto LABEL_62;
  }
LABEL_283:
  v134 = (const char *)_GET_LANG_TEXT(61, *(unsigned __int8 *)(v9 + 13494), v8);
  v135 = snprintf((char *)v139, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v134);
  if ( v135 >= 0x100 )
    v135 = 255;
  return httpd_cgi_ret(a1, (char *)v139, v135, 4);
}
// 4B87DC: variable 'v44' is possibly undefined
// 4B98BC: variable 'v57' is possibly undefined
// 4B9A24: variable 'v132' is possibly undefined
// 4B9AA4: variable 'v8' is possibly undefined
// 4B9C9C: variable 'v137' is possibly undefined
// 4B9CBC: variable 'v138' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83A0: using guessed type int __fastcall mng_client_restart(_DWORD);
// 6A8550: using guessed type int __fastcall jhl_check_and_tran_unicode2312(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

