char *strchr(const char *s, int c)
{
  MEMORY[0](s, c);
  return (char *)user_mod();
}
// 4CCA20: using guessed type int user_mod(void);

