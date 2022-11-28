int __fastcall httpd_conn_epoll_read_pty(int a1)
{
  *(&array_conn.events + 4 * *(_DWORD *)(a1 + 205432)) = 1;
  return 0;
}

