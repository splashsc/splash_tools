struct tm *gmtime(const time_t *timer)
{
  const char *v1; // $a0

  MEMORY[0](timer);
  return (struct tm *)opendir(v1);
}
// 4CDA99: variable 'v1' is possibly undefined

