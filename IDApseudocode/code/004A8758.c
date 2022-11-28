int __fastcall sub_4A8758(int a1)
{
  char *v2; // $s6
  char *v3; // $s4
  char *v4; // $v0
  const char *v5; // $s1
  const char *v6; // $v0
  unsigned int v7; // $s4
  _BYTE *v9; // $v0
  void *v10; // $v0
  void *v11; // $s2
  _BYTE *v12; // $s3
  _DWORD *v13; // $s1
  char *v14; // $s5
  char *v15; // $s3
  int v16; // $a0
  char *v17; // $s6
  int v18; // $v0
  const char *v19; // $v0
  char *v20; // $v1
  int v21; // $t0
  int v22; // $a3
  int v23; // $a2
  int v24; // $a1
  const char *v25; // $a1
  const char *v26; // $s7
  const char *v27; // $v1
  const char *v28; // $a3
  int v29; // $a0
  char *v30; // $v1
  const char *v31; // $v0
  int v32; // $t0
  int v33; // $a3
  int v34; // $a2
  int v35; // $a1
  int v36; // $v0
  int v37; // $a1
  int v38; // $a2
  int v39; // $a0
  const char *v40; // $v0
  int v41; // $v0
  const char *v42; // $v0
  int v43; // $v0
  const char *v44; // [sp+14h] [-17Ch]
  char v45[256]; // [sp+38h] [-158h] BYREF
  char *v46; // [sp+138h] [-58h] BYREF
  char *v47; // [sp+13Ch] [-54h]
  char *v48; // [sp+140h] [-50h]
  char *v49; // [sp+144h] [-4Ch]
  char *v50; // [sp+148h] [-48h]
  char *v51; // [sp+14Ch] [-44h]
  char *v52; // [sp+150h] [-40h]
  char *v53; // [sp+154h] [-3Ch]
  char *v54; // [sp+158h] [-38h]
  int v55; // [sp+168h] [-28h]
  char *v56; // [sp+16Ch] [-24h]
  char *v57; // [sp+170h] [-20h]
  char *v58; // [sp+174h] [-1Ch]
  char *v59; // [sp+178h] [-18h]
  char *v60; // [sp+17Ch] [-14h]
  char *v61; // [sp+180h] [-10h]
  char *v62; // [sp+184h] [-Ch]
  char *v63; // [sp+188h] [-8h]

  v61 = httpd_get_parm(a1, "en");
  v60 = httpd_get_parm(a1, "proto");
  v62 = httpd_get_parm(a1, (char *)&off_647174);
  v57 = httpd_get_parm(a1, "out_port");
  v58 = httpd_get_parm(a1, "in_port");
  v2 = httpd_get_parm(a1, "in_addr");
  v3 = httpd_get_parm(a1, "name");
  v56 = httpd_get_parm(a1, "interface");
  v59 = httpd_get_parm(a1, "convert_addr");
  v55 = httpd_get_json_parm(a1, (int)"del_list");
  v4 = httpd_get_parm(a1, "opt");
  if ( !v4 )
    goto LABEL_6;
  v5 = v4;
  if ( !strcmp(v4, (const char *)&off_646D8C) || !strcmp(v5, (const char *)&off_648DDC) || !strcmp(v5, "del") )
  {
    if ( !strcmp(v5, (const char *)&off_64712C) )
      goto LABEL_24;
    _mem_malloc(102400, "portward_nat_asp", 1423);
    v11 = v10;
    _mem_malloc(102400, "portward_nat_asp", 1424);
    v12 = v9;
    if ( !v11 )
    {
      v42 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
      v7 = snprintf(v45, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v42);
      if ( v7 >= 0x100 )
        v7 = 255;
      goto LABEL_64;
    }
    if ( v9 )
    {
      if ( !strcmp(v5, "del") && v55 && cJSON_IsArray(v55) )
      {
        v13 = *(_DWORD **)(v55 + 8);
        if ( !v13 || !v13[4] )
          goto LABEL_60;
        v63 = "1\"";
        v55 = 0;
        v56 = "portward_nat_list";
        do
        {
          jhl_parm_get("portward_nat_list", v11, 102400);
          if ( nvparm_get_str(v11, 60, 11, v13[4], 124, 6, &v46) )
          {
            if ( !strcmp(v46, "1") )
            {
              v41 = J_atoi(v53);
              if ( v54 )
              {
                if ( *v54 )
                  jhl_nat_onebyone_del_iface(v41, v54);
              }
            }
          }
          memset(v11, 0, 0x19000u);
          jhl_parm_get("portward_nat_list", v11, 102400);
          if ( nvparm_del_str(v11, 60, 11, v13[4], 124, 6, v12) )
          {
            jhl_parm_set(v56, v12);
            v55 = 1;
          }
          v13 = (_DWORD *)*v13;
        }
        while ( v13 && v13[4] );
LABEL_73:
        if ( !v55 )
        {
LABEL_60:
          jhl_start_firewall();
          v30 = v45;
          v31 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          do
          {
            v32 = *(_DWORD *)v31;
            v33 = *((_DWORD *)v31 + 1);
            v34 = *((_DWORD *)v31 + 2);
            v35 = *((_DWORD *)v31 + 3);
            v31 += 16;
            *(_DWORD *)v30 = v32;
            *((_DWORD *)v30 + 1) = v33;
            *((_DWORD *)v30 + 2) = v34;
            *((_DWORD *)v30 + 3) = v35;
            v30 += 16;
          }
          while ( v31 != "}" );
          v7 = 33;
          *(_WORD *)v30 = *(_WORD *)v31;
LABEL_63:
          _mem_free(v11);
LABEL_64:
          if ( v12 )
            _mem_free(v12);
          return httpd_cgi_ret(a1, v45, v7, 4);
        }
LABEL_59:
        jhl_parm_set(v63 - 11548, v12);
        jhl_parm_commit(v29);
        goto LABEL_60;
      }
      if ( v3 )
      {
        if ( !strcmp(v5, (const char *)&off_648DDC) )
        {
          v63 = "1\"";
          jhl_parm_get("portward_nat_list", v11, 102400);
          if ( nvparm_get_str(v11, 60, 11, v3, 124, 6, &v46) )
          {
            if ( !strcmp(v46, "1") )
            {
              v36 = J_atoi(v53);
              if ( v54 )
              {
                if ( *v54 )
                  jhl_nat_onebyone_del_iface(v36, v54);
              }
            }
          }
          v55 = 102400;
          memset(v11, 0, 0x19000u);
          jhl_parm_get(v63 - 11548, v11, v55);
          v55 = nvparm_del_str(v11, 60, 11, v3, 124, 6, v12) != 0;
          if ( strcmp(v5, (const char *)&off_646D8C) && strcmp(v5, (const char *)&off_648DDC) )
            goto LABEL_73;
        }
        else
        {
          if ( strcmp(v5, (const char *)&off_646D8C) )
            goto LABEL_60;
          v55 = 0;
        }
        v52 = v3;
        if ( v2 && *v2 )
        {
          v51 = v2;
          if ( !v59 || !*v59 )
            v59 = "";
          v54 = v59;
          if ( !v56 || !*v56 )
            v56 = "0";
          v53 = v56;
          if ( !v60 )
            v60 = "";
          v47 = v60;
          if ( !v57 || !*v57 )
            v57 = "";
          v49 = v57;
          if ( !v58 || !*v58 )
            v58 = "";
          v50 = v58;
          if ( v62 && *v62 )
            v48 = v62;
          else
            v48 = "";
          if ( !v61 || strcmp(v61, "1") )
          {
            v25 = v59;
            v26 = v56;
            v27 = v58;
            v28 = v60;
            v61 = "0";
            v44 = v57;
            goto LABEL_55;
          }
          v43 = J_atoi(v56);
          v25 = v54;
          if ( !v54 || !*v54 )
          {
            v28 = v47;
            v27 = v50;
            v2 = v51;
            v3 = v52;
            v26 = v53;
            v44 = v49;
            goto LABEL_55;
          }
          if ( !jhl_nat_onebyone_add_iface(v43, (int)v54) )
          {
            v28 = v47;
            v27 = v50;
            v2 = v51;
            v3 = v52;
            v26 = v53;
            v25 = v54;
            v44 = v49;
LABEL_55:
            v46 = v61;
            sprintf((char *)v11, "%s|%s|%s|%s|%s|%s|%s|%s|%s<", v61, v28, v48, v44, v27, v2, v3, v26, v25);
            if ( v55 )
            {
              strcat(v12, (char *)v11);
              v63 = "1\"";
            }
            else
            {
              v63 = "1\"";
              jhl_parm_get("portward_nat_list", v12, 102400);
              if ( !strcmp(v12, " ") )
                *v12 = 0;
              strcat(v12, (char *)v11);
            }
            goto LABEL_59;
          }
          v37 = *(unsigned __int8 *)(a1 + 210102);
          v38 = (int)&unk_64D350;
          v39 = 12;
        }
        else
        {
          v37 = *(unsigned __int8 *)(a1 + 210102);
          v38 = (int)&unk_64D344;
          v39 = 12;
        }
      }
      else
      {
        v37 = *(unsigned __int8 *)(a1 + 210102);
        v38 = (int)&unk_6442E4;
        v39 = 12;
      }
    }
    else
    {
      v37 = *(unsigned __int8 *)(a1 + 210102);
      v38 = 102400;
      v39 = 4;
    }
    v40 = (const char *)_GET_LANG_TEXT(v39, v37, v38);
    v7 = snprintf(v45, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v40);
    if ( v7 >= 0x100 )
      v7 = 255;
    goto LABEL_63;
  }
  if ( strcmp(v5, (const char *)&off_64712C) )
  {
LABEL_6:
    v6 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
    v7 = snprintf(v45, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v6);
    if ( v7 >= 0x100 )
      v7 = 255;
    return httpd_cgi_ret(a1, v45, v7, 4);
  }
LABEL_24:
  v14 = httpd_get_parm(a1, "nf_loopback");
  v15 = httpd_get_parm(a1, "nf_dxtong");
  v17 = httpd_get_parm(a1, "nf_fullcone");
  if ( v14 )
  {
    nvram_set("nf_loopback", v14);
    v18 = 1;
  }
  else
  {
    v18 = 0;
  }
  if ( v15 )
  {
    nvram_set("nf_dxtong", v15);
    if ( !v17 )
    {
LABEL_29:
      jhl_parm_commit(v16);
      jhl_start_firewall();
      goto LABEL_30;
    }
LABEL_28:
    nvram_set("nf_fullcone", v17);
    goto LABEL_29;
  }
  if ( v17 )
    goto LABEL_28;
  if ( v18 )
    goto LABEL_29;
LABEL_30:
  v19 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v20 = v45;
  do
  {
    v21 = *(_DWORD *)v19;
    v22 = *((_DWORD *)v19 + 1);
    v23 = *((_DWORD *)v19 + 2);
    v24 = *((_DWORD *)v19 + 3);
    v19 += 16;
    *(_DWORD *)v20 = v21;
    *((_DWORD *)v20 + 1) = v22;
    *((_DWORD *)v20 + 2) = v23;
    *((_DWORD *)v20 + 3) = v24;
    v20 += 16;
  }
  while ( v19 != "}" );
  *(_WORD *)v20 = *(_WORD *)v19;
  return httpd_cgi_ret(a1, v45, 33, 4);
}
// 4A8A1C: variable 'v10' is possibly undefined
// 4A8A28: variable 'v9' is possibly undefined
// 4A8C98: variable 'v16' is possibly undefined
// 4A8FCC: variable 'v29' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 647174: using guessed type void *off_647174;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86B0: using guessed type int __fastcall nvparm_get_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

