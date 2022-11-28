int jhl_httpd_reset_user()
{
  nvram_unset("http_user_lock");
  set_jhttpd_info(
    (int)gl_httpd_user,
    (int)gl_httpd_password,
    &gl_httpd_port,
    (int)gl_httpd_admin,
    (int)gl_httpd_adminpwd,
    &gl_httpd_tggl_port,
    &gl_httpd_https_port);
  return killall("ac_server", 17);
}
// 666174: using guessed type __int16 gl_httpd_https_port;
// 666176: using guessed type __int16 gl_httpd_tggl_port;
// 666178: using guessed type __int16 gl_httpd_port;
// 6A8178: using guessed type int __fastcall killall(_DWORD, _DWORD);
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);

