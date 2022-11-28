void srandom(unsigned int seed)
{
  MEMORY[0](seed);
  run_timers();
}
// 4CE030: using guessed type int run_timers(void);

