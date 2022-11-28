int __fastcall httpd_user_check_cookie(int a1, const char *a2, const char *a3)
{
  int v6; // $s0
  int result; // $v0

  strlcpy(a1 + 210032, a2, 64);
  if ( gl_httpd_high_admin_en && !strcmp(a2, gl_httpd_high_admin) && !strcmp(a3, gl_httpd_high_adminpwd_md5) )
  {
    jhl_user_login_add((_DWORD *)(a1 + 205460), (void *)3, a2, 1);
    result = 5;
  }
  else if ( !gl_httpd_admin_en || (v6 = strcmp(a2, gl_httpd_admin)) != 0 )
  {
    if ( gl_httpd_user_en )
    {
      v6 = strcmp(a2, gl_httpd_user);
      if ( !v6 )
      {
        if ( !strcmp(a3, gl_httpd_password_md5) )
        {
          jhl_user_login_add((_DWORD *)(a1 + 205460), (void *)2, a2, 1);
          v6 = 3;
        }
        return v6;
      }
    }
    v6 = gl_httpd_guest_user_en;
    if ( !gl_httpd_guest_user_en )
      return v6;
    v6 = strcmp(a2, gl_httpd_guest_user);
    if ( !v6 )
    {
      if ( !strcmp(a3, gl_httpd_guest_pwd_md5) )
        v6 = 2;
      return v6;
    }
    result = 0;
  }
  else
  {
    if ( strcmp(a3, gl_httpd_adminpwd_md5) )
      return v6;
    jhl_user_login_add((_DWORD *)(a1 + 205460), (void *)1, a2, 1);
    result = 4;
  }
  return result;
}
// 666170: using guessed type int gl_httpd_admin_en;
// 67D090: using guessed type int gl_httpd_guest_user_en;
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 67D098: using guessed type int gl_httpd_user_en;
// 6A8480: using guessed type int __fastcall strlcpy(_DWORD, _DWORD, _DWORD);

