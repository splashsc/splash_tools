int __fastcall sub_441AF0(int a1)
{
  char *v1; // $v0
  const char *v2; // $s0
  char *v3; // $v0
  char *v4; // $fp
  char *v5; // $v0
  int v6; // $v0
  int v7; // $v0
  int v8; // $s3
  char *v9; // $s5
  int v10; // $s1
  char *v11; // $s4
  int v12; // $s0
  _DWORD *v13; // $s2
  void *v14; // $v0
  _DWORD *v15; // $s6
  char *v16; // $a1
  void *v17; // $s5
  int v18; // $s5
  int i; // $s7
  int v20; // $v0
  int v21; // $v0
  char *v22; // $a0
  int v23; // $s1
  int v24; // $v0
  int v25; // $s3
  int v26; // $v0
  int v27; // $a2
  const char *v29; // $v0
  unsigned int v30; // $a2
  const char *v31; // $v0
  unsigned int v32; // $v0
  char v33[1024]; // [sp+20h] [-448h] BYREF
  int v34[8]; // [sp+420h] [-48h] BYREF
  int v35[8]; // [sp+440h] [-28h] BYREF
  _DWORD *v36; // [sp+460h] [-8h]
  void *ptr; // [sp+464h] [-4h]

  v35[0] = 0;
  v35[1] = 0;
  v35[2] = 0;
  v35[3] = 0;
  v35[4] = 0;
  v35[5] = 0;
  v35[6] = 0;
  v35[7] = 0;
  v34[0] = 0;
  v34[1] = 0;
  v34[2] = 0;
  v34[3] = 0;
  v34[4] = 0;
  v34[5] = 0;
  v34[6] = 0;
  v34[7] = 0;
  v1 = httpd_get_parm(a1, "type");
  if ( !v1 || (v2 = v1, strcmp(v1, "m")) && strcmp(v2, "h") && strcmp(v2, "d") )
  {
    v29 = (const char *)_GET_LANG_TEXT(12, *(unsigned __int8 *)(a1 + 210102), &unk_64334C);
    v30 = snprintf(v33, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v29);
    if ( v30 >= 0x400 )
      v30 = 1023;
    return httpd_cgi_ret(a1, v33, v30, 4);
  }
  sprintf((char *)v35, "host_num_%s_l", v2);
  sprintf((char *)v34, "host_num_%s_t", v2);
  _mem_malloc(102400, "hi_history_data", 519);
  v4 = v3;
  if ( v3 )
  {
    strcpy(v3, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v3, "{\"code\":0,\"error", 16);
    v5 = (char *)nvram_get(v34);
    if ( !v5 )
      v5 = "";
    v6 = J_atoi(v5);
    v7 = snprintf(v4 + 29, 102371, "\"time\":%lu,\"all\":", v6);
    if ( v7 >= 102371 )
    {
      v8 = 102399;
      v9 = (char *)nvram_get(v35);
      if ( v9 )
        goto LABEL_9;
    }
    else
    {
      v8 = v7 + 29;
      v9 = (char *)nvram_get(v35);
      if ( v9 )
      {
LABEL_9:
        v10 = 102400 - v8;
        v11 = &v4[v8];
        v12 = snprintf(&v4[v8], 102400 - v8, (char *)&word_642A04);
        if ( v12 >= 102400 - v8 )
          v12 = 102399 - v8;
        v13 = malloc(0xCu);
        v36 = malloc(0x808u);
        v15 = v36;
        v14 = malloc(0x200000u);
        ptr = v14;
        if ( v14 )
        {
          if ( v13 )
          {
            v16 = v9;
            if ( v15 )
            {
              v17 = v14;
              strlcpy(v14, v16, 0x200000);
              v18 = split_string(v17, 60, v15, 512);
              if ( v18 > 0 )
              {
                for ( i = 0; i != v18; ++i )
                {
                  v20 = split_string(*v15, 124, v13, 1);
                  format_hi_history_data(v13, v20, &v11[v12], v10 - v12);
                  v12 += v21;
                  ++v15;
                }
              }
            }
          }
          free(ptr);
        }
        if ( v13 )
          free(v13);
        if ( v36 )
          free(v36);
        v22 = &v11[v12];
        if ( v12 > 0 && *(v22 - 1) == 44 )
          v22 = &v11[--v12];
        v23 = v10 - v12;
        *v22 = 0;
        v24 = snprintf(v22, v23, &byte_6445A0);
        if ( v24 >= v23 )
          v24 = v23 - 1;
        v25 = v12 + v24 + v8;
        v26 = snprintf(&v4[v25], 102400 - v25, "}}");
        if ( v26 >= 102400 - v25 )
          v27 = 102399 - v25;
        else
          v27 = v26;
        return httpd_cgi_ret(a1, v4, v27 + v25, 8);
      }
    }
    v9 = "";
    goto LABEL_9;
  }
  v31 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v32 = snprintf(v33, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v31);
  if ( v32 >= 0x400 )
    v32 = 1023;
  return httpd_cgi_ret(a1, v33, v32, 4);
}
// 441C30: variable 'v3' is possibly undefined
// 441E34: variable 'v21' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A89B4: using guessed type int __fastcall J_atoi(_DWORD);

