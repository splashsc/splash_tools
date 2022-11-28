int setsockopt(int fd, int level, int optname, const void *optval, socklen_t optlen)
{
  int v5; // $a0
  int v6; // $a1
  int v7; // $a2
  const void *v8; // $a3

  MEMORY[0](fd, level, optname, optval);
  return SSL_accept(v5, v6, v7, v8, optlen);
}
// 4CD779: variable 'v5' is possibly undefined
// 4CD779: variable 'v6' is possibly undefined
// 4CD779: variable 'v7' is possibly undefined
// 4CD779: variable 'v8' is possibly undefined

