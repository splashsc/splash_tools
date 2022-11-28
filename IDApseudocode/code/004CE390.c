int connect(int fd, const struct sockaddr *addr, socklen_t len)
{
  int v3; // $a0
  fd_set *v4; // $a1
  fd_set *v5; // $a2
  fd_set *v6; // $a3
  struct timeval *v8; // [sp+10h] [+10h]

  MEMORY[0](fd, addr, len);
  return select(v3, v4, v5, v6, v8);
}
// 4CE399: variable 'v3' is possibly undefined
// 4CE399: variable 'v4' is possibly undefined
// 4CE399: variable 'v5' is possibly undefined
// 4CE399: variable 'v6' is possibly undefined

