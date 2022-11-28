char *fgets(char *s, int n, FILE *stream)
{
  MEMORY[0](s, n, stream);
  return (char *)restart_wan_auto_conn();
}
// 4CC9B0: using guessed type int restart_wan_auto_conn(void);

