int __fastcall sub_4687E0(int a1)
{
  char *v2; // $fp
  int v3; // $s5
  char *v4; // $s1
  char *v5; // $v0
  char *v6; // $v0
  char *v7; // $s4
  char *v8; // $s2
  int v9; // $v0
  char *v10; // $v1
  int v11; // $a1
  const char *v12; // $a2
  int v13; // $a0
  char *v14; // $s5
  char *v15; // $v1
  const char *v16; // $v0
  int v17; // $t0
  int v18; // $a3
  int v19; // $a2
  int v20; // $a1
  int v21; // $s7
  int v23; // $a0
  _DWORD *v24; // $fp
  const char *v25; // $v0
  int v26; // $a0
  const char *v27; // $v0
  const char *v28; // $v0
  int v29; // $v0
  char v30[1024]; // [sp+38h] [-5D8h] BYREF
  char s[256]; // [sp+438h] [-1D8h] BYREF
  char v32[64]; // [sp+538h] [-D8h] BYREF
  const char *v33; // [sp+578h] [-98h] BYREF
  char *v34; // [sp+57Ch] [-94h]
  const char *v35; // [sp+580h] [-90h]
  const char *v36; // [sp+584h] [-8Ch]
  char *v37; // [sp+588h] [-88h]
  const char *v38; // [sp+58Ch] [-84h]
  char *v39; // [sp+590h] [-80h]
  const char *v40; // [sp+594h] [-7Ch]
  const char *v41; // [sp+598h] [-78h]
  const char *v42; // [sp+59Ch] [-74h]
  const char *v43; // [sp+5A0h] [-70h]
  const char *v44; // [sp+5A4h] [-6Ch]
  int v45; // [sp+5A8h] [-68h]
  char *v46; // [sp+5ACh] [-64h] BYREF
  char *v47; // [sp+5B0h] [-60h]
  char *v48; // [sp+5B4h] [-5Ch]
  char *v49; // [sp+5B8h] [-58h]
  char *v50; // [sp+5BCh] [-54h]
  char *v51; // [sp+5C0h] [-50h]
  char *v52; // [sp+5C4h] [-4Ch]
  char *v53; // [sp+5C8h] [-48h]
  char *v54; // [sp+5CCh] [-44h]
  char *v55; // [sp+5D0h] [-40h]
  int v56; // [sp+5D4h] [-3Ch]
  int v57; // [sp+5D8h] [-38h]
  char *v58; // [sp+5E0h] [-30h]
  char *v59; // [sp+5E4h] [-2Ch]
  char *v60; // [sp+5E8h] [-28h]
  char *v61; // [sp+5ECh] [-24h]
  char *v62; // [sp+5F0h] [-20h]
  char *v63; // [sp+5F4h] [-1Ch]
  char *v64; // [sp+5F8h] [-18h]
  char *v65; // [sp+5FCh] [-14h]
  char *v66; // [sp+600h] [-10h]
  char *v67; // [sp+604h] [-Ch]
  char *v68; // [sp+608h] [-8h]
  char *v69; // [sp+60Ch] [-4h]

  v46 = 0;
  v47 = 0;
  v48 = 0;
  v49 = 0;
  v50 = 0;
  v51 = 0;
  v52 = 0;
  v53 = 0;
  v54 = 0;
  v55 = 0;
  v56 = 0;
  v57 = 0;
  memset(v32, 0, sizeof(v32));
  v58 = httpd_get_parm(a1, "name");
  v67 = httpd_get_parm(a1, "old_name");
  v59 = httpd_get_parm(a1, "en");
  v60 = httpd_get_parm(a1, "user_id");
  v61 = httpd_get_parm(a1, "shibie_name");
  v2 = httpd_get_parm(a1, "time");
  v62 = httpd_get_parm(a1, "act");
  v63 = httpd_get_parm(a1, (char *)&off_64E034);
  v64 = httpd_get_parm(a1, "rpri");
  v65 = httpd_get_parm(a1, "ipport");
  v66 = httpd_get_parm(a1, "ruleips");
  v3 = httpd_get_json_parm(a1, (int)"del_list");
  v4 = httpd_get_parm(a1, "opt");
  _mem_malloc(0x200000, "xwgl_ref_asp", 1835);
  v7 = v6;
  _mem_malloc(0x200000, "xwgl_ref_asp", 1836);
  v8 = v5;
  if ( v7 )
  {
    if ( v5 )
    {
      if ( !v4 )
      {
LABEL_9:
        v11 = *(unsigned __int8 *)(a1 + 210102);
        v12 = "not opt";
        v13 = 12;
        goto LABEL_75;
      }
      if ( strcmp(v4, (const char *)&off_646D8C) && strcmp(v4, (const char *)&off_648DDC) && strcmp(v4, "del") )
      {
        if ( strcmp(v4, "delall") )
        {
          v58 = "a";
          v9 = strcmp(v4, (const char *)&off_64712C);
          v10 = v58;
          if ( v9 )
            goto LABEL_9;
          goto LABEL_13;
        }
        goto LABEL_22;
      }
      if ( !strcmp(v4, "delall") )
      {
LABEL_22:
        if ( set_xwgl_ref_to_kernel(v4, &v46) )
          goto LABEL_15;
        *v8 = 0;
        v68 = "a";
LABEL_24:
        jhl_parm_set(v68 + 27928, v8);
        jhl_parm_commit(v23);
LABEL_15:
        v15 = s;
        v16 = "{\"code\":0,\"error\":\"\",\"data\":null}";
        do
        {
          v17 = *(_DWORD *)v16;
          v18 = *((_DWORD *)v16 + 1);
          v19 = *((_DWORD *)v16 + 2);
          v20 = *((_DWORD *)v16 + 3);
          v16 += 16;
          *(_DWORD *)v15 = v17;
          *((_DWORD *)v15 + 1) = v18;
          *((_DWORD *)v15 + 2) = v19;
          *((_DWORD *)v15 + 3) = v20;
          v15 += 16;
        }
        while ( v16 != "}" );
        v21 = 33;
        *(_WORD *)v15 = *(_WORD *)v16;
        goto LABEL_18;
      }
      v68 = "a";
      if ( !strcmp(v4, (const char *)&off_64712C) )
      {
        v10 = v68;
LABEL_13:
        v46 = httpd_get_parm(a1, v10 + 28972);
        v14 = v46;
        if ( !set_xwgl_ref_to_kernel(v4, &v46) )
        {
          jhl_parm_set("xwgl_def", v14);
          jhl_parm_commit(v26);
        }
        goto LABEL_15;
      }
      v68 = "a";
      strcpy(v32, "xwgl_all");
      if ( !strcmp(v4, "del") && v3 && cJSON_IsArray(v3) )
      {
        v24 = *(_DWORD **)(v3 + 8);
        if ( !v24 )
          goto LABEL_15;
        v25 = (const char *)v24[4];
        if ( !v25 )
          goto LABEL_15;
        v58 = 0;
        do
        {
          v46 = (char *)v25;
          if ( !set_xwgl_ref_to_kernel(v4, &v46) )
          {
            jhl_parm_get(v32, v7, 0x200000);
            if ( nvparm_del_str(v7, 60, 12, v24[4], 124, 0, v8) )
            {
              jhl_parm_set(v32, v8);
              v58 = (char *)1;
            }
          }
          v24 = (_DWORD *)*v24;
          if ( !v24 )
            break;
          v25 = (const char *)v24[4];
        }
        while ( v25 );
        if ( !v58 )
          goto LABEL_15;
        goto LABEL_24;
      }
      if ( v58 )
      {
        v46 = v58;
        if ( strcmp(v4, (const char *)&off_646D8C) && strcmp(v4, (const char *)&off_648DDC) )
          goto LABEL_15;
        v69 = v30;
        memset(v30, 0, sizeof(v30));
        if ( strcmp(v4, (const char *)&off_646D8C) )
        {
LABEL_40:
          if ( !v59 || !*v59 )
            v59 = "1";
          v47 = v59;
          if ( !v60 || !*v60 )
            v60 = "";
          v48 = v60;
          if ( !v61 || !*v61 )
            v61 = "0";
          v49 = v61;
          if ( !v2 || !*v2 )
            v2 = "OFF";
          v50 = v2;
          if ( !v62 || !*v62 )
            v62 = "1";
          v51 = v62;
          if ( !v63 || !*v63 )
            v63 = "1";
          v52 = v63;
          if ( !v64 || !*v64 )
            v64 = "1";
          v53 = v64;
          if ( !v65 || !*v65 )
            v65 = "";
          v54 = v65;
          if ( !v66 || !*v66 )
            v66 = "";
          v55 = v66;
          if ( get_time_group(v2, v69, 1024) )
            strlcpy(v69, v50, 1024);
          if ( v67 )
          {
            v34 = v67;
            v33 = "xwgl_ref_del.sh";
            v35 = 0;
            eval(&v33, 0, 0, 0);
            v33 = "xwgl_ref_add.sh";
            v34 = v46;
            v35 = v47;
            v36 = v48;
            v45 = 0;
            v37 = "0";
            v38 = v49;
            v39 = v69;
            v40 = v51;
            v41 = v52;
            v42 = v53;
            v43 = v54;
            v44 = v55;
            eval(&v33, 0, 0, 0);
            if ( strcmp(v4, (const char *)&off_648DDC) )
              goto LABEL_62;
            jhl_parm_get(v32, v7, 0x200000);
            v29 = nvparm_del_str(v7, 60, 12, v67, 124, 0, v8);
          }
          else
          {
            set_xwgl_ref_to_kernel(v4, &v46);
            if ( strcmp(v4, (const char *)&off_648DDC) )
              goto LABEL_62;
            jhl_parm_get(v32, v7, 0x200000);
            v29 = nvparm_del_str(v7, 60, 12, v58, 124, 0, v8);
          }
          if ( v29 )
          {
            sprintf(v7, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<", v46, v47, v48, v49, v50, v51, v52, v53, v54, v55);
LABEL_64:
            strcat(v8, v7);
            goto LABEL_24;
          }
LABEL_62:
          sprintf(v7, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s<", v46, v47, v48, v49, v50, v51, v52, v53, v54, v55);
          jhl_parm_get(v32, v8, 0x200000);
          if ( !strcmp(v8, " ") )
            *v8 = 0;
          goto LABEL_64;
        }
        jhl_parm_get(v32, v8, 0x200000);
        if ( !nvparm_find_str(v8, 60, 12, v58, 124, 0) )
        {
          v21 = check_rule_num_limit(a1, 13, (int)v32, 60, s, 0x100u);
          if ( v21 > 0 )
          {
LABEL_18:
            _mem_free(v7);
            goto LABEL_19;
          }
          goto LABEL_40;
        }
        v11 = *(unsigned __int8 *)(a1 + 210102);
        v12 = "same name";
        v13 = 12;
      }
      else
      {
        v11 = *(unsigned __int8 *)(a1 + 210102);
        v12 = (const char *)&unk_6442E4;
        v13 = 12;
      }
    }
    else
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = (const char *)0x200000;
      v13 = 4;
    }
LABEL_75:
    v27 = (const char *)_GET_LANG_TEXT(v13, v11, v12);
    v21 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
    if ( (unsigned int)v21 >= 0x100 )
      v21 = 255;
    goto LABEL_18;
  }
  v28 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v21 = snprintf(s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v28);
  if ( (unsigned int)v21 >= 0x100 )
    v21 = 255;
LABEL_19:
  if ( v8 )
    _mem_free(v8);
  return httpd_cgi_ret(a1, s, v21, 4);
}
// 468A0C: variable 'v6' is possibly undefined
// 468A18: variable 'v5' is possibly undefined
// 4691DC: variable 'v26' is possibly undefined
// 468C88: variable 'v23' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 64E034: using guessed type int (**off_64E034)();
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8298: using guessed type int __fastcall get_time_group(_DWORD, _DWORD, _DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86A4: using guessed type int __fastcall set_xwgl_ref_to_kernel(_DWORD, _DWORD);

