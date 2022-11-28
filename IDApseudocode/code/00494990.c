int __fastcall sub_494990(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $s1
  int v5; // $v0
  int v6; // $s1
  int v7; // $v0
  int v8; // $s1
  int v9; // $v0
  int v10; // $a2
  int result; // $v0
  const char *v12; // $v0
  unsigned int v13; // $v0
  char v14[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(102400, "dns_more_dnswan_data", 1016);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{\"all\":");
    qmemcpy((void *)v2, "{\"code\":0,\"error", 16);
    *(_DWORD *)(v2 + 24) = 975331700;
    *(_BYTE *)(v2 + 32) = 108;
    v4 = get_dns_more_dnswan_data((char *)(v2 + 35), 102365) + 35;
    v5 = snprintf(&v3[v4], 102400 - v4, (char *)&dword_6448E0);
    if ( v5 >= 102400 - v4 )
      v5 = 102399 - v4;
    v6 = v5 + v4 + get_wans_data(&v3[v5 + v4], 102400 - (v5 + v4));
    v7 = snprintf(&v3[v6], 102400 - v6, (char *)&dword_64331C);
    if ( v7 >= 102400 - v6 )
      v7 = 102399 - v6;
    v8 = v7 + v6 + get_vpns_iface(&v3[v7 + v6]);
    v9 = snprintf(&v3[v8], 102400 - v8, "}}");
    if ( v9 >= 102400 - v8 )
      v10 = 102399 - v8;
    else
      v10 = v9;
    result = httpd_cgi_ret(a1, v3, v10 + v8, 8);
  }
  else
  {
    v12 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
    v13 = snprintf(v14, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v12);
    if ( v13 >= 0x100 )
      v13 = 255;
    result = httpd_cgi_ret(a1, v14, v13, 4);
  }
  return result;
}
// 4949E4: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 64331C: using guessed type int dword_64331C;
// 6448E0: using guessed type int dword_6448E0;
// 6459A8: using guessed type int dword_6459A8;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

