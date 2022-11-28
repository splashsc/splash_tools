int __fastcall usb_httpd_cgi_user_check(const char *a1, int a2)
{
  int result; // $v0

  memset(httpd_set_cookie, 0, sizeof(httpd_set_cookie));
  if ( nvram_match_def("usb_husername", a1) && nvram_match_def("usb_hpasswd", a2) )
  {
    sprintf(httpd_set_cookie, "usb_userid=%s,usb_passwd=%s", a1, gl_usb_hpassword_md5);
    result = 2;
  }
  else if ( nvram_match_def("usb_username", a1) && nvram_match_def("usb_passwd", a2) )
  {
    sprintf(httpd_set_cookie, "usb_userid=%s,usb_passwd=%s", a1, gl_usb_password_md5);
    result = 1;
  }
  else
  {
    result = 0;
  }
  return result;
}
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);

