int __fastcall httpd_send_auth_pic_file(int a1)
{
  int v2; // $s1
  const char *v3; // $v0
  const char *v5; // $v0
  char v6[256]; // [sp+18h] [-2A0h] BYREF
  int v7[64]; // [sp+118h] [-1A0h] BYREF
  struct stat v8; // [sp+218h] [-A0h] BYREF

  memset(v7, 0, sizeof(v7));
  v2 = -1;
  if ( strncmp(*(const char **)(a1 + 44), "/auth_pic/auth.", 0xFu) )
    return v2;
  if ( stat("/tmp/auth_pic", &v8) && check_usb_state() )
  {
    memset(v6, 0, sizeof(v6));
    v5 = (const char *)nvram_get("auth_pic_ext");
    if ( !v5 )
      v5 = ".jpg";
    snprintf(v6, 256, "/tmp/mnt/sda1/auth_pic/auth%s", v5);
    if ( !stat(v6, &v8) )
      system("cp -rf /tmp/mnt/sda1/auth_pic /tmp/auth_pic");
  }
  v3 = (const char *)nvram_get("auth_pic_ext");
  if ( !v3 )
    v3 = ".jpg";
  snprintf((char *)v7, 256, "/tmp/auth_pic/auth%s", v3);
  v2 = stat((const char *)v7, &v8);
  if ( !v2 )
  {
    httpd_send_big_file(a1, (int)v7, v8.st_atim.tv_sec);
    return v2;
  }
  v7[0] = -808864562;
  v7[1] = -1127371852;
  LOWORD(v7[2]) = -21306;
  BYTE2(v7[2]) = 0;
  httpd_cgi_ret(a1, (char *)v7, 10, 4);
  return 0;
}
// 6A81BC: using guessed type int __fastcall nvram_get(_DWORD);
// 6A88E0: using guessed type int check_usb_state(void);

