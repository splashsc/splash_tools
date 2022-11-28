int __fastcall read_file_asp(int a1, int a2, const char *a3)
{
  const char *v4; // $s1
  int v5; // $v0
  int v6; // $a2
  void *v7; // $a2
  int v9; // $a0
  int v10; // $a1
  int v11; // $a2
  const char *v12; // $v0
  unsigned int v13; // $a2
  char v14[200]; // [sp+20h] [-D4h] BYREF
  void *v15; // [sp+E8h] [-Ch] BYREF

  if ( a3 )
    v4 = a3;
  else
    v4 = "application/binary-file";
  read_file_buf((const char *)a2, (int *)&v15);
  if ( v5 >= 0 )
  {
    v7 = v15;
    *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
    return httpd_send_mime_file(a1, v4, v7, v5);
  }
  if ( v5 == -3 )
  {
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = -1;
    v9 = 4;
  }
  else
  {
    v9 = 12;
    if ( v5 == -2 )
    {
      v12 = (const char *)_GET_LANG_TEXT(38, *(unsigned __int8 *)(a1 + 210102), v6);
      goto LABEL_9;
    }
    v10 = *(unsigned __int8 *)(a1 + 210102);
    v11 = (int)"not fn";
  }
  v12 = (const char *)_GET_LANG_TEXT(v9, v10, v11);
LABEL_9:
  v13 = snprintf(v14, 200, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v12);
  if ( v13 >= 0xC8 )
    v13 = 199;
  return httpd_cgi_ret(a1, v14, v13, 4);
}
// 48AB2C: variable 'v5' is possibly undefined
// 48AC2C: variable 'v6' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

