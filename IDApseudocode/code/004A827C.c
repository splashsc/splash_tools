int __fastcall sub_4A827C(int a1)
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
  int v22; // $s0
  const char *v23; // $s1
  int v24; // $s3
  const char *v25; // $v0
  const char *v26; // $s0
  int v27; // $s3
  int v28; // $v0
  int v29; // $a2
  int result; // $v0
  const char *v31; // $v0
  unsigned int v32; // $v0
  char v33[256]; // [sp+20h] [-108h] BYREF
  _DWORD *v34; // [sp+120h] [-8h]
  void *ptr; // [sp+124h] [-4h]

  _mem_malloc(102400, "portward_nat_data", 1306);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{\"wans\":");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    strcpy((char *)(v1 + 32), "ns\":");
    v3 = get_wans_data((char *)(v1 + 36), 102364);
    v4 = &v2[v3 + 36];
    strcpy(v4, ",\"portward_nat_list\":");
    qmemcpy(v4, ",\"portward_nat_l", 16);
    v5 = v3 + 57;
    v6 = 102400 - (v3 + 57);
    v7 = &v2[v3 + 57];
    v8 = nvram_get("portward_nat_list");
    v9 = snprintf(&v2[v5], 102400 - v5, (char *)&word_642A04);
    if ( v9 >= 102400 - v5 )
      v9 = 102399 - v5;
    if ( v8 )
    {
      v10 = (const char **)malloc(0x2Cu);
      v34 = malloc(0x4008u);
      v12 = v34;
      v11 = malloc(0x200000u);
      ptr = v11;
      if ( v11 )
      {
        if ( v10 )
        {
          v13 = v8;
          if ( v34 )
          {
            v14 = v11;
            strlcpy(v11, v13, 0x200000);
            v15 = split_string(v14, 60, v34, 4096);
            if ( v15 > 0 )
            {
              for ( i = 0; i != v15; ++i )
              {
                v17 = split_string(*v12, 124, v10, 9);
                format_portward_nat_data(v10, v17, &v7[v9], v6 - v9);
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
      if ( v34 )
        free(v34);
    }
    v19 = &v7[v9];
    if ( v9 > 0 && *(v19 - 1) == 44 )
      v19 = &v7[--v9];
    v20 = v6 - v9;
    *v19 = 0;
    v21 = snprintf(v19, v20, &byte_6445A0);
    if ( v21 >= v20 )
      v21 = v20 - 1;
    v22 = v9 + v21;
    v23 = (const char *)jhl_nv_get_def("nf_loopback");
    v24 = v22 + v5;
    v26 = (const char *)jhl_nv_get_def("nf_dxtong");
    v25 = (const char *)jhl_nv_get_def("nf_fullcone");
    v27 = v24
        + sprintf(
            &v2[v24],
            ",\"mode\":\"%s\",\"nf_dxtong\":\"%s\",\"nf_fullcone\":\"%s\",\"fullcone_show\":%d",
            v23,
            v26,
            v25,
            1);
    v28 = snprintf(&v2[v27], 102400 - v27, "}}");
    if ( v28 >= 102400 - v27 )
      v29 = 102399 - v27;
    else
      v29 = v28;
    result = httpd_cgi_ret(a1, v2, v29 + v27, 8);
  }
  else
  {
    v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v32 = snprintf(v33, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
    if ( v32 >= 0x100 )
      v32 = 255;
    result = httpd_cgi_ret(a1, v33, v32, 4);
  }
  return result;
}
// 4A82E0: variable 'v1' is possibly undefined
// 4A8514: variable 'v18' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

