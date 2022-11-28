int __fastcall sub_45E8B0(int a1)
{
  char *v2; // $s7
  char *v3; // $fp
  char *v4; // $s6
  char *v5; // $v0
  int v6; // $s4
  const char *v7; // $s2
  const char *v8; // $v0
  int v9; // $v0
  _BYTE *v10; // $s3
  void *v11; // $s1
  char *v13; // $fp
  char *v14; // $s7
  char *v15; // $s5
  char *v16; // $s1
  int v17; // $v0
  char *v18; // $s3
  int v19; // $fp
  char *v20; // $s2
  int v21; // $a0
  int *v22; // $v1
  const char *v23; // $v0
  int v24; // $t0
  int v25; // $a3
  int v26; // $a2
  int v27; // $a1
  _BYTE *v28; // $v0
  void *v29; // $v0
  _DWORD *v30; // $s2
  int v31; // $v0
  int v32; // $a0
  int *v33; // $v1
  const char *v34; // $v0
  int v35; // $t0
  int v36; // $a3
  int v37; // $a2
  int v38; // $a1
  __int16 v39; // $a0
  int v40; // $a1
  int v41; // $a2
  int v42; // $a0
  const char *v43; // $v0
  int v44[256]; // [sp+50h] [-668h] BYREF
  int v45[64]; // [sp+450h] [-268h] BYREF
  int s[64]; // [sp+550h] [-168h] BYREF
  char *v47; // [sp+650h] [-68h] BYREF
  const char *v48; // [sp+654h] [-64h]
  const char *v49; // [sp+658h] [-60h]
  char *v50; // [sp+65Ch] [-5Ch]
  const char *v51; // [sp+660h] [-58h]
  const char *v52; // [sp+664h] [-54h]
  char *v53; // [sp+668h] [-50h]
  const char *v54; // [sp+66Ch] [-4Ch]
  const char *v55; // [sp+670h] [-48h]
  char *v56; // [sp+674h] [-44h]
  const char *v57; // [sp+678h] [-40h]
  const char *v58; // [sp+67Ch] [-3Ch]
  char *v59; // [sp+680h] [-38h]
  const char *v60; // [sp+684h] [-34h]
  const char *v61; // [sp+688h] [-30h]
  int v62; // [sp+698h] [-20h]
  char *v63; // [sp+69Ch] [-1Ch]
  char *v64; // [sp+6A0h] [-18h]
  int v65; // [sp+6A4h] [-14h]
  char *v66; // [sp+6A8h] [-10h]
  char *v67; // [sp+6ACh] [-Ch]
  char *v68; // [sp+6B0h] [-8h]

  v64 = httpd_get_parm(a1, "name");
  v65 = (int)httpd_get_parm(a1, "old_name");
  v62 = (int)httpd_get_parm(a1, "en");
  v63 = httpd_get_parm(a1, "user_id");
  v2 = httpd_get_parm(a1, "proto");
  v3 = httpd_get_parm(a1, "num");
  v4 = httpd_get_parm(a1, "time");
  v6 = httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  if ( !v5 )
  {
LABEL_6:
    v8 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    v9 = snprintf((char *)s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
    if ( (unsigned int)v9 >= 0x100 )
      v9 = 255;
    v10 = 0;
    v11 = 0;
    goto LABEL_9;
  }
  v7 = v5;
  if ( strcmp(v5, (const char *)&off_64712C) )
  {
    v66 = "a";
    if ( strcmp(v7, (const char *)&off_646D8C) && strcmp(v7, (const char *)&off_648DDC) && strcmp(v7, "del") )
      goto LABEL_6;
    _mem_malloc(102400, "ctxz_asp", 2028);
    v11 = v29;
    _mem_malloc(102400, "ctxz_asp", 2029);
    v10 = v28;
    if ( v11 && v28 )
    {
      if ( !strcmp(v7, "del") && v6 )
      {
        v30 = *(_DWORD **)(v6 + 8);
        if ( !v30 )
          goto LABEL_70;
        v31 = v30[4];
        if ( !v31 )
          goto LABEL_70;
        v67 = "a";
        v65 = 0;
        v62 = 102400;
        v63 = "hixz_ct";
        do
        {
          v44[1] = v31;
          v44[0] = (int)"hictxz_del.sh";
          v44[2] = 0;
          eval(v44, 0, 0, 0);
          jhl_parm_get("hixz_ct", v11, v62);
          if ( nvparm_del_str(v11, 60, 10, v30[4], 124, 0, v10) )
          {
            jhl_parm_set(v63, v10);
            v65 = 1;
          }
          v30 = (_DWORD *)*v30;
          if ( !v30 )
            break;
          v31 = v30[4];
        }
        while ( v31 );
LABEL_73:
        if ( v65 )
        {
LABEL_69:
          jhl_parm_set(v67 + 26092, v10);
          jhl_parm_commit(v32);
        }
LABEL_70:
        v33 = s;
        v34 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v35 = *(_DWORD *)v34;
          v36 = *((_DWORD *)v34 + 1);
          v37 = *((_DWORD *)v34 + 2);
          v38 = *((_DWORD *)v34 + 3);
          v34 += 16;
          *v33 = v35;
          v33[1] = v36;
          v33[2] = v37;
          v33[3] = v38;
          v33 += 4;
        }
        while ( v34 != "}" );
        v39 = *(_WORD *)v34;
        v9 = 33;
        *(_WORD *)v33 = v39;
LABEL_9:
        v62 = v9;
        _mem_free(v11);
        _mem_free(v10);
        return httpd_cgi_ret(a1, (char *)s, v62, 4);
      }
      if ( v64 )
      {
        v68 = "1\"";
        if ( !strcmp(v7, (const char *)&off_648DDC) )
        {
          if ( v65 )
          {
            v44[1] = v65;
            v67 = "a";
            v44[0] = (int)"hictxz_del.sh";
            v44[2] = 0;
            eval(v44, 0, 0, 0);
            jhl_parm_get("hixz_ct", v11, 102400);
            v65 = nvparm_del_str(v11, 60, 8, v65, 124, 0, v10) != 0;
            if ( strcmp(v7, v66 + 28044) && strcmp(v7, v68 - 29220) )
              goto LABEL_73;
          }
          else
          {
            v65 = 0;
            v67 = "a";
          }
        }
        else
        {
          if ( strcmp(v7, v66 + 28044) )
            goto LABEL_70;
          v65 = 0;
          v67 = "a";
        }
        memset(v44, 0, sizeof(v44));
        if ( !v62 || !*(_BYTE *)v62 )
          v62 = (int)"1";
        if ( !v63 || !*v63 )
          v63 = "";
        if ( !v2 || !*v2 )
          v2 = "all";
        if ( !v3 || !*v3 )
          v3 = "2000";
        if ( !v4 || !*v4 )
          v4 = "OFF";
        if ( !strcmp(v7, v66 + 28044) )
        {
          v9 = check_rule_num_limit(a1, 11, (int)(v67 + 26092), 60, (char *)s, 0x100u);
          if ( v9 > 0 )
            goto LABEL_9;
        }
        if ( get_time_group(v4, v44, 1024) )
          strlcpy(v44, v4, 1024);
        v45[0] = (int)"hictxz_add.sh";
        v45[2] = v62;
        v45[3] = (int)v63;
        v45[1] = (int)v64;
        v45[4] = (int)v2;
        v45[5] = (int)v3;
        v45[6] = (int)v44;
        v45[7] = (int)v44;
        v45[8] = 0;
        eval(v45, 0, 0, 0);
        sprintf((char *)v11, "%s|%s|%s|%s|%s|%s<", v64, (const char *)v62, v63, v2, v3, v4);
        if ( !v65 )
        {
          jhl_parm_get(v67 + 26092, v10, 102400);
          if ( !strcmp(v10, " ") )
            *v10 = 0;
        }
        strcat(v10, (char *)v11);
        goto LABEL_69;
      }
      v40 = *(unsigned __int8 *)(a1 + 210102);
      v41 = (int)&unk_6442E4;
      v42 = 12;
    }
    else
    {
      v40 = *(unsigned __int8 *)(a1 + 210102);
      v41 = 102400;
      v42 = 4;
    }
    v43 = (const char *)_GET_LANG_TEXT(v42, v40, v41);
    v9 = snprintf((char *)s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v43);
    if ( (unsigned int)v9 >= 0x100 )
      v9 = 255;
    goto LABEL_9;
  }
  memset(v45, 0, sizeof(v45));
  memset(v44, 0, 0x100u);
  v13 = httpd_get_parm(a1, (char *)&off_64712C);
  v14 = httpd_get_parm(a1, "defTcp");
  v15 = httpd_get_parm(a1, "defUdp");
  v16 = httpd_get_parm(a1, "defIcmp");
  v18 = httpd_get_parm(a1, "defOther");
  v17 = jhl_nv_get_def("hixz3");
  strlcpy(v45, v17, 256);
  split_string(v45, 60, &v47, 15);
  if ( !v13 || !strcmp(v47, v13) )
  {
    v19 = 0;
  }
  else
  {
    v47 = v13;
    v19 = 1;
  }
  if ( v14 && strcmp(v50, v14) )
  {
    v50 = v14;
    v19 = 1;
  }
  if ( v15 && strcmp(v53, v15) )
  {
    v53 = v15;
    v19 = 1;
  }
  if ( v16 && strcmp(v56, v16) )
  {
    v56 = v16;
    v20 = v59;
    if ( !v18 || !strcmp(v59, v18) )
      goto LABEL_25;
    v59 = v18;
    goto LABEL_24;
  }
  if ( v18 && strcmp(v59, v18) )
  {
    v16 = v56;
    v59 = v18;
LABEL_24:
    v20 = v18;
LABEL_25:
    sprintf(
      (char *)v44,
      "%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s<%s",
      v47,
      v48,
      v49,
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v16,
      v57,
      v58,
      v20,
      v60,
      v61);
    nvram_set("hixz3", v44);
    s[0] = (int)"wys";
    s[1] = (int)"ctrule";
    s[2] = (int)"defset";
    s[3] = (int)v47;
    s[4] = (int)v48;
    s[5] = (int)v49;
    s[6] = (int)v50;
    s[7] = (int)v51;
    s[8] = (int)v52;
    s[9] = (int)v53;
    s[10] = (int)v54;
    s[11] = (int)v55;
    s[12] = (int)v56;
    s[13] = (int)v57;
    s[14] = (int)v58;
    s[15] = (int)v59;
    s[16] = (int)v60;
    s[18] = 0;
    s[17] = (int)v61;
    eval(s, 0, 0, 0);
    jhl_parm_commit(v21);
    goto LABEL_30;
  }
  if ( v19 )
  {
    v16 = v56;
    v20 = v59;
    goto LABEL_25;
  }
LABEL_30:
  v22 = s;
  v23 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v24 = *(_DWORD *)v23;
    v25 = *((_DWORD *)v23 + 1);
    v26 = *((_DWORD *)v23 + 2);
    v27 = *((_DWORD *)v23 + 3);
    v23 += 16;
    *v22 = v24;
    v22[1] = v25;
    v22[2] = v26;
    v22[3] = v27;
    v22 += 4;
  }
  while ( v23 != "}" );
  *(_WORD *)v22 = *(_WORD *)v23;
  return httpd_cgi_ret(a1, (char *)s, 33, 4);
}
// 45EEA4: variable 'v21' is possibly undefined
// 45EFB0: variable 'v29' is possibly undefined
// 45EFBC: variable 'v28' is possibly undefined
// 45F408: variable 'v32' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

