int strncmp(const char *s1, const char *s2, size_t n)
{
  MEMORY[0](s1, s2, n);
  return restart_shenji_ctrl();
}
// 4CCAD0: using guessed type int restart_shenji_ctrl(void);

