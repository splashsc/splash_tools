int __fastcall sub_488B80(int a1)
{
  char *v2; // $s3
  char *v3; // $s5
  char *v4; // $s2
  char *v5; // $s6
  int v6; // $s4
  const char *v7; // $s7
  int v8; // $a0
  const char *v9; // $v1
  char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  int v15; // $a2
  _DWORD *v16; // $fp
  int v17; // $a1
  const char *v18; // $a2
  const char *v19; // $v0
  int v20; // $v0
  char *v22; // $s2
  char *v23; // $s6
  char *v24; // $s5
  char *v25; // $s3
  int v26; // $a0
  int v27; // $t0
  int v28; // $a3
  int v29; // $a2
  int v30; // $a1
  char *v31; // $s6
  int v32; // $v0
  int v33; // $s6
  char *v34; // $s6
  const char *v35; // [sp+38h] [-32458h] BYREF
  char *v36; // [sp+3Ch] [-32454h]
  const char *v37; // [sp+40h] [-32450h]
  char *v38; // [sp+44h] [-3244Ch]
  char *v39; // [sp+48h] [-32448h]
  int v40; // [sp+4Ch] [-32444h]
  char s[102400]; // [sp+19038h] [-19458h] BYREF
  _BYTE v42[1024]; // [sp+32038h] [-458h] BYREF
  const char *v43; // [sp+32438h] [-58h] BYREF
  char *v44; // [sp+3243Ch] [-54h]
  char *v45; // [sp+32440h] [-50h]
  char *v46; // [sp+32444h] [-4Ch]
  char *v47; // [sp+32448h] [-48h]
  _BYTE *v48; // [sp+3244Ch] [-44h]
  _BYTE *v49; // [sp+32450h] [-40h]
  char *v50; // [sp+32454h] [-3Ch]
  char *v51; // [sp+32458h] [-38h]
  char *v52; // [sp+3245Ch] [-34h]
  int v53; // [sp+32460h] [-30h]
  char *v54; // [sp+32468h] [-28h]
  char *v55; // [sp+3246Ch] [-24h]
  char *v56; // [sp+32470h] [-20h]
  char *v57; // [sp+32474h] [-1Ch]
  char *v58; // [sp+32478h] [-18h]
  char *v59; // [sp+3247Ch] [-14h]
  char *v60; // [sp+32480h] [-10h]
  const char *v61; // [sp+32484h] [-Ch]
  char *v62; // [sp+32488h] [-8h]

  memset(v42, 0, sizeof(v42));
  v2 = httpd_get_parm(a1, "name");
  v60 = httpd_get_parm(a1, "old_name");
  v55 = httpd_get_parm(a1, "en");
  v54 = httpd_get_parm(a1, "ips");
  v3 = httpd_get_parm(a1, "u");
  v59 = httpd_get_parm(a1, "time");
  v56 = httpd_get_parm(a1, "act");
  v57 = httpd_get_parm(a1, "rpri");
  v58 = httpd_get_parm(a1, (char *)&off_64E034);
  v4 = httpd_get_parm(a1, "opt");
  v5 = httpd_get_parm(a1, "flag");
  v6 = httpd_get_json_parm(a1, (int)"del_list");
  if ( v5 )
    v7 = v5;
  else
    v7 = "0";
  if ( J_atoi(v7) )
    v61 = "urlfilter_add.sh";
  else
    v61 = "url_add.sh";
  if ( !v4 )
  {
LABEL_75:
    v17 = *(unsigned __int8 *)(a1 + 210102);
    v18 = "not opt";
    goto LABEL_30;
  }
  if ( strcmp(v4, (const char *)&off_646D8C) && strcmp(v4, (const char *)&off_648DDC) && strcmp(v4, "del") )
  {
    if ( strcmp(v4, (const char *)&off_64712C) )
    {
      if ( !strcmp(v4, "delall") )
      {
LABEL_11:
        v35 = "url_clean.sh";
        v36 = 0;
        eval(&v35, 0, 0, 0);
        v35 = "urlfilter_clean.sh";
        v36 = 0;
        eval(&v35, 0, 0, 0);
        LOBYTE(v35) = 0;
LABEL_12:
        jhl_parm_set("url_rules", &v35);
        jhl_parm_commit(v8);
        goto LABEL_13;
      }
      goto LABEL_75;
    }
LABEL_34:
    v22 = httpd_get_parm(a1, (char *)&off_64712C);
    v23 = httpd_get_parm(a1, "tiao");
    v24 = httpd_get_parm(a1, "tiaozhuan");
    v25 = httpd_get_parm(a1, "block");
    if ( !v22 || strcmp(v22, "0") && strcmp(v22, "1") && strcmp(v22, "2") )
    {
      v17 = *(unsigned __int8 *)(a1 + 210102);
      v18 = (const char *)&unk_647128;
      goto LABEL_30;
    }
    if ( v25 )
    {
      if ( v23 )
        goto LABEL_41;
    }
    else
    {
      v25 = "1";
      if ( v23 )
      {
LABEL_41:
        if ( v24 )
          goto LABEL_42;
        goto LABEL_83;
      }
    }
    v23 = "0";
    if ( v24 )
    {
LABEL_42:
      v36 = "url";
      v35 = "wys";
      v37 = "setdef";
      v38 = v22;
      v39 = v25;
      v40 = 0;
      eval(&v35, 0, 0, 0);
      v36 = "urlfilter";
      v35 = "wys";
      v37 = "global";
      v38 = v22;
      v39 = v25;
      v40 = 0;
      eval(&v35, 0, 0, 0);
      jhl_parm_set("urlAct", v22);
      jhl_parm_set("urlto", v23);
      jhl_parm_set("urltoz", v24);
      jhl_parm_set(&unk_64A784, v25);
      jhl_parm_commit(v26);
      v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      v10 = s;
      do
      {
        v27 = *(_DWORD *)v9;
        v28 = *((_DWORD *)v9 + 1);
        v29 = *((_DWORD *)v9 + 2);
        v30 = *((_DWORD *)v9 + 3);
        v9 += 16;
        *(_DWORD *)v10 = v27;
        *((_DWORD *)v10 + 1) = v28;
        *((_DWORD *)v10 + 2) = v29;
        *((_DWORD *)v10 + 3) = v30;
        v10 += 16;
      }
      while ( v9 != "}" );
      goto LABEL_15;
    }
LABEL_83:
    v24 = "";
    goto LABEL_42;
  }
  if ( !strcmp(v4, (const char *)&off_64712C) )
    goto LABEL_34;
  if ( !strcmp(v4, "delall") )
    goto LABEL_11;
  if ( !strcmp(v4, "del") && v6 && cJSON_IsArray(v6) )
  {
    v16 = *(_DWORD **)(v6 + 8);
    if ( !v16 )
      goto LABEL_13;
    v60 = 0;
    v54 = "urlfilter_del.sh";
    v55 = "url_rules";
    do
    {
      v43 = "url_del.sh";
      v44 = (char *)v16[4];
      v45 = 0;
      eval(&v43, 0, 0, 0);
      v43 = v54;
      v44 = (char *)v16[4];
      v45 = 0;
      eval(&v43, 0, 0, 0);
      jhl_parm_get("url_rules", s, 102400);
      if ( nvparm_del_str(s, 60, 7, v16[4], 124, 0, &v35) )
      {
        jhl_parm_set(v55, &v35);
        v60 = (char *)1;
      }
      v16 = (_DWORD *)*v16;
    }
    while ( v16 );
    goto LABEL_80;
  }
  if ( !v2 || !*v2 )
  {
    v17 = *(unsigned __int8 *)(a1 + 210102);
    v18 = (const char *)&unk_6442E4;
    goto LABEL_30;
  }
  v62 = "1\"";
  if ( strcmp(v4, (const char *)&off_648DDC) )
  {
    v33 = strcmp(v4, (const char *)&off_646D8C);
    if ( v33 )
      goto LABEL_13;
    v60 = 0;
LABEL_49:
    if ( v3 && *v3 )
    {
      if ( v33 || (v20 = check_rule_num_limit(a1, 14, (int)"url_rules", 60, s, 0x19000u), v20 <= 0) )
      {
        if ( !v54 || !*v54 )
          v54 = "not";
        if ( !v58 || !*v58 )
          v58 = "0";
        if ( !v57 || !*v57 )
          v57 = "100";
        if ( !v56 || !*v56 )
          v56 = "1";
        if ( !v55 || !*v55 )
          v55 = "1";
        if ( !v59 || !*v59 )
          v59 = "OFF";
        v34 = v59;
        sprintf(s, "%s|%s|%s|%s|%s|%s|%s|%s|%s<", v2, v55, v54, v3, v59, v58, v57, v56, v7);
        if ( get_time_group(v34, v42, 1024) )
          strlcpy(v42, v59, 1024);
        v48 = v42;
        v49 = v42;
        v43 = v61;
        v50 = v58;
        v45 = v55;
        v51 = v57;
        v44 = v2;
        v46 = v54;
        v47 = v3;
        v52 = v56;
        v53 = 0;
        eval(&v43, 0, 0, 0);
        if ( !v60 )
          jhl_parm_get("url_rules", &v35, 102400);
        strcat((char *)&v35, s);
        goto LABEL_12;
      }
LABEL_32:
      v15 = v20;
      return httpd_cgi_ret(a1, s, v15, 4);
    }
    v17 = *(unsigned __int8 *)(a1 + 210102);
    v18 = "not u";
LABEL_30:
    v19 = (const char *)_GET_LANG_TEXT(12, v17, v18);
    v20 = snprintf(s, 102400, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
    if ( (unsigned int)v20 >= 0x19000 )
      v20 = 102399;
    goto LABEL_32;
  }
  v31 = v60;
  if ( v60 )
  {
    v36 = v60;
    v35 = "url_del.sh";
    v37 = 0;
    eval(&v35, 0, 0, 0);
    v35 = "urlfilter_del.sh";
    v36 = v31;
    v37 = 0;
    eval(&v35, 0, 0, 0);
    v60 = s;
    jhl_parm_get("url_rules", s, 102400);
    v32 = nvparm_del_str(v60, 60, 7, v31, 124, 0, &v35);
  }
  else
  {
    v36 = v2;
    v35 = "url_del.sh";
    v37 = 0;
    eval(&v35, 0, 0, 0);
    v35 = "urlfilter_del.sh";
    v36 = v2;
    v37 = 0;
    eval(&v35, 0, 0, 0);
    jhl_parm_get("url_rules", s, 102400);
    v32 = nvparm_del_str(s, 60, 7, v2, 124, 0, &v35);
  }
  v60 = (char *)(v32 != 0);
  v33 = strcmp(v4, (const char *)&off_646D8C);
  if ( !v33 || !strcmp(v4, v62 - 29220) )
    goto LABEL_49;
LABEL_80:
  if ( v60 )
    goto LABEL_12;
LABEL_13:
  v9 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v10 = s;
  do
  {
    v11 = *(_DWORD *)v9;
    v12 = *((_DWORD *)v9 + 1);
    v13 = *((_DWORD *)v9 + 2);
    v14 = *((_DWORD *)v9 + 3);
    v9 += 16;
    *(_DWORD *)v10 = v11;
    *((_DWORD *)v10 + 1) = v12;
    *((_DWORD *)v10 + 2) = v13;
    *((_DWORD *)v10 + 3) = v14;
    v10 += 16;
  }
  while ( v9 != "}" );
LABEL_15:
  *(_WORD *)v10 = *(_WORD *)v9;
  v15 = 33;
  return httpd_cgi_ret(a1, s, v15, 4);
}
// 488EF8: variable 'v8' is possibly undefined
// 489450: variable 'v26' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 64E034: using guessed type int (**off_64E034)();
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

