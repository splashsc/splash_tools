int __fastcall httpds_send_redirect_ipmac(int a1, const char *a2, const char *a3)
{
  bool v6; // dc
  int v7; // $v0
  unsigned int v8; // $v0
  char v10[4100]; // [sp+20h] [-1004h] BYREF

  v6 = strchr(a2, 63) == 0;
  v7 = 63;
  if ( !v6 )
    v7 = 38;
  v8 = snprintf(
         v10,
         4096,
         "HTTP/1.1 302 Found\r\n"
         "Location: %s%c%s\r\n"
         "Content-Type: text/html\r\n"
         "Pragma: no-cache\r\n"
         "Cache-Control: no-cache\r\n"
         "Expires: 0\r\n"
         "Content-Length: 0\r\n"
         "\r\n",
         a2,
         v7,
         a3);
  *(_BYTE *)(a1 + 41) = 2;
  *(_DWORD *)(a1 + 205392) = 0;
  if ( v8 >= 0x1000 )
    v8 = 4095;
  if ( httpd_send_data_alloc(a1, v10, v8) || *(_DWORD *)(a1 + 205380) )
    return 0;
  httpd_conn_close((int *)a1);
  return 0;
}

