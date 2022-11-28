int __fastcall sub_4AAE6C(int a1)
{
  int v1; // $v0
  int v2; // $s0
  char *v3; // $fp
  int v4; // $v0
  char *v5; // $a0
  int v6; // $s1
  int v7; // $s2
  int v8; // $v0
  const char *v9; // $v0
  char *v10; // $a0
  char *v11; // $a1
  int v12; // $s1
  int v13; // $s2
  char *v14; // $s4
  int v15; // $s5
  int v16; // $s0
  const char **v17; // $s3
  void *v18; // $v0
  _DWORD *v19; // $s6
  int v20; // $a1
  void *v21; // $s5
  int v22; // $s5
  int i; // $s7
  int v24; // $v0
  int v25; // $v0
  char *v26; // $a0
  int v27; // $s2
  int v28; // $v0
  int v29; // $s1
  int v30; // $v0
  int v31; // $a2
  int result; // $v0
  const char *v33; // $v0
  unsigned int v34; // $v0
  char v35[256]; // [sp+20h] [-108h] BYREF
  _DWORD *v36; // [sp+120h] [-8h]
  void *ptr; // [sp+124h] [-4h]

  v2 = sq_file_get_max_wan();
  _mem_malloc(102400, "menu_nat_more_data", 2113);
  v3 = (char *)v1;
  if ( v1 )
  {
    strcpy((char *)v1, "{\"code\":0,\"error\":\"\",\"data\":{\"wans\":");
    qmemcpy((void *)v1, "{\"code\":0,\"error", 16);
    *(_DWORD *)(v1 + 24) = 975331700;
    strcpy((char *)(v1 + 32), "ns\":");
    v4 = get_wans_data((char *)(v1 + 36), 102364);
    v5 = &v3[v4 + 36];
    strcpy(v5, ",\"vpns\":[ ");
    *(_DWORD *)v5 = *(_DWORD *)",\"vpns\":[ ";
    v6 = v4 + 46;
    if ( v2 > 0 )
    {
      v7 = 0;
      do
      {
        v8 = jhl_vpnget("vpn_proto", v7);
        v9 = (const char *)nvram_get(v8);
        if ( !v9 || strcmp(v9, (const char *)&off_63F984) )
          v6 += sprintf(&v3[v6], "{\"iface\":%d},", v7);
        ++v7;
      }
      while ( v7 != 5 && v2 != v7 );
    }
    v10 = &v3[v6];
    if ( v6 > 0 && *(v10 - 1) == 44 )
      v10 = &v3[--v6];
    *(_WORD *)v10 = 93;
    v11 = &v3[v6 + 1];
    strcpy(v11, ",\"nat_list_more\":");
    qmemcpy(v11, ",\"nat_list_m", 12);
    v12 = v6 + 18;
    v13 = 102400 - v12;
    v14 = &v3[v12];
    v15 = nvram_get("nat_list_more");
    v16 = snprintf(&v3[v12], 102400 - v12, (char *)&word_642A04);
    if ( v16 >= 102400 - v12 )
      v16 = 102399 - v12;
    if ( v15 )
    {
      v17 = (const char **)malloc(0x30u);
      v36 = malloc(0x4008u);
      v19 = v36;
      v18 = malloc(0x200000u);
      ptr = v18;
      if ( v18 )
      {
        if ( v17 )
        {
          v20 = v15;
          if ( v36 )
          {
            v21 = v18;
            strlcpy(v18, v20, 0x200000);
            v22 = split_string(v21, 60, v36, 4096);
            if ( v22 > 0 )
            {
              for ( i = 0; i != v22; ++i )
              {
                v24 = split_string(*v19, 124, v17, 10);
                format_menu_nat_more_data(v17, v24, &v14[v16], v13 - v16);
                v16 += v25;
                ++v19;
              }
            }
          }
        }
        free(ptr);
      }
      if ( v17 )
        free(v17);
      if ( v36 )
        free(v36);
    }
    v26 = &v14[v16];
    if ( v16 > 0 && *(v26 - 1) == 44 )
      v26 = &v14[--v16];
    v27 = v13 - v16;
    *v26 = 0;
    v28 = snprintf(v26, v27, &byte_6445A0);
    if ( v28 >= v27 )
      v28 = v27 - 1;
    v29 = v16 + v28 + v12;
    v30 = snprintf(&v3[v29], 102400 - v29, "}}");
    if ( v30 >= 102400 - v29 )
      v31 = 102399 - v29;
    else
      v31 = v30;
    result = httpd_cgi_ret(a1, v3, v31 + v29, 8);
  }
  else
  {
    v33 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v34 = snprintf(v35, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v33);
    if ( v34 >= 0x100 )
      v34 = 255;
    result = httpd_cgi_ret(a1, v35, v34, 4);
  }
  return result;
}
// 4AAEE4: variable 'v1' is possibly undefined
// 4AB21C: variable 'v25' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 642A04: using guessed type __int16 word_642A04;
// 6445A0: using guessed type char byte_6445A0;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8778: using guessed type int __fastcall split_string(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

