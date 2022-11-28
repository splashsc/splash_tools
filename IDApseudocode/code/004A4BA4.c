int __fastcall sub_4A4BA4(int a1)
{
  int v2; // $s6
  void *v3; // $v0
  void *v4; // $s3
  void *v5; // $v0
  void *v6; // $s1
  char *v7; // $v0
  char *v8; // $v0
  char *v9; // $s4
  char *v10; // $v0
  char *v11; // $s7
  char *v12; // $s0
  char *v13; // $v0
  int v14; // $a0
  int v15; // $v1
  _BOOL4 v16; // $a2
  char *v17; // $s0
  int v18; // $s6
  int v19; // $s7
  int v20; // $v0
  char *v21; // $v0
  int v22; // $a0
  const char *v23; // $s0
  int v24; // $a1
  const char *v25; // $v0
  unsigned int v26; // $v0
  const char *v28; // $v0
  char v29[5120]; // [sp+20h] [-2440h] BYREF
  char v30[4096]; // [sp+1420h] [-1040h] BYREF
  char v31[24]; // [sp+2420h] [-40h] BYREF
  int v32; // [sp+2438h] [-28h]
  char *src; // [sp+2448h] [-18h]
  int v34; // [sp+244Ch] [-14h]
  int v35; // [sp+2450h] [-10h]
  int v36; // [sp+2454h] [-Ch]
  char *format; // [sp+2458h] [-8h]
  char *v38; // [sp+245Ch] [-4h]

  v34 = get_rule_num_limit(27);
  v2 = *(_DWORD *)(a1 + 205364);
  _mem_malloc(0x200000, "nat_base_cgi", 361);
  v4 = v3;
  _mem_malloc(0x100000, "nat_base_cgi", 362);
  v6 = v5;
  _mem_malloc(0x200000, "nat_base_cgi", 363);
  v9 = v8;
  _mem_malloc(0x200000, "nat_base_cgi", 364);
  src = v7;
  if ( !v4 )
  {
    v23 = "mem_malloc failed";
    goto LABEL_23;
  }
  if ( !v6 || !v9 || !v7 )
  {
    v23 = "mem_malloc failed";
LABEL_33:
    _mem_free(v4);
    goto LABEL_23;
  }
  find_file_head(a1, *(const char **)(a1 + 205564));
  v11 = v10;
  if ( !v10 || (v12 = find_file_end(a1, v10, *(_DWORD *)(a1 + 205564) + v2 - (_DWORD)v10)) == 0 )
  {
    v23 = "Error reading file";
    goto LABEL_33;
  }
  v38 = "a";
  *v12 = 0;
  jhl_parm_get("portforward", v9, 0x200000);
  if ( v12 - v11 <= 0 )
  {
    v14 = 0;
  }
  else
  {
    v13 = v11;
    v14 = 0;
    do
    {
      v15 = *v13++;
      v16 = v14 + 1 < 0x1FFFFF;
      if ( v15 != 13 && v15 != 10 )
      {
        *((_BYTE *)v4 + v14++) = v15;
        if ( !v16 )
          break;
      }
    }
    while ( v12 != v13 );
  }
  v17 = v30;
  *((_BYTE *)v4 + v14) = 0;
  v18 = split_string(v4, 62, v30, 1024);
  if ( v18 > 0 )
  {
    v36 = 0;
    v35 = 0;
    v19 = 0;
    format = "%s>";
    do
    {
      memset(v6, 0, 0x100000u);
      strlcpy(v6, *(_DWORD *)v17, 0x100000);
      ++v19;
      if ( split_string(*(_DWORD *)v17, 60, v31, 8) >= 7 && !nvparm_find_str_too_loog(v9, 62, 9, v32, 60, 6) )
      {
        ++v36;
        v20 = sprintf(&src[v35], format, v6);
        v35 += v20;
        if ( v36 >= v34 )
          break;
      }
      v17 += 4;
    }
    while ( v18 != v19 );
  }
  if ( *v9 )
  {
    v21 = &v9[strlen(v9)];
    if ( *(v21 - 1) != 62 )
      *(_WORD *)v21 = 62;
  }
  strcat(v9, src);
  jhl_parm_set(v38 + 7376, v9);
  v23 = 0;
  jhl_parm_commit(v22);
  jhl_start_firewall();
  _mem_free(v4);
LABEL_23:
  if ( v9 )
    _mem_free(v9);
  if ( v6 )
    _mem_free(v6);
  if ( src )
    _mem_free(src);
  v24 = *(unsigned __int8 *)(a1 + 210102);
  if ( !v23 )
  {
    v28 = (const char *)_GET_LANG_TEXT(34, v24, 0);
    v26 = snprintf(v29, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v28);
    if ( v26 < 0x1400 )
      return httpd_cgi_ret(a1, v29, v26, 4);
LABEL_35:
    v26 = 5119;
    return httpd_cgi_ret(a1, v29, v26, 4);
  }
  v25 = (const char *)_GET_LANG_TEXT(33, v24, v23);
  v26 = snprintf(v29, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v25);
  if ( v26 >= 0x1400 )
    goto LABEL_35;
  return httpd_cgi_ret(a1, v29, v26, 4);
}
// 4A4C34: variable 'v3' is possibly undefined
// 4A4C50: variable 'v5' is possibly undefined
// 4A4C6C: variable 'v8' is possibly undefined
// 4A4C70: variable 'v7' is possibly undefined
// 4A4CB0: variable 'v10' is possibly undefined
// 4A4EF8: variable 'v22' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A858C: using guessed type int jhl_start_firewall(void);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A865C: using guessed type int __fastcall nvparm_find_str_too_loog(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

