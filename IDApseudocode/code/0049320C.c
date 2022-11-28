int __fastcall sub_49320C(int a1)
{
  char *v2; // $s0
  char *v3; // $v0
  void *v4; // $v0
  void *v5; // $s7
  _DWORD *v6; // $s1
  char *v7; // $v0
  int v8; // $s2
  int v9; // $a0
  int v10; // $v0
  int v11; // $a2
  int v12; // $a2
  const char *v13; // $v0
  unsigned int v14; // $s1
  const char *v16; // $v1
  char *v17; // $v0
  int v18; // $t0
  int v19; // $a3
  int v20; // $a2
  int v21; // $a1
  int v22; // $s3
  char *v23; // $s1
  int i; // $s0
  int v25; // $s1
  char *v26; // $s3
  int v27; // $s4
  char *v28; // $a1
  int v29; // $a0
  int v30; // $t0
  int v31; // $a3
  int v32; // $a2
  int v33; // $a1
  int v34; // $a1
  int v35; // $a2
  int v36; // $a0
  const char *v37; // $v0
  int v38; // $a3
  char *v39; // $s0
  int v40; // $a0
  const char *v41; // $v0
  char v42[81920]; // [sp+28h] [-14628h] BYREF
  char s[1024]; // [sp+14028h] [-628h] BYREF
  _DWORD v44[128]; // [sp+14428h] [-228h] BYREF
  char *v45; // [sp+14628h] [-28h] BYREF
  char *v46; // [sp+1462Ch] [-24h]
  int v47; // [sp+14630h] [-20h]
  int v48; // [sp+14634h] [-1Ch]
  char *v49; // [sp+14638h] [-18h]
  char *v50; // [sp+1463Ch] [-14h]
  char *v51; // [sp+14640h] [-10h]
  char *v52; // [sp+14644h] [-Ch]
  int v53; // [sp+14648h] [-8h]

  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v50 = httpd_get_parm(a1, "name");
  v52 = httpd_get_parm(a1, "id");
  v2 = httpd_get_parm(a1, "opt");
  v51 = (char *)httpd_get_json_parm(a1, (int)"del_list");
  if ( !v2 || strcmp(v2, (const char *)&off_646D8C) && strcmp(v2, "del") && strcmp(v2, "delall") )
  {
    v13 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    if ( v14 >= 0x400 )
      v14 = 1023;
    return httpd_cgi_ret(a1, s, v14, 4);
  }
  _mem_malloc(1024000, "dns_more_dnstype_asp", 553);
  v5 = v4;
  _mem_malloc(1024000, "dns_more_dnstype_asp", 554);
  v49 = v3;
  if ( !v5 )
  {
    v41 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v41);
    if ( v14 >= 0x400 )
      v14 = 1023;
    goto LABEL_30;
  }
  if ( !v3 )
  {
    v34 = *(unsigned __int8 *)(a1 + 210102);
    v35 = 1024000;
    v36 = 4;
    goto LABEL_49;
  }
  if ( !strcmp(v2, "delall") )
  {
    v50 = "1\"";
    jhl_parm_get("dns_more_dnstype_item", v5, 1024000);
    v22 = split_string(v5, 60, v42, 20480);
    if ( v22 > 0 )
    {
      v23 = v42;
      for ( i = 0; i != v22; ++i )
      {
        if ( split_string(*(_DWORD *)v23, 124, v44, 128) >= 2 )
          set_dns_more_dnstype_item_to_kernel("del", v44);
        v23 += 4;
      }
    }
    v52 = "a: no-cache\r\nCache-Control: no-cache\r\nSec-WebSocket-Accept: %s\r\n\r\n";
    jhl_parm_set(v50 - 17924, "");
    v51 = "1\"";
    memset(v5, 0, 0xFA000u);
    jhl_parm_get("dns_more_dnstype", v5, 1024000);
    v25 = split_string(v5, 60, v42, 512);
    if ( v25 > 0 )
    {
      v26 = v42;
      v27 = 0;
      v50 = "del";
      do
      {
        while ( 1 )
        {
          ++v27;
          if ( split_string(*(_DWORD *)v26, 124, v44, 128) >= 3 && !J_atoi(v44[2]) )
            break;
          v26 += 4;
          if ( v25 == v27 )
            goto LABEL_43;
        }
        set_dns_more_dnstype_to_kernel(v50, v44);
        v26 += 4;
      }
      while ( v25 != v27 );
    }
LABEL_43:
    memset(v5, 0, 0xFA000u);
    if ( dns_more_dnstype_get(v5, 1024000) )
      v28 = (char *)v5;
    else
      v28 = v52 - 1556;
    jhl_parm_set(v51 - 17900, v28);
    jhl_parm_commit(v29);
    v16 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    v17 = s;
    do
    {
      v30 = *(_DWORD *)v16;
      v31 = *((_DWORD *)v16 + 1);
      v32 = *((_DWORD *)v16 + 2);
      v33 = *((_DWORD *)v16 + 3);
      v16 += 16;
      *(_DWORD *)v17 = v30;
      *((_DWORD *)v17 + 1) = v31;
      *((_DWORD *)v17 + 2) = v32;
      *((_DWORD *)v17 + 3) = v33;
      v17 += 16;
    }
    while ( v16 != "}" );
    goto LABEL_28;
  }
  if ( strcmp(v2, "del") || !v51 || !cJSON_IsArray(v51) )
  {
    if ( v50 )
    {
      v45 = v50;
      if ( strcmp(v2, (const char *)&off_646D8C) )
        goto LABEL_26;
      v51 = "1\"";
      v14 = check_rule_num_limit(a1, 4, (int)"dns_more_dnstype", 60, s, 0x400u);
      if ( (int)v14 > 0 )
        goto LABEL_29;
      if ( !v52 || !*v52 )
        v52 = "0";
      v46 = v52;
      v38 = set_dns_more_dnstype_to_kernel(v2, &v45);
      if ( v38 < 0 )
        goto LABEL_26;
      sprintf((char *)v5, "%s|%d|%d<", v45, v38, 0);
      v39 = v49;
      jhl_parm_get(v51 - 17900, v49, 1024000);
      if ( !strcmp(v39, " ") )
        *v39 = 0;
      strcat(v49, (char *)v5);
      goto LABEL_60;
    }
    v34 = *(unsigned __int8 *)(a1 + 210102);
    v35 = (int)&unk_6442E4;
    v36 = 12;
LABEL_49:
    v37 = (const char *)_GET_LANG_TEXT(v36, v34, v35);
LABEL_50:
    v14 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v37);
    if ( v14 >= 0x400 )
      v14 = 1023;
    goto LABEL_29;
  }
  v6 = (_DWORD *)*((_DWORD *)v51 + 2);
  if ( !v6 )
    goto LABEL_26;
  v53 = 0;
  v52 = (char *)&v45;
  v51 = "dns_more_dnstype";
  do
  {
    v8 = cJSON_GetObjectItem(v6, "name");
    v7 = (char *)cJSON_GetObjectItem(v6, "id");
    if ( v8 && v7 )
    {
      v9 = *((_DWORD *)v7 + 4);
      v50 = v7;
      v10 = dns_more_dnstype_is_used(v9);
      if ( v10 )
      {
        v37 = (const char *)_GET_LANG_TEXT(v10, *(unsigned __int8 *)(a1 + 210102), v11);
        goto LABEL_50;
      }
      if ( dns_more_get_dnstype_item_list_id(*((_DWORD *)v50 + 4)) )
      {
        v37 = (const char *)_GET_LANG_TEXT(39, *(unsigned __int8 *)(a1 + 210102), v12);
        goto LABEL_50;
      }
      v45 = *(char **)(v8 + 16);
      if ( set_dns_more_dnstype_to_kernel(v2, v52) >= 0 )
      {
        jhl_parm_get(v51, v5, 1024000);
        if ( nvparm_del_str(v5, 60, 2, *(_DWORD *)(v8 + 16), 124, 0, v49) )
        {
          jhl_parm_set(v51, v49);
          v53 = 1;
        }
      }
    }
    v6 = (_DWORD *)*v6;
  }
  while ( v6 );
  if ( !v53 )
    goto LABEL_26;
  v51 = "1\"";
LABEL_60:
  jhl_parm_set(v51 - 17900, v49);
  jhl_parm_commit(v40);
LABEL_26:
  v16 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v17 = s;
  do
  {
    v18 = *(_DWORD *)v16;
    v19 = *((_DWORD *)v16 + 1);
    v20 = *((_DWORD *)v16 + 2);
    v21 = *((_DWORD *)v16 + 3);
    v16 += 16;
    *(_DWORD *)v17 = v18;
    *((_DWORD *)v17 + 1) = v19;
    *((_DWORD *)v17 + 2) = v20;
    *((_DWORD *)v17 + 3) = v21;
    v17 += 16;
  }
  while ( v16 != "}" );
LABEL_28:
  v14 = 33;
  *(_WORD *)v17 = *(_WORD *)v16;
LABEL_29:
  _mem_free(v5);
LABEL_30:
  if ( v49 )
    _mem_free(v49);
  return httpd_cgi_ret(a1, s, v14, 4);
}
// 493378: variable 'v4' is possibly undefined
// 493390: variable 'v3' is possibly undefined
// 493A24: variable 'v29' is possibly undefined
// 493C9C: variable 'v40' is possibly undefined
// 493D8C: variable 'v11' is possibly undefined
// 493DB0: variable 'v12' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8278: using guessed type int __fastcall set_dns_more_dnstype_to_kernel(_DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83E8: using guessed type int __fastcall dns_more_dnstype_get(_DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A88D0: using guessed type int __fastcall set_dns_more_dnstype_item_to_kernel(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

