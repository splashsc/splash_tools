int dup2(int fd, int fd2)
{
  MEMORY[0](fd, fd2);
  return user_num_get();
}
// 4CCE40: using guessed type int user_num_get(void);

