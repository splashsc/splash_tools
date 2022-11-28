int __fastcall sub_4B2B98(int a1)
{
  char *v2; // $s3
  int v3; // $a2
  char *v4; // $s1
  int v5; // $a1
  int v6; // $a0
  char *v7; // $v0
  unsigned int v8; // $v0
  char *v10; // $v0
  int v11; // [sp+10h] [-494h]
  char v12[1024]; // [sp+20h] [-484h] BYREF
  char v13[132]; // [sp+420h] [-84h] BYREF

  memset(v13, 0, 0x80u);
  v2 = httpd_find_ext_name(*(const char **)(a1 + 44));
  v4 = httpd_get_parm(a1, "path");
  usb_httpd_conn_check_user(a1);
  if ( *(_BYTE *)(a1 + 43) == 1 )
  {
    if ( !v4 || (v10 = strstr(v4, "/usb/")) == 0 || (v4 = v10 + 5, v10 == (char *)-5) )
      v4 = "";
    if ( check_usb_state() )
      return usb_upload_do_rcv2(a1);
    v5 = *(unsigned __int8 *)(a1 + 210102);
    v6 = 186;
  }
  else
  {
    v5 = *(unsigned __int8 *)(a1 + 210102);
    v6 = 2;
  }
  v7 = (char *)_GET_LANG_TEXT(v6, v5, v3);
  strcpy(v13, v7);
  sync();
  if ( v2 && !strcmp(v2, (const char *)&off_4CFE60) )
  {
    v11 = _GET_LANG_TEXT(33, *(unsigned __int8 *)(a1 + 210102), v13);
    v8 = snprintf(v12, 1024, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, v11);
  }
  else
  {
    v8 = snprintf(
           v12,
           1024,
           "<html><head><script type='text/javascript'>function init(){alert('%s');window.parent.location.href='/usb/%s';"
           "}</script><body onLoad='init();'></body></head></html>",
           v13,
           v4);
  }
  if ( v8 >= 0x400 )
    v8 = 1023;
  return httpd_cgi_ret(a1, v12, v8, 4);
}
// 4B2C4C: variable 'v3' is possibly undefined
// 4CFE60: using guessed type void *off_4CFE60;
// 6A8318: using guessed type int __fastcall _GET_LANG_TEXT(_DWORD, _DWORD, _DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

