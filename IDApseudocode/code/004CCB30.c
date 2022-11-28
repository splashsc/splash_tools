char *strrchr(const char *s, int c)
{
  const char *v2; // $a0
  struct stat *v3; // $a1

  MEMORY[0](s, c);
  return (char *)stat(v2, v3);
}
// 4CCB39: variable 'v2' is possibly undefined
// 4CCB39: variable 'v3' is possibly undefined

