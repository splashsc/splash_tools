int __fastcall sub_44A1B8(int a1)
{
  char *v2; // $s4
  char *v3; // $s6
  int v4; // $s5
  char *v5; // $v0
  char *v6; // $v0
  char *v7; // $s0
  char *v8; // $s1
  int v9; // $v0
  _DWORD *v10; // $fp
  const char *v11; // $a0
  int v12; // $s4
  int v13; // $s7
  char *v15; // $v1
  const char *v16; // $v0
  int v17; // $t0
  int v18; // $a3
  int v19; // $a2
  int v20; // $a1
  int v21; // $a1
  const char *v22; // $a2
  int v23; // $a0
  const char *v24; // $v0
  char *v25; // $s4
  int v26; // $v0
  char s[256]; // [sp+28h] [-110h] BYREF
  char *v28; // [sp+128h] [-10h]
  char *v29; // [sp+12Ch] [-Ch]
  const char *v30; // [sp+130h] [-8h]

  v2 = httpd_get_parm(a1, "opt");
  v3 = httpd_get_parm(a1, "name");
  v29 = httpd_get_parm(a1, "old_name");
  v4 = httpd_get_json_parm(a1, (int)"del_list");
  _mem_malloc(102400, "wan_group_asp", 4979);
  v7 = v6;
  _mem_malloc(102400, "wan_group_asp", 4980);
  v8 = v5;
  if ( v7 && v5 )
  {
    v9 = a1 + 196608;
    if ( v2 )
    {
      if ( !strcmp(v2, (const char *)&off_646D8C) || !strcmp(v2, (const char *)&off_648DDC) )
      {
        if ( strcmp(v2, "del") )
          goto LABEL_17;
        goto LABEL_7;
      }
      if ( !strcmp(v2, "del") )
      {
LABEL_7:
        if ( v4 && cJSON_IsArray(v4) )
        {
          v10 = *(_DWORD **)(v4 + 8);
          if ( !v10 )
            goto LABEL_23;
          v11 = (const char *)v10[4];
          if ( !v11 )
            goto LABEL_23;
          v28 = "a";
          v29 = 0;
          v12 = 0;
          v30 = "wan_groups";
          do
          {
            v12 += _wan_group_modify(v11, (int)"");
            jhl_parm_get("wan_groups", v7, 102400);
            if ( nvparm_del_str(v7, 60, 4, v10[4], 124, 0, v8) )
            {
              jhl_parm_set(v30, v8);
              v29 = (char *)1;
            }
            v10 = (_DWORD *)*v10;
            if ( !v10 )
              break;
            v11 = (const char *)v10[4];
          }
          while ( v11 );
          if ( !v29 )
          {
            if ( !v12 )
            {
LABEL_23:
              v15 = s;
              v16 = "{\"code\":0,\"error\":\"\",\"data\":null}";
              do
              {
                v17 = *(_DWORD *)v16;
                v18 = *((_DWORD *)v16 + 1);
                v19 = *((_DWORD *)v16 + 2);
                v20 = *((_DWORD *)v16 + 3);
                v16 += 16;
                *(_DWORD *)v15 = v17;
                *((_DWORD *)v15 + 1) = v18;
                *((_DWORD *)v15 + 2) = v19;
                *((_DWORD *)v15 + 3) = v20;
                v15 += 16;
              }
              while ( v16 != "}" );
              v13 = 33;
              *(_WORD *)v15 = *(_WORD *)v16;
              goto LABEL_21;
            }
LABEL_37:
            jhl_parm_commit(v11);
            goto LABEL_23;
          }
LABEL_36:
          jhl_parm_set(v28 + 17112, v8);
          goto LABEL_37;
        }
LABEL_17:
        if ( v3 )
        {
          if ( strcmp(v2, (const char *)&off_646D8C) )
          {
            if ( strcmp(v2, (const char *)&off_648DDC) )
              goto LABEL_23;
            v28 = "a";
            goto LABEL_20;
          }
          v28 = "a";
          jhl_parm_get("wan_groups", v8, 102400);
          if ( !nvparm_find_str(v8, 60, 4, v3, 124, 0) )
          {
LABEL_20:
            v13 = check_rule_num_limit(a1, 40, (int)(v28 + 17112), 60, s, 0x100u);
            if ( v13 > 0 )
              goto LABEL_21;
            if ( !strcmp(v2, (const char *)&off_648DDC)
              && ((jhl_parm_get(v28 + 17112, v7, 102400), (v25 = v29) == 0) ? (v26 = nvparm_del_str(
                                                                                       v7,
                                                                                       60,
                                                                                       4,
                                                                                       v3,
                                                                                       124,
                                                                                       0,
                                                                                       v8)) : (_wan_group_modify(
                                                                                                 v29,
                                                                                                 (int)v3),
                                                                                               v26 = nvparm_del_str(v7, 60, 4, v25, 124, 0, v8)),
                  v26) )
            {
              sprintf(v7, "%s<", v3);
            }
            else
            {
              sprintf(v7, "%s<", v3);
              jhl_parm_get(v28 + 17112, v8, 102400);
              if ( !strcmp(v8, " ") )
                *v8 = 0;
            }
            strcat(v8, v7);
            goto LABEL_36;
          }
          v21 = *(unsigned __int8 *)(a1 + 210102);
          v22 = "same name";
        }
        else
        {
          v21 = *(unsigned __int8 *)(a1 + 210102);
          v22 = (const char *)&unk_6442E4;
        }
        goto LABEL_29;
      }
      v9 = a1 + 196608;
    }
    v21 = *(unsigned __int8 *)(v9 + 13494);
    v22 = "not opt";
LABEL_29:
    v23 = 12;
    goto LABEL_30;
  }
  v21 = *(unsigned __int8 *)(a1 + 210102);
  v22 = (const char *)102400;
  v23 = 4;
LABEL_30:
  v24 = (const char *)_GET_LANG_TEXT(v23, v21, v22);
  v13 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
  if ( (unsigned int)v13 >= 0x100 )
    v13 = 255;
LABEL_21:
  _mem_free(v7);
  _mem_free(v8);
  return httpd_cgi_ret(a1, s, v13, 4);
}
// 44A298: variable 'v6' is possibly undefined
// 44A2A4: variable 'v5' is possibly undefined
// 44A704: variable 'v11' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

