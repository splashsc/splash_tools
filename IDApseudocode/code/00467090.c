int __fastcall sub_467090(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $s1
  int v5; // $v0
  int v6; // $s1
  int v7; // $v0
  int v8; // $s1
  int v9; // $v0
  int v10; // $s1
  int v11; // $v0
  int v12; // $a2
  int result; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(1024000, "group_all_data", 1419);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{\"ips\":");
    qmemcpy((void *)v2, "{\"code\":0,\"error", 16);
    *(_DWORD *)(v2 + 24) = 975331700;
    *(_BYTE *)(v2 + 32) = 115;
    v4 = get_ips_group_data((char *)(v2 + 35), 1023965) + 35;
    v5 = snprintf(&v3[v4], 1024000 - v4, ",\"times\":");
    if ( v5 >= 1024000 - v4 )
      v5 = 1023999 - v4;
    v6 = v5 + v4 + get_time_group_data(&v3[v5 + v4], 1024000 - (v5 + v4));
    v7 = snprintf(&v3[v6], 1024000 - v6, ",\"dnszu\":");
    if ( v7 >= 1024000 - v6 )
      v7 = 1023999 - v6;
    v8 = v7 + v6 + dns_more_dnstype_get_json(&v3[v7 + v6], 1024000 - (v7 + v6));
    v9 = snprintf(&v3[v8], 1024000 - v8, ",\"dnsout\":");
    if ( v9 >= 1024000 - v8 )
      v9 = 1023999 - v8;
    v10 = v9 + v8 + get_dns_more_dnswan_data(&v3[v9 + v8], 1024000 - (v9 + v8));
    v11 = snprintf(&v3[v10], 1024000 - v10, "}}");
    if ( v11 >= 1024000 - v10 )
      v12 = 1023999 - v10;
    else
      v12 = v11;
    result = httpd_cgi_ret(a1, v3, v12 + v10, 8);
  }
  else
  {
    v14 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 1024000);
    v15 = snprintf(v16, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v15 >= 0x100 )
      v15 = 255;
    result = httpd_cgi_ret(a1, v16, v15, 4);
  }
  return result;
}
// 4670E4: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A8934: using guessed type int __fastcall dns_more_dnstype_get_json(_DWORD, _DWORD);

