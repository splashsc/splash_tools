int poll(struct pollfd *fds, nfds_t nfds, int timeout)
{
  char *v3; // $a0

  MEMORY[0](fds, nfds, timeout);
  return sscanf(v3);
}
// 4CE3B9: variable 'v3' is possibly undefined

