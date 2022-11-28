int fputs(const char *s, FILE *stream)
{
  MEMORY[0](s, stream);
  return split_string2();
}
// 4CCCA0: using guessed type int split_string2(void);

