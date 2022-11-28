int __fastcall sub_46175C(int a1)
{
  char *v2; // $s5
  char *v3; // $s7
  char *v4; // $fp
  char *v5; // $v0
  int v6; // $s4
  const char *v7; // $s2
  const char *v8; // $v0
  unsigned int v9; // $s6
  char *v11; // $fp
  char *v12; // $s7
  char *v13; // $s2
  char *v14; // $s3
  char *v15; // $s5
  char *v16; // $s6
  int v17; // $v0
  int v18; // $a0
  char *v19; // $s1
  int v20; // $s1
  char *v21; // $s7
  char *v22; // $s7
  char *v23; // $s7
  char *v24; // $s7
  char *v25; // $s7
  char *v26; // $s1
  const char *v27; // $v0
  char *v28; // $s2
  char *v29; // $s1
  const char *v30; // $s2
  const char *v31; // $v0
  int v32; // $s2
  const char *v33; // $v0
  _BYTE *v34; // $v0
  void *v35; // $v0
  void *v36; // $s1
  _BYTE *v37; // $s3
  _DWORD *v38; // $fp
  int v39; // $v0
  int v40; // $v0
  const char *v41; // $s6
  int v42; // $a0
  char *v43; // $v1
  const char *v44; // $v0
  int v45; // $t0
  int v46; // $a3
  int v47; // $a2
  int v48; // $a1
  int v49; // $a1
  int v50; // $a2
  int v51; // $a0
  const char *v52; // $v0
  const char *v53; // $v0
  const char *v54; // [sp+40h] [-5D0h]
  int v55[256]; // [sp+50h] [-5C0h] BYREF
  char s[256]; // [sp+450h] [-1C0h] BYREF
  const char *v57; // [sp+550h] [-C0h] BYREF
  const char *v58; // [sp+554h] [-BCh]
  const char *v59; // [sp+558h] [-B8h]
  char *v60; // [sp+55Ch] [-B4h]
  char *v61; // [sp+560h] [-B0h]
  char *v62; // [sp+564h] [-ACh]
  const char *v63; // [sp+568h] [-A8h]
  char *v64; // [sp+56Ch] [-A4h]
  char *v65; // [sp+570h] [-A0h]
  const char *v66; // [sp+574h] [-9Ch]
  char *v67; // [sp+578h] [-98h]
  char *v68; // [sp+57Ch] [-94h]
  const char *v69; // [sp+580h] [-90h]
  char *v70; // [sp+584h] [-8Ch]
  char *v71; // [sp+588h] [-88h]
  const char *v72; // [sp+58Ch] [-84h]
  char *v73; // [sp+590h] [-80h]
  char *v74; // [sp+594h] [-7Ch]
  int v75; // [sp+598h] [-78h]
  char *v76; // [sp+59Ch] [-74h] BYREF
  char *v77; // [sp+5A0h] [-70h]
  char *v78; // [sp+5A4h] [-6Ch]
  const char *v79; // [sp+5A8h] [-68h]
  char *v80; // [sp+5ACh] [-64h]
  char *v81; // [sp+5B0h] [-60h]
  const char *v82; // [sp+5B4h] [-5Ch]
  char *v83; // [sp+5B8h] [-58h]
  char *v84; // [sp+5BCh] [-54h]
  const char *v85; // [sp+5C0h] [-50h]
  char *v86; // [sp+5C4h] [-4Ch]
  char *v87; // [sp+5C8h] [-48h]
  const char *v88; // [sp+5CCh] [-44h]
  char *v89; // [sp+5D0h] [-40h]
  char *v90; // [sp+5D4h] [-3Ch]
  char *v91; // [sp+5E0h] [-30h]
  char *v92; // [sp+5E4h] [-2Ch]
  char *v93; // [sp+5E8h] [-28h]
  char *v94; // [sp+5ECh] [-24h]
  int v95; // [sp+5F0h] [-20h]
  char *v96; // [sp+5F4h] [-1Ch]
  char *v97; // [sp+5F8h] [-18h]
  char *v98; // [sp+5FCh] [-14h]
  char *v99; // [sp+600h] [-10h]
  char *v100; // [sp+604h] [-Ch]
  char *v101; // [sp+608h] [-8h]
  char *v102; // [sp+60Ch] [-4h]

  v2 = httpd_get_parm(a1, "name");
  v95 = (int)httpd_get_parm(a1, "old_name");
  v91 = httpd_get_parm(a1, "en");
  v92 = httpd_get_parm(a1, "user_id");
  v93 = httpd_get_parm(a1, "proto");
  v94 = httpd_get_parm(a1, "num");
  v3 = httpd_get_parm(a1, "c");
  v4 = httpd_get_parm(a1, "time");
  v6 = httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  if ( !v5 )
    goto LABEL_6;
  v7 = v5;
  if ( strcmp(v5, (const char *)&off_64712C) )
  {
    v97 = "a";
    if ( strcmp(v7, (const char *)&off_646D8C) && strcmp(v7, (const char *)&off_648DDC) && strcmp(v7, "del") )
    {
LABEL_6:
      v8 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
      v9 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
      if ( v9 >= 0x100 )
        v9 = 255;
      return httpd_cgi_ret(a1, s, v9, 4);
    }
    v96 = "a";
    _mem_malloc(102400, "ddos_asp", 1346);
    v36 = v35;
    _mem_malloc(102400, "ddos_asp", 1347);
    v37 = v34;
    if ( !v36 )
    {
      v53 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
      v9 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v53);
      if ( v9 >= 0x100 )
        v9 = 255;
      goto LABEL_105;
    }
    if ( v34 )
    {
      if ( !strcmp(v7, "del") && v6 )
      {
        v38 = *(_DWORD **)(v6 + 8);
        if ( !v38 )
          goto LABEL_101;
        v39 = v38[4];
        if ( !v39 )
          goto LABEL_101;
        v98 = "a";
        v95 = 0;
        v91 = "hixz_ddos";
        do
        {
          v55[1] = v39;
          v55[0] = (int)"hixzddos_del.sh";
          v55[2] = 0;
          eval(v55, 0, 0, 0);
          jhl_parm_get("hixz_ddos", v36, 102400);
          if ( nvparm_del_str(v36, 60, 10, v38[4], 124, 0, v37) )
          {
            jhl_parm_set(v91, v37);
            v95 = 1;
          }
          v38 = (_DWORD *)*v38;
          if ( !v38 )
            break;
          v39 = v38[4];
        }
        while ( v39 );
LABEL_108:
        if ( v95 )
        {
LABEL_100:
          jhl_parm_set(v98 + 26668, v37);
          jhl_parm_commit(v42);
        }
LABEL_101:
        v43 = s;
        v44 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v45 = *(_DWORD *)v44;
          v46 = *((_DWORD *)v44 + 1);
          v47 = *((_DWORD *)v44 + 2);
          v48 = *((_DWORD *)v44 + 3);
          v44 += 16;
          *(_DWORD *)v43 = v45;
          *((_DWORD *)v43 + 1) = v46;
          *((_DWORD *)v43 + 2) = v47;
          *((_DWORD *)v43 + 3) = v48;
          v43 += 16;
        }
        while ( v44 != "}" );
        v9 = 33;
        *(_WORD *)v43 = *(_WORD *)v44;
LABEL_104:
        _mem_free(v36);
LABEL_105:
        if ( v37 )
          _mem_free(v37);
        return httpd_cgi_ret(a1, s, v9, 4);
      }
      if ( v2 )
      {
        if ( !strcmp(v7, (const char *)&off_648DDC) )
        {
          if ( v95 )
          {
            v55[1] = v95;
            v98 = "a";
            v55[2] = 0;
            v55[0] = (int)"hixzddos_del.sh";
            eval(v55, 0, 0, 0);
            jhl_parm_get("hixz_ddos", v36, 102400);
            v40 = nvparm_del_str(v36, 60, 10, v95, 124, 0, v37);
          }
          else
          {
            v55[1] = (int)v2;
            v98 = "a";
            v55[2] = 0;
            v55[0] = (int)"hixzddos_del.sh";
            eval(v55, 0, 0, 0);
            jhl_parm_get(v98 + 26668, v36, 102400);
            v40 = nvparm_del_str(v36, 60, 10, v2, 124, 0, v37);
          }
          v95 = v40 != 0;
          if ( strcmp(v7, v97 + 28044) && strcmp(v7, (const char *)&off_648DDC) )
            goto LABEL_108;
        }
        else
        {
          if ( strcmp(v7, v97 + 28044) )
            goto LABEL_101;
          v95 = 0;
          v98 = "a";
        }
        memset(v55, 0, sizeof(v55));
        if ( v91 )
          v99 = v91;
        else
          v99 = "1";
        if ( v92 )
          v91 = v92;
        else
          v91 = "0";
        if ( v93 )
          v92 = v93;
        else
          v92 = "all";
        if ( v94 )
        {
          v93 = v94;
          if ( v3 )
          {
LABEL_93:
            if ( !v4 )
              v4 = "OFF";
            strlcpy(v55, v4, 1024);
            if ( !strcmp(v7, v97 + 28044) )
            {
              v9 = check_rule_num_limit(a1, 12, (int)(v98 + 26668), 60, s, 0x100u);
              if ( (int)v9 > 0 )
                goto LABEL_104;
            }
            if ( get_time_group(v4, v55, 1024) )
              strlcpy(v55, v4, 1024);
            v41 = v99;
            v57 = "hixzddos_add.sh";
            v61 = v92;
            v62 = v93;
            v58 = v2;
            v59 = v99;
            v60 = v91;
            v63 = v3;
            v64 = (char *)v55;
            v65 = (char *)v55;
            v66 = 0;
            eval(&v57, 0, 0, 0);
            sprintf((char *)v36, "%s|%s|%s|%s|%s|%s|%s<", v2, v41, v91, v92, v93, v3, v4);
            if ( !v95 )
            {
              jhl_parm_get(v98 + 26668, v37, 102400);
              if ( !strcmp(v37, " ") )
                *v37 = 0;
            }
            strcat(v37, (char *)v36);
            goto LABEL_100;
          }
        }
        else
        {
          v93 = "50";
          if ( v3 )
            goto LABEL_93;
        }
        v3 = "1";
        goto LABEL_93;
      }
      v49 = *(unsigned __int8 *)(a1 + 210102);
      v50 = (int)&unk_6442E4;
      v51 = 12;
    }
    else
    {
      v49 = *(unsigned __int8 *)(a1 + 210102);
      v50 = 102400;
      v51 = 4;
    }
    v52 = (const char *)_GET_LANG_TEXT(v51, v49, v50);
    v9 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v52);
    if ( v9 >= 0x100 )
      v9 = 255;
    goto LABEL_104;
  }
  v94 = httpd_get_parm(a1, "def_max");
  v11 = httpd_get_parm(a1, "def_time");
  v12 = httpd_get_parm(a1, "def_tcp_max");
  v95 = (int)httpd_get_parm(a1, "def_tcp_time");
  v96 = httpd_get_parm(a1, "def_udp_max");
  v97 = httpd_get_parm(a1, "def_udp_time");
  v98 = httpd_get_parm(a1, "def_icmp_max");
  v99 = httpd_get_parm(a1, "def_icmp_time");
  v13 = httpd_get_parm(a1, "def_other_max");
  v14 = httpd_get_parm(a1, "def_other_time");
  v15 = httpd_get_parm(a1, "maclist");
  v92 = "a";
  v100 = httpd_get_parm(a1, "reconn_en");
  v93 = "a";
  v101 = httpd_get_parm(a1, "reconn_limit");
  v91 = httpd_get_parm(a1, "drop_broadcast");
  v16 = httpd_get_parm(a1, "drop_foreign_ip");
  memset(s, 0, sizeof(s));
  v102 = "a";
  memset(v55, 0, 0x100u);
  v17 = jhl_nv_get_def("hixz3");
  strlcpy(s, v17, 256);
  split_string(s, 60, &v76, 15);
  v19 = v94;
  if ( !v94 || !strcmp(v77, v94) )
  {
    v20 = 0;
  }
  else
  {
    v77 = v19;
    v20 = 1;
  }
  if ( v11 && strcmp(v78, v11) )
  {
    v78 = v11;
    v20 = 1;
  }
  if ( v12 && strcmp(v80, v12) )
  {
    v80 = v12;
    v20 = 1;
  }
  v21 = (char *)v95;
  if ( v95 && strcmp(v81, (const char *)v95) )
  {
    v81 = v21;
    v20 = 1;
  }
  v22 = v96;
  if ( v96 && strcmp(v83, v96) )
  {
    v83 = v22;
    v20 = 1;
  }
  v23 = v97;
  if ( v97 && strcmp(v84, v97) )
  {
    v84 = v23;
    v20 = 1;
  }
  v24 = v98;
  if ( v98 && strcmp(v86, v98) )
  {
    v86 = v24;
    v20 = 1;
  }
  v25 = v99;
  if ( v99 && strcmp(v87, v99) )
  {
    v87 = v25;
    v20 = 1;
  }
  if ( v13 && strcmp(v89, v13) )
  {
    v89 = v13;
    v26 = v90;
    if ( !v14 || !strcmp(v90, v14) )
      goto LABEL_39;
    v90 = v14;
    goto LABEL_38;
  }
  if ( v14 && strcmp(v90, v14) )
  {
    v13 = v89;
    v90 = v14;
LABEL_38:
    v26 = v14;
    goto LABEL_39;
  }
  if ( !v20 )
    goto LABEL_40;
  v13 = v89;
  v26 = v90;
LABEL_39:
  v54 = v26;
  v20 = 1;
  sprintf(
    (char *)v55,
    "%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s",
    v76,
    v77,
    v78,
    v79,
    v80,
    v81,
    v82,
    v83,
    v84,
    v85,
    v86,
    v87,
    v88,
    v13,
    v54);
  nvram_set("hixz3", v55);
  v57 = "wys";
  v58 = "ctrule";
  v59 = "defset";
  v60 = v76;
  v61 = v77;
  v62 = v78;
  v63 = v79;
  v64 = v80;
  v65 = v81;
  v66 = v82;
  v67 = v83;
  v68 = v84;
  v69 = v85;
  v70 = v86;
  v71 = v87;
  v72 = v88;
  v73 = v89;
  v75 = 0;
  v74 = v90;
  eval(&v57, 0, 0, 0);
LABEL_40:
  if ( v15 )
  {
    v27 = (const char *)nvram_get("ddos_maclist");
    if ( !v27 || strcmp(v27, v15) )
    {
      nvram_set("ddos_maclist", v15);
      v57 = "wys";
      v58 = "ddos";
      v59 = "mac_set";
      v60 = v15;
      v61 = 0;
      eval(&v57, 0, 0, 0);
      v20 = 1;
    }
  }
  if ( v100 )
  {
    v28 = v101;
    if ( v101 )
    {
      v29 = v100;
      nvram_set("ddos_wan_reconn_en", v100);
      nvram_set("ddos_wan_reconn_limit", v28);
      v61 = v29;
      v57 = "wys";
      v58 = "ddos";
      v59 = "wan_attack";
      v60 = "set";
      v62 = v28;
      v63 = 0;
      eval(&v57, 0, 0, 0);
      v20 = 1;
    }
  }
  v30 = v91;
  if ( v91 )
  {
    v31 = (const char *)nvram_get(v92 + 26740);
    if ( v31 && !strcmp(v31, v30) )
    {
      v32 = 0;
      if ( !v16 )
        goto LABEL_57;
    }
    else
    {
      nvram_set(v92 + 26740, v91);
      v20 = 1;
      if ( !v16 )
        goto LABEL_55;
      v32 = 1;
    }
  }
  else
  {
    v32 = 0;
    if ( !v16 )
      goto LABEL_57;
  }
  v33 = (const char *)nvram_get(v93 + 26756);
  if ( v33 && !strcmp(v33, v16) )
  {
    if ( !v32 )
      goto LABEL_57;
    goto LABEL_56;
  }
  nvram_set(v93 + 26756, v16);
LABEL_55:
  v20 = 1;
LABEL_56:
  jhl_setwanxx();
LABEL_57:
  if ( v20 )
    jhl_parm_commit(v18);
  return ddos_data(a1);
}
// 46217C: variable 'v18' is possibly undefined
// 46224C: variable 'v35' is possibly undefined
// 462258: variable 'v34' is possibly undefined
// 462680: variable 'v42' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A82B8: using guessed type int jhl_setwanxx(void);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

