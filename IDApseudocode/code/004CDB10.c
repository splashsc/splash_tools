size_t fwrite(const void *ptr, size_t size, size_t n, FILE *s)
{
  const char *v4; // $a0

  MEMORY[0](ptr, size, n, s);
  return puts(v4);
}
// 4CDB19: variable 'v4' is possibly undefined

