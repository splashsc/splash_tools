int __fastcall sub_43E2A8(int a1)
{
  char *v2; // $s0
  int v3; // $s3
  int v4; // $a2
  _DWORD *v6; // $s2
  int v7; // $v0
  bool v8; // dc
  int v9; // $v0
  int v10; // $s3
  int v11; // $s5
  const char *v12; // $fp
  unsigned int v13; // $s0
  unsigned int v14; // $v0
  int v15; // $a0
  char *v16; // $v1
  const char *v17; // $v0
  int v18; // $t0
  int v19; // $a3
  int v20; // $a2
  int v21; // $a1
  int v22; // $a1
  const char *v23; // $a2
  const char *v24; // $v0
  int **v25; // $s3
  char *v26; // $s0
  int v27; // $v0
  const char *v28; // $s7
  int v29; // $s4
  int v30; // $fp
  int v31; // $s2
  const char *v32; // $s6
  unsigned int v33; // $v0
  int v34; // $t0
  int v35; // $a3
  int v36; // $a2
  int v37; // $a1
  char v38[20480]; // [sp+30h] [-A4D8h] BYREF
  char v39[20480]; // [sp+5030h] [-54D8h] BYREF
  char s[1024]; // [sp+A030h] [-4D8h] BYREF
  _BYTE v41[136]; // [sp+A430h] [-D8h] BYREF
  int v42; // [sp+A4B8h] [-50h] BYREF
  const char *v43; // [sp+A4BCh] [-4Ch]
  int v44; // [sp+A4C0h] [-48h]
  int v45; // [sp+A4C4h] [-44h]
  int v46; // [sp+A4C8h] [-40h]
  int v47; // [sp+A4CCh] [-3Ch]
  int v48; // [sp+A4D0h] [-38h]
  int v49; // [sp+A4D4h] [-34h]
  char *v50; // [sp+A4D8h] [-30h]
  char *v51; // [sp+A4DCh] [-2Ch]
  char *v52; // [sp+A4E0h] [-28h]
  char *v53; // [sp+A4E4h] [-24h]
  char *v54; // [sp+A4E8h] [-20h]
  char *v55; // [sp+A4ECh] [-1Ch]
  char *v56; // [sp+A4F0h] [-18h]
  int v57; // [sp+A4F4h] [-14h]
  int *v58; // [sp+A4F8h] [-10h]
  char *v59; // [sp+A4FCh] [-Ch]
  char *v60; // [sp+A500h] [-8h]
  int v61; // [sp+A530h] [+28h]

  memset(s, 0, sizeof(s));
  v2 = httpd_get_parm(a1, "opt");
  v50 = httpd_get_parm(a1, "name");
  v56 = httpd_get_parm(a1, "mode");
  v59 = httpd_get_parm(a1, "policy");
  v55 = httpd_get_parm(a1, "lanwan");
  v54 = httpd_get_parm(a1, "port");
  v53 = httpd_get_parm(a1, "bond");
  v52 = httpd_get_parm(a1, "old_bond");
  v51 = v39;
  v3 = httpd_get_json_parm(a1, (int)"del_list");
  memset(v39, 0, sizeof(v39));
  memset(v38, 0, sizeof(v38));
  v42 = 0;
  v43 = 0;
  v44 = 0;
  v45 = 0;
  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  if ( !v2 || !strcmp(v2, (const char *)&off_646D8C) || !strcmp(v2, (const char *)&off_648DDC) || !strcmp(v2, "del") )
  {
    v60 = "a";
    jhl_parm_get("bond_list", v51, 20480);
    if ( !strcmp(v2, (const char *)&off_646D8C) )
    {
      if ( v53 && v54 && v50 && v55 && v56 && v59 )
      {
        v4 = check_rule_num_limit(a1, 37, (int)(v60 + 12064), 60, s, 0x400u);
        if ( v4 > 0 )
          return httpd_cgi_ret(a1, s, v4, 4);
        snprintf(v38, 20480, "%s%s|%s|%s|%s|%s|%s<", v51, v50, v53, v56, v59, v55, v54);
        goto LABEL_28;
      }
    }
    else
    {
      if ( strcmp(v2, (const char *)&off_648DDC) )
      {
        if ( strcmp(v2, "del") || !v3 || !cJSON_IsArray(v3) || (v25 = *(int ***)(v3 + 8)) == 0 || !v25[4] )
        {
          v17 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          v16 = s;
          do
          {
            v34 = *(_DWORD *)v17;
            v35 = *((_DWORD *)v17 + 1);
            v36 = *((_DWORD *)v17 + 2);
            v37 = *((_DWORD *)v17 + 3);
            v17 += 16;
            *(_DWORD *)v16 = v34;
            *((_DWORD *)v16 + 1) = v35;
            *((_DWORD *)v16 + 2) = v36;
            *((_DWORD *)v16 + 3) = v37;
            v16 += 16;
          }
          while ( v17 != "}" );
          goto LABEL_31;
        }
        v52 = v41;
        v50 = "%s|%s|%s|%s|%s|%s<";
        do
        {
          memset(v38, 0, sizeof(v38));
          v26 = v51;
          jhl_parm_get(v60 + 12064, v51, 20480);
          v27 = split_string(v26, 60, v52, 32);
          if ( v27 >= 2 )
          {
            v28 = v52;
            v29 = v27 - 1;
            v30 = 0;
            v31 = 0;
            do
            {
              while ( 1 )
              {
                split_string(*(_DWORD *)v28, 124, &v42, 6);
                v32 = v43;
                ++v30;
                if ( strcmp((const char *)v25[4], v43) )
                  break;
                v28 += 4;
                if ( v29 == v30 )
                  goto LABEL_48;
              }
              v33 = snprintf(&v38[v31], 20480 - v31, v50, v42, v32, v44, v45, v46, v47);
              if ( v33 >= 20480 - v31 )
                v33 = 20479 - v31;
              v31 += v33;
              v28 += 4;
            }
            while ( v29 != v30 );
          }
LABEL_48:
          nvram_set(v60 + 12064, v38);
          v25 = (int **)*v25;
        }
        while ( v25 && v25[4] );
LABEL_29:
        jhl_parm_commit(v15);
        jhl_gl_net_restart_timer(1000);
        v16 = s;
        v17 = "{\"code\":4,\"error\":\"\",\"data\":null}";
        do
        {
          v18 = *(_DWORD *)v17;
          v19 = *((_DWORD *)v17 + 1);
          v20 = *((_DWORD *)v17 + 2);
          v21 = *((_DWORD *)v17 + 3);
          v17 += 16;
          *(_DWORD *)v16 = v18;
          *((_DWORD *)v16 + 1) = v19;
          *((_DWORD *)v16 + 2) = v20;
          *((_DWORD *)v16 + 3) = v21;
          v16 += 16;
        }
        while ( v17 != "}" );
LABEL_31:
        v4 = 33;
        *(_WORD *)v16 = *(_WORD *)v17;
        return httpd_cgi_ret(a1, s, v4, 4);
      }
      if ( v52 && v53 && v54 && v50 && v55 && v56 )
      {
        memset(v38, 0, sizeof(v38));
        v6 = v41;
        v7 = split_string(v51, 60, v41, 32);
        v8 = v7 < 2;
        v9 = v7 - 1;
        if ( !v8 )
        {
          v57 = v9;
          v58 = &v42;
          v51 = "%s|%s|%s|%s|%s|%s<";
          v61 = a1;
          v10 = 0;
          v11 = 0;
          do
          {
            split_string(*v6, 124, v58, 6);
            v12 = v43;
            v13 = 20480 - v11;
            if ( !strcmp(v52, v43) )
            {
              v14 = snprintf(&v38[v11], 20480 - v11, v51, v50, v53, v56, v59, v55, v54);
              if ( v14 >= v13 )
                v14 = 20479 - v11;
            }
            else
            {
              v14 = snprintf(&v38[v11], 20480 - v11, v51, v42, v12, v44, v45, v46, v47);
              if ( v14 >= v13 )
                v14 = 20479 - v11;
            }
            v11 += v14;
            ++v10;
            ++v6;
          }
          while ( v10 != v57 );
          a1 = v61;
        }
LABEL_28:
        nvram_set(v60 + 12064, v38);
        goto LABEL_29;
      }
    }
    v22 = *(unsigned __int8 *)(a1 + 210102);
    v23 = "param err";
  }
  else
  {
    v22 = *(unsigned __int8 *)(a1 + 210102);
    v23 = "not opt";
  }
  v24 = (const char *)_GET_LANG_TEXT(12, v22, v23);
  v4 = snprintf(s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
  if ( (unsigned int)v4 >= 0x400 )
    v4 = 1023;
  return httpd_cgi_ret(a1, s, v4, 4);
}
// 43E8F4: variable 'v15' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

