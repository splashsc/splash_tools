int __fastcall sub_491F24(int a1)
{
  char *v2; // $s7
  char *v3; // $s6
  char *v4; // $s1
  int v5; // $s5
  char *v6; // $v0
  char *v7; // $v0
  char *v8; // $s2
  char *v9; // $s4
  int v10; // $v0
  char *v11; // $s6
  int v12; // $a0
  char *v13; // $s1
  const char **v14; // $v1
  const char *v15; // $v0
  const char *v16; // $t0
  const char *v17; // $a3
  const char *v18; // $a2
  const char *v19; // $a1
  int v20; // $fp
  char *v22; // $v0
  const char *v23; // $v0
  const char *v24; // $v0
  const char *v25; // $v0
  int v26; // $a0
  const char *v27; // $t0
  const char *v28; // $a3
  const char *v29; // $a2
  const char *v30; // $a1
  _DWORD *v31; // $s7
  const char *v32; // $v0
  int v33; // $v0
  int v34; // $a1
  const char *v35; // $a2
  int v36; // $a0
  const char *v37; // $v0
  const char *s; // [sp+28h] [-468h] BYREF
  const char *v39; // [sp+2Ch] [-464h]
  char *v40; // [sp+30h] [-460h]
  char *v41; // [sp+34h] [-45Ch]
  char *v42; // [sp+38h] [-458h]
  char *v43; // [sp+3Ch] [-454h]
  int v44; // [sp+40h] [-450h]
  int v45; // [sp+44h] [-44Ch]
  const char *v46; // [sp+428h] [-68h] BYREF
  const char *v47; // [sp+42Ch] [-64h]
  const char *v48; // [sp+430h] [-60h]
  char *v49; // [sp+434h] [-5Ch]
  char *v50; // [sp+438h] [-58h]
  const char *v51; // [sp+43Ch] [-54h]
  const char *v52; // [sp+440h] [-50h]
  const char *v53; // [sp+444h] [-4Ch]
  const char *v54; // [sp+448h] [-48h]
  int v55; // [sp+44Ch] [-44h]
  char *v56; // [sp+450h] [-40h] BYREF
  char *v57; // [sp+454h] [-3Ch]
  const char *v58; // [sp+458h] [-38h]
  const char *v59; // [sp+45Ch] [-34h]
  char *v60; // [sp+460h] [-30h]
  const char *v61; // [sp+464h] [-2Ch]
  int v62; // [sp+468h] [-28h]
  int v63; // [sp+46Ch] [-24h]
  int v64; // [sp+470h] [-20h]
  char *v65; // [sp+474h] [-1Ch]
  char *v66; // [sp+478h] [-18h]
  char *v67; // [sp+47Ch] [-14h]
  char *v68; // [sp+480h] [-10h]
  char *v69; // [sp+484h] [-Ch]
  char *v70; // [sp+488h] [-8h]

  v56 = 0;
  v57 = 0;
  v58 = 0;
  v59 = 0;
  v60 = 0;
  v61 = 0;
  v62 = 0;
  v63 = 0;
  v2 = httpd_get_parm(a1, "name");
  v66 = httpd_get_parm(a1, "old_name");
  v64 = (int)httpd_get_parm(a1, "en");
  v67 = httpd_get_parm(a1, "rpri");
  v68 = httpd_get_parm(a1, "userzu");
  v69 = httpd_get_parm(a1, "dnszu");
  v3 = httpd_get_parm(a1, "outzu");
  v4 = httpd_get_parm(a1, "opt");
  v5 = httpd_get_json_parm(a1, (int)"del_list");
  _mem_malloc(102400, "dns_more_dnswan_rule_asp", 228);
  v8 = v7;
  _mem_malloc(102400, "dns_more_dnswan_rule_asp", 229);
  v9 = v6;
  if ( v8 && v6 )
  {
    v10 = a1 + 196608;
    if ( !v4 )
    {
LABEL_61:
      v34 = *(unsigned __int8 *)(v10 + 13494);
      v35 = "not opt";
LABEL_62:
      v36 = 12;
      goto LABEL_63;
    }
    v65 = "a";
    if ( !strcmp(v4, (const char *)&off_646D8C) || !strcmp(v4, (const char *)&off_648DDC) )
    {
      if ( !strcmp(v4, (const char *)&off_64712C) )
        goto LABEL_8;
      v70 = "1\"";
      if ( strcmp(v4, "del") )
        goto LABEL_18;
    }
    else
    {
      v70 = "1\"";
      if ( strcmp(v4, "del") )
      {
        if ( !strcmp(v4, (const char *)&off_64712C) )
        {
LABEL_8:
          v11 = httpd_get_parm(a1, "def_out");
          v13 = httpd_get_parm(a1, (char *)&off_645B94);
          if ( v11 )
          {
            nvram_set("dns_more_def_out", v11);
            s = "wys";
            v39 = "dns_more";
            v40 = "dnswan";
            v41 = "set_def";
            v42 = v11;
            v43 = 0;
            eval(&s, 0, 0, 0);
          }
          if ( v13 )
          {
            nvram_set("dns_more_def_pri", v13);
            s = "wys";
            v39 = "dns_more";
            v41 = "set";
            v40 = "opt";
            v42 = "on";
            v43 = v13;
            v44 = jhl_nv_get_def("dnsMaxtm");
            v45 = 0;
            eval(&s, 0, 0, 0);
          }
          jhl_parm_commit(v12);
          v14 = &s;
          v15 = "{\"code\":0,\"error\":\"\",\"data\":null}";
          do
          {
            v16 = *(const char **)v15;
            v17 = (const char *)*((_DWORD *)v15 + 1);
            v18 = (const char *)*((_DWORD *)v15 + 2);
            v19 = (const char *)*((_DWORD *)v15 + 3);
            v15 += 16;
            *v14 = v16;
            v14[1] = v17;
            v14[2] = v18;
            v14[3] = v19;
            v14 += 4;
          }
          while ( v15 != "}" );
          goto LABEL_14;
        }
        v10 = a1 + 196608;
        goto LABEL_61;
      }
      if ( !strcmp(v4, (const char *)&off_64712C) )
        goto LABEL_8;
    }
    if ( v5 && cJSON_IsArray(v5) )
    {
      v31 = *(_DWORD **)(v5 + 8);
      if ( !v31 )
        goto LABEL_40;
      v32 = (const char *)v31[4];
      if ( !v32 )
        goto LABEL_40;
      v64 = 0;
      do
      {
        v56 = (char *)v32;
        if ( set_dns_more_dnswan_rule_to_kernel(v4, &v56) >= 0 )
        {
          jhl_parm_get("dns_more_dnswan_rule", v8, 102400);
          if ( nvparm_del_str(v8, 60, 6, v31[4], 124, 0, v9) )
          {
            jhl_parm_set("dns_more_dnswan_rule", v9);
            v64 = 1;
          }
        }
        v31 = (_DWORD *)*v31;
        if ( !v31 )
          break;
        v32 = (const char *)v31[4];
      }
      while ( v32 );
      if ( !v64 )
        goto LABEL_40;
      goto LABEL_39;
    }
LABEL_18:
    if ( !v2 )
    {
      v34 = *(unsigned __int8 *)(a1 + 210102);
      v35 = (const char *)&unk_6442E4;
      goto LABEL_62;
    }
    v56 = v2;
    if ( !strcmp(v4, v65 + 28044) )
    {
      jhl_parm_get("dns_more_dnswan_rule", v9, 102400);
      if ( nvparm_find_str(v9, 60, 8, v56, 124, 0) )
      {
        v34 = *(unsigned __int8 *)(a1 + 210102);
        v35 = "same name";
        goto LABEL_62;
      }
      v20 = check_rule_num_limit(a1, 3, (int)"dns_more_dnswan_rule", 60, (char *)&s, 0x400u);
      if ( v20 > 0 )
        goto LABEL_15;
    }
    else if ( strcmp(v4, (const char *)&off_648DDC) )
    {
      goto LABEL_40;
    }
    v22 = (char *)v64;
    if ( !v64 )
      v22 = "1";
    v57 = v22;
    v23 = v68;
    if ( !v68 )
      v23 = "0";
    v58 = v23;
    v24 = v69;
    if ( !v69 )
      v24 = "0";
    v59 = v24;
    if ( !v3 )
      v3 = "0";
    v25 = v67;
    v60 = v3;
    if ( !v67 )
      v25 = "3000";
    v61 = v25;
    if ( v66 )
    {
      v64 = (int)&v46;
      v50 = v66;
      v46 = "wys";
      v47 = "dns_more";
      v48 = "dnswan_rule";
      v49 = v70 - 15196;
      v51 = 0;
      eval(&v46, 0, 0, 0);
      if ( !strcmp(v57, "1") )
      {
        v49 = v65 + 28044;
        v50 = v56;
        v51 = v58;
        v52 = v59;
        v53 = v60;
        v46 = "wys";
        v47 = "dns_more";
        v48 = "dnswan_rule";
        v54 = v61;
        v55 = 0;
        eval(v64, 0, 0, 0);
      }
      if ( strcmp(v4, (const char *)&off_648DDC) )
        goto LABEL_36;
      jhl_parm_get("dns_more_dnswan_rule", v8, 102400);
      v33 = nvparm_del_str(v8, 60, 8, v66, 124, 0, v9);
      goto LABEL_58;
    }
    if ( set_dns_more_dnswan_rule_to_kernel(v4, &v56) >= 0 )
    {
      if ( strcmp(v4, (const char *)&off_648DDC) )
        goto LABEL_36;
      jhl_parm_get("dns_more_dnswan_rule", v8, 102400);
      v33 = nvparm_del_str(v8, 60, 8, v2, 124, 0, v9);
LABEL_58:
      if ( v33 )
      {
        sprintf(v8, "%s|%s|%s|%s|%s|%s<", v56, v57, v58, v59, v60, v61);
LABEL_38:
        strcat(v9, v8);
LABEL_39:
        jhl_parm_set("dns_more_dnswan_rule", v9);
        jhl_parm_commit(v26);
        goto LABEL_40;
      }
LABEL_36:
      sprintf(v8, "%s|%s|%s|%s|%s|%s<", v56, v57, v58, v59, v60, v61);
      jhl_parm_get("dns_more_dnswan_rule", v9, 102400);
      if ( !strcmp(v9, " ") )
        *v9 = 0;
      goto LABEL_38;
    }
LABEL_40:
    v14 = &s;
    v15 = "{\"code\":0,\"error\":\"\",\"data\":null}";
    do
    {
      v27 = *(const char **)v15;
      v28 = (const char *)*((_DWORD *)v15 + 1);
      v29 = (const char *)*((_DWORD *)v15 + 2);
      v30 = (const char *)*((_DWORD *)v15 + 3);
      v15 += 16;
      *v14 = v27;
      v14[1] = v28;
      v14[2] = v29;
      v14[3] = v30;
      v14 += 4;
    }
    while ( v15 != "}" );
LABEL_14:
    v20 = 33;
    *(_WORD *)v14 = *(_WORD *)v15;
    goto LABEL_15;
  }
  v34 = *(unsigned __int8 *)(a1 + 210102);
  v35 = (const char *)102400;
  v36 = 4;
LABEL_63:
  v37 = (const char *)_GET_LANG_TEXT(v36, v34, v35);
  v20 = snprintf((char *)&s, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v37);
  if ( (unsigned int)v20 >= 0x400 )
    v20 = 1023;
LABEL_15:
  _mem_free(v8);
  _mem_free(v9);
  return httpd_cgi_ret(a1, (char *)&s, v20, 4);
}
// 4920B0: variable 'v7' is possibly undefined
// 4920BC: variable 'v6' is possibly undefined
// 4922A0: variable 'v12' is possibly undefined
// 492620: variable 'v26' is possibly undefined
// 645B94: using guessed type void *off_645B94;
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85F8: using guessed type int __fastcall set_dns_more_dnswan_rule_to_kernel(_DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

