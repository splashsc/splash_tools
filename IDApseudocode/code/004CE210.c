int kill(__pid_t pid, int sig)
{
  MEMORY[0](pid, sig);
  return get_upfile_version_flag();
}
// 4CE220: using guessed type int get_upfile_version_flag(void);

