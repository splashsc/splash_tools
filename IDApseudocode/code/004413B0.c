int __fastcall sub_4413B0(int a1)
{
  char *v2; // $v0
  char *v3; // $s0
  const char *v4; // $s1
  int v5; // $v0
  int v6; // $v0
  char *v7; // $s6
  int v8; // $v0
  int v9; // $v0
  char *v10; // $s0
  char *v11; // $v0
  char *v12; // $fp
  int v13; // $v0
  int v14; // $v0
  int v15; // $s3
  int v16; // $s1
  char *v17; // $s4
  int v18; // $s0
  const char **v19; // $s2
  void *v20; // $v0
  void *v21; // $s7
  void *v22; // $s7
  _DWORD *v23; // $s6
  int i; // $s7
  int v25; // $v0
  int v26; // $v0
  char *v27; // $a0
  int v28; // $s1
  int v29; // $v0
  int v30; // $s3
  int v31; // $a2
  int v33; // $a1
  int v34; // $a2
  int v35; // $a0
  const char *v36; // $v0
  unsigned int v37; // $v0
  char v38[1024]; // [sp+20h] [-450h] BYREF
  int v39[8]; // [sp+420h] [-50h] BYREF
  int v40[8]; // [sp+440h] [-30h] BYREF
  int v41; // [sp+460h] [-10h]
  void *v42; // [sp+464h] [-Ch]
  void *ptr; // [sp+468h] [-8h]

  v40[0] = 0;
  v40[1] = 0;
  v40[2] = 0;
  v40[3] = 0;
  v40[4] = 0;
  v40[5] = 0;
  v40[6] = 0;
  v40[7] = 0;
  v39[0] = 0;
  v39[1] = 0;
  v39[2] = 0;
  v39[3] = 0;
  v39[4] = 0;
  v39[5] = 0;
  v39[6] = 0;
  v39[7] = 0;
  v3 = httpd_get_parm(a1, "type");
  v2 = httpd_get_parm(a1, "iface");
  if ( !v3 || (v4 = v2, strcmp(v3, "m")) && strcmp(v3, "h") && strcmp(v3, "d") )
  {
    v33 = *(unsigned __int8 *)(a1 + 210102);
    v34 = (int)&unk_64334C;
    v35 = 12;
    goto LABEL_39;
  }
  if ( !v4 )
  {
    v33 = *(unsigned __int8 *)(a1 + 210102);
    v34 = (int)&unk_643358;
    v35 = 12;
    goto LABEL_39;
  }
  if ( !strcmp(v4, "all") )
  {
    sprintf((char *)v40, "wan_flow_a_%s_l", v3);
    sprintf((char *)v39, "wan_flow_a_%s_t", v3);
    v7 = (char *)nvram_get(v40);
    if ( !v7 )
      v7 = "";
    v10 = (char *)nvram_get(v39);
    if ( v10 )
      goto LABEL_10;
  }
  else
  {
    sprintf((char *)v40, "wan_flow_%s_l", v3);
    sprintf((char *)v39, "wan_flow_%s_t", v3);
    v5 = J_atoi(v4);
    v6 = jhl_nvget(v40, v5);
    v7 = (char *)nvram_get(v6);
    if ( !v7 )
      v7 = "";
    v8 = J_atoi(v4);
    v9 = jhl_nvget(v39, v8);
    v10 = (char *)nvram_get(v9);
    if ( v10 )
      goto LABEL_10;
  }
  v10 = "";
LABEL_10:
  _mem_malloc(102400, "wanll_history_data", 471);
  v12 = v11;
  if ( v11 )
  {
    strcpy(v11, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v11, "{\"code\":0,\"error\":\"\"", 20);
    v13 = J_atoi(v10);
    v14 = snprintf(v12 + 29, 102371, "\"time\":%lu,\"all\":", v13);
    if ( v14 >= 102371 )
      v14 = 102370;
    v15 = v14 + 29;
    v16 = 102400 - (v14 + 29);
    v17 = &v12[v14 + 29];
    v18 = snprintf(v17, v16, (char *)&word_642A04);
    if ( v18 >= v16 )
      v18 = 102399 - v15;
    v19 = (const char **)malloc(0x10u);
    v42 = malloc(0x808u);
    v21 = v42;
    v20 = malloc(0x200000u);
    ptr = v20;
    if ( v20 )
    {
      if ( v19 )
      {
        v42 = v21;
        if ( v21 )
        {
          v22 = v20;
          strlcpy(v20, v7, 0x200000);
          v23 = v42;
          v41 = split_string(v22, 60, v42, 512);
          if ( v41 > 0 )
          {
            for ( i = 0; i != v41; ++i )
            {
              v25 = split_string(*v23, 124, v19, 2);
              format_wanll_history_data(v19, v25, &v17[v18], v16 - v18);
              v18 += v26;
              ++v23;
            }
          }
        }
      }
      free(ptr);
    }
    if ( v19 )
      free(v19);
    if ( v42 )
      free(v42);
    v27 = &v17[v18];
    if ( v18 > 0 && *(v27 - 1) == 44 )
      v27 = &v17[--v18];
    v28 = v16 - v18;
    *v27 = 0;
    v29 = snprintf(v27, v28, &byte_6445A0);
    if ( v29 >= v28 )
      v29 = v28 - 1;
    v30 = v18 + v29 + v15;
    v31 = snprintf(&v12[v30], 102400 - v30, "}}");
    if ( v31 >= 102400 - v30 )
      v31 = 102399 - v30;
    return httpd_cgi_ret(a1, v12, v31 + v30, 8);
  }
  v33 = *(unsigned __int8 *)(a1 + 210102);
  v34 = 102400;
  v35 = 4;
LABEL_39:
  v36 = (const char *)_GET_LANG_TEXT(v35, v33, v34);
  v37 = snprintf(v38, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v36);
  if ( v37 >= 0x400 )
    v37 = 1023;
  return httpd_cgi_ret(a1, v38, v37, 4);
}
// 4415F4: variable 'v11' is possibly undefined
// 4417CC: variable 'v26' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A890C: using guessed type int __fastcall jhl_nvget(_DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

