int __fastcall httpd_proxy_client_close(int a1)
{
  int v1; // $s0

  v1 = a1 + 196608;
  if ( !**(_DWORD **)(a1 + 205440) )
    return httpd_conn_close((int *)a1);
  if ( *(_DWORD *)(a1 + 205424) != -1 )
  {
    httpd_conn_epoll_del_proxy(a1);
    close_socket(*(_DWORD *)(v1 + 8816));
    *(_DWORD *)(v1 + 8816) = -1;
  }
  httpd_conn_epoll_write(a1);
  return 0;
}

