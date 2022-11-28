int memcmp(const void *s1, const void *s2, size_t n)
{
  MEMORY[0](s1, s2, n);
  return wt_client_restart();
}
// 4CDFF0: using guessed type int wt_client_restart(void);

