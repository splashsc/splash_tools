int httpd_unix_init()
{
  int v0; // $v0
  int v1; // $s1
  const char *v2; // $v1
  char *v3; // $v0
  int v4; // $a0
  int v5; // $a1
  int v6; // $a0
  int result; // $v0
  struct sockaddr v8[7]; // [sp+20h] [-8Ch] BYREF
  int v9[2]; // [sp+90h] [-1Ch] BYREF
  int v10; // [sp+98h] [-14h] BYREF
  int v11; // [sp+9Ch] [-10h] BYREF
  socklen_t optlen; // [sp+A0h] [-Ch] BYREF
  int v13[2]; // [sp+A4h] [-8h] BYREF

  v13[0] = 1;
  optlen = 0;
  v11 = 0x100000;
  v10 = 0x100000;
  v0 = socket(1, 1, 0);
  if ( v0 < 0 )
  {
    printf("%s[%d]: httpd_unix_init socket fialed\n", "httpd_unix_init", 21);
    result = -1;
  }
  else
  {
    v8[0].sa_family = 1;
    v1 = v0;
    setsockopt(v0, 0xFFFF, 4097, &v10, 4u);
    setsockopt(v1, 0xFFFF, 4098, &v11, 4u);
    optlen = 4;
    v13[0] = 0;
    getsockopt(v1, 0xFFFF, 4097, v13, &optlen);
    optlen = 4;
    v13[0] = 0;
    getsockopt(v1, 0xFFFF, 4098, v13, &optlen);
    v9[0] = 3;
    v9[1] = 0;
    setsockopt(v1, 0xFFFF, 4101, v9, 8u);
    setsockopt(v1, 0xFFFF, 4102, v9, 8u);
    create_dir2("/tmp/ac_server/jhttpd_local.sock");
    unlink("/tmp/ac_server/jhttpd_local.sock");
    v2 = "/tmp/ac_server/jhttpd_local.sock";
    v3 = v8[0].sa_data;
    do
    {
      v4 = *((_DWORD *)v2 + 1);
      *(_DWORD *)v3 = *(_DWORD *)v2;
      *((_DWORD *)v3 + 1) = v4;
      v5 = *((_DWORD *)v2 + 2);
      *((_DWORD *)v3 + 1) = v4;
      *((_DWORD *)v3 + 2) = v5;
      v6 = *((_DWORD *)v2 + 3);
      *((_DWORD *)v3 + 2) = v5;
      *((_DWORD *)v3 + 3) = v6;
      v2 += 16;
      *((_DWORD *)v3 + 3) = v6;
      v3 += 16;
    }
    while ( v2 != "" );
    *v3 = *v2;
    if ( bind(v1, v8, 0x6Eu) < 0 )
    {
      printf("%s[%d]: httpd_unix_init bind fialed\n", "httpd_unix_init", 46);
      result = -1;
    }
    else
    {
      setnonblocking(v1);
      result = 0;
      gl_httpd_unix_fd = v1;
    }
  }
  return result;
}
// 66B5F0: using guessed type int gl_httpd_unix_fd;
// 6A8584: using guessed type int __fastcall create_dir2(_DWORD);

