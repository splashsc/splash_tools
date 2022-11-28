__pid_t get_lans_num()
{
  __pid_t v0; // $a0
  int *v1; // $a1
  int v2; // $a2

  MEMORY[0]();
  return waitpid(v0, v1, v2);
}
// 4CCEF9: variable 'v0' is possibly undefined
// 4CCEF9: variable 'v1' is possibly undefined
// 4CCEF9: variable 'v2' is possibly undefined

