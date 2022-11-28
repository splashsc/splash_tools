int open(const char *file, int oflag, ...)
{
  MEMORY[0](file, oflag);
  return user_delall();
}
// 4CE2C0: using guessed type int user_delall(void);

