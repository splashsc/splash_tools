struct dirent *readdir(DIR *dirp)
{
  MEMORY[0](dirp);
  return (struct dirent *)term_proc();
}
// 4CE770: using guessed type int term_proc(void);

