int mem_init_fun()
{
  jiffies_init();
  init_timers_cpu();
  httpd_mem_init();
  httpd_file_init();
  httpd_file_ext_init();
  httpd_cgi_ext_init();
  return 0;
}
// 6A81C4: using guessed type int jiffies_init(void);
// 6A834C: using guessed type int init_timers_cpu(void);

