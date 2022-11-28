int __fastcall sub_462EE0(int a1)
{
  int v1; // $v0
  char *v2; // $fp
  int v3; // $v0
  const char *v4; // $s1
  const char *v5; // $s2
  const char *v6; // $s3
  const char *v7; // $s4
  const char *v8; // $s5
  const char *v9; // $v0
  int v10; // $v0
  int v11; // $s3
  int v12; // $s1
  char *v13; // $s4
  int v14; // $s5
  int v15; // $s0
  const char **v16; // $s2
  void *v17; // $v0
  _DWORD *v18; // $s6
  int v19; // $a1
  void *v20; // $s5
  int v21; // $s5
  int i; // $s7
  int v23; // $v0
  int v24; // $v0
  char *v25; // $a0
  int v26; // $s1
  int v27; // $v0
  int v28; // $s3
  int v29; // $v0
  int v30; // $a2
  int result; // $v0
  const char *v32; // $v0
  unsigned int v33; // $v0
  char v34[256]; // [sp+30h] [-208h] BYREF
  int v35[64]; // [sp+130h] [-108h] BYREF
  _DWORD *v36; // [sp+230h] [-8h]
  void *ptr; // [sp+234h] [-4h]

  memset(v34, 0, sizeof(v34));
  _mem_malloc(102400, "ctxz_data", 1858);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    v3 = jhl_nv_get_def("hixz3");
    strlcpy(v34, v3, 256);
    split_string(v34, 60, v35, 15);
    v4 = (const char *)v35[0];
    v5 = (const char *)v35[3];
    v6 = (const char *)v35[6];
    v7 = (const char *)v35[9];
    v8 = (const char *)v35[12];
    v9 = (const char *)nvram_get("ct_max");
    if ( !v9 )
      v9 = "";
    v10 = snprintf(
            v2 + 29,
            102371,
            "\"def\":%s,\"defTcp\":%s,\"defUdp\":%s,\"defIcmp\":%s,\"defOther\":%s,\"ct_max\":%s,\"all\":",
            v4,
            v5,
            v6,
            v7,
            v8,
            v9);
    if ( v10 >= 102371 )
      v10 = 102370;
    v11 = v10 + 29;
    v12 = 102400 - (v10 + 29);
    v13 = &v2[v10 + 29];
    v14 = nvram_get("hixz_ct");
    v15 = snprintf(&v2[v11], 102400 - v11, (char *)&word_642A04);
    if ( v15 >= 102400 - v11 )
      v15 = 102399 - v11;
    if ( v14 )
    {
      v16 = (const char **)malloc(0x20u);
      v36 = malloc(0x4008u);
      v18 = v36;
      v17 = malloc(0x200000u);
      ptr = v17;
      if ( v17 )
      {
        if ( v16 )
        {
          v19 = v14;
          if ( v18 )
          {
            v20 = v17;
            strlcpy(v17, v19, 0x200000);
            v21 = split_string(v20, 60, v18, 4096);
            if ( v21 > 0 )
            {
              for ( i = 0; i != v21; ++i )
              {
                v23 = split_string(*v18, 124, v16, 6);
                format_ctxz_data(v16, v23, &v13[v15], v12 - v15);
                v15 += v24;
                ++v18;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v16 )
        free(v16);
      if ( v36 )
        free(v36);
    }
    v25 = &v13[v15];
    if ( v15 > 0 && *(v25 - 1) == 44 )
      v25 = &v13[--v15];
    v26 = v12 - v15;
    *v25 = 0;
    v27 = snprintf(v25, v26, &byte_6445A0);
    if ( v27 >= v26 )
      v27 = v26 - 1;
    v28 = v15 + v27 + v11;
    v29 = snprintf(&v2[v28], 102400 - v28, "}}");
    if ( v29 >= 102400 - v28 )
      v30 = 102399 - v28;
    else
      v30 = v29;
    result = httpd_cgi_ret(a1, v2, v30 + v28, 8);
  }
  else
  {
    v32 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v33 = snprintf((char *)v35, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v32);
    if ( v33 >= 0x100 )
      v33 = 255;
    result = httpd_cgi_ret(a1, 0, v33, 4);
  }
  return result;
}
// 462F60: variable 'v1' is possibly undefined
// 4631C8: variable 'v24' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

