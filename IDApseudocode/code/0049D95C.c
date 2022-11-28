int __fastcall pppoe_br_user_asp(int a1)
{
  char *v1; // $v0
  const char *v3; // $s1
  char *v4; // $fp
  char *v5; // $s5
  char *v6; // $s7
  char *v7; // $s6
  void *v8; // $v0
  void *v9; // $s3
  int v10; // $a0
  _DWORD *v11; // $s1
  unsigned int v12; // $v0
  int v13; // $a1
  char *v14; // $a2
  int v15; // $a0
  const char *v16; // $v0
  unsigned int v17; // $s2
  char *v19; // $s5
  char *v20; // $s4
  char *v21; // $s3
  char *v22; // $v0
  char *v23; // $s2
  const char *v24; // $s1
  unsigned __int8 v25; // $s6
  unsigned __int8 v26; // $s7
  unsigned __int8 v27; // $fp
  int v28; // $v0
  int v29; // $a0
  char *v30; // $v1
  const char *v31; // $v0
  int v32; // $t0
  int v33; // $a3
  int v34; // $a2
  int v35; // $a1
  int v36; // $a2
  unsigned __int8 v37; // $s5
  char *v38; // $v0
  char *v39; // $a0
  unsigned __int8 v40; // $s7
  int v41; // $v0
  char *v42; // $v0
  unsigned __int16 v43; // $s2
  bool v44; // dc
  unsigned int v45; // $v0
  int v46; // $a1
  int v47; // $a2
  int v48; // $a0
  const char *v49; // $v0
  char *v50; // $v1
  const char *v51; // $v0
  int v52; // $t0
  int v53; // $a3
  int v54; // $a2
  int v55; // $a1
  char *v56; // $v0
  char *v57; // $a0
  char v58[128]; // [sp+48h] [-B0h] BYREF
  int v59[2]; // [sp+C8h] [-30h] BYREF
  int v60; // [sp+D0h] [-28h]
  char *v61; // [sp+D4h] [-24h]
  char *v62; // [sp+D8h] [-20h]
  char *v63; // [sp+DCh] [-1Ch]
  char *v64; // [sp+E0h] [-18h]
  char *v65; // [sp+E4h] [-14h]
  char *v66; // [sp+E8h] [-10h]
  char *v67; // [sp+ECh] [-Ch]
  char *v68; // [sp+F0h] [-8h]
  char *v69; // [sp+F4h] [-4h]

  v1 = httpd_get_parm(a1, "opt");
  if ( !v1 )
    goto LABEL_72;
  v3 = v1;
  if ( strcmp(v1, (const char *)&off_64712C) )
  {
    if ( strcmp(v3, (const char *)&off_646D8C)
      && strcmp(v3, (const char *)&off_648DDC)
      && strcmp(v3, "update")
      && strcmp(v3, "del")
      && strcmp(v3, "delall") )
    {
LABEL_72:
      v46 = *(unsigned __int8 *)(a1 + 210102);
      v47 = (int)"not opt";
      v48 = 12;
      goto LABEL_73;
    }
    v64 = httpd_get_parm(a1, "en");
    v4 = httpd_get_parm(a1, "user");
    v66 = httpd_get_parm(a1, "o_user");
    v5 = httpd_get_parm(a1, "bind");
    v6 = httpd_get_parm(a1, (char *)&off_646724);
    v61 = httpd_get_parm(a1, "cdate");
    v62 = httpd_get_parm(a1, "ddate");
    v65 = httpd_get_parm(a1, "mem");
    v63 = httpd_get_parm(a1, "dev");
    v7 = httpd_get_parm(a1, "vlan");
    v67 = httpd_get_parm(a1, "name");
    v68 = httpd_get_parm(a1, (char *)&off_64C72C);
    v69 = httpd_get_parm(a1, "phone");
    v60 = httpd_get_json_parm(a1, (int)"del_list");
    _mem_malloc(0x200000, "pppoe_br_user_asp", 1835);
    v9 = v8;
    if ( !v8 )
    {
      v46 = *(unsigned __int8 *)(a1 + 210102);
      v47 = 0x200000;
      v48 = 4;
LABEL_73:
      v49 = (const char *)_GET_LANG_TEXT(v48, v46, v47);
      v17 = snprintf(v58, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v49);
      if ( v17 >= 0x80 )
        v17 = 127;
      return httpd_cgi_ret(a1, v58, v17, 4);
    }
    if ( !strcmp(v3, "delall") )
    {
      v12 = pppoe_br_user_delall();
      if ( v12 == -1 )
        goto LABEL_17;
      if ( v12 )
        goto LABEL_63;
    }
    if ( !strcmp(v3, "del") && v60 && cJSON_IsArray(v60) )
    {
      v11 = *(_DWORD **)(v60 + 8);
      if ( v11 )
      {
        v10 = v11[4];
        if ( v10 )
        {
          while ( 1 )
          {
            v12 = pppoe_br_user_del();
            if ( v12 == -1 )
              goto LABEL_17;
            v10 = 196608;
            if ( v12 )
              goto LABEL_63;
            v11 = (_DWORD *)*v11;
            if ( v11 )
            {
              v10 = v11[4];
              if ( v10 )
                continue;
            }
            break;
          }
        }
      }
LABEL_82:
      jhl_parm_commit(v10);
      v50 = v58;
      v51 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v52 = *(_DWORD *)v51;
        v53 = *((_DWORD *)v51 + 1);
        v54 = *((_DWORD *)v51 + 2);
        v55 = *((_DWORD *)v51 + 3);
        v51 += 16;
        *(_DWORD *)v50 = v52;
        *((_DWORD *)v50 + 1) = v53;
        *((_DWORD *)v50 + 2) = v54;
        *((_DWORD *)v50 + 3) = v55;
        v50 += 16;
      }
      while ( v51 != "}" );
      v17 = 33;
      *(_WORD *)v50 = *(_WORD *)v51;
      goto LABEL_22;
    }
    if ( !strcmp(v3, (const char *)&off_646D8C) )
    {
      if ( strcmp(v3, (const char *)&off_648DDC) )
        goto LABEL_36;
    }
    else if ( strcmp(v3, (const char *)&off_648DDC) )
    {
      if ( strcmp(v3, "update") )
        goto LABEL_82;
LABEL_36:
      if ( !v4 )
      {
        v13 = *(unsigned __int8 *)(a1 + 210102);
        v14 = "not user";
        v15 = 12;
        goto LABEL_19;
      }
      if ( !v5 )
        v5 = "0";
      v37 = J_atoi(v5);
      v60 = v37;
      if ( !v6 || strlen(v6) != 17 || !strcmp(v6, "00:00:00:00:00:00") || !strcmp(v6, "00-00-00-00-00-00") )
      {
        if ( v37 == 1 )
        {
LABEL_92:
          v16 = (const char *)_GET_LANG_TEXT(205, *(unsigned __int8 *)(a1 + 210102), v36);
LABEL_20:
          v17 = snprintf(v58, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v16);
          if ( v17 >= 0x80 )
            v17 = 127;
LABEL_22:
          _mem_free(v9);
          return httpd_cgi_ret(a1, v58, v17, 4);
        }
        v60 = (int)v59;
        v59[0] = 0;
        v59[1] = 0;
      }
      else
      {
        v60 = (int)v59;
        if ( StrToMac(v6, v59) )
          goto LABEL_92;
      }
      if ( !v64 )
        v64 = "1";
      if ( !v62 )
        v62 = "0";
      if ( !v61 )
        v61 = "0";
      if ( !v65 )
        v65 = " ";
      if ( !v63 )
        v63 = "1";
      if ( v7 )
      {
        v62 = (char *)J_atoi(v62);
        v38 = (char *)J_atoi(v61);
        v39 = v64;
        v64 = v38;
        v40 = J_atoi(v39);
        v41 = (unsigned __int8)J_atoi(v63);
        if ( !v41 )
          v41 = 1;
      }
      else
      {
        v62 = (char *)J_atoi(v62);
        v56 = (char *)J_atoi(v61);
        v57 = v64;
        v64 = v56;
        v40 = J_atoi(v57);
        v41 = (unsigned __int8)J_atoi(v63);
        if ( !v41 )
        {
          v61 = 0;
          v63 = (char *)1;
          v7 = "0";
LABEL_58:
          v43 = J_atoi(v7);
          if ( !strcmp(v3, (const char *)&off_646D8C) )
          {
            v12 = pppoe_br_user_add(v40, v37, v60, v63, v64, v62, v4, v65, v43, v61, v67, v68, v69);
          }
          else if ( !strcmp(v3, "update") )
          {
            v12 = pppoe_br_user_mod(1, v40, v37, v60, v63, v64, v62, v4, v4, v65, v43, v61, v67, v68, v69);
          }
          else
          {
            v12 = pppoe_br_user_mod(0, v40, v37, v60, v63, v64, v62, v66, v4, v65, v43, v61, v67, v68, v69);
          }
          if ( v12 != -1 )
          {
            v10 = 196608;
            if ( !v12 )
              goto LABEL_82;
LABEL_63:
            v13 = *(unsigned __int8 *)(a1 + 210102);
            v44 = v12 >= 0x33;
            v45 = v12;
            if ( !v44 )
            {
              v14 = (char *)jhlret_err_str[v45];
              if ( v14 )
              {
                v15 = 3;
                goto LABEL_19;
              }
            }
            v14 = "not find err!";
LABEL_18:
            v15 = 3;
LABEL_19:
            v16 = (const char *)_GET_LANG_TEXT(v15, v13, v14);
            goto LABEL_20;
          }
LABEL_17:
          v13 = *(unsigned __int8 *)(a1 + 210102);
          v14 = "";
          goto LABEL_18;
        }
        v7 = "0";
      }
      v63 = (char *)v41;
      v42 = strchr(v7, 46);
      if ( v42 )
      {
        *v42 = 0;
        LOWORD(v61) = J_atoi(v42 + 1);
        v61 = (char *)(unsigned __int16)v61;
      }
      else
      {
        v61 = 0;
      }
      goto LABEL_58;
    }
    if ( !v66 )
    {
      v13 = *(unsigned __int8 *)(a1 + 210102);
      v14 = (char *)&unk_64C730;
      v15 = 12;
      goto LABEL_19;
    }
    goto LABEL_36;
  }
  v19 = httpd_get_parm(a1, "date_expire");
  v20 = httpd_get_parm(a1, "mac_err");
  v21 = httpd_get_parm(a1, "no_exist");
  v23 = httpd_get_parm(a1, "dev_err");
  v22 = httpd_get_parm(a1, "user_time");
  v24 = v22;
  if ( v19 )
  {
    if ( v20 )
      goto LABEL_26;
  }
  else
  {
    v19 = "0";
    if ( v20 )
    {
LABEL_26:
      if ( v21 )
        goto LABEL_27;
LABEL_76:
      v21 = "0";
      if ( v23 )
        goto LABEL_28;
      goto LABEL_75;
    }
  }
  v20 = "0";
  if ( !v21 )
    goto LABEL_76;
LABEL_27:
  if ( !v23 )
LABEL_75:
    v23 = "0";
LABEL_28:
  if ( !v22 )
    v24 = "600";
  v25 = J_atoi(v19);
  v26 = J_atoi(v20);
  v27 = J_atoi(v21);
  v60 = J_atoi(v23);
  v28 = J_atoi(v24);
  pppoe_br_user_conf(v25, v26, v27, (unsigned __int8)v60, v28);
  nvram_set("pppoe_br_user_date_expire_en", v19);
  nvram_set("pppoe_br_user_mac_err_en", v20);
  nvram_set("pppoe_br_user_no_exist_en", v21);
  nvram_set("pppoe_br_user_dev_err_en", v23);
  nvram_set("pppoe_br_user_time", v24);
  jhl_parm_commit(v29);
  v30 = v58;
  v31 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v32 = *(_DWORD *)v31;
    v33 = *((_DWORD *)v31 + 1);
    v34 = *((_DWORD *)v31 + 2);
    v35 = *((_DWORD *)v31 + 3);
    v31 += 16;
    *(_DWORD *)v30 = v32;
    *((_DWORD *)v30 + 1) = v33;
    *((_DWORD *)v30 + 2) = v34;
    *((_DWORD *)v30 + 3) = v35;
    v30 += 16;
  }
  while ( v31 != "}" );
  *(_WORD *)v30 = *(_WORD *)v31;
  return httpd_cgi_ret(a1, v58, 33, 4);
}
// 49DBC4: variable 'v8' is possibly undefined
// 49DF2C: variable 'v29' is possibly undefined
// 49E400: variable 'v10' is possibly undefined
// 49E518: variable 'v36' is possibly undefined
// 646724: using guessed type void *off_646724;
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 64C72C: using guessed type void *off_64C72C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8234: using guessed type int pppoe_br_user_delall(void);
// 6A82A8: using guessed type int __fastcall pppoe_br_user_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8524: using guessed type int __fastcall pppoe_br_user_conf(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A85EC: using guessed type int __fastcall StrToMac(_DWORD, _DWORD);
// 6A8654: using guessed type int pppoe_br_user_del(void);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A8958: using guessed type int __fastcall pppoe_br_user_mod(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

