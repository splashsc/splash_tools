ssize_t __fastcall jhl_parm_set(int fd, void *buf, size_t n, int flags, struct sockaddr *addr, socklen_t *addr_len)
{
  MEMORY[0](fd, buf, n, flags);
  return crypt_sha1();
}
// 4CE130: using guessed type int crypt_sha1(void);

