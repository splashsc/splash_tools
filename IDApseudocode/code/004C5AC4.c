int __fastcall sub_4C5AC4(int a1)
{
  char *v2; // $s2
  char *v3; // $s6
  char *v4; // $s7
  char *v5; // $v0
  char *v6; // $s4
  int v7; // $fp
  void *v8; // $v0
  void *v9; // $s1
  void *v10; // $v0
  _DWORD *v11; // $s4
  int v12; // $s6
  int v13; // $a0
  unsigned int v14; // $s5
  int v16; // $a1
  int v17; // $a2
  int v18; // $a0
  const char *v19; // $v0
  int v20; // $a1
  const char *v21; // $a2
  int v22; // $a0
  const char *v23; // $v0
  char *v24; // $v1
  const char *v25; // $v0
  int v26; // $t0
  int v27; // $a3
  int v28; // $a2
  int v29; // $a1
  char *v30; // $s4
  const char *v31; // $v0
  char v32[1024]; // [sp+28h] [-430h] BYREF
  char *v33; // [sp+428h] [-30h] BYREF
  char *v34; // [sp+42Ch] [-2Ch]
  char *v35; // [sp+430h] [-28h]
  char *v36; // [sp+434h] [-24h]
  int v37; // [sp+438h] [-20h]
  int v38; // [sp+43Ch] [-1Ch]
  char *s; // [sp+440h] [-18h]
  void *v40; // [sp+444h] [-14h]
  char *v41; // [sp+448h] [-10h]
  char *v42; // [sp+44Ch] [-Ch]
  char *v43; // [sp+450h] [-8h]
  int v44; // [sp+454h] [-4h]

  s = v32;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  memset(v32, 0, sizeof(v32));
  v2 = httpd_get_parm(a1, "opt");
  v3 = httpd_get_parm(a1, "name");
  v4 = httpd_get_parm(a1, "dst");
  v41 = httpd_get_parm(a1, "gw");
  v42 = httpd_get_parm(a1, "dev");
  v5 = httpd_get_parm(a1, "old_name");
  v43 = "a";
  v6 = v5;
  v7 = httpd_get_json_parm(a1, (int)"del_list");
  if ( strcmp((const char *)&off_646D8C, v2) && strcmp("del", v2) && strcmp((const char *)&off_648DDC, v2) )
  {
    v16 = *(unsigned __int8 *)(a1 + 210102);
    v17 = (int)"not opt";
    v18 = 12;
    goto LABEL_28;
  }
  _mem_malloc(102400, "ipv6_router_asp", 630);
  v9 = v8;
  if ( !v8 )
  {
    v16 = *(unsigned __int8 *)(a1 + 210102);
    v17 = 102400;
    v18 = 4;
LABEL_28:
    v19 = (const char *)_GET_LANG_TEXT(v18, v16, v17);
    v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
    if ( v14 >= 0x400 )
      v14 = 1023;
    return httpd_cgi_ret(a1, s, v14, 4);
  }
  _mem_malloc(102400, "ipv6_router_asp", 637);
  v40 = v10;
  if ( v10 )
  {
    v44 = (int)"1\"";
    if ( !strcmp("del", v2) && v7 && cJSON_IsArray(v7) )
    {
      v11 = *(_DWORD **)(v7 + 8);
      if ( !v11 )
        goto LABEL_48;
      v12 = v11[4];
      if ( !v12 )
        goto LABEL_48;
      v44 = 0;
      v42 = "ipv6_router_static";
      v41 = (char *)102400;
      v43 = "ipv6_router_static";
      do
      {
        jhl_parm_get(v42, v9, v41);
        if ( nvparm_get_str(v9, 60, 6, v12, 124, 3, &v33) )
        {
          if ( !ipv6_router_set_to_server(v2, &v33) )
          {
            jhl_parm_get(v43, v9, v41);
            if ( nvparm_del_str(v9, 60, 6, v12, 124, 3, v40) )
            {
              nvram_set(v42, v40);
              v44 = 1;
            }
          }
        }
        v11 = (_DWORD *)*v11;
        if ( !v11 )
          break;
        v12 = v11[4];
      }
      while ( v12 );
LABEL_47:
      if ( !v44 )
        goto LABEL_48;
      goto LABEL_56;
    }
    if ( v3 )
    {
      if ( strcmp(v2, (const char *)&off_648DDC) )
        goto LABEL_21;
      if ( !v6 )
      {
        v20 = *(unsigned __int8 *)(a1 + 210102);
        v21 = (const char *)&unk_650A48;
        v22 = 12;
        goto LABEL_45;
      }
      jhl_parm_get("ipv6_router_static", v9, 102400);
      if ( nvparm_get_str(v9, 60, 6, v3, 124, 3, &v33)
        && !ipv6_router_set_to_server(v44 - 15196, &v33)
        && (jhl_parm_get("ipv6_router_static", v9, 102400), nvparm_del_str(v9, 60, 6, v3, 124, 3, v40)) )
      {
        nvram_set("ipv6_router_static", v40);
        v44 = 1;
      }
      else
      {
LABEL_21:
        v44 = 0;
      }
      if ( !strcmp(v43 + 28044, v2) )
      {
        v14 = check_rule_num_limit(a1, 33, (int)"ipv6_router_static", 62, s, 0x400u);
        if ( (int)v14 > 0 )
        {
LABEL_24:
          _mem_free(v9);
          _mem_free(v40);
          return httpd_cgi_ret(a1, s, v14, 4);
        }
      }
      else if ( strcmp((const char *)&off_648DDC, v2) )
      {
        goto LABEL_47;
      }
      jhl_parm_get("ipv6_router_static", v9, 102400);
      if ( nvparm_find_str(v9, 60, 6, v3, 124, 3) )
      {
        v20 = *(unsigned __int8 *)(a1 + 210102);
        v21 = "same name";
        v22 = 12;
      }
      else
      {
        if ( !*v3 )
          v3 = "";
        v36 = v3;
        if ( !v4 || !*v4 )
          v4 = "";
        v33 = v4;
        if ( !v41 || !*v41 )
          v41 = "";
        v34 = v41;
        if ( !v42 || !*v42 )
          v42 = "";
        v35 = v42;
        if ( !ipv6_router_set_to_server(v2, &v33) )
        {
          v30 = (char *)v40;
          snprintf((char *)v40, 102400, "%s|%s|%s|%s<", v4, v41, v42, v3);
          jhl_parm_get("ipv6_router_static", v9, 102400);
          strcat((char *)v9, v30);
          nvram_set("ipv6_router_static", v9);
LABEL_56:
          jhl_parm_commit(v13);
LABEL_48:
          v24 = s;
          v25 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          do
          {
            v26 = *(_DWORD *)v25;
            v27 = *((_DWORD *)v25 + 1);
            v28 = *((_DWORD *)v25 + 2);
            v29 = *((_DWORD *)v25 + 3);
            v25 += 16;
            *(_DWORD *)v24 = v26;
            *((_DWORD *)v24 + 1) = v27;
            *((_DWORD *)v24 + 2) = v28;
            *((_DWORD *)v24 + 3) = v29;
            v24 += 16;
          }
          while ( v25 != "}" );
          v14 = 33;
          *(_WORD *)v24 = *(_WORD *)v25;
          goto LABEL_24;
        }
        v20 = *(unsigned __int8 *)(a1 + 210102);
        v21 = v2;
        v22 = 166;
      }
    }
    else
    {
      v20 = *(unsigned __int8 *)(a1 + 210102);
      v21 = (const char *)&unk_6442E4;
      v22 = 12;
    }
LABEL_45:
    v23 = (const char *)_GET_LANG_TEXT(v22, v20, v21);
    v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v23);
    if ( v14 >= 0x400 )
      v14 = 1023;
    goto LABEL_24;
  }
  v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
  if ( v14 >= 0x400 )
    v14 = 1023;
  _mem_free(v9);
  return httpd_cgi_ret(a1, s, v14, 4);
}
// 4C5C70: variable 'v8' is possibly undefined
// 4C5C88: variable 'v10' is possibly undefined
// 4C6338: variable 'v13' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8568: using guessed type int __fastcall ipv6_router_set_to_server(_DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86B0: using guessed type int __fastcall nvparm_get_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

