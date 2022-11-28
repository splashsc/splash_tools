time_t time(time_t *timer)
{
  FILE *v1; // $a0
  int v2; // $a1
  int v3; // $a2

  MEMORY[0](timer);
  return fseek(v1, v2, v3);
}
// 4CDF89: variable 'v1' is possibly undefined
// 4CDF89: variable 'v2' is possibly undefined
// 4CDF89: variable 'v3' is possibly undefined

