char *asctime(const struct tm *tp)
{
  int v1; // $a0
  void *v2; // $a1
  size_t v3; // $a2
  int v4; // $a3

  MEMORY[0](tp);
  return (char *)recv(v1, v2, v3, v4);
}
// 4CD079: variable 'v1' is possibly undefined
// 4CD079: variable 'v2' is possibly undefined
// 4CD079: variable 'v3' is possibly undefined
// 4CD079: variable 'v4' is possibly undefined

