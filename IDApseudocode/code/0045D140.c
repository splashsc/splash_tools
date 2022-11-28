int __fastcall sub_45D140(int a1)
{
  char *v1; // $s2
  void *v2; // $v0
  void *v3; // $s0
  int v4; // $a0
  int v5; // $v0
  int v6; // $s4
  int v7; // $s6
  int v8; // $s0
  int v9; // $s3
  int v10; // $v0
  int v11; // $s1
  int v12; // $a0
  int v13; // $s3
  int v14; // $s5
  int v15; // $v0
  char *v16; // $a0
  char *v17; // $v1
  const char *v18; // $v0
  int v19; // $t0
  int v20; // $a3
  int v21; // $a2
  int v22; // $a1
  __int16 v23; // $a0
  int v25; // $a1
  const char *v26; // $a2
  const char *v27; // $v0
  const char *v28; // $v0
  char v29[256]; // [sp+20h] [-138h] BYREF
  char v30[8]; // [sp+120h] [-38h] BYREF
  char *v31; // [sp+128h] [-30h]
  char *v32; // [sp+12Ch] [-2Ch]
  char *s; // [sp+130h] [-28h]
  char *v34; // [sp+134h] [-24h]
  char *v35; // [sp+138h] [-20h]
  char *v36; // [sp+13Ch] [-1Ch]
  char *v37; // [sp+140h] [-18h]
  int v38; // [sp+144h] [-14h]
  int v39; // [sp+148h] [-10h]
  char *v40; // [sp+14Ch] [-Ch]
  char *v41; // [sp+150h] [-8h]

  v1 = httpd_get_parm(a1, "opt");
  v40 = httpd_get_parm(a1, "t");
  v34 = httpd_get_parm(a1, "d");
  if ( !v40 )
    v40 = "0";
  if ( !v1 )
  {
LABEL_44:
    v25 = *(unsigned __int8 *)(a1 + 210102);
    v26 = "not opt";
    goto LABEL_45;
  }
  v35 = "a";
  if ( !strcmp(v1, (const char *)&off_646D8C) || !strcmp(v1, "del") || !strcmp(v1, (const char *)&off_648DDC) )
  {
    if ( !strcmp(v1, "delall") )
      goto LABEL_9;
    if ( !strcmp(v1, "addall") )
      goto LABEL_43;
    if ( v34 )
    {
      v5 = httpd_get_json_parm(a1, (int)"data");
      v6 = v5;
      if ( v5 )
      {
        v7 = cJSON_GetArraySize(v5);
        if ( v7 <= 0 )
        {
          s = v29;
          goto LABEL_36;
        }
        v31 = "1\"";
        v38 = 0;
        v32 = "a";
        v8 = 0;
        v41 = "a";
        s = v29;
        v37 = "del";
        v39 = (int)"arp_st";
        v36 = (char *)&off_648DDC;
        while ( 1 )
        {
          while ( 1 )
          {
            v9 = cJSON_GetArrayItem(v6, v8);
            v11 = cJSON_GetObjectItem(v9, "i");
            v10 = cJSON_GetObjectItem(v9, v31 - 8516);
            v12 = v9;
            v13 = v10;
            v14 = cJSON_GetObjectItem(v12, v32 + 28320);
            if ( !v11 || !get_ip_from_str(*(_DWORD *)(v11 + 16)) )
              goto LABEL_21;
            if ( !strcmp(v1, v37) || !strcmp(v1, v36) )
              break;
            if ( !strcmp(v1, v35 + 28044) )
              goto LABEL_29;
LABEL_21:
            if ( v7 == ++v8 )
              goto LABEL_35;
          }
          arp_st_del(v34, *(_DWORD *)(v11 + 16));
          if ( strcmp(v1, v35 + 28044) && strcmp(v1, v36) )
          {
            v38 = 1;
            goto LABEL_21;
          }
          v38 = 1;
LABEL_29:
          v15 = check_rule_num_limit(a1, 9, v39, 60, s, 0x100u);
          if ( v15 > 0 )
            return httpd_cgi_ret(a1, s, v15, 4);
          if ( !v13 || StrToMac(*(_DWORD *)(v13 + 16), v30) )
            goto LABEL_21;
          if ( v14 )
            v16 = *(char **)(v14 + 16);
          else
            v16 = v41 + 25596;
          arp_st_add(v16, v34, *(_DWORD *)(v11 + 16), *(_DWORD *)(v13 + 16), v40);
          ++v8;
          v38 = 1;
          if ( v7 == v8 )
          {
LABEL_35:
            if ( !v38 )
              goto LABEL_36;
            goto LABEL_10;
          }
        }
      }
      v25 = *(unsigned __int8 *)(a1 + 210102);
      v26 = (const char *)&unk_646418;
    }
    else
    {
      v25 = *(unsigned __int8 *)(a1 + 210102);
      v26 = "not net";
    }
LABEL_45:
    v27 = (const char *)_GET_LANG_TEXT(12, v25, v26);
    s = v29;
    v15 = snprintf(v29, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
    if ( (unsigned int)v15 >= 0x100 )
      v15 = 255;
    return httpd_cgi_ret(a1, s, v15, 4);
  }
  if ( strcmp(v1, "addall") )
  {
    if ( !strcmp(v1, "delall") )
    {
LABEL_9:
      s = v29;
      arp_st_delall();
      goto LABEL_10;
    }
    goto LABEL_44;
  }
  if ( !strcmp(v1, "delall") )
    goto LABEL_9;
LABEL_43:
  arp_st_addall("lan", v40);
  s = v29;
LABEL_10:
  _mem_malloc(0x200000, "arp_list_st_asp", 278);
  v3 = v2;
  if ( v2 )
  {
    if ( arp_st_get(v2, 0x200000) )
      nvram_set("arp_st", v3);
    else
      nvram_set("arp_st", " ");
    _mem_free(v3);
    jhl_parm_commit(v4);
LABEL_36:
    v17 = s;
    v18 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v19 = *(_DWORD *)v18;
      v20 = *((_DWORD *)v18 + 1);
      v21 = *((_DWORD *)v18 + 2);
      v22 = *((_DWORD *)v18 + 3);
      v18 += 16;
      *(_DWORD *)v17 = v19;
      *((_DWORD *)v17 + 1) = v20;
      *((_DWORD *)v17 + 2) = v21;
      *((_DWORD *)v17 + 3) = v22;
      v17 += 16;
    }
    while ( v18 != "}" );
    v23 = *(_WORD *)v18;
    v15 = 33;
    *(_WORD *)v17 = v23;
  }
  else
  {
    v28 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
    if ( (unsigned int)v15 >= 0x100 )
      v15 = 255;
  }
  return httpd_cgi_ret(a1, s, v15, 4);
}
// 45D2C0: variable 'v2' is possibly undefined
// 45D328: variable 'v4' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8288: using guessed type int __fastcall arp_st_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82FC: using guessed type int arp_st_delall(void);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8518: using guessed type int __fastcall cJSON_GetArrayItem(_DWORD, _DWORD);
// 6A855C: using guessed type int __fastcall arp_st_addall(_DWORD, _DWORD);
// 6A85EC: using guessed type int __fastcall StrToMac(_DWORD, _DWORD);
// 6A86E0: using guessed type int __fastcall arp_st_get(_DWORD, _DWORD);
// 6A86FC: using guessed type int __fastcall cJSON_GetArraySize(_DWORD);
// 6A8748: using guessed type int __fastcall get_ip_from_str(_DWORD);
// 6A8820: using guessed type int __fastcall arp_st_del(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

