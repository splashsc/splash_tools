int puts(const char *s)
{
  MEMORY[0](s);
  return start_version_upgrade_auto();
}
// 4CDB30: using guessed type int start_version_upgrade_auto(void);

