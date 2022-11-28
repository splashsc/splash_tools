int __fastcall sub_496CB8(int a1)
{
  char *v2; // $fp
  char *v3; // $s6
  int v4; // $s7
  char *v5; // $s2
  char *v6; // $v0
  char *v7; // $v0
  char *v8; // $s4
  char *v9; // $s1
  int v10; // $v0
  int v11; // $a0
  char *v12; // $v1
  const char *v13; // $v0
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  int v18; // $s5
  int v20; // $a1
  const char *v21; // $a2
  int v22; // $a0
  _DWORD *v23; // $s6
  const char *v24; // $v0
  const char *v25; // $v0
  int v26; // $v0
  char s[256]; // [sp+28h] [-118h] BYREF
  char *v28; // [sp+128h] [-18h]
  char *v29; // [sp+12Ch] [-14h]
  char *v30; // [sp+130h] [-10h]
  char *v31; // [sp+134h] [-Ch]
  char *v32; // [sp+138h] [-8h]
  char *v33; // [sp+13Ch] [-4h]

  v2 = httpd_get_parm(a1, "dest");
  v28 = httpd_get_parm(a1, "gateway");
  v29 = httpd_get_parm(a1, "mask");
  v30 = httpd_get_parm(a1, "metric");
  v31 = httpd_get_parm(a1, "ifname");
  v3 = httpd_get_parm(a1, "name");
  v32 = httpd_get_parm(a1, "old_name");
  v4 = httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  _mem_malloc(102400, "router_asp", 228);
  v8 = v7;
  _mem_malloc(102400, "router_asp", 229);
  v9 = v6;
  if ( v8 )
  {
    if ( !v6 )
    {
      v20 = *(unsigned __int8 *)(a1 + 210102);
      v21 = (const char *)102400;
      v22 = 4;
      goto LABEL_41;
    }
    v10 = a1 + 196608;
    if ( !v5 )
    {
LABEL_40:
      v20 = *(unsigned __int8 *)(v10 + 13494);
      v21 = "not opt";
      v22 = 12;
      goto LABEL_41;
    }
    if ( !strcmp(v5, (const char *)&off_646D8C) || !strcmp(v5, (const char *)&off_648DDC) )
    {
      if ( !strcmp(v5, "delall") )
        goto LABEL_8;
      if ( strcmp(v5, "del") )
        goto LABEL_18;
    }
    else
    {
      if ( strcmp(v5, "del") )
      {
        if ( !strcmp(v5, "delall") )
        {
LABEL_8:
          jhl_parm_set("routes_static", v9);
          jhl_parm_commit(v11);
          goto LABEL_9;
        }
        v10 = a1 + 196608;
        goto LABEL_40;
      }
      if ( !strcmp(v5, "delall") )
        goto LABEL_8;
    }
    if ( v4 && cJSON_IsArray(v4) )
    {
      v23 = *(_DWORD **)(v4 + 8);
      if ( !v23 || !v23[4] )
        goto LABEL_9;
      v32 = 0;
      v28 = "routes_static";
      do
      {
        jhl_parm_get("routes_static", v8, 102400);
        if ( nvparm_del_str(v8, 62, 8, v23[4], 60, 5, v9) )
        {
          jhl_parm_set(v28, v9);
          v32 = (char *)1;
        }
        v23 = (_DWORD *)*v23;
      }
      while ( v23 && v23[4] );
LABEL_46:
      if ( v32 )
        goto LABEL_8;
LABEL_9:
      jhl_gl_restart_jhttpd("routing-restart", 500);
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
      goto LABEL_12;
    }
LABEL_18:
    if ( v3 )
    {
      if ( v2 )
      {
        if ( v28 )
        {
          if ( v29 )
          {
            if ( v30 )
            {
              if ( v31 )
              {
                v33 = "1\"";
                if ( !strcmp(v5, (const char *)&off_648DDC) )
                {
                  jhl_parm_get("routes_static", v8, 102400);
                  if ( v32 )
                    v26 = nvparm_del_str(v8, 62, 8, v32, 60, 5, v9);
                  else
                    v26 = nvparm_del_str(v8, 62, 8, v3, 60, 5, v9);
                  v32 = (char *)(v26 != 0);
                  if ( strcmp(v5, (const char *)&off_646D8C) )
                  {
                    if ( strcmp(v5, v33 - 29220) )
                      goto LABEL_46;
LABEL_52:
                    sprintf(v8, "%s<%s<%s<%s<%s<%s>", v2, v28, v29, v30, v31, v3);
                    if ( !v32 )
                    {
                      jhl_parm_get("routes_static", v9, 102400);
                      if ( !strcmp(v9, " ") )
                        *v9 = 0;
                    }
                    strcat(v9, v8);
                    goto LABEL_8;
                  }
                }
                else
                {
                  if ( strcmp(v5, (const char *)&off_646D8C) )
                    goto LABEL_9;
                  v32 = 0;
                }
                jhl_parm_get("routes_static", v9, 102400);
                if ( nvparm_find_str(v9, 62, 8, v3, 60, 5) )
                {
                  v20 = *(unsigned __int8 *)(a1 + 210102);
                  v21 = "same name";
                  v22 = 12;
                  goto LABEL_41;
                }
                v18 = check_rule_num_limit(a1, 23, (int)"routes_static", 62, s, 0x100u);
                if ( v18 > 0 )
                {
LABEL_12:
                  _mem_free(v8);
                  goto LABEL_13;
                }
                goto LABEL_52;
              }
              v20 = *(unsigned __int8 *)(a1 + 210102);
              v21 = (const char *)&unk_64BE28;
              v22 = 12;
            }
            else
            {
              v20 = *(unsigned __int8 *)(a1 + 210102);
              v21 = (const char *)&unk_64BE1C;
              v22 = 12;
            }
          }
          else
          {
            v20 = *(unsigned __int8 *)(a1 + 210102);
            v21 = (const char *)&unk_64BE10;
            v22 = 12;
          }
        }
        else
        {
          v20 = *(unsigned __int8 *)(a1 + 210102);
          v21 = (const char *)&unk_64BE04;
          v22 = 12;
        }
      }
      else
      {
        v20 = *(unsigned __int8 *)(a1 + 210102);
        v21 = (const char *)&unk_64BDF8;
        v22 = 12;
      }
    }
    else
    {
      v20 = *(unsigned __int8 *)(a1 + 210102);
      v21 = (const char *)&unk_6442E4;
      v22 = 12;
    }
LABEL_41:
    v24 = (const char *)_GET_LANG_TEXT(v22, v20, v21);
    v18 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
    if ( (unsigned int)v18 >= 0x100 )
      v18 = 255;
    goto LABEL_12;
  }
  v25 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v18 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
  if ( (unsigned int)v18 >= 0x100 )
    v18 = 255;
LABEL_13:
  if ( v9 )
    _mem_free(v9);
  return httpd_cgi_ret(a1, s, v18, 4);
}
// 496E24: variable 'v7' is possibly undefined
// 496E30: variable 'v6' is possibly undefined
// 496EEC: variable 'v11' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

