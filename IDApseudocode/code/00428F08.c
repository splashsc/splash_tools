int __fastcall usb_httpd_check_user(int a1, int a2)
{
  if ( *(_BYTE *)(a1 + 43) == 1 && *(_DWORD *)(a1 + 205588) >= a2 )
    return 0;
  if ( usb_httpd_user_auth_cookie(a1) )
    return -1;
  if ( *(_DWORD *)(a1 + 205588) < a2 )
  {
    usb_httpd_send_login_html(a1);
    return -1;
  }
  return 0;
}

