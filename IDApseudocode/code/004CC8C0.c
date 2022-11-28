size_t fread(void *ptr, size_t size, size_t n, FILE *stream)
{
  return MEMORY[0](ptr, size, n, stream);
}

