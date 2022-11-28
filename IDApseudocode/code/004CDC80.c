uint32_t htonl(uint32_t hostlong)
{
  char *v1; // $a0
  int v2; // $a1
  char *v3; // $a2

  MEMORY[0](hostlong);
  return snprintf(v1, v2, v3);
}
// 4CDC89: variable 'v1' is possibly undefined
// 4CDC89: variable 'v2' is possibly undefined
// 4CDC89: variable 'v3' is possibly undefined

