int __fastcall sub_4AB3F4(int a1)
{
  char *v2; // $s2
  char *v3; // $s3
  char *v4; // $fp
  char *v5; // $s1
  int v6; // $s7
  char *v7; // $s0
  char *v8; // $v0
  void *v9; // $v0
  void *v10; // $s5
  char *v11; // $s6
  int v12; // $v0
  _DWORD *v14; // $s0
  const char *v15; // $fp
  int v16; // $a1
  const char *v17; // $a2
  int v18; // $a0
  const char *v19; // $v0
  const char *v20; // $s7
  int v21; // $v0
  int v22; // $v0
  int v23; // $v0
  char *v24; // $a3
  char *v25; // $v0
  const char *v26; // $v1
  const char *v27; // $a0
  char *v28; // $a1
  const char *v29; // $a2
  const char *v30; // $t0
  char *v31; // $s0
  int v32; // $s3
  int v33; // $s1
  const char *v34; // $fp
  int v35; // $v0
  char *v36; // $v1
  const char *v37; // $v0
  int v38; // $t0
  int v39; // $a3
  int v40; // $a2
  int v41; // $a1
  __int16 v42; // $a0
  int v43; // $a0
  int v44; // $v0
  int v45; // $v0
  int v46; // $v0
  const char *v47; // $s7
  int v48; // $v0
  const char *v49; // [sp+20h] [-4178h]
  char v50[16384]; // [sp+38h] [-4160h] BYREF
  char s[256]; // [sp+4038h] [-160h] BYREF
  char *v52; // [sp+4138h] [-60h] BYREF
  char *v53; // [sp+413Ch] [-5Ch]
  char *v54; // [sp+4140h] [-58h]
  char *v55; // [sp+4144h] [-54h]
  char *v56; // [sp+4148h] [-50h]
  char *v57; // [sp+414Ch] [-4Ch]
  char *v58; // [sp+4150h] [-48h]
  char *v59; // [sp+4154h] [-44h]
  char *v60; // [sp+4158h] [-40h]
  char *v61; // [sp+415Ch] [-3Ch]
  char *v62; // [sp+4168h] [-30h]
  int v63; // [sp+416Ch] [-2Ch]
  char *v64; // [sp+4170h] [-28h]
  char *v65; // [sp+4174h] [-24h]
  char *v66; // [sp+4178h] [-20h]
  char *v67; // [sp+417Ch] [-1Ch]
  char *v68; // [sp+4180h] [-18h]
  char *v69; // [sp+4184h] [-14h]
  char *v70; // [sp+4188h] [-10h]
  char *v71; // [sp+418Ch] [-Ch]
  char *v72; // [sp+4190h] [-8h]
  char *v73; // [sp+4194h] [-4h]

  v69 = httpd_get_parm(a1, (char *)&off_647174);
  v73 = httpd_get_parm(a1, "old_src");
  v2 = httpd_get_parm(a1, "en");
  v3 = httpd_get_parm(a1, "nat_inter_en");
  v62 = httpd_get_parm(a1, "src_addr");
  v4 = httpd_get_parm(a1, "src_netmask");
  v65 = httpd_get_parm(a1, "target_addr_type");
  v66 = httpd_get_parm(a1, "target_addr");
  v67 = httpd_get_parm(a1, "target_netmask");
  v68 = httpd_get_parm(a1, "to_address");
  v5 = httpd_get_parm(a1, "interface");
  v70 = "1\"";
  v6 = httpd_get_json_parm(a1, (int)"del_list");
  v7 = httpd_get_parm(a1, "opt");
  _mem_malloc(10240, "menu_nat_more_asp", 2187);
  v10 = v9;
  _mem_malloc(10240, "menu_nat_more_asp", 2188);
  v11 = v8;
  if ( v10 && v8 )
  {
    if ( !v7 )
    {
LABEL_108:
      v16 = *(unsigned __int8 *)(a1 + 210102);
      v17 = "not opt";
LABEL_35:
      v18 = 12;
      goto LABEL_36;
    }
    v71 = "a";
    if ( !strcmp(v7, (const char *)&off_646D8C) || (v64 = "1\"", !strcmp(v7, (const char *)&off_648DDC)) )
    {
      if ( strcmp(v7, "del") )
        goto LABEL_10;
    }
    else if ( strcmp(v7, "del") )
    {
      if ( !strcmp(v7, "delall") )
      {
        v63 = 1;
        goto LABEL_13;
      }
      goto LABEL_108;
    }
    if ( v6 && cJSON_IsArray(v6) )
    {
      v14 = *(_DWORD **)(v6 + 8);
      if ( !v14 || !v14[4] )
      {
        v64 = s;
LABEL_97:
        jhl_start_firewall();
        v36 = v64;
        v37 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v38 = *(_DWORD *)v37;
          v39 = *((_DWORD *)v37 + 1);
          v40 = *((_DWORD *)v37 + 2);
          v41 = *((_DWORD *)v37 + 3);
          v37 += 16;
          *(_DWORD *)v36 = v38;
          *((_DWORD *)v36 + 1) = v39;
          *((_DWORD *)v36 + 2) = v40;
          *((_DWORD *)v36 + 3) = v41;
          v36 += 16;
        }
        while ( v37 != "}" );
        v42 = *(_WORD *)v37;
        v12 = 33;
        *(_WORD *)v36 = v42;
        goto LABEL_18;
      }
      v63 = 0;
      do
      {
        jhl_parm_get("nat_list_more", v10, 10240);
        if ( nvparm_get_str(v10, 60, 12, v14[4], 124, 9, &v52) )
        {
          if ( !strcmp(v52, "1") )
          {
            if ( !strcmp(v53, "1") )
              jhl_nat_more_del_iface((int)v54, (int)v55);
            v15 = v59;
            if ( strcmp(v59, "255") )
            {
              v45 = J_atoi(v15);
              jhl_nat_more_del_wanip(v45, (int)v60);
            }
          }
          jhl_parm_set("nat_list_more", v11);
          v63 = 1;
        }
        v14 = (_DWORD *)*v14;
      }
      while ( v14 && v14[4] );
      v64 = s;
      goto LABEL_96;
    }
LABEL_10:
    if ( !strcmp(v7, "delall") )
    {
      v63 = 1;
      v64 = "1\"";
    }
    else
    {
      if ( !v69 )
      {
        v16 = *(unsigned __int8 *)(a1 + 210102);
        v17 = (const char *)&unk_6442E4;
        goto LABEL_35;
      }
      v63 = 0;
      v64 = "1\"";
    }
LABEL_13:
    if ( !strcmp(v7, v64 - 29220) )
    {
      v72 = "1\"";
      jhl_parm_get("nat_list_more", v10, 10240);
      if ( v73 )
      {
        if ( nvparm_get_str(v10, 60, 12, v73, 124, 9, &v52) && !strcmp(v52, "1") )
        {
          if ( !strcmp(v53, "1") )
            jhl_nat_more_del_iface((int)v54, (int)v55);
          v20 = v59;
          if ( strcmp(v59, "255") )
          {
            v21 = J_atoi(v20);
            jhl_nat_more_del_wanip(v21, (int)v60);
          }
        }
        memset(v10, 0, 0x2800u);
        jhl_parm_get(v72 - 11388, v10, 10240);
        v22 = nvparm_del_str(v10, 60, 12, v73, 124, 9, v11);
      }
      else
      {
        if ( nvparm_get_str(v10, 60, 12, v69, 124, 9, &v52) && !strcmp(v52, "1") )
        {
          if ( !strcmp(v53, "1") )
            jhl_nat_more_del_iface((int)v54, (int)v55);
          v47 = v59;
          if ( strcmp(v59, "255") )
          {
            v48 = J_atoi(v47);
            jhl_nat_more_del_wanip(v48, (int)v60);
          }
        }
        memset(v10, 0, 0x2800u);
        jhl_parm_get(v72 - 11388, v10, 10240);
        v22 = nvparm_del_str(v10, 60, 12, v69, 124, 9, v11);
      }
      if ( v22 )
        v63 = 1;
      if ( !strcmp(v7, v71 + 28044) )
        goto LABEL_16;
      v23 = strcmp(v7, v64 - 29220);
      v64 = s;
      if ( !v23 )
        goto LABEL_50;
    }
    else if ( !strcmp(v7, v71 + 28044) )
    {
      v72 = "1\"";
LABEL_16:
      jhl_parm_get(v72 - 11388, v11, 10240);
      if ( !nvparm_find_str(v11, 60, 12, v69, 124, 9) )
      {
        v64 = s;
        v12 = check_rule_num_limit(a1, 29, (int)(v72 - 11388), 60, s, 0x100u);
        if ( v12 > 0 )
          goto LABEL_18;
LABEL_50:
        v61 = v69;
        if ( !v2 || !*v2 )
          v2 = "0";
        v52 = v2;
        if ( !v3 || !*v3 )
          v3 = "0";
        v53 = v3;
        if ( !v62 || !*v62 )
          v62 = "0.0.0.0";
        v54 = v62;
        if ( !v4 || !*v4 )
          v4 = "0.0.0.0";
        v55 = v4;
        if ( !v65 || !*v65 )
          v65 = "0";
        v56 = v65;
        if ( !v66 || !*v66 )
          v66 = "0.0.0.0";
        v57 = v66;
        if ( !v67 || !*v67 )
          v67 = "0.0.0.0";
        v58 = v67;
        if ( !v5 || !*v5 )
          v5 = "255";
        v59 = v5;
        if ( !v68 || !*v68 )
          v68 = "";
        v60 = v68;
        if ( !strcmp(v2, "1") )
        {
          if ( !strcmp(v3, "1") )
          {
            jhl_nat_more_add_iface((int)v62, (int)v4);
            v5 = v59;
          }
          if ( strcmp(v5, "255") )
          {
            v46 = J_atoi(v5);
            jhl_nat_more_add_wanip(v46, (int)v60);
            v24 = v53;
            v25 = v54;
            v4 = v55;
            v26 = v56;
            v27 = v57;
            v5 = v59;
            v29 = v60;
            v30 = v61;
            v49 = v58;
            goto LABEL_83;
          }
          v24 = v53;
          v25 = v54;
          v4 = v55;
          v26 = v56;
          v27 = v57;
          v28 = v58;
          v29 = v60;
          v30 = v61;
        }
        else
        {
          v30 = v69;
          v29 = v68;
          v28 = v67;
          v27 = v66;
          v26 = v65;
          v25 = v62;
          v24 = v3;
        }
        v49 = v28;
LABEL_83:
        v52 = v2;
        sprintf((char *)v10, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<", v2, v24, v25, v4, v26, v27, v49, v5, v29, v30);
        if ( !v63 )
        {
          jhl_parm_get(v72 - 11388, v11, 10240);
          if ( !strcmp(v11, " ") )
            *v11 = 0;
        }
        strcat(v11, (char *)v10);
        if ( strcmp(v7, "addall")
          || (jhl_parm_get(v72 - 11388, v10, 10240), v31 = v50,
                                                     v32 = split_string(v10, 60, v50, 4096),
                                                     v63 = 1,
                                                     v32 <= 0) )
        {
LABEL_101:
          jhl_parm_set(v72 - 11388, v11);
          jhl_parm_commit(v43);
          goto LABEL_97;
        }
        goto LABEL_88;
      }
      v16 = *(unsigned __int8 *)(a1 + 210102);
      v17 = "same name";
      goto LABEL_35;
    }
    v44 = strcmp(v7, "addall");
    v64 = s;
    if ( v44 || (jhl_parm_get("nat_list_more", v10, 10240), v31 = v50, v32 = split_string(v10, 60, v50, 4096), v32 <= 0) )
    {
LABEL_96:
      if ( !v63 )
        goto LABEL_97;
      v72 = "1\"";
      goto LABEL_101;
    }
LABEL_88:
    v33 = 0;
    v62 = "255";
    do
    {
      while ( 1 )
      {
        ++v33;
        if ( split_string(*(_DWORD *)v31, 124, &v52, 10) >= 5 && !strcmp(v52, "1") )
        {
          if ( !strcmp(v53, "1") )
            jhl_nat_more_del_iface((int)v54, (int)v55);
          v34 = v59;
          if ( strcmp(v59, v62) )
            break;
        }
        v31 += 4;
        if ( v33 >= v32 )
          goto LABEL_96;
      }
      v35 = J_atoi(v34);
      jhl_nat_more_del_wanip(v35, (int)v60);
      v31 += 4;
    }
    while ( v33 < v32 );
    goto LABEL_96;
  }
  v16 = *(unsigned __int8 *)(a1 + 210102);
  v17 = (const char *)10240;
  v18 = 4;
LABEL_36:
  v19 = (const char *)_GET_LANG_TEXT(v18, v16, v17);
  v64 = s;
  v12 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v19);
  if ( (unsigned int)v12 >= 0x100 )
    v12 = 255;
LABEL_18:
  v62 = (char *)v12;
  _mem_free(v10);
  _mem_free(v11);
  return httpd_cgi_ret(a1, v64, (int)v62, 4);
}
// 4AB5D4: variable 'v9' is possibly undefined
// 4AB5E0: variable 'v8' is possibly undefined
// 4AC0AC: variable 'v43' is possibly undefined
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
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

