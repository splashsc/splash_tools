__sighandler_t signal(int sig, __sighandler_t handler)
{
  MEMORY[0](sig, handler);
  return (__sighandler_t)mr_parm_default();
}
// 4CE380: using guessed type int mr_parm_default(void);

