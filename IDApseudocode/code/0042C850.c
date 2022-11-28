int __fastcall httpd_conn_epoll_add_proxy(_DWORD *a1)
{
  int *v1; // $v1
  int v2; // $v0
  bool v3; // dc
  int v4; // $a1
  int v5; // $t3
  int v6; // $t0
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
      fprintf(stderr, "socket '%d' add  poll false\n", a1[51356]);
      return -1;
    }
  }
  v4 = curfds;
  v5 = a1[51356];
  v6 = fbss;
  a1[51359] = v2;
  v7 = &array_conn + v2;
  v7->fd = v5;
  fbss = (int)(a1 + 4);
  *(_DWORD *)(v6 + 4) = a1 + 4;
  a1[4] = v6;
  a1[5] = &fbss;
  v7->events = 1;
  if ( v2 >= v4 )
    curfds = v2 + 1;
  return 0;
}
// 67D050: using guessed type int fbss;
// 67D0A4: using guessed type int curfds;
// 6997E8: using guessed type int dword_6997E8;

