int __fastcall sub_440C94(int a1)
{
  int v2; // $v0
  int v3; // $s4
  char *v4; // $s0
  int v5; // $v0
  char *v6; // $v1
  int v7; // $s2
  int v8; // $s1
  int v9; // $v0
  const char *v10; // $v0
  char *v11; // $s1
  const char *v12; // $v0
  int v13; // $s2
  int v14; // $v0
  int v15; // $a2
  int result; // $v0
  const char *v17; // $v0
  unsigned int v18; // $v0
  char v19[260]; // [sp+20h] [-104h] BYREF

  v3 = sq_file_get_max_wan();
  _mem_malloc(0x200000, "wansvpns_data", 3382);
  v4 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{\"wans\":");
    qmemcpy((void *)v2, "{\"code\":0,\"error", 16);
    *(_DWORD *)(v2 + 24) = 975331700;
    strcpy((char *)(v2 + 32), "ns\":");
    v5 = get_wans_data((char *)(v2 + 36), 2097116);
    v6 = &v4[v5 + 36];
    strcpy(v6, ",\"vpns\":[ ");
    *(_DWORD *)v6 = *(_DWORD *)",\"vpns\":[ ";
    v7 = v5 + 46;
    if ( v3 > 0 )
    {
      v8 = 0;
      do
      {
        v9 = jhl_vpnget("vpn_proto", v8);
        v10 = (const char *)nvram_get(v9);
        if ( !v10 || strcmp(v10, (const char *)&off_63F984) )
          v7 += sprintf(&v4[v7], "{\"iface\":%d},", v8);
        ++v8;
      }
      while ( v8 != 5 && v3 != v8 );
    }
    v11 = &v4[v7];
    if ( v7 > 0 && *(v11 - 1) == 44 )
      v11 = &v4[--v7];
    *v11 = 0;
    v12 = (const char *)jhl_nv_get_def("mr_mode");
    v13 = v7 + sprintf(v11, "],\"mr_mode\":\"%s\"", v12);
    v14 = snprintf(&v4[v13], 0x200000 - v13, "}}");
    if ( v14 >= 0x200000 - v13 )
      v15 = 0x1FFFFF - v13;
    else
      v15 = v14;
    result = httpd_cgi_ret(a1, v4, v15 + v13, 8);
  }
  else
  {
    v17 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v18 = snprintf(v19, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v17);
    if ( v18 >= 0x100 )
      v18 = 255;
    result = httpd_cgi_ret(a1, v19, v18, 4);
  }
  return result;
}
// 440D00: variable 'v2' is possibly undefined
// 63F984: using guessed type void *off_63F984;
// 642164: using guessed type __int16 word_642164;
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A84C8: using guessed type int __fastcall jhl_nv_get_def(_DWORD);
// 6A85E0: using guessed type int sq_file_get_max_wan(void);
// 6A8948: using guessed type int __fastcall jhl_vpnget(_DWORD, _DWORD);

