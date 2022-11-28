int __fastcall sub_467900(int a1)
{
  int v2; // $v0
  int v3; // $s2
  char *v4; // $s3
  char *v5; // $v0
  char *v6; // $v0
  char *v7; // $s0
  char *v8; // $s5
  char *v9; // $v0
  const char *v10; // $v0
  int v11; // $a0
  char *v12; // $v1
  const char *v13; // $v0
  int v14; // $t0
  int v15; // $a3
  int v16; // $a2
  int v17; // $a1
  int v18; // $s2
  char *v19; // $s4
  char *v20; // $s7
  char *v21; // $v0
  char *v22; // $v0
  int v23; // $a0
  _DWORD *v24; // $s7
  int v25; // $v0
  int v26; // $a1
  const char *v27; // $a2
  int v28; // $a0
  const char *v29; // $v0
  char *v30; // $a0
  char v32[512]; // [sp+28h] [-248h] BYREF
  char *v33; // [sp+228h] [-48h] BYREF
  char *v34; // [sp+22Ch] [-44h]
  const char *v35; // [sp+230h] [-40h]
  char *v36; // [sp+234h] [-3Ch]
  char *v37; // [sp+238h] [-38h]
  char *s; // [sp+240h] [-30h]
  char *v39; // [sp+244h] [-2Ch]
  char *v40; // [sp+248h] [-28h]
  char *v41; // [sp+24Ch] [-24h]
  char *v42; // [sp+250h] [-20h]
  char *v43; // [sp+254h] [-1Ch]
  char *v44; // [sp+258h] [-18h]
  char *v45; // [sp+25Ch] [-14h]
  const char *v46; // [sp+260h] [-10h]
  int v47; // [sp+264h] [-Ch]
  char *v48; // [sp+268h] [-8h]

  s = v32;
  v33 = 0;
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  memset(v32, 0, sizeof(v32));
  v41 = httpd_get_parm(a1, "qq");
  v40 = httpd_get_parm(a1, "name");
  v45 = httpd_get_parm(a1, "old_name");
  v48 = httpd_get_parm(a1, "time");
  v2 = httpd_get_json_parm(a1, (int)"del_list");
  v42 = "a";
  v3 = v2;
  v4 = httpd_get_parm(a1, "opt");
  _mem_malloc(102400, "qq_hbmd_asp", 1561);
  v7 = v6;
  _mem_malloc(102400, "qq_hbmd_asp", 1562);
  v8 = v5;
  if ( v7 && v5 )
  {
    if ( v4 )
    {
      v43 = "a";
      if ( !strcmp(v4, (const char *)&off_646D8C) )
      {
        v44 = "1\"";
LABEL_6:
        if ( strcmp(v4, (const char *)&off_64712C) )
        {
          v39 = "1\"";
          goto LABEL_8;
        }
        v39 = "1\"";
        goto LABEL_29;
      }
      v44 = "1\"";
      if ( !strcmp(v4, (const char *)&off_648DDC) )
        goto LABEL_6;
      v39 = "1\"";
      if ( !strcmp(v4, "del") )
      {
        if ( strcmp(v4, (const char *)&off_64712C) )
        {
LABEL_35:
          if ( v3 )
          {
            v24 = *(_DWORD **)(v3 + 8);
            if ( v24 )
            {
              v25 = v24[4];
              if ( v25 )
              {
                v47 = 0;
                v46 = "hbmd_all_commqq";
                do
                {
                  v33 = (char *)v25;
                  jhl_parm_get("hbmd_all_commqq", v7, 102400);
                  if ( nvparm_get_str(v7, 60, 7, v33, 124, 0, &v33) )
                  {
                    common_qq_val_edt(v39 - 15196, &v33);
                    jhl_parm_get(v46, v7, 102400);
                    if ( nvparm_del_str(v7, 60, 7, v33, 124, 0, v8) )
                    {
                      common_qq_val_edt(v39 - 15196, &v33);
                      jhl_parm_set("hbmd_all_commqq", v8);
                      v47 = 1;
                    }
                  }
                  v24 = (_DWORD *)*v24;
                  if ( !v24 )
                    break;
                  v25 = v24[4];
                }
                while ( v25 );
LABEL_10:
                if ( !strcmp(v4, v44 - 29220) )
                {
                  if ( v40 )
                  {
                    v9 = v45;
                    if ( !v45 )
                      v9 = v40;
                    v33 = v9;
                    jhl_parm_get("hbmd_all_commqq", v7, 102400);
                    if ( nvparm_get_str(v7, 60, 7, v33, 124, 0, &v33) )
                    {
                      jhl_parm_get("hbmd_all_commqq", v7, 102400);
                      if ( nvparm_del_str(v7, 60, 7, v33, 124, 0, v8) )
                      {
                        common_qq_val_edt(v39 - 15196, &v33);
                        jhl_parm_set("hbmd_all_commqq", v8);
                        v47 = 1;
                      }
                    }
                    if ( strcmp(v4, v43 + 28044) )
                    {
                      if ( !strcmp(v4, v44 - 29220) )
                      {
                        if ( v41 )
                        {
LABEL_18:
                          jhl_parm_get("hbmd_all_commqq", v8, 102400);
                          if ( !nvparm_find_str(v8, 60, 7, v40, 124, 0) )
                          {
                            v33 = v40;
                            v34 = v41;
                            v10 = v48;
                            if ( !v48 )
                              v10 = "OFF";
                            v35 = v10;
                            sprintf(v7, "%s|%s|%s<", v40, v41, v10);
                            strcat(v8, v7);
                            common_qq_val_edt(v43 + 28044, &v33);
                            goto LABEL_22;
                          }
                          v26 = *(unsigned __int8 *)(a1 + 210102);
                          v27 = "same name";
                          goto LABEL_48;
                        }
                        goto LABEL_47;
                      }
LABEL_51:
                      if ( !v47 )
                      {
LABEL_23:
                        v12 = s;
                        v13 = "{\"code\":0,\"error\":\"\",\"data\":null}";
                        do
                        {
                          v14 = *(_DWORD *)v13;
                          v15 = *((_DWORD *)v13 + 1);
                          v16 = *((_DWORD *)v13 + 2);
                          v17 = *((_DWORD *)v13 + 3);
                          v13 += 16;
                          *(_DWORD *)v12 = v14;
                          *((_DWORD *)v12 + 1) = v15;
                          *((_DWORD *)v12 + 2) = v16;
                          *((_DWORD *)v12 + 3) = v17;
                          v12 += 16;
                        }
                        while ( v13 != "}" );
                        v18 = 33;
                        *(_WORD *)v12 = *(_WORD *)v13;
                        goto LABEL_55;
                      }
LABEL_22:
                      jhl_parm_set("hbmd_all_commqq", v8);
                      jhl_parm_commit(v11);
                      goto LABEL_23;
                    }
                    if ( v41 )
                    {
LABEL_54:
                      v18 = check_rule_num_limit(a1, 17, (int)"hbmd_all_commqq", 60, s, 0x200u);
                      if ( v18 > 0 )
                      {
LABEL_55:
                        v30 = v7;
                        goto LABEL_56;
                      }
                      goto LABEL_18;
                    }
LABEL_47:
                    v26 = *(unsigned __int8 *)(a1 + 210102);
                    v27 = "not qqval";
LABEL_48:
                    v28 = 12;
                    goto LABEL_49;
                  }
                }
                else
                {
                  if ( strcmp(v4, v43 + 28044) )
                    goto LABEL_51;
                  if ( v40 )
                  {
                    if ( v41 )
                      goto LABEL_54;
                    goto LABEL_47;
                  }
                }
                v26 = *(unsigned __int8 *)(a1 + 210102);
                v27 = (const char *)&unk_6442E4;
                goto LABEL_48;
              }
            }
          }
LABEL_9:
          v47 = 0;
          goto LABEL_10;
        }
        goto LABEL_29;
      }
      if ( !strcmp(v4, (const char *)&off_64712C) )
      {
LABEL_29:
        v19 = httpd_get_parm(a1, "act");
        v20 = httpd_get_parm(a1, (char *)&off_64E034);
        if ( v19 )
          v21 = v19;
        else
          v21 = "0";
        v36 = v21;
        nvram_set("hbmd_def_commqq", v21);
        nvram_set("hbmd_def_qq", v36);
        nvram_set("hbmd_def_mqq", v36);
        common_qq_val_edt(&off_64712C, &v33);
        if ( v20 )
          v22 = v20;
        else
          v22 = "0";
        v37 = v22;
        nvram_set(&unk_646F64, v22);
        nvram_set("hbmd_log_qq", v37);
        nvram_set("hbmd_log_mqq", v37);
        common_qq_val_edt(&off_64E034, &v33);
        jhl_parm_commit(v23);
LABEL_8:
        if ( strcmp(v4, v39 - 15196) )
          goto LABEL_9;
        goto LABEL_35;
      }
    }
    v26 = *(unsigned __int8 *)(a1 + 210102);
    v27 = "not opt";
    goto LABEL_48;
  }
  v26 = *(unsigned __int8 *)(a1 + 210102);
  v27 = (const char *)102400;
  v28 = 4;
LABEL_49:
  v29 = (const char *)_GET_LANG_TEXT(v28, v26, v27);
  v18 = snprintf(s, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v29);
  v30 = v7;
  if ( (unsigned int)v18 >= 0x200 )
    v18 = 511;
LABEL_56:
  _mem_free(v30);
  _mem_free(v8);
  return httpd_cgi_ret(a1, s, v18, 4);
}
// 467A5C: variable 'v6' is possibly undefined
// 467A68: variable 'v5' is possibly undefined
// 467CD8: variable 'v11' is possibly undefined
// 467EC8: variable 'v23' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 648DDC: using guessed type char *off_648DDC;
// 64E034: using guessed type int (**off_64E034)();
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83BC: using guessed type int __fastcall common_qq_val_edt(_DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86B0: using guessed type int __fastcall nvparm_get_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

