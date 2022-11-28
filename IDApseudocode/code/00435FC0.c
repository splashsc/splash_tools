int __fastcall httpd_proxy_server_close(int a1)
{
  int v1; // $s0

  v1 = a1 + 196608;
  if ( !**(_DWORD **)(a1 + 205444) )
    return httpd_conn_close((int *)a1);
  if ( *(_DWORD *)(a1 + 205416) != -1 )
  {
    httpd_conn_epoll_del(a1);
    close_socket(*(_DWORD *)(v1 + 8808));
    *(_DWORD *)(v1 + 8808) = -1;
  }
  httpd_conn_epoll_write_proxy(a1);
  return 0;
}

