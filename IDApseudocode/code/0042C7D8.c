int __fastcall httpd_conn_epoll_write_pty(int a1)
{
  *(&array_conn.events + 4 * *(_DWORD *)(a1 + 205432)) = 5;
  return 0;
}

