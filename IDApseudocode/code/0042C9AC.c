int __fastcall httpd_conn_epoll_del_proxy(int a1)
{
  *(&array_conn.fd + 2 * *(_DWORD *)(a1 + 205436)) = -1;
  return 0;
}

