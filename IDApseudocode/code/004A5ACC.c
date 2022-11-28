int __fastcall sub_4A5ACC(int a1)
{
  char *v1; // $v0
  char *v2; // $fp
  int v3; // $v0
  char *v4; // $a2
  int v5; // $s1
  char *v6; // $a1
  int v7; // $s1
  int v8; // $s2
  char *v9; // $s4
  int v10; // $s5
  int v11; // $s0
  const char **v12; // $s3
  void *v13; // $v0
  _DWORD *v14; // $s6
  int v15; // $a1
  void *v16; // $s5
  int v17; // $s5
  int i; // $s7
  int v19; // $v0
  int v20; // $v0
  char *v21; // $a0
  int v22; // $s2
  int v23; // $v0
  int v24; // $s1
  char *v25; // $a0
  int v26; // $v0
  int v27; // $a2
  int result; // $v0
  const char *v29; // $v0
  unsigned int v30; // $v0
  char v31[256]; // [sp+20h] [-120h] BYREF
  const char *v32[6]; // [sp+120h] [-20h] BYREF
  _DWORD *v33; // [sp+138h] [-8h]
  void *ptr; // [sp+13Ch] [-4h]

  v32[0] = "upnp_enable";
  v32[1] = "upnp_mnp";
  v32[2] = "upnp_waniface";
  v32[3] = "";
  v32[4] = "";
  _mem_malloc(1024000, "upnp_data", 645);
  v2 = v1;
  if ( v1 )
  {
    strcpy(v1, "{\"code\":0,\"error\":\"\",\"data\":{");
    qmemcpy(v1, "{\"code\":0,\"error\":\"\"", 20);
    v3 = get_nvarms(v32, (int)(v1 + 29), 1023971);
    v4 = &v2[v3 + 29];
    strcpy(v4, "\"wans\":");
    strcpy(v4, "\"wans\":");
    v5 = v3 + 36 + get_wans_data(&v2[v3 + 36], 1024000 - (v3 + 36));
    v6 = &v2[v5];
    strcpy(&v2[v5], ",\"upnp_list\":");
    *(_DWORD *)v6 = 1886724652;
    *((_DWORD *)v6 + 1) = 1818194030;
    v7 = v5 + 13;
    v8 = 1024000 - v7;
    v9 = &v2[v7];
    v10 = nvram_get("upnp_list");
    v11 = snprintf(&v2[v7], 1024000 - v7, (char *)&word_642A04);
    if ( v11 >= 1024000 - v7 )
      v11 = 1023999 - v7;
    if ( v10 )
    {
      v12 = (const char **)malloc(0x18u);
      v33 = malloc(0x4008u);
      v14 = v33;
      v13 = malloc(0x200000u);
      ptr = v13;
      if ( v13 )
      {
        if ( v12 )
        {
          v15 = v10;
          if ( v14 )
          {
            v16 = v13;
            strlcpy(v13, v15, 0x200000);
            v17 = split_string(v16, 60, v14, 4096);
            if ( v17 > 0 )
            {
              for ( i = 0; i != v17; ++i )
              {
                v19 = split_string(*v14, 124, v12, 4);
                format_upnp_list_data(v12, v19, &v9[v11], v8 - v11);
                v11 += v20;
                ++v14;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v12 )
        free(v12);
      if ( v33 )
        free(v33);
    }
    v21 = &v9[v11];
    if ( v11 > 0 && *(v21 - 1) == 44 )
      v21 = &v9[--v11];
    v22 = v8 - v11;
    *v21 = 0;
    v23 = snprintf(v21, v22, &byte_6445A0);
    if ( v23 >= v22 )
      v23 = v22 - 1;
    v24 = v11 + v23 + v7;
    v25 = &v2[v24];
    if ( v24 > 0 && *(v25 - 1) == 44 )
      v25 = &v2[--v24];
    *v25 = 0;
    v26 = snprintf(v25, 1024000 - v24, "}}");
    if ( v26 >= 1024000 - v24 )
      v27 = 1023999 - v24;
    else
      v27 = v26;
    result = httpd_cgi_ret(a1, v2, v24 + v27, 8);
  }
  else
  {
    v29 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v30 = snprintf(v31, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v29);
    if ( v30 >= 0x100 )
      v30 = 255;
    result = httpd_cgi_ret(a1, v31, v30, 4);
  }
  return result;
}
// 4A5B64: variable 'v1' is possibly undefined
// 4A5DA8: variable 'v20' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);

