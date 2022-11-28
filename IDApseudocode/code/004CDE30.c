int strcasecmp(const char *s1, const char *s2)
{
  MEMORY[0](s1, s2);
  return start_auto_reboot();
}
// 4CDE40: using guessed type int start_auto_reboot(void);

