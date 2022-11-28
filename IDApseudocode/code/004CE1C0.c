int start_dhcp_server_just_check()
{
  const char *v0; // $a0
  struct in_addr *v1; // $a1

  MEMORY[0]();
  return inet_aton(v0, v1);
}
// 4CE1C9: variable 'v0' is possibly undefined
// 4CE1C9: variable 'v1' is possibly undefined

