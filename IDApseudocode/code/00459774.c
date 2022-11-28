int __fastcall sub_459774(int a1)
{
  void *v2; // $v0
  void *v3; // $s3
  int v4; // $s0
  int result; // $v0
  int v6; // $s0
  const char *v7; // $v0
  unsigned int v8; // $v0
  char v9[256]; // [sp+20h] [-140h] BYREF
  char v10; // [sp+120h] [-40h] BYREF
  char v11[63]; // [sp+121h] [-3Fh] BYREF

  _mem_malloc(0x100000, "wayosparm_cfg", 277);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v9, "/tmp/backupXXXXXX");
    wys_mkstemp(v9);
    dword_66FD28 = (int)v9;
    sprintf(&v10, ">%s.msg", v9);
    eval(off_66FD20, &v10, 0, 0);
    if ( f_exists(v9) )
    {
      v6 = do_file(v9, (int)v3, 0x100000);
      unlink(v9);
      unlink(v11);
      result = httpd_send_mime_file(a1, "application/binary-file", v3, v6);
    }
    else
    {
      v4 = do_file(v11, (int)v3, 0x100000);
      unlink(v11);
      result = httpd_cgi_ret(a1, (char *)v3, v4, 8);
    }
  }
  else
  {
    v7 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 0x100000);
    v8 = snprintf(v9, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v7);
    if ( v8 >= 0x100 )
      v8 = 255;
    result = httpd_cgi_ret(a1, v9, v8, 4);
  }
  return result;
}
// 4597C4: variable 'v2' is possibly undefined
// 66FD20: using guessed type char *off_66FD20[2];
// 66FD28: using guessed type int dword_66FD28;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A846C: using guessed type int __fastcall f_exists(_DWORD);
// 6A863C: using guessed type int __fastcall wys_mkstemp(_DWORD);

