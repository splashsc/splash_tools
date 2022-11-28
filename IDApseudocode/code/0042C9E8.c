int __fastcall httpd_conn_epoll_add(int a1)
{
  int *v1; // $v1
  int v2; // $v0
  bool v3; // dc
  int v4; // $a0
  int v5; // $v1
  int v6; // $a2
  struct pollfd *v7; // $a3

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
      fprintf(stderr, "socket '%d' add  poll false\n", *(_DWORD *)(a1 + 205416));
      return -1;
    }
  }
  v4 = a1 + 196608;
  v5 = curfds;
  v6 = *(_DWORD *)(v4 + 8808);
  v7 = &array_conn + v2;
  *(_DWORD *)(v4 + 8820) = v2;
  v7->fd = v6;
  v7->events = 1;
  if ( v2 >= v5 )
    curfds = v2 + 1;
  return 0;
}
// 67D0A4: using guessed type int curfds;
// 6997E8: using guessed type int dword_6997E8;

