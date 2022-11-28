int __fastcall sub_46D0D0(int a1)
{
  char *v2; // $s4
  char *v3; // $s5
  char *v4; // $s6
  char *v5; // $s7
  char *v6; // $fp
  char *v7; // $s2
  int v8; // $a1
  const char *v9; // $a2
  int v10; // $a0
  int v11; // $v0
  char *v12; // $v1
  int v13; // $s3
  int v14; // $v0
  int v15; // $a0
  const char *v16; // $v0
  char *v17; // $v1
  int v18; // $t0
  int v19; // $a3
  int v20; // $a2
  int v21; // $a1
  unsigned int v22; // $a2
  char *v24; // $v0
  const char *v25; // $s3
  int v26; // $a0
  const char *v27; // $v1
  char *v28; // $v0
  int v29; // $t0
  int v30; // $a3
  int v31; // $a2
  int v32; // $a1
  const char *v33; // $v0
  int v34; // $v0
  int v35[25600]; // [sp+40h] [-32060h] BYREF
  char v36[102400]; // [sp+19040h] [-19060h] BYREF
  const char *v37; // [sp+32040h] [-60h] BYREF
  char *v38; // [sp+32044h] [-5Ch]
  char *v39; // [sp+32048h] [-58h]
  char *v40; // [sp+3204Ch] [-54h]
  char *v41; // [sp+32050h] [-50h]
  char *v42; // [sp+32054h] [-4Ch]
  char *v43; // [sp+32058h] [-48h]
  char *v44; // [sp+3205Ch] [-44h]
  char *v45; // [sp+32060h] [-40h]
  char *v46; // [sp+32064h] [-3Ch]
  char *v47; // [sp+32068h] [-38h]
  int v48; // [sp+3206Ch] [-34h]
  int v49; // [sp+32070h] [-30h]
  char *v50; // [sp+32078h] [-28h]
  char *v51; // [sp+3207Ch] [-24h]
  char *v52; // [sp+32080h] [-20h]
  char *v53; // [sp+32084h] [-1Ch]
  char *v54; // [sp+32088h] [-18h]
  char *v55; // [sp+3208Ch] [-14h]
  char *v56; // [sp+32090h] [-10h]
  int v57; // [sp+32094h] [-Ch]
  char *v58; // [sp+32098h] [-8h]

  v37 = 0;
  v38 = 0;
  v39 = 0;
  v40 = 0;
  v41 = 0;
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v51 = httpd_get_parm(a1, "name");
  v56 = httpd_get_parm(a1, "old_name");
  v50 = httpd_get_parm(a1, "en");
  v52 = httpd_get_parm(a1, "ips");
  v53 = httpd_get_parm(a1, "time");
  v54 = httpd_get_parm(a1, (char *)&off_64E034);
  v55 = httpd_get_parm(a1, "rpri");
  v2 = httpd_get_parm(a1, "act");
  v3 = httpd_get_parm(a1, "thd_type");
  v4 = httpd_get_parm(a1, (char *)&off_645A5C);
  v5 = httpd_get_parm(a1, "ipport");
  v6 = httpd_get_parm(a1, "ruleips");
  v7 = httpd_get_parm(a1, "opt");
  v57 = httpd_get_json_parm(a1, (int)"del_list");
  if ( !v7 )
    goto LABEL_7;
  if ( strcmp(v7, (const char *)&off_646D8C) && strcmp(v7, (const char *)&off_648DDC) && strcmp(v7, "del") )
  {
    v50 = "a";
    if ( strcmp(v7, (const char *)&off_64712C) )
    {
      if ( strcmp(v7, "delall") )
      {
LABEL_7:
        v8 = *(unsigned __int8 *)(a1 + 210102);
        v9 = "not opt";
        v10 = 12;
        goto LABEL_75;
      }
      goto LABEL_49;
    }
    v14 = strcmp(v7, "delall");
    v12 = v50;
    if ( !v14 )
    {
LABEL_49:
      if ( set_rule_to_kernel(&off_644A94, v7, &v37) )
        goto LABEL_52;
      strlcpy(v35, "", 102400);
LABEL_51:
      jhl_parm_set("accAll2", v35);
      jhl_parm_commit(v15);
LABEL_52:
      v16 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      v17 = v36;
      do
      {
        v18 = *(_DWORD *)v16;
        v19 = *((_DWORD *)v16 + 1);
        v20 = *((_DWORD *)v16 + 2);
        v21 = *((_DWORD *)v16 + 3);
        v16 += 16;
        *(_DWORD *)v17 = v18;
        *((_DWORD *)v17 + 1) = v19;
        *((_DWORD *)v17 + 2) = v20;
        *((_DWORD *)v17 + 3) = v21;
        v17 += 16;
      }
      while ( v16 != "}" );
      v22 = 33;
      *(_WORD *)v17 = *(_WORD *)v16;
      return httpd_cgi_ret(a1, v36, v22, 4);
    }
    goto LABEL_56;
  }
  if ( !strcmp(v7, "delall") )
    goto LABEL_49;
  v58 = "a";
  v11 = strcmp(v7, (const char *)&off_64712C);
  v12 = "a";
  if ( v11 )
  {
    if ( !strcmp(v7, "del") && v57 && cJSON_IsArray(v57) )
    {
      v13 = *(_DWORD *)(v57 + 8);
      if ( !v13 )
        goto LABEL_52;
      if ( !*(_DWORD *)(v13 + 16) )
        goto LABEL_52;
      v37 = *(const char **)(v13 + 16);
      if ( set_rule_to_kernel(&off_644A94, v7, &v37) )
        goto LABEL_52;
      jhl_parm_get("accAll2", v36, 102400);
      if ( !nvparm_del_str(v36, 60, 13, *(_DWORD *)(v13 + 16), 124, 0, v35) )
        goto LABEL_52;
      jhl_parm_set("accAll2", v35);
      goto LABEL_51;
    }
    if ( !v51 )
    {
      v8 = *(unsigned __int8 *)(a1 + 210102);
      v9 = "error name";
      v10 = 12;
      goto LABEL_75;
    }
    v37 = v51;
    if ( v56 )
    {
      if ( strcmp(v7, (const char *)&off_648DDC) )
      {
        if ( strcmp(v7, (const char *)&off_646D8C) )
          goto LABEL_52;
        goto LABEL_22;
      }
      v35[0] = (int)"acc_del.sh";
      v35[1] = (int)v56;
      v35[2] = 0;
      eval(v35, 0, 0, 0);
    }
    if ( strcmp(v7, (const char *)&off_646D8C) && strcmp(v7, (const char *)&off_648DDC) )
      goto LABEL_52;
LABEL_22:
    if ( !v50 || !*v50 )
      v50 = "1";
    v38 = v50;
    if ( !v52 || !*v52 )
      v52 = "";
    v39 = v52;
    if ( !v53 || !*v53 )
      v53 = "OFF";
    v40 = v53;
    if ( !v54 || !*v54 )
      v54 = "0";
    v41 = v54;
    if ( !v55 || !*v55 )
      v55 = "1";
    v42 = v55;
    if ( !v2 || !*v2 )
      v2 = "1";
    v43 = v2;
    if ( !v3 || !*v3 )
      v3 = "0";
    v44 = v3;
    if ( !v4 || !*v4 )
      v4 = "";
    v45 = v4;
    if ( !v5 || !*v5 )
      v5 = "";
    v46 = v5;
    if ( !v6 || !*v6 )
      v6 = "0";
    v47 = v6;
    if ( !set_rule_to_kernel(&off_644A94, v7, &v37) )
    {
      if ( !strcmp(v7, (const char *)&off_648DDC)
        && ((jhl_parm_get("accAll2", v36, 102400), !v56) ? (v34 = nvparm_del_str(v36, 60, 13, v51, 124, 0, v35)) : (v34 = nvparm_del_str(v36, 60, 13, v56, 124, 0, v35)),
            v34) )
      {
        sprintf(v36, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<", v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47);
        strcat((char *)v35, v36);
      }
      else
      {
        sprintf(v36, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<", v37, v38, v39, v40, v41, v42, v43, v44, v45, v46, v47);
        jhl_parm_get("accAll2", v35, 102400);
        if ( !strcmp((const char *)v35, " ") )
          LOBYTE(v35[0]) = 0;
        strcat((char *)v35, v36);
      }
      goto LABEL_51;
    }
    v8 = *(unsigned __int8 *)(a1 + 210102);
    v9 = v7;
    v10 = 3;
LABEL_75:
    v33 = (const char *)_GET_LANG_TEXT(v10, v8, v9);
    v22 = snprintf(v36, 102400, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v33);
    if ( v22 >= 0x19000 )
      v22 = 102399;
    return httpd_cgi_ret(a1, v36, v22, 4);
  }
LABEL_56:
  v24 = httpd_get_parm(a1, v12 + 28972);
  v25 = v24;
  if ( !v24 || strcmp(v24, (const char *)&off_63F984) && strcmp(v25, "accept") && strcmp(v25, "drop") )
  {
    v8 = *(unsigned __int8 *)(a1 + 210102);
    v9 = "error def";
    v10 = 12;
    goto LABEL_75;
  }
  v37 = v25;
  if ( !set_rule_to_kernel(&off_644A94, v7, &v37) )
  {
    jhl_parm_set("accAct", v25);
    jhl_parm_commit(v26);
  }
  v27 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v28 = v36;
  do
  {
    v29 = *(_DWORD *)v27;
    v30 = *((_DWORD *)v27 + 1);
    v31 = *((_DWORD *)v27 + 2);
    v32 = *((_DWORD *)v27 + 3);
    v27 += 16;
    *(_DWORD *)v28 = v29;
    *((_DWORD *)v28 + 1) = v30;
    *((_DWORD *)v28 + 2) = v31;
    *((_DWORD *)v28 + 3) = v32;
    v28 += 16;
  }
  while ( v27 != "}" );
  *(_WORD *)v28 = *(_WORD *)v27;
  v22 = 33;
  return httpd_cgi_ret(a1, v36, v22, 4);
}
// 46DA1C: variable 'v15' is possibly undefined
// 46DBA8: variable 'v26' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 644A94: using guessed type void *off_644A94;
// 645A5C: using guessed type char *off_645A5C;
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 64E034: using guessed type int (**off_64E034)();
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A832C: using guessed type int __fastcall set_rule_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

