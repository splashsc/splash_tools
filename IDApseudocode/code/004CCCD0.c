int nvram_getdef_int()
{
  MEMORY[0]();
  return jiffies_get();
}
// 4CCCE0: using guessed type int jiffies_get(void);

