int fflush(FILE *stream)
{
  int v1; // $a0
  int v2; // $a1

  MEMORY[0](stream);
  return dup2(v1, v2);
}
// 4CCE29: variable 'v1' is possibly undefined
// 4CCE29: variable 'v2' is possibly undefined

