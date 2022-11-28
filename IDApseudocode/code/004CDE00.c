ssize_t write(int fd, const void *buf, size_t n)
{
  MEMORY[0](fd, buf, n);
  return duolan_do();
}
// 4CDE10: using guessed type int duolan_do(void);

