int __fastcall spqos_asp(const char *a1, int a2)
{
  char *v4; // $s1
  _WORD *v5; // $v0
  void *v6; // $v0
  void *v7; // $s3
  _WORD *v8; // $s2
  const char *v9; // $a2
  int v10; // $v0
  int v11; // $a1
  int v12; // $a0
  const char *v13; // $v0
  int v14; // $s7
  int v16; // $s6
  _DWORD *v17; // $s6
  const char *v18; // $v0
  int *v19; // $v1
  const char *v20; // $v0
  int v21; // $t0
  int v22; // $a3
  int v23; // $a2
  int v24; // $a1
  int v25; // $a0
  int v26; // $v0
  _BOOL4 v27; // $s1
  const char *v28; // $v0
  int s[64]; // [sp+58h] [-1E0h] BYREF
  const char *v30; // [sp+158h] [-E0h] BYREF
  char *v31; // [sp+15Ch] [-DCh]
  char *v32; // [sp+160h] [-D8h]
  char *v33; // [sp+164h] [-D4h]
  char *v34; // [sp+168h] [-D0h]
  char *v35; // [sp+16Ch] [-CCh]
  char *v36; // [sp+170h] [-C8h]
  char *v37; // [sp+174h] [-C4h]
  char *v38; // [sp+178h] [-C0h]
  char *v39; // [sp+17Ch] [-BCh]
  char *v40; // [sp+180h] [-B8h]
  char *v41; // [sp+184h] [-B4h]
  char *v42; // [sp+188h] [-B0h]
  char *v43; // [sp+18Ch] [-ACh]
  char *v44; // [sp+190h] [-A8h]
  char *v45; // [sp+194h] [-A4h]
  char *v46; // [sp+198h] [-A0h]
  char v47[68]; // [sp+1A4h] [-94h] BYREF
  char *v48; // [sp+1E8h] [-50h]
  int v49; // [sp+1ECh] [-4Ch]
  char *v50; // [sp+1F0h] [-48h]
  char *v51; // [sp+1F4h] [-44h]
  char *v52; // [sp+1F8h] [-40h]
  char *v53; // [sp+1FCh] [-3Ch]
  char *v54; // [sp+200h] [-38h]
  char *v55; // [sp+204h] [-34h]
  char *v56; // [sp+208h] [-30h]
  char *v57; // [sp+20Ch] [-2Ch]
  char *v58; // [sp+210h] [-28h]
  char *v59; // [sp+214h] [-24h]
  char *v60; // [sp+218h] [-20h]
  char *v61; // [sp+21Ch] [-1Ch]
  char *v62; // [sp+220h] [-18h]
  char *v63; // [sp+224h] [-14h]
  char *v64; // [sp+228h] [-10h]
  char *v65; // [sp+22Ch] [-Ch]
  int v66; // [sp+230h] [-8h]

  memset(v47, 0, 0x40u);
  v48 = httpd_get_parm(a2, "name");
  v49 = (int)httpd_get_parm(a2, "old_name");
  v50 = httpd_get_parm(a2, "en");
  v51 = httpd_get_parm(a2, "rpri");
  v52 = httpd_get_parm(a2, "dev_prio");
  v53 = httpd_get_parm(a2, "hi_prio");
  v54 = httpd_get_parm(a2, "bh");
  v55 = httpd_get_parm(a2, "type");
  v56 = httpd_get_parm(a2, "thd_type");
  v57 = httpd_get_parm(a2, "sx");
  v58 = httpd_get_parm(a2, "xx");
  v59 = httpd_get_parm(a2, "ips");
  v60 = httpd_get_parm(a2, "wans");
  v61 = httpd_get_parm(a2, (char *)&off_645A5C);
  v62 = httpd_get_parm(a2, "shibie_id");
  v63 = httpd_get_parm(a2, "ipport");
  v64 = httpd_get_parm(a2, "time");
  v65 = httpd_get_parm(a2, "flowed_val");
  v66 = httpd_get_json_parm(a2, (int)"del_list");
  v4 = httpd_get_parm(a2, "opt");
  _mem_malloc(102400, "spqos_asp", 359);
  v7 = v6;
  _mem_malloc(102400, "spqos_asp", 360);
  v8 = v5;
  if ( v7 )
  {
    v9 = (const char *)102400;
    if ( !v5 )
    {
      v11 = *(unsigned __int8 *)(a2 + 210102);
      v12 = 4;
      goto LABEL_11;
    }
    if ( !a1 )
    {
      v11 = *(unsigned __int8 *)(a2 + 210102);
      v9 = "not type param";
      v12 = 12;
      goto LABEL_11;
    }
    v10 = a2 + 196608;
    if ( !v4 )
    {
LABEL_10:
      v11 = *(unsigned __int8 *)(v10 + 13494);
      v9 = "not opt";
      v12 = 12;
LABEL_11:
      v13 = (const char *)_GET_LANG_TEXT(v12, v11, v9);
      goto LABEL_12;
    }
    if ( strcmp(v4, (const char *)&off_646D8C)
      && strcmp(v4, (const char *)&off_648DDC)
      && strcmp(v4, "del")
      && strcmp(v4, "delall") )
    {
      v10 = a2 + 196608;
      goto LABEL_10;
    }
    snprintf(v47, 64, "sqos_%s", a1);
    if ( !strcmp(v4, "delall") )
    {
      if ( set_qos_to_kernel(a1, v4, &v30) )
        goto LABEL_36;
      *v8 = 32;
      goto LABEL_42;
    }
    if ( !strcmp(v4, "del") )
    {
      v16 = v66;
      if ( v66 )
      {
        if ( cJSON_IsArray(v66) )
        {
          v17 = *(_DWORD **)(v16 + 8);
          if ( !v17 )
            goto LABEL_36;
          v18 = (const char *)v17[4];
          if ( !v18 )
            goto LABEL_36;
          v49 = 0;
          v48 = (char *)102400;
          do
          {
            v30 = v18;
            if ( set_qos_to_kernel(a1, v4, &v30) >= 0 )
            {
              jhl_parm_get(v47, v7, v48);
              if ( nvparm_del_str(v7, 60, 19, v30, 124, 0, v8) )
              {
                jhl_parm_set(v47, v8);
                v49 = 1;
              }
            }
            v17 = (_DWORD *)*v17;
            if ( !v17 )
              break;
            v18 = (const char *)v17[4];
          }
          while ( v18 );
          if ( !v49 )
            goto LABEL_36;
          goto LABEL_42;
        }
      }
    }
    if ( !v48 )
    {
      v11 = *(unsigned __int8 *)(a2 + 210102);
      v9 = (const char *)&unk_6442E4;
      v12 = 12;
      goto LABEL_11;
    }
    v30 = v48;
    if ( v49 )
    {
      if ( strcmp(v4, (const char *)&off_648DDC) )
      {
        if ( strcmp(v4, (const char *)&off_646D8C) )
          goto LABEL_36;
        goto LABEL_33;
      }
      s[0] = (int)"qos_del.sh";
      s[1] = (int)a1;
      s[2] = v49;
      s[3] = 0;
      eval(s, 0, 0, 0);
    }
    if ( strcmp(v4, (const char *)&off_646D8C) )
    {
      if ( strcmp(v4, (const char *)&off_648DDC) )
      {
LABEL_36:
        v19 = s;
        v20 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v21 = *(_DWORD *)v20;
          v22 = *((_DWORD *)v20 + 1);
          v23 = *((_DWORD *)v20 + 2);
          v24 = *((_DWORD *)v20 + 3);
          v20 += 16;
          *v19 = v21;
          v19[1] = v22;
          v19[2] = v23;
          v19[3] = v24;
          v19 += 4;
        }
        while ( v20 != "}" );
        v14 = 33;
        *(_WORD *)v19 = *(_WORD *)v20;
        goto LABEL_39;
      }
      goto LABEL_47;
    }
LABEL_33:
    v14 = check_rule_num_limit(a2, 7, (int)v47, 60, (char *)s, 0x100u);
    if ( v14 > 0 )
    {
LABEL_39:
      _mem_free(v7);
      goto LABEL_14;
    }
    jhl_parm_get(v47, v8, 102400);
    if ( nvparm_find_str(v8, 60, 19, v48, 124, 0) )
    {
      v13 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a2 + 210102), "same name");
LABEL_12:
      v14 = snprintf((char *)s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
      if ( (unsigned int)v14 >= 0x100 )
      {
        _mem_free(v7);
        v14 = 255;
        goto LABEL_14;
      }
      goto LABEL_39;
    }
LABEL_47:
    if ( !v50 || !*v50 )
      v50 = "0";
    v31 = v50;
    if ( !v51 || !*v51 )
      v51 = "0";
    v32 = v51;
    if ( !v52 || !*v52 )
      v52 = "0";
    v33 = v52;
    if ( !v53 || !*v53 )
      v53 = "0";
    v34 = v53;
    if ( !v54 || !*v54 )
      v54 = "0";
    v35 = v54;
    if ( !v55 || !*v55 )
      v55 = "0";
    v36 = v55;
    if ( !v56 || !*v56 )
      v56 = "0";
    v37 = v56;
    if ( !v57 || !*v57 )
      v57 = "0";
    v38 = v57;
    if ( !v58 || !*v58 )
      v58 = "0";
    v39 = v58;
    if ( !v59 || !*v59 )
      v59 = "";
    v40 = v59;
    if ( !v60 || !*v60 )
      v60 = "";
    v41 = v60;
    if ( !v61 || !*v61 )
      v61 = "";
    v42 = v61;
    if ( !v62 || !*v62 )
      v62 = "00000000";
    v43 = v62;
    if ( !v63 || !*v63 )
      v63 = "";
    v44 = v63;
    if ( !v64 || !*v64 )
      v64 = "OFF";
    v45 = v64;
    if ( !v65 || !*v65 )
      v65 = "0";
    v46 = v65;
    if ( set_qos_to_kernel(a1, v4, &v30) < 0 )
      goto LABEL_36;
    jhl_parm_get(v47, v7, 102400);
    memset(v8, 0, 0x19000u);
    if ( v49 )
      v26 = nvparm_del_str(v7, 60, 19, v49, 124, 0, v8);
    else
      v26 = nvparm_del_str(v7, 60, 19, v48, 124, 0, v8);
    v27 = v26 != 0;
    sprintf(
      (char *)v7,
      "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<",
      v30,
      v31,
      v32,
      v33,
      v34,
      v35,
      v36,
      v37,
      v38,
      v39,
      v40,
      v41,
      v42,
      v43,
      v44,
      v45,
      v46);
    if ( !v27 )
    {
      jhl_parm_get(v47, v8, 102400);
      if ( !strcmp((const char *)v8, " ") )
        *(_BYTE *)v8 = 0;
    }
    strcat((char *)v8, (char *)v7);
LABEL_42:
    jhl_parm_set(v47, v8);
    jhl_parm_commit(v25);
    goto LABEL_36;
  }
  v28 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a2 + 210102), 102400);
  v14 = snprintf((char *)s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
  if ( (unsigned int)v14 >= 0x100 )
    v14 = 255;
LABEL_14:
  if ( v8 )
    _mem_free(v8);
  return httpd_cgi_ret(a2, (char *)s, v14, 4);
}
// 456CDC: variable 'v6' is possibly undefined
// 456CE8: variable 'v5' is possibly undefined
// 457190: variable 'v25' is possibly undefined
// 645A5C: using guessed type char *off_645A5C;
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A85DC: using guessed type int __fastcall set_qos_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

