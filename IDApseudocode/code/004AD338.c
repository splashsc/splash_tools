int __fastcall sub_4AD338(int a1)
{
  char *v1; // $v0
  const char *v3; // $s4
  char *v4; // $s3
  char *v5; // $s4
  char *v6; // $fp
  char *v7; // $s2
  char *v8; // $s5
  char *v9; // $s6
  char *v10; // $s7
  int v11; // $v0
  int v12; // $s2
  int v13; // $v0
  char *v14; // $s2
  int v15; // $a0
  const char **v16; // $v1
  const char *v17; // $v0
  const char *v18; // $t0
  const char *v19; // $a3
  const char *v20; // $a2
  const char *v21; // $a1
  unsigned int v22; // $a2
  char *v24; // $v0
  char *v25; // $s3
  char *v26; // $s6
  int v27; // $s7
  int v28; // $s6
  int v29; // $v0
  int v30; // $s1
  _DWORD *v31; // $s2
  int v32; // $v0
  int v33; // $s3
  int v34; // $v0
  int v35; // $s3
  int v36; // $s6
  int v37; // $a1
  const char *v38; // $a2
  const char *v39; // $v0
  int v40; // $v0
  const char *v41; // [sp+10h] [-4D8h]
  const char *v42; // [sp+30h] [-4B8h] BYREF
  const char *v43; // [sp+34h] [-4B4h]
  const char *v44; // [sp+38h] [-4B0h]
  char *v45; // [sp+3Ch] [-4ACh]
  int v46; // [sp+40h] [-4A8h]
  char v47[128]; // [sp+430h] [-B8h] BYREF
  int v48[6]; // [sp+4B0h] [-38h] BYREF
  char *v49; // [sp+4C8h] [-20h]
  char *v50; // [sp+4CCh] [-1Ch]
  char *v51; // [sp+4D0h] [-18h]
  char *v52; // [sp+4D4h] [-14h]
  char *v53; // [sp+4D8h] [-10h]
  const char *v54; // [sp+4DCh] [-Ch]
  const char *v55; // [sp+4E0h] [-8h]

  v1 = httpd_get_parm(a1, "opt");
  if ( !v1 )
    goto LABEL_41;
  v3 = v1;
  if ( !strcmp(v1, (const char *)&off_646D8C) )
  {
    if ( strcmp(v3, "del") )
    {
      if ( strcmp(v3, (const char *)&off_648DDC) )
      {
LABEL_5:
        v52 = "1\"";
        v54 = "service";
        v55 = "ddns";
        v53 = v47;
        v51 = "a";
        goto LABEL_6;
      }
      goto LABEL_26;
    }
    goto LABEL_31;
  }
  if ( strcmp(v3, "del") )
  {
    if ( !strcmp(v3, (const char *)&off_648DDC) )
      goto LABEL_26;
LABEL_41:
    v39 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    goto LABEL_42;
  }
LABEL_31:
  v29 = httpd_get_json_parm(a1, (int)"del_list");
  v30 = v29;
  if ( !v29 || !cJSON_IsArray(v29) )
  {
    v39 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_64D83C);
    goto LABEL_42;
  }
  v31 = *(_DWORD **)(v30 + 8);
  if ( v31 )
  {
    v49 = "wan";
    v50 = "service";
    v51 = "ddns";
    v52 = "stop";
    do
    {
      v35 = cJSON_GetObjectItem(v31, v49);
      v34 = cJSON_GetObjectItem(v31, "id");
      v36 = v34;
      if ( !v35 || !v34 )
      {
        v37 = *(unsigned __int8 *)(a1 + 210102);
        v38 = "del not wan or id";
        goto LABEL_39;
      }
      nvram_set("action_p1", *(_DWORD *)(v34 + 16));
      v42 = v50;
      v43 = v51;
      v44 = v52;
      v45 = *(char **)(v35 + 16);
      v46 = 0;
      eval(&v42, 0, 0, 0);
      v33 = J_atoi(*(_DWORD *)(v35 + 16));
      v32 = J_atoi(*(_DWORD *)(v36 + 16));
      jhl_ddns_del(v33, v32);
      v31 = (_DWORD *)*v31;
    }
    while ( v31 );
    v40 = strcmp(v3, (const char *)&off_648DDC);
  }
  else
  {
    v40 = strcmp(v3, (const char *)&off_648DDC);
  }
  if ( v40 )
  {
    if ( strcmp(v3, (const char *)&off_646D8C) )
    {
LABEL_20:
      jhl_parm_commit(v15);
      v16 = &v42;
      v17 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v18 = *(const char **)v17;
        v19 = (const char *)*((_DWORD *)v17 + 1);
        v20 = (const char *)*((_DWORD *)v17 + 2);
        v21 = (const char *)*((_DWORD *)v17 + 3);
        v17 += 16;
        *v16 = v18;
        v16[1] = v19;
        v16[2] = v20;
        v16[3] = v21;
        v16 += 4;
      }
      while ( v17 != "}" );
      v22 = 33;
      *(_WORD *)v16 = *(_WORD *)v17;
      return httpd_cgi_ret(a1, (char *)&v42, v22, 4);
    }
    goto LABEL_5;
  }
LABEL_26:
  v25 = httpd_get_parm(a1, "oldwans");
  v24 = httpd_get_parm(a1, "oldid");
  v26 = v24;
  if ( v25 && v24 )
  {
    v27 = J_atoi(v25);
    v51 = "a";
    v28 = J_atoi(v26);
    v53 = v47;
    v52 = "1\"";
    sprintf(v47, v51 + 24872, v28);
    nvram_set(v52 - 10144, v47);
    v54 = "service";
    v55 = "ddns";
    v42 = "service";
    v43 = "ddns";
    v44 = "stop";
    v45 = v25;
    v46 = 0;
    eval(&v42, 0, 0, 0);
    jhl_ddns_del(v27, v28);
    if ( strcmp(v3, (const char *)&off_646D8C) && strcmp(v3, (const char *)&off_648DDC) )
      goto LABEL_20;
LABEL_6:
    v4 = httpd_get_parm(a1, "wans");
    v5 = httpd_get_parm(a1, "serv");
    v6 = httpd_get_parm(a1, "user");
    v7 = httpd_get_parm(a1, "host");
    v49 = httpd_get_parm(a1, "wild");
    v50 = httpd_get_parm(a1, "mx");
    v8 = httpd_get_parm(a1, "bmx");
    v9 = httpd_get_parm(a1, "cust");
    v10 = httpd_get_parm(a1, "ip");
    if ( !v4 )
      v4 = "0";
    v11 = -1;
    if ( v5 )
    {
      v11 = strcmp(v5, "oray");
      if ( v6 )
        goto LABEL_10;
    }
    else
    {
      v5 = "";
      if ( v6 )
      {
LABEL_10:
        if ( !v7 )
          v7 = "";
        if ( !v49 )
          v49 = "";
        if ( v50 )
        {
          if ( v8 )
            goto LABEL_16;
        }
        else
        {
          v50 = "";
          if ( v8 )
          {
LABEL_16:
            if ( v9 )
              goto LABEL_17;
            goto LABEL_50;
          }
        }
        v8 = "";
        if ( v9 )
        {
LABEL_17:
          if ( v10 )
            goto LABEL_18;
          goto LABEL_48;
        }
LABEL_50:
        v9 = "";
        if ( v10 )
        {
LABEL_18:
          if ( v11 )
          {
LABEL_19:
            v41 = v7;
            v12 = J_atoi(v4);
            sprintf((char *)&v42, "%s|%s|%s|%s|%s|%s|%s|%s", v5, v6, v41, v49, v50, v8, v9, v10);
            v13 = jhl_ddns_add(v12, &v42);
            v14 = v53;
            sprintf(v53, v51 + 24872, v13);
            nvram_set(v52 - 10144, v14);
            v48[0] = (int)v54;
            v48[1] = (int)v55;
            v48[2] = (int)"start";
            v48[3] = (int)v4;
            v48[4] = 0;
            eval(v48, 0, 0, 0);
            goto LABEL_20;
          }
LABEL_40:
          v7 = "";
          goto LABEL_19;
        }
LABEL_48:
        v10 = "";
        if ( v11 )
          goto LABEL_19;
        goto LABEL_40;
      }
    }
    v6 = "";
    goto LABEL_10;
  }
  v37 = *(unsigned __int8 *)(a1 + 210102);
  v38 = (const char *)&unk_64D87C;
LABEL_39:
  v39 = (const char *)_GET_LANG_TEXT(12, v37, v38);
LABEL_42:
  v22 = snprintf((char *)&v42, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v39);
  if ( v22 >= 0x400 )
    v22 = 1023;
  return httpd_cgi_ret(a1, (char *)&v42, v22, 4);
}
// 4AD698: variable 'v15' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8794: using guessed type int __fastcall jhl_ddns_add(_DWORD, _DWORD);
// 6A886C: using guessed type int __fastcall jhl_ddns_del(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

