int __fastcall sub_4BF098(int a1)
{
  char *v2; // $s7
  char *v3; // $s1
  int v4; // $s6
  int v5; // $v0
  char *v6; // $v0
  char *v7; // $s4
  int v8; // $s3
  char *v9; // $v1
  const char *v10; // $v0
  int v11; // $t0
  int v12; // $a3
  int v13; // $a2
  int v14; // $a1
  int v15; // $fp
  const char *v17; // $a3
  const char *v18; // $v0
  const char *v19; // $v1
  const char *v20; // $a1
  const char *v21; // $t0
  const char *v22; // $t1
  const char *v23; // $t2
  const char *v24; // $t3
  const char *v25; // $t4
  const char *v26; // $t5
  const char *v27; // $fp
  _BOOL4 v28; // $s7
  _DWORD *v29; // $fp
  int v30; // $v0
  int v31; // $a0
  const char *v32; // $v0
  int v33; // $v0
  char s[256]; // [sp+40h] [-180h] BYREF
  int v35[15]; // [sp+140h] [-80h] BYREF
  int v36[3]; // [sp+17Ch] [-44h] BYREF
  char *v37; // [sp+188h] [-38h]
  char *v38; // [sp+18Ch] [-34h]
  char *v39; // [sp+190h] [-30h]
  char *v40; // [sp+194h] [-2Ch]
  char *v41; // [sp+198h] [-28h]
  char *v42; // [sp+19Ch] [-24h]
  char *v43; // [sp+1A0h] [-20h]
  char *v44; // [sp+1A4h] [-1Ch]
  char *v45; // [sp+1A8h] [-18h]
  char *v46; // [sp+1ACh] [-14h]
  char *v47; // [sp+1B0h] [-10h]
  char *v48; // [sp+1B4h] [-Ch]
  char *v49; // [sp+1B8h] [-8h]

  memset(v35, 0, sizeof(v35));
  v2 = httpd_get_parm(a1, "name");
  v48 = httpd_get_parm(a1, "old_name");
  v37 = httpd_get_parm(a1, "en");
  v38 = httpd_get_parm(a1, "ips");
  v39 = httpd_get_parm(a1, "time");
  v40 = httpd_get_parm(a1, (char *)&off_64E034);
  v41 = httpd_get_parm(a1, "rpri");
  v42 = httpd_get_parm(a1, "wans");
  v43 = httpd_get_parm(a1, "thd_type");
  v44 = httpd_get_parm(a1, (char *)&off_645A5C);
  v45 = httpd_get_parm(a1, "shibie");
  v46 = httpd_get_parm(a1, "ipport");
  v47 = httpd_get_parm(a1, "no_change");
  v3 = httpd_get_parm(a1, "opt");
  v4 = httpd_get_json_parm(a1, (int)"del_list");
  _mem_malloc(102400, "mrprot_asp", 932);
  v7 = v6;
  _mem_malloc(102400, "mrprot_asp", 933);
  v8 = v5;
  if ( !v7 || !v5 )
  {
    v32 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    goto LABEL_77;
  }
  if ( !v3 )
  {
LABEL_76:
    v32 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    goto LABEL_77;
  }
  if ( !strcmp(v3, (const char *)&off_646D8C) || !strcmp(v3, (const char *)&off_648DDC) )
  {
    if ( !strcmp(v3, "delall") )
      goto LABEL_8;
    if ( strcmp(v3, "del") )
      goto LABEL_15;
  }
  else
  {
    if ( strcmp(v3, "del") )
    {
      if ( !strcmp(v3, "delall") )
      {
LABEL_8:
        if ( set_rule_to_kernel("mr", v3, v35) )
          goto LABEL_9;
        *(_BYTE *)v8 = 32;
        *(_BYTE *)(v8 + 1) = 0;
        v49 = "a";
        goto LABEL_65;
      }
      goto LABEL_76;
    }
    if ( !strcmp(v3, "delall") )
      goto LABEL_8;
  }
  if ( v4 && cJSON_IsArray(v4) )
  {
    v29 = *(_DWORD **)(v4 + 8);
    if ( !v29 )
      goto LABEL_9;
    v30 = v29[4];
    if ( !v30 )
      goto LABEL_9;
    v38 = 0;
    v37 = (char *)102400;
    do
    {
      v35[0] = v30;
      if ( !set_rule_to_kernel("mr", v3, v35) )
      {
        jhl_parm_get("mrprot2", v7, v37);
        if ( nvparm_del_str(v7, 60, 15, v29[4], 124, 0, v8) )
        {
          jhl_parm_set("mrprot2", v8);
          v38 = (char *)1;
        }
      }
      v29 = (_DWORD *)*v29;
      if ( !v29 )
        break;
      v30 = v29[4];
    }
    while ( v30 );
    if ( !v38 )
      goto LABEL_9;
    v49 = "a";
    goto LABEL_65;
  }
LABEL_15:
  if ( !v2 )
  {
    v32 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
    goto LABEL_77;
  }
  v35[0] = (int)v2;
  if ( !strcmp(v3, (const char *)&off_646D8C) )
  {
    v49 = "a";
    jhl_parm_get("mrprot2", v8, 102400);
    if ( nvparm_find_str(v8, 60, 15, v2, 124, 0) )
    {
      v32 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "same name");
      goto LABEL_77;
    }
  }
  else
  {
    if ( strcmp(v3, (const char *)&off_648DDC) )
      goto LABEL_9;
    v49 = "a";
  }
  v15 = check_rule_num_limit(a1, 2, (int)(v49 + 27920), 60, s, 0x100u);
  if ( v15 > 0 )
    goto LABEL_12;
  if ( v37 )
  {
    if ( !*v37 )
      v37 = "1";
  }
  else
  {
    v37 = "1";
  }
  v35[1] = (int)v37;
  if ( !v38 || !*v38 )
    v38 = "";
  v35[2] = (int)v38;
  if ( !v39 || !*v39 )
    v39 = "OFF";
  v35[3] = (int)v39;
  if ( !v40 || !*v40 )
    v40 = "0";
  v35[4] = (int)v40;
  if ( !v41 || !*v41 )
    v41 = "1";
  v35[5] = (int)v41;
  if ( !v42 || !*v42 )
    v42 = "";
  v35[6] = (int)v42;
  if ( !v43 || !*v43 )
    v43 = "0";
  v35[7] = (int)v43;
  if ( !v44 || !*v44 )
    v44 = "";
  v35[8] = (int)v44;
  if ( !v45 || !*v45 )
    v45 = "00000000";
  v35[9] = (int)v45;
  if ( !v46 || !*v46 )
    v46 = "";
  v35[10] = (int)v46;
  if ( !v47 || !*v47 )
    v47 = "0";
  v35[11] = (int)v47;
  if ( !v48 )
  {
    if ( strcmp(v3, (const char *)&off_648DDC) )
    {
      v27 = v47;
      v26 = v46;
      v25 = v45;
      v24 = v44;
      v23 = v43;
      v22 = v42;
      v21 = v41;
      v20 = v40;
      v19 = v39;
      v18 = v38;
      v17 = v37;
      v28 = 0;
      goto LABEL_45;
    }
    jhl_parm_get(v49 + 27920, v7, 102400);
    v33 = nvparm_del_str(v7, 60, 15, v2, 124, 0, v8);
LABEL_84:
    v28 = v33 != 0;
    sprintf(
      v7,
      "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<",
      (const char *)v35[0],
      (const char *)v35[1],
      (const char *)v35[2],
      (const char *)v35[3],
      (const char *)v35[4],
      (const char *)v35[5],
      (const char *)v35[6],
      (const char *)v35[7],
      (const char *)v35[8],
      (const char *)v35[9],
      (const char *)v35[10],
      (const char *)v35[11]);
    goto LABEL_46;
  }
  v36[1] = (int)v48;
  v36[0] = (int)"mr_del.sh";
  v36[2] = 0;
  eval(v36, 0, 0, 0);
  if ( !strcmp(v3, (const char *)&off_648DDC) )
  {
    jhl_parm_get(v49 + 27920, v7, 102400);
    v33 = nvparm_del_str(v7, 60, 15, v48, 124, 0, v8);
    goto LABEL_84;
  }
  v17 = (const char *)v35[1];
  v18 = (const char *)v35[2];
  v19 = (const char *)v35[3];
  v20 = (const char *)v35[4];
  v21 = (const char *)v35[5];
  v22 = (const char *)v35[6];
  v23 = (const char *)v35[7];
  v24 = (const char *)v35[8];
  v25 = (const char *)v35[9];
  v26 = (const char *)v35[10];
  v27 = (const char *)v35[11];
  v28 = 0;
LABEL_45:
  sprintf(
    v7,
    "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<",
    (const char *)v35[0],
    v17,
    v18,
    v19,
    v20,
    v21,
    v22,
    v23,
    v24,
    v25,
    v26,
    v27);
LABEL_46:
  if ( !set_rule_to_kernel("mr", v3, v35) )
  {
    if ( !v28 )
    {
      jhl_parm_get(v49 + 27920, v8, 102400);
      if ( !strcmp((const char *)v8, " ") )
        *(_BYTE *)v8 = 0;
    }
    strcat((char *)v8, v7);
LABEL_65:
    jhl_parm_set(v49 + 27920, v8);
    jhl_parm_commit(v31);
LABEL_9:
    v9 = s;
    v10 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v11 = *(_DWORD *)v10;
      v12 = *((_DWORD *)v10 + 1);
      v13 = *((_DWORD *)v10 + 2);
      v14 = *((_DWORD *)v10 + 3);
      v10 += 16;
      *(_DWORD *)v9 = v11;
      *((_DWORD *)v9 + 1) = v12;
      *((_DWORD *)v9 + 2) = v13;
      *((_DWORD *)v9 + 3) = v14;
      v9 += 16;
    }
    while ( v10 != "}" );
    v15 = 33;
    *(_WORD *)v9 = *(_WORD *)v10;
    goto LABEL_12;
  }
  v32 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), v3);
LABEL_77:
  v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v32);
  if ( (unsigned int)v15 >= 0x100 )
    v15 = 255;
LABEL_12:
  _mem_free(v7);
  _mem_free((void *)v8);
  return httpd_cgi_ret(a1, s, v15, 4);
}
// 4BF2D0: variable 'v6' is possibly undefined
// 4BF2DC: variable 'v5' is possibly undefined
// 4BFA10: variable 'v31' is possibly undefined
// 645A5C: using guessed type char *off_645A5C;
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 64E034: using guessed type int (**off_64E034)();
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A832C: using guessed type int __fastcall set_rule_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

