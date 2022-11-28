int __fastcall sub_47A918(int a1)
{
  char *v2; // $fp
  char *v3; // $s5
  char *v4; // $s7
  char *v5; // $s6
  char *v6; // $s2
  int v7; // $a2
  int v8; // $a1
  const char *v9; // $v0
  unsigned int v10; // $a2
  size_t v12; // $v0
  size_t v13; // $v0
  size_t v14; // $v0
  size_t v15; // $v0
  size_t v16; // $v0
  size_t v17; // $v0
  size_t v18; // $v0
  size_t v19; // $v0
  int v20; // $s5
  int v21; // $a0
  char *v22; // $a1
  const char *v23; // $v0
  int v24; // $s2
  _DWORD *v25; // $s2
  const char *v26; // $s4
  size_t v27; // $v0
  size_t v28; // $v0
  unsigned int v29; // $v0
  int v30; // $a1
  char *v31; // $a2
  int v32; // $a0
  char *v33; // $v0
  char *v34; // $s2
  const char *v35; // $v0
  char *v36; // $v1
  int v37; // $t0
  int v38; // $a3
  int v39; // $a2
  int v40; // $a1
  int v41; // $s5
  int v42; // $v0
  int v43; // $s6
  int v44; // $a0
  int v45; // $v1
  unsigned __int16 v46; // $s4
  int v47; // $s2
  _DWORD *v48; // $fp
  char *v49; // $v0
  char *v50; // $s4
  int v51; // $s0
  int v52; // $s2
  const char *v53; // $s0
  size_t v54; // $v0
  size_t v55; // $v0
  const char *v56; // $s0
  size_t v57; // $v0
  size_t v58; // $v0
  _DWORD *v59; // $s1
  int v60; // $s3
  int v61; // $s2
  _BOOL4 v62; // $v1
  unsigned int v63; // $v0
  unsigned int v64; // $v0
  const char *v65; // $a2
  int v66; // $s2
  _BYTE *v67; // $a1
  int *v68; // $v1
  int v69; // $fp
  int v70; // $t0
  _DWORD v71[1024]; // [sp+58h] [-3560h] BYREF
  int v72[1024]; // [sp+1058h] [-2560h] BYREF
  char v73[1024]; // [sp+2058h] [-1560h] BYREF
  char v74[1024]; // [sp+2458h] [-1160h] BYREF
  char v75[1024]; // [sp+2858h] [-D60h] BYREF
  char v76[1024]; // [sp+2C58h] [-960h] BYREF
  char v77[1024]; // [sp+3058h] [-560h] BYREF
  char v78[256]; // [sp+3458h] [-160h] BYREF
  int v79[2]; // [sp+3558h] [-60h] BYREF
  char *v80; // [sp+3560h] [-58h]
  char *v81; // [sp+3564h] [-54h]
  char *v82; // [sp+3568h] [-50h]
  int v83; // [sp+356Ch] [-4Ch]
  char *v84; // [sp+3570h] [-48h]
  char *v85; // [sp+3574h] [-44h]
  char *v86; // [sp+3578h] [-40h]
  char *v87; // [sp+357Ch] [-3Ch]
  char *v88; // [sp+3580h] [-38h]
  char *v89; // [sp+3584h] [-34h]
  char *v90; // [sp+3588h] [-30h]
  char *v91; // [sp+358Ch] [-2Ch]
  char *v92; // [sp+3590h] [-28h]
  char *v93; // [sp+3594h] [-24h]
  char *v94; // [sp+3598h] [-20h]
  char *v95; // [sp+359Ch] [-1Ch]
  char *v96; // [sp+35A0h] [-18h]
  char *v97; // [sp+35A4h] [-14h]
  char *v98; // [sp+35A8h] [-10h]
  char *v99; // [sp+35ACh] [-Ch]
  char *v100; // [sp+35B0h] [-8h]
  int v101; // [sp+35E0h] [+28h]

  memset(v77, 0, sizeof(v77));
  v80 = v76;
  memset(v76, 0, sizeof(v76));
  v81 = v75;
  memset(v75, 0, sizeof(v75));
  v82 = v74;
  memset(v74, 0, sizeof(v74));
  memset(v73, 0, sizeof(v73));
  v85 = httpd_get_parm(a1, "id");
  v2 = httpd_get_parm(a1, "user");
  v99 = httpd_get_parm(a1, "all_users");
  v100 = httpd_get_parm(a1, "all_mems");
  v3 = httpd_get_parm(a1, "old_user");
  v4 = httpd_get_parm(a1, (char *)&off_649194);
  v86 = httpd_get_parm(a1, "ip_start");
  v87 = httpd_get_parm(a1, "ip_end");
  v84 = httpd_get_parm(a1, (char *)&off_646724);
  v88 = httpd_get_parm(a1, "state");
  v90 = httpd_get_parm(a1, (char *)&off_64918C);
  v91 = httpd_get_parm(a1, "ddate");
  v5 = httpd_get_parm(a1, "mem");
  v89 = httpd_get_parm(a1, "num");
  v92 = httpd_get_parm(a1, "speed_up");
  v93 = httpd_get_parm(a1, "speed_down");
  v94 = httpd_get_parm(a1, "speed_mode");
  v95 = httpd_get_parm(a1, "mod_pwd");
  v96 = httpd_get_parm(a1, "vlan");
  v97 = httpd_get_parm(a1, "vlan2");
  v98 = httpd_get_parm(a1, "group");
  v83 = httpd_get_json_parm(a1, (int)"list");
  v6 = httpd_get_parm(a1, "opt");
  if ( nvram_match_def("jf_en", "1") && sq_file_get_state_new("wys_jf") || nvram_match_def("billing_en", "1") )
  {
    v8 = *(unsigned __int8 *)(a1 + 210102);
    if ( *(_BYTE *)(a1 + 210100) != 2 )
    {
      v9 = (const char *)_GET_LANG_TEXT(74, v8, v7);
      goto LABEL_5;
    }
    v23 = (const char *)_GET_LANG_TEXT(74, v8, v7);
LABEL_30:
    v10 = snprintf(v78, 256, "{\"err\":\"%s\"}", v23);
    if ( v10 < 0x100 )
      return httpd_cgi_ret(a1, v78, v10, 4);
    goto LABEL_31;
  }
  if ( *(_BYTE *)(a1 + 210100) == 2 )
  {
    if ( v2 )
      strlcpy(v77, v2, 1024);
    if ( v4 )
      strlcpy(v80, v4, 1024);
    if ( v5 )
      strlcpy(v81, v5, 1024);
    if ( v3 )
      strlcpy(v82, v3, 1024);
  }
  else
  {
    if ( v2 )
    {
      memset(v73, 0, sizeof(v73));
      v12 = strlen(v2);
      base64_decode(v2, v73, v12);
      v13 = strlen(v73);
      str_to_gb2312(v73, v13, v77, 1024);
    }
    if ( v4 )
    {
      memset(v73, 0, sizeof(v73));
      v14 = strlen(v4);
      base64_decode(v4, v73, v14);
      v15 = strlen(v73);
      str_to_gb2312(v73, v15, v80, 1024);
    }
    if ( v5 )
    {
      memset(v73, 0, sizeof(v73));
      v16 = strlen(v5);
      base64_decode(v5, v73, v16);
      v17 = strlen(v73);
      str_to_gb2312(v73, v17, v81, 1024);
    }
    if ( v3 )
    {
      memset(v73, 0, sizeof(v73));
      v18 = strlen(v3);
      base64_decode(v3, v73, v18);
      v19 = strlen(v73);
      str_to_gb2312(v73, v19, v82, 1024);
    }
  }
  if ( !v6 )
    goto LABEL_69;
  v20 = strcmp(v6, (const char *)&off_646D8C);
  if ( v20
    && strcmp(v6, (const char *)&off_648DDC)
    && strcmp(v6, "del")
    && strcmp(v6, "delall")
    && strcmp(v6, "mod2")
    && strcmp(v6, "lock") )
  {
    if ( strcmp(v6, "deltime") )
    {
      if ( strcmp(v6, "mod_all") )
      {
        if ( !strcmp(v6, "hide") )
          goto LABEL_27;
LABEL_69:
        v30 = *(unsigned __int8 *)(a1 + 210102);
        v31 = "not opt";
        if ( *(_BYTE *)(a1 + 210100) != 2 )
        {
LABEL_70:
          v32 = 12;
          goto LABEL_71;
        }
        goto LABEL_87;
      }
      if ( !strcmp(v6, "hide") )
      {
LABEL_27:
        v22 = httpd_get_parm(a1, "hide_nouse");
        if ( v22 )
          nvram_set("user_hide_nouse", v22);
        goto LABEL_56;
      }
      goto LABEL_35;
    }
    if ( !strcmp(v6, "hide") )
      goto LABEL_27;
LABEL_51:
    memset(v71, 0, 0x100u);
    v34 = httpd_get_parm(a1, "del_status");
    v33 = httpd_get_parm(a1, "del_time");
    if ( !v34 )
      v34 = "0";
    if ( !v33 )
      v33 = "0-6;00:01";
    snprintf((char *)v71, 255, "%s|%s", v34, v33);
    nvram_set("user_deltime", v71);
    start_user_deltime();
    goto LABEL_56;
  }
  if ( !strcmp(v6, "hide") )
    goto LABEL_27;
  if ( !strcmp(v6, "deltime") )
    goto LABEL_51;
  if ( !strcmp(v6, "lock") )
  {
    user_lock_asp(a1);
    goto LABEL_56;
  }
LABEL_35:
  if ( !strcmp(v6, "delall") )
  {
    v29 = user_delall(&off_649144, v85);
    if ( v29 != -1 )
    {
      if ( !v29 )
        goto LABEL_56;
      v45 = a1 + 196608;
      if ( *(_BYTE *)(a1 + 210100) != 2 )
      {
        v30 = *(unsigned __int8 *)(a1 + 210102);
        if ( v29 >= 0x33 || (v31 = (char *)jhlret_err_str[v29]) == 0 )
          v31 = "not find err!";
        v32 = 3;
        goto LABEL_71;
      }
      goto LABEL_135;
    }
    goto LABEL_129;
  }
  if ( strcmp(v6, "del") )
  {
    if ( v74[0] && !strcmp(v6, "mod2") )
    {
      v29 = user_del(v82);
      if ( v29 == -1 )
        goto LABEL_129;
      if ( v29 )
        goto LABEL_145;
      v20 = strcmp(v6, (const char *)&off_646D8C);
    }
    if ( !v20 || !strcmp(v6, (const char *)&off_648DDC) || !strcmp(v6, "mod2") )
    {
      if ( !v77[0] && strcmp(v6, "mod_all") )
      {
        v30 = *(unsigned __int8 *)(a1 + 210102);
        v31 = "not user";
        if ( *(_BYTE *)(a1 + 210100) != 2 )
          goto LABEL_70;
        v44 = 12;
        goto LABEL_88;
      }
    }
    else if ( strcmp(v6, "mod_all") )
    {
      goto LABEL_56;
    }
    v41 = 0;
    if ( v86 )
      v41 = get_ip_from_str(v86);
    if ( v87 && (v42 = get_ip_from_str(v87), (v43 = v42) != 0) )
    {
      if ( !v41 )
        v41 = v42;
    }
    else
    {
      v43 = v41;
    }
    if ( v84 )
    {
      if ( StrToMac(v84, v79) )
      {
        v30 = *(unsigned __int8 *)(a1 + 210102);
        v31 = (char *)&unk_646720;
        if ( *(_BYTE *)(a1 + 210100) != 2 )
          goto LABEL_70;
LABEL_87:
        v44 = 12;
LABEL_88:
        v23 = (const char *)_GET_LANG_TEXT(v44, v30, v31);
        goto LABEL_30;
      }
    }
    else
    {
      v79[0] = 0;
      v79[1] = 0;
    }
    if ( !v88 )
    {
      v30 = *(unsigned __int8 *)(a1 + 210102);
      v31 = (char *)&unk_64917C;
      if ( *(_BYTE *)(a1 + 210100) != 2 )
        goto LABEL_70;
      v44 = 12;
      goto LABEL_88;
    }
    if ( !v90 )
    {
      v30 = *(unsigned __int8 *)(a1 + 210102);
      v31 = (char *)&unk_649188;
      if ( *(_BYTE *)(a1 + 210100) != 2 )
        goto LABEL_70;
      v44 = 12;
      goto LABEL_88;
    }
    if ( !v91 )
      v91 = "0";
    if ( !v89 )
      v89 = "1";
    v46 = J_atoi(v88);
    v84 = (char *)J_atoi(v90);
    v82 = (char *)J_atoi(v91);
    if ( !strcmp(v6, (const char *)&off_646D8C) || !strcmp(v6, "mod2") )
    {
      if ( !v76[0] )
      {
        v30 = *(unsigned __int8 *)(a1 + 210102);
        v31 = (char *)&unk_649190;
        if ( *(_BYTE *)(a1 + 210100) != 2 )
          goto LABEL_70;
        v44 = 12;
        goto LABEL_88;
      }
      v29 = user_add(
              v46,
              (unsigned __int8)v84,
              v77,
              v80,
              v41,
              v43,
              v79,
              v82,
              v81,
              v89,
              v92,
              v93,
              v94,
              v95,
              0,
              0,
              v96,
              v97,
              v98);
    }
    else
    {
      if ( !strcmp(v6, "mod_all") )
      {
        if ( v99 && v100 && *(_BYTE *)(a1 + 210100) == 2 )
        {
          memset(v72, 0, sizeof(v72));
          memset(v71, 0, sizeof(v71));
          v66 = split_string(v99, 44, v72, 1024);
          split_string(v100, 44, v71, 1024);
          if ( v66 <= 0 )
            goto LABEL_56;
          v67 = (_BYTE *)v72[0];
          if ( !v72[0] || !*(_BYTE *)v72[0] )
            goto LABEL_56;
          v83 = (unsigned __int8)v84;
          v68 = &v72[1];
          v69 = 0;
          v70 = -1;
          while ( 1 )
          {
            v84 = (char *)v70;
            v85 = (char *)v68;
            strlcpy(v77, v67, 1024);
            strlcpy(v81, v71[v69], 1024);
            v63 = user_mod(v46, v83, v77, v80, v41, v43, v79, v82, v81, v89, v92, v93, v94, v95, v96, v97, v98);
            v70 = (int)v84;
            ++v69;
            if ( (char *)v63 == v84 )
              goto LABEL_153;
            if ( v63 )
            {
              v62 = v63 < 0x33;
LABEL_162:
              v64 = v63;
              if ( !v62 || (v65 = (const char *)jhlret_err_str[v64]) == 0 )
                v65 = "not find err!";
              v10 = sprintf(v78, "{\"err\":\"%s\"}", v65);
              return httpd_cgi_ret(a1, v78, v10, 4);
            }
            if ( v66 != v69 )
            {
              v67 = *(_BYTE **)v85;
              v68 = (int *)(v85 + 4);
              if ( *(_DWORD *)v85 )
              {
                if ( *v67 )
                  continue;
              }
            }
            goto LABEL_56;
          }
        }
        if ( !v83 )
          goto LABEL_103;
        v47 = v83;
        if ( !cJSON_IsArray(v83) )
          goto LABEL_103;
        v48 = *(_DWORD **)(v47 + 8);
        if ( !v48 )
          goto LABEL_56;
        v101 = a1;
        v83 = (int)"u";
        v85 = "m";
        v84 = (char *)(unsigned __int8)v84;
        v49 = (char *)v46;
        v50 = v81;
        v86 = v49;
        while ( 1 )
        {
          v51 = cJSON_GetObjectItem(v48, v83);
          v52 = cJSON_GetObjectItem(v48, v85);
          if ( v51 )
          {
            memset(v77, 0, sizeof(v77));
            memset(v73, 0, sizeof(v73));
            v53 = *(const char **)(v51 + 16);
            v54 = strlen(v53);
            base64_decode(v53, v73, v54);
            v55 = strlen(v73);
            str_to_gb2312(v73, v55, v77, 1024);
            memset(v50, 0, 0x400u);
            if ( v52 )
            {
              memset(v73, 0, sizeof(v73));
              v56 = *(const char **)(v52 + 16);
              v57 = strlen(v56);
              base64_decode(v56, v73, v57);
              v58 = strlen(v73);
              str_to_gb2312(v73, v58, v50, 1024);
            }
            v29 = user_mod(v86, v84, v77, v80, v41, v43, v79, v82, v50, v89, v92, v93, v94, v95, v96, v97, v98);
            if ( v29 == -1 )
            {
              a1 = v101;
              goto LABEL_48;
            }
            v21 = 196608;
            if ( v29 )
              break;
          }
          v48 = (_DWORD *)*v48;
          if ( !v48 )
          {
            a1 = v101;
            goto LABEL_56;
          }
        }
        a1 = v101;
LABEL_139:
        v30 = *(unsigned __int8 *)(a1 + 210102);
        if ( v29 >= 0x33 )
          goto LABEL_147;
LABEL_140:
        v31 = (char *)jhlret_err_str[v29];
        if ( v31 )
        {
LABEL_141:
          v32 = 3;
          goto LABEL_71;
        }
LABEL_147:
        v31 = "not find err!";
        goto LABEL_141;
      }
      v29 = user_mod(
              v46,
              (unsigned __int8)v84,
              v77,
              v80,
              v41,
              v43,
              v79,
              v82,
              v81,
              v89,
              v92,
              v93,
              v94,
              v95,
              v96,
              v97,
              v98);
    }
    if ( v29 != -1 )
    {
      if ( !v29 )
        goto LABEL_56;
LABEL_145:
      v45 = a1 + 196608;
      if ( *(_BYTE *)(a1 + 210100) != 2 )
      {
        v30 = *(unsigned __int8 *)(a1 + 210102);
        if ( v29 >= 0x33 )
          goto LABEL_147;
        goto LABEL_140;
      }
LABEL_135:
      v30 = *(unsigned __int8 *)(v45 + 13494);
      if ( v29 >= 0x33 || (v31 = (char *)jhlret_err_str[v29]) == 0 )
        v31 = "not find err!";
      v44 = 3;
      goto LABEL_88;
    }
LABEL_129:
    v30 = *(unsigned __int8 *)(a1 + 210102);
    v31 = "";
    if ( *(_BYTE *)(a1 + 210100) == 2 )
    {
      v44 = 3;
      goto LABEL_88;
    }
LABEL_49:
    v32 = 3;
LABEL_71:
    v9 = (const char *)_GET_LANG_TEXT(v32, v30, v31);
LABEL_5:
    v10 = snprintf(v78, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 < 0x100 )
      return httpd_cgi_ret(a1, v78, v10, 4);
LABEL_31:
    v10 = 255;
    return httpd_cgi_ret(a1, v78, v10, 4);
  }
  if ( v77[0] && *(_BYTE *)(a1 + 210100) == 2 )
  {
    v59 = v71;
    v60 = split_string(v77, 44, v71, 512);
    if ( v60 <= 0 )
      goto LABEL_56;
    v61 = 0;
    while ( 1 )
    {
      ++v61;
      v63 = user_del(*v59);
      if ( v63 == -1 )
        break;
      v62 = v63 < 0x33;
      if ( v63 )
        goto LABEL_162;
      ++v59;
      if ( v60 == v61 )
        goto LABEL_56;
    }
LABEL_153:
    strcpy(v78, "{\"err\":\"set_opt false!\"}");
    v10 = 24;
    return httpd_cgi_ret(a1, v78, v10, 4);
  }
  if ( !v83 || (v24 = v83, !cJSON_IsArray(v83)) )
  {
LABEL_103:
    v30 = *(unsigned __int8 *)(a1 + 210102);
    v31 = (char *)&unk_649164;
    v32 = 12;
    goto LABEL_71;
  }
  v25 = *(_DWORD **)(v24 + 8);
  if ( v25 && v25[4] )
  {
    while ( 1 )
    {
      memset(v77, 0, sizeof(v77));
      memset(v73, 0, sizeof(v73));
      v26 = (const char *)v25[4];
      v27 = strlen(v26);
      base64_decode(v26, v73, v27);
      v28 = strlen(v73);
      str_to_gb2312(v73, v28, v77, 1024);
      v29 = user_del(v77);
      if ( v29 == -1 )
        break;
      v21 = 196608;
      if ( v29 )
        goto LABEL_139;
      v25 = (_DWORD *)*v25;
      if ( !v25 || !v25[4] )
        goto LABEL_56;
    }
LABEL_48:
    v30 = *(unsigned __int8 *)(a1 + 210102);
    v31 = "";
    goto LABEL_49;
  }
LABEL_56:
  jhl_parm_commit(v21);
  if ( *(_BYTE *)(a1 + 210100) == 2 )
    return user_data(a1);
  v35 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v36 = v78;
  do
  {
    v37 = *(_DWORD *)v35;
    v38 = *((_DWORD *)v35 + 1);
    v39 = *((_DWORD *)v35 + 2);
    v40 = *((_DWORD *)v35 + 3);
    v35 += 16;
    *(_DWORD *)v36 = v37;
    *((_DWORD *)v36 + 1) = v38;
    *((_DWORD *)v36 + 2) = v39;
    *((_DWORD *)v36 + 3) = v40;
    v36 += 16;
  }
  while ( v35 != "}" );
  *(_WORD *)v36 = *(_WORD *)v35;
  return httpd_cgi_ret(a1, v78, 33, 4);
}
// 47ACD8: variable 'v7' is possibly undefined
// 47B444: variable 'v21' is possibly undefined
// 646724: using guessed type void *off_646724;
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 649144: using guessed type void *off_649144;
// 64918C: using guessed type void *off_64918C;
// 649194: using guessed type char *off_649194;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81CC: using guessed type int __fastcall base64_decode(_DWORD, _DWORD, _DWORD);
// 6A82A0: using guessed type int __fastcall user_delall(_DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84DC: using guessed type int __fastcall user_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A85EC: using guessed type int __fastcall StrToMac(_DWORD, _DWORD);
// 6A8624: using guessed type int start_user_deltime(void);
// 6A8704: using guessed type int __fastcall user_del(_DWORD);
// 6A8748: using guessed type int __fastcall get_ip_from_str(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8848: using guessed type int __fastcall sq_file_get_state_new(_DWORD);
// 6A88A4: using guessed type int __fastcall str_to_gb2312(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A88D8: using guessed type int __fastcall user_mod(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

