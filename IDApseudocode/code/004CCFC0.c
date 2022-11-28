int usleep(__useconds_t useconds)
{
  unsigned int v1; // $a0
  int result; // $v0

  MEMORY[0](useconds);
  srand(v1);
  return result;
}
// 4CCFC9: variable 'v1' is possibly undefined

