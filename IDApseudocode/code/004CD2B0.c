int sigaction(int sig, const struct sigaction *act, struct sigaction *oact)
{
  int v3; // $a0
  int v4; // $a1

  MEMORY[0](sig, act, oact);
  return listen(v3, v4);
}
// 4CD2B9: variable 'v3' is possibly undefined
// 4CD2B9: variable 'v4' is possibly undefined

