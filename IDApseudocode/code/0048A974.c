int __fastcall sub_48A974(int a1)
{
  char *v1; // $v0
  int v3; // $v0
  int v4; // $a2
  void *v5; // $a2
  int v7; // $a0
  int v8; // $a1
  int v9; // $a2
  const char *v10; // $v0
  unsigned int v11; // $a2
  char v12[200]; // [sp+20h] [-D4h] BYREF
  void *v13; // [sp+E8h] [-Ch] BYREF

  v1 = httpd_get_parm(a1, "fn");
  read_file_buf(v1, (int *)&v13);
  if ( v3 >= 0 )
  {
    v5 = v13;
    *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
    return httpd_send_mime_file(a1, "application/binary-file", v5, v3);
  }
  if ( v3 == -3 )
  {
    v8 = *(unsigned __int8 *)(a1 + 210102);
    v9 = -1;
    v7 = 4;
  }
  else
  {
    v7 = 12;
    if ( v3 == -2 )
    {
      v10 = (const char *)_GET_LANG_TEXT(38, *(unsigned __int8 *)(a1 + 210102), v4);
      goto LABEL_7;
    }
    v8 = *(unsigned __int8 *)(a1 + 210102);
    v9 = (int)"not fn";
  }
  v10 = (const char *)_GET_LANG_TEXT(v7, v8, v9);
LABEL_7:
  v11 = snprintf(v12, 200, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v10);
  if ( v11 >= 0xC8 )
    v11 = 199;
  return httpd_cgi_ret(a1, v12, v11, 4);
}
// 48A9C4: variable 'v3' is possibly undefined
// 48AAB8: variable 'v4' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);

