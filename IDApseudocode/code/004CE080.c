int ioctl(int fd, unsigned int request, ...)
{
  MEMORY[0](fd, request);
  return set_rule_to_kernel();
}
// 4CE090: using guessed type int set_rule_to_kernel(void);

