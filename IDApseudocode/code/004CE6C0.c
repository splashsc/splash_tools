void *malloc(size_t size)
{
  int v1; // $a0
  const void *v2; // $a1
  size_t v3; // $a2
  int v4; // $a3

  MEMORY[0](size);
  return (void *)send(v1, v2, v3, v4);
}
// 4CE6C9: variable 'v1' is possibly undefined
// 4CE6C9: variable 'v2' is possibly undefined
// 4CE6C9: variable 'v3' is possibly undefined
// 4CE6C9: variable 'v4' is possibly undefined

