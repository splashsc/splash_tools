int __fastcall sub_4C73B8(int a1)
{
  int v2; // $v0
  char *v3; // $s0
  int v4; // $s3
  int v5; // $v0
  int v6; // $a2
  int result; // $v0
  const char *v8; // $v0
  unsigned int v9; // $v0
  char v10[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(0x200000, "wan_conf_ipv6_data", 211);
  v3 = (char *)v2;
  if ( v2 )
  {
    strcpy((char *)v2, "{\"code\":0,\"error\":\"\",\"data\":{\"wans\":");
    qmemcpy((void *)v2, "{\"code\":0,\"error\":\"\"", 20);
    *(_DWORD *)(v2 + 24) = 975331700;
    strcpy((char *)(v2 + 32), "ns\":");
    v4 = get_ipv6_wans_data((char *)(v2 + 36), 2097116) + 36;
    v5 = snprintf(&v3[v4], 0x200000 - v4, "}}");
    if ( v5 >= 0x200000 - v4 )
      v6 = 0x1FFFFF - v4;
    else
      v6 = v5;
    result = httpd_cgi_ret(a1, v3, v6 + v4, 8);
  }
  else
  {
    v8 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v9 = snprintf(v10, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v8);
    if ( v9 >= 0x100 )
      v9 = 255;
    result = httpd_cgi_ret(a1, v10, v9, 4);
  }
  return result;
}
// 4C7408: variable 'v2' is possibly undefined
// 642164: using guessed type __int16 word_642164;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

