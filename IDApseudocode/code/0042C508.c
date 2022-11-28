int __fastcall sub_42C508(int a1)
{
  int *v1; // $v0
  int v2; // $s0
  bool v3; // dc

  v1 = &dword_6997E8;
  v2 = 1;
  while ( 1 )
  {
    v3 = *v1 >= 0;
    v1 += 2;
    if ( !v3 )
      break;
    if ( ++v2 == 5120 )
    {
      fprintf(stderr, "socket '%d' add  poll false\n", a1);
      return -1;
    }
  }
  v3 = debug_level <= 0;
  *(&array_conn.fd + 2 * v2) = a1;
  if ( !v3 )
    printf("%s:%d %s[%d]: add sockfd:%d, poll_i:%d\n", "httpd_epoll_add", 837, "httpd_epoll_add", 837, a1, v2);
  v3 = v2 < curfds;
  *(&array_conn.events + 4 * v2) = 1;
  if ( !v3 )
    curfds = v2 + 1;
  return v2;
}
// 67D0A4: using guessed type int curfds;
// 67D0BC: using guessed type int debug_level;
// 6997E8: using guessed type int dword_6997E8;

