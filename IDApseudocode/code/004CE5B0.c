int getsockopt(int fd, int level, int optname, void *optval, socklen_t *optlen)
{
  int v5; // $a0
  int v6; // $a1
  int v7; // $a2
  void *v8; // $a3

  MEMORY[0](fd, level, optname, optval);
  return get_sn(v5, v6, v7, v8, optlen);
}
// 4CE5B9: variable 'v5' is possibly undefined
// 4CE5B9: variable 'v6' is possibly undefined
// 4CE5B9: variable 'v7' is possibly undefined
// 4CE5B9: variable 'v8' is possibly undefined

