int __fastcall sub_4742B4(int a1)
{
  void *v2; // $v0
  char *v3; // $s2
  int v4; // $v0
  void *v5; // $s1
  int result; // $v0
  const char *v7; // $v0
  unsigned int v8; // $v0
  char v9[256]; // [sp+20h] [-100h] BYREF

  v3 = httpd_get_parm(a1, "id");
  _mem_malloc(0x200000, "users_txt", 1893);
  if ( v2 )
  {
    v5 = v2;
    v4 = user_get_file_csv(v2, 0x200000, v3);
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
// 474310: variable 'v2' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A86F0: using guessed type int __fastcall user_get_file_csv(_DWORD, _DWORD, _DWORD);

