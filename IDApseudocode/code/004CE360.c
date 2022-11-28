__sighandler_t set_dns_more_dnstype_to_kernel()
{
  int v0; // $a0
  __sighandler_t v1; // $a1

  MEMORY[0]();
  return signal(v0, v1);
}
// 4CE369: variable 'v0' is possibly undefined
// 4CE369: variable 'v1' is possibly undefined

