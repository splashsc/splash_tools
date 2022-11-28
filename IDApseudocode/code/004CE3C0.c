int sscanf(char *format, ...)
{
  int v1; // $a0
  const struct sockaddr *v2; // $a1
  socklen_t v3; // $a2

  MEMORY[0](format);
  return bind(v1, v2, v3);
}
// 4CE3C9: variable 'v1' is possibly undefined
// 4CE3C9: variable 'v2' is possibly undefined
// 4CE3C9: variable 'v3' is possibly undefined

