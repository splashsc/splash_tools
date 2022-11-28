size_t strftime(char *s, size_t maxsize, const char *format, const struct tm *tp)
{
  MEMORY[0](s, maxsize, format, tp);
  return start_dhcp_server();
}
// 4CDA60: using guessed type int start_dhcp_server(void);

