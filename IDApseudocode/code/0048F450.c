int __fastcall sub_48F450(int a1)
{
  char *v2; // $s5
  char *v3; // $s6
  char *v4; // $s4
  char *v5; // $s7
  char *v6; // $s2
  int v7; // $v0
  char *v8; // $s1
  int v9; // $fp
  _DWORD *i; // $fp
  int v11; // $a0
  int v12; // $a0
  char *v13; // $v0
  char *v14; // $v1
  const char *v15; // $v0
  int v16; // $t0
  int v17; // $a3
  int v18; // $a2
  int v19; // $a1
  int v20; // $a2
  char *v22; // $a2
  int v23; // $a1
  const char *v24; // $a2
  const char *v25; // $v0
  char s[1024]; // [sp+30h] [-418h] BYREF
  char *v27; // [sp+430h] [-18h]
  char *v28; // [sp+434h] [-14h]
  char *v29; // [sp+438h] [-10h]
  char *v30; // [sp+43Ch] [-Ch]
  char *v31; // [sp+440h] [-8h]
  char *v32; // [sp+444h] [-4h]

  v2 = httpd_get_parm(a1, "user");
  v3 = httpd_get_parm(a1, "old_user");
  v28 = httpd_get_parm(a1, (char *)&off_649194);
  v29 = httpd_get_parm(a1, "ip");
  v30 = httpd_get_parm(a1, "type");
  v31 = httpd_get_parm(a1, "utype");
  v4 = httpd_get_parm(a1, "route");
  v27 = httpd_get_parm(a1, "mem");
  v5 = httpd_get_parm(a1, "en");
  v6 = httpd_get_parm(a1, "opt");
  v8 = httpd_get_parm(a1, "id");
  v7 = httpd_get_json_parm(a1, (int)"del_list");
  if ( !v6 )
    goto LABEL_41;
  v9 = v7;
  if ( !strcmp(v6, (const char *)&off_646D8C) )
  {
    if ( strcmp(v6, "del") )
      goto LABEL_14;
    v32 = "1\"";
    goto LABEL_5;
  }
  v32 = "1\"";
  if ( !strcmp(v6, (const char *)&off_648DDC) )
  {
    if ( strcmp(v6, "del") )
      goto LABEL_14;
    goto LABEL_5;
  }
  if ( strcmp(v6, "del") )
  {
    if ( !strcmp(v6, "delall") )
      goto LABEL_11;
LABEL_41:
    v23 = *(unsigned __int8 *)(a1 + 210102);
    v24 = "not opt";
    goto LABEL_42;
  }
LABEL_5:
  if ( v9 )
  {
    for ( i = *(_DWORD **)(v9 + 8); i; i = (_DWORD *)*i )
    {
      v11 = i[4];
      if ( !v11 )
        break;
      vpn_user_del(v11, v8);
    }
  }
  if ( strcmp(v6, v32 - 29220) )
  {
LABEL_11:
    if ( strcmp(v6, (const char *)&off_646D8C) )
    {
LABEL_26:
      jhl_parm_commit(v12);
      v14 = s;
      v15 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v16 = *(_DWORD *)v15;
        v17 = *((_DWORD *)v15 + 1);
        v18 = *((_DWORD *)v15 + 2);
        v19 = *((_DWORD *)v15 + 3);
        v15 += 16;
        *(_DWORD *)v14 = v16;
        *((_DWORD *)v14 + 1) = v17;
        *((_DWORD *)v14 + 2) = v18;
        *((_DWORD *)v14 + 3) = v19;
        v14 += 16;
      }
      while ( v15 != "}" );
      v20 = 33;
      *(_WORD *)v14 = *(_WORD *)v15;
      return httpd_cgi_ret(a1, s, v20, 4);
    }
  }
LABEL_14:
  if ( v2 )
  {
    if ( v3 )
      vpn_user_del(v3, v8);
    else
      vpn_user_del(v2, v8);
    if ( strcmp(v6, (const char *)&off_646D8C) )
    {
      if ( strcmp(v6, (const char *)&off_648DDC) )
        goto LABEL_26;
LABEL_19:
      if ( !v4 )
        v4 = "";
      if ( !v5 )
        v4 = "1";
      v13 = v27;
      if ( !v27 )
        v13 = "";
      vpn_user_add(v5, v2, v28, v31, v29, v30, v4, v13, v8);
      goto LABEL_26;
    }
    if ( v8 )
    {
      if ( !strcmp(v8, "pptp") )
      {
        v22 = "pptp_vpn_users";
        goto LABEL_35;
      }
      if ( !strcmp(v8, "l2tp") )
      {
        v22 = "l2tp_vpn_users";
        goto LABEL_35;
      }
    }
    v22 = "";
LABEL_35:
    v20 = check_rule_num_limit(a1, 21, (int)v22, 60, s, 0x400u);
    if ( v20 > 0 )
      return httpd_cgi_ret(a1, s, v20, 4);
    goto LABEL_19;
  }
  v23 = *(unsigned __int8 *)(a1 + 210102);
  v24 = "not user";
LABEL_42:
  v25 = (const char *)_GET_LANG_TEXT(12, v23, v24);
  v20 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
  if ( (unsigned int)v20 >= 0x400 )
    v20 = 1023;
  return httpd_cgi_ret(a1, s, v20, 4);
}
// 48F7B8: variable 'v12' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 649194: using guessed type char *off_649194;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A820C: using guessed type int __fastcall vpn_user_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82EC: using guessed type int __fastcall vpn_user_del(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

