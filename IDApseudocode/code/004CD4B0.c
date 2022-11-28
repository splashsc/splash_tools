struct hostent *gethostbyname(const char *name)
{
  MEMORY[0](name);
  return (struct hostent *)start_user_deltime();
}
// 4CD4C0: using guessed type int start_user_deltime(void);

