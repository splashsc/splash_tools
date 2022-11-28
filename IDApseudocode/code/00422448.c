int __fastcall httpds_send_redirect(int a1, const char *a2)
{
  unsigned int v3; // $v0
  char v5[4100]; // [sp+18h] [-1004h] BYREF

  v3 = snprintf(
         v5,
         4096,
         "HTTP/1.1 302 Found\r\n"
         "Location: %s\r\n"
         "Content-Type: text/html\r\n"
         "Pragma: no-cache\r\n"
         "Cache-Control: no-cache\r\n"
         "Expires: 0\r\n"
         "Content-Length: 0\r\n"
         "\r\n",
         a2);
  *(_BYTE *)(a1 + 41) = 2;
  *(_DWORD *)(a1 + 205392) = 0;
  if ( v3 >= 0x1000 )
    v3 = 4095;
  if ( !httpd_send_data_alloc(a1, v5, v3) && (!*(_DWORD *)(a1 + 205380) || *(_DWORD *)(a1 + 209984)) )
    httpd_conn_close((int *)a1);
  return 0;
}

