ssize_t send(int fd, const void *buf, size_t n, int flags)
{
  MEMORY[0](fd, buf, n, flags);
  return dual_getIfMac();
}
// 4CE6E0: using guessed type int dual_getIfMac(void);

