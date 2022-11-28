int __fastcall sub_494640(int a1)
{
  _DWORD *v2; // $v0
  char *v3; // $s2
  int v4; // $v0
  void *v5; // $s1
  int result; // $v0
  const char *v7; // $v0
  unsigned int v8; // $v0
  char v9[256]; // [sp+20h] [-100h] BYREF

  v3 = httpd_get_parm(a1, (char *)&off_64918C);
  _mem_malloc(0x200000, "dns_more_dnstype_item_txt", 931);
  if ( v2 )
  {
    v5 = v2;
    v4 = dns_more_dnstype_item_get_file(v2, 0x200000u, v3);
    *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
    result = httpd_send_mime_file(a1, "application/binary-file", v5, v4);
  }
  else
  {
    v7 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v8 = snprintf(v9, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v7);
    if ( v8 >= 0x100 )
      v8 = 255;
    result = httpd_cgi_ret(a1, v9, v8, 4);
  }
  return result;
}
// 49469C: variable 'v2' is possibly undefined
// 64918C: using guessed type void *off_64918C;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

