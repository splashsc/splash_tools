int __fastcall sub_49A7E4(int a1)
{
  int v1; // $v0
  char *v2; // $fp
  const char *v3; // $v0
  int v4; // $v0
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
  int v22; // $s0
  int v23; // $v0
  int v24; // $s0
  int v25; // $v0
  int v26; // $s0
  int v27; // $v0
  int v28; // $a2
  int result; // $v0
  const char *v30; // $v0
  unsigned int v31; // $v0
  char v32[256]; // [sp+20h] [-108h] BYREF
  _DWORD *v33; // [sp+120h] [-8h]
  void *ptr; // [sp+124h] [-4h]

  _mem_malloc(0x200000, "pppoe_br_more_data", 946);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    v3 = (const char *)jhl_nv_get_def("pppoe_br_more_enable");
    v4 = snprintf(v2 + 29, 2097123, "\"enable\":\"%s\",\"all\":", v3);
    if ( v4 >= 2097123 )
      v4 = 2097122;
    v5 = v4 + 29;
    v6 = 0x200000 - (v4 + 29);
    v7 = &v2[v4 + 29];
    v8 = nvram_get("pppoe_br_all");
    v9 = snprintf(&v2[v5], 0x200000 - v5, (char *)&word_642A04);
    if ( v9 >= 0x200000 - v5 )
      v9 = 0x1FFFFF - v5;
    if ( v8 )
    {
      v10 = (const char **)malloc(0x14u);
      v33 = malloc(0x4008u);
      v12 = v33;
      v11 = malloc(0x200000u);
      ptr = v11;
      if ( v11 )
      {
        if ( v10 )
        {
          v13 = v8;
          if ( v33 )
          {
            v14 = v11;
            strlcpy(v11, v13, 0x200000);
            v15 = split_string(v14, 60, v33, 4096);
            if ( v15 > 0 )
            {
              for ( i = 0; i != v15; ++i )
              {
                v17 = split_string(*v12, 124, v10, 3);
                format_pppoe_br_more_data(v10, v17, &v7[v9], v6 - v9);
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
      if ( v33 )
        free(v33);
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
    v23 = snprintf(&v2[v22], 0x200000 - v22, (char *)&dword_6448E0);
    if ( v23 >= 0x200000 - v22 )
      v23 = 0x1FFFFF - v22;
    v24 = v23 + v22 + get_wans_pppoebr_data(&v2[v23 + v22], 0x200000 - (v23 + v22));
    v25 = snprintf(&v2[v24], 0x200000 - v24, ",\"real_wans\":");
    if ( v25 >= 0x200000 - v24 )
      v25 = 0x1FFFFF - v24;
    v26 = v25 + v24 + get_realwans_data(1, &v2[v25 + v24], 0x200000 - (v25 + v24));
    v27 = snprintf(&v2[v26], 0x200000 - v26, "}}");
    if ( v27 >= 0x200000 - v26 )
      v28 = 0x1FFFFF - v26;
    else
      v28 = v27;
    result = httpd_cgi_ret(a1, v2, v28 + v26, 8);
  }
  else
  {
    v30 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v31 = snprintf(v32, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v30);
    if ( v31 >= 0x100 )
      v31 = 255;
    result = httpd_cgi_ret(a1, v32, v31, 4);
  }
  return result;
}
// 49A844: variable 'v1' is possibly undefined
// 49AA34: variable 'v18' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6448E0: using guessed type int dword_6448E0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85B4: using guessed type int __fastcall get_realwans_data(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

