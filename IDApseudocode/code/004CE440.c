int SSL_CIPHER_get_version()
{
  const char *v0; // $a0
  char **v1; // $a1
  int v2; // $a2

  MEMORY[0]();
  return strtol(v0, v1, v2);
}
// 4CE449: variable 'v0' is possibly undefined
// 4CE449: variable 'v1' is possibly undefined
// 4CE449: variable 'v2' is possibly undefined

