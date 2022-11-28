int __fastcall sub_4A410C(int a1)
{
  char *v2; // $s5
  char *v3; // $s7
  int v4; // $s6
  char *v5; // $s2
  int v6; // $v0
  char *v7; // $v0
  char *v8; // $s3
  int v9; // $s1
  int v10; // $a0
  char *v11; // $fp
  char *v12; // $s7
  int v13; // $a0
  const char *v14; // $v0
  const char *v15; // $v0
  const char *v16; // $v0
  char *v17; // $v1
  const char *v18; // $v0
  int v19; // $t0
  int v20; // $a3
  int v21; // $a2
  int v22; // $a1
  int v23; // $s6
  char *v25; // $a3
  _DWORD *v26; // $fp
  int v27; // $s7
  int v28; // $t0
  int v29; // $a3
  int v30; // $a2
  int v31; // $a1
  int v32; // $a1
  int v33; // $a2
  int v34; // $a0
  const char *v35; // $v0
  const char *v36; // $v0
  char s[1024]; // [sp+30h] [-420h] BYREF
  char *v38; // [sp+430h] [-20h]
  char *v39; // [sp+434h] [-1Ch]
  char *v40; // [sp+438h] [-18h]
  char *v41; // [sp+43Ch] [-14h]
  char *v42; // [sp+440h] [-10h]
  char *v43; // [sp+444h] [-Ch]
  char *v44; // [sp+448h] [-8h]
  char *v45; // [sp+44Ch] [-4h]

  v2 = httpd_get_parm(a1, "name");
  v3 = httpd_get_parm(a1, "old_name");
  v38 = httpd_get_parm(a1, "en");
  v39 = httpd_get_parm(a1, (char *)&off_647174);
  v40 = httpd_get_parm(a1, "inip");
  v41 = httpd_get_parm(a1, "fport");
  v42 = httpd_get_parm(a1, "inport");
  v43 = httpd_get_parm(a1, "prot");
  v44 = httpd_get_parm(a1, "wans");
  v4 = httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  _mem_malloc(0x200000, "nat_base2_asp", 186);
  v8 = v7;
  _mem_malloc(0x200000, "nat_base2_asp", 187);
  v9 = v6;
  if ( v8 )
  {
    if ( !v6 )
    {
      v32 = *(unsigned __int8 *)(a1 + 210102);
      v33 = 0x200000;
      v34 = 4;
      goto LABEL_56;
    }
    if ( !v5 )
      goto LABEL_62;
    if ( !strcmp(v5, (const char *)&off_64712C) )
    {
      v11 = httpd_get_parm(a1, "nf_loopback");
      v12 = httpd_get_parm(a1, "nf_dxtong");
      v38 = httpd_get_parm(a1, "nf_fullcone");
      if ( v11 )
      {
        v14 = (const char *)nvram_get("nf_loopback");
        if ( !v14 || strcmp(v14, v11) )
          nvram_set("nf_loopback", v11);
      }
      if ( v12 )
      {
        v15 = (const char *)nvram_get("nf_dxtong");
        if ( !v15 || strcmp(v15, v12) )
          nvram_set("nf_dxtong", v12);
      }
      if ( v38 )
      {
        v16 = (const char *)nvram_get("nf_fullcone");
        if ( !v16 || strcmp(v16, v38) )
          nvram_set("nf_fullcone", v38);
      }
      jhl_parm_commit(v13);
      jhl_start_firewall();
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
      goto LABEL_25;
    }
    if ( !strcmp(v5, (const char *)&off_646D8C) || !strcmp(v5, (const char *)&off_648DDC) )
    {
      if ( !strcmp(v5, "delall") )
        goto LABEL_9;
      if ( strcmp(v5, "del") )
        goto LABEL_32;
    }
    else
    {
      if ( strcmp(v5, "del") )
      {
        if ( !strcmp(v5, "delall") )
        {
LABEL_9:
          *(_BYTE *)v9 = 32;
          *(_BYTE *)(v9 + 1) = 0;
          v45 = "a";
          goto LABEL_10;
        }
LABEL_62:
        v32 = *(unsigned __int8 *)(a1 + 210102);
        v33 = (int)"not opt";
        v34 = 12;
        goto LABEL_56;
      }
      if ( !strcmp(v5, "delall") )
        goto LABEL_9;
    }
    if ( v4 && cJSON_IsArray(v4) )
    {
      v26 = *(_DWORD **)(v4 + 8);
      if ( !v26 )
        goto LABEL_52;
      v27 = 0;
      if ( !v26[4] )
        goto LABEL_52;
      v45 = "a";
      v38 = "portforward";
      do
      {
        jhl_parm_get("portforward", v8, 0x200000);
        if ( nvparm_del_str(v8, 62, 10, v26[4], 60, 6, v9) )
        {
          jhl_parm_set(v38, v9);
          v27 = 1;
        }
        v26 = (_DWORD *)*v26;
      }
      while ( v26 && v26[4] );
      if ( !v27 )
        goto LABEL_52;
      goto LABEL_10;
    }
LABEL_32:
    if ( v2 )
    {
      if ( strcmp(v5, (const char *)&off_646D8C) && strcmp(v5, (const char *)&off_648DDC) )
        goto LABEL_52;
      v45 = "a";
      jhl_parm_get("portforward", v8, 0x200000);
      if ( v3 )
        v25 = v3;
      else
        v25 = v2;
      if ( nvparm_del_str(v8, 62, 10, v25, 60, 6, v9) )
      {
        if ( !strcmp(v5, (const char *)&off_646D8C) )
        {
          v23 = check_rule_num_limit(a1, 27, (int)(v45 + 7376), 62, s, 0x400u);
          if ( v23 > 0 )
            goto LABEL_26;
          sprintf(v8, "%s<%s<%s<%s<%s<%s<%s<%s>", v38, v43, v39, v41, v42, v40, v2, v44);
        }
        else
        {
          sprintf(v8, "%s<%s<%s<%s<%s<%s<%s<%s>", v38, v43, v39, v41, v42, v40, v2, v44);
        }
      }
      else
      {
        if ( !strcmp(v5, (const char *)&off_646D8C) )
        {
          v23 = check_rule_num_limit(a1, 27, (int)(v45 + 7376), 62, s, 0x400u);
          if ( v23 > 0 )
            goto LABEL_26;
          sprintf(v8, "%s<%s<%s<%s<%s<%s<%s<%s>", v38, v43, v39, v41, v42, v40, v2, v44);
        }
        else
        {
          sprintf(v8, "%s<%s<%s<%s<%s<%s<%s<%s>", v38, v43, v39, v41, v42, v40, v2, v44);
        }
        jhl_parm_get(v45 + 7376, v9, 0x200000);
        if ( !strcmp((const char *)v9, " ") )
          *(_BYTE *)v9 = 0;
      }
      strcat((char *)v9, v8);
LABEL_10:
      jhl_parm_set(v45 + 7376, v9);
      jhl_parm_commit(v10);
      jhl_start_firewall();
LABEL_52:
      v17 = s;
      v18 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v28 = *(_DWORD *)v18;
        v29 = *((_DWORD *)v18 + 1);
        v30 = *((_DWORD *)v18 + 2);
        v31 = *((_DWORD *)v18 + 3);
        v18 += 16;
        *(_DWORD *)v17 = v28;
        *((_DWORD *)v17 + 1) = v29;
        *((_DWORD *)v17 + 2) = v30;
        *((_DWORD *)v17 + 3) = v31;
        v17 += 16;
      }
      while ( v18 != "}" );
LABEL_25:
      v23 = 33;
      *(_WORD *)v17 = *(_WORD *)v18;
LABEL_26:
      _mem_free(v8);
      goto LABEL_27;
    }
    v32 = *(unsigned __int8 *)(a1 + 210102);
    v33 = (int)&unk_6442E4;
    v34 = 12;
LABEL_56:
    v35 = (const char *)_GET_LANG_TEXT(v34, v32, v33);
    v23 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v35);
    if ( (unsigned int)v23 >= 0x400 )
      v23 = 1023;
    goto LABEL_26;
  }
  v36 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v23 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v36);
  if ( (unsigned int)v23 >= 0x400 )
    v23 = 1023;
LABEL_27:
  if ( v9 )
    _mem_free((void *)v9);
  return httpd_cgi_ret(a1, s, v23, 4);
}
// 4A42AC: variable 'v7' is possibly undefined
// 4A42B8: variable 'v6' is possibly undefined
// 4A43A8: variable 'v10' is possibly undefined
// 4A4534: variable 'v13' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 647174: using guessed type void *off_647174;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

