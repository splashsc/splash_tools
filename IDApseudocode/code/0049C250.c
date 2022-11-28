int __fastcall sub_49C250(int a1)
{
  unsigned int v2; // $s3
  char *v3; // $s5
  char *v4; // $s6
  int v5; // $v0
  char *v6; // $s2
  int v7; // $s0
  int v8; // $a1
  const char *v9; // $a2
  const char *v10; // $v0
  unsigned int v11; // $a2
  _BOOL4 v12; // $s5
  int v13; // $a0
  const char *v14; // $v0
  char **v15; // $v1
  char *v16; // $t0
  char *v17; // $a3
  char *v18; // $a2
  char *v19; // $a1
  _DWORD *v21; // $fp
  char *v22; // $s0
  char *v23; // $s6
  char *v24; // $s2
  char *v25; // $s4
  int v26; // $a0
  char *v27; // $s5
  int v28; // $s6
  char *v29; // $a1
  char *v30; // $a1
  int v31; // $s4
  int v32; // $s4
  const char *v33; // $v1
  char **v34; // $v0
  char *v35; // $t0
  char *v36; // $a3
  char *v37; // $a2
  char *v38; // $a1
  int v39; // $t0
  _DWORD v40[25600]; // [sp+28h] [-32030h] BYREF
  char *v41; // [sp+19028h] [-19030h] BYREF
  char *v42; // [sp+1902Ch] [-1902Ch]
  int v43; // [sp+30028h] [-2030h] BYREF
  const char *v44; // [sp+32028h] [-30h] BYREF
  const char *v45; // [sp+3202Ch] [-2Ch]
  const char *v46; // [sp+32030h] [-28h]
  const char *v47; // [sp+32034h] [-24h]
  int v48; // [sp+32038h] [-20h]
  char *v49; // [sp+3203Ch] [-1Ch] BYREF
  char *v50; // [sp+32040h] [-18h]
  char *v51; // [sp+32048h] [-10h]
  const char *v52; // [sp+3204Ch] [-Ch]
  const char *v53; // [sp+32050h] [-8h]
  const char *v54; // [sp+32054h] [-4h]

  v2 = sq_file_get_max_wan();
  v3 = httpd_get_parm(a1, "wan_name");
  v4 = httpd_get_parm(a1, "wan_mac");
  v6 = httpd_get_parm(a1, "opt");
  v5 = httpd_get_json_parm(a1, (int)"del_list");
  if ( !v6 )
    goto LABEL_6;
  v7 = v5;
  if ( !strcmp(v6, (const char *)&off_646D8C) || !strcmp(v6, (const char *)&off_648DDC) )
  {
    if ( !strcmp(v6, (const char *)&off_64712C) )
      goto LABEL_34;
    if ( strcmp(v6, "del") )
      goto LABEL_12;
    goto LABEL_24;
  }
  if ( !strcmp(v6, "del") )
  {
    if ( !strcmp(v6, (const char *)&off_64712C) )
      goto LABEL_34;
LABEL_24:
    if ( v7 && cJSON_IsArray(v7) )
    {
      v21 = *(_DWORD **)(v7 + 8);
      if ( !v21 || !v21[4] )
        goto LABEL_19;
      v51 = "1\"";
      v52 = "wys";
      v53 = "pppoe_br";
      v12 = 0;
      v54 = "mac_del";
      do
      {
        jhl_parm_get("pppoe_br_mac", &v41, 102400);
        if ( nvparm_get_str(&v41, 60, 4, v21[4], 124, 0, &v49) )
        {
          v44 = v52;
          v45 = v53;
          v46 = v54;
          v47 = v50;
          v48 = 0;
          eval(&v44, 0, 0, 0);
          jhl_parm_get(v51 - 15228, &v41, 102400);
          if ( nvparm_del_str(&v41, 60, 4, v21[4], 124, 0, v40) )
          {
            jhl_parm_set(v51 - 15228, v40);
            v12 = 1;
          }
        }
        v21 = (_DWORD *)*v21;
      }
      while ( v21 && v21[4] );
LABEL_66:
      if ( !v12 )
      {
LABEL_19:
        v14 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        v15 = &v41;
        do
        {
          v16 = *(char **)v14;
          v17 = (char *)*((_DWORD *)v14 + 1);
          v18 = (char *)*((_DWORD *)v14 + 2);
          v19 = (char *)*((_DWORD *)v14 + 3);
          v14 += 16;
          *v15 = v16;
          v15[1] = v17;
          v15[2] = v18;
          v15[3] = v19;
          v15 += 4;
        }
        while ( v14 != "}" );
        v11 = 33;
        *(_WORD *)v15 = *(_WORD *)v14;
        return httpd_cgi_ret(a1, (char *)&v41, v11, 4);
      }
LABEL_18:
      jhl_parm_set("pppoe_br_mac", v40);
      jhl_parm_commit(v13);
      goto LABEL_19;
    }
LABEL_12:
    if ( !v3 )
    {
      v8 = *(unsigned __int8 *)(a1 + 210102);
      v9 = (const char *)&unk_6442E4;
      goto LABEL_7;
    }
    v51 = (char *)&v43;
    v49 = v3;
    if ( !strcmp(v6, (const char *)&off_648DDC) )
    {
      v53 = (const char *)102400;
      v52 = (const char *)&v41;
      jhl_parm_get("pppoe_br_mac", &v41, 102400);
      if ( nvparm_get_str(v52, 60, 4, v3, 124, 0, &v49) )
      {
        v39 = *((_DWORD *)v51 + 2054);
        v40[0] = "wys";
        v40[3] = v39;
        v40[1] = "pppoe_br";
        v40[2] = "mac_del";
        v40[4] = 0;
        eval(v40, 0, 0, 0);
        jhl_parm_get("pppoe_br_mac", v52, v53);
        v12 = nvparm_del_str(v52, 60, 4, v3, 124, 0, v40) != 0;
      }
      else
      {
        v12 = 0;
      }
      if ( strcmp(v6, (const char *)&off_646D8C) && strcmp(v6, (const char *)&off_648DDC) )
        goto LABEL_66;
    }
    else
    {
      v12 = 0;
      if ( strcmp(v6, (const char *)&off_646D8C) )
        goto LABEL_19;
    }
    if ( !v4 )
    {
      v10 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_646720);
LABEL_8:
      v11 = snprintf((char *)&v41, 102400, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
      if ( v11 >= 0x19000 )
        v11 = 102399;
      return httpd_cgi_ret(a1, (char *)&v41, v11, 4);
    }
    v44 = "wys";
    v45 = "pppoe_br";
    v50 = v4;
    v46 = "mac_add";
    v47 = v4;
    v48 = 0;
    eval(&v44, 0, 0, 0);
    sprintf((char *)&v41, "%s|%s<", v49, v50);
    if ( !v12 )
    {
      jhl_parm_get("pppoe_br_mac", v40, 102400);
      if ( !strcmp((const char *)v40, " ") )
        LOBYTE(v40[0]) = 0;
    }
    strcat((char *)v40, (char *)&v41);
    goto LABEL_18;
  }
  if ( strcmp(v6, (const char *)&off_64712C) )
  {
LABEL_6:
    v8 = *(unsigned __int8 *)(a1 + 210102);
    v9 = "not opt";
LABEL_7:
    v10 = (const char *)_GET_LANG_TEXT(12, v8, v9);
    goto LABEL_8;
  }
LABEL_34:
  v22 = httpd_get_parm(a1, "enable");
  v23 = httpd_get_parm(a1, "wan_br_iface");
  v24 = httpd_get_parm(a1, "wan_br_time");
  v25 = httpd_get_parm(a1, "wan_br_vlan");
  v27 = httpd_get_parm(a1, "wan_br_info");
  if ( v22 )
    jhl_parm_set("pppoe_br_enable", v22);
  if ( v23 )
  {
    v28 = split_string(v23, 124, &v41, 3);
    if ( v28 > 0 )
    {
      strcpy((char *)v40, "pppoe_br_wan");
      if ( v41 && v2 >= J_atoi(v41) )
      {
        v29 = v41;
      }
      else
      {
        v29 = "0";
        v41 = "0";
      }
      jhl_parm_set(v40, v29);
      if ( v28 != 1 )
      {
        sprintf((char *)v40, "pppoe_br_wan%d", 2);
        if ( v42 && v2 >= J_atoi(v42) )
        {
          v30 = v42;
        }
        else
        {
          v30 = "0";
          v42 = "0";
        }
        jhl_parm_set(v40, v30);
      }
    }
  }
  if ( v25 )
  {
    v31 = split_string(v25, 124, &v41, 3);
    if ( v31 > 0 )
    {
      strcpy((char *)v40, "pppoe_br_vlan");
      jhl_parm_set(v40, v41);
      if ( v31 != 1 )
      {
        sprintf((char *)v40, "pppoe_br_vlan%d", 2);
        jhl_parm_set(v40, v42);
      }
    }
  }
  if ( v27 )
  {
    v32 = split_string(v27, 124, &v41, 3);
    if ( v32 > 0 )
    {
      strcpy((char *)v40, "pppoe_br_info");
      jhl_parm_set(v40, v41);
      if ( v32 != 1 )
      {
        sprintf((char *)v40, "pppoe_br_info%d", 2);
        jhl_parm_set(v40, v42);
      }
    }
  }
  if ( v24 )
    jhl_parm_set("pppoe_br_time", v24);
  jhl_parm_commit(v26);
  jhl_gl_net_restart_timer(1000);
  v33 = "{\"code\":4,\"error\":\"\",\"data\":null}";
  v34 = &v41;
  do
  {
    v35 = *(char **)v33;
    v36 = (char *)*((_DWORD *)v33 + 1);
    v37 = (char *)*((_DWORD *)v33 + 2);
    v38 = (char *)*((_DWORD *)v33 + 3);
    v33 += 16;
    *v34 = v35;
    v34[1] = v36;
    v34[2] = v37;
    v34[3] = v38;
    v34 += 4;
  }
  while ( v33 != "}" );
  *(_WORD *)v34 = *(_WORD *)v33;
  v11 = 33;
  return httpd_cgi_ret(a1, (char *)&v41, v11, 4);
}
// 49C584: variable 'v13' is possibly undefined
// 49CBAC: variable 'v26' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86B0: using guessed type int __fastcall nvparm_get_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

