int __fastcall sub_494C4C(int a1)
{
  char *v2; // $s7
  char *v3; // $s6
  char *v4; // $s5
  char *v5; // $s1
  char *v6; // $v0
  char *v7; // $v0
  char *v8; // $s2
  char *v9; // $s4
  int v10; // $v0
  _DWORD *v11; // $s5
  char *v12; // $fp
  int v13; // $v0
  int v14; // $s6
  const char *v15; // $a0
  int v16; // $v0
  int v17; // $s7
  int v18; // $a0
  int *v19; // $v1
  const char *v20; // $v0
  int v21; // $t0
  int v22; // $a3
  int v23; // $a2
  int v24; // $a1
  int v25; // $s6
  int v27; // $v0
  int v28; // $a1
  int v29; // $a2
  int v30; // $a0
  const char *v31; // $v0
  int s[64]; // [sp+28h] [-148h] BYREF
  int v33[6]; // [sp+128h] [-48h] BYREF
  char *v34; // [sp+140h] [-30h] BYREF
  char *v35; // [sp+144h] [-2Ch]
  char *v36; // [sp+148h] [-28h]
  char *v37; // [sp+14Ch] [-24h]
  int v38; // [sp+150h] [-20h]
  int v39; // [sp+154h] [-1Ch]
  char *v40; // [sp+158h] [-18h]
  const char *v41; // [sp+15Ch] [-14h]
  int v42; // [sp+160h] [-10h]
  char *v43; // [sp+164h] [-Ch]
  char *v44; // [sp+168h] [-8h]
  char *v45; // [sp+16Ch] [-4h]

  v44 = "a";
  v34 = 0;
  v35 = 0;
  v36 = 0;
  v37 = 0;
  v38 = 0;
  v39 = 0;
  v45 = "1\"";
  v40 = httpd_get_parm(a1, "name");
  v42 = (int)httpd_get_parm(a1, "old_name");
  v2 = httpd_get_parm(a1, "id");
  v3 = httpd_get_parm(a1, "dns");
  v4 = httpd_get_parm(a1, "wans");
  v5 = httpd_get_parm(a1, "opt");
  v41 = (const char *)httpd_get_json_parm(a1, (int)"del_list");
  _mem_malloc(10240, "dns_more_dnswan_asp", 1072);
  v8 = v7;
  _mem_malloc(10240, "dns_more_dnswan_asp", 1073);
  v9 = v6;
  if ( v8 && v6 )
  {
    v10 = a1 + 196608;
    if ( v5 )
    {
      if ( !strcmp(v5, (const char *)&off_646D8C) || !strcmp(v5, (const char *)&off_648DDC) )
      {
        v43 = "1\"";
        if ( strcmp(v5, "del") )
        {
LABEL_19:
          if ( v40 )
          {
            v34 = v40;
            if ( strcmp(v5, (const char *)&off_646D8C) && strcmp(v5, (const char *)&off_648DDC) )
              goto LABEL_35;
            if ( !v2 || !*v2 )
              v2 = "0";
            v35 = v2;
            if ( !v3 || !*v3 )
              v3 = "";
            v36 = v3;
            if ( !v4 || !*v4 )
              v4 = "";
            v37 = v4;
            if ( v42 )
            {
              s[0] = (int)"wys";
              s[1] = (int)"dns_more";
              s[2] = (int)"dnswan";
              s[4] = v42;
              s[3] = (int)(v43 - 15196);
              s[5] = 0;
              eval(s, 0, 0, 0);
              v17 = dns_more_dnswan_add(v34, v35, v36, v37);
            }
            else
            {
              v25 = check_rule_num_limit(a1, 6, (int)"dns_more_dnswan", 60, (char *)s, 0x100u);
              if ( v25 > 0 )
                goto LABEL_38;
              v17 = set_dns_more_dnswan_to_kernel(v5, &v34);
            }
            if ( v17 < 0 )
              goto LABEL_35;
            if ( !strcmp(v5, (const char *)&off_648DDC)
              && ((jhl_parm_get("dns_more_dnswan", v8, 10240), !v42) ? (v27 = nvparm_del_str(v8, 60, 6, v40, 124, 0, v9)) : (v27 = nvparm_del_str(v8, 60, 6, v42, 124, 0, v9)),
                  v27) )
            {
              sprintf(v8, "%s|%d|%s|%s<", v34, v17, v36, v37);
            }
            else
            {
              sprintf(v8, "%s|%d|%s|%s<", v34, v17, v36, v37);
              jhl_parm_get("dns_more_dnswan", v9, 10240);
              if ( !strcmp(v9, " ") )
                *v9 = 0;
            }
            strcat(v9, v8);
            goto LABEL_34;
          }
          v28 = *(unsigned __int8 *)(a1 + 210102);
          v29 = (int)&unk_6442E4;
          goto LABEL_50;
        }
LABEL_7:
        if ( v41 && cJSON_IsArray(v41) )
        {
          v11 = (_DWORD *)*((_DWORD *)v41 + 2);
          if ( !v11 )
          {
LABEL_35:
            v19 = s;
            v20 = "{\"code\":0,\"error\":\"\",\"data\":null}";
            do
            {
              v21 = *(_DWORD *)v20;
              v22 = *((_DWORD *)v20 + 1);
              v23 = *((_DWORD *)v20 + 2);
              v24 = *((_DWORD *)v20 + 3);
              v20 += 16;
              *v19 = v21;
              v19[1] = v22;
              v19[2] = v23;
              v19[3] = v24;
              v19 += 4;
            }
            while ( v20 != "}" );
            v25 = 33;
            *(_WORD *)v19 = *(_WORD *)v20;
            goto LABEL_38;
          }
          v42 = 0;
          v40 = v44 + 17128;
          v12 = v45 - 3336;
          v41 = "dns_more_dnswan";
          do
          {
            v14 = cJSON_GetObjectItem(v11, v40);
            v13 = cJSON_GetObjectItem(v11, v12);
            if ( v14 && v13 )
            {
              v15 = *(const char **)(v13 + 16);
              v34 = *(char **)(v14 + 16);
              v16 = dns_more_dnswan_is_used(v15);
              if ( v16 )
              {
                v29 = *(_DWORD *)(v14 + 16);
                v28 = *(unsigned __int8 *)(a1 + 210102);
                v30 = v16;
                goto LABEL_51;
              }
              if ( set_dns_more_dnswan_to_kernel(v5, &v34) >= 0 )
              {
                jhl_parm_get(v41, v8, 10240);
                if ( nvparm_del_str(v8, 60, 6, *(_DWORD *)(v14 + 16), 124, 0, v9) )
                {
                  jhl_parm_set(v41, v9);
                  v42 = 1;
                }
              }
            }
            v11 = (_DWORD *)*v11;
          }
          while ( v11 );
          if ( !v42 )
            goto LABEL_35;
LABEL_34:
          v33[0] = (int)"wys";
          v33[1] = (int)"dns_more";
          v33[2] = (int)"dnswan";
          v33[3] = (int)"set_def";
          v33[4] = jhl_nv_get_def("dns_more_def_out");
          v33[5] = 0;
          eval(v33, 0, 0, 0);
          jhl_parm_set("dns_more_dnswan", v9);
          jhl_parm_commit(v18);
          goto LABEL_35;
        }
        goto LABEL_19;
      }
      v43 = "1\"";
      if ( !strcmp(v5, "del") )
        goto LABEL_7;
      v10 = a1 + 196608;
    }
    v28 = *(unsigned __int8 *)(v10 + 13494);
    v29 = (int)"not opt";
LABEL_50:
    v30 = 12;
    goto LABEL_51;
  }
  v28 = *(unsigned __int8 *)(a1 + 210102);
  v29 = 10240;
  v30 = 4;
LABEL_51:
  v31 = (const char *)_GET_LANG_TEXT(v30, v28, v29);
  v25 = snprintf((char *)s, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
  if ( (unsigned int)v25 >= 0x100 )
    v25 = 255;
LABEL_38:
  _mem_free(v8);
  _mem_free(v9);
  return httpd_cgi_ret(a1, (char *)s, v25, 4);
}
// 494DA0: variable 'v7' is possibly undefined
// 494DAC: variable 'v6' is possibly undefined
// 4951FC: variable 'v18' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 648DDC: using guessed type char *off_648DDC;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83C8: using guessed type int __fastcall nvparm_del_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A84FC: using guessed type int __fastcall dns_more_dnswan_add(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A875C: using guessed type int __fastcall set_dns_more_dnswan_to_kernel(_DWORD, _DWORD);
// 6A8910: using guessed type int __fastcall cJSON_GetObjectItem(_DWORD, _DWORD);

