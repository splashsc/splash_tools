int prepare_upgrade()
{
  MEMORY[0]();
  return nvram_get();
}
// 4CE630: using guessed type int nvram_get(void);

