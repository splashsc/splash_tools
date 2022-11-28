int __fastcall sub_471174(int a1)
{
  char *v2; // $s6
  char *v3; // $s5
  char *v4; // $s1
  char *v5; // $v0
  char *v6; // $s3
  char *v7; // $s4
  int v8; // $v0
  int v9; // $a2
  int v11; // $a1
  char *v12; // $a2
  int v13; // $a0
  const char *v14; // $v0
  int v15; // $a2
  int v16; // $a1
  int v17; // $a0
  const char *v18; // $v0
  int v19; // $t0
  int v20; // $a3
  int v21; // $a2
  int v22; // $a0
  int v23; // $v1
  int v24; // $a2
  int v25[256]; // [sp+18h] [-61Ch] BYREF
  char v26[512]; // [sp+418h] [-21Ch] BYREF
  int v27; // [sp+618h] [-1Ch] BYREF
  int v28; // [sp+61Ch] [-18h]
  int v29; // [sp+620h] [-14h]
  int v30; // [sp+624h] [-10h]
  int v31; // [sp+628h] [-Ch]

  v2 = httpd_get_parm(a1, (char *)&off_649194);
  v3 = httpd_get_parm(a1, "old_pwd");
  v4 = httpd_get_parm(a1, "opt");
  v6 = httpd_get_parm(a1, "i");
  v5 = httpd_get_parm(a1, "u");
  if ( !v4 || (v7 = v5, strcmp(v4, "modpwd")) && strcmp(v4, "down") )
  {
    v11 = *(unsigned __int8 *)(a1 + 210102);
    v12 = "not opt";
LABEL_12:
    v13 = 12;
LABEL_13:
    v14 = (const char *)_GET_LANG_TEXT(v13, v11, v12);
LABEL_14:
    v9 = sprintf(v26, "{\"ret\":1,\"msg\":\"%s\"}", v14);
    return httpd_cgi_ret(a1, v26, v9, 4);
  }
  if ( !v7 || !v6 )
  {
    v11 = *(unsigned __int8 *)(a1 + 210102);
    v12 = "not user or ipaddr";
    goto LABEL_12;
  }
  v27 = 0;
  v28 = 0;
  v29 = 0;
  v30 = 0;
  v31 = 0;
  if ( strchr(v6, 46) || strchr(v6, 58) )
    StrToIpaddr(v6, &v27);
  else
    v28 = J_atoi(v6);
  if ( !strcmp(v4, "down") )
  {
    user_ipdown_set(&v27, 0);
    v16 = *(unsigned __int8 *)(a1 + 210102);
    v17 = 83;
LABEL_18:
    v18 = (const char *)_GET_LANG_TEXT(v17, v16, v15);
    v9 = sprintf(v26, "{\"ret\":0,\"msg\":\"%s\"}", v18);
    return httpd_cgi_ret(a1, v26, v9, 4);
  }
  v8 = strcmp(v4, "modpwd");
  v9 = 0;
  if ( !v8 )
  {
    memset(v25, 0, sizeof(v25));
    v25[0] = 16;
    v25[3] = 21;
    v25[1] = 1024;
    v25[57] = v27;
    v25[58] = v28;
    v25[59] = v29;
    v25[60] = v30;
    v19 = *(_DWORD *)(a1 + 205460);
    v20 = *(_DWORD *)(a1 + 205464);
    v21 = *(_DWORD *)(a1 + 205468);
    v22 = *(_DWORD *)(a1 + 205472);
    v25[61] = v31;
    v23 = *(_DWORD *)(a1 + 205476);
    v25[52] = v19;
    v25[53] = v20;
    v25[56] = v23;
    v25[54] = v21;
    v25[55] = v22;
    strlcpy(&v25[4], v7, 64);
    strlcpy(&v25[36], v2, 64);
    strlcpy(&v25[20], v3, 64);
    if ( jianhl_order_opt_fun(v25, v25[1], v24) )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      v12 = "";
      v13 = 3;
      goto LABEL_13;
    }
    if ( v25[2] )
    {
      v11 = *(unsigned __int8 *)(a1 + 210102);
      if ( v25[2] >= 0x33u || (v12 = (char *)jhlret_err_str[v25[2]]) == 0 )
        v12 = "not find err!";
      v13 = 3;
      goto LABEL_13;
    }
    if ( v25[62] == 1 )
    {
      v16 = *(unsigned __int8 *)(a1 + 210102);
      v17 = 78;
      goto LABEL_18;
    }
    if ( v25[62] < 2 )
    {
      if ( !v25[62] )
      {
        v16 = *(unsigned __int8 *)(a1 + 210102);
        v17 = 79;
        goto LABEL_18;
      }
    }
    else
    {
      if ( v25[62] == 2 )
      {
        v16 = *(unsigned __int8 *)(a1 + 210102);
        v17 = 76;
        goto LABEL_18;
      }
      if ( v25[62] == 13 )
      {
        v16 = *(unsigned __int8 *)(a1 + 210102);
        v17 = 77;
        goto LABEL_18;
      }
    }
    v14 = (const char *)_GET_LANG_TEXT(80, *(unsigned __int8 *)(a1 + 210102), v15);
    goto LABEL_14;
  }
  return httpd_cgi_ret(a1, v26, v9, 4);
}
// 471410: variable 'v15' is possibly undefined
// 471554: variable 'v24' is possibly undefined
// 649194: using guessed type char *off_649194;
// 6A8284: using guessed type int __fastcall StrToIpaddr(_DWORD, _DWORD);
// 6A82C4: using guessed type int __fastcall user_ipdown_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8900: using guessed type int __fastcall jianhl_order_opt_fun(_DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

