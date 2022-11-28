int __fastcall sub_486C1C(int a1)
{
  char *v2; // $s3
  char *v3; // $v0
  char *v4; // $s4
  const char *v5; // $s1
  const char *v6; // $v0
  int v7; // $v0
  unsigned int v9; // $v0
  int v10; // $a1
  char *v11; // $a2
  unsigned __int8 v12; // $v0
  unsigned int v13; // $v0
  int v14; // $a0
  char *v15; // $v1
  const char *v16; // $v0
  int v17; // $t0
  int v18; // $a3
  int v19; // $a2
  int v20; // $a1
  const char *v21; // $a2
  char s[10240]; // [sp+20h] [-2800h] BYREF

  v2 = httpd_get_parm(a1, "name");
  v4 = httpd_get_parm(a1, "id");
  v3 = httpd_get_parm(a1, "opt");
  if ( !v3 )
    goto LABEL_4;
  v5 = v3;
  if ( !strcmp(v3, (const char *)&off_646D8C) )
  {
    if ( strcmp(v5, "del") )
      goto LABEL_10;
  }
  else if ( strcmp(v5, "del") )
  {
LABEL_4:
    v6 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    goto LABEL_5;
  }
  if ( !v4 )
  {
    v6 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not id");
    goto LABEL_5;
  }
  v12 = J_atoi(v4);
  v13 = url_group_del(v12);
  if ( v13 == -1 )
  {
    v6 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
    goto LABEL_5;
  }
  if ( v13 )
  {
    if ( v13 >= 0x33 || (v21 = (const char *)jhlret_err_str[v13]) == 0 )
      v21 = "not find err!";
    v6 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), v21);
    goto LABEL_5;
  }
  if ( !strcmp(v5, (const char *)&off_646D8C) )
  {
LABEL_10:
    if ( v2 )
    {
      v7 = check_rule_num_limit(a1, 15, (int)&unk_64A61C, 60, s, 0x2800u);
      if ( v7 > 0 )
        return httpd_cgi_ret(a1, s, v7, 4);
      v9 = url_group_add(v2, 0, 0);
      if ( v9 == -1 )
      {
        v10 = *(unsigned __int8 *)(a1 + 210102);
        v11 = "";
      }
      else
      {
        if ( !v9 )
          goto LABEL_21;
        v10 = *(unsigned __int8 *)(a1 + 210102);
        if ( v9 >= 0x33 || (v11 = (char *)jhlret_err_str[v9]) == 0 )
          v11 = "not find err!";
      }
      v6 = (const char *)_GET_LANG_TEXT(3, v10, v11);
    }
    else
    {
      v6 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
    }
LABEL_5:
    v7 = snprintf(s, 10240, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v6);
    if ( (unsigned int)v7 >= 0x2800 )
      v7 = 10239;
    return httpd_cgi_ret(a1, s, v7, 4);
  }
LABEL_21:
  if ( url_group_get(s, 10240) )
    jhl_parm_set(&unk_64A61C, s);
  else
    jhl_parm_set(&unk_64A61C, "");
  jhl_parm_commit(v14);
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
  *(_WORD *)v15 = *(_WORD *)v16;
  return httpd_cgi_ret(a1, s, 33, 4);
}
// 486EE4: variable 'v14' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A819C: using guessed type int __fastcall url_group_del(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8648: using guessed type int __fastcall url_group_get(_DWORD, _DWORD);
// 6A8674: using guessed type int __fastcall url_group_add(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

