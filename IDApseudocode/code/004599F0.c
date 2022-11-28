int __fastcall sub_4599F0(int a1)
{
  int v1; // $s0
  int v2; // $s3
  char *v3; // $v0
  char *v5; // $v0
  char *v6; // $s2
  char *v7; // $s0
  const char *v8; // $a2
  const char *v9; // $v0
  unsigned int v10; // $a2
  int v12; // $a2
  const char *v13; // $v0
  char v14[1024]; // [sp+20h] [-54Ch] BYREF
  char v15[256]; // [sp+420h] [-14Ch] BYREF
  char v16; // [sp+520h] [-4Ch] BYREF
  char v17[63]; // [sp+521h] [-4Bh] BYREF
  const char *v18; // [sp+560h] [-Ch]

  v1 = a1 + 196608;
  v2 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( !v3
    || (v6 = v3, v5 = find_file_end(a1, v3, *(_DWORD *)(v1 + 8956) + v2 - (_DWORD)v3), v7 = (char *)(v5 - v6), !v5) )
  {
    v8 = "Error reading file";
    goto LABEL_5;
  }
  if ( (unsigned int)(v7 - 64) >= 0x1FFFC1 )
  {
    v8 = "Invalid file";
    goto LABEL_5;
  }
  strcpy(v15, "/tmp/restoreXXXXXX");
  wys_mkstemp(v15);
  if ( v7 != (char *)f_write(v15, v6, v7, 0, 384) )
  {
    v8 = "Error writing temporary file";
LABEL_5:
    if ( v15[0] )
    {
      v18 = v8;
      unlink(v15);
      v8 = v18;
    }
    v9 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v8);
    v10 = snprintf(v14, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v9);
    if ( v10 < 0x400 )
      return httpd_cgi_ret(a1, v14, v10, 4);
LABEL_14:
    v10 = 1023;
    return httpd_cgi_ret(a1, v14, v10, 4);
  }
  prepare_upgrade();
  dword_66FD18 = (int)v15;
  sprintf(&v16, ">%s.msg", v15);
  if ( eval(off_66FD10, &v16, 0, 0) )
  {
    do_file(v17, (int)v14, 1024);
    unlink(v17);
  }
  if ( v15[0] )
    unlink(v15);
  nvram_commit();
  jhl_gl_reboot_timer(2000);
  v13 = (const char *)_GET_LANG_TEXT(48, *(unsigned __int8 *)(a1 + 210102), v12);
  v10 = snprintf(v14, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v13);
  if ( v10 >= 0x400 )
    goto LABEL_14;
  return httpd_cgi_ret(a1, v14, v10, 4);
}
// 459A3C: variable 'v3' is possibly undefined
// 459BD8: variable 'v12' is possibly undefined
// 66FD10: using guessed type char *off_66FD10[2];
// 66FD18: using guessed type int dword_66FD18;
// 6A81C0: using guessed type int prepare_upgrade(void);
// 6A8204: using guessed type int __fastcall f_write(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83DC: using guessed type int __fastcall eval(_DWORD, _DWORD, _DWORD, _DWORD);
// 6A863C: using guessed type int __fastcall wys_mkstemp(_DWORD);
// 6A87C4: using guessed type int nvram_commit(void);

