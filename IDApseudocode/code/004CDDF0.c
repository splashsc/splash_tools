ssize_t f_read_string()
{
  int v0; // $a0
  const void *v1; // $a1
  size_t v2; // $a2

  MEMORY[0]();
  return write(v0, v1, v2);
}
// 4CDDF9: variable 'v0' is possibly undefined
// 4CDDF9: variable 'v1' is possibly undefined
// 4CDDF9: variable 'v2' is possibly undefined

