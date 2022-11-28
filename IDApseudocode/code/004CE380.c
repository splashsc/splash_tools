int mr_parm_default()
{
  int v0; // $a0
  const struct sockaddr *v1; // $a1
  socklen_t v2; // $a2

  MEMORY[0]();
  return connect(v0, v1, v2);
}
// 4CE389: variable 'v0' is possibly undefined
// 4CE389: variable 'v1' is possibly undefined
// 4CE389: variable 'v2' is possibly undefined

