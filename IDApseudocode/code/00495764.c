int __fastcall sub_495764(int a1)
{
  char *v2; // $s7
  char *v3; // $v0
  char *v4; // $s6
  const char *v5; // $s1
  char *v6; // $v0
  char *v7; // $v0
  char *v8; // $s5
  char *v9; // $s3
  _BOOL4 v10; // $s6
  unsigned int v11; // $s4
  int v12; // $s4
  int v13; // $a1
  const char *v14; // $a2
  const char *v15; // $v0
  int v16; // $a1
  char *v17; // $a2
  int v18; // $a0
  const char *v19; // $v0
  unsigned int v21; // $v0
  bool v22; // dc
  unsigned int v23; // $v0
  unsigned int v24; // $v0
  const char *v25; // $a2
  const char *v26; // $v0
  char *v27; // $v1
  const char *v28; // $v0
  int v29; // $t0
  int v30; // $a3
  int v31; // $a2
  int v32; // $a1
  int v33; // $a0
  char s[1024]; // [sp+28h] [-410h] BYREF
  char *v35; // [sp+428h] [-10h]
  int v36; // [sp+42Ch] [-Ch]
  char *v37; // [sp+430h] [-8h]

  v35 = httpd_get_parm(a1, "dns");
  v2 = httpd_get_parm(a1, "old_dns");
  v4 = httpd_get_parm(a1, (char *)&off_64918C);
  v3 = httpd_get_parm(a1, "opt");
  if ( !v3
    || (v5 = v3, strcmp(v3, (const char *)&off_646D8C))
    && strcmp(v5, (const char *)&off_648DDC)
    && strcmp(v5, "del")
    && strcmp(v5, "delall") )
  {
    v13 = *(unsigned __int8 *)(a1 + 210102);
    v14 = "not opt";
    goto LABEL_19;
  }
  if ( !v4 )
  {
    v13 = *(unsigned __int8 *)(a1 + 210102);
    v14 = (const char *)&unk_649188;
LABEL_19:
    v15 = (const char *)_GET_LANG_TEXT(12, v13, v14);
    v11 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v15);
    if ( v11 >= 0x400 )
      v11 = 1023;
    return httpd_cgi_ret(a1, s, v11, 4);
  }
  _mem_malloc(1024000, "dns_more_dnstype_item_asp", 1320);
  v8 = v7;
  _mem_malloc(1024000, "dns_more_dnstype_item_asp", 1321);
  v9 = v6;
  if ( !v8 )
  {
    v26 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v11 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v26);
    if ( v11 >= 0x400 )
      v11 = 1023;
    goto LABEL_26;
  }
  if ( !v6 )
  {
    v16 = *(unsigned __int8 *)(a1 + 210102);
    v17 = (char *)1024000;
    v18 = 4;
LABEL_22:
    v19 = (const char *)_GET_LANG_TEXT(v18, v16, v17);
    goto LABEL_23;
  }
  v36 = J_atoi(v4);
  if ( !strcmp(v5, "delall") )
  {
    v21 = dns_more_dnstype_item_delall((unsigned __int8)v36);
    if ( v21 == -1 )
    {
LABEL_51:
      v16 = *(unsigned __int8 *)(a1 + 210102);
      v17 = "";
      v18 = 3;
      goto LABEL_22;
    }
    if ( v21 )
    {
LABEL_32:
      v16 = *(unsigned __int8 *)(a1 + 210102);
      v22 = v21 < 0x33;
      v23 = v21;
      if ( !v22 || (v17 = (char *)jhlret_err_str[v23]) == 0 )
        v17 = "not find err!";
      v18 = 3;
      goto LABEL_22;
    }
    jhl_parm_get("dns_more_dnstype_item", v8, 1024000);
    v10 = nvparm_del_str(v8, 60, 2, v4, 124, 1, v9) != 0;
  }
  else
  {
    v10 = 0;
  }
  if ( strcmp(v5, "del") && strcmp(v5, (const char *)&off_648DDC) )
  {
    if ( !strcmp(v5, (const char *)&off_646D8C) )
    {
      if ( v35 )
      {
        v37 = "1\"";
        goto LABEL_13;
      }
      goto LABEL_53;
    }
LABEL_56:
    if ( !v10 )
      goto LABEL_57;
    v37 = "1\"";
LABEL_65:
    jhl_parm_set(v37 - 17924, v9);
    jhl_parm_commit(v33);
LABEL_57:
    v27 = s;
    v28 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v29 = *(_DWORD *)v28;
      v30 = *((_DWORD *)v28 + 1);
      v31 = *((_DWORD *)v28 + 2);
      v32 = *((_DWORD *)v28 + 3);
      v28 += 16;
      *(_DWORD *)v27 = v29;
      *((_DWORD *)v27 + 1) = v30;
      *((_DWORD *)v27 + 2) = v31;
      *((_DWORD *)v27 + 3) = v32;
      v27 += 16;
    }
    while ( v28 != "}" );
    v11 = 33;
    *(_WORD *)v27 = *(_WORD *)v28;
    goto LABEL_25;
  }
  if ( !v2 )
  {
LABEL_53:
    v16 = *(unsigned __int8 *)(a1 + 210102);
    v17 = "not dns";
    v18 = 12;
    goto LABEL_22;
  }
  v12 = (unsigned __int8)v36;
  v21 = dns_more_dnstype_item_del(v2, (unsigned __int8)v36);
  if ( v21 == -1 )
    goto LABEL_51;
  if ( v21 )
    goto LABEL_32;
  v37 = "1\"";
  jhl_parm_get("dns_more_dnstype_item", v8, 1024000);
  if ( nvparm_del_str(v8, 60, 2, v2, 124, 0, v9) )
    v10 = 1;
  if ( strcmp(v5, (const char *)&off_646D8C) )
  {
    if ( strcmp(v5, (const char *)&off_648DDC) )
      goto LABEL_56;
    if ( v35 )
      goto LABEL_42;
    goto LABEL_53;
  }
  if ( !v35 )
    goto LABEL_53;
LABEL_13:
  v11 = check_rule_num_limit(a1, 5, (int)(v37 - 17924), 60, s, 0x400u);
  if ( (int)v11 <= 0 )
  {
    v12 = (unsigned __int8)v36;
LABEL_42:
    v24 = dns_more_dnstype_item_add(v12, v35);
    if ( v24 != -1 )
    {
      if ( v24 )
      {
        if ( v24 >= 0x33 || (v25 = (const char *)jhlret_err_str[v24]) == 0 )
          v25 = "not find err!";
        v19 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), v25);
        goto LABEL_23;
      }
      sprintf(v8, "%s|%d<", v35, v12);
      if ( !v10 )
      {
        jhl_parm_get(v37 - 17924, v9, 1024000);
        if ( !strcmp(v9, " ") )
          *v9 = 0;
      }
      strcat(v9, v8);
      goto LABEL_65;
    }
    v19 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), "");
LABEL_23:
    v11 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
    if ( v11 >= 0x400 )
      v11 = 1023;
  }
LABEL_25:
  _mem_free(v8);
LABEL_26:
  if ( v9 )
    _mem_free(v9);
  return httpd_cgi_ret(a1, s, v11, 4);
}
// 49586C: variable 'v7' is possibly undefined
// 495878: variable 'v6' is possibly undefined
// 495F08: variable 'v33' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 64918C: using guessed type void *off_64918C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8290: using guessed type int __fastcall dns_more_dnstype_item_delall(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8590: using guessed type int __fastcall dns_more_dnstype_item_add(_DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86BC: using guessed type int __fastcall dns_more_dnstype_item_del(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

