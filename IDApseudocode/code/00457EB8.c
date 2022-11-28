int __fastcall spqos_txt(const char *a1, int a2)
{
  char *v4; // $v0
  const char *v5; // $v0
  char *v6; // $s1
  int v7; // $v0
  int result; // $v0
  const char *v9; // $v0
  unsigned int v10; // $v0
  char v11[256]; // [sp+20h] [-114h] BYREF
  int v12[5]; // [sp+120h] [-14h] BYREF

  v12[0] = 0;
  v12[1] = 0;
  v12[2] = 0;
  v12[3] = 0;
  snprintf((char *)v12, 16, "sqos_%s", a1);
  _mem_malloc(0x200000, "spqos_txt", 674);
  if ( v4 )
  {
    v6 = v4;
    v5 = (const char *)nvram_get(v12);
    if ( !v5 )
      v5 = " ";
    v7 = sprintf(v6, "%s%s", a1, v5);
    *(_DWORD *)(a2 + 32) &= 0xFFFFFFFD;
    result = httpd_send_mime_file(a2, "application/binary-file", v6, v7);
  }
  else
  {
    v9 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a2 + 210102), 0x200000);
    v10 = snprintf(v11, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 >= 0x100 )
      v10 = 255;
    result = httpd_cgi_ret(a2, v11, v10, 4);
  }
  return result;
}
// 457F38: variable 'v4' is possibly undefined
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

