int close(int fd)
{
  MEMORY[0](fd);
  return httpd_check_sys_freemem2();
}
// 4CC9E0: using guessed type int httpd_check_sys_freemem2(void);

