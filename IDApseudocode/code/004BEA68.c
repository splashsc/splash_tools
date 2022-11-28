int __fastcall sub_4BEA68(int a1)
{
  _BYTE *v1; // $v0
  _BYTE *v2; // $s3
  char *v3; // $v0
  char *v4; // $v0
  char *v5; // $s0
  char *v6; // $s1
  int v7; // $s4
  char *v8; // $v0
  char *v9; // $s0
  char *v10; // $s3
  char *v11; // $s4
  char *v12; // $a1
  char *v13; // $v0
  int v14; // $a0
  int v15; // $v1
  _BOOL4 v16; // $a2
  _BYTE *v17; // $v0
  char *v18; // $s3
  int v19; // $s4
  int v20; // $s0
  const char **v21; // $s5
  int v22; // $fp
  int i; // $s6
  int v24; // $s0
  char *v25; // $s3
  int v26; // $a0
  int v27; // $a2
  const char *v28; // $v0
  unsigned int v29; // $s0
  int v30; // $a2
  int result; // $v0
  const char *v32; // $v0
  unsigned int v33; // $s0
  int v34; // $a2
  const char *v35; // $v0
  unsigned int v36; // $v0
  char v37[5120]; // [sp+20h] [-1E28h] BYREF
  char v38[2048]; // [sp+1420h] [-A28h] BYREF
  int v39[128]; // [sp+1C20h] [-228h] BYREF
  char *s; // [sp+1E20h] [-28h]
  _BYTE *v41; // [sp+1E24h] [-24h]
  int v42; // [sp+1E28h] [-20h]
  char *dest; // [sp+1E2Ch] [-1Ch]
  int v44; // [sp+1E30h] [-18h]
  char *v45; // [sp+1E34h] [-14h]
  int v46; // [sp+1E38h] [-10h]
  char **v47; // [sp+1E3Ch] [-Ch]
  char *v48; // [sp+1E40h] [-8h]
  char *v49; // [sp+1E44h] [-4h]

  v45 = "1\"";
  v46 = get_rule_num_limit(2);
  _mem_malloc(102400, "mrprot_cgi", 639);
  v41 = v1;
  v2 = v1;
  _mem_malloc(102400, "mrprot_cgi", 640);
  dest = v3;
  v5 = v3;
  _mem_malloc(102400, "mrprot_cgi", 641);
  v6 = v4;
  if ( v2 && v5 && v4 )
  {
    v7 = *(_DWORD *)(a1 + 205364);
    find_file_head(a1, *(const char **)(a1 + 205564));
    v9 = v8;
    if ( v8 && (v10 = find_file_end(a1, v8, *(_DWORD *)(a1 + 205564) + v7 - (_DWORD)v8)) != 0 )
    {
      v11 = dest;
      v12 = dest;
      v49 = "a";
      *v10 = 0;
      jhl_parm_get("mrprot2", v12, 102400);
      if ( !strcmp(v11, " ") )
        *v11 = 0;
      if ( v10 - v9 <= 0 )
      {
        v14 = 0;
      }
      else
      {
        v13 = v9;
        v14 = 0;
        do
        {
          v15 = *v13++;
          v16 = v14 + 1 < 102399;
          if ( v15 != 13 && v15 != 10 )
          {
            v41[v14++] = v15;
            if ( !v16 )
              break;
          }
        }
        while ( v10 != v13 );
      }
      v17 = v41;
      v18 = v38;
      v41[v14] = 0;
      v42 = split_string(v17, 60, v38, 512);
      v19 = 0;
      if ( v42 <= 0 )
      {
        s = v37;
      }
      else
      {
        v48 = "1\"";
        s = v37;
        v44 = 0;
        v47 = &off_646D8C;
        do
        {
          strlcpy(s, *(_DWORD *)v18, 5120);
          v20 = split_string(*(_DWORD *)v18, 124, v39, 128);
          if ( v20 >= 10 )
          {
            v21 = (const char **)v39;
            if ( !nvparm_find_str(dest, 60, 18, v39[0], 124, 0) )
            {
              v22 = 0;
              for ( i = 0; i != v20; ++i )
                v22 += sprintf(&v6[v22], "%s|", *v21++);
              set_rule_to_kernel(v48 - 424, v47, v39);
              *(_WORD *)&v6[v22 - 1] = 60;
              v24 = ++v44;
              strcat(dest, v6);
              if ( v24 >= v46 )
                break;
            }
          }
          ++v19;
          v18 += 4;
        }
        while ( v42 != v19 );
      }
      v25 = dest;
      jhl_parm_set(v49 + 27920, dest);
      jhl_parm_commit(v26);
      v28 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v27);
      v29 = snprintf(s, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v28);
      _mem_free(v41);
      _mem_free(v25);
      _mem_free(v6);
      v30 = v29;
      if ( v29 >= 0x1400 )
        v30 = 5119;
      httpd_cgi_ret(a1, s, v30, 4);
      result = 0;
    }
    else
    {
      v32 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
      s = v37;
      v33 = snprintf(v37, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v32);
      _mem_free(v41);
      _mem_free(dest);
      _mem_free(v6);
      v34 = v33;
      if ( v33 >= 0x1400 )
        v34 = 5119;
      httpd_cgi_ret(a1, s, v34, 4);
      result = -1;
    }
  }
  else
  {
    _mem_free(v41);
    _mem_free(dest);
    _mem_free(v6);
    v35 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    s = v37;
    v36 = snprintf(v37, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v35);
    if ( v36 >= 0x1400 )
      v36 = 5119;
    result = httpd_cgi_ret(a1, s, v36, 4);
  }
  return result;
}
// 4BEAF4: variable 'v1' is possibly undefined
// 4BEB14: variable 'v3' is possibly undefined
// 4BEB28: variable 'v4' is possibly undefined
// 4BEB68: variable 'v8' is possibly undefined
// 4BEDD8: variable 'v26' is possibly undefined
// 4BEDFC: variable 'v27' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A832C: using guessed type int __fastcall set_rule_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

