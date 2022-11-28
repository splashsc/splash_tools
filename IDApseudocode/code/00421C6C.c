int __fastcall usb_httpd_user_check_cookie(int a1, int a2, const char *a3)
{
  bool v5; // dc
  int result; // $v0

  if ( !nvram_match_def("usb_husername", a2) || (v5 = strcmp(a3, gl_usb_hpassword_md5) != 0, result = 2, v5) )
  {
    result = nvram_match_def("usb_username", a2);
    if ( result )
      result = strcmp(a3, gl_usb_password_md5) == 0;
  }
  return result;
}
// 6A83E4: using guessed type int __fastcall nvram_match_def(_DWORD, _DWORD);

