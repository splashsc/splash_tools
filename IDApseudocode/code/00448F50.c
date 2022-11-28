int __fastcall sub_448F50(int a1)
{
  int v1; // $v0
  char *v2; // $fp
  const char *v3; // $s1
  const char *v4; // $v0
  int v5; // $v0
  int v6; // $s3
  int v7; // $s1
  char *v8; // $s4
  int v9; // $s5
  int v10; // $s0
  const char **v11; // $s2
  void *v12; // $v0
  _DWORD *v13; // $s6
  int v14; // $a1
  void *v15; // $s5
  int v16; // $s5
  int i; // $s7
  int v18; // $v0
  int v19; // $v0
  char *v20; // $a0
  int v21; // $s1
  int v22; // $v0
  int v23; // $s0
  int v24; // $v0
  int v25; // $s0
  int v26; // $v0
  int v27; // $s0
  int v28; // $v0
  int v29; // $s0
  int v30; // $v0
  int v31; // $a2
  int result; // $v0
  const char *v33; // $v0
  unsigned int v34; // $v0
  char v35[256]; // [sp+20h] [-108h] BYREF
  _DWORD *v36; // [sp+120h] [-8h]
  void *ptr; // [sp+124h] [-4h]

  _mem_malloc(0x200000, "wan_extend_data", 3948);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    v3 = (const char *)jhl_nv_get_def("increase_wan");
    v4 = (const char *)jhl_nv_get_def("increase_base");
    v5 = snprintf(v2 + 29, 2097123, "\"increase_wan\":\"%s\",\"increase_base\":\"%s\",\"all\":", v3, v4);
    if ( v5 >= 2097123 )
      v5 = 2097122;
    v6 = v5 + 29;
    v7 = 0x200000 - (v5 + 29);
    v8 = &v2[v5 + 29];
    v9 = nvram_get("increase_wan_all");
    v10 = snprintf(&v2[v6], 0x200000 - v6, (char *)&word_642A04);
    if ( v10 >= 0x200000 - v6 )
      v10 = 0x1FFFFF - v6;
    if ( v9 )
    {
      v11 = (const char **)malloc(0x18u);
      v36 = malloc(0x4008u);
      v13 = v36;
      v12 = malloc(0x200000u);
      ptr = v12;
      if ( v12 )
      {
        if ( v11 )
        {
          v14 = v9;
          if ( v36 )
          {
            v15 = v12;
            strlcpy(v12, v14, 0x200000);
            v16 = split_string(v15, 60, v36, 4096);
            if ( v16 > 0 )
            {
              for ( i = 0; i != v16; ++i )
              {
                v18 = split_string(*v13, 124, v11, 4);
                format_wan_extend_data(v11, v18, &v8[v10], v7 - v10);
                v10 += v19;
                ++v13;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v11 )
        free(v11);
      if ( v36 )
        free(v36);
    }
    v20 = &v8[v10];
    if ( v10 > 0 && *(v20 - 1) == 44 )
      v20 = &v8[--v10];
    v21 = v7 - v10;
    *v20 = 0;
    v22 = snprintf(v20, v21, &byte_6445A0);
    if ( v22 >= v21 )
      v22 = v21 - 1;
    v23 = v10 + v22 + v6;
    v24 = snprintf(&v2[v23], 0x200000 - v23, (char *)&dword_6448E0);
    if ( v24 >= 0x200000 - v23 )
      v24 = 0x1FFFFF - v23;
    v25 = v24 + v23 + get_wans_increase_data(&v2[v24 + v23], 0x200000 - (v24 + v23));
    v26 = snprintf(&v2[v25], 0x200000 - v25, ",\"real_wans\":");
    if ( v26 >= 0x200000 - v25 )
      v26 = 0x1FFFFF - v25;
    v27 = v26 + v25 + get_realwans_data(0, &v2[v26 + v25], 0x200000 - (v26 + v25));
    v28 = snprintf(&v2[v27], 0x200000 - v27, ",\"sfp_num\":%d", 0);
    if ( v28 >= 0x200000 - v27 )
      v28 = 0x1FFFFF - v27;
    v29 = v28 + v27;
    v30 = snprintf(&v2[v29], 0x200000 - v29, "}}");
    if ( v30 >= 0x200000 - v29 )
      v31 = 0x1FFFFF - v29;
    else
      v31 = v30;
    result = httpd_cgi_ret(a1, v2, v31 + v29, 8);
  }
  else
  {
    v33 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v34 = snprintf(v35, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v33);
    if ( v34 >= 0x100 )
      v34 = 255;
    result = httpd_cgi_ret(a1, v35, v34, 4);
  }
  return result;
}
// 448FB0: variable 'v1' is possibly undefined
// 4491C0: variable 'v19' is possibly undefined
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

