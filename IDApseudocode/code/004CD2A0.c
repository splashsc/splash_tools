int nvparm_get_str()
{
  int v0; // $a0
  const struct sigaction *v1; // $a1
  struct sigaction *v2; // $a2

  MEMORY[0]();
  return sigaction(v0, v1, v2);
}
// 4CD2A9: variable 'v0' is possibly undefined
// 4CD2A9: variable 'v1' is possibly undefined
// 4CD2A9: variable 'v2' is possibly undefined

