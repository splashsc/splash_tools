int __fastcall sub_4657C0(int a1)
{
  char *v2; // $s7
  int v3; // $s6
  char *v4; // $s0
  char *v5; // $v0
  void *v6; // $v0
  void *v7; // $s1
  char *v8; // $s2
  int v9; // $a1
  char *v10; // $a2
  int v11; // $a0
  int v12; // $s5
  const char *v13; // $v0
  int v14; // $s6
  _DWORD *v16; // $s0
  int v17; // $v0
  int v18; // $s6
  int v19; // $s7
  int v20; // $a0
  int v21; // $v0
  char *v22; // $v1
  const char *v23; // $v0
  int v24; // $t0
  int v25; // $a3
  int v26; // $a2
  int v27; // $a1
  int v28; // $fp
  int v29; // $a0
  const char *v30; // $v0
  int v31; // $v0
  char s[1024]; // [sp+28h] [-430h] BYREF
  char *v33; // [sp+428h] [-30h] BYREF
  char *v34; // [sp+42Ch] [-2Ch]
  char *v35; // [sp+430h] [-28h]
  int v36; // [sp+434h] [-24h]
  int v37; // [sp+438h] [-20h]
  char *v38; // [sp+440h] [-18h]
  char *v39; // [sp+444h] [-14h]
  char *v40; // [sp+448h] [-10h]
  int v41; // [sp+44Ch] [-Ch]
  int v42; // [sp+450h] [-8h]

  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v2 = httpd_get_parm(a1, "name");
  v39 = httpd_get_parm(a1, "old_name");
  v38 = httpd_get_parm(a1, "ips");
  v3 = httpd_get_json_parm(a1, (int)"del_list");
  v4 = httpd_get_parm(a1, "opt");
  _mem_malloc(1024000, "ips_group_asp", 969);
  v7 = v6;
  _mem_malloc(1024000, "ips_group_asp", 970);
  v8 = v5;
  if ( v7 )
  {
    if ( !v5 )
    {
      v9 = *(unsigned __int8 *)(a1 + 210102);
      v10 = (char *)1024000;
      v11 = 4;
      goto LABEL_16;
    }
    if ( !v4 )
    {
LABEL_8:
      v9 = *(unsigned __int8 *)(a1 + 210102);
      v10 = "not opt";
      v11 = 12;
      goto LABEL_16;
    }
    if ( !strcmp(v4, (const char *)&off_646D8C) || (v40 = "1\"", !strcmp(v4, (const char *)&off_648DDC)) )
    {
      if ( strcmp(v4, "delall") )
      {
        v42 = 0;
LABEL_11:
        if ( !strcmp(v4, "del") && v3 )
        {
          v16 = *(_DWORD **)(v3 + 8);
          if ( v16 )
            goto LABEL_26;
          goto LABEL_35;
        }
        v12 = strcmp(v4, (const char *)&off_646D8C);
        if ( v12 && strcmp(v4, (const char *)&off_648DDC) )
          goto LABEL_35;
        goto LABEL_13;
      }
    }
    else if ( !strcmp(v4, "del") )
    {
      if ( strcmp(v4, "delall") )
      {
        if ( v3 )
        {
          v16 = *(_DWORD **)(v3 + 8);
          v42 = 0;
          if ( v16 )
          {
LABEL_26:
            v39 = "a";
            v40 = "a";
            v41 = 1024000;
            v38 = "dns_more_hitype";
            while ( 1 )
            {
              v18 = cJSON_GetObjectItem(v16, v39 + 28312);
              v17 = cJSON_GetObjectItem(v16, v40 + 28320);
              v19 = v17;
              if ( !v18 )
              {
                v9 = *(unsigned __int8 *)(a1 + 210102);
                v10 = "not i";
                v11 = 12;
                goto LABEL_16;
              }
              if ( !v17 )
              {
                v9 = *(unsigned __int8 *)(a1 + 210102);
                v10 = "not n";
                v11 = 12;
                goto LABEL_16;
              }
              v20 = *(_DWORD *)(v18 + 16);
              v33 = *(char **)(v17 + 16);
              v21 = ips_group_is_used(v20);
              if ( v21 )
              {
                v10 = *(char **)(v19 + 16);
                v9 = *(unsigned __int8 *)(a1 + 210102);
                v11 = v21;
                goto LABEL_16;
              }
              if ( set_dns_more_hitype_to_kernel("del", &v33) < 0 )
                break;
              jhl_parm_get(v38, v7, v41);
              if ( nvparm_del_str(v7, 60, 3, v33, 124, 0, v8) )
              {
                jhl_parm_set(v38, v8);
                v42 = 1;
              }
              v16 = (_DWORD *)*v16;
              if ( !v16 )
                goto LABEL_35;
            }
            if ( v42 )
              jhl_parm_commit(v38);
            v10 = v33;
            v9 = *(unsigned __int8 *)(a1 + 210102);
            v11 = 31;
            goto LABEL_16;
          }
          goto LABEL_36;
        }
        v12 = strcmp(v4, (const char *)&off_646D8C);
        if ( strcmp(v4, v40 - 29220) )
        {
LABEL_36:
          v22 = s;
          v23 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          do
          {
            v24 = *(_DWORD *)v23;
            v25 = *((_DWORD *)v23 + 1);
            v26 = *((_DWORD *)v23 + 2);
            v27 = *((_DWORD *)v23 + 3);
            v23 += 16;
            *(_DWORD *)v22 = v24;
            *((_DWORD *)v22 + 1) = v25;
            *((_DWORD *)v22 + 2) = v26;
            *((_DWORD *)v22 + 3) = v27;
            v22 += 16;
          }
          while ( v23 != "}" );
          v14 = 33;
          *(_WORD *)v22 = *(_WORD *)v23;
LABEL_18:
          _mem_free(v7);
          goto LABEL_19;
        }
        v42 = 0;
LABEL_13:
        if ( v2 && *v2 )
        {
          if ( v38 && strlen(v38) >= 7 )
          {
            if ( !v12 )
            {
              v14 = check_rule_num_limit(a1, 18, (int)"dns_more_hitype", 60, s, 0x400u);
              if ( v14 > 0 )
                goto LABEL_18;
            }
            v33 = v2;
            v34 = "0";
            v35 = v38;
            if ( v39 )
            {
              dns_more_hitype_del(v39, &v33);
              v28 = dns_more_hitype_add(v33, v34, v35);
            }
            else
            {
              v28 = set_dns_more_hitype_to_kernel(v4, &v33);
            }
            if ( v28 >= 0 )
            {
              if ( !strcmp(v4, (const char *)&off_648DDC)
                && ((jhl_parm_get("dns_more_hitype", v7, 1024000), !v39) ? (v31 = nvparm_del_str(
                                                                                    v7,
                                                                                    60,
                                                                                    5,
                                                                                    v2,
                                                                                    124,
                                                                                    0,
                                                                                    v8)) : (v31 = nvparm_del_str(
                                                                                                    v7,
                                                                                                    60,
                                                                                                    5,
                                                                                                    v39,
                                                                                                    124,
                                                                                                    0,
                                                                                                    v8)),
                    v31) )
              {
                sprintf((char *)v7, "%s|%d|%s<", v33, v28, v35);
              }
              else
              {
                sprintf((char *)v7, "%s|%d|%s<", v33, v28, v35);
                if ( !v42 )
                {
                  jhl_parm_get("dns_more_hitype", v8, 1024000);
                  if ( !strcmp(v8, " ") )
                    *v8 = 0;
                }
              }
              strcat(v8, (char *)v7);
LABEL_50:
              jhl_parm_set("dns_more_hitype", v8);
              jhl_parm_commit(v29);
              goto LABEL_36;
            }
LABEL_35:
            if ( !v42 )
              goto LABEL_36;
            goto LABEL_50;
          }
          v9 = *(unsigned __int8 *)(a1 + 210102);
          v10 = "not ips";
          v11 = 12;
        }
        else
        {
          v9 = *(unsigned __int8 *)(a1 + 210102);
          v10 = (char *)&unk_6442E4;
          v11 = 12;
        }
LABEL_16:
        v13 = (const char *)_GET_LANG_TEXT(v11, v9, v10);
        v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
        if ( (unsigned int)v14 >= 0x400 )
          v14 = 1023;
        goto LABEL_18;
      }
    }
    else if ( strcmp(v4, "delall") )
    {
      goto LABEL_8;
    }
    if ( dns_more_hitype_delall() < 0 )
    {
      v9 = *(unsigned __int8 *)(a1 + 210102);
      v10 = "";
      v11 = 31;
      goto LABEL_16;
    }
    memset(v8, 0, 0xFA000u);
    v42 = 1;
    goto LABEL_11;
  }
  v30 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
  v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v30);
  if ( (unsigned int)v14 >= 0x400 )
    v14 = 1023;
LABEL_19:
  if ( v8 )
    _mem_free(v8);
  return httpd_cgi_ret(a1, s, v14, 4);
}
// 4658D0: variable 'v6' is possibly undefined
// 4658DC: variable 'v5' is possibly undefined
// 465E68: variable 'v29' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81A0: using guessed type int __fastcall dns_more_hitype_del(_DWORD, _DWORD);
// 6A8230: using guessed type int dns_more_hitype_delall(void);
// 6A82D4: using guessed type int __fastcall set_dns_more_hitype_to_kernel(_DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A87DC: using guessed type int __fastcall dns_more_hitype_add(_DWORD, _DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

