int __fastcall usb_email_asp(int a1)
{
  char *v2; // $s5
  char *v3; // $s6
  char *v4; // $s7
  char *v5; // $s1
  char *v6; // $v0
  char *v7; // $v0
  char *v8; // $s3
  char *v9; // $s4
  int v10; // $v0
  char *v11; // $v0
  int v12; // $a2
  const char *v13; // $v0
  int v14; // $fp
  _DWORD *v16; // $fp
  int v17; // $s7
  int v18; // $v0
  const char *v19; // $v0
  int v20; // $a0
  char *v21; // $v1
  const char *v22; // $v0
  int v23; // $t0
  int v24; // $a3
  int v25; // $a2
  int v26; // $a1
  int v27; // $a1
  int v28; // $a2
  int v29; // $a0
  int v30; // $v0
  int v31; // $a2
  char s[256]; // [sp+28h] [-110h] BYREF
  char *v33; // [sp+128h] [-10h]
  char *v34; // [sp+12Ch] [-Ch]
  char *v35; // [sp+130h] [-8h]

  v34 = httpd_get_parm(a1, "email_name");
  v35 = httpd_get_parm(a1, "old_email_name");
  v2 = httpd_get_parm(a1, "email_en");
  v3 = httpd_get_parm(a1, "email_url");
  v4 = httpd_get_parm(a1, "email_mem");
  v33 = (char *)httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  _mem_malloc(102400, "usb_email_asp", 344);
  v8 = v7;
  _mem_malloc(102400, "usb_email_asp", 345);
  v9 = v6;
  if ( !v8 || !v6 )
  {
    v27 = *(unsigned __int8 *)(a1 + 210102);
    v28 = 102400;
    v29 = 4;
    goto LABEL_59;
  }
  v10 = a1 + 196608;
  if ( !v5 )
    goto LABEL_57;
  if ( strcmp(v5, (const char *)&off_646D8C) && strcmp(v5, (const char *)&off_648DDC) && strcmp(v5, "del") )
  {
    if ( strcmp(v5, "delall") )
    {
      if ( !strcmp(v5, "send") )
        goto LABEL_9;
      v10 = a1 + 196608;
LABEL_57:
      v27 = *(unsigned __int8 *)(v10 + 13494);
      v28 = (int)"not opt";
LABEL_58:
      v29 = 12;
LABEL_59:
      v13 = (const char *)_GET_LANG_TEXT(v29, v27, v28);
      goto LABEL_15;
    }
    if ( strcmp(v5, "send") )
      goto LABEL_51;
LABEL_9:
    v11 = (char *)nvram_get("usb_send_email_list");
    if ( !v11 )
      v11 = "";
    if ( *v11 && v11[1] && v11[2] )
    {
      if ( !usb_send_email() )
      {
        v19 = (const char *)_GET_LANG_TEXT(57, *(unsigned __int8 *)(a1 + 210102), v31);
        v14 = snprintf(s, 256, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v19);
        if ( (unsigned int)v14 < 0x100 )
          goto LABEL_16;
        goto LABEL_47;
      }
      v13 = (const char *)_GET_LANG_TEXT(56, *(unsigned __int8 *)(a1 + 210102), v31);
    }
    else
    {
      v13 = (const char *)_GET_LANG_TEXT(55, *(unsigned __int8 *)(a1 + 210102), v12);
    }
LABEL_15:
    v14 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    if ( (unsigned int)v14 < 0x100 )
      goto LABEL_16;
LABEL_47:
    v14 = 255;
    goto LABEL_16;
  }
  if ( !strcmp(v5, "send") )
    goto LABEL_9;
  if ( !strcmp(v5, "delall") )
  {
LABEL_51:
    *v9 = 32;
    v9[1] = 0;
    v33 = "1\"";
LABEL_52:
    jhl_parm_set(v33 - 6712, v9);
    jhl_parm_commit(v20);
    goto LABEL_53;
  }
  if ( !strcmp(v5, "del") && v33 && cJSON_IsArray(v33) )
  {
    v16 = (_DWORD *)*((_DWORD *)v33 + 2);
    if ( !v16 || !v16[4] )
      goto LABEL_53;
    v33 = "1\"";
    v17 = 0;
    v34 = "usb_send_email_list";
    do
    {
      jhl_parm_get("usb_send_email_list", v8, 102400);
      if ( nvparm_del_str(v8, 60, 6, v16[4], 124, 0, v9) )
      {
        jhl_parm_set(v34, v9);
        v17 = 1;
      }
      v16 = (_DWORD *)*v16;
    }
    while ( v16 && v16[4] );
    if ( !v17 )
      goto LABEL_53;
    goto LABEL_52;
  }
  if ( !v34 )
  {
    v27 = *(unsigned __int8 *)(a1 + 210102);
    v28 = (int)&unk_6442E4;
    goto LABEL_58;
  }
  if ( !strcmp(v5, (const char *)&off_646D8C) )
  {
    v18 = strcmp(v5, (const char *)&off_648DDC);
LABEL_32:
    if ( !v2 || !*v2 )
      v2 = "1";
    if ( !v3 || !*v3 )
      v3 = "";
    if ( !v4 || !*v4 )
      v4 = "";
    if ( v18 )
    {
      v33 = "1\"";
    }
    else
    {
      v33 = "1\"";
      jhl_parm_get("usb_send_email_list", v8, 102400);
      if ( v35 )
        v30 = nvparm_del_str(v8, 60, 6, v35, 124, 0, v9);
      else
        v30 = nvparm_del_str(v8, 60, 6, v34, 124, 0, v9);
      if ( v30 )
      {
        v14 = check_rule_num_limit(a1, 36, (int)(v33 - 6712), 60, s, 0x100u);
        if ( v14 > 0 )
          goto LABEL_16;
        sprintf(v8, "%s|%s|%s|%s<", v34, v2, v3, v4);
LABEL_66:
        strcat(v9, v8);
        goto LABEL_52;
      }
    }
    v14 = check_rule_num_limit(a1, 36, (int)(v33 - 6712), 60, s, 0x100u);
    if ( v14 > 0 )
      goto LABEL_16;
    sprintf(v8, "%s|%s|%s|%s<", v34, v2, v3, v4);
    jhl_parm_get(v33 - 6712, v9, 102400);
    if ( !strcmp(v9, " ") )
      *v9 = 0;
    goto LABEL_66;
  }
  v18 = strcmp(v5, (const char *)&off_648DDC);
  if ( !v18 )
    goto LABEL_32;
LABEL_53:
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
  v14 = 33;
  *(_WORD *)v21 = *(_WORD *)v22;
LABEL_16:
  _mem_free(v8);
  _mem_free(v9);
  return httpd_cgi_ret(a1, s, v14, 4);
}
// 4B57FC: variable 'v7' is possibly undefined
// 4B5808: variable 'v6' is possibly undefined
// 4B591C: variable 'v12' is possibly undefined
// 4B5CB0: variable 'v31' is possibly undefined
// 4B5D5C: variable 'v20' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);

