ssize_t sendto(int fd, const void *buf, size_t n, int flags, const struct sockaddr *addr, socklen_t addr_len)
{
  int v6; // $a0
  const void *v7; // $a1
  size_t v8; // $a2
  int v9; // $a3

  MEMORY[0](fd, buf, n, flags);
  return ipv6_router_set_to_server(v6, v7, v8, v9, addr, addr_len);
}
// 4CD799: variable 'v6' is possibly undefined
// 4CD799: variable 'v7' is possibly undefined
// 4CD799: variable 'v8' is possibly undefined
// 4CD799: variable 'v9' is possibly undefined

