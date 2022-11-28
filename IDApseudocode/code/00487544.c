int __fastcall sub_487544(int a1)
{
  char *v2; // $s4
  char *v3; // $s5
  char *v4; // $s7
  char *v5; // $v0
  char *v6; // $s6
  const char *v7; // $s1
  int v8; // $s2
  int v9; // $fp
  unsigned int v10; // $v0
  bool v11; // dc
  unsigned int v12; // $v0
  const char *v13; // $a2
  const char *v14; // $v0
  int v15; // $s1
  void *v16; // $s3
  unsigned __int8 v18; // $v0
  unsigned int v19; // $v0
  int v20; // $a2
  int v21; // $a1
  char *v22; // $a2
  void *v23; // $v0
  int v24; // $a0
  char *v25; // $v1
  const char *v26; // $v0
  int v27; // $t0
  int v28; // $a3
  int v29; // $a2
  int v30; // $a1
  void *v31; // $v0
  const char *v32; // $v0
  char s[128]; // [sp+20h] [-80h] BYREF

  v2 = httpd_get_parm(a1, "name");
  v3 = httpd_get_parm(a1, "u");
  v4 = httpd_get_parm(a1, "old_u");
  v6 = httpd_get_parm(a1, (char *)&off_64918C);
  v5 = httpd_get_parm(a1, "opt");
  if ( !v5 )
  {
LABEL_48:
    v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    goto LABEL_11;
  }
  v7 = v5;
  v8 = strcmp(v5, (const char *)&off_646D8C);
  v9 = v8;
  if ( !v8 || !strcmp(v7, (const char *)&off_648DDC) )
  {
    if ( !strcmp(v7, "delall") )
      goto LABEL_6;
    if ( strcmp(v7, "del") && strcmp(v7, (const char *)&off_648DDC) )
    {
      if ( v8 )
        goto LABEL_36;
      goto LABEL_23;
    }
LABEL_18:
    if ( !v4 )
    {
      v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not old_url");
      goto LABEL_11;
    }
    v10 = url_member_del(v4);
    if ( v10 == -1 )
      goto LABEL_52;
    if ( v10 )
    {
LABEL_8:
      v11 = v10 < 0x33;
      v12 = v10;
      if ( !v11 || (v13 = (const char *)jhlret_err_str[v12]) == 0 )
        v13 = "not find err!";
      v14 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), v13);
      goto LABEL_11;
    }
    v9 = strcmp(v7, (const char *)&off_646D8C);
    if ( v9 && strcmp(v7, (const char *)&off_648DDC) )
      goto LABEL_36;
LABEL_23:
    if ( !v2 )
    {
      v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
      goto LABEL_11;
    }
    if ( !v3 )
    {
      v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not url");
      goto LABEL_11;
    }
    if ( !v6 )
    {
      v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_649188);
      goto LABEL_11;
    }
    if ( !v9 )
    {
      v15 = check_rule_num_limit(a1, 16, (int)"url_member", 60, s, 0x80u);
      if ( v15 > 0 )
      {
        v16 = 0;
        goto LABEL_14;
      }
    }
    v18 = J_atoi(v6);
    v19 = url_member_add(v18, v2, v3, 0);
    if ( v19 == -2 )
    {
      v14 = (const char *)_GET_LANG_TEXT(180, *(unsigned __int8 *)(a1 + 210102), v20);
      goto LABEL_11;
    }
    if ( v19 == -1 )
    {
      v21 = *(unsigned __int8 *)(a1 + 210102);
      v22 = "";
LABEL_32:
      v14 = (const char *)_GET_LANG_TEXT(3, v21, v22);
LABEL_11:
      v15 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
      if ( (unsigned int)v15 >= 0x80 )
        v15 = 127;
      v16 = 0;
      goto LABEL_14;
    }
    if ( v19 )
    {
      v21 = *(unsigned __int8 *)(a1 + 210102);
      if ( v19 >= 0x33 || (v22 = (char *)jhlret_err_str[v19]) == 0 )
        v22 = "not find err!";
      goto LABEL_32;
    }
LABEL_36:
    _mem_malloc(0x200000, "url_member_asp", 364);
    v16 = v23;
    if ( v23 )
    {
      if ( url_member_get(v23, 0x200000) )
        jhl_parm_set("url_member", v16);
      else
        jhl_parm_set("url_member", "");
      jhl_parm_commit(v24);
      v25 = s;
      v26 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v27 = *(_DWORD *)v26;
        v28 = *((_DWORD *)v26 + 1);
        v29 = *((_DWORD *)v26 + 2);
        v30 = *((_DWORD *)v26 + 3);
        v26 += 16;
        *(_DWORD *)v25 = v27;
        *((_DWORD *)v25 + 1) = v28;
        *((_DWORD *)v25 + 2) = v29;
        *((_DWORD *)v25 + 3) = v30;
        v25 += 16;
      }
      while ( v26 != "}" );
      v15 = 33;
      *(_WORD *)v25 = *(_WORD *)v26;
      goto LABEL_14;
    }
    v32 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    goto LABEL_57;
  }
  if ( strcmp(v7, "del") )
  {
    if ( !strcmp(v7, "delall") )
      goto LABEL_6;
    goto LABEL_48;
  }
  if ( strcmp(v7, "delall") )
    goto LABEL_18;
LABEL_6:
  v10 = url_member_delall();
  if ( v10 == -1 )
  {
LABEL_52:
    v14 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
    goto LABEL_11;
  }
  if ( v10 )
    goto LABEL_8;
  _mem_malloc(0x200000, "url_member_asp", 273);
  v16 = v31;
  if ( v31 )
  {
    if ( url_group_get(v31, 0x200000) )
      jhl_parm_set(&unk_64A61C, v16);
    else
      jhl_parm_set(&unk_64A61C, "");
    _mem_free(v16);
    goto LABEL_36;
  }
  v32 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
LABEL_57:
  v15 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v32);
  if ( (unsigned int)v15 >= 0x80 )
    v15 = 127;
LABEL_14:
  _mem_free(v16);
  return httpd_cgi_ret(a1, s, v15, 4);
}
// 487970: variable 'v23' is possibly undefined
// 4879B4: variable 'v24' is possibly undefined
// 487A48: variable 'v31' is possibly undefined
// 487C20: variable 'v20' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 64918C: using guessed type void *off_64918C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8390: using guessed type int __fastcall url_member_get(_DWORD, _DWORD);
// 6A83B4: using guessed type int url_member_delall(void);
// 6A8648: using guessed type int __fastcall url_group_get(_DWORD, _DWORD);
// 6A86C4: using guessed type int __fastcall url_member_del(_DWORD);
// 6A8770: using guessed type int __fastcall url_member_add(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

