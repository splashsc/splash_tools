int __fastcall sub_487F0C(int a1)
{
  char *v2; // $v0
  int v3; // $v0
  char *v4; // $s1
  int result; // $v0
  const char *v6; // $v0
  unsigned int v7; // $v0
  char v8[260]; // [sp+20h] [-104h] BYREF

  _mem_malloc(0x200000, "url_member_txt", 474);
  if ( v2 )
  {
    v4 = v2;
    v3 = url_member_get_file(v2, 0x200000u);
    *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
    result = httpd_send_mime_file(a1, "application/binary-file", v4, v3);
  }
  else
  {
    v6 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x200000);
    v7 = snprintf(v8, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v6);
    if ( v7 >= 0x100 )
      v7 = 255;
    result = httpd_cgi_ret(a1, v8, v7, 4);
  }
  return result;
}
// 487F4C: variable 'v2' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

