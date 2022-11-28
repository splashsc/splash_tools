int __fastcall spqos_cgi(const char *a1, int a2)
{
  int v2; // $s1
  int v3; // $s3
  char *v4; // $v0
  char *v5; // $s0
  char *v6; // $v0
  char *v7; // $s1
  char *v8; // $v0
  int v9; // $a1
  int v10; // $v1
  _BOOL4 v11; // $a2
  size_t v12; // $s1
  const char *v13; // $v0
  unsigned int v14; // $v0
  unsigned int v15; // $a2
  _DWORD *v17; // $s3
  int v18; // $s5
  int v19; // $s0
  const char **v20; // $s6
  int v21; // $fp
  int i; // $s7
  int v23; // $s0
  int v24; // $a0
  int v25; // $a2
  const char *v26; // $v0
  char v27[102400]; // [sp+20h] [-36630h] BYREF
  char v28[94208]; // [sp+19020h] [-1D630h] BYREF
  int v29; // [sp+30020h] [-6630h] BYREF
  char v30[10240]; // [sp+32020h] [-4630h] BYREF
  char v31[5120]; // [sp+34820h] [-1E30h] BYREF
  _BYTE v32[2048]; // [sp+35C20h] [-A30h] BYREF
  int v33; // [sp+36420h] [-230h] BYREF
  _DWORD v34[4]; // [sp+36620h] [-30h] BYREF
  const char **v35; // [sp+36630h] [-20h]
  int v36; // [sp+36634h] [-1Ch]
  char *v37; // [sp+36638h] [-18h]
  int v38; // [sp+3663Ch] [-14h]
  int v39; // [sp+36640h] [-10h]
  int *v40; // [sp+36644h] [-Ch]
  int v41; // [sp+36648h] [-8h]
  char **v42; // [sp+3664Ch] [-4h]

  v34[0] = 0;
  v34[1] = 0;
  v34[2] = 0;
  v34[3] = 0;
  v2 = a2 + 196608;
  v39 = get_rule_num_limit(7);
  snprintf((char *)v34, 16, "sqos_%s", a1);
  v3 = *(_DWORD *)(a2 + 205364);
  find_file_head(a2, *(const char **)(a2 + 205564));
  if ( !v4 )
    goto LABEL_12;
  v5 = v4;
  v6 = find_file_end(a2, v4, *(_DWORD *)(v2 + 8956) + v3 - (_DWORD)v4);
  v7 = v6;
  if ( !v6 )
    goto LABEL_12;
  *v6 = 0;
  jhl_parm_get(v34, v27, 102400);
  if ( !strcmp(v27, " ") )
    v27[0] = 0;
  if ( v7 - v5 <= 0 )
  {
    v9 = 0;
  }
  else
  {
    v8 = v5;
    v9 = 0;
    do
    {
      v10 = *v8++;
      v11 = v9 + 1 < 102399;
      if ( v10 != 13 && v10 != 10 )
      {
        v28[v9++] = v10;
        if ( !v11 )
          break;
      }
    }
    while ( v7 != v8 );
  }
  v28[v9] = 0;
  v12 = strlen(a1);
  if ( strncmp(v28, a1, v12) )
  {
LABEL_12:
    v13 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a2 + 210102), "Error reading file");
    v14 = snprintf(v31, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    if ( v14 < 0x1400 )
    {
LABEL_13:
      v15 = v14;
      return httpd_cgi_ret(a2, v31, v15, 4);
    }
LABEL_24:
    v14 = 5119;
    goto LABEL_13;
  }
  v17 = v32;
  v36 = split_string(&v28[v12], 60, v32, 512);
  if ( v36 > 0 )
  {
    v41 = 0;
    v37 = v31;
    v35 = (const char **)&v33;
    v40 = &v29;
    v18 = 0;
    v42 = &off_646D8C;
    do
    {
      strlcpy(v37, *v17, 5120);
      v19 = split_string(*v17, 124, v35, 128);
      if ( v19 >= 10 )
      {
        v38 = v40[6400];
        if ( !nvparm_find_str(v27, 60, 19, v38, 124, 0) )
        {
          v20 = v35;
          set_qos_to_kernel(a1, v42, v35);
          v21 = 0;
          for ( i = 0; i != v19; ++i )
            v21 += sprintf(&v30[v21], "%s|", *v20++);
          *(_WORD *)&v30[v21 - 1] = 60;
          v23 = ++v41;
          strcat(v27, v30);
          if ( v23 >= v39 )
            break;
        }
      }
      ++v18;
      ++v17;
    }
    while ( v36 != v18 );
  }
  jhl_parm_set(v34, v27);
  jhl_parm_commit(v24);
  v26 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a2 + 210102), v25);
  v15 = snprintf(v31, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v26);
  if ( v15 >= 0x1400 )
    goto LABEL_24;
  return httpd_cgi_ret(a2, v31, v15, 4);
}
// 457984: variable 'v4' is possibly undefined
// 457E3C: variable 'v24' is possibly undefined
// 457E6C: variable 'v25' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A85DC: using guessed type int __fastcall set_qos_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

