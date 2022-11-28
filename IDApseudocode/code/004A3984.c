int __fastcall sub_4A3984(int a1)
{
  int v1; // $v0
  int v2; // $fp
  const char *v3; // $s3
  const char *v4; // $s1
  const char *v5; // $s2
  const char *v6; // $v0
  int v7; // $v0
  char *v8; // $a1
  int v9; // $s3
  int v10; // $s1
  int v11; // $s4
  int v12; // $s5
  int v13; // $s0
  const char **v14; // $s2
  void *v15; // $v0
  _DWORD *v16; // $s6
  int v17; // $a1
  void *v18; // $s5
  int v19; // $s5
  int i; // $s7
  int v21; // $v0
  int v22; // $v0
  char *v23; // $a0
  int v24; // $s1
  int v25; // $v0
  int v26; // $s3
  _DWORD *v27; // $v0
  int v28; // $s3
  int v29; // $v0
  int v30; // $a2
  int result; // $v0
  const char *v32; // $v0
  unsigned int v33; // $v0
  char v34[256]; // [sp+28h] [-108h] BYREF
  _DWORD *v35; // [sp+128h] [-8h]
  void *ptr; // [sp+12Ch] [-4h]

  _mem_malloc(0x200000, "nat_base_data", 74);
  if ( v1 )
  {
    v2 = v1;
    asp_lipp(v34);
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    v3 = (const char *)jhl_nv_get_def("nf_loopback");
    v4 = (const char *)jhl_nv_get_def("nf_sports");
    v5 = (const char *)jhl_nv_get_def("nf_dxtong");
    v6 = (const char *)jhl_nv_get_def("nf_fullcone");
    v7 = sprintf(
           (char *)(v2 + 29),
           "\"mode\":\"%s\",\"nf_sports\":\"%s\",\"nf_dxtong\":\"%s\",\"nf_fullcone\":\"%s\",\"fullcone_show\":%d,\"lipp\""
           ":\"%s\",\"karten_modus\":0",
           v3,
           v4,
           v5,
           v6,
           1,
           v34);
    v8 = (char *)(v2 + v7 + 29);
    strcpy(v8, ",\"portforward\":");
    strcpy(v8, ",\"portforward\":");
    v9 = v7 + 44;
    v10 = 0x200000 - (v7 + 44);
    v11 = v2 + v7 + 44;
    v12 = nvram_get("portforward");
    v13 = snprintf((char *)(v2 + v9), 0x200000 - v9, (char *)&word_642A04);
    if ( v13 >= 0x200000 - v9 )
      v13 = 0x1FFFFF - v9;
    if ( v12 )
    {
      v14 = (const char **)malloc(0x28u);
      v35 = malloc(0x4008u);
      v16 = v35;
      v15 = malloc(0x200000u);
      ptr = v15;
      if ( v15 )
      {
        if ( v14 )
        {
          v17 = v12;
          if ( v16 )
          {
            v18 = v15;
            strlcpy(v15, v17, 0x200000);
            v19 = split_string(v18, 62, v16, 4096);
            if ( v19 > 0 )
            {
              for ( i = 0; i != v19; ++i )
              {
                v21 = split_string(*v16, 60, v14, 8);
                format_nat_base_data(v14, v21, (char *)(v11 + v13), v10 - v13);
                v13 += v22;
                ++v16;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v14 )
        free(v14);
      if ( v35 )
        free(v35);
    }
    v23 = (char *)(v11 + v13);
    if ( v13 > 0 && *(v23 - 1) == 44 )
    {
      --v13;
      v23 = (char *)(v11 + v13);
    }
    v24 = v10 - v13;
    *v23 = 0;
    v25 = snprintf(v23, v24, &byte_6445A0);
    if ( v25 >= v24 )
      v25 = v24 - 1;
    v26 = v13 + v25 + v9;
    v27 = (_DWORD *)(v2 + v26);
    strcpy((char *)(v2 + v26), ",\"wans\":");
    *v27 = 1635197484;
    v27[1] = 975336302;
    v28 = v26 + 8 + get_wans_data((char *)(v2 + v26 + 8), 0x200000 - (v26 + 8));
    v29 = snprintf((char *)(v2 + v28), 0x200000 - v28, "}}");
    if ( v29 >= 0x200000 - v28 )
      v30 = 0x1FFFFF - v28;
    else
      v30 = v29;
    result = httpd_cgi_ret(a1, (char *)v2, v30 + v28, 8);
  }
  else
  {
    v32 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v33 = snprintf(v34, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v32);
    if ( v33 >= 0x100 )
      v33 = 255;
    result = httpd_cgi_ret(a1, v34, v33, 4);
  }
  return result;
}
// 4A39E0: variable 'v1' is possibly undefined
// 4A3C84: variable 'v22' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6448E0: using guessed type int dword_6448E0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

