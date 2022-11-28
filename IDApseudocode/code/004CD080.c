ssize_t recv(int fd, void *buf, size_t n, int flags)
{
  MEMORY[0](fd, buf, n, flags);
  return SSL_get_version();
}
// 4CD090: using guessed type int SSL_get_version(void);

