void perror(const char *s)
{
  MEMORY[0](s);
  reset_wtclient_rzgl_parm();
}
// 4CD590: using guessed type int reset_wtclient_rzgl_parm(void);

