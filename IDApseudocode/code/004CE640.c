int *__errno_location(void)
{
  MEMORY[0]();
  return (int *)nvram_get_int();
}
// 4CE650: using guessed type int nvram_get_int(void);

