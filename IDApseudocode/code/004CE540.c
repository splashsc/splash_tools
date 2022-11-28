int rename(const char *old, const char *a2)
{
  MEMORY[0](old, a2);
  return nvparm_find_str();
}
// 4CE550: using guessed type int nvparm_find_str(void);

