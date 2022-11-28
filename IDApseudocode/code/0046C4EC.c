int __fastcall sub_46C4EC(int a1)
{
  char *v2; // $v0
  const char *v3; // $v0
  char *v4; // $s1
  int v5; // $v0
  int result; // $v0
  const char *v7; // $v0
  unsigned int v8; // $v0
  char v9[260]; // [sp+20h] [-104h] BYREF

  _mem_malloc(0x200000, "acc_txt", 2909);
  if ( v2 )
  {
    v4 = v2;
    v3 = (const char *)nvram_get("accAll2");
    if ( !v3 )
      v3 = " ";
    v5 = snprintf(v4, 0x200000, "%s", v3);
    *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
    if ( v5 >= 0x200000 )
      v5 = 0x1FFFFF;
    result = httpd_send_mime_file(a1, "application/binary-file", v4, v5);
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
// 46C52C: variable 'v2' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

