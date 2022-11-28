int __fastcall httpd_conn_epoll_del(int a1)
{
  *(&array_conn.fd + 2 * *(_DWORD *)(a1 + 205428)) = -1;
  return 0;
}

