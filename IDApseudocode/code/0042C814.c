int __fastcall httpd_conn_epoll_del_pty(int a1)
{
  *(&array_conn.fd + 2 * *(_DWORD *)(a1 + 205432)) = -1;
  return 0;
}

