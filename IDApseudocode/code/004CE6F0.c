int strcmp(const char *s1, const char *s2)
{
  MEMORY[0](s1, s2);
  return check_ip_is_wanip();
}
// 4CE700: using guessed type int check_ip_is_wanip(void);

