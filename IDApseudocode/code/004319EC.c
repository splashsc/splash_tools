int __fastcall httpd_user_check(int a1, const char *a2, const char *a3)
{
  _DWORD *v6; // $a0
  int v7; // $s0
  int result; // $v0

  if ( gl_httpd_high_admin_en && !strcmp(a2, gl_httpd_high_admin) && !strcmp(a3, gl_httpd_high_adminpwd) )
  {
    jhl_user_login_add((_DWORD *)(a1 + 205460), (void *)3, a2, 1);
    result = 5;
  }
  else if ( gl_httpd_admin_en && !strcmp(a2, gl_httpd_admin) && !strcmp(a3, gl_httpd_adminpwd) )
  {
    jhl_user_login_add((_DWORD *)(a1 + 205460), (void *)1, a2, 1);
    result = 4;
  }
  else
  {
    if ( gl_httpd_user_en && !strcmp(a2, gl_httpd_user) && !strcmp(a3, gl_httpd_password) )
    {
      v6 = (_DWORD *)(a1 + 205460);
      v7 = 3;
      jhl_user_login_add(v6, (void *)2, a2, 1);
      return v7;
    }
    v7 = gl_httpd_guest_user_en;
    if ( !gl_httpd_guest_user_en )
      return v7;
    v7 = strcmp(a2, gl_httpd_guest_user);
    if ( v7 )
    {
      result = 0;
    }
    else
    {
      if ( strcmp(a3, gl_httpd_guest_pwd) )
        return v7;
      result = 2;
    }
  }
  return result;
}
// 666170: using guessed type int gl_httpd_admin_en;
// 67D090: using guessed type int gl_httpd_guest_user_en;
// 67D094: using guessed type int gl_httpd_high_admin_en;
// 67D098: using guessed type int gl_httpd_user_en;

