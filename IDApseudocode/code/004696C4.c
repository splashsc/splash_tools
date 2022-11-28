int __fastcall sub_4696C4(int a1)
{
  int v1; // $s5
  char *v2; // $v0
  char *v3; // $s0
  char *v4; // $s3
  char *v5; // $a1
  char *v6; // $v0
  int v7; // $a1
  int v8; // $v1
  _BOOL4 v9; // $a3
  char *v10; // $t0
  char *v11; // $s3
  char *v12; // $s5
  int v13; // $s4
  int v14; // $s0
  const char **v15; // $s7
  int v16; // $fp
  int v17; // $s6
  char *v18; // $s1
  char *v19; // $s1
  int v20; // $a0
  int v21; // $a2
  const char *v22; // $v0
  unsigned int v23; // $v0
  unsigned int v24; // $a2
  const char *v26; // $v0
  char v27[102400]; // [sp+20h] [-36620h] BYREF
  _BYTE v28[102400]; // [sp+19020h] [-1D620h] BYREF
  _BYTE v29[10240]; // [sp+32020h] [-4620h] BYREF
  int v30; // [sp+36620h] [-20h]
  char *v31; // [sp+36624h] [-1Ch]
  int v32; // [sp+36628h] [-18h]
  char *v33; // [sp+3662Ch] [-14h]
  char *v34; // [sp+36630h] [-10h]
  char **v35; // [sp+36634h] [-Ch]
  char *v36; // [sp+36638h] [-8h]

  v33 = v27;
  memset(v28, 0, sizeof(v28));
  memset(v27, 0, sizeof(v27));
  memset(v29, 0, sizeof(v29));
  v1 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( v2 )
  {
    v3 = v2;
    v4 = find_file_end(a1, v2, *(_DWORD *)(a1 + 205564) + v1 - (_DWORD)v2);
    if ( v4 )
    {
      v36 = "a";
      v5 = v33;
      *v4 = 0;
      jhl_parm_get("xwgl_all", v5, 102400);
      v6 = v3;
      if ( v4 - v3 <= 0 )
      {
        v7 = 0;
      }
      else
      {
        v7 = 0;
        do
        {
          v8 = *v6++;
          v9 = v7 + 1 < 102399;
          if ( v8 != 13 && v8 != 10 )
          {
            v28[v7++] = v8;
            if ( !v9 )
              break;
          }
        }
        while ( v4 != v6 );
      }
      v10 = v33;
      v11 = v33 + 220160;
      v33[v7 + 102400] = 0;
      v30 = split_string(v10 + 102400, 60, v11, 512);
      if ( v30 > 0 )
      {
        v31 = v33 + 215040;
        v12 = v33 + 222208;
        v34 = v33 + 196608;
        v13 = 0;
        v35 = &off_646D8C;
        do
        {
          while ( 1 )
          {
            strlcpy(v31, *(_DWORD *)v11, 5120);
            v14 = split_string(*(_DWORD *)v11, 124, v12, 128);
            if ( v14 >= 6 )
            {
              v32 = *((_DWORD *)v34 + 6400);
              if ( !nvparm_find_str(v33, 60, 9, v32, 124, 0) )
                break;
            }
            ++v13;
            v11 += 4;
            if ( v30 == v13 )
              goto LABEL_17;
          }
          set_xwgl_ref_to_kernel(v35, v12);
          v15 = (const char **)v12;
          v16 = 0;
          v17 = 0;
          v18 = v33 + 204800;
          do
          {
            ++v17;
            v16 += sprintf(&v18[v16], "%s|", *v15++);
          }
          while ( v14 != v17 );
          *(_WORD *)&v18[v16 - 1] = 60;
          strcat(v33, v18);
          ++v13;
          v11 += 4;
        }
        while ( v30 != v13 );
      }
LABEL_17:
      v19 = v33;
      jhl_parm_set(v36 + 27928, v33);
      jhl_parm_commit(v20);
      v22 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v21);
      v23 = snprintf(v19 + 215040, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v22);
      if ( v23 < 0x1400 )
        goto LABEL_18;
      goto LABEL_23;
    }
    if ( debug_level > 0 )
      printf("%s:%d find_file_end err \n", "xwgl_ref_cgi", 2071);
  }
  else if ( debug_level > 0 )
  {
    printf("%s:%d find_file_head err  \n", "xwgl_ref_cgi", 2064);
  }
  v26 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
  v24 = snprintf(v33 + 215040, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v26);
  if ( v24 < 0x1400 )
    return httpd_cgi_ret(a1, v33 + 215040, v24, 4);
LABEL_23:
  v23 = 5119;
LABEL_18:
  v24 = v23;
  return httpd_cgi_ret(a1, v33 + 215040, v24, 4);
}
// 4697D4: variable 'v2' is possibly undefined
// 469B34: variable 'v20' is possibly undefined
// 469B64: variable 'v21' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 67D0BC: using guessed type int debug_level;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A86A4: using guessed type int __fastcall set_xwgl_ref_to_kernel(_DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

