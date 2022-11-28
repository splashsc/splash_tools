int __fastcall sub_473268(int a1)
{
  char *v1; // $v0
  const char *v3; // $s0
  const char *v4; // $v0
  char *v5; // $v1
  int v6; // $t1
  int v7; // $t0
  int v8; // $a3
  int v9; // $a2
  char v11[132]; // [sp+18h] [-84h] BYREF

  v1 = httpd_get_parm(a1, "fn");
  if ( v1 )
  {
    v3 = v1;
    if ( !strcmp(v1, "notify_htm")
      || !strcmp(v3, "auth_htm")
      || !strcmp(v3, "ddate_htm")
      || !strcmp(v3, "install_htm")
      || !strcmp(v3, "jdauth_htm")
      || !strcmp(v3, "ddate_notify_htm")
      || !strcmp(v3, "userinfo_htm")
      || !strcmp(v3, "second_auth_htm") )
    {
      nvram_unset(v3);
      nvram_commit();
    }
    if ( !strcmp(v3, "auth_pic") )
    {
      system("rm -rf /tmp/auth_pic");
      if ( check_usb_state() )
        system("rm -rf /tmp/mnt/sda1/auth_pic");
    }
    else if ( !strcmp(v3, "auth_html") )
    {
      system("rm -rf /tmp/auth_html");
      if ( check_usb_state() )
        system("rm -rf /tmp/mnt/sda1/auth_html");
    }
  }
  v4 = "{\"code\":0,\"error\":\"\",\"data\":null}";
  v5 = v11;
  do
  {
    v6 = *(_DWORD *)v4;
    v7 = *((_DWORD *)v4 + 1);
    v8 = *((_DWORD *)v4 + 2);
    v9 = *((_DWORD *)v4 + 3);
    v4 += 16;
    *(_DWORD *)v5 = v6;
    *((_DWORD *)v5 + 1) = v7;
    *((_DWORD *)v5 + 2) = v8;
    *((_DWORD *)v5 + 3) = v9;
    v5 += 16;
  }
  while ( v4 != "}" );
  *(_WORD *)v5 = *(_WORD *)v4;
  return httpd_cgi_ret(a1, v11, 33, 4);
}
// 6A8540: using guessed type int __fastcall nvram_unset(_DWORD);
// 6A87C4: using guessed type int nvram_commit(void);
// 6A88E0: using guessed type int check_usb_state(void);

