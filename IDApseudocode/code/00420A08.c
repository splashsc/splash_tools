int __fastcall httpd_send_data(int a1)
{
  int v2; // $v0
  int v3; // $a1
  int v4; // $v0

  if ( *(_DWORD *)(a1 + 209984) )
    v2 = https_ssl_write(a1);
  else
    v2 = send(*(_DWORD *)(a1 + 205416), *(const void **)(a1 + 205368), *(_DWORD *)(a1 + 205380), 0);
  if ( v2 >= 0 )
  {
    v3 = *(_DWORD *)(a1 + 205368) + v2;
    v4 = *(_DWORD *)(a1 + 205380) - v2;
    *(_DWORD *)(a1 + 205368) = v3;
    *(_DWORD *)(a1 + 205380) = v4;
    if ( v4 <= 0 || !httpd_conn_epoll_write(a1) )
      return 0;
  }
  httpd_conn_close((int *)a1);
  return -1;
}

