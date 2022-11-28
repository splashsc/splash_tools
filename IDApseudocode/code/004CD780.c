ssize_t __fastcall SSL_accept(int fd, int level, int optname, const void *optval, socklen_t optlen, socklen_t a6)
{
  int v6; // $a0
  const void *v7; // $a1
  size_t v8; // $a2
  int v9; // $a3

  MEMORY[0](fd, level, optname, optval);
  return sendto(v6, v7, v8, v9, (const struct sockaddr *)optlen, a6);
}
// 4CD789: variable 'v6' is possibly undefined
// 4CD789: variable 'v7' is possibly undefined
// 4CD789: variable 'v8' is possibly undefined
// 4CD789: variable 'v9' is possibly undefined

