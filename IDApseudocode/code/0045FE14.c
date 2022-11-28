int __fastcall sub_45FE14(int a1)
{
  char *v2; // $s7
  char *v3; // $s4
  char *v4; // $s1
  _BYTE *v6; // $v0
  void *v7; // $v0
  void *v8; // $s2
  _BYTE *v9; // $s3
  _DWORD *v10; // $s6
  char *v11; // $s1
  const char *v12; // $v0
  int v13; // $a0
  const char *v14; // $v0
  char *v15; // $v1
  int v16; // $t0
  int v17; // $a3
  int v18; // $a2
  int v19; // $a1
  const char *v20; // $s1
  int v21; // $a0
  const char *v22; // $v0
  int v23; // $fp
  int v24; // $a1
  int v25; // $a2
  int v26; // $a0
  const char *v27; // $v0
  const char *v28; // [sp+28h] [-240h] BYREF
  const char *v29; // [sp+2Ch] [-23Ch]
  const char *v30; // [sp+30h] [-238h]
  int v31; // [sp+34h] [-234h]
  int v32; // [sp+38h] [-230h]
  int v33; // [sp+3Ch] [-22Ch]
  char v34[256]; // [sp+128h] [-140h] BYREF
  int v35[8]; // [sp+228h] [-40h] BYREF
  int v36; // [sp+248h] [-20h]
  char *v37; // [sp+24Ch] [-1Ch]
  char *v38; // [sp+250h] [-18h]
  char *v39; // [sp+254h] [-14h]
  char *v40; // [sp+258h] [-10h]
  void *s; // [sp+25Ch] [-Ch]
  char *v42; // [sp+260h] [-8h]

  v40 = httpd_get_parm(a1, "en");
  v2 = httpd_get_parm(a1, "name");
  v39 = httpd_get_parm(a1, "old_name");
  v3 = httpd_get_parm(a1, "macs");
  v4 = httpd_get_parm(a1, "opt");
  v38 = httpd_get_parm(a1, "act");
  v37 = httpd_get_parm(a1, "time");
  v36 = httpd_get_json_parm(a1, (int)"del_list");
  if ( !v4 )
    goto LABEL_56;
  if ( !strcmp(v4, (const char *)&off_646D8C) || !strcmp(v4, (const char *)&off_648DDC) || !strcmp(v4, "del") )
  {
    if ( !strcmp(v4, "delall") )
      goto LABEL_7;
    if ( !strcmp(v4, (const char *)&off_64712C) )
    {
LABEL_23:
      v11 = httpd_get_parm(a1, (char *)&off_64712C);
      if ( v11 )
      {
        v12 = (const char *)nvram_get("macfilterAct");
        if ( !v12 || strcmp(v12, v11) )
        {
          nvram_set("macfilterAct", v11);
          v28 = "wys";
          v29 = "macfilter";
          v30 = "defaut_set";
          v31 = jhl_nv_get_def("macfilterAct");
          v32 = jhl_nv_get_def("macfilterWAN");
          v33 = 0;
          eval(&v28, 0, 0, 0);
          jhl_parm_commit(v13);
        }
      }
      v14 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      v15 = v34;
      do
      {
        v16 = *(_DWORD *)v14;
        v17 = *((_DWORD *)v14 + 1);
        v18 = *((_DWORD *)v14 + 2);
        v19 = *((_DWORD *)v14 + 3);
        v14 += 16;
        *(_DWORD *)v15 = v16;
        *((_DWORD *)v15 + 1) = v17;
        *((_DWORD *)v15 + 2) = v18;
        *((_DWORD *)v15 + 3) = v19;
        v15 += 16;
      }
      while ( v14 != "}" );
      JUMPOUT(0x46007C);
    }
    _mem_malloc(0x200000, "mac_filter_asp", 888);
    v8 = v7;
    _mem_malloc(0x200000, "mac_filter_asp", 889);
    v9 = v6;
    if ( v8 && v6 )
    {
      if ( !strcmp(v4, "del") && v36 && cJSON_IsArray(v36) )
      {
        v10 = *(_DWORD **)(v36 + 8);
        if ( !v10 || !v10[4] )
          goto LABEL_49;
        v42 = "a";
        v36 = 0;
        do
        {
          jhl_parm_get("macfilterAll", v8, 0x200000);
          if ( nvparm_del_str_too_loog(v8, 60, 6, v10[4], 124, 0, v9) )
          {
            v28 = "macfilter_del.sh";
            v29 = (const char *)v10[4];
            v30 = 0;
            eval(&v28, 0, 0, 0);
            jhl_parm_set("macfilterAll", v9);
            v36 = 1;
          }
          v10 = (_DWORD *)*v10;
        }
        while ( v10 && v10[4] );
LABEL_54:
        if ( !v36 )
          goto LABEL_49;
        goto LABEL_48;
      }
      if ( v2 || !strcmp(v4, (const char *)&off_64712C) )
      {
        if ( !strcmp(v4, (const char *)&off_648DDC) )
        {
          v42 = "a";
          jhl_parm_get("macfilterAll", v8, 0x200000);
          if ( v39 )
          {
            s = &v28;
            v28 = "macfilter_del.sh";
            v36 = nvparm_del_str_too_loog(v8, 60, 6, v39, 124, 0, v9) != 0;
            v29 = v39;
          }
          else
          {
            v36 = nvparm_del_str_too_loog(v8, 60, 6, v2, 124, 0, v9) != 0;
            s = &v28;
            v28 = "macfilter_del.sh";
            v29 = v2;
          }
          v30 = 0;
          eval(&v28, 0, 0, 0);
          if ( strcmp(v4, (const char *)&off_646D8C) && strcmp(v4, (const char *)&off_648DDC) )
            goto LABEL_54;
        }
        else
        {
          if ( strcmp(v4, (const char *)&off_646D8C) )
          {
LABEL_49:
            _mem_free(v8);
            _mem_free(v9);
            mac_filter_data(a1);
            goto LABEL_72;
          }
          v36 = 0;
          s = &v28;
        }
        memset(s, 0, 0x100u);
        if ( v3 && *v3 )
        {
          if ( !strcmp(v4, (const char *)&off_646D8C) )
          {
            v42 = "a";
            v23 = check_rule_num_limit(a1, 10, (int)"macfilterAll", 60, v34, 0x100u);
            if ( v23 > 0 )
            {
LABEL_59:
              _mem_free(v8);
              _mem_free(v9);
              httpd_cgi_ret(a1, v34, v23, 4);
LABEL_72:
              JUMPOUT(0x46009C);
            }
          }
          else
          {
            v42 = "a";
          }
          if ( !v38 || !*v38 )
            v38 = "1";
          if ( !v37 )
            v37 = "OFF";
          sprintf((char *)v8, "%s|%s|%s|%s|%s<", v2, v40, v3, v37, v38);
          if ( !v36 )
          {
            jhl_parm_get(v42 + 25912, v9, 0x200000);
            if ( !strcmp(v9, " ") )
              *v9 = 0;
          }
          strcat(v9, (char *)v8);
          v20 = (const char *)s;
          if ( !get_time_group(v37, s, 256) )
            v37 = (char *)v20;
          v35[0] = (int)"macfilter_add.sh";
          v35[1] = (int)v40;
          v35[4] = (int)v38;
          v35[2] = (int)v2;
          v35[3] = (int)v3;
          v35[5] = (int)v37;
          v35[6] = 0;
          eval(v35, 0, 0, 0);
LABEL_48:
          jhl_parm_set(v42 + 25912, v9);
          jhl_parm_commit(v21);
          goto LABEL_49;
        }
        v24 = *(unsigned __int8 *)(a1 + 210102);
        v25 = (int)&unk_646720;
      }
      else
      {
        v24 = *(unsigned __int8 *)(a1 + 210102);
        v25 = (int)&unk_6442E4;
      }
      v26 = 12;
    }
    else
    {
      v24 = *(unsigned __int8 *)(a1 + 210102);
      v25 = 0x200000;
      v26 = 4;
    }
    v27 = (const char *)_GET_LANG_TEXT(v26, v24, v25);
    v23 = snprintf(v34, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
    if ( (unsigned int)v23 >= 0x100 )
      v23 = 255;
    goto LABEL_59;
  }
  if ( !strcmp(v4, (const char *)&off_64712C) )
  {
    if ( !strcmp(v4, "delall") )
      goto LABEL_7;
    goto LABEL_23;
  }
  if ( strcmp(v4, "delall") )
  {
LABEL_56:
    v22 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    v23 = snprintf(v34, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v22);
    if ( (unsigned int)v23 >= 0x100 )
      v23 = 255;
    v9 = 0;
    v8 = 0;
    goto LABEL_59;
  }
LABEL_7:
  v28 = "macfilter_delall.sh";
  v29 = 0;
  eval(&v28, 0, 0, 0);
  return sub_460000();
}
// 4603F4: control flows out of bounds to 46007C
// 460650: control flows out of bounds to 46009C
// 460138: variable 'v7' is possibly undefined
// 460144: variable 'v6' is possibly undefined
// 4603A4: variable 'v13' is possibly undefined
// 4605FC: variable 'v21' is possibly undefined
// 460000: using guessed type int sub_460000(void);
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A87F8: using guessed type int __fastcall nvparm_del_str_too_loog(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

