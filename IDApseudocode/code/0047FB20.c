int __fastcall sub_47FB20(int a1)
{
  int result; // $v0
  int v3; // $a2
  const char *v4; // $v0
  unsigned int v5; // $s1
  char v6[128]; // [sp+20h] [-80h] BYREF

  if ( check_usb_state() )
    return auth_html_upload_do_rcv(a1);
  memset(v6, 0, sizeof(v6));
  v4 = (const char *)_GET_LANG_TEXT(142, *(unsigned __int8 *)(a1 + 210102), v3);
  v5 = snprintf(v6, 128, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v4);
  sync();
  if ( v5 >= 0x80 )
    result = httpd_cgi_ret(a1, v6, 127, 4);
  else
    result = httpd_cgi_ret(a1, v6, v5, 4);
  return result;
}
// 47FBB0: variable 'v3' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

