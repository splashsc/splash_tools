int __fastcall pppoe_bridge_check_token(int a1)
{
  char *v2; // $v0
  char *v3; // $s3
  int v4; // $v0
  int v6; // $s0
  unsigned int v7; // $v0
  char v8[128]; // [sp+20h] [-100h] BYREF
  char v9[64]; // [sp+A0h] [-80h] BYREF
  char v10[64]; // [sp+E0h] [-40h] BYREF

  memset(v10, 0, sizeof(v10));
  memset(v9, 0, sizeof(v9));
  memset(v8, 0, sizeof(v8));
  v3 = httpd_get_parm(a1, "token");
  v2 = httpd_get_parm(a1, "random");
  if ( v3 && v2 )
  {
    v4 = snprintf(v8, 128, "%s+%s", gl_httpd_pppoe_br_md5, v2);
    pppoe_bridge_md5(v9, (int)v8, v4);
    if ( !strcmp(v3, v9) )
      return 0;
    v6 = -3;
  }
  else
  {
    v6 = -2;
  }
  v7 = snprintf(v10, 64, "{\"code\":%d,\"error\":\"%s\",\"data\":null}", 1, "token error");
  if ( v7 >= 0x40 )
    v7 = 63;
  httpd_cgi_ret(a1, v10, v7, 4);
  return v6;
}

