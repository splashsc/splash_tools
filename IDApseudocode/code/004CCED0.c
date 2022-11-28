int fprintf(void *stream, char *format, ...)
{
  MEMORY[0](stream, format);
  return wan_proto_check();
}
// 4CCEE0: using guessed type int wan_proto_check(void);

