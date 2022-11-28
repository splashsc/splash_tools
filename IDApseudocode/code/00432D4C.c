int __fastcall httpd_cgi_user_check(const char *a1, const char *a2, _DWORD *a3)
{
  int v6; // $s0

  memset(httpd_set_cookie, 0, sizeof(httpd_set_cookie));
  if ( gl_httpd_high_admin_en && !strcmp(a1, gl_httpd_high_admin) && !strcmp(a2, gl_httpd_high_adminpwd) )
  {
    sprintf(httpd_set_cookie, "vue_userid=%s,vue_passwd=%s", a1, gl_httpd_high_adminpwd_md5);
    *a3 = 5;
    return 1;
  }
  if ( gl_httpd_admin_en )
  {
    v6 = strcmp(a1, gl_httpd_admin);
    if ( !v6 )
    {
      if ( !strcmp(a2, gl_httpd_adminpwd) )
      {
        sprintf(httpd_set_cookie, "vue_userid=%s,vue_passwd=%s", a1, gl_httpd_adminpwd_md5);
        *a3 = 4;
        v6 = 1;
      }
      return v6;
    }
  }
  if ( gl_httpd_user_en )
  {
    v6 = strcmp(a1, gl_httpd_user);
    if ( !v6 )
    {
      if ( !strcmp(a2, gl_httpd_password) )
      {
        sprintf(httpd_set_cookie, "vue_userid=%s,vue_passwd=%s", a1, gl_httpd_password_md5);
        *a3 = 3;
        v6 = 1;
      }
      return v6;
    }
  }
  v6 = gl_httpd_guest_user_en;
  if ( !gl_httpd_guest_user_en )
    return v6;
  v6 = strcmp(a1, gl_httpd_guest_user);
  if ( !v6 )
  {
    if ( !strcmp(a2, gl_httpd_guest_pwd) )
    {
      sprintf(httpd_set_cookie, "vue_userid=%s,vue_passwd=%s", a1, gl_httpd_guest_pwd_md5);
      *a3 = 2;
      v6 = 1;
    }
    return v6;
  }
  return 0;
}
// 666170: using guessed type int gl_httpd_admin_en;
// 67D090: using guessed type int gl_httpd_guest_user_en;
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 67D098: using guessed type int gl_httpd_user_en;

