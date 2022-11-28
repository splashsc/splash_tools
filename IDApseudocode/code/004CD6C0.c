ssize_t read(int fd, void *buf, size_t nbytes)
{
  MEMORY[0](fd, buf, nbytes);
  return jhl_nv_is_def();
}
// 4CD6D0: using guessed type int jhl_nv_is_def(void);

