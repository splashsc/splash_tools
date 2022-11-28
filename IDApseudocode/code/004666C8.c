int __fastcall sub_4666C8(int a1)
{
  char *v2; // $s6
  char *v3; // $s7
  int v4; // $fp
  char *v5; // $s3
  char *v6; // $v0
  void *v7; // $v0
  void *v8; // $s0
  char *v9; // $s1
  int v10; // $s5
  int v11; // $a1
  char *v12; // $a2
  int v13; // $a0
  const char *v14; // $v0
  unsigned int v15; // $s3
  const char *v17; // $v0
  _DWORD *v18; // $s3
  int v19; // $v0
  int v20; // $s6
  int v21; // $s7
  const char *v22; // $a0
  int v23; // $v0
  char *v24; // $v1
  const char *v25; // $v0
  char *v26; // $a0
  int v27; // $t0
  int v28; // $a3
  int v29; // $a2
  int v30; // $a1
  const char *v31; // $v0
  int v32; // $a1
  const char *v33; // $a2
  int v34; // $a0
  const char *v35; // $v0
  char s[256]; // [sp+28h] [-128h] BYREF
  const char *v37; // [sp+128h] [-28h] BYREF
  char *v38; // [sp+12Ch] [-24h]
  char *v39; // [sp+130h] [-20h]
  char *v40; // [sp+140h] [-10h]
  int v41; // [sp+144h] [-Ch]
  int v42; // [sp+148h] [-8h]

  v2 = httpd_get_parm(a1, "name");
  v40 = httpd_get_parm(a1, "old_name");
  v3 = httpd_get_parm(a1, "time");
  v4 = httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  _mem_malloc(102400, "time_group_asp", 1248);
  v8 = v7;
  _mem_malloc(102400, "time_group_asp", 1249);
  v9 = v6;
  if ( v8 )
  {
    if ( !v6 )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = (char *)102400;
      v13 = 4;
      goto LABEL_9;
    }
    if ( !v5 )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = "not opt";
      goto LABEL_8;
    }
    v41 = (int)"a";
    v10 = strcmp(v5, (const char *)&off_646D8C);
    if ( !v10 || !strcmp(v5, (const char *)&off_648DDC) )
    {
      if ( strcmp(v5, "del") )
        goto LABEL_17;
    }
    else if ( strcmp(v5, "del") )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = v5;
LABEL_8:
      v13 = 12;
LABEL_9:
      v14 = (const char *)_GET_LANG_TEXT(v13, v11, v12);
      goto LABEL_10;
    }
    if ( v4 )
    {
      v18 = *(_DWORD **)(v4 + 8);
      if ( v18 )
      {
        v40 = "i";
        v42 = 0;
        v41 = 102400;
        while ( 1 )
        {
          v20 = cJSON_GetObjectItem(v18, v40);
          v19 = cJSON_GetObjectItem(v18, "n");
          v21 = v19;
          if ( !v20 )
          {
            v32 = *(unsigned __int8 *)(a1 + 210102);
            v33 = "not i";
            v34 = 12;
            goto LABEL_59;
          }
          if ( !v19 )
          {
            v32 = *(unsigned __int8 *)(a1 + 210102);
            v33 = "not n";
            v34 = 12;
            goto LABEL_59;
          }
          v22 = *(const char **)(v20 + 16);
          v39 = *(char **)(v19 + 16);
          v37 = v22;
          v23 = time_group_is_used(v22);
          if ( v23 )
            break;
          jhl_parm_get("time_group", v8, v41);
          if ( nvparm_del_str(v8, 60, 5, v39, 124, 2, v9) )
          {
            jhl_parm_set("time_group", v9);
            v42 = 1;
          }
          v18 = (_DWORD *)*v18;
          if ( !v18 )
            goto LABEL_47;
        }
        v33 = *(const char **)(v21 + 16);
        v32 = *(unsigned __int8 *)(a1 + 210102);
        v34 = v23;
LABEL_59:
        v35 = (const char *)_GET_LANG_TEXT(v34, v32, v33);
        v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v35);
        if ( v15 >= 0x100 )
          v15 = 255;
        goto LABEL_50;
      }
      goto LABEL_46;
    }
LABEL_17:
    if ( !v2 )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = (char *)&unk_6442E4;
      v13 = 12;
      goto LABEL_9;
    }
    if ( !v3 )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = (char *)&unk_646EE4;
      v13 = 12;
      goto LABEL_9;
    }
    if ( v10 )
    {
      if ( strcmp(v5, (const char *)&off_648DDC) )
        goto LABEL_46;
    }
    else
    {
      jhl_parm_get("time_group", v8, 102400);
      if ( nvparm_find_str(v8, 60, 3, v2, 124, 2) )
        goto LABEL_64;
      if ( strcmp(v5, (const char *)&off_648DDC) )
      {
        v42 = 0;
        if ( strcmp(v5, (const char *)(v41 + 28044)) )
          goto LABEL_46;
        goto LABEL_54;
      }
    }
    if ( !v40 )
    {
      v40 = v2;
      goto LABEL_24;
    }
    if ( !strcmp(v40, v2) || (jhl_parm_get("time_group", v8, 102400), !nvparm_find_str(v8, 60, 3, v2, 124, 2)) )
    {
LABEL_24:
      jhl_parm_get("time_group", v8, 102400);
      if ( nvparm_get_str(v8, 60, 3, v40, 124, 2, &v37) )
      {
        v42 = J_atoi(v37);
        if ( strcmp(v38, v3) )
          time_group_modify((int)v37, (int)v3);
        jhl_parm_get("time_group", v8, 102400);
        nvparm_del_str(v8, 60, 3, v40, 124, 2, v9);
        jhl_parm_set("time_group", v9);
      }
      else
      {
        v42 = 0;
      }
      if ( strcmp(v5, (const char *)(v41 + 28044)) )
      {
        if ( !strcmp(v5, (const char *)&off_648DDC) )
        {
LABEL_28:
          v39 = v2;
          v38 = v3;
          jhl_parm_get("time_group", v8, 102400);
          if ( nvparm_find_str(v8, 60, 3, v2, 124, 2) )
          {
            v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "same name");
LABEL_10:
            v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
            if ( v15 >= 0x100 )
              v15 = 255;
            goto LABEL_12;
          }
          if ( !v42 )
          {
            jhl_parm_get("time_group", v8, 102400);
            v42 = time_group_get_id((int)v8);
          }
          v17 = (const char *)nvram_get("time_group");
          if ( !v17 )
            v17 = "";
          snprintf(v9, 102400, "%s%u|%s|%s<", v17, v42, v3, v2);
          jhl_parm_set("time_group", v9);
          v42 = 1;
          goto LABEL_47;
        }
LABEL_46:
        v42 = 0;
LABEL_47:
        v24 = s;
        v25 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        v26 = "}";
        do
        {
          v27 = *(_DWORD *)v25;
          v28 = *((_DWORD *)v25 + 1);
          v29 = *((_DWORD *)v25 + 2);
          v30 = *((_DWORD *)v25 + 3);
          v25 += 16;
          *(_DWORD *)v24 = v27;
          *((_DWORD *)v24 + 1) = v28;
          *((_DWORD *)v24 + 2) = v29;
          *((_DWORD *)v24 + 3) = v30;
          v24 += 16;
        }
        while ( v25 != "}" );
        v15 = 33;
        *(_WORD *)v24 = *(_WORD *)v25;
LABEL_50:
        if ( v42 )
          jhl_parm_commit(v26);
        goto LABEL_12;
      }
LABEL_54:
      v15 = check_rule_num_limit(a1, 19, (int)"time_group", 60, s, 0x100u);
      if ( (int)v15 > 0 )
      {
LABEL_12:
        _mem_free(v8);
        goto LABEL_13;
      }
      goto LABEL_28;
    }
LABEL_64:
    v11 = *(unsigned __int8 *)(a1 + 210102);
    v12 = "same name";
    v13 = 12;
    goto LABEL_9;
  }
  v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
  if ( v15 >= 0x100 )
    v15 = 255;
LABEL_13:
  if ( v9 )
    _mem_free(v9);
  return httpd_cgi_ret(a1, s, v15, 4);
}
// 4667C4: variable 'v7' is possibly undefined
// 4667D0: variable 'v6' is possibly undefined
// 466D90: variable 'v26' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86B0: using guessed type int __fastcall nvparm_get_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

