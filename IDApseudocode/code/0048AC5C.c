int __fastcall sub_48AC5C(int a1, int a2, int a3)
{
  int v3; // $s0
  int v4; // $s3
  char *v7; // $v0
  char *v9; // $v0
  char *v10; // $s2
  int v11; // $a2
  const char *v12; // $a2
  const char *v13; // $v0
  unsigned int v14; // $v0
  const char *v16; // $v0
  unsigned int v17; // $a2
  char v18[1028]; // [sp+20h] [-404h] BYREF

  v3 = a1 + 196608;
  v4 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( !v7 || (v10 = v7, (v9 = find_file_end(a1, v7, *(_DWORD *)(v3 + 8956) + v4 - (_DWORD)v7)) == 0) )
  {
    v12 = "Error reading file";
    goto LABEL_6;
  }
  if ( v9 - v10 != f_write(a2, v10, v9 - v10, 0, a3) )
  {
    v12 = "Error writing temporary file";
LABEL_6:
    v13 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v12);
    v14 = snprintf(v18, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
    if ( v14 >= 0x400 )
      v14 = 1023;
    httpd_cgi_ret(a1, v18, v14, 4);
    return -1;
  }
  v16 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(v3 + 13494), v11);
  v17 = snprintf(v18, 1024, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v16);
  if ( v17 >= 0x400 )
    v17 = 1023;
  httpd_cgi_ret(a1, v18, v17, 4);
  return 0;
}
// 48ACB8: variable 'v7' is possibly undefined
// 48ADC8: variable 'v11' is possibly undefined
// 6A8204: using guessed type int __fastcall f_write(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

