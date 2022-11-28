void *memset(void *s, int c, size_t n)
{
  MEMORY[0](s, c, n);
  return (void *)stop_proxy_auto_send_email();
}
// 4CD290: using guessed type int stop_proxy_auto_send_email(void);

