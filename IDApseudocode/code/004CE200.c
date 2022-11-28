int miitool_data_buf()
{
  __pid_t v0; // $a0
  int v1; // $a1

  MEMORY[0]();
  return kill(v0, v1);
}
// 4CE209: variable 'v0' is possibly undefined
// 4CE209: variable 'v1' is possibly undefined

