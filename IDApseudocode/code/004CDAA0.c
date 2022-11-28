DIR *opendir(const char *name)
{
  MEMORY[0](name);
  return (DIR *)ct_low_limit_check();
}
// 4CDAB0: using guessed type int ct_low_limit_check(void);

