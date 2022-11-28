int __fastcall sub_4882FC(int a1)
{
  int v1; // $v0
  char *v2; // $fp
  const char *v3; // $s1
  const char *v4; // $s2
  const char *v5; // $s3
  const char *v6; // $v0
  int v7; // $v0
  int v8; // $s1
  int v9; // $s0
  int v10; // $v0
  int v11; // $s1
  int v12; // $v0
  int v13; // $s3
  int v14; // $s1
  char *v15; // $s4
  int v16; // $s5
  int v17; // $s0
  const char **v18; // $s2
  void *v19; // $v0
  _DWORD *v20; // $s6
  int v21; // $a1
  void *v22; // $s5
  int v23; // $s5
  int i; // $s7
  int v25; // $v0
  int v26; // $v0
  char *v27; // $a0
  int v28; // $s1
  int v29; // $v0
  int v30; // $s3
  int v31; // $v0
  int v32; // $a2
  int result; // $v0
  const char *v34; // $v0
  unsigned int v35; // $v0
  char v36[256]; // [sp+28h] [-108h] BYREF
  _DWORD *v37; // [sp+128h] [-8h]
  void *ptr; // [sp+12Ch] [-4h]

  _mem_malloc(0x200000, "url_rule_data", 602);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    v3 = (const char *)jhl_nv_get_def("urlAct");
    v4 = (const char *)jhl_nv_get_def(&unk_64A784);
    v5 = (const char *)jhl_nv_get_def("urlto");
    v6 = (const char *)jhl_nv_get_def("urltoz");
    v7 = snprintf(v2 + 29, 2097123, "\"def\":%s,\"block\":%s,\"tiao\":%s,\"tiaozhuan\":\"%s\"", v3, v4, v5, v6);
    if ( v7 >= 2097123 )
      v7 = 2097122;
    v8 = v7 + 29;
    v9 = 0x200000 - (v7 + 29);
    v10 = snprintf(&v2[v7 + 29], v9, (char *)&dword_64A6B0);
    if ( v10 >= v9 )
      v10 = 0x1FFFFF - v8;
    v11 = v10 + v8 + get_url_group_data(&v2[v10 + v8], 0x200000 - (v10 + v8));
    v12 = snprintf(&v2[v11], 0x200000 - v11, ",\"all\":");
    if ( v12 >= 0x200000 - v11 )
      v12 = 0x1FFFFF - v11;
    v13 = v12 + v11;
    v14 = 0x200000 - (v12 + v11);
    v15 = &v2[v13];
    v16 = nvram_get("url_rules");
    v17 = snprintf(&v2[v13], 0x200000 - v13, (char *)&word_642A04);
    if ( v17 >= 0x200000 - v13 )
      v17 = 0x1FFFFF - v13;
    if ( v16 )
    {
      v18 = (const char **)malloc(0x2Cu);
      v37 = malloc(0x4008u);
      v20 = v37;
      v19 = malloc(0x200000u);
      ptr = v19;
      if ( v19 )
      {
        if ( v18 )
        {
          v21 = v16;
          if ( v37 )
          {
            v22 = v19;
            strlcpy(v19, v21, 0x200000);
            v23 = split_string(v22, 60, v37, 4096);
            if ( v23 > 0 )
            {
              for ( i = 0; i != v23; ++i )
              {
                v25 = split_string(*v20, 124, v18, 9);
                format_url_rule_data(v18, v25, &v15[v17], v14 - v17);
                v17 += v26;
                ++v20;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v18 )
        free(v18);
      if ( v37 )
        free(v37);
    }
    v27 = &v15[v17];
    if ( v17 > 0 && *(v27 - 1) == 44 )
      v27 = &v15[--v17];
    v28 = v14 - v17;
    *v27 = 0;
    v29 = snprintf(v27, v28, &byte_6445A0);
    if ( v29 >= v28 )
      v29 = v28 - 1;
    v30 = v17 + v29 + v13;
    v31 = snprintf(&v2[v30], 0x200000 - v30, "}}");
    if ( v31 >= 0x200000 - v30 )
      v32 = 0x1FFFFF - v30;
    else
      v32 = v31;
    result = httpd_cgi_ret(a1, v2, v32 + v30, 8);
  }
  else
  {
    v34 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v35 = snprintf(v36, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v34);
    if ( v35 >= 0x100 )
      v35 = 255;
    result = httpd_cgi_ret(a1, v36, v35, 4);
  }
  return result;
}
// 48835C: variable 'v1' is possibly undefined
// 48863C: variable 'v26' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 64A6B0: using guessed type int dword_64A6B0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

