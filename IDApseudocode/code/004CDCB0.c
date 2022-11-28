int power_off()
{
  int v0; // $a0
  int v1; // $a1

  MEMORY[0]();
  return fcntl(v0, v1);
}
// 4CDCB9: variable 'v0' is possibly undefined
// 4CDCB9: variable 'v1' is possibly undefined

