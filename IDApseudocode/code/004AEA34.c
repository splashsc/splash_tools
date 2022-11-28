int __fastcall sub_4AEA34(int a1)
{
  int v1; // $s0
  int v2; // $s3
  char *v3; // $v0
  char *v5; // $v0
  char *v6; // $s1
  signed int v7; // $v0
  int v8; // $s0
  const char *v9; // $a2
  const char *v10; // $v0
  unsigned int v11; // $v0
  int v13; // $a2
  const char *v14; // $v0
  unsigned int v15; // $a2
  char v16[1028]; // [sp+20h] [-404h] BYREF

  v1 = a1 + 196608;
  v2 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( !v3 || (v6 = v3, (v5 = find_file_end(a1, v3, *(_DWORD *)(v1 + 8956) + v2 - (_DWORD)v3)) == 0) )
  {
    v9 = "Error reading file";
    goto LABEL_6;
  }
  v8 = v5 - v6;
  v7 = strlen(v6);
  if ( v7 < v8 )
  {
    v8 = v7;
    if ( v7 >= 1025 )
      goto LABEL_5;
  }
  else if ( v8 >= 1025 )
  {
LABEL_5:
    v9 = "file too long err!";
LABEL_6:
    v10 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v9);
    v11 = snprintf(v16, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
    if ( v11 >= 0x400 )
      v11 = 1023;
    return httpd_cgi_ret(a1, v16, v11, 4);
  }
  memset(v16, 0, 0x400u);
  memcpy(v16, v6, v8);
  v14 = (const char *)_GET_LANG_TEXT(72, *(unsigned __int8 *)(a1 + 210102), v13);
  v15 = snprintf(v16, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
  if ( v15 >= 0x400 )
    v15 = 1023;
  return httpd_cgi_ret(a1, v16, v15, 4);
}
// 4AEA80: variable 'v3' is possibly undefined
// 4AEBDC: variable 'v13' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

