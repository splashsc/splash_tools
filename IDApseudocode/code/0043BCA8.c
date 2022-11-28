int __fastcall sub_43BCA8(int a1)
{
  char *v2; // $v0
  char *v3; // $s1
  void **v4; // $s0
  int v5; // $s2
  void **v6; // $fp
  const char *v7; // $v0
  int v8; // $a0
  int v9; // $v0
  char *v10; // $a0
  int v11; // $a2
  const char *v13; // $v0
  unsigned int v14; // $a2
  char v15[256]; // [sp+20h] [-100h] BYREF

  _mem_malloc(102400, "weblogin_data", 2123);
  v3 = v2;
  if ( v2 )
  {
    strcpy(v2, "{\"code\":0,\"error\":\"\",\"data\":[");
    qmemcpy(v2, "{\"code\":0,\"error", 16);
    v4 = (void **)user_login_list;
    if ( user_login_list == &user_login_list )
    {
      v9 = 28;
      v8 = 29;
      v5 = 29;
LABEL_7:
      if ( v3[v9] != 44 )
        goto LABEL_8;
    }
    else
    {
      v5 = 29;
      do
      {
        v6 = (void **)*v4;
        v7 = (const char *)IpaddrToStr(v15, v4 + 2);
        v5 += sprintf(&v3[v5], "{\"ip\":\"%s\",\"tm\":%u,\"user\":%u},", v7, v4[7], v4[8]);
        v4 = v6;
        if ( v5 >= 102337 )
        {
          v8 = v5;
          v9 = v5 - 1;
          goto LABEL_7;
        }
      }
      while ( v6 != &user_login_list );
      v8 = v5;
      if ( v5 <= 0 || v3[v5 - 1] != 44 )
        goto LABEL_8;
    }
    v8 = --v5;
LABEL_8:
    v10 = &v3[v8];
    *v10 = 0;
    v11 = snprintf(v10, 102400 - v5, "]}");
    if ( v11 >= 102400 - v5 )
      v11 = 102399 - v5;
    return httpd_cgi_ret(a1, v3, v5 + v11, 8);
  }
  v13 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), 102400);
  v14 = snprintf(v15, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
  if ( v14 >= 0x100 )
    v14 = 255;
  return httpd_cgi_ret(a1, v15, v14, 4);
}
// 43BD0C: variable 'v2' is possibly undefined
// 642A04: using guessed type __int16 word_642A04;
// 66B5E0: using guessed type void *user_login_list;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A843C: using guessed type int __fastcall IpaddrToStr(_DWORD, _DWORD);

