int StrToIpaddr()
{
  struct sysinfo *v0; // $a0

  MEMORY[0]();
  return sysinfo(v0);
}
// 4CE339: variable 'v0' is possibly undefined

