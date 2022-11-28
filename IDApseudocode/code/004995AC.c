int __fastcall sub_4995AC(int a1)
{
  char *v2; // $s5
  char *v3; // $s6
  char *v4; // $s7
  char *v5; // $fp
  char *v6; // $s2
  char *v7; // $v0
  char *v8; // $v0
  char *v9; // $s1
  char *v10; // $s4
  const char *v11; // $v0
  int v12; // $s6
  int v13; // $v0
  int v14; // $a0
  bool v15; // dc
  char *v16; // $v0
  int *v17; // $v1
  const char *v18; // $v0
  int v19; // $t0
  int v20; // $a3
  int v21; // $a2
  int v22; // $a1
  _DWORD *v24; // $s6
  const char *v25; // $fp
  int v26; // $v0
  const char *v27; // $a2
  int v28; // $v0
  const char *v29; // $v1
  int v30; // $a0
  int v31; // $a1
  int v32; // $a0
  const char *v33; // $v0
  unsigned int v34; // $v0
  int v35; // $a2
  int v36; // $v0
  int v37; // $a1
  int v38; // $a0
  int v39; // $v0
  char v40[256]; // [sp+28h] [-270h] BYREF
  char *s; // [sp+128h] [-170h] BYREF
  const char *v42; // [sp+12Ch] [-16Ch]
  char *v43; // [sp+130h] [-168h]
  char *v44; // [sp+134h] [-164h]
  char *v45; // [sp+138h] [-160h]
  int v46; // [sp+13Ch] [-15Ch]
  int v47; // [sp+140h] [-158h]
  char v48[4]; // [sp+228h] [-70h] BYREF
  int v49; // [sp+22Ch] [-6Ch]
  int v50; // [sp+230h] [-68h]
  const char *v51; // [sp+244h] [-54h] BYREF
  char *v52; // [sp+248h] [-50h]
  char *v53; // [sp+24Ch] [-4Ch]
  char *v54; // [sp+250h] [-48h]
  char *v55; // [sp+254h] [-44h]
  int v56[4]; // [sp+260h] [-38h] BYREF
  char *v57; // [sp+270h] [-28h]
  char *v58; // [sp+274h] [-24h]
  char *v59; // [sp+278h] [-20h]
  int v60; // [sp+27Ch] [-1Ch]
  char *v61; // [sp+280h] [-18h]
  char *v62; // [sp+284h] [-14h]
  const char *v63; // [sp+288h] [-10h]
  char *v64; // [sp+28Ch] [-Ch]
  char *v65; // [sp+290h] [-8h]

  v61 = "1\"";
  v57 = httpd_get_parm(a1, "name");
  v58 = httpd_get_parm(a1, "old_name");
  v2 = httpd_get_parm(a1, "ip");
  v3 = httpd_get_parm(a1, "mask");
  v4 = httpd_get_parm(a1, "speed");
  v5 = httpd_get_parm(a1, "dns");
  v6 = httpd_get_parm(a1, "opt");
  v59 = (char *)httpd_get_json_parm(a1, (int)"del_list");
  _mem_malloc(102400, "pppoe_group_asp", 661);
  v9 = v8;
  _mem_malloc(102400, "pppoe_group_asp", 662);
  v10 = v7;
  if ( v9 && v7 )
  {
    if ( !v6 )
    {
LABEL_8:
      v11 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
      goto LABEL_9;
    }
    v60 = (int)"a";
    if ( !strcmp(v6, (const char *)&off_646D8C) || !strcmp(v6, (const char *)&off_648DDC) )
    {
      if ( !strcmp(v6, "delall") )
        goto LABEL_37;
      v62 = "1\"";
      if ( strcmp(v6, "del") )
      {
LABEL_13:
        if ( v57 )
        {
          v51 = v57;
          if ( !strcmp(v6, (const char *)(v60 + 28044)) )
          {
            v59 = "1\"";
          }
          else
          {
            v59 = "1\"";
            if ( strcmp(v6, (const char *)&off_648DDC) )
            {
LABEL_38:
              v17 = (int *)&s;
              v18 = "{\"code\":0,\"error\":\"\",\"data\":null}";
              do
              {
                v19 = *(_DWORD *)v18;
                v20 = *((_DWORD *)v18 + 1);
                v21 = *((_DWORD *)v18 + 2);
                v22 = *((_DWORD *)v18 + 3);
                v18 += 16;
                *v17 = v19;
                v17[1] = v20;
                v17[2] = v21;
                v17[3] = v22;
                v17 += 4;
              }
              while ( v18 != "}" );
              v12 = 33;
              *(_WORD *)v17 = *(_WORD *)v18;
              goto LABEL_41;
            }
          }
          if ( !v2 || !*v2 )
            v2 = "";
          v52 = v2;
          if ( !v3 || !*v3 )
            v3 = "255.255.255.0";
          v53 = v3;
          if ( !v4 || !*v4 )
            v4 = "";
          v54 = v4;
          if ( !v5 || !*v5 )
            v5 = "";
          v55 = v5;
          if ( strcmp(v6, v59 - 29220) )
          {
            if ( !strcmp(v6, (const char *)(v60 + 28044)) )
            {
              v12 = check_rule_num_limit(a1, 24, (int)"pppoe_group_list", 60, (char *)&s, 0x100u);
              if ( v12 > 0 )
                goto LABEL_41;
            }
            if ( v58 )
              goto LABEL_27;
LABEL_83:
            v13 = set_pppoe_group_to_kernel(v6, &v51, "0");
            goto LABEL_29;
          }
          jhl_parm_get("pppoe_group_list", v9, 102400);
          if ( !v58 )
          {
            if ( nvparm_get_str(v9, 60, 7, v57, 124, 0, v48) )
            {
              ip_get_tbm(v49, v50, v40);
              s = v61 + 444;
              v42 = "route";
              v43 = v62 - 15196;
              v44 = v40;
              v45 = "dev";
              v46 = jhl_nv_get_def("pppoesrv");
              v47 = 0;
              eval(&s, 0, 0, 0);
            }
            goto LABEL_83;
          }
          if ( !strcmp(v58, "Default") )
          {
            v37 = *(unsigned __int8 *)(a1 + 210102);
            v38 = 45;
          }
          else
          {
            v36 = pppoe_group_get_username(v58);
            v35 = 7;
            if ( v36 < 3 )
            {
              if ( nvparm_get_str(v9, 60, 7, v58, 124, 0, v48) )
              {
                ip_get_tbm(v49, v50, v40);
                s = v61 + 444;
                v42 = "route";
                v43 = v62 - 15196;
                v44 = v40;
                v45 = "dev";
                v46 = jhl_nv_get_def("pppoesrv");
                v47 = 0;
                eval(&s, 0, 0, 0);
              }
LABEL_27:
              if ( pppoe_group_del_kernel(v58) )
                goto LABEL_38;
              v56[0] = (int)"pppoe_group_del.sh";
              v56[1] = (int)v58;
              v56[2] = 0;
              eval(v56, 0, 0, 0);
              v13 = set_pppoe_group_to_kernel(v60 + 28044, &v51, "0");
LABEL_29:
              if ( v13 < 0 )
                goto LABEL_38;
              if ( !strcmp(v6, v59 - 29220) )
              {
                v59 = "1\"";
                jhl_parm_get("pppoe_group_list", v9, 102400);
                if ( v58 )
                  v39 = nvparm_del_str(v9, 60, 7, v58, 124, 0, v10);
                else
                  v39 = nvparm_del_str(v9, 60, 7, v57, 124, 0, v10);
                if ( v39 )
                {
                  sprintf(v9, "%s|%s|%s|%s|%s<", v51, v52, v53, v54, v55);
LABEL_34:
                  strcat(v10, v9);
                  goto LABEL_35;
                }
              }
              else
              {
                v59 = "1\"";
              }
              sprintf(v9, "%s|%s|%s|%s|%s<", v51, v52, v53, v54, v55);
              jhl_parm_get(v59 - 15976, v10, 102400);
              if ( !strcmp(v10, " ") )
                *v10 = 0;
              goto LABEL_34;
            }
            v37 = *(unsigned __int8 *)(a1 + 210102);
            v38 = 46;
          }
          v11 = (const char *)_GET_LANG_TEXT(v38, v37, v35);
        }
        else
        {
          v11 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
        }
LABEL_9:
        v12 = snprintf((char *)&s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
        if ( (unsigned int)v12 >= 0x100 )
          v12 = 255;
LABEL_41:
        _mem_free(v9);
        _mem_free(v10);
        return httpd_cgi_ret(a1, (char *)&s, v12, 4);
      }
    }
    else
    {
      v62 = "1\"";
      if ( strcmp(v6, "del") )
      {
        if ( strcmp(v6, "delall") )
          goto LABEL_8;
        goto LABEL_37;
      }
      if ( !strcmp(v6, "delall") )
      {
LABEL_37:
        v15 = set_pppoe_group_to_kernel(v6, &v51, "0") == 0;
        v16 = v10;
        if ( !v15 )
          goto LABEL_38;
        v29 = "Default|172.16.1.1|255.255.255.0||<";
        do
        {
          v30 = *((_DWORD *)v29 + 1);
          *(_DWORD *)v16 = *(_DWORD *)v29;
          *((_DWORD *)v16 + 1) = v30;
          v31 = *((_DWORD *)v29 + 2);
          *((_DWORD *)v16 + 1) = v30;
          *((_DWORD *)v16 + 2) = v31;
          v32 = *((_DWORD *)v29 + 3);
          *((_DWORD *)v16 + 2) = v31;
          *((_DWORD *)v16 + 3) = v32;
          v29 += 16;
          *((_DWORD *)v16 + 3) = v32;
          v16 += 16;
        }
        while ( v29 != "||<" );
        *(_DWORD *)v16 = *(_DWORD *)v29;
        v52 = "172.16.1.1";
        v51 = "Default";
        v53 = "255.255.255.0";
        v54 = "";
        v55 = "";
        set_pppoe_group_to_kernel(v60 + 28044, &v51, "0");
        v59 = "1\"";
LABEL_35:
        jhl_parm_set(v59 - 15976, v10);
        jhl_parm_commit(v14);
        goto LABEL_38;
      }
    }
    if ( v59 && cJSON_IsArray(v59) )
    {
      v24 = (_DWORD *)*((_DWORD *)v59 + 2);
      if ( !v24 )
        goto LABEL_38;
      v25 = (const char *)v24[4];
      if ( !v25 )
        goto LABEL_38;
      v57 = "1\"";
      v60 = 0;
      v58 = "a";
      v65 = "1\"";
      v63 = "route";
      v64 = "dev";
      do
      {
        v26 = strcmp(v25, v57 - 15812);
        v27 = v58 + 14076;
        if ( !v26 )
        {
          v11 = (const char *)_GET_LANG_TEXT(43, *(unsigned __int8 *)(a1 + 210102), v27);
          goto LABEL_9;
        }
        v51 = v25;
        if ( set_pppoe_group_to_kernel(v6, &v51, v27) < 0 )
        {
          v11 = (const char *)_GET_LANG_TEXT(44, *(unsigned __int8 *)(a1 + 210102), 102400);
          goto LABEL_9;
        }
        jhl_parm_get("pppoe_group_list", v9, 102400);
        v28 = nvparm_get_str(v9, 60, 7, v24[4], 124, 0, v48);
        v59 = "1\"";
        if ( v28 )
        {
          ip_get_tbm(v49, v50, v40);
          v43 = v62 - 15196;
          s = v61 + 444;
          v42 = v63;
          v44 = v40;
          v45 = v64;
          v46 = jhl_nv_get_def(v65 - 15804);
          v47 = 0;
          eval(&s, 0, 0, 0);
        }
        jhl_parm_get("pppoe_group_list", v9, 102400);
        if ( nvparm_del_str(v9, 60, 7, v24[4], 124, 0, v10) )
        {
          jhl_parm_set("pppoe_group_list", v10);
          v60 = 1;
        }
        v24 = (_DWORD *)*v24;
        if ( !v24 )
          break;
        v25 = (const char *)v24[4];
      }
      while ( v25 );
      if ( !v60 )
        goto LABEL_38;
      goto LABEL_35;
    }
    goto LABEL_13;
  }
  _mem_free(v9);
  _mem_free(v10);
  v33 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v34 = snprintf((char *)&s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v33);
  if ( v34 >= 0x100 )
    v34 = 255;
  return httpd_cgi_ret(a1, (char *)&s, v34, 4);
}
// 499704: variable 'v8' is possibly undefined
// 499710: variable 'v7' is possibly undefined
// 499A98: variable 'v14' is possibly undefined
// 49A07C: variable 'v35' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8250: using guessed type int __fastcall set_pppoe_group_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A84D0: using guessed type int __fastcall pppoe_group_del_kernel(_DWORD);
// 6A85D4: using guessed type int __fastcall pppoe_group_get_username(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86B0: using guessed type int __fastcall nvparm_get_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A898C: using guessed type int __fastcall ip_get_tbm(_DWORD, _DWORD, _DWORD);

