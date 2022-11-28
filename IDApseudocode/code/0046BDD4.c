int __fastcall sub_46BDD4(int a1)
{
  char *v2; // $s3
  char *v3; // $s4
  char *v4; // $s1
  int v5; // $v0
  char *v6; // $s6
  int v7; // $s5
  const char *v8; // $v0
  int v9; // $v0
  unsigned int v10; // $v0
  unsigned int v11; // $v0
  int v12; // $a1
  int v13; // $a2
  int v14; // $a0
  _DWORD *v15; // $s1
  int v16; // $a0
  int v17; // $a2
  void *v18; // $v0
  void *v19; // $s2
  int v20; // $a0
  char *v21; // $v1
  const char *v22; // $v0
  int v23; // $t0
  int v24; // $a3
  int v25; // $a2
  int v26; // $a1
  const char *v28; // $a2
  int v29; // $s1
  int v30; // $v0
  char s[128]; // [sp+20h] [-80h] BYREF

  v2 = httpd_get_parm(a1, (char *)&off_647174);
  v3 = httpd_get_parm(a1, "dst");
  v4 = httpd_get_parm(a1, "opt");
  v6 = httpd_get_parm(a1, "old_src");
  v5 = httpd_get_json_parm(a1, (int)"del_list");
  if ( !v4 )
    goto LABEL_6;
  v7 = v5;
  if ( !strcmp(v4, (const char *)&off_646D8C) )
  {
    if ( !strcmp(v4, "delall") )
      goto LABEL_36;
    if ( strcmp(v4, "del") )
      goto LABEL_11;
  }
  else
  {
    if ( strcmp(v4, "del") )
    {
      if ( strcmp(v4, "delall") )
      {
        if ( strcmp(v4, (const char *)&off_648DDC) )
        {
LABEL_6:
          v8 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
          goto LABEL_7;
        }
        goto LABEL_11;
      }
LABEL_36:
      if ( dns_url_delall() < 0 )
      {
        v29 = *(unsigned __int8 *)(a1 + 210102);
        v30 = _GET_LANG_TEXT(113, v29, v17);
        v8 = (const char *)_GET_LANG_TEXT(12, v29, v30);
        goto LABEL_7;
      }
      jhl_parm_set("dnsUrl", "");
      goto LABEL_38;
    }
    if ( !strcmp(v4, "delall") )
      goto LABEL_36;
  }
  if ( v7 && cJSON_IsArray(v7) )
  {
    v15 = *(_DWORD **)(v7 + 8);
    if ( !v15 )
      goto LABEL_38;
    v16 = v15[4];
    if ( !v16 )
      goto LABEL_38;
    while ( 1 )
    {
      v10 = dns_url_del(v16);
      if ( v10 == -1 )
        goto LABEL_35;
      if ( v10 )
        goto LABEL_48;
      v15 = (_DWORD *)*v15;
      if ( v15 )
      {
        v16 = v15[4];
        if ( v16 )
          continue;
      }
      goto LABEL_38;
    }
  }
LABEL_11:
  if ( !v2 )
  {
    v8 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_647170);
    goto LABEL_7;
  }
  if ( strcmp(v4, (const char *)&off_648DDC) )
  {
    if ( strcmp(v4, (const char *)&off_646D8C) )
      goto LABEL_38;
    goto LABEL_45;
  }
  if ( v6 )
    v10 = dns_url_del(v6);
  else
    v10 = dns_url_del(v2);
  if ( v10 == -1 )
  {
LABEL_35:
    v8 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), &unk_647158);
    goto LABEL_7;
  }
  if ( v10 )
  {
LABEL_48:
    if ( v10 >= 0x33 || (v28 = (const char *)jhlret_err_str[v10]) == 0 )
      v28 = "not find err!";
    v8 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), v28);
    goto LABEL_7;
  }
  if ( strcmp(v4, (const char *)&off_646D8C) )
  {
    if ( strcmp(v4, (const char *)&off_648DDC) )
      goto LABEL_38;
    if ( v3 )
      goto LABEL_20;
    goto LABEL_62;
  }
LABEL_45:
  if ( !v3 )
  {
LABEL_62:
    v8 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not dst");
LABEL_7:
    v9 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
    if ( (unsigned int)v9 >= 0x80 )
      v9 = 127;
    return httpd_cgi_ret(a1, s, v9, 4);
  }
  v9 = check_rule_num_limit(a1, 31, (int)"dnsUrl", 60, s, 0x80u);
  if ( v9 > 0 )
    return httpd_cgi_ret(a1, s, v9, 4);
LABEL_20:
  v11 = dns_url_add(v2, v3, 0);
  if ( v11 == -1 )
  {
    v12 = *(unsigned __int8 *)(a1 + 210102);
    v13 = (int)&unk_647158;
    v14 = 3;
    goto LABEL_56;
  }
  if ( v11 )
  {
    v12 = *(unsigned __int8 *)(a1 + 210102);
    if ( v11 >= 0x33 || (v13 = jhlret_err_str[v11]) == 0 )
      v13 = (int)"not find err!";
    v14 = 3;
    goto LABEL_56;
  }
LABEL_38:
  _mem_malloc(0x200000, "dns_url_asp", 2860);
  v19 = v18;
  if ( !v18 )
  {
    v12 = *(unsigned __int8 *)(a1 + 210102);
    v13 = 0x200000;
    v14 = 4;
LABEL_56:
    v8 = (const char *)_GET_LANG_TEXT(v14, v12, v13);
    goto LABEL_7;
  }
  if ( dns_url_get(v18, 0x200000) )
    jhl_parm_set("dnsUrl", v19);
  else
    jhl_parm_set("dnsUrl", "");
  jhl_parm_commit(v20);
  _mem_free(v19);
  dns_redirect_write_hosts();
  v21 = s;
  v22 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v23 = *(_DWORD *)v22;
    v24 = *((_DWORD *)v22 + 1);
    v25 = *((_DWORD *)v22 + 2);
    v26 = *((_DWORD *)v22 + 3);
    v22 += 16;
    *(_DWORD *)v21 = v23;
    *((_DWORD *)v21 + 1) = v24;
    *((_DWORD *)v21 + 2) = v25;
    *((_DWORD *)v21 + 3) = v26;
    v21 += 16;
  }
  while ( v22 != "}" );
  *(_WORD *)v21 = *(_WORD *)v22;
  return httpd_cgi_ret(a1, s, 33, 4);
}
// 46C1CC: variable 'v18' is possibly undefined
// 46C214: variable 'v20' is possibly undefined
// 46C3B4: variable 'v17' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 647174: using guessed type void *off_647174;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8548: using guessed type int __fastcall dns_url_add(_DWORD, _DWORD, _DWORD);
// 6A8634: using guessed type int dns_redirect_write_hosts(void);
// 6A8840: using guessed type int __fastcall dns_url_get(_DWORD, _DWORD);
// 6A8884: using guessed type int __fastcall dns_url_del(_DWORD);

