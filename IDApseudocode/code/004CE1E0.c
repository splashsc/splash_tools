__off_t lseek(int fd, __off_t offset, int whence)
{
  MEMORY[0](fd, offset, whence);
  return set_dns_more_hitype_to_kernel();
}
// 4CE1F0: using guessed type int set_dns_more_hitype_to_kernel(void);

