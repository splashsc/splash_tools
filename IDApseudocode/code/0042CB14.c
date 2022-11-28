int __fastcall httpd_conn_epoll_write(int a1)
{
  int v1; // $v0

  *(&array_conn.events + 4 * *(_DWORD *)(a1 + 205428)) = 5;
  v1 = jiffies_get();
  mod_timer(a1 + 205540, v1 + 5000);
  return 0;
}
// 6A81A4: using guessed type int __fastcall mod_timer(_DWORD, _DWORD);
// 6A8824: using guessed type int jiffies_get(void);

