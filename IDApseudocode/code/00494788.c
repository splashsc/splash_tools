int __fastcall sub_494788(int a1)
{
  char *v1; // $v0
  int v3; // $s4
  char *v4; // $v0
  char *v5; // $s3
  char *v6; // $s2
  char *v7; // $v0
  int v8; // $a2
  const char *v9; // $v0
  unsigned int v10; // $v0
  const char *v12; // $a2
  const char *v13; // $v0
  unsigned int v14; // $v0
  char v15[512]; // [sp+20h] [-200h] BYREF

  v1 = httpd_get_parm(a1, (char *)&off_64918C);
  if ( v1
    && (v3 = *(_DWORD *)(a1 + 205364), v5 = v1, find_file_head(a1, *(const char **)(a1 + 205564)), (v6 = v4) != 0)
    && (v7 = find_file_end(a1, v4, *(_DWORD *)(a1 + 205564) + v3 - (_DWORD)v4)) != 0 )
  {
    *v7 = 0;
    if ( dns_more_dnstype_item_buf(v6, 0, v5) >= 0 )
    {
      v9 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v8);
      v10 = snprintf(v15, 512, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v9);
      if ( v10 >= 0x200 )
        httpd_cgi_ret(a1, v15, 511, 4);
      else
        httpd_cgi_ret(a1, v15, v10, 4);
      return 0;
    }
    v12 = "Error DNS member";
  }
  else
  {
    v12 = "Error reading file";
  }
  v13 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v12);
  v14 = snprintf(v15, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v13);
  if ( v14 >= 0x200 )
    v14 = 511;
  httpd_cgi_ret(a1, v15, v14, 4);
  return -1;
}
// 4947FC: variable 'v4' is possibly undefined
// 494850: variable 'v8' is possibly undefined
// 64918C: using guessed type void *off_64918C;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A87F0: using guessed type int __fastcall dns_more_dnstype_item_buf(_DWORD, _DWORD, _DWORD);

