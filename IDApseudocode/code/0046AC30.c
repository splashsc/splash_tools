int __fastcall sub_46AC30(int a1)
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
  int v22; // $s3
  char *v23; // $a0
  int v24; // $v0
  int v25; // $a2
  int result; // $v0
  const char *v27; // $v0
  unsigned int v28; // $v0
  char v29[256]; // [sp+20h] [-108h] BYREF
  _DWORD *v30; // [sp+120h] [-8h]
  void *ptr; // [sp+124h] [-4h]

  _mem_malloc(0x200000, "dns_acc_data", 2528);
  v2 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v1, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v1 + 24) = 975331700;
    v3 = (const char *)jhl_nv_get_def("dnsDef");
    v4 = snprintf(v2 + 29, 2097123, "\"def\":%s,\"all\":", v3);
    if ( v4 >= 2097123 )
      v4 = 2097122;
    v5 = v4 + 29;
    v6 = 0x200000 - (v4 + 29);
    v7 = &v2[v4 + 29];
    v8 = nvram_get("dnsAcc");
    v9 = snprintf(&v2[v5], 0x200000 - v5, (char *)&word_642A04);
    if ( v9 >= 0x200000 - v5 )
      v9 = 0x1FFFFF - v5;
    if ( v8 )
    {
      v10 = (const char **)malloc(0xCu);
      v30 = malloc(0x4008u);
      v12 = v30;
      v11 = malloc(0x200000u);
      ptr = v11;
      if ( v11 )
      {
        if ( v10 )
        {
          v13 = v8;
          if ( v30 )
          {
            v14 = v11;
            strlcpy(v11, v13, 0x200000);
            v15 = split_string(v14, 60, v30, 4096);
            if ( v15 > 0 )
            {
              for ( i = 0; i != v15; ++i )
              {
                v17 = split_string(*v12, 124, v10, 1);
                format_dns_acc_data(v10, v17, &v7[v9], v6 - v9);
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
      if ( v30 )
        free(v30);
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
    v23 = &v2[v22];
    if ( v22 > 0 && *(v23 - 1) == 44 )
      v23 = &v2[--v22];
    *v23 = 0;
    v24 = snprintf(v23, 0x200000 - v22, "}}");
    if ( v24 >= 0x200000 - v22 )
      v25 = 0x1FFFFF - v22;
    else
      v25 = v24;
    result = httpd_cgi_ret(a1, v2, v22 + v25, 8);
  }
  else
  {
    v27 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v28 = snprintf(v29, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v27);
    if ( v28 >= 0x100 )
      v28 = 255;
    result = httpd_cgi_ret(a1, v29, v28, 4);
  }
  return result;
}
// 46AC90: variable 'v1' is possibly undefined
// 46AE80: variable 'v18' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

