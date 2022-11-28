int __fastcall sub_476A24(int a1)
{
  char *v2; // $s1
  char *v3; // $fp
  char *v4; // $v0
  char *v5; // $s7
  char *v6; // $s5
  char *v7; // $s6
  char *v8; // $s4
  char *v9; // $v0
  char *v10; // $v0
  char *v11; // $s2
  char v12; // $s3
  int v13; // $s3
  const char *v14; // $v0
  int v15; // $a2
  int v16; // $v0
  char *v17; // $s3
  int v18; // $a2
  char *v19; // $a1
  const char *v20; // $s3
  const char *v21; // $v0
  const char *v22; // $s3
  const char *v23; // $v0
  const char *v24; // $s3
  const char *v25; // $v0
  const char *v26; // $s3
  const char *v27; // $v0
  const char *v28; // $s3
  const char *v29; // $v0
  const char *v30; // $s3
  const char *v31; // $v0
  const char *v32; // $s3
  const char *v33; // $v0
  const char *v34; // $v0
  int v35; // $s3
  const char *v36; // $v0
  const char *v37; // $s2
  size_t v38; // $v0
  const char *v39; // $s2
  size_t v40; // $v0
  const char *v41; // $v0
  const char *v42; // $v0
  int v43; // $s1
  const char *v44; // $v0
  const char *v45; // $v0
  int v46; // $a0
  char *v47; // $v1
  const char *v48; // $v0
  int v49; // $t0
  int v50; // $a3
  int v51; // $a2
  int v52; // $a1
  int v54; // $a2
  const char *v55; // $v0
  unsigned int v56; // $v0
  const char *v57; // $v0
  char *v58; // $s2
  char *v59; // $s3
  char *v60; // $s2
  char v61[1024]; // [sp+20h] [-EB0h] BYREF
  char v62[1024]; // [sp+420h] [-AB0h] BYREF
  char v63[1024]; // [sp+820h] [-6B0h] BYREF
  char v64[256]; // [sp+C20h] [-2B0h] BYREF
  char v65[256]; // [sp+D20h] [-1B0h] BYREF
  int v66[8]; // [sp+E20h] [-B0h] BYREF
  char *v67; // [sp+E40h] [-90h]
  char *str; // [sp+E44h] [-8Ch]
  char *v69; // [sp+E48h] [-88h]
  const char *v70; // [sp+E4Ch] [-84h]
  char *v71; // [sp+E50h] [-80h]
  char *v72; // [sp+E54h] [-7Ch]
  char *v73; // [sp+E58h] [-78h]
  char *v74; // [sp+E5Ch] [-74h]
  char *v75; // [sp+E60h] [-70h]
  char *v76; // [sp+E64h] [-6Ch]
  char *v77; // [sp+E68h] [-68h]
  char *v78; // [sp+E6Ch] [-64h]
  char *v79; // [sp+E70h] [-60h]
  char *v80; // [sp+E74h] [-5Ch]
  void *s; // [sp+E78h] [-58h]
  char *v82; // [sp+E7Ch] [-54h]
  char *v83; // [sp+E80h] [-50h]
  char *v84; // [sp+E84h] [-4Ch]
  char *v85; // [sp+E88h] [-48h]
  char *v86; // [sp+E8Ch] [-44h]
  char *v87; // [sp+E90h] [-40h]
  char *v88; // [sp+E94h] [-3Ch]
  char *v89; // [sp+E98h] [-38h]
  char *v90; // [sp+E9Ch] [-34h]
  char *v91; // [sp+EA0h] [-30h]
  char *v92; // [sp+EA4h] [-2Ch]
  char *v93; // [sp+EA8h] [-28h]
  char *v94; // [sp+EACh] [-24h]
  char *v95; // [sp+EB0h] [-20h]
  char *v96; // [sp+EB4h] [-1Ch]
  char *v97; // [sp+EB8h] [-18h]
  char *v98; // [sp+EBCh] [-14h]
  char *v99; // [sp+EC0h] [-10h]
  char *v100; // [sp+EC4h] [-Ch]
  char *v101; // [sp+EC8h] [-8h]
  char *v102; // [sp+ECCh] [-4h]

  str = v63;
  memset(v63, 0, sizeof(v63));
  v80 = v65;
  memset(v65, 0, sizeof(v65));
  s = v62;
  memset(v62, 0, sizeof(v62));
  v2 = v61;
  memset(v61, 0, sizeof(v61));
  v3 = httpd_get_parm(a1, "type");
  v69 = httpd_get_parm(a1, "tq");
  v73 = httpd_get_parm(a1, "unline");
  v89 = httpd_get_parm(a1, (char *)&off_64D744);
  httpd_get_parm(a1, "lx");
  v97 = "a";
  v4 = httpd_get_parm(a1, "auto_type");
  v98 = "a";
  v5 = v4;
  v74 = httpd_get_parm(a1, "web_exit");
  v75 = httpd_get_parm(a1, "web_anyuser");
  v6 = httpd_get_parm(a1, "fip");
  v7 = httpd_get_parm(a1, "dns");
  v8 = httpd_get_parm(a1, "host");
  v67 = httpd_get_parm(a1, (char *)&off_646724);
  v76 = httpd_get_parm(a1, "timeout");
  v90 = httpd_get_parm(a1, "redirct_url");
  v91 = httpd_get_parm(a1, "redirct_en");
  v92 = httpd_get_parm(a1, "usblog");
  v9 = httpd_get_parm(a1, "third_url");
  v100 = "a";
  v93 = v9;
  v10 = httpd_get_parm(a1, "third_timeout");
  v101 = "a";
  v70 = v10;
  v94 = httpd_get_parm(a1, "vmiandan_checktime");
  v95 = httpd_get_parm(a1, "vmiandan_checkcount");
  v82 = httpd_get_parm(a1, "noauth_en");
  v83 = httpd_get_parm(a1, "noauth_pc");
  v84 = httpd_get_parm(a1, "noauth_ssid1");
  v85 = httpd_get_parm(a1, "noauth_ssid2");
  v86 = httpd_get_parm(a1, "noauth_ssid3");
  v87 = httpd_get_parm(a1, "noauth_ssid4");
  v88 = httpd_get_parm(a1, "noauth_ssid5");
  v72 = httpd_get_parm(a1, "mac_timeout");
  v79 = httpd_get_parm(a1, "mac_en");
  v99 = v64;
  v96 = (char *)jhl_nv_get_def("dual_lan_mode");
  memset(v64, 0, sizeof(v64));
  v11 = httpd_get_parm(a1, "js_status");
  v77 = httpd_get_parm(a1, "js_time");
  v78 = httpd_get_parm(a1, "js_value");
  if ( v3 )
  {
    v71 = "a";
    if ( !v5 )
      v5 = "0";
    v12 = J_atoi(v5);
    if ( strcmp(v3, v71 + 14076) && (v12 & 6) != 0 )
    {
      v13 = v12 & 0x10;
      goto LABEL_7;
    }
  }
  else
  {
    v71 = "a";
    if ( v5 )
    {
      v12 = J_atoi(v5);
    }
    else
    {
      v5 = "0";
      v12 = J_atoi("0");
    }
    v3 = "0";
  }
  v102 = "a";
  if ( nvram_match_def("jf_en", "1") && sq_file_get_state_new("wys_jf") || nvram_match_def("billing_en", v102 + 9340) )
  {
    v55 = (const char *)_GET_LANG_TEXT(153, *(unsigned __int8 *)(a1 + 210102), v54);
    goto LABEL_127;
  }
  if ( strcmp(v3, v71 + 14076) )
  {
    v13 = v12 & 0x10;
LABEL_7:
    if ( v13 )
      goto LABEL_12;
  }
  v66[0] = 0;
  v66[1] = 0;
  v66[2] = 0;
  v66[3] = 0;
  v66[4] = 0;
  v66[5] = 0;
  v66[6] = 0;
  v66[7] = 0;
  v14 = (const char *)nvram_get("wt_base_enable");
  if ( v14 && !strcmp(v14, "1") )
  {
    v16 = _GET_LANG_TEXT(155, *(unsigned __int8 *)(a1 + 210102), v15);
    strlcpy(v66, v16, 32);
  }
  if ( !LOBYTE(v66[0]) )
  {
LABEL_12:
    if ( !v11 )
      v11 = v71 + 14076;
    if ( !v77 )
      v77 = "0-6;00:01";
    if ( !v78 )
      v78 = "180";
    v17 = v99;
    snprintf(v99, 255, "%s|%s|%s", v11, v77, v78);
    nvram_set("user_js_mod", v17);
    start_user_jsmod();
    if ( !v8 )
      v8 = "";
    if ( !v6 )
      v6 = "";
    if ( !v67 )
      v67 = "";
    if ( !v7 )
      v7 = "";
    if ( (*v6 & 0xDF) == 0 )
      v6 = "";
    if ( (*v8 & 0xDF) == 0 )
      v8 = "";
    if ( (*v67 & 0xDF) == 0 )
      v67 = "";
    if ( (*v7 & 0xDF) == 0 )
      v7 = "";
    if ( v69 )
    {
      if ( (unsigned int)J_atoi(v69) >= 0x65 )
        v69 = "100";
    }
    else
    {
      v69 = "7";
    }
    if ( !v73 )
      v73 = v71 + 14076;
    if ( !v74 )
      v74 = v71 + 14076;
    if ( !v75 )
      v75 = v71 + 14076;
    v19 = v89;
    if ( !v89 )
      v19 = (char *)_GET_LANG_TEXT(51, *(unsigned __int8 *)(a1 + 210102), v18);
    strlcpy(v80, v19, 256);
    if ( !v76 )
      v76 = (char *)&unk_4D15F8;
    v20 = v82;
    if ( v82 )
    {
      v21 = (const char *)nvram_get("rzgl_pc_no_auth");
      if ( !v21 || strcmp(v21, v20) )
        nvram_set("rzgl_pc_no_auth", v82);
    }
    v22 = v83;
    if ( v83 )
    {
      v23 = (const char *)nvram_get("rzgl_noauth_pc");
      if ( !v23 || strcmp(v23, v22) )
        nvram_set("rzgl_noauth_pc", v83);
    }
    v24 = v84;
    if ( v84 )
    {
      v25 = (const char *)nvram_get("rzgl_noauth_ssid1");
      if ( !v25 || strcmp(v25, v24) )
        nvram_set("rzgl_noauth_ssid1", v84);
    }
    v26 = v85;
    if ( v85 )
    {
      v27 = (const char *)nvram_get("rzgl_noauth_ssid2");
      if ( !v27 || strcmp(v27, v26) )
        nvram_set("rzgl_noauth_ssid2", v85);
    }
    v28 = v86;
    if ( v86 )
    {
      v29 = (const char *)nvram_get("rzgl_noauth_ssid3");
      if ( !v29 || strcmp(v29, v28) )
        nvram_set("rzgl_noauth_ssid3", v86);
    }
    v30 = v87;
    if ( v87 )
    {
      v31 = (const char *)nvram_get("rzgl_noauth_ssid4");
      if ( !v31 || strcmp(v31, v30) )
        nvram_set("rzgl_noauth_ssid4", v87);
    }
    v32 = v88;
    if ( v88 )
    {
      v33 = (const char *)nvram_get("rzgl_noauth_ssid5");
      if ( !v33 || strcmp(v33, v32) )
        nvram_set("rzgl_noauth_ssid5", v88);
    }
    if ( !v72 )
      v72 = "24";
    if ( v79 )
    {
      v34 = (const char *)nvram_get("rzgl_mac_en");
      if ( !v34 || (v35 = 0, strcmp(v34, v79)) )
      {
        nvram_set("rzgl_mac_en", v79);
        v35 = 1;
      }
    }
    else
    {
      v35 = 0;
    }
    v36 = (const char *)nvram_get("rzgl_mac_timeout");
    if ( v36 && !strcmp(v36, v72) )
    {
      if ( !v35 )
      {
LABEL_85:
        if ( !strcmp(v96, "1") )
        {
          v72 = httpd_get_parm(a1, "sys_iface_en");
          v71 = httpd_get_parm(a1, "sys_iface_list");
          v59 = httpd_get_parm(a1, "third_iface_en");
          v60 = httpd_get_parm(a1, "third_iface_list");
          if ( v72 )
            nvram_set("webS_iface_en", v72);
          if ( v71 )
            nvram_set("webS_iface_list", v71);
          if ( v59 )
            nvram_set("webT_iface_en", v59);
          if ( v60 )
            nvram_set("webT_iface_list", v60);
        }
        if ( v70 )
        {
          if ( (unsigned int)J_atoi(v70) >= 0x79 )
            v70 = "120";
        }
        else
        {
          v70 = (const char *)&unk_4D15F8;
        }
        jhl_parm_set("rzgl_third_timeout", v70);
        v37 = v93;
        if ( v93 )
        {
          memset(v61, 0, sizeof(v61));
          memset(s, 0, 0x400u);
          v38 = strlen(v37);
          base64_decode(v37, v61, v38);
          if ( !strncmp(v61, "http://", 7u) || !strncmp(v61, "https://", 8u) )
          {
            jhl_parm_set("rzgl_third_url", v61);
          }
          else
          {
            v58 = (char *)s;
            *(_DWORD *)s = *(_DWORD *)"http://";
            strcpy(v58 + 4, "://");
            strcpy(&v62[7], v61);
            jhl_parm_set("rzgl_third_url", v58);
          }
        }
        if ( v95 )
          jhl_parm_set(v101 + 32692, v95);
        if ( v94 )
          jhl_parm_set(v100 + 32672, v94);
        if ( v91 )
          jhl_parm_set("rzgl_redirct_en", v91);
        v39 = v90;
        if ( v90 )
        {
          memset(v61, 0, sizeof(v61));
          memset(s, 0, 0x400u);
          v40 = strlen(v39);
          base64_decode(v39, v61, v40);
          if ( strncmp(v61, "http://", 7u) && strncmp(v61, "https://", 8u) )
          {
            v2 = (char *)s;
            *(_DWORD *)s = *(_DWORD *)"http://";
            strcpy(v2 + 4, "://");
            strcpy(&v62[7], v61);
          }
          jhl_parm_set("rzgl_redirct_url", v2);
        }
        jhl_parm_set("rzglType", v3);
        jhl_parm_set("rzglTq", v69);
        jhl_parm_set("rzglUnline", v73);
        jhl_parm_set("rzglMsg", v80);
        jhl_parm_set("rzglAtype", v5);
        jhl_parm_set(v97 + 32516, v74);
        jhl_parm_set(v98 + 32528, v75);
        jhl_parm_set("rzgl_web_ageing_time", v76);
        v41 = (const char *)nvram_get("rzglFip");
        if ( v41 && !strcmp(v41, v6) )
        {
          v57 = (const char *)nvram_get("rzglDns");
          if ( !v57 || (v43 = 0, strcmp(v57, v7)) )
          {
LABEL_108:
            jhl_parm_set("rzglDns", v7);
            v44 = (const char *)nvram_get("rzglHost");
            v43 = 1;
            if ( !v44 )
              goto LABEL_110;
LABEL_109:
            if ( !strcmp(v44, v8) )
            {
              v45 = (const char *)nvram_get("rzglMac");
              if ( !v45 )
                goto LABEL_112;
LABEL_111:
              if ( !strcmp(v45, v67) )
              {
LABEL_113:
                if ( v92 )
                  nvram_set("save_auth_log_usb", v92);
                start_rzgl(v43);
                restart_third_rzgl();
                jhl_parm_commit(v46);
                v47 = str;
                v48 = "{\"code\":0,\"error\":\"\",\"data\":null}";
                do
                {
                  v49 = *(_DWORD *)v48;
                  v50 = *((_DWORD *)v48 + 1);
                  v51 = *((_DWORD *)v48 + 2);
                  v52 = *((_DWORD *)v48 + 3);
                  v48 += 16;
                  *(_DWORD *)v47 = v49;
                  *((_DWORD *)v47 + 1) = v50;
                  *((_DWORD *)v47 + 2) = v51;
                  *((_DWORD *)v47 + 3) = v52;
                  v47 += 16;
                }
                while ( v48 != "}" );
                *(_WORD *)v47 = *(_WORD *)v48;
                return httpd_cgi_ret(a1, str, 33, 4);
              }
LABEL_112:
              jhl_parm_set("rzglMac", v67);
              v43 = 1;
              goto LABEL_113;
            }
LABEL_110:
            jhl_parm_set("rzglHost", v8);
            v45 = (const char *)nvram_get("rzglMac");
            v43 = 1;
            if ( !v45 )
              goto LABEL_112;
            goto LABEL_111;
          }
        }
        else
        {
          jhl_parm_set("rzglFip", v6);
          v42 = (const char *)nvram_get("rzglDns");
          if ( !v42 )
            goto LABEL_108;
          v43 = 1;
          if ( strcmp(v42, v7) )
            goto LABEL_108;
        }
        v44 = (const char *)nvram_get("rzglHost");
        if ( !v44 )
          goto LABEL_110;
        goto LABEL_109;
      }
    }
    else
    {
      nvram_set("rzgl_mac_timeout", v72);
    }
    macuser_conf_set();
    goto LABEL_85;
  }
  v55 = (const char *)_GET_LANG_TEXT(154, *(unsigned __int8 *)(a1 + 210102), v66);
LABEL_127:
  v56 = snprintf(str, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v55);
  if ( v56 >= 0x400 )
    v56 = 1023;
  return httpd_cgi_ret(a1, str, v56, 4);
}
// 476F88: variable 'v15' is possibly undefined
// 477F58: variable 'v18' is possibly undefined
// 477A3C: variable 'v46' is possibly undefined
// 477B7C: variable 'v54' is possibly undefined
// 646724: using guessed type void *off_646724;
// 64D744: using guessed type void *off_64D744;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8508: using guessed type int start_user_jsmod(void);
// 6A8514: using guessed type int restart_third_rzgl(void);
// 6A86DC: using guessed type int macuser_conf_set(void);
// 6A8848: using guessed type int __fastcall sq_file_get_state_new(_DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8978: using guessed type int __fastcall start_rzgl(_DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

