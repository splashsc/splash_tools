int __fastcall sub_494170(int a1)
{
  int v1; // $s0
  int v2; // $s3
  char *v3; // $v0
  char *v5; // $v0
  char *v6; // $s2
  void *v7; // $v0
  int v8; // $a2
  void *v9; // $s0
  int v10; // $a0
  const char *v11; // $v0
  unsigned int v12; // $v0
  int result; // $v0
  const char *v14; // $v0
  unsigned int v15; // $v0
  char v16[516]; // [sp+20h] [-204h] BYREF

  v1 = a1 + 196608;
  v2 = *(_DWORD *)(a1 + 205364);
  find_file_head(a1, *(const char **)(a1 + 205564));
  if ( v3 && (v6 = v3, (v5 = find_file_end(a1, v3, *(_DWORD *)(v1 + 8956) + v2 - (_DWORD)v3)) != 0) )
  {
    *v5 = 0;
    dns_more_dnstype_buf(v6, 0);
    _mem_malloc(0x200000, "dns_more_memberfile_cgi", 820);
    v9 = v7;
    if ( v7 )
    {
      if ( dns_more_dnstype_get(v7, 0x200000) )
        jhl_parm_set("dns_more_dnstype", v9);
      else
        jhl_parm_set("dns_more_dnstype", "");
      jhl_parm_commit(v10);
      _mem_free(v9);
    }
    v11 = (const char *)_GET_LANG_TEXT(34, *(unsigned __int8 *)(a1 + 210102), v8);
    v12 = snprintf(v16, 512, "{\"code\":0,\"error\":\"\",\"message\":\"%s\",\"data\":null}", v11);
    if ( v12 >= 0x200 )
      v12 = 511;
    httpd_cgi_ret(a1, v16, v12, 4);
    result = 0;
  }
  else
  {
    v14 = (const char *)_GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), "Error reading file");
    v15 = snprintf(v16, 512, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v14);
    if ( v15 >= 0x200 )
      v15 = 511;
    httpd_cgi_ret(a1, v16, v15, 4);
    result = -1;
  }
  return result;
}
// 4941BC: variable 'v3' is possibly undefined
// 494220: variable 'v7' is possibly undefined
// 49426C: variable 'v10' is possibly undefined
// 4942A0: variable 'v8' is possibly undefined
// 6A8180: using guessed type int __fastcall jhl_parm_commit(_DWORD);
// 6A8308: using guessed type int __fastcall jhl_parm_set(_DWORD, _DWORD);
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A83E8: using guessed type int __fastcall dns_more_dnstype_get(_DWORD, _DWORD);
// 6A85B8: using guessed type int __fastcall dns_more_dnstype_buf(_DWORD, _DWORD);

