int stat(const char *file, struct stat *buf)
{
  uint16_t v2; // $a0

  MEMORY[0](file, buf);
  return ntohs(v2);
}
// 4CCB49: variable 'v2' is possibly undefined

