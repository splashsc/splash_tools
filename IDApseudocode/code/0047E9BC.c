int __fastcall org_html(int a1, int a2)
{
  int v3; // $v0
  int *v5; // $v0
  int v6; // $a2
  int v7; // $a0
  char *v8; // $a2
  signed int v9; // $a3
  int v10; // $v0
  int result; // $v0
  const char *v12; // $v0
  unsigned int v13; // $v0
  char v14[204]; // [sp+20h] [-CCh] BYREF

  v3 = get_name_hash((unsigned __int8 *)a2);
  v5 = httpd_get_file((const char *)a2, v3);
  if ( v5 )
  {
    v7 = *(_DWORD *)v5[8];
    v8 = *(char **)(v7 + 4);
    v9 = *(_DWORD *)(v7 + 8);
    v10 = *(_DWORD *)(a1 + 36) | 0x4000;
    *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
    *(_DWORD *)(a1 + 44) = a2;
    *(_DWORD *)(a1 + 36) = v10;
    result = httpd_send_html_file(a1, "application/binary-file", v8, v9);
  }
  else
  {
    v12 = (const char *)_GET_LANG_TEXT(138, *(unsigned __int8 *)(a1 + 210102), v6);
    v13 = snprintf(v14, 200, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v12);
    if ( v13 >= 0xC8 )
      v13 = 199;
    result = httpd_cgi_ret(a1, v14, v13, 4);
  }
  return result;
}
// 47EA7C: variable 'v6' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

