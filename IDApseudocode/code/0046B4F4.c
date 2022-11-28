int __fastcall sub_46B4F4(int a1)
{
  char *v2; // $s5
  char *v3; // $s3
  int v4; // $v0
  char *v5; // $s0
  int v6; // $s6
  const char *v7; // $v0
  int v8; // $v0
  _DWORD *v10; // $s0
  int v11; // $a0
  unsigned int v12; // $v0
  int *v13; // $s0
  struct in_addr v14; // $a0
  char *v15; // $v0
  struct in_addr v16; // $a0
  char *v17; // $v0
  int v18; // $v0
  int v19; // $v0
  char *v20; // $v0
  char *v21; // $s2
  int v22; // $a0
  char *v23; // $v1
  const char *v24; // $v0
  int v25; // $t0
  int v26; // $a3
  int v27; // $a2
  int v28; // $a1
  unsigned int v29; // $v0
  int v30; // $a1
  int v31; // $a2
  int v32; // $a0
  int v33; // $a2
  char *v34; // $v0
  const char *v35; // $a2
  char s[128]; // [sp+20h] [-1A0h] BYREF
  char v37[100]; // [sp+A0h] [-120h] BYREF
  _WORD v38[50]; // [sp+104h] [-BCh] BYREF
  int v39[11]; // [sp+168h] [-58h] BYREF
  _DWORD v40[5]; // [sp+194h] [-2Ch] BYREF
  _DWORD v41[6]; // [sp+1A8h] [-18h] BYREF

  v2 = httpd_get_parm(a1, "name");
  v3 = httpd_get_parm(a1, (char *)&off_64712C);
  v5 = httpd_get_parm(a1, "opt");
  v4 = httpd_get_json_parm(a1, (int)"del_list");
  if ( !v5 )
    goto LABEL_6;
  v6 = v4;
  if ( strcmp(v5, (const char *)&off_646D8C) && strcmp(v5, "del") )
  {
    if ( strcmp(v5, (const char *)&off_64712C) )
    {
      if ( strcmp(v5, "delall") )
      {
LABEL_6:
        v7 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), "not opt");
        goto LABEL_7;
      }
      goto LABEL_48;
    }
    goto LABEL_23;
  }
  if ( !strcmp(v5, (const char *)&off_64712C) )
  {
LABEL_23:
    v41[0] = 0;
    v41[1] = 0;
    v41[2] = 0;
    v41[3] = 0;
    v41[4] = 0;
    v40[0] = 0;
    v40[1] = 0;
    v40[2] = 0;
    v40[3] = 0;
    v40[4] = 0;
    if ( !v3 )
    {
      v7 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_647128);
      goto LABEL_7;
    }
    jhl_parm_get("dnsEn", v38, 100);
    jhl_parm_get("lan_ifname", v37, 100);
    if ( strcmp((const char *)v38, "1") && strcmp((const char *)v38, "0") )
      v38[0] = 49;
    v13 = (int *)wys_get_dns();
    if ( *v13 <= 0 )
    {
      strcpy((char *)v40, "114.114.114.114");
      strcpy((char *)v41, "8.8.8.8");
    }
    else
    {
      v14.s_addr = v13[1];
      if ( *v13 == 1 )
      {
        v34 = inet_ntoa(v14);
        strcpy((char *)v41, v34);
        v16.s_addr = v13[1];
      }
      else
      {
        v15 = inet_ntoa(v14);
        strcpy((char *)v41, v15);
        v16.s_addr = v13[2];
      }
      v17 = inet_ntoa(v16);
      strcpy((char *)v40, v17);
    }
    sprintf(s, "%s,%s", (const char *)v41, (const char *)v40);
    v39[0] = (int)"wys";
    v39[1] = (int)"dns";
    v39[2] = (int)"set";
    v18 = jhl_nv_get_def("dnsEn");
    v39[4] = (int)v3;
    v39[3] = v18;
    v39[5] = jhl_nv_get_def("dnsMintm");
    v39[6] = jhl_nv_get_def("dnsMaxtm");
    v19 = jhl_nv_get_def("dnsShowct");
    v39[9] = (int)"240c::6666 240c::6644";
    v39[8] = (int)s;
    v39[7] = v19;
    v39[10] = 0;
    eval(v39, 0, 0, 0);
    jhl_parm_set("dnsDef", v3);
    goto LABEL_32;
  }
  if ( !strcmp(v5, "delall") )
  {
LABEL_48:
    if ( dns_acc_delall() >= 0 )
    {
      jhl_parm_set("dnsAcc", "");
      goto LABEL_32;
    }
    v7 = (const char *)_GET_LANG_TEXT(113, *(unsigned __int8 *)(a1 + 210102), v33);
LABEL_7:
    v8 = snprintf(s, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v7);
    if ( (unsigned int)v8 >= 0x80 )
      v8 = 127;
    return httpd_cgi_ret(a1, s, v8, 4);
  }
  if ( !strcmp(v5, "del") && v6 && cJSON_IsArray(v6) )
  {
    v10 = *(_DWORD **)(v6 + 8);
    if ( v10 )
    {
      v11 = v10[4];
      if ( v11 )
      {
        while ( 1 )
        {
          v12 = dns_acc_del(v11);
          if ( v12 == -1 )
          {
            v7 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), &unk_647158);
            goto LABEL_7;
          }
          if ( v12 )
            break;
          v10 = (_DWORD *)*v10;
          if ( v10 )
          {
            v11 = v10[4];
            if ( v11 )
              continue;
          }
          goto LABEL_32;
        }
        if ( v12 >= 0x33 || (v35 = (const char *)jhlret_err_str[v12]) == 0 )
          v35 = "not find err!";
        v7 = (const char *)_GET_LANG_TEXT(3, *(unsigned __int8 *)(a1 + 210102), v35);
        goto LABEL_7;
      }
    }
  }
  else
  {
    if ( !v2 )
    {
      v7 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_6442E4);
      goto LABEL_7;
    }
    if ( !strcmp(v5, (const char *)&off_646D8C) )
    {
      v8 = check_rule_num_limit(a1, 32, (int)"dnsAcc", 60, s, 0x80u);
      if ( v8 > 0 )
        return httpd_cgi_ret(a1, s, v8, 4);
      v29 = dns_acc_add(v2);
      if ( v29 == -1 )
      {
        v30 = *(unsigned __int8 *)(a1 + 210102);
        v31 = (int)&unk_647158;
        v32 = 3;
        goto LABEL_51;
      }
      if ( v29 )
      {
        v30 = *(unsigned __int8 *)(a1 + 210102);
        if ( v29 >= 0x33 || (v31 = jhlret_err_str[v29]) == 0 )
          v31 = (int)"not find err!";
        v32 = 3;
        goto LABEL_51;
      }
    }
  }
LABEL_32:
  _mem_malloc(0x200000, "dns_acc_asp", 2719);
  v21 = v20;
  if ( !v20 )
  {
    v30 = *(unsigned __int8 *)(a1 + 210102);
    v31 = 0x200000;
    v32 = 4;
LABEL_51:
    v7 = (const char *)_GET_LANG_TEXT(v32, v30, v31);
    goto LABEL_7;
  }
  if ( dns_acc_get(v20, 0x200000u) )
    jhl_parm_set("dnsAcc", v21);
  else
    jhl_parm_set("dnsAcc", "");
  _mem_free(v21);
  jhl_parm_commit(v22);
  v23 = s;
  v24 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  do
  {
    v25 = *(_DWORD *)v24;
    v26 = *((_DWORD *)v24 + 1);
    v27 = *((_DWORD *)v24 + 2);
    v28 = *((_DWORD *)v24 + 3);
    v24 += 16;
    *(_DWORD *)v23 = v25;
    *((_DWORD *)v23 + 1) = v26;
    *((_DWORD *)v23 + 2) = v27;
    *((_DWORD *)v23 + 3) = v28;
    v23 += 16;
  }
  while ( v24 != "}" );
  *(_WORD *)v23 = *(_WORD *)v24;
  return httpd_cgi_ret(a1, s, 33, 4);
}
// 46BA18: variable 'v20' is possibly undefined
// 46BA7C: variable 'v22' is possibly undefined
// 46BD10: variable 'v33' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 64712C: using guessed type char **off_64712C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81D4: using guessed type int __fastcall dns_acc_del(_DWORD);
// 6A82B4: using guessed type int __fastcall cJSON_IsArray(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8784: using guessed type int __fastcall dns_acc_add(_DWORD);
// 6A88B4: using guessed type int wys_get_dns(void);

