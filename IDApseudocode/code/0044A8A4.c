int __fastcall sub_44A8A4(int a1)
{
  int v1; // $v0
  char *v2; // $s0
  _BYTE *v3; // $s4
  int v4; // $s1
  const char **v5; // $s3
  void *v6; // $v0
  _DWORD *v7; // $s7
  int v8; // $a1
  void *v9; // $s1
  int v10; // $s6
  _DWORD *v11; // $fp
  int v12; // $s1
  int i; // $s2
  int v14; // $v0
  int v15; // $v0
  int v16; // $s5
  char *v17; // $a0
  int v18; // $v0
  int v19; // $s1
  int v20; // $v0
  int v21; // $s1
  int v22; // $a2
  const char *v24; // $v0
  unsigned int v25; // $v0
  char v26[1024]; // [sp+20h] [-408h] BYREF
  void *ptr; // [sp+420h] [-8h]

  _mem_malloc(0x200000, "wan_group_data", 5116);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{\"groups\":");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    *(_BYTE *)(v1 + 32) = 111;
    v3 = (_BYTE *)(v1 + 38);
    v4 = nvram_get("wan_groups");
    v2[38] = 91;
    v2[39] = 0;
    if ( v4 )
    {
      v5 = (const char **)malloc(0x10u);
      v7 = malloc(0x4008u);
      v6 = malloc(0x200000u);
      ptr = v6;
      if ( v6 )
      {
        if ( v5 && (v8 = v4, v7) && (v9 = v6, strlcpy(v6, v8, 0x200000), v10 = split_string(v9, 60, v7, 4096), v10 > 0) )
        {
          v11 = v7;
          v12 = 1;
          for ( i = 0; i != v10; ++i )
          {
            v14 = split_string(*v11, 124, v5, 2);
            format_wan_groups_data(v5, v14, &v3[v12], 2097114 - v12);
            v12 += v15;
            ++v11;
          }
          v16 = v12;
        }
        else
        {
          v16 = 1;
          v12 = 1;
        }
        free(ptr);
      }
      else
      {
        v16 = 1;
        v12 = 1;
      }
      if ( v5 )
        free(v5);
      if ( v7 )
        free(v7);
      if ( v12 <= 0 )
      {
        v17 = &v3[v16];
        goto LABEL_17;
      }
      v17 = &v3[v16];
      if ( v3[v16 - 1] != 44 )
      {
LABEL_17:
        *v17 = 0;
        v18 = snprintf(v17, 2097114 - v12, &byte_6445A0);
        if ( v18 >= 2097114 - v12 )
          v18 = 2097113 - v12;
        v19 = v12 + v18 + 38;
        v20 = snprintf(&v2[v19], 0x200000 - v19, (char *)&dword_6448E0);
        if ( v20 >= 0x200000 - v19 )
          v20 = 0x1FFFFF - v19;
        v21 = v20 + v19 + get_wans_data(&v2[v20 + v19], 0x200000 - (v20 + v19));
        v22 = snprintf(&v2[v21], 0x200000 - v21, "}}");
        if ( v22 >= 0x200000 - v21 )
          v22 = 0x1FFFFF - v21;
        return httpd_cgi_ret(a1, v2, v22 + v21, 8);
      }
    }
    else
    {
      v17 = v2 + 39;
      v12 = 1;
      if ( *v3 != 44 )
        goto LABEL_17;
    }
    v17 = &v3[--v12];
    goto LABEL_17;
  }
  v24 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
  v25 = snprintf(v26, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v24);
  if ( v25 >= 0x400 )
    v25 = 1023;
  return httpd_cgi_ret(a1, v26, v25, 4);
}
// 44A904: variable 'v1' is possibly undefined
// 44AAB8: variable 'v15' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6445A0: using guessed type char byte_6445A0;
// 6448E0: using guessed type int dword_6448E0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

