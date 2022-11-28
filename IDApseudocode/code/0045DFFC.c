int __fastcall sub_45DFFC(int a1)
{
  int v2; // $v0
  int v3; // $s2
  char *v4; // $v0
  int v5; // $s4
  char *v6; // $v0
  char *v7; // $fp
  int v8; // $s3
  char *v9; // $a3
  char *v10; // $v1
  int v11; // $v0
  int v12; // $v0
  bool v13; // dc
  int v14; // $v0
  char *v15; // $t4
  char *v16; // $t5
  const char *v17; // $a0
  int v18; // $t2
  int v19; // $t1
  int v20; // $a3
  int v21; // $a2
  char *i; // $v0
  int v23; // $v1
  char *v24; // $v0
  int v25; // $v0
  void *v26; // $v0
  void *v27; // $s2
  int v28; // $a0
  int v29; // $a2
  const char *v30; // $v0
  unsigned int v31; // $v0
  int v33; // $a1
  int v34; // $a2
  int v35; // $a0
  const char *v36; // $v0
  char v37[1024]; // [sp+20h] [-890h] BYREF
  char v38[1024]; // [sp+420h] [-490h] BYREF
  char v39[120]; // [sp+820h] [-90h] BYREF
  char *v40; // [sp+898h] [-18h]
  char *v41; // [sp+89Ch] [-14h]
  int v42; // [sp+8A0h] [-10h]
  int v43; // [sp+8A4h] [-Ch]
  int v44; // [sp+8A8h] [-8h]
  int v45; // [sp+8ACh] [-4h]

  v2 = get_rule_num_limit(9);
  v3 = *(_DWORD *)(a1 + 205364);
  v5 = v2;
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( !v4 )
  {
    if ( debug_level > 0 )
      printf("%s:%d find_file_head err  \n", "arpstsfile_cgi", 483);
    goto LABEL_41;
  }
  v7 = v4;
  v6 = find_file_end(a1, v4, *(_DWORD *)(a1 + 205564) + v3 - (_DWORD)v4);
  v8 = 0;
  if ( !v6 )
  {
    if ( debug_level > 0 )
      printf("%s:%d find_file_end err \n", "arpstsfile_cgi", 490);
LABEL_41:
    v33 = *(unsigned __int8 *)(a1 + 210102);
    v34 = (int)"Error reading file";
    v35 = 33;
    goto LABEL_42;
  }
  *v6 = 0;
  v40 = "only";
  v41 = "a";
  while ( *v7 )
  {
    memset(v37, 0, sizeof(v37));
    v9 = v7 + 1002;
    v10 = v37;
    while ( 1 )
    {
      v11 = *v7;
      if ( !*v7 )
        break;
      if ( v11 == 10 || v11 == 13 )
        goto LABEL_20;
      *v10++ = v11;
      if ( v7 + 1 == v9 )
      {
        v11 = v7[1];
        v7 = v9;
LABEL_20:
        while ( v11 == 10 || v11 == 13 )
          v11 = *++v7;
        break;
      }
      ++v7;
    }
    if ( v37[0] == 123 && *(v10 - 1) == 125 )
    {
      *(v10 - 1) = 0;
      v12 = split_string(&v37[1], 44, v39, 30);
      v13 = v12 <= 0;
      v14 = 4 * v12;
      if ( !v13 )
      {
        v15 = v39;
        v16 = &v39[v14];
        v17 = 0;
        v18 = 0;
        v19 = 0;
        v20 = 0;
        v21 = 0;
        do
        {
          for ( i = *(char **)v15; ; ++i )
          {
            v23 = *i;
            if ( v23 != 32 && v23 != 9 )
              break;
          }
          if ( i[1] == 58 )
          {
            switch ( (char)v23 )
            {
              case 'I':
                v21 = (int)(i + 2);
                break;
              case 'M':
                v20 = (int)(i + 2);
                break;
              case 'd':
                v18 = (int)(i + 2);
                break;
              case 'n':
                v19 = (int)(i + 2);
                break;
              case 't':
                v17 = i + 2;
                break;
              default:
                break;
            }
          }
          v15 += 4;
        }
        while ( v15 != v16 );
        if ( v21 && v20 && v18 )
        {
          if ( !v19 )
            v19 = (int)(v41 + 25836);
          v24 = "1";
          if ( v17 )
          {
            v45 = v19;
            v44 = v20;
            v43 = v21;
            v42 = v18;
            v25 = strcmp(v17, v40);
            v18 = v42;
            v21 = v43;
            v20 = v44;
            v19 = v45;
            v13 = v25 == 0;
            v24 = "2";
            if ( !v13 )
              v24 = "1";
          }
          ++v8;
          arp_st_add(v19, v18, v21, v20, v24);
          if ( v8 >= v5 )
            break;
        }
      }
    }
  }
  _mem_malloc(0x200000, "arpstsfile_cgi", 590);
  v27 = v26;
  if ( !v26 )
  {
    v33 = *(unsigned __int8 *)(a1 + 210102);
    v34 = 0x200000;
    v35 = 4;
LABEL_42:
    v36 = (const char *)_GET_LANG_TEXT(v35, v33, v34);
    v31 = snprintf(v38, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v36);
    if ( v31 < 0x400 )
      return httpd_cgi_ret(a1, v38, v31, 4);
LABEL_43:
    v31 = 1023;
    return httpd_cgi_ret(a1, v38, v31, 4);
  }
  if ( arp_st_get(v26, 0x200000) )
    nvram_set("arp_st", v27);
  else
    nvram_set("arp_st", " ");
  jhl_parm_commit(v28);
  _mem_free(v27);
  v30 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v29);
  v31 = snprintf(v38, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v30);
  if ( v31 >= 0x400 )
    goto LABEL_43;
  return httpd_cgi_ret(a1, v38, v31, 4);
}
// 45E074: variable 'v4' is possibly undefined
// 45E2D4: variable 'v26' is possibly undefined
// 45E320: variable 'v28' is possibly undefined
// 45E358: variable 'v29' is possibly undefined
// 67D0BC: using guessed type int debug_level;
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8288: using guessed type int __fastcall arp_st_add(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A86E0: using guessed type int __fastcall arp_st_get(_DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8918: using guessed type int __fastcall nvram_set(_DWORD, _DWORD);

