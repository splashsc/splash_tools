int __fastcall sub_42C640(int a1, int a2)
{
  bool v2; // dc

  v2 = debug_level <= 0;
  *(&array_conn.fd + 2 * a2) = -1;
  if ( !v2 )
    printf("%s:%d %s[%d]: del sockfd:%d, poll_i:%d\n", "httpd_epoll_del", 858, "httpd_epoll_del", 858, a1, a2);
  return 0;
}
// 67D0BC: using guessed type int debug_level;

