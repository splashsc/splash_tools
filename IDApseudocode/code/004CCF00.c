__pid_t waitpid(__pid_t pid, int *stat_loc, int options)
{
  MEMORY[0](pid, stat_loc, options);
  return __gtsf2();
}
// 4CCF10: using guessed type int __gtsf2(void);

