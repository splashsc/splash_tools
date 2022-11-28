int __fastcall ai_sn_data(int a1)
{
  char *v2; // $v0
  const char *v3; // $s2
  const char *v4; // $v0
  const char *v5; // $s3
  unsigned int v6; // $a2
  const char *v8; // $v0
  const char *v9; // $s2
  char v10[1028]; // [sp+28h] [-404h] BYREF

  memset(v10, 0, 0x400u);
  v2 = httpd_get_parm(a1, "callback");
  if ( !v2 )
  {
    v9 = (const char *)get_sn();
    v8 = (const char *)custom_device_name();
    v6 = snprintf(v10, 1024, "{\"sn\":\"%s\",\"model\":\"%s\",\"version\":\"%s\"}", v9, v8, wayos_version);
    if ( v6 < 0x400 )
      return httpd_cgi_ret(a1, v10, v6, 4);
LABEL_5:
    v6 = 1023;
    return httpd_cgi_ret(a1, v10, v6, 4);
  }
  v3 = v2;
  v5 = (const char *)get_sn();
  v4 = (const char *)custom_device_name();
  v6 = snprintf(v10, 1024, "%s({\"sn\":\"%s\",\"model\":\"%s\",\"version\":\"%s\"})", v3, v5, v4, wayos_version);
  if ( v6 >= 0x400 )
    goto LABEL_5;
  return httpd_cgi_ret(a1, v10, v6, 4);
}
// 6A81D8: using guessed type int get_sn(void);
// 6A86E4: using guessed type int custom_device_name(void);

