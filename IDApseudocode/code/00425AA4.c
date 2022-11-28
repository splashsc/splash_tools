int __fastcall httpd_send_redirect(int a1, const char *a2)
{
  char *v4; // $v0
  char *v5; // $s0
  const char *v6; // $a3
  char *v7; // $v0
  int v8; // $v0

  if ( !strncmp(a2, "http", 4u) )
  {
    _mem_malloc(20480, "httpd_send_redirect", 6028);
    v5 = v4;
    if ( !v4 )
      return 0;
    v6 = "";
  }
  else
  {
    _mem_malloc(20480, "httpd_send_redirect", 6028);
    v5 = v7;
    if ( !v7 )
      return 0;
    v6 = "http://";
  }
  v8 = snprintf(
         v5,
         20480,
         "HTTP/1.1 302 Found\r\n"
         "Location: %s%s\r\n"
         "Content-Type: text/html;charset=gb2312\r\n"
         "Pragma: no-cache\r\n"
         "Cache-Control: no-cache\r\n"
         "Connection: close\r\n"
         "Server: HTTPD 1.0\r\n"
         "Content-Length: 0\r\n"
         "\r\n",
         v6,
         a2);
  *(_BYTE *)(a1 + 41) = 2;
  *(_DWORD *)(a1 + 205392) = 0;
  if ( v8 >= 20480 )
    v8 = 20479;
  if ( !httpd_send_data_alloc(a1, v5, v8) && !*(_DWORD *)(a1 + 205380) )
    httpd_conn_close((int *)a1);
  _mem_free(v5);
  return 0;
}
// 425B14: variable 'v4' is possibly undefined
// 425B40: variable 'v7' is possibly undefined

