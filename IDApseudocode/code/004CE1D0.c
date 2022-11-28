int inet_aton(const char *cp, struct in_addr *inp)
{
  int v2; // $a0
  __off_t v3; // $a1
  int v4; // $a2

  MEMORY[0](cp, inp);
  return lseek(v2, v3, v4);
}
// 4CE1D9: variable 'v2' is possibly undefined
// 4CE1D9: variable 'v3' is possibly undefined
// 4CE1D9: variable 'v4' is possibly undefined

