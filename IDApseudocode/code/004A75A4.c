int __fastcall sub_4A75A4(int a1)
{
  char *v2; // $fp
  char *v3; // $s7
  char *v4; // $s6
  char *v5; // $s3
  char *v6; // $v0
  void *v7; // $v0
  void *v8; // $s1
  char *v9; // $s2
  int v10; // $v0
  int v11; // $a1
  const char *v12; // $a2
  int v13; // $a0
  const char *v14; // $v0
  int v15; // $s5
  int v17; // $a0
  char *v18; // $v1
  const char *v19; // $v0
  int v20; // $t0
  int v21; // $a3
  int v22; // $a2
  int v23; // $a1
  _DWORD *v24; // $s3
  int v25; // $v0
  int v26; // $v0
  const char *v27; // $a3
  const char *v28; // $v0
  const char *v29; // $v1
  int v30; // $v0
  const char *v31; // $v0
  int v32; // $v0
  int v33; // $v0
  char s[256]; // [sp+30h] [-148h] BYREF
  char *v35; // [sp+130h] [-48h] BYREF
  char *v36; // [sp+134h] [-44h]
  char *v37; // [sp+138h] [-40h]
  char *v38; // [sp+13Ch] [-3Ch]
  char *v39; // [sp+140h] [-38h]
  char *v40; // [sp+144h] [-34h]
  char *v41; // [sp+148h] [-30h]
  char *v42; // [sp+158h] [-20h]
  char *v43; // [sp+15Ch] [-1Ch]
  char *v44; // [sp+160h] [-18h]
  char *v45; // [sp+164h] [-14h]
  char *v46; // [sp+168h] [-10h]
  int v47; // [sp+16Ch] [-Ch]
  char *v48; // [sp+170h] [-8h]
  int v49; // [sp+174h] [-4h]

  v2 = httpd_get_parm(a1, (char *)&off_647174);
  v47 = (int)httpd_get_parm(a1, "old_src");
  v46 = httpd_get_parm(a1, "en");
  v42 = httpd_get_parm(a1, "in_addr");
  v3 = httpd_get_parm(a1, "out_addr");
  v4 = httpd_get_parm(a1, "interface");
  v43 = httpd_get_parm(a1, "out_port");
  v44 = httpd_get_parm(a1, "proto");
  v45 = (char *)httpd_get_json_parm(a1, (int)"del_list");
  v5 = httpd_get_parm(a1, "opt");
  _mem_malloc(102400, "menu_nat_asp", 1058);
  v8 = v7;
  _mem_malloc(102400, "menu_nat_asp", 1059);
  v9 = v6;
  if ( v8 )
  {
    if ( !v6 )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = (const char *)102400;
      v13 = 4;
      goto LABEL_10;
    }
    v10 = a1 + 196608;
    if ( !v5 )
      goto LABEL_9;
    if ( !strcmp(v5, (const char *)&off_646D8C) || !strcmp(v5, (const char *)&off_648DDC) )
    {
      if ( !strcmp(v5, "delall") )
        goto LABEL_25;
      if ( strcmp(v5, "del") )
        goto LABEL_18;
    }
    else
    {
      if ( strcmp(v5, "del") )
      {
        if ( strcmp(v5, "delall") )
        {
          v10 = a1 + 196608;
LABEL_9:
          v11 = *(unsigned __int8 *)(v10 + 13494);
          v12 = "not opt";
          v13 = 12;
LABEL_10:
          v14 = (const char *)_GET_LANG_TEXT(v13, v11, v12);
          goto LABEL_11;
        }
        goto LABEL_25;
      }
      if ( !strcmp(v5, "delall") )
      {
LABEL_25:
        v45 = "1\"";
LABEL_26:
        jhl_parm_set(v45 - 11760, v9);
        jhl_parm_commit(v17);
        goto LABEL_27;
      }
    }
    if ( v45 && cJSON_IsArray(v45) )
    {
      v24 = (_DWORD *)*((_DWORD *)v45 + 2);
      if ( !v24 || !v24[4] )
        goto LABEL_27;
      v45 = "1\"";
      v47 = 0;
      v42 = "nat_list_onebyone";
      do
      {
        jhl_parm_get("nat_list_onebyone", v8, 102400);
        if ( nvparm_get_str(v8, 60, 9, v24[4], 124, 4, &v35) && !strcmp(v35, "1") )
        {
          v30 = J_atoi(v38);
          jhl_nat_onebyone_del_iface(v30, v37);
        }
        memset(v8, 0, 0x19000u);
        jhl_parm_get("nat_list_onebyone", v8, 102400);
        if ( nvparm_del_str(v8, 60, 9, v24[4], 124, 4, v9) )
        {
          jhl_parm_set(v42, v9);
          v47 = 1;
        }
        v24 = (_DWORD *)*v24;
      }
      while ( v24 && v24[4] );
LABEL_73:
      if ( v47 )
        goto LABEL_26;
LABEL_27:
      jhl_start_firewall();
      v18 = s;
      v19 = "{\"code\":0,\"error\":\"\",\"data\":null}";
      do
      {
        v20 = *(_DWORD *)v19;
        v21 = *((_DWORD *)v19 + 1);
        v22 = *((_DWORD *)v19 + 2);
        v23 = *((_DWORD *)v19 + 3);
        v19 += 16;
        *(_DWORD *)v18 = v20;
        *((_DWORD *)v18 + 1) = v21;
        *((_DWORD *)v18 + 2) = v22;
        *((_DWORD *)v18 + 3) = v23;
        v18 += 16;
      }
      while ( v19 != "}" );
      v15 = 33;
      *(_WORD *)v18 = *(_WORD *)v19;
      goto LABEL_30;
    }
LABEL_18:
    if ( !v2 )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = (const char *)&unk_6442E4;
      v13 = 12;
      goto LABEL_10;
    }
    v48 = "1\"";
    if ( !strcmp(v5, (const char *)&off_648DDC) )
    {
      v45 = "1\"";
      jhl_parm_get("nat_list_onebyone", v8, 102400);
      if ( v47 )
      {
        if ( nvparm_get_str(v8, 60, 9, v47, 124, 4, &v35) && !strcmp(v35, "1") )
        {
          v32 = J_atoi(v38);
          jhl_nat_onebyone_del_iface(v32, v37);
        }
        v49 = 102400;
        memset(v8, 0, 0x19000u);
        jhl_parm_get(v45 - 11760, v8, v49);
        v25 = nvparm_del_str(v8, 60, 9, v47, 124, 4, v9);
      }
      else
      {
        if ( nvparm_get_str(v8, 60, 9, v2, 124, 4, &v35) && !strcmp(v35, "1") )
        {
          v33 = J_atoi(v38);
          jhl_nat_onebyone_del_iface(v33, v37);
        }
        v47 = 102400;
        memset(v8, 0, 0x19000u);
        jhl_parm_get(v45 - 11760, v8, v47);
        v25 = nvparm_del_str(v8, 60, 9, v2, 124, 4, v9);
      }
      v47 = v25 != 0;
      if ( strcmp(v5, (const char *)&off_646D8C) )
      {
        if ( strcmp(v5, v48 - 29220) )
          goto LABEL_73;
LABEL_48:
        v39 = v2;
        if ( !v42 || !*v42 )
          v42 = "0.0.0.0";
        v36 = v42;
        if ( !v3 || !*v3 )
          v3 = "0.0.0.0";
        v37 = v3;
        if ( !v4 || !*v4 )
          v4 = "0";
        v38 = v4;
        if ( !v44 )
          v44 = "";
        if ( !v43 )
          v43 = "";
        v40 = v43;
        v41 = v44;
        if ( !strcmp(v46, "1") )
        {
          v26 = J_atoi(v4);
          if ( jhl_nat_onebyone_add_iface(v26, (int)v37) )
          {
            v14 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_64D23C);
LABEL_11:
            v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
            if ( (unsigned int)v15 >= 0x100 )
            {
              _mem_free(v8);
              v15 = 255;
              goto LABEL_13;
            }
            goto LABEL_30;
          }
          v27 = v36;
          v3 = v37;
          v4 = v38;
          v2 = v39;
          v28 = v40;
          v29 = v41;
        }
        else
        {
          v29 = v44;
          v28 = v43;
          v27 = v42;
          v46 = "0";
        }
        v35 = v46;
        sprintf((char *)v8, "%s|%s|%s|%s|%s|%s|%s<", v46, v27, v3, v4, v2, v28, v29);
        if ( !v47 )
        {
          jhl_parm_get(v45 - 11760, v9, 102400);
          if ( !strcmp(v9, " ") )
            *v9 = 0;
        }
        strcat(v9, (char *)v8);
        goto LABEL_26;
      }
    }
    else
    {
      if ( strcmp(v5, (const char *)&off_646D8C) )
        goto LABEL_27;
      v47 = 0;
      v45 = "1\"";
    }
    jhl_parm_get(v45 - 11760, v9, 102400);
    if ( nvparm_find_str(v9, 60, 9, v2, 124, 4) )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = "same name";
      v13 = 12;
      goto LABEL_10;
    }
    v15 = check_rule_num_limit(a1, 28, (int)(v45 - 11760), 60, s, 0x100u);
    if ( v15 > 0 )
    {
LABEL_30:
      _mem_free(v8);
      goto LABEL_13;
    }
    goto LABEL_48;
  }
  v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v15 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
  if ( (unsigned int)v15 >= 0x100 )
    v15 = 255;
LABEL_13:
  if ( v9 )
    _mem_free(v9);
  return httpd_cgi_ret(a1, s, v15, 4);
}
// 4A772C: variable 'v7' is possibly undefined
// 4A7738: variable 'v6' is possibly undefined
// 4A79F4: variable 'v17' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 647174: using guessed type void *off_647174;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86B0: using guessed type int __fastcall nvparm_get_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

