int fseek(FILE *stream, int off, int whence)
{
  MEMORY[0](stream, off, whence);
  return init_timer();
}
// 4CDFA0: using guessed type int init_timer(void);

