int __fastcall sub_474130(int a1)
{
  int v1; // $a2
  int v3; // $a1
  int v4; // $a0
  const char *v5; // $v0
  unsigned int v6; // $a2
  int v8; // $v0
  void *v9; // $a2
  char v10[256]; // [sp+20h] [-10Ch] BYREF
  void *v11; // [sp+120h] [-Ch] BYREF

  if ( check_usb_state() )
  {
    read_file_buf("/tmp/mnt/sda1/auth_html/auth.tar.gz", (int *)&v11);
    if ( v8 >= 0 )
    {
      v9 = v11;
      *(_DWORD *)(a1 + 32) &= 0xFFFFFFFD;
      return httpd_send_mime_file(a1, "application/binary-file", v9, v8);
    }
    if ( v8 == -3 )
    {
      v5 = (const char *)_GET_LANG_TEXT(4, *(unsigned __int8 *)(a1 + 210102), -1);
      goto LABEL_4;
    }
    v3 = *(unsigned __int8 *)(a1 + 210102);
    if ( v8 == -2 )
      v4 = 143;
    else
      v4 = 144;
  }
  else
  {
    v3 = *(unsigned __int8 *)(a1 + 210102);
    v4 = 142;
  }
  v5 = (const char *)_GET_LANG_TEXT(v4, v3, v1);
LABEL_4:
  v6 = snprintf(v10, 256, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v5);
  if ( v6 >= 0x100 )
    v6 = 255;
  return httpd_cgi_ret(a1, v10, v6, 4);
}
// 47417C: variable 'v1' is possibly undefined
// 474204: variable 'v8' is possibly undefined
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

