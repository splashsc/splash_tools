int __fastcall sub_4A6154(int a1)
{
  char *v2; // $s5
  char *v3; // $s7
  int v4; // $s6
  char *v5; // $s3
  char *v6; // $v0
  char *v7; // $v0
  char *v8; // $s2
  char *v9; // $s1
  int v10; // $v0
  int v11; // $a0
  char *v12; // $v1
  const char *v13; // $v0
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  int v18; // $s6
  char *v20; // $a3
  _DWORD *v21; // $fp
  int v22; // $s7
  int v23; // $a1
  int v24; // $a2
  int v25; // $a0
  const char *v26; // $v0
  const char *v27; // $v0
  char s[1024]; // [sp+28h] [-410h] BYREF
  char *v29; // [sp+428h] [-10h]
  char *v30; // [sp+42Ch] [-Ch]
  char *v31; // [sp+430h] [-8h]
  char *v32; // [sp+434h] [-4h]

  v2 = httpd_get_parm(a1, "name");
  v3 = httpd_get_parm(a1, "old_name");
  v29 = httpd_get_parm(a1, "en");
  v30 = httpd_get_parm(a1, "inip");
  v31 = httpd_get_parm(a1, "wan");
  v4 = httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  _mem_malloc(0x200000, "upnp_asp", 755);
  v8 = v7;
  _mem_malloc(0x200000, "upnp_asp", 756);
  v9 = v6;
  if ( v8 )
  {
    if ( !v6 )
    {
      v23 = *(unsigned __int8 *)(a1 + 210102);
      v24 = 0x200000;
      v25 = 4;
      goto LABEL_46;
    }
    v10 = a1 + 196608;
    if ( !v5 )
    {
LABEL_45:
      v23 = *(unsigned __int8 *)(v10 + 13494);
      v24 = (int)"not opt";
      v25 = 12;
      goto LABEL_46;
    }
    if ( !strcmp(v5, (const char *)&off_646D8C) || !strcmp(v5, (const char *)&off_648DDC) )
    {
      if ( !strcmp(v5, "delall") )
        goto LABEL_8;
      if ( strcmp(v5, "del") )
        goto LABEL_19;
    }
    else
    {
      if ( strcmp(v5, "del") )
      {
        if ( !strcmp(v5, "delall") )
        {
LABEL_8:
          *v9 = 32;
          v9[1] = 0;
          v32 = "1\"";
LABEL_9:
          jhl_parm_set(v32 - 11988, v9);
          jhl_parm_commit(v11);
LABEL_10:
          v12 = s;
          v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          do
          {
            v14 = *(_DWORD *)v13;
            v15 = *((_DWORD *)v13 + 1);
            v16 = *((_DWORD *)v13 + 2);
            v17 = *((_DWORD *)v13 + 3);
            v13 += 16;
            *(_DWORD *)v12 = v14;
            *((_DWORD *)v12 + 1) = v15;
            *((_DWORD *)v12 + 2) = v16;
            *((_DWORD *)v12 + 3) = v17;
            v12 += 16;
          }
          while ( v13 != "}" );
          v18 = 33;
          *(_WORD *)v12 = *(_WORD *)v13;
          goto LABEL_13;
        }
        v10 = a1 + 196608;
        goto LABEL_45;
      }
      if ( !strcmp(v5, "delall") )
        goto LABEL_8;
    }
    if ( v4 && cJSON_IsArray(v4) )
    {
      v21 = *(_DWORD **)(v4 + 8);
      if ( !v21 || !v21[4] )
        goto LABEL_10;
      v22 = 0;
      v32 = "1\"";
      v29 = "upnp_list";
      do
      {
        jhl_parm_get("upnp_list", v8, 0x200000);
        if ( nvparm_del_str(v8, 60, 6, v21[4], 124, 1, v9) )
        {
          jhl_parm_set(v29, v9);
          v22 = 1;
        }
        v21 = (_DWORD *)*v21;
      }
      while ( v21 && v21[4] );
      if ( !v22 )
        goto LABEL_10;
      goto LABEL_9;
    }
LABEL_19:
    if ( v2 )
    {
      if ( strcmp(v5, (const char *)&off_646D8C) && strcmp(v5, (const char *)&off_648DDC) )
        goto LABEL_10;
      v32 = "1\"";
      jhl_parm_get("upnp_list", v8, 0x200000);
      if ( v3 )
        v20 = v3;
      else
        v20 = v2;
      if ( nvparm_del_str(v8, 60, 6, v20, 124, 1, v9) )
      {
        if ( strcmp(v5, (const char *)&off_646D8C) )
        {
          sprintf(v8, "%s|%s|%s|%s<", v29, v2, v30, v31);
LABEL_27:
          strcat(v9, v8);
          goto LABEL_9;
        }
        v18 = check_rule_num_limit(a1, 27, (int)(v32 - 11988), 60, s, 0x400u);
        if ( v18 <= 0 )
        {
          sprintf(v8, "%s|%s|%s|%s<", v29, v2, v30, v31);
          goto LABEL_27;
        }
LABEL_13:
        _mem_free(v8);
        goto LABEL_14;
      }
      if ( !strcmp(v5, (const char *)&off_646D8C) )
      {
        v18 = check_rule_num_limit(a1, 27, (int)(v32 - 11988), 60, s, 0x400u);
        if ( v18 > 0 )
          goto LABEL_13;
        sprintf(v8, "%s|%s|%s|%s<", v29, v2, v30, v31);
      }
      else
      {
        sprintf(v8, "%s|%s|%s|%s<", v29, v2, v30, v31);
      }
      jhl_parm_get(v32 - 11988, v9, 0x200000);
      if ( !strcmp(v9, " ") )
        *v9 = 0;
      goto LABEL_27;
    }
    v23 = *(unsigned __int8 *)(a1 + 210102);
    v24 = (int)&unk_6442E4;
    v25 = 12;
LABEL_46:
    v26 = (const char *)_GET_LANG_TEXT(v25, v23, v24);
    v18 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v26);
    if ( (unsigned int)v18 >= 0x400 )
      v18 = 1023;
    goto LABEL_13;
  }
  v27 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v18 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
  if ( (unsigned int)v18 >= 0x400 )
    v18 = 1023;
LABEL_14:
  if ( v9 )
    _mem_free(v9);
  return httpd_cgi_ret(a1, s, v18, 4);
}
// 4A6284: variable 'v7' is possibly undefined
// 4A6290: variable 'v6' is possibly undefined
// 4A6360: variable 'v11' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

