int __fastcall sub_46C654(int a1)
{
  int v1; // $s1
  int v2; // $s2
  char *v3; // $v0
  char *v4; // $s0
  char *v5; // $s1
  char *v6; // $v0
  int v7; // $a1
  int v8; // $v1
  _BOOL4 v9; // $a2
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
  char v27[215040]; // [sp+20h] [-36618h] BYREF
  char v28[7680]; // [sp+34820h] [-1E18h] BYREF
  int v29; // [sp+36620h] [-18h]
  char *v30; // [sp+36624h] [-14h]
  char *v31; // [sp+36628h] [-10h]
  char **v32; // [sp+3662Ch] [-Ch]
  char *v33; // [sp+36630h] [-8h]
  char *v34; // [sp+36634h] [-4h]

  v1 = a1 + 196608;
  v2 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  v4 = v3;
  if ( v3 && (v5 = find_file_end(a1, v3, *(_DWORD *)(v1 + 8956) + v2 - (_DWORD)v3)) != 0 )
  {
    v34 = "a";
    v31 = v27;
    *v5 = 0;
    jhl_parm_get("accAll2", v27, 102400);
    if ( v5 - v4 <= 0 )
    {
      v7 = 0;
    }
    else
    {
      v6 = v4;
      v7 = 0;
      do
      {
        v8 = *v6++;
        v9 = v7 + 1 < 102399;
        if ( v8 != 13 && v8 != 10 )
        {
          v27[v7++ + 102400] = v8;
          if ( !v9 )
            break;
        }
      }
      while ( v5 != v6 );
    }
    v10 = v31;
    v11 = v31 + 220160;
    v31[v7 + 102400] = 0;
    v29 = split_string(v10 + 102400, 60, v11, 512);
    if ( v29 > 0 )
    {
      v33 = "a";
      v30 = v31 + 215040;
      v12 = v31 + 222208;
      v13 = 0;
      v32 = &off_646D8C;
      do
      {
        while ( 1 )
        {
          strlcpy(v30, *(_DWORD *)v11, 5120);
          v14 = split_string(*(_DWORD *)v11, 124, v12, 128);
          if ( v14 >= 10 && !nvparm_find_str(v31, 60, 15, *((_DWORD *)v31 + 55552), 124, 0) )
            break;
          ++v13;
          v11 += 4;
          if ( v29 == v13 )
            goto LABEL_17;
        }
        set_rule_to_kernel(v33 + 19092, v32, v12);
        v15 = (const char **)v12;
        v16 = 0;
        v17 = 0;
        v18 = v31 + 204800;
        do
        {
          ++v17;
          v16 += sprintf(&v18[v16], "%s|", *v15++);
        }
        while ( v14 != v17 );
        *(_WORD *)&v18[v16 - 1] = 60;
        strcat(v31, v18);
        ++v13;
        v11 += 4;
      }
      while ( v29 != v13 );
    }
LABEL_17:
    v19 = v31;
    jhl_parm_set(v34 + 29056, v31);
    jhl_parm_commit(v20);
    v22 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v21);
    v23 = snprintf(v19 + 215040, 5120, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v22);
    if ( v23 < 0x1400 )
      goto LABEL_18;
  }
  else
  {
    v26 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
    v31 = v27;
    v24 = snprintf(v28, 5120, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v26);
    if ( v24 < 0x1400 )
      return httpd_cgi_ret(a1, v31 + 215040, v24, 4);
  }
  v23 = 5119;
LABEL_18:
  v24 = v23;
  return httpd_cgi_ret(a1, v31 + 215040, v24, 4);
}
// 46C6D4: variable 'v3' is possibly undefined
// 46CA40: variable 'v20' is possibly undefined
// 46CA70: variable 'v21' is possibly undefined
// 646D8C: using guessed type char *off_646D8C;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A81F4: using guessed type int __fastcall nvparm_find_str(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A832C: using guessed type int __fastcall set_rule_to_kernel(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8600: using guessed type int __fastcall jhl_parm_get(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

