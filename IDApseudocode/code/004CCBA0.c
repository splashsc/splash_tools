char *strerror(int errnum)
{
  void *v1; // $a0
  char *result; // $v0

  MEMORY[0](errnum);
  free(v1);
  return result;
}
// 4CCBA9: variable 'v1' is possibly undefined

