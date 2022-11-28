ssize_t recvfrom(int fd, void *buf, size_t n, int flags, struct sockaddr *addr, socklen_t *addr_len)
{
  int v6; // $a0
  void *v7; // $a1
  size_t v8; // $a2
  int v9; // $a3

  MEMORY[0](fd, buf, n, flags);
  return jhl_parm_set(v6, v7, v8, v9, addr, addr_len);
}
// 4CE119: variable 'v6' is possibly undefined
// 4CE119: variable 'v7' is possibly undefined
// 4CE119: variable 'v8' is possibly undefined
// 4CE119: variable 'v9' is possibly undefined

