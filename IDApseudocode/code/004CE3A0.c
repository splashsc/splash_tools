int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout)
{
  struct pollfd *v5; // $a0
  nfds_t v6; // $a1
  int v7; // $a2

  MEMORY[0](nfds, readfds, writefds, exceptfds);
  return poll(v5, v6, v7);
}
// 4CE3A9: variable 'v5' is possibly undefined
// 4CE3A9: variable 'v6' is possibly undefined
// 4CE3A9: variable 'v7' is possibly undefined

