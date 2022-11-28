int __fastcall sub_4A6B9C(int a1)
{
  int v1; // $v0
  char *v2; // $fp
  int v3; // $v0
  char *v4; // $a0
  int v5; // $s3
  int v6; // $s1
  char *v7; // $s4
  int v8; // $s5
  int v9; // $s0
  const char **v10; // $s2
  void *v11; // $v0
  _DWORD *v12; // $s6
  int v13; // $a1
  void *v14; // $s5
  int v15; // $s5
  int i; // $s7
  int v17; // $v0
  int v18; // $v0
  char *v19; // $a0
  int v20; // $s1
  int v21; // $v0
  int v22; // $s3
  int v23; // $v0
  int v24; // $a2
  int result; // $v0
  const char *v26; // $v0
  unsigned int v27; // $v0
  char v28[256]; // [sp+20h] [-108h] BYREF
  _DWORD *v29; // [sp+120h] [-8h]
  void *ptr; // [sp+124h] [-4h]

  _mem_malloc(102400, "menu_nat_data", 931);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{\"wans\":");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    strcpy((char *)(v1 + 32), "ns\":");
    v3 = get_wans_data((char *)(v1 + 36), 102364);
    v4 = &v2[v3 + 36];
    strcpy(v4, ",\"nat_list_onebyone\":");
    qmemcpy(v4, ",\"nat_list_oneby", 16);
    v5 = v3 + 57;
    v6 = 102400 - (v3 + 57);
    v7 = &v2[v3 + 57];
    v8 = nvram_get("nat_list_onebyone");
    v9 = snprintf(&v2[v5], 102400 - v5, (char *)&word_642A04);
    if ( v9 >= 102400 - v5 )
      v9 = 102399 - v5;
    if ( v8 )
    {
      v10 = (const char **)malloc(0x24u);
      v29 = malloc(0x4008u);
      v12 = v29;
      v11 = malloc(0x200000u);
      ptr = v11;
      if ( v11 )
      {
        if ( v10 )
        {
          v13 = v8;
          if ( v29 )
          {
            v14 = v11;
            strlcpy(v11, v13, 0x200000);
            v15 = split_string(v14, 60, v29, 4096);
            if ( v15 > 0 )
            {
              for ( i = 0; i != v15; ++i )
              {
                v17 = split_string(*v12, 124, v10, 7);
                format_menu_nat_data(v10, v17, &v7[v9], v6 - v9);
                v9 += v18;
                ++v12;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v10 )
        free(v10);
      if ( v29 )
        free(v29);
    }
    v19 = &v7[v9];
    if ( v9 > 0 && *(v19 - 1) == 44 )
      v19 = &v7[--v9];
    v20 = v6 - v9;
    *v19 = 0;
    v21 = snprintf(v19, v20, &byte_6445A0);
    if ( v21 >= v20 )
      v21 = v20 - 1;
    v22 = v9 + v21 + v5;
    v23 = snprintf(&v2[v22], 102400 - v22, "}}");
    if ( v23 >= 102400 - v22 )
      v24 = 102399 - v22;
    else
      v24 = v23;
    result = httpd_cgi_ret(a1, v2, v24 + v22, 8);
  }
  else
  {
    v26 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v27 = snprintf(v28, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v26);
    if ( v27 >= 0x100 )
      v27 = 255;
    result = httpd_cgi_ret(a1, v28, v27, 4);
  }
  return result;
}
// 4A6C00: variable 'v1' is possibly undefined
// 4A6E34: variable 'v18' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

